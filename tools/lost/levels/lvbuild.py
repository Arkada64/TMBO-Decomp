"""Stage 1 of a Lost / Head-On level conversion: render meshes + textures + pickups -> TMB level files.
  python3 lvbuild.py HC_xx.BDD OUTDIR NAME [scale=1.15]
Writes NAME.NGP / .PTR / .TEX / .RTX (raw, for base 0x980000) and NAME.PKP. Collision (TMB op15 grid / op18 BSP
trees / op7 object list) is stage 2, so the NGP has the render tree only (one entry point)."""
import sys, os, struct, math, zlib, collections
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.dirname(HERE)); sys.path.insert(0, '/home/claude/lost')
from bdd import bdd
from homesh import decode
from hotx import walk
from levtex import textures
from meshconv import hierobject
from tmbcar import Car, BASE
from textconv import tex0, join, clut_blocks, TEX1
from pkpconv import convert as pkp_convert
from hocol import piece, collision_objects
from lvcol import build_piece, encode

TEX_BUDGET = 2654208          # level TEX slot 0x1C05670 .. 0x1E8E3F0 (0x288D80)
CLUT_BUDGET = 0x411           # level CLUT blocks
LEAF = 24                     # meshes per leaf render group (retail: 12-49)

def packet_of(n, o):
    q = o
    while q < o + 0x400 and not ((int.from_bytes(n[q:q + 4], 'little') >> 16) == 0x6000 and int.from_bytes(n[q + 4:q + 8], 'little') == 0):
        q += 16
    return q

MERGE_CELL = float(os.environ.get('LV_MERGE', '800'))   # 0 = off
MERGE_NSV = int(os.environ.get('LV_MERGE_NSV', '800'))  # strip vertices per merged object
def merge_meshes(meshes, cell):
    """Fewer, bigger render objects: the game builds one VU1 packet entry per drawn object into a fixed buffer
    (pktAddVu1ObjAsm hits `break 0` when it is full - the hang right after the level loads). Head-On splits
    its levels into many tiny meshes (median ~22 vertices), so meshes with the same texture list in the same
    cell x cell square are joined into one (positions/normals appended, strip indices offset; the strip tags
    keep selecting textures by position in the shared list)."""
    split = []
    for m in meshes:      # big single meshes: split by strips (each part keeps the shared position list)
        nsv = sum(len(s_['idx']) for s_ in m['strips'])
        if nsv <= MERGE_NSV: split.append(m); continue
        cur, k = [], 0
        for s_ in m['strips']:
            if cur and k + len(s_['idx']) > MERGE_NSV:
                split.append(dict(m, strips=cur)); cur, k = [], 0
            cur.append(s_); k += len(s_['idx'])
        if cur: split.append(dict(m, strips=cur))
    meshes = split
    out = {}
    for m in meshes:
        P = np.array(m['pos']); c = (P.max(0) + P.min(0)) / 2
        key = (math.floor(c[0] / cell), math.floor(c[1] / cell), tuple(m['texrefs']))
        nrm = list(m['nrm']) + [(0.0, 0.0, 1.0)] * (len(m['pos']) - len(m['nrm']))
        nsv = sum(len(s_['idx']) for s_ in m['strips'])
        if key in out and out[key]['_nsv'] + nsv > MERGE_NSV:     # keep packets retail-sized (retail max ~1650 qw)
            k2 = 1
            while key + (k2,) in out and out[key + (k2,)]['_nsv'] + nsv > MERGE_NSV: k2 += 1
            key = key + (k2,)
        if key not in out:
            out[key] = dict(m, pos=list(m['pos']), nrm=nrm, strips=[dict(s_) for s_ in m['strips']], _nsv=nsv)
            continue
        g = out[key]; base = len(g['pos']); g['_nsv'] += nsv
        g['pos'] += list(m['pos']); g['nrm'] += nrm
        for s_ in m['strips']:
            g['strips'].append(dict(s_, idx=[i + base for i in s_['idx']]))
    return list(out.values())

