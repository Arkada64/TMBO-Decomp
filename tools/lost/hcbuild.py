"""A Harbor City / Head-On car (BDD) onto a retail TMB donor car (generalized pakbuild.py, no 12 Pak hatches / mounts).
  python3 hcbuild.py DONORDIR DONORCODE CAR.BDD OUTDIR OUTCODE [--scale S] [--lift Z] [--half] [--no-drop] [--no-relight]
DONORDIR holds the donor as <DONORCODE>.NGP/PTR/TEX/RTX (or STP.*); output: OUTDIR/<OUTCODE>.NGP/PTR/TEX/RTX.
e.g. python3 hcbuild.py /mnt/user-data/uploads/cloud/hc PCP THUMP.BDD out ZUP     (Thumper on Brimstone, local copy)
     python3 hcbuild.py /mnt/user-data/uploads/cloud/hc PCA THUMP.BDD out ZUA --half

What is found automatically (printed):
 Donor (TMB car NGP, entry 0 = op1 car root with id R):
  - LOD node = the root's op2 child with 2 kids: kid 0 high, kid 1 far LOD (an op1 group of meshes).
  - body damage states = the op31 directly under the high LOD whose kids are exactly 3 op1 groups with r >= 8
    (Roadkill 0x32270, Brimstone 0x1ad30); each gets the new car's damage state 0/1/2.
  - kept: wheels (op4 id R+1..R+4), shadow (op1 id R+5), weapon-mount models (op1 id >= 4000), everything outside
    the high LOD (headlight beams, shield / freeze shells, op7 effect characters with id 0).
  - the scorch op31 (first kid op9, >= 5 op1 kids: black burn decal shells in the donor's shape shown as health drops;
    Brimstone 0x26ac0, Roadkill 0x5ca90, which pakbuild kept) is hidden: the new car's damage states carry their own.
  - brake lights = op6 id R+10 with 3 kids: its kids become the new car's own 3 brake-light meshes (off / on / on).
  - every other op0 of the high LOD (body panels, doors, driver, weapon hardware, op7 characters with id != 0)
    gets an empty packet, no texture slots; the far LOD group's meshes are replaced by the new car's far LOD.
  - donor textures / CLUTs no longer referenced are dropped; new CLUTs go into the freed CLUT blocks.
 Head-On car (BDD ngp):
  - LOD roots = the op2 node with 2 kids that holds the most meshes: kid with more meshes = high, other = far.
  - wheels = meshes outside the LOD roots with a wheel-shaped box (dy ~ dz, thin in x, |x| > 1) in car space.
  - brake lights = 3 meshes outside the roots with one shared, flat box at the rear (darkest = off).
  - skipped: meshes without normals (light cones, flames), env-map shine shells (hflags & 0x0E), parts reaching
    below the wheels' ground or out past the body sides (stray poles / exhaust).
 Placement: scale = donor wheelbase / new wheelbase (both measured), y offset centres the axles, z offset puts the
 wheel centres on the donor's (+ --lift); the donor's wheels stay.
 Relight (HC fan-build cars are unfinished: most meshes carry no vertex colours, so TMB drew them at the 0xFFFF
 default (~2.5x a retail car's prelit level) next to flat 128 RGBA8 parts at ~41: patchy lighting): normals are
 renormalized, normals disagreeing with the surface (|dot| < 0.5) are replaced by the geometric normal, and every
 vertex gets a baked colour from its normal (retail prelit range, Brimstone's body averages ~55); alpha is kept.
"""
import sys, os, struct, argparse
import numpy as np
from bdd import bdd
from homesh import find_packets, decode, triangles
from hocollect import collect
from tmbcar import Car, mesh_extent, u32, BASE
from textconv import TexBuilder, clut_blocks
from meshconv import hierobject
from tmbtree_walk import kid_slots

CLUT_LIMIT = 76            # retail cars use 57-76 CLUT blocks (Sweet Tooth / Brimstone 76)
TEX_LIMIT = 299520         # largest retail car TEX


def f32(d, o): return struct.unpack_from('<f', d, o)[0]


def box(P):
    P = np.asarray(P, float)
    return P.min(0), P.max(0)