def placed_meshes(n, scale):
    ms, st, unk = walk(n)
    out = []
    for o, M in ms:
        try: m = decode(n, packet_of(n, o))
        except Exception: continue
        if not m['strips'] or not m['pos']: continue
        P = np.c_[np.array(m['pos'], float), np.ones(len(m['pos']))] @ M
        R = M[:3, :3]
        N = np.array(m['nrm'], float) @ R if m['nrm'] else np.zeros((0, 3))
        if len(N): N /= np.maximum(np.linalg.norm(N, axis=1, keepdims=True), 1e-9)
        if np.linalg.det(R) < 0:   # mirrored instance: strips would turn inside out
            for s in m['strips']: s['brk'] = s['brk']
        out.append(dict(m, pos=[tuple(p) for p in P[:, :3] * scale], nrm=[tuple(v) for v in N]))
    return out, unk

class LevelTex:
    def __init__(self, T, next_id=1, next_cbp=0, budget=TEX_BUDGET, clut_budget=CLUT_BUDGET):
        self.T = T; self.map = {}; self.recs = []; self.cluts = []; self.next_cbp = next_cbp; self.next_id = next_id
        self.half = set(); self.to4 = set(); self.budget = budget; self.clut_budget = clut_budget
        self.cbp_of = {}                                   # palette bytes -> CLUT address (shared palettes)
    def clut_of(self, k):
        t = self.T[k]
        if k in self.to4: return self.q4(k)[1]
        return t['clutraw'], t['ctw'], t['cth']
    def q4(self, k):
        if not hasattr(self, '_q4'): self._q4 = {}
        if k not in self._q4:
            from PIL import Image
            t = self.T[k]
            q = Image.fromarray(t['img'][:, :, :3]).quantize(16, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
            idx = np.asarray(q, np.uint8).reshape(-1)
            pal = np.array((q.getpalette() + [0] * 48)[:48], np.uint8).reshape(16, 3)
            raw = np.concatenate([pal, np.full((16, 1), 0x80, np.uint8)], 1).tobytes()
            self._q4[k] = (idx, (raw, 3, 1))
        return self._q4[k]
    def size(self, k):
        t = self.T[k]; h, w = t['h'], t['w']
        if k in self.half: h, w = h // 2, w // 2
        return w * h // (2 if t['bpp'] == 4 or k in self.to4 else 1)
    def clut_total(self, keys):
        seen = {}
        for k in keys:
            raw, tw, th = self.clut_of(k); seen[raw] = clut_blocks(tw, th)
        return sum(seen.values())
    def plan(self, keys):
        """halve the biggest textures until the set fits the level TEX slot"""
        keys = [k for k in keys if k in self.T]
        def total(): return sum(self.size(k) + 0x80 for k in keys)
        order = sorted(keys, key=lambda k: -self.size(k))
        i = 0
        # palettes: 256-colour textures without transparency -> 16 colours until the CLUT area fits
        if self.clut_total(keys) > self.clut_budget:
            for k in sorted(keys, key=lambda k: self.T[k]['w'] * self.T[k]['h']):
                t = self.T[k]
                if t['bpp'] == 8 and t['img'][:, :, 3].min() >= 250: self.to4.add(k)
                if self.clut_total(keys) <= self.clut_budget: break
        while total() > self.budget * 0.97 and i < len(order) * 3:
            k = order[i % len(order)]
            t = self.T[k]
            if k not in self.half and t['w'] >= 32 and t['h'] >= 32: self.half.add(k)
            i += 1
        return total(), self.clut_total(keys)
    def add(self, key):
        if key in self.map: return self.map[key]
        t = self.T[key]; h, w = t['h'], t['w']
        idx = (self.q4(key)[0] if key in self.to4 else t['idx']).reshape(h, w)
        if key in self.half: idx = idx[::2, ::2]; h, w = h // 2, w // 2
        idx = idx.reshape(-1).astype(np.uint8)
        if t['bpp'] == 8 and key not in self.to4: payload, psm = idx.tobytes(), 0x13
        else: payload, psm = (idx[0::2] | (idx[1::2] << 4)).astype(np.uint8).tobytes(), 0x14
        tid = self.next_id; self.next_id += 1
        tw, th = w.bit_length() - 1, h.bit_length() - 1
        nbytes = len(payload)
        self.recs.append((tid, psm, tw, th, payload))
        raw, ctw, cth = self.clut_of(key)
        if raw in self.cbp_of: cbp = self.cbp_of[raw]
        else:
            c = bytearray(raw)
            for i in range(3, len(c), 4): c[i] = min(255, c[i] * 2)
            cbp = self.next_cbp; self.next_cbp += clut_blocks(ctw, cth); self.cbp_of[raw] = cbp
            rgs = (cbp << 16) | (ctw << 40) | (cth << 44) | (0x08 << 48) | (0x01 << 56)
            self.cluts.append(struct.pack('<IIQ', (16 + len(c)) // 4, 0, rgs) + bytes(c))
        self.map[key] = (tid, psm, w, h, cbp)
        return self.map[key]
    def gs_ctx(self, key):
        tid, psm, w, h, cbp = self.add(key)
        return tid, struct.pack('<Q', tex0(psm, w, h, cbp)) + struct.pack('<II', 6, 0) + TEX1 + b'\0' * 16
    def tex_bytes(self, extra=()):
        sizes = sorted({len(p) for *_, p in self.recs} | {len(r) - 0x80 for r in extra})
        bins = [1 << max(8, (s - 1).bit_length()) for s in sizes]
        classes = sorted(set(bins))
        cnt = collections.Counter()
        recs = []
        for r in extra:                               # donor records: class index rewritten
            r = bytearray(r); bs = 1 << max(8, (len(r) - 0x81).bit_length()); cls = classes.index(bs); cnt[cls] += 1
            gs = struct.unpack_from('<Q', r, 8)[0] & ~(0x1f << 59) | (cls << 59); struct.pack_into('<Q', r, 8, gs)
            struct.pack_into('<I', r, 0, len(r) // 4); recs.append(bytes(r))
        for tid, psm, tw, th, payload in self.recs:
            bs = 1 << max(8, (len(payload) - 1).bit_length()); cls = classes.index(bs); cnt[cls] += 1
            gs = tid | (psm << 32) | (tw << 40) | (th << 44) | ((4 if psm == 0x13 else 8) << 51) | (cls << 59)
            q = len(payload) // 16
            hdr = struct.pack('<IIQ', (0x80 + len(payload)) // 4, zlib.crc32(payload) or 1, gs)
            hdr += struct.pack('<IIII', 0x60000000 | (q + 6), 0, 0, 0x50000000 | (q + 6)) + b'\0' * 0x60
            recs.append(hdr + payload)
        recq = (8 + 8 * len(classes) + 15) // 16
        head = bytearray(recq * 16)
        struct.pack_into('<II', head, 0, len(classes), recq)
        for i, bs in enumerate(classes): struct.pack_into('<II', head, 8 + 8 * i, cnt[i], bs)
        out = head + join(recs)
        return bytes(out + b'\0' * (-len(out) % 2048))
    def rtx_bytes(self, extra=()):
        out = join([bytes(bytearray(r)) for r in extra] + self.cluts)
        return bytes(out + b'\0' * (-len(out) % 2048))

def full_walk(n, root):
    """every node under root, all LODs / states (TMB child layouts)"""
    u = lambda o: struct.unpack_from('<I', n, o)[0]; s32 = lambda o: struct.unpack_from('<i', n, o)[0]
    u16 = lambda o: struct.unpack_from('<H', n, o)[0]
    P = lambda s_: (u(s_) - BASE) if BASE <= u(s_) < BASE + len(n) else None
    seen = set(); st = [root]
    while st:
        x = st.pop()
        if x is None or x in seen: continue
        seen.add(x); op = u(x) & 0x3f; k = []
        if op == 1: k = [P(x + 0x20 + 4 * i) for i in range(u16(x + 8))]
        elif op == 2: k = [P(x + 0x28 + 0x10 * i) for i in range(max(0, s32(x + 4)))]
        elif op == 3: k = [P(x + 0x1C + 4 * i) for i in range(s32(x + 8) & 0xffff)]
        elif op == 4: k = [P(x + 0x50 + 4 * i) for i in range(s32(x + 8) & 0xffff)]
        elif op == 30: k = [P(x + 0x2C + 4 * i) for i in range(s32(x + 8) & 0xffff)]
        elif op == 17: k = [P(x + 0xCC + 4 * i) for i in range(s32(x + 4))]
        elif op == 6: k = [P(x + 0xC + 4 * i) for i in range(n[x + 0xB])]
        elif op == 31: k = [P(x + 0xC + 0x14 * i) for i in range(n[x + 9])]
        elif op in (8, 9): k = [P(x + 4), P(x + 8)]
        elif op == 13: k = [P(x + 0xBC + 4 * i) for i in range(s32(x + 4))]
        elif op == 23: k = [P(x + 4)]
        st += k
    return seen

def donor_prepare(car, drop=None, drop_c=None):
    """TMB level used as the base: its shared assets (weapons, pickup models, effects: callback ids >= 3000)
    stay; its arena (callback id 1 = render + collision, id 14 = extra collision) goes. Returns the id-1 node,
    the id-14 nodes, the op15 grid node, texture records / CLUT records to keep, next free texture id / CLUT block."""
    from ngptrav import traverse
    from textconv import records, tex_rec_size, rtx_rec_size
    n = bytes(car.n); u = lambda o: struct.unpack_from('<I', n, o)[0]
    par = {}
    v = traverse(n, [4 + 4 * i for i in range(u(0))], parents=par)
    arena = set(); id1 = None; id14 = []
    for o, op, i1, i2 in v:
        if i1 == 1: id1 = o; arena |= full_walk(n, o)
        elif i1 == 14: id14.append(o); arena |= full_walk(n, o)
    asset = set()
    for o, op, i1, i2 in v:
        if i1 not in (0, 1, 14): asset |= full_walk(n, o)
    def tids(nodes):
        out = set()
        for a, g in car.pairs:
            for back in range(0x50, 0x70, 2):
                if a - back in nodes and (u(a - back) & 0x3f) == 0: out.add(struct.unpack_from('<H', n, a)[0]); break
        return out
    if drop is None: drop = tids(arena) - tids(asset)
    tr = records(bytes(car.tex), tex_rec_size); rr = records(bytes(car.rtx), rtx_rec_size)
    cbp_of = {}
    for a, g in car.pairs: cbp_of[struct.unpack_from('<H', n, a)[0]] = (struct.unpack_from('<Q', n, g)[0] >> 37) & 0x3fff
    keep_t = [bytes(car.tex[o:o + b]) for o, b, gs, k in tr if (gs & 0xffff) not in drop]
    used_cbp = {c for t, c in cbp_of.items() if t not in drop}
    if drop_c is None: drop_c = {cbp_of[t] for t in drop if t in cbp_of} - used_cbp
    keep_r = [bytes(car.rtx[o:o + b]) for o, b, gs, k in rr if ((gs >> 16) & 0xffff) not in drop_c]
    next_id = max(gs & 0xffff for o, b, gs, k in tr) + 1
    next_cbp = max(((gs >> 16) & 0xffff) + clut_blocks((gs >> 40) & 15, (gs >> 44) & 15) for o, b, gs, k in rr
                   if ((gs >> 48) & 0xff) == 8)          # CLUT records (the others are VRAM-resident textures)
    op15 = next(u(4 + 4 * i) - BASE for i in range(u(0)) if (u(u(4 + 4 * i) - BASE) & 0x3f) == 15)
    arena_meshes = sorted(o for o in arena - asset if (u(o) & 0x3f) == 0)
    chain = [id1]
    while par.get(chain[0]) is not None: chain.insert(0, par[chain[0]])
    return dict(chain_id1=chain, drop=drop, drop_c=drop_c, arena_meshes=arena_meshes, id1=id1, id14=id14, op15=op15, keep_t=keep_t, keep_r=keep_r, next_id=next_id, next_cbp=next_cbp,
                kept_bytes=sum(len(r) for r in keep_t), dropped=len(drop))

def build(path, outdir, name, scale=1.15, donor=None):
    b = bdd(path); n = b['ngp']
    meshes, unk = placed_meshes(n, scale)
    # prelit colours: Head-On's level colours run brighter than Black's (DEATH6 averages ~33 of 128); scale them
    # to the same average (the car value, 0.32, left the maps far too dark)
    import meshconv
    cols = []
    for m in meshes[:600]:
        for s_ in m['strips']:
            for c_ in s_['col'][:8]:
                cols.append(((c_ & 31) << 3) + (((c_ >> 5) & 31) << 3) + (((c_ >> 10) & 31) << 3) if c_ <= 0xFFFF else (c_ & 255) + ((c_ >> 8) & 255) + ((c_ >> 16) & 255))
    meshconv.COLOR_SCALE = min(1.0, 33.0 * 3 / max(1.0, float(np.mean(cols)))) if cols else 0.5
    T = textures(b['tex'])
    keys = sorted({k for m in meshes for k in m['texrefs']})
    missing = [k for k in keys if k not in T]
    meshes = [m for m in meshes if all(k in T for k in m['texrefs'])]
    # strip texture selectors: TMB's VU1 code reads GS context 1 + 3*k (k < texture count); Head-On meshes also have
    # untextured meshes (no context at all), first strips that select nothing (inherit the previous object's
    # context), out-of-range and flagged (0x8000) selectors - any of these feed the GS a garbage context
    nt0 = len(meshes); meshes = [m for m in meshes if m['texrefs']]; fixed = 0
    for m in meshes:
        nt = len(m['texrefs'])
        for i, s_ in enumerate(m['strips']):
            t = s_['tag'][3]; t2 = t & 0x7fff
            if t2 and ((t2 - 1) % 3 or t2 > 1 + 3 * (nt - 1)): t2 = 1 + 3 * min((t2 - 1) // 3, nt - 1)
            if i == 0 and t2 == 0: t2 = 1
            if t2 != t:
                tag = list(s_['tag']); tag[3] = t2; m['strips'][i] = dict(s_, tag=tuple(tag)); fixed += 1
    print('  untextured meshes dropped', nt0 - len(meshes), 'texture selectors fixed', fixed)
    if MERGE_CELL:
        n0 = len(meshes); meshes = merge_meshes(meshes, MERGE_CELL); print('  merged', n0, '->', len(meshes))
    if donor:
        car = Car(*[open(f'{donor}.{k}', 'rb').read() for k in ('NGP', 'PTR', 'TEX', 'RTX')])
        dn = donor_prepare(car)
        from tmbcar import mesh_extent
        dead = sorted(mesh_extent(car.n, o) for o in dn['arena_meshes'])
        dead = [(a, (b + 15) & ~15) for a, b in dead]
        donor_size = len(car.n); car.compact(dead)
        dn = donor_prepare(car, dn['drop'], dn['drop_c']); dn['compacted'] = donor_size - len(car.n)
        LT = LevelTex(T, dn['next_id'], dn['next_cbp'], TEX_BUDGET - dn['kept_bytes'], CLUT_BUDGET - dn['next_cbp'])
    else:
        dn = None
        LT = LevelTex(T)
        car = Car(struct.pack('<4I', 3, 0, 0, 0), struct.pack('<II', 0, 0), b'', b'')
    tex_total, clut_total = LT.plan(keys)
    tiles = collections.defaultdict(list)
    def translucent(k):
        a = T[k]['img'][..., 3]
        return float((a < a.max()).mean()) > 0.02
    tl = {k: translucent(k) for k in keys if k in T}
    placed = []; nfail = 0
    for m in meshes:
        ctx = [LT.gs_ctx(k) for k in m['texrefs']]
        m['level'] = True
        if os.environ.get('LV_ALPHA', '1') == '1':
            m['alpha'] = any(tl.get(k) for k in m['texrefs'])   # retail arenas: ~15% alpha meshes
        try:
            blob, rel, pairs, sph = hierobject(m, 1.0, ctx)
        except Exception as e:
            nfail += 1; continue
        if max(abs(sph[0]), abs(sph[1]), abs(sph[2])) > 50000: nfail += 1; continue   # bad transform path
        off = car.append(blob, rel, pairs)
        placed.append((off, sph))
    print('  meshes', len(placed), 'failed', nfail, 'alpha', sum(bool(m.get('alpha')) for m in meshes))
    def bound(lst):
        P = np.array([s[:3] for _, s in lst]); c = tuple((P.max(0) + P.min(0)) / 2)
        return (*c, max(math.dist(c, s[:3]) + s[3] for _, s in lst))
    def kd(lst):
        # small spatial leaf groups (retail: ~12-16 meshes), all directly under the root: a nested tree
        # (depth 11) blacked the screen in game, the old flat layout (depth 9) loads
        if len(lst) <= LEAF:
            b_ = bound(lst); return [(car.group([o for o, _ in lst], sphere=b_), b_)]
        P = np.array([s[:3] for _, s in lst]); ax = int(np.argmax(P.max(0) - P.min(0)))
        lst = sorted(lst, key=lambda e: e[1][ax]); h = len(lst) // 2
        return kd(lst[:h]) + kd(lst[h:])
    groups = []
    # very large meshes (backdrops, terrain sheets) go straight under the root; the rest into the tree
    if os.environ.get('LV_GROUPS', 'kd') == 'tiles':
        # the first layout (loaded in game, much missing): 1200-unit tiles, up to 250 meshes per group
        tiles = collections.defaultdict(list)
        for off, sph in placed: tiles[(math.floor(sph[0] / 1200.0), math.floor(sph[1] / 1200.0))].append((off, sph))
        for key, lst in tiles.items():
            xs = [s[0] for _, s in lst]; ys = [s[1] for _, s in lst]; zs = [s[2] for _, s in lst]
            c = ((max(xs) + min(xs)) / 2, (max(ys) + min(ys)) / 2, (max(zs) + min(zs)) / 2)
            r = max(math.dist(c, s[:3]) + s[3] for _, s in lst)
            for i in range(0, len(lst), 250):
                part = lst[i:i + 250]
                groups.append((car.group([o for o, _ in part], sphere=(*c, r)), (*c, r)))
    else:
        big = [e for e in placed if e[1][3] > 3000]; small = [e for e in placed if e[1][3] <= 3000]
        if small: groups += kd(small)
        for off, sph in big: groups.append((car.group([off], sphere=sph), sph))
    # ---- collision: one op18 per Head-On collision piece
    col = []; colpts = []; cn = 0
    for node, op, M, bb in collision_objects(n):
        if op != 26: continue
        V, Tr, F = piece(n, node)
        if not len(Tr): continue
        Wv = (np.c_[V, np.ones(len(V))] @ M)[:, :3] * scale
        if np.abs(Wv).max() > 50000: continue          # bad transform path
        r = build_piece(Wv, Tr)
        if r is None: continue
        nodes, broot, _ = r
        used = Wv[np.unique(Tr)]
        c = (used.max(0) + used.min(0)) / 2; rad = float(np.linalg.norm(used - c, axis=1).max()) + 1.0
        while len(car.n) % 16: car.n.append(0)
        base = len(car.n)
        blob, slots, _ = encode(nodes, broot, BASE + base)
        car.n += blob; car.slots += [base + s_ for s_ in slots]
        cn += len(blob) // 0x20
        hdr = bytearray(0x20)
        struct.pack_into('<IffI3fI', hdr, 0, 0x12, rad * rad, rad, BASE + base, *c, 0)
        o18 = car.append(bytes(hdr)); car.slots.append(o18 + 0xC)
        wrap = car.group([o18], sphere=(*c, rad), flags=2)   # alone in an op1 (the grid's path leaf); flag 2 = holds collision
        col.append((wrap, (*c, rad))); colpts.append(used)
    colgroups = []
    for i in range(0, len(col), 250):
        part = col[i:i + 250]
        cs = np.array([s_[:3] for _, s_ in part]); c = tuple((cs.max(0) + cs.min(0)) / 2)
        r = max(math.dist(c, s_[:3]) + s_[3] for _, s_ in part)
        g_ = car.group([o for o, _ in part], sphere=(*c, r), flags=2)   # hdTraverse_hdcar skips groups without flag 2
        groups.append((g_, (*c, r))); colgroups.append((g_, part))
    allc = np.array([g[1][:3] for g in groups]); cc = tuple((allc.max(0) + allc.min(0)) / 2)
    rr = max(math.dist(cc, g[1][:3]) + g[1][3] for g in groups)
    root = car.group([g for g, _ in groups], sphere=(*cc, rr), flags=3)   # 1 = drawable, 2 = collision below
    # ---- op15 collision grid (hdColGrid): cols x rows inline cell pointers after a 0x20 header
    # {0xf, u16 cols, f32 cell, f32 minx, miny, maxx, maxy, run-time table}; a cell -> linked entries {next, path};
    # path {0, n, n node pointers from the entry root down to the op1 that holds one op18}
    P = np.concatenate(colpts) if colpts else np.zeros((1, 3))
    x0, y0 = math.floor(P[:, 0].min() - 100), math.floor(P[:, 1].min() - 100)
    cols = int(math.ceil((P[:, 0].max() + 100 - x0) / 100.0)); rows = int(math.ceil((P[:, 1].max() + 100 - y0) / 100.0))
    prefix = (dn['chain_id1'] if dn else []) + [root]
    cells = [[] for _ in range(cols * rows)]
    for g_, part in colgroups:
        for w_, (cx, cy, cz, r) in part:
            pth = prefix + [g_, w_]
            blob = struct.pack('<2I', 0, len(pth)) + b''.join(struct.pack('<I', BASE + q) for q in pth)
            po = car.append(blob); car.slots += [po + 8 + 4 * k for k in range(len(pth))]
            for j in range(max(0, int((cy - r - y0) // 100)), min(rows, int((cy + r - y0) // 100) + 1)):
                for i_ in range(max(0, int((cx - r - x0) // 100)), min(cols, int((cx + r - x0) // 100) + 1)):
                    cells[j * cols + i_].append(po)
    ents_start = None; heads = [0] * len(cells)
    for k, lst in enumerate(cells):
        nxt = None
        for po in lst:
            e_ = car.append(struct.pack('<2I', 0, 0) + b'\0' * 8)
            if ents_start is None: ents_start = e_
            car.setp(e_ + 4, po)
            if nxt is not None: car.setp(e_, nxt)
            nxt = e_
        heads[k] = nxt
    g15 = bytearray(0x20 + 4 * cols * rows)
    struct.pack_into('<IIf4f', g15, 0, 0xf, cols, 100.0, x0, y0, x0 + 100.0 * cols, y0 + 100.0 * rows)
    e15 = car.append(bytes(g15))
    # +0x1C: a second cols x rows table the game fills at run time (dynamic objects per cell, hdcar); zero on disc
    dyn = car.append(bytes(4 * cols * rows)); car.setp(e15 + 0x1C, dyn)
    for k, h_ in enumerate(heads):
        if h_ is not None: car.setp(e15 + 0x20 + 4 * k, h_)
    ncell = cols * rows
    if dn:
        # donor: the id-1 node now holds our tree; id-14 extra collision off; the entry point to its op15 grid
        # replaced by ours
        o1 = dn['id1']
        struct.pack_into('<H', car.n, o1 + 8, 1)
        car.setp(o1 + 0x20, root)
        struct.pack_into('<f3ff', car.n, o1 + 0xC, rr * rr, *cc, rr)
        for o in dn['id14']:
            w0 = struct.unpack_from('<I', car.n, o)[0]; struct.pack_into('<I', car.n, o, w0 & 0x3ffff)
        ne_ = struct.unpack_from('<I', car.n, 0)[0]
        for i_ in range(ne_):
            if struct.unpack_from('<I', car.n, 4 + 4 * i_)[0] == BASE + dn['op15']:
                struct.pack_into('<I', car.n, 4 + 4 * i_, BASE + e15)
    else:
        e7 = car.append(struct.pack('<4I', 7, 0, 0, 0))
        hdr = struct.pack('<4I', 3, BASE + root, BASE + e15, BASE + e7)
        car.n[0:16] = hdr
    os.makedirs(outdir, exist_ok=True)
    files = {'NGP': car.ngp_bytes(), 'PTR': car.ptr_bytes(),
             'TEX': LT.tex_bytes(dn['keep_t'] if dn else ()), 'RTX': LT.rtx_bytes(dn['keep_r'] if dn else ())}
    pk, seen = pkp_convert(b['pkp'], scale); files['PKP'] = pk
    for ext, d in files.items(): open(f'{outdir}/{name}.{ext}', 'wb').write(d)
    import meshconv as _mc
    rep = dict(color_scale=round(_mc.COLOR_SCALE, 3), donor_compacted=dn.get('compacted', 0) if dn else 0, donor_dropped_tex=dn['dropped'] if dn else 0, to4=len(LT.to4), meshes=len(meshes), groups=len(groups), textures=len(LT.map), halved=len(LT.half), missing_tex=len(missing),
               tex_bytes=len(files['TEX']), tex_budget=TEX_BUDGET, clut_blocks=LT.next_cbp, clut_budget=CLUT_BUDGET,
               ngp=len(files['NGP']), ptr=len(files['PTR']), col_pieces=len(col), bsp_nodes=cn, grid=(cols, rows), grid_entries=sum(map(len, cells)), unhandled=dict(unk), pickups=dict(sorted(seen.items())))
    return rep

if __name__ == '__main__':
    sc = float(sys.argv[4]) if len(sys.argv) > 4 and sys.argv[4] != '-' else 1.15
    print(build(sys.argv[1], sys.argv[2], sys.argv[3], sc, sys.argv[5] if len(sys.argv) > 5 else None))