# ---------------------------------------------------------------- Head-On side
class HoCar:
    def __init__(self, path):
        s = bdd(path)
        self.n, self.tex = s['ngp'], s['tex']
        n = self.n
        self.hd = {}
        from hotex import textures as ho_textures
        tkeys = set(ho_textures(self.tex))
        self.texfixed = []
        for o in find_packets(n):
            m = decode(n, o)
            if m['hdr'] is not None:
                h = m['hdr']
                ks = []
                for i in range(4):
                    k = u32(n, h + 0x10 + 4 * i)
                    if k not in tkeys:
                        break
                    ks.append(k)
                need = max([(st['tag'][3] - 1) // 3 + 1 for st in m['strips'] if st['tag'][3]] or [0])
                if ks and len(m['texrefs']) < max(need, 1) <= len(ks):
                    # the fan-build cars' GS context for these is tagged 0x20000006 (homesh counts only
                    # 0x20000005), so their texture key was missed: Old Pickup / Pit Viper looked untextured
                    m = dict(m, texrefs=ks)
                    self.texfixed.append(h)
                self.hd[h] = m
        best = None
        for o in range(0, len(n) - 0x40, 16):
            if u32(n, o) & 0x3f != 2 or struct.unpack_from('<i', n, o + 4)[0] != 2:
                continue
            ks = [u32(n, o + 0x28 + 0x10 * i) for i in range(2)]
            if not all(0 < k < len(n) and k % 16 == 0 for k in ks):
                continue
            cnt = [len(collect(n, k, 0, lod=0)) for k in ks]
            if best is None or sum(cnt) > best[0]:
                best = (sum(cnt), o, ks, cnt)
        if best is None:             # near-static fan-build cars (Old Pickup, Pit Viper): one tree, no LOD
            self.lod = None
            self.hi = self.lo = u32(n, 4)
        else:
            _, self.lod, ks, cnt = best
            self.hi, self.lo = (ks[1], ks[0]) if cnt[1] >= cnt[0] else (ks[0], ks[1])
        inroots = set()
        for st in range(4):
            inroots |= set(collect(n, self.hi, st, lod=0)) | set(collect(n, self.lo, st, lod=0))
        self.outside = [h for h in sorted(self.hd) if h not in inroots]
        # wheels: wheel-shaped meshes in car space, anywhere (Thumper's sit outside the LOD roots, Outlaw 2's /
        # the Pickup's inside the body tree); local-space wheel copies (centred on x 0) don't count
        wh = []
        for h in sorted(self.hd):
            lo, hi = box(self.hd[h]['pos']); d = hi - lo; c = (lo + hi) / 2
            if d[1] > 1 and abs(d[1] - d[2]) < 0.1 * d[1] and d[0] < 0.8 * d[1] and abs(c[0]) > 1 \
                    and not self.hd[h]['hflags'] & 0x0E:        # chrome hubcap / env shells are not the wheel
                wh.append((h, c, d[2] / 2))
        if len(wh) > 4:                # several per corner (Gold Tooth: low-poly copies): the most detailed one each
            best4 = {}
            for w in wh:
                q = (w[1][0] > 0, w[1][1] > 0)
                if q not in best4 or len(self.hd[w[0]]['pos']) > len(self.hd[best4[q][0]]['pos']):
                    best4[q] = w
            extra_w = [w[0] for w in wh if w not in best4.values()]
            wh = list(best4.values())
        else:
            extra_w = []
        assert wh, 'no wheels found in car space'
        self.wheel_q = {(c[0] > 0, c[1] > (max(w[1][1] for w in wh) + min(w[1][1] for w in wh)) / 2): (h, c, r)
                        for h, c, r in wh}            # (right, front) -> (mesh, car-space centre, radius)
        # parts sitting inside a wheel's box (Gold Tooth's gold hubcaps): they ride on the same tire node
        self.wheel_parts = {}
        allw = {h for h, _, _ in wh} | set(extra_w)
        for h, c, r in wh:
            lo, hi = box(self.hd[h]['pos'])
            self.wheel_parts[h] = [k for k, m in sorted(self.hd.items()) if k not in allw and m['pos'] and
                                   (box(m['pos'])[0] >= lo - 0.2).all() and (box(m['pos'])[1] <= hi + 0.2).all()]
        ys = [c[1] for _, c, _ in wh]
        self.wheel = dict(front=max(ys), rear=min(ys), z=float(np.mean([c[2] for _, c, _ in wh])),
                          r=float(np.mean([r for _, _, r in wh])), x=float(np.mean([abs(c[0]) for _, c, _ in wh])),
                          meshes=[h for h, _, _ in wh] + extra_w)
        assert len(wh) <= 4, 'more than 4 wheel candidates: %s' % [hex(h) for h, _, _ in wh]
        # 5-bit vertex colour level that counts as full (95th percentile of the brightest channel)
        c5 = [max(c & 31, (c >> 5) & 31, (c >> 10) & 31) for m in self.hd.values() for st in m['strips']
              for c in st['col'] if c <= 0xFFFF]
        self.c5norm = max(8.0, float(np.percentile(c5, 95))) if c5 else 31.0
        # body box (state 0 high LOD)
        big = max((h for h in collect(n, self.hi, 0, lod=0) if h in self.hd and h not in self.wheel['meshes']),
                  key=lambda h: len(self.hd[h]['pos']))
        self.body = box(self.hd[big]['pos'])        # the main shell (flames / poles would stretch a box of all)
        # brake lights: 3 outside meshes sharing one flat box behind the rear axle
        groups = {}
        for h in self.outside:
            lo, hi = box(self.hd[h]['pos'])
            if hi[1] - lo[1] < 0.3 and hi[1] < self.wheel['rear'] - 2:
                groups.setdefault(tuple(np.round(np.r_[lo, hi], 2)), []).append(h)
        bl = [g for g in groups.values() if len(g) == 3]
        self.brake = []
        if bl:
            def bright(h):
                cs = [c for s in self.hd[h]['strips'] for c in s['col']]
                if not cs: return 31.0              # no colours = 0xFFFF default
                return float(np.mean([(c & 31) if c <= 0xFFFF else (c & 255) / 8 for c in cs]))
            self.brake = sorted(bl[0], key=bright)   # off (darkest) first

    def env_overlay(self, h):
        """an env-mapped mesh laid over a plain mesh of the same box (Thumper's shine shell) - not a part by itself"""
        lo, hi = box(self.hd[h]['pos'])
        for k, m in self.hd.items():
            if k != h and m['pos'] and not m['hflags'] & 0x0E:
                l2, h2 = box(m['pos'])
                if np.abs(l2 - lo).max() < 0.05 and np.abs(h2 - hi).max() < 0.05:
                    return True
        return False

    def skip_reason(self, h, wheel_ground, far=False, env='skip', own=False):
        m = self.hd[h]
        lo, hi = box(m['pos'])
        if far and own:              # --own-wheels: the far LOD keeps its wheels (the donor's far wheels go)
            if not m['nrm'] and h not in self.brake:
                return 'no normals (light cone / flame / sprite)'
            if m['hflags'] & 0x0E and (env == 'skip' or self.env_overlay(h)):
                return 'env-map shine shell'
            return None
        if h in self.wheel['meshes']:
            return "wheel (the donor's are kept)"
        if not m['nrm'] and h not in self.brake:
            return 'no normals (light cone / flame / sprite)'
        if m['hflags'] & 0x0E and (env == 'skip' or self.env_overlay(h)):
            return 'env-map shine shell'
        wt = {t for w in self.wheel['meshes'] for t in set(self.hd[w]['texrefs'][:2])}   # tyre + rim
        if m['texrefs'] and set(m['texrefs']) <= wt | (set(self.hd[self.wheel['meshes'][0]]['texrefs']) if far else set()):
            return "wheel part (the donor's wheels are kept)"
        if far:                      # far LOD: its wheels give way to the donor's far wheels (kept), nothing else is cut
            return None
        if lo[2] < wheel_ground - 0.2:
            return 'below the ground'
        if max(-lo[0], hi[0]) > max(-self.body[0][0], self.body[1][0]) + 0.5:
            return 'out past the body sides'
        return None


def relight(m, xform, c5norm=31.0):
    """placement + normal repair + baked vertex colours; returns new mesh dict and stats"""
    s, d = xform
    P = np.asarray(m['pos'], float)
    N = np.zeros_like(P)
    if m['nrm']:
        N[:len(m['nrm'])] = np.asarray(m['nrm'], float)[:len(P)]
    acc = np.zeros_like(P)
    for a, b, c in triangles(m):
        i, j, k = a[0], b[0], c[0]
        f = np.cross(P[j] - P[i], P[k] - P[i]); acc[i] += f; acc[j] += f; acc[k] += f
    ln = np.linalg.norm(N, axis=1); la = np.linalg.norm(acc, axis=1)
    G = np.where(la[:, None] > 1e-9, acc / np.maximum(la, 1e-9)[:, None], 0)
    Nn = np.where(ln[:, None] > 1e-6, N / np.maximum(ln, 1e-6)[:, None], 0)
    dot = (G * Nn).sum(1)
    bad = (ln < 0.5) | ((la > 1e-9) & (np.abs(dot) < 0.5))
    sign = np.where(dot < 0, -1.0, 1.0)
    out = (P - np.array([0, 0.5, 1.5])); sg2 = np.where((G * out).sum(1) < 0, -1.0, 1.0)
    sign = np.where(ln < 0.5, sg2, sign)
    Nf = np.where(bad[:, None], G * sign[:, None], Nn)
    Nf = np.where((np.linalg.norm(Nf, axis=1) < 1e-6)[:, None], np.array([0, 0, 1.0]), Nf)
    L = np.array([0.3, 0.4, 0.85]); L /= np.linalg.norm(L)
    lum = 0.35 + 0.45 * np.maximum(0, Nf @ L) + 0.2 * (0.5 + 0.5 * Nf[:, 2])
    strips = []
    for st in m['strips']:
        cols = []
        for i, pi in enumerate(st['idx']):
            c0 = st['col'][i] if i < len(st['col']) else 0xFFFF
            if c0 <= 0xFFFF:          # 5-bit: hue kept (untextured painted parts), level relative to the car's full
                a = 0x80 if (c0 >> 15) & 1 else 0
                f = np.array([c0 & 31, (c0 >> 5) & 31, (c0 >> 10) & 31]) / c5norm
            else:                     # RGBA8: 128 = 1.0
                a = (c0 >> 24) & 255
                f = np.array([c0 & 255, (c0 >> 8) & 255, (c0 >> 16) & 255]) / 128.0
            r, g, b = (int(x) for x in np.clip(90 * lum[pi] * np.minimum(f, 1.5), 0, 255))
            cols.append(r | (g << 8) | (max(b, 1) << 16) | (a << 24))     # > 0xFFFF: meshconv's RGBA8 path
        strips.append(dict(st, col=cols, noscale=True))
    pos = [tuple(p * s + d) for p in P]
    m2 = dict(m, pos=pos, nrm=[tuple(x) for x in Nf], strips=strips)
    return m2, int(bad.sum()), len(P)


# ---------------------------------------------------------------- donor side
def chars_of(n, op7):
    return [u32(n, op7 + 8 + 4 * i) - BASE for i in range(u32(n, op7 + 4))]


def trav_slots(n, o):
    """child slots dbsTraverse reads (tools/shift/ngptrav.py layouts)"""
    op = u32(n, o) & 0x3f
    s32 = lambda a: struct.unpack_from('<i', n, a)[0]
    if op == 1: return [o + 0x20 + 4 * i for i in range(struct.unpack_from('<H', n, o + 8)[0])]
    if op == 2: k = s32(o + 4); return ([o + 0x28] + [o + 0x38 + 0x10 * (i - 1) for i in range(1, k)]) if k > 0 else []
    if op == 3: return [o + 0x1c + 4 * i for i in range(max(0, s32(o + 8)))]
    if op == 4: return [o + 0x50 + 4 * i for i in range(max(0, s32(o + 8)))]
    if op == 17: return [o + 0xcc + 4 * i for i in range(max(0, s32(o + 4)))]
    if op == 6: return [o + 0xc + 4 * i for i in range(n[o + 0xb])]
    if op == 31: return [o + 0xc + 0x14 * i for i in range(n[o + 9])]
    if op == 8: return [o + 4, o + 8]
    if op == 13: return [o + 0xbc + 4 * i for i in range(max(0, s32(o + 4)))]
    if op == 23: return [o + 4]
    if op == 25: return [o + 0x2c + 4 * i for i in range(max(0, s32(o + 0x28)))]
    if op == 30: return [o + 0x2c + 4 * i for i in range(max(0, s32(o + 8)))]
    if op == 7: return [o + 8 + 4 * i for i in range(u32(n, o + 4))]
    return []


def traverse_check(n, ptr_slots):
    """full traversal from every entry point: (reached nodes, bad slots = read slots holding no valid pointer or
    missing from the PTR list)"""
    ptr = set(ptr_slots); ne = u32(n, 0)
    seen, bad, st = set(), [], []
    def chk(slot, owner):
        v = u32(n, slot)
        ok = BASE <= v < BASE + len(n)
        if not ok or (slot >= 4 + 4 * ne and slot not in ptr):
            bad.append((owner, slot, v))
        return v - BASE if ok else None
    st = [chk(4 + 4 * i, -1) for i in range(ne)]
    while st:
        o = st.pop()
        if o is None or o in seen: continue
        seen.add(o)
        st += [chk(sl, o) for sl in trav_slots(n, o) if sl + 4 <= len(n)]
        if u32(n, o) & 0x3f in (17, 25) and o + 0x30 <= len(n):     # character bone mesh (not a traverse slot)
            v = u32(n, o + 0x2c)
            if BASE <= v < BASE + len(n): st.append(v - BASE)
    return seen, bad


def mesh_range(car, nd):
    """[node, packet end) of an op0 whose packet is a plain TMB mesh packet right after its header, else None
    (sprite / odd meshes are left alone: a bogus qword count would cut away live nodes after them)"""
    pk = car.P(nd + 4)
    nt = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
    if pk is None or pk != nd + 0x70 + 0x30 * nt or (u32(car.n, pk) >> 16) != 0x6000:
        return None
    try:
        __import__('tmbmesh').decode(bytes(car.n), nd)
    except Exception:
        return None
    return mesh_extent(car.n, nd)


def kids(car, o):
    op = u32(car.n, o) & 0x3f
    if op == 0:
        return []
    sl = sorted(set(kid_slots(car.n, o)) | set(trav_slots(car.n, o)))
    if op in (17, 25):
        sl = [o + 0x2c] + sl
    out = []
    for s in sl:
        if s + 4 <= len(car.n):
            t = car.P(s)
            if t is not None:
                out.append(t)
    return out


def meshes_under(car, root, stop=lambda o: False):
    out, seen, st = [], set(), [root]
    while st:
        o = st.pop()
        if o in seen or stop(o):
            continue
        seen.add(o)
        if u32(car.n, o) & 0x3f == 0:
            out.append(o)
        else:
            st += kids(car, o)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('donordir'); ap.add_argument('donorcode'); ap.add_argument('bdd'); ap.add_argument('outdir')
    ap.add_argument('outcode')
    ap.add_argument('--scale', type=float, default=None)
    ap.add_argument('--lift', type=float, default=0.25, help='raise the body above the wheel-centre match')
    ap.add_argument('--half', action='store_true', help='new textures at half size (other players\' copy)')
    ap.add_argument('--no-drop', action='store_true')
    ap.add_argument('--keep-scorch', action='store_true', help="keep the donor's scorch op31 (black burn shells in its shape)")
    ap.add_argument('--one-state', action='store_true', help='damage state 0 for all three states (smaller NGP)')
    ap.add_argument('--own16', default='auto', help="Head-On texture keys quantized to 16 colours (hex list, 'auto' = "
                    "every texture but the largest when the CLUT / TEX budget would overflow, 'none')")
    ap.add_argument('--no-relight', action='store_true')
    ap.add_argument('--env', default='skip', choices=('skip', 'bake'), help='env-mapped meshes: skip (shine shells, '
                    'default) or bake their reflection lookup into UVs (parts made of chrome / gold; overlays still skipped)')
    ap.add_argument('--add', default='', help='Head-On mesh headers outside the LOD roots added to every damage state '
                    "(hex, comma separated; Gold Tooth's head / eyes / arm 0x1230,0x3bd0,0x3e0)")
    ap.add_argument('--skip-tex', default='', help='Head-On texture keys whose meshes are left out (hex, comma '
                    'separated; Gold Tooth: flares / flames / far-LOD wheels 8a480,c1fa8,84320,87f40,8bba8,a2888)')
    ap.add_argument('--reuse', default='', help="Head-On texture key:donor CLUT block, quantized onto the donor's "
                    "palette instead of a new CLUT (Gold Tooth on STP: b0448:45,a91b8:49,8dc74:45,9e768:5; STA 53,57,53,5)")
    ap.add_argument('--half-keys', default='', help='Head-On texture keys stored at half size (hex, comma separated)')
    ap.add_argument('--own-wheels', action='store_true', help="the new car's own wheels on the donor's tire nodes "
                    '(spin / steer / suspension stay the donor\'s), scale 1, own proportions')
    ap.add_argument('--robot', default='', help="new car's alternate-form root onto a donor character, 'SRC:@CHAR' "
                    "(Gold Tooth on STP: 0x45a60:@0x91c20, STA: 0x45a60:@0x8a210)")
    ap.add_argument('--robot-far', default='', help="new car's far alternate form onto a donor group, 'SRC:@GROUP' "
                    "(Gold Tooth on STP: 0x2a820:@0x94160)")
    ap.add_argument('--hide-node', default='', help='donor node offsets (hex, comma separated) whose meshes get empty '
                    "packets too, e.g. Outlaw's roof light bar op31 (SUP 0x67ae0, SUA 0x5d6a0)")
    ap.add_argument('--keep-part', default='', help="donor node ids kept with their subtree, ';'-separated, each "
                    "optionally ':dx,dy,dz' to move it (e.g. Outlaw's turret '124:0,0,-1.9'); '@hex' names a node offset (Sweet "
                    "Tooth's robot character '@0x91c20')")
    ap.add_argument('--skip', default='', help='extra Head-On mesh headers to leave out (hex, comma separated)')
    a = ap.parse_args()

    def rd(e):
        for nm in (a.donorcode, 'STP'):
            p = os.path.join(a.donordir, nm + '.' + e)
            if os.path.exists(p):
                return open(p, 'rb').read()
        raise FileNotFoundError(e)
    own = set() if a.own16 in ('auto', 'none') else {int(x, 16) for x in a.own16.split(',')}
    outs, over, keys = build(a, rd, own)
    if over and a.own16 == 'auto':
        own = set(keys)
        print('--- over budget: again with 16-colour palettes for', [hex(k) for k in sorted(own)])
        outs, over, keys = build(a, rd, own)
    os.makedirs(a.outdir, exist_ok=True)
    for e, b in outs:
        open(os.path.join(a.outdir, a.outcode + '.' + e), 'wb').write(b)
        print(e, len(b), '(donor %d)' % len(rd(e)))
    if over:
        print('WARNING: CLUT blocks or TEX above the retail limits')


def build(a, rd, own16):
    os.environ.setdefault('GT_ENVLIFT', '0')     # textconv's own16 tints palettes for reflection maps otherwise
    car = Car(rd('NGP'), rd('PTR'), rd('TEX'), rd('RTX'))
    orig_ngp = len(car.n)
    n = car.n
    import hcmounts
    mount_rec = hcmounts.donor_mounts(car)     # weapon mounts at rest, read before anything is edited (HC_MOUNTS)
    ho = HoCar(a.bdd)
    print('Head-On: LOD %s high %#x far %#x; wheels %s; brake %s' % (hex(ho.lod) if ho.lod else None, ho.hi, ho.lo,
          {k: (round(v, 2) if isinstance(v, float) else [hex(x) for x in v]) for k, v in ho.wheel.items()}, [hex(x) for x in ho.brake]))

    # ---- donor structure
    root = u32(n, 4) - BASE
    R = u32(n, root) >> 18
    lvl, lodn = [root], None           # the root's op2 (most cars) or deeper: Sweet Tooth root -> op1 -> op6 id R+25
    for _ in range(4):                 # (kid 0 truck, kid 1 robot) -> op2; breadth first, first 2-kid op2 wins
        lodn = next((t for t in lvl if u32(n, t) & 0x3f == 2 and struct.unpack_from('<i', n, t + 4)[0] == 2), None)
        if lodn is not None:
            break
        lvl = [k for o in lvl for k in kids(car, o)]
    assert lodn is not None, 'no 2-kid LOD node'
    hi, lo = car.P(lodn + 0x28), car.P(lodn + 0x38)
    states_op31 = None
    lvl, cand = [hi], []
    for _ in range(3):                 # direct kid of the high LOD (Brimstone, Roadkill) or nested (Crazy 8)
        lvl = [k for o in lvl if u32(n, o) & 0x3f in (1, 31) for k in kids(car, o)]
        cand += lvl
    for t in cand:
        if u32(n, t) & 0x3f != 31 or states_op31:
            continue
        ks = [k for k in kids(car, t) if u32(n, k) & 0x3f != 9]
        if len(ks) == 3 and all(u32(n, k) & 0x3f == 1 and f32(n, k + 0x1c) >= 8 for k in ks):
            states_op31, STATES = t, ks
    assert states_op31, 'no body damage-state op31'
    nodes = {}
    st = [root]; seen = set()
    while st:
        o = st.pop()
        if o in seen: continue
        seen.add(o); nodes[o] = u32(n, o)
        st += kids(car, o)
    wheels4 = [o for o, h in nodes.items() if h & 0x3f == 4 and R + 1 <= (h >> 18) <= R + 4]
    shadow = [o for o, h in nodes.items() if h & 0x3f == 1 and (h >> 18) == R + 5]
    mounts = [o for o, h in nodes.items() if h & 0x3f == 1 and (h >> 18) >= 4000]
    brake_sw = [o for o, h in nodes.items() if h & 0x3f == 6 and (h >> 18) == R + 10 and n[o + 0xb] == 3]
    wreck = [o for o, h in nodes.items() if h & 0x3f == 31 and n[o + 9] >= 6 and (u32(n, car.P(o + 0xc) or 0) & 0x3f) == 9
             and sum(1 for k in kids(car, o) if u32(n, k) & 0x3f == 1) >= 5]
    keep = set()
    for k in wheels4 + shadow + mounts + (wreck if a.keep_scorch else []):
        keep |= set(meshes_under(car, k))
    # --keep-part ID[:dx,dy,dz]: donor parts kept (e.g. Outlaw's roof turret, op4 id R+28), optionally moved by a
    # translate node put in front of them
    moves = []
    for spec in filter(None, a.keep_part.split(';')):
        pid, _, off = spec.partition(':')
        for o, h in nodes.items():
            if (o == int(pid[1:], 16)) if pid.startswith('@') else (h >> 18) == int(pid, 0):   # '@hex' = node offset
                keep |= set(meshes_under(car, o))
                if off:
                    moves.append((o, [float(x) for x in off.split(',')]))
                print('kept donor part id %s node %#x (%d meshes)%s' % (pid, o, len(meshes_under(car, o)),
                                                                        ' moved by ' + off if off else ''))
    for o, (dx, dy, dz) in moves:
        refs = [sl for sl in list(car.slots) if car.P(sl) == o]
        t = car.append(struct.pack('<IIIIfffI', 3, 0, 1, 0, dx, dy, dz, 0))
        car.setp(t + 0x1c, o)
        for sl in refs:
            car.setp(sl, t)
    wpos = [(f32(n, w + 0x40), f32(n, w + 0x44), f32(n, w + 0x48)) for w in wheels4]
    wr = max(box(__import__('tmbmesh').decode(bytes(n), m)['pos'])[1][2] for w in wheels4 for m in meshes_under(car, w))
    dw = dict(front=max(p[1] for p in wpos), rear=min(p[1] for p in wpos), z=float(np.mean([p[2] for p in wpos])),
              x=float(np.mean([abs(p[0]) for p in wpos])), r=wr)
    print('donor %s: root %#x id %d, LOD %#x high %#x far %#x, states op31 %#x %s, wheels %s %s, shadow %s, mounts %d, '
          'brake %s, wreck %s' % (a.donorcode, root, R, lodn, hi, lo, states_op31, [hex(x) for x in STATES],
                                  [hex(x) for x in wheels4], {k: round(v, 2) for k, v in dw.items()},
                                  [hex(x) for x in shadow], len(mounts), [hex(x) for x in brake_sw], [hex(x) for x in wreck]))

    # ---- placement
    if a.own_wheels:                   # own wheels: own proportions (scale 1, Head-On units = TMB units), own origin
        s = a.scale or 1.0             # in y; only z moves so its wheels stand on the donor's ground plane
        dy = 0.0
        dz = (dw['z'] - dw['r']) - s * (ho.wheel['z'] - ho.wheel['r'])
    else:
        s = a.scale or (dw['front'] - dw['rear']) / (ho.wheel['front'] - ho.wheel['rear'])
        dy = (dw['front'] + dw['rear']) / 2 - s * (ho.wheel['front'] + ho.wheel['rear']) / 2
        dz = dw['z'] - s * ho.wheel['z'] + a.lift
    xform = (s, np.array([0.0, dy, dz]))
    print('placement: scale %.3f offset y %.3f z %.3f | wheels new (scaled) x %.2f r %.2f vs donor x %.2f r %.2f | '
          'body (scaled) x %.2f..%.2f y %.2f..%.2f z %.2f..%.2f, donor ground z %.2f' % (
              s, dy, dz, ho.wheel['x'] * s, ho.wheel['r'] * s, dw['x'], dw['r'],
              ho.body[0][0] * s, ho.body[1][0] * s, ho.body[0][1] * s + dy, ho.body[1][1] * s + dy,
              ho.body[0][2] * s + dz, ho.body[1][2] * s + dz, dw['z'] - dw['r']))

    # ---- converting Head-On meshes
    reuse = {int(k, 16): int(v) for k, v in (x.split(':') for x in a.reuse.split(',') if x)}
    tb = TexBuilder(car.tex, car.rtx, ho.tex, car.max_tex_id() + 1, reuse,
                    [int(x, 16) for x in a.half_keys.split(',') if x], own16)
    WHITE = 0xFFFFFFF0                 # Head-On draws texture-less meshes (TME still set) on white: give them one
    tb.ho[WHITE] = dict(img=np.full((8, 8, 4), 255, np.uint8), idx=np.zeros(64, np.uint8), bpp=4,
                        clutraw=bytes([255, 255, 255, 0x80] * 16), clut=dict(tw=3, th=1))
    if a.half:
        tb.half |= set(ho.hd[h]['texrefs'][0] for h in ho.hd if ho.hd[h]['texrefs'])
    ground = ho.wheel['z'] - ho.wheel['r']
    extra = {int(x, 16) for x in a.skip.split(',') if x}
    skip_tex = {int(x, 16) for x in a.skip_tex.split(',') if x}
    built, skipped, fixed = {}, {}, [0, 0]

    def node(h, cols=None, local=None, frame=None):
        """local = (car-space centre, inverse rotation, mirror): a wheel mesh in its tire node's space"""
        key = (h, cols, None if local is None else (tuple(np.round(local[0], 4)), tuple(np.round(local[1], 4).ravel()), local[2]),
               None if frame is None else (tuple(np.round(frame[0], 4).ravel()), tuple(np.round(frame[1], 4))))
        if key not in built:
            m = ho.hd[h]
            xf = xform
            if local is not None:
                c0, Rinv, mir = local
                P = np.asarray(m['pos'], float) - c0
                N = np.asarray(m['nrm'], float) if m['nrm'] else np.zeros((0, 3))
                if mir:
                    P[:, 0] *= -1
                    if len(N): N = N * np.array([-1, 1, 1])
                m = dict(m, pos=[tuple(p) for p in P], nrm=[tuple(q) for q in N])
                xf = (s, np.zeros(3))
            if a.no_relight:
                m = dict(m, pos=[tuple(np.asarray(p) * s + xf[1]) for p in m['pos']])
            else:
                m, nb, nv = relight(m, xf, ho.c5norm)
                fixed[0] += nb; fixed[1] += nv
            if cols is not None:      # brake lights: fixed brightness (off dim, on glowing)
                m = dict(m, strips=[dict(st, col=[cols | (0x80 << 24)] * len(st['idx']), noscale=True) for st in m['strips']])
            if local is not None:
                m = dict(m, pos=[tuple(np.asarray(p) @ local[1]) for p in m['pos']],
                         nrm=[tuple(np.asarray(q) @ local[1]) for q in m['nrm']])
            if frame is not None:      # into a donor node's frame (row vectors: world = local @ M + t)
                Mi = np.linalg.inv(frame[0])
                m = dict(m, pos=[tuple((np.asarray(p) - frame[1]) @ Mi) for p in m['pos']],
                         nrm=[tuple(np.asarray(q) @ Mi) for q in m['nrm']])
            if m['texrefs'] and m['strips'] and not m['strips'][0]['tag'][3]:     # texture select on the 1st strip
                st0 = [dict(st) for st in m['strips']]
                t = list(st0[0]['tag']); t[3] = 1; st0[0]['tag'] = tuple(t)
                m = dict(m, strips=st0)
            if not m['texrefs']:
                st0 = [dict(st) for st in m['strips']]
                if st0:
                    t = list(st0[0]['tag']); t[3] = 1; st0[0]['tag'] = tuple(t)
                m = dict(m, texrefs=[WHITE], strips=st0)
            # --env bake: an env-mapped part (Gold Tooth's gold body) gets its reflection-map lookup baked into UVs
            m = dict(m, twosided=bool(local is not None and local[2]),        # mirrored wheel: both faces
                     bake=a.env == 'bake' and bool(ho.hd[h]['hflags'] & 0x0E),
                     hflags=m.get('hflags', 0) & ~0x0E)
            blob, slots, pairs, sph = hierobject(m, 1.0, [tb.gs_ctx(k) for k in m['texrefs']])
            built[key] = car.append(blob, slots, pairs)
        return built[key]

    def ho_meshes(r, state, far=False):
        out = []
        for h in collect(ho.n, r, state, lod=0):
            m = ho.hd.get(h)
            if m is None or not m['strips']:
                continue
            why = 'listed' if h in extra else 'skipped texture' if set(m['texrefs']) & skip_tex else \
                ho.skip_reason(h, ground, far, a.env, a.own_wheels)
            if why:
                skipped[h] = why; continue
            out.append(h)
        return out

    add_meshes = [int(x, 16) for x in a.add.split(',') if x]   # Head-On meshes outside the LOD roots, every state
    box_d = hcmounts.body_box_tmb(car, STATES[0])              # donor body (state 0), for the mount box map
    # HC_FLAME (default 1 for Old Pickup): its roof flamethrower leaves the body mesh and becomes a 5-frame yaw switch
    # (attach type 7, sub hcmounts.FLAME_SUB) a code hook can turn; frame 0 = the model as built
    flame_sw, FLAME_SRC = None, 0x8c30
    if os.environ.get('HC_FLAME', '1') == '1' and 'PICKUP' in os.path.basename(a.bdd).upper() and FLAME_SRC in ho.hd:
        lo_, hi_ = hcmounts.FLAME_BOX
        gun, rest = hcmounts.split_mesh(ho.hd[FLAME_SRC], lambda p: (p >= lo_).all() and (p <= hi_).all())
        ho.hd[0x10000000 | FLAME_SRC] = rest
        for i, deg in enumerate(hcmounts.FLAME_YAW):
            ho.hd[0x20000000 | (i << 24) | FLAME_SRC] = hcmounts.turned(gun, hcmounts.FLAME_PIVOT, deg)
        kids_ = [node(0x20000000 | (i << 24) | FLAME_SRC) for i in range(len(hcmounts.FLAME_YAW))]
        nk_ = len(kids_)
        flame_sw = car.append(struct.pack('<IIBBBB', 6 | (hcmounts.FLAME_SUB << 7) | ((R + 7) << 18), 0, 0, 0, 0, nk_)
                              + b'\0' * (4 * nk_ + 8))
        for i, k_ in enumerate(kids_):
            car.setp(flame_sw + 0xc + 4 * i, k_)
        print('flamethrower: %d of %d body triangles -> switch id %d sub %d, %d yaw frames %s about (%.2f %.2f) '
              '(Head-On space)' % (sum(max(0, len(s_['idx']) - 2) for s_ in gun['strips']),
                                   len(triangles(ho.hd[FLAME_SRC])), R + 7, hcmounts.FLAME_SUB, nk_,
                                   hcmounts.FLAME_YAW, *hcmounts.FLAME_PIVOT))
    dead = []
    for stn, g in enumerate(STATES):
        k = u32(car.n, g + 8) & 0xffff
        dead += [mesh_range(car, t) for t in meshes_under(car, g)]
        hs = ho_meshes(ho.hi, 0 if a.one_state else stn)
        hs += [h for h in add_meshes if h not in hs]
        if flame_sw is not None:
            hs = [(0x10000000 | h) if h == FLAME_SRC else h for h in hs]
        newg = car.group([node(h) for h in hs] + ([flame_sw] if flame_sw is not None else []),
                         sphere=struct.unpack_from('<3ff', car.n, g + 0x10))
        struct.pack_into('<H', car.n, g + 8, 1)
        car.setp(g + 0x20, newg)
        for i in range(1, k):
            struct.pack_into('<I', car.n, g + 0x20 + 4 * i, 0)
        if stn == 0:
            state0_hs = hs
        print('state', stn, len(hs), 'meshes')
    # far LOD: the donor's meshes -> the new car's far LOD, except the donor's far wheels / underside (a mesh centred
    # at or below the wheel centres, Brimstone 0x4aa30, Roadkill 0x5e310), which stays like the near wheels
    k = u32(car.n, lo + 8) & 0xffff
    lokids = [car.P(lo + 0x20 + 4 * i) for i in range(k)]
    lokeep = [t for t in lokids if t is not None and (u32(car.n, t) & 0x3f == 4 or (
        not a.own_wheels and u32(car.n, t) & 0x3f in (0, 1) and f32(car.n, t + 0x18) <= dw['z'] + 0.3))]
    lokept = {m for t in lokeep for m in meshes_under(car, t)}
    lomesh = [t for t in meshes_under(car, lo) if t not in lokept]
    dead += [mesh_range(car, t) for t in lomesh]
    hs = ho_meshes(ho.lo, 0, far=True)
    if not hs:                         # far LOD with nothing but wheels (Twister): the high LOD's state 0 (shared nodes)
        hs = ho_meshes(ho.hi, 0)
        print('far LOD: the new car\'s far LOD is wheels only, using its high LOD')
    if flame_sw is not None and FLAME_SRC in hs:   # far LOD (the Pickup has one tree): split body + gun at rest
        hs = [h for h in hs if h != FLAME_SRC] + [0x10000000 | FLAME_SRC, 0x20000000 | FLAME_SRC]
    newk = [car.group([node(h) for h in hs], sphere=struct.unpack_from('<3ff', car.n, lo + 0x10))] + lokeep
    struct.pack_into('<H', car.n, lo + 8, len(newk))
    for i in range(k):
        struct.pack_into('<I', car.n, lo + 0x20 + 4 * i, 0)
    for i, t in enumerate(newk):
        car.setp(lo + 0x20 + 4 * i, t)
    print('far LOD: donor meshes %s -> new car %d meshes + kept donor wheels %s' % (
        [hex(t) for t in lomesh], len(hs), [hex(t) for t in lokeep]))
    # --robot SRC:@CHAR: the new car's alternate (special) form onto a donor character (Gold Tooth's jointed robot
    # 0x45a60 onto Sweet Tooth's robot 0x91c20). Both are rigged trucks in their rest pose (the robot animation
    # unfolds them), and the donor's bone meshes are stored in model space. Every new part goes to the donor bone
    # slot whose rest mesh is nearest in the two forms' normalized boxes, converted into that slot's frame
    # (op3 / op4 above it); the donor's own meshes go. --robot-far SRC:@GROUP: a plain group (the far robot) gets
    # the new car's meshes under SRC.
    for spec in filter(None, a.robot.split(';')):
        src, _, ch = spec.partition(':@')
        src, ch = int(src, 16), int(ch, 16)
        slots_ = []                    # (slot, mesh, M, t)
        st_ = [(ch, np.eye(3), np.zeros(3))]
        seen_ = set()
        while st_:
            o, M, t = st_.pop()
            if o in seen_:
                continue
            seen_.add(o)
            op = u32(car.n, o) & 0x3f
            if op == 3:
                t = t + np.array(struct.unpack_from('<3f', car.n, o + 0x10)) @ M
            elif op == 4:
                m4 = np.array(struct.unpack_from('<16f', car.n, o + 0x10)).reshape(4, 4)
                t = t + m4[3, :3] @ M; M = m4[:3, :3] @ M
            if op == 1 and (u32(car.n, o) >> 18) >= 4000:
                continue               # weapon models stay
            sl = sorted(set(kid_slots(car.n, o)) | set(trav_slots(car.n, o)))
            if op in (17, 25):
                sl = [o + 0x2c] + sl
            for s_ in sl:
                if s_ + 4 > len(car.n):
                    continue
                k_ = car.P(s_)
                if k_ is None:
                    continue
                if u32(car.n, k_) & 0x3f == 0:
                    slots_.append((s_, k_, M, t))
                else:
                    st_.append((k_, M, t))
        from tmbmesh import decode as tdec
        tm = []
        for s_, k_, M, t in slots_:
            try:
                P = np.array(tdec(bytes(car.n), k_)['pos'])
            except Exception:
                continue
            if len(P) and (u32(car.n, k_ + 0xc) >> 16):
                tm.append((s_, k_, M, t, (P.min(0) + P.max(0)) / 2 @ M + t, P @ M + t))
        hs = ho_meshes(src, 0) + [h for h in add_meshes if h not in ho_meshes(src, 0)]   # + head / eyes / arm
        gc = {h: (box(ho.hd[h]['pos'])[0] + box(ho.hd[h]['pos'])[1]) / 2 * s + xform[1] for h in hs}
        allg = np.array([np.asarray(p) * s + xform[1] for h in hs for p in ho.hd[h]['pos']])
        allt = np.concatenate([x[5] for x in tm])
        g0, g1, t0, t1 = allg.min(0), allg.max(0), allt.min(0), allt.max(0)
        norm_g = lambda c: (c - g0) / np.maximum(g1 - g0, 1e-6)
        norm_t = lambda c: (c - t0) / np.maximum(t1 - t0, 1e-6)
        by_slot = {}
        for h in hs:
            j = min(range(len(tm)), key=lambda i: ((norm_g(gc[h]) - norm_t(tm[i][4])) ** 2).sum())
            by_slot.setdefault(j, []).append(h)
        for j, hl in by_slot.items():
            s_, k_, M, t = tm[j][:4]
            nodes_ = [node(h, frame=(M, t)) for h in hl]
            car.setp(s_, nodes_[0] if len(nodes_) == 1 else car.group(nodes_, sphere=(0, 0, 0, 20.0)))
        for j, (s_, k_, M, t, c, P) in enumerate(tm):
            if j in by_slot:
                r = mesh_range(car, k_)
                if r: dead.append(r)
        print('robot: %d new meshes onto %d of %d donor bone meshes of %#x (new box %s..%s, donor rest box %s..%s)' % (
            len(hs), len(by_slot), len(tm), ch, g0.round(1), g1.round(1), t0.round(1), t1.round(1)))
    for spec in filter(None, a.robot_far.split(';')):
        src, _, grp = spec.partition(':@')
        src, grp = int(src, 16), int(grp, 16)
        old = meshes_under(car, grp)
        hs = [h for h in collect(ho.n, src, 0, lod=0) if h in ho.hd and ho.hd[h]['strips']
              and not ho.skip_reason(h, ground, True, a.env, True)]
        k = u32(car.n, grp + 8) & 0xffff
        for i in range(k):
            struct.pack_into('<I', car.n, grp + 0x20 + 4 * i, 0)
        car.setp(grp + 0x20, car.group([node(h) for h in hs], sphere=struct.unpack_from('<3ff', car.n, grp + 0x10)))
        struct.pack_into('<H', car.n, grp + 8, 1)
        dead += [r for r in (mesh_range(car, t_) for t_ in old) if r]
        print('far robot: group %#x, %d donor meshes -> %d new' % (grp, len(old), len(hs)))
    # --own-wheels: the donor's tire nodes (op4 id R+1..R+4: the game spins / steers / bounces them, and keeps the
    # node's +0x48, its translation z, as the tire's rest height) get the new car's wheel meshes, centred on the
    # node, and the node moves to the new wheel's centre. A missing wheel (Thumper's front left) is the other
    # side's, mirrored (drawn two-sided).
    wheel_report = []
    if a.own_wheels:
        ymid = (dw['front'] + dw['rear']) / 2
        for w in wheels4:
            M = np.array(struct.unpack_from('<16f', car.n, w + 0x10)).reshape(4, 4)
            R3, t = M[:3, :3], M[3, :3]
            q = (bool(t[0] > 0), bool(t[1] > ymid))
            mir = q not in ho.wheel_q
            h, c, r = ho.wheel_q[(not q[0], q[1]) if mir else q]
            cw = c * np.array([-1.0, 1, 1]) if mir else c
            cn = cw * s + np.array([0.0, dy, dz])
            dead += [mesh_range(car, t_) for t_ in meshes_under(car, w)]
            k = struct.unpack_from('<i', car.n, w + 8)[0]
            for i in range(1, max(k, 1)):
                struct.pack_into('<I', car.n, w + 0x50 + 4 * i, 0)
            struct.pack_into('<i', car.n, w + 8, 1)
            loc = (np.asarray(c, float), np.linalg.inv(R3), mir)
            parts = [k for k in ho.wheel_parts.get(h, []) if not ho.skip_reason(k, ground, False, a.env)
                     and not set(ho.hd[k]['texrefs']) & skip_tex]
            if parts:
                kid = car.group([node(h, local=loc)] + [node(k, local=loc) for k in parts],
                                sphere=(0, 0, 0, r * s * 1.5))
            else:
                kid = node(h, local=loc)
            car.setp(w + 0x50, kid)
            struct.pack_into('<3f', car.n, w + 0x40, *cn)
            wheel_report.append((u32(car.n, w) >> 18, cn, r * s, hex(h) + (' mirrored' if mir else '') +
                                 (' + parts %s' % [hex(k) for k in parts] if parts else '')))
        for wid, cn, r, src in sorted(wheel_report):
            print('tire node id %d: centre (%.2f %.2f %.2f) radius %.2f  <- %s' % (wid, cn[0], cn[1], cn[2], r, src))
        xs = [abs(c[0]) for _, c, _, _ in wheel_report]; ys = [c[1] for _, c, _, _ in wheel_report]
        print('own wheels (donor model space): half track %.2f, front axle y %.2f, rear axle y %.2f, centre z %.2f, '
              'radius %.2f (donor: %.2f / %.2f / %.2f / %.2f / %.2f)' % (
                  np.mean(xs), max(ys), min(ys), np.mean([c[2] for _, c, _, _ in wheel_report]),
                  np.mean([r for _, _, r, _ in wheel_report]), dw['x'], dw['front'], dw['rear'], dw['z'], dw['r']))
    # brake lights
    brake_old, brake_hide = set(), set()
    if brake_sw and len(ho.brake) == 3:
        sw = brake_sw[0]
        for i in range(3):
            brake_old |= set(meshes_under(car, car.P(sw + 0xc + 4 * i)))
        dead += [mesh_range(car, t) for t in brake_old]
        ws = [0x2d2d2d, 0xffffff, 0xffffff]          # off: dim, braking / reverse: glowing
        for i, h in enumerate([ho.brake[0], ho.brake[2], ho.brake[2]]):
            car.setp(sw + 0xc + 4 * i, node(h, ws[i]))
        print('brake lights: donor switch %#x (%d meshes) -> %s' % (sw, len(brake_old), [hex(x) for x in ho.brake]))
    elif brake_sw:                     # the new car has none: the donor's lamps (often outside the high LOD) go
        sw = brake_sw[0]
        for i in range(3):
            if car.P(sw + 0xc + 4 * i) is not None:
                brake_hide |= set(meshes_under(car, car.P(sw + 0xc + 4 * i)))
        print('brake lights: the new car has none, donor switch %#x lamps hidden (%d meshes)' % (sw, len(brake_hide)))
    print('skipped Head-On meshes:', {hex(h): w for h, w in sorted(skipped.items())})
    if not a.no_relight:
        print('relight: %d of %d vertices got a geometric normal' % tuple(fixed))

    # ---- weapon mounts (HC_MOUNTS, tools/lost/hcmounts.py): the donor's machine guns / weapon models move onto the
    # new model (its Head-On mount list, placed like the body: scale s, offset (0, dy, dz))
    _, L = hcmounts.ho_list(ho.n)
    to_donor = lambda p: np.asarray(p, float) * s + np.array([0.0, dy, dz])
    # new body box: every kept state-0 mesh (1st..99th percentile: stray poles / aerials don't stretch it)
    P0 = np.concatenate([np.asarray(ho.hd[h]['pos'], float) for h in state0_hs if ho.hd[h]['pos']])
    box_n = (to_donor(np.percentile(P0, 1, axis=0)), to_donor(np.percentile(P0, 99, axis=0)))
    print('mounts: Head-On list %s, donor body box %s..%s, new body box %s..%s' % (
        {k: [None if p is None else tuple(round(x, 2) for x in p) for p in v] for k, v in sorted(L.items())} or 'none',
        np.round(box_d[0], 2), np.round(box_d[1], 2), np.round(box_n[0], 2), np.round(box_n[1], 2)))
    hcmounts.apply(car, mount_rec, L, to_donor, box_d, box_n, name=os.path.basename(a.bdd))

    # ---- hide the donor's own parts (empty packet, no texture slots)
    dead = [r for r in dead if r]
    deadset = {x for x, _ in dead}
    op7 = next(u32(n, 4 + 4 * i) - BASE for i in range(u32(n, 0)) if (u32(n, u32(n, 4 + 4 * i) - BASE) & 0x3f) == 7)
    hide = set(meshes_under(car, hi)) | brake_hide
    for x in filter(None, a.hide_node.split(',')):      # donor parts outside the high LOD hidden on request
        hn = set(meshes_under(car, int(x, 16)))
        hide |= hn
        print('hidden on request: donor node %s (%d meshes)' % (x, len(hn)))
    for c in chars_of(car.n, op7):
        if (u32(car.n, c) >> 18) != 0:
            hide |= set(meshes_under(car, c))
    hide -= keep | deadset | set(built.values())
    nopk = car.append(struct.pack('<4I', 0x60000001, 0, 0, 0) + struct.pack('<4I', 0x01000404, 0, 0, 0))
    hidepairs = set()
    odd = []
    for nd in sorted(hide):
        r = mesh_range(car, nd)
        if r is None:                  # odd packet format: hidden too, but its bytes stay (its qword count can't be
            odd.append(nd)             # trusted to find the packet end)
        else:
            dead.append((car.P(nd + 4), r[1]))
        nt = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
        hidepairs |= {nd + 0x50 + 2 * i for i in range(nt)}
        struct.pack_into('<H', car.n, nd + 0x5a, 0)
        car.setp(nd + 4, nopk)
        struct.pack_into('<I', car.n, nd + 0xc, u32(car.n, nd + 0xc) & 0xFFFF)
    car.pairs = [(x, g) for x, g in car.pairs if x not in hidepairs]
    print('donor parts hidden: %d meshes (kept: %d wheel / shadow / mount meshes; odd packets kept in place: %s)' % (
        len(hide), len(keep), [hex(x) for x in odd]))

    # nothing the game still reaches may sit in a removed range (a shared mesh / a node after a sprite packet)
    reached, _ = traverse_check(bytes(car.n), car.slots)
    rs = sorted(reached)
    import bisect
    spared = [r for r in set(dead) if bisect.bisect_left(rs, r[0]) < bisect.bisect_left(rs, r[1])]
    dead = set(dead) - set(spared)
    for nd, end in spared:            # a removed mesh still reached (e.g. through an op7 character of a replaced
        if nd in reached and u32(car.n, nd) & 0x3f == 0 and car.P(nd + 4) == nd + 0x70 + 0x30 * struct.unpack_from(
                '<H', car.n, nd + 0x5a)[0]:                                    # damage state): hide it in place
            nt = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
            car.pairs = [(x, g) for x, g in car.pairs if not nd + 0x50 <= x < nd + 0x50 + 2 * nt]
            dead.add((car.P(nd + 4), end))
            struct.pack_into('<H', car.n, nd + 0x5a, 0)
            car.setp(nd + 4, nopk)
            struct.pack_into('<I', car.n, nd + 0xc, u32(car.n, nd + 0xc) & 0xFFFF)
    dead = sorted(dead)
    if spared:
        print('still reached, hidden in place instead of removed:', [hex(a) for a, _ in sorted(spared)])
    before = len(car.n)
    dropped = car.compact(dead)
    _, bad = traverse_check(bytes(car.n), car.slots)
    assert not bad, 'traversal reads bad slots: %s' % [(hex(o), hex(s), hex(v)) for o, s, v in bad[:10]]
    print('traversal check: %d nodes, 0 bad slots' % len(_))

    # ---- textures: drop the donor's unreferenced ones, pack new CLUTs into free blocks
    newtids = {v[0] for v in tb.map.values()}
    used, usedc = set(), set()
    for x, g in car.pairs:
        tid = struct.unpack_from('<H', car.n, x)[0]
        if tid not in newtids:
            used.add(tid); usedc.add((struct.unpack_from('<Q', car.n, g)[0] >> 37) & 0x3fff)
    usedc |= set(reuse.values())       # donor palettes the new textures were quantized onto
    old = [(gs & 0xffff, b) for o, b, gs, k in tb.trecs]
    oldc = [((gs >> 16) & 0xffff, clut_blocks((gs >> 40) & 15, (gs >> 44) & 15)) for o, b, gs, k in tb.rrecs]
    if not a.no_drop:
        tb.drop_tids = {t for t, _ in old if t not in used}
        tb.drop_cbps = {c for c, _ in oldc if c not in usedc}
    dc = getattr(tb, 'drop_cbps', set())
    taken = np.zeros(512, bool)
    for c, nb in oldc:
        if c not in dc:
            taken[c:c + nb] = True
    remap, newrtx = {}, []
    for r in tb.new_rtx:
        gs = struct.unpack_from('<Q', r, 8)[0]
        c, nb = (gs >> 16) & 0xffff, clut_blocks((gs >> 40) & 15, (gs >> 44) & 15)
        f = next(i for i in range(512) if not taken[i:i + nb].any())
        taken[f:f + nb] = True
        remap[c] = f
        r = bytearray(r); struct.pack_into('<Q', r, 8, (gs & ~(0xffff << 16)) | (f << 16)); newrtx.append(bytes(r))
    tb.new_rtx = newrtx
    for x, g in car.pairs:
        if struct.unpack_from('<H', car.n, x)[0] in newtids:
            q = struct.unpack_from('<Q', car.n, g)[0]
            c = (q >> 37) & 0x3fff
            struct.pack_into('<Q', car.n, g, (q & ~(0x3fff << 37)) | (remap.get(c, c) << 37))
    clut_top = int(np.nonzero(taken)[0].max()) + 1
    print('textures: donor %d (%d dropped), new %d; CLUT blocks used %d, top %d (donor %d, limit %d)' % (
        len(old), len(getattr(tb, 'drop_tids', ())), len(tb.new_tex), int(taken.sum()), clut_top,
        max(c + nb for c, nb in oldc), CLUT_LIMIT))
    print('ngp %d -> %d (donor %d, %+.1f%%), dropped slots %d' % (before, len(car.n), orig_ngp,
                                                                  100.0 * (len(car.n) - orig_ngp) / orig_ngp, dropped))
    outs = (('NGP', car.ngp_bytes()), ('PTR', car.ptr_bytes()), ('TEX', tb.tex_bytes()), ('RTX', tb.rtx_bytes()))
    over = clut_top > CLUT_LIMIT or len(outs[2][1]) > TEX_LIMIT
    big = sorted(tb.map, key=lambda k: -tb.ho[k]['img'].size)
    # 16-colour candidates: all but the largest, opaque (own16 drops alpha) and with more than 16 colours
    keys = [k for k in big[1:] if (tb.ho[k]['img'][:, :, 3] == 255).all()
            and len(np.unique(tb.ho[k]['img'].reshape(-1, 4), axis=0)) > 16]
    return outs, over, keys


if __name__ == '__main__':
    main()
