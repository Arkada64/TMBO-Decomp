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
TILE = 1200.0                 # render groups: square tiles (culling)

def packet_of(n, o):
    q = o
    while q < o + 0x400 and not ((int.from_bytes(n[q:q + 4], 'little') >> 16) == 0x6000 and int.from_bytes(n[q + 4:q + 8], 'little') == 0):
        q += 16
    return q

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

def donor_prepare(car, drop=None):
    """TMB level used as the base: its shared assets (weapons, pickup models, effects: callback ids >= 3000)
    stay; its arena (callback id 1 = render + collision, id 14 = extra collision) goes. Returns the id-1 node,
    the id-14 nodes, the op15 grid node, texture records / CLUT records to keep, next free texture id / CLUT block."""
    from ngptrav import traverse
    from textconv import records, tex_rec_size, rtx_rec_size
    n = bytes(car.n); u = lambda o: struct.unpack_from('<I', n, o)[0]
    v = traverse(n, [4 + 4 * i for i in range(u(0))])
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
    drop_c = {cbp_of[t] for t in drop} - used_cbp
    keep_r = [bytes(car.rtx[o:o + b]) for o, b, gs, k in rr if ((gs >> 16) & 0xffff) not in drop_c]
    next_id = max(gs & 0xffff for o, b, gs, k in tr) + 1
    next_cbp = max(((gs >> 16) & 0xffff) + clut_blocks((gs >> 40) & 15, (gs >> 44) & 15) for o, b, gs, k in rr
                   if ((gs >> 48) & 0xff) == 8)          # CLUT records (the others are VRAM-resident textures)
    op15 = next(u(4 + 4 * i) - BASE for i in range(u(0)) if (u(u(4 + 4 * i) - BASE) & 0x3f) == 15)
    arena_meshes = sorted(o for o in arena - asset if (u(o) & 0x3f) == 0)
    return dict(drop=drop, arena_meshes=arena_meshes, id1=id1, id14=id14, op15=op15, keep_t=keep_t, keep_r=keep_r, next_id=next_id, next_cbp=next_cbp,
                kept_bytes=sum(len(r) for r in keep_t), dropped=len(drop))

def build(path, outdir, name, scale=1.15, donor=None):
    b = bdd(path); n = b['ngp']
    meshes, unk = placed_meshes(n, scale)
    T = textures(b['tex'])
    keys = sorted({k for m in meshes for k in m['texrefs']})
    missing = [k for k in keys if k not in T]
    meshes = [m for m in meshes if all(k in T for k in m['texrefs'])]
    if donor:
        car = Car(*[open(f'{donor}.{k}', 'rb').read() for k in ('NGP', 'PTR', 'TEX', 'RTX')])
        dn = donor_prepare(car)
        from tmbcar import mesh_extent
        dead = sorted(mesh_extent(car.n, o) for o in dn['arena_meshes'])
        dead = [(a, (b + 15) & ~15) for a, b in dead]
        donor_size = len(car.n); car.compact(dead)
        dn = donor_prepare(car, dn['drop']); dn['compacted'] = donor_size - len(car.n)
        LT = LevelTex(T, dn['next_id'], dn['next_cbp'], TEX_BUDGET - dn['kept_bytes'], CLUT_BUDGET - dn['next_cbp'])
    else:
        dn = None
        LT = LevelTex(T)
        car = Car(struct.pack('<4I', 3, 0, 0, 0), struct.pack('<II', 0, 0), b'', b'')
    tex_total, clut_total = LT.plan(keys)
    tiles = collections.defaultdict(list)
    for m in meshes:
        ctx = [LT.gs_ctx(k) for k in m['texrefs']]
        try:
            blob, rel, pairs, sph = hierobject(m, 1.0, ctx)
        except Exception as e:
            continue
        off = car.append(blob, rel, pairs)
        tiles[(math.floor(sph[0] / TILE), math.floor(sph[1] / TILE))].append((off, sph))
    groups = []
    for key, lst in tiles.items():
        xs = [s[0] for _, s in lst]; ys = [s[1] for _, s in lst]; zs = [s[2] for _, s in lst]
        c = ((max(xs) + min(xs)) / 2, (max(ys) + min(ys)) / 2, (max(zs) + min(zs)) / 2)
        r = max(math.dist(c, s[:3]) + s[3] for _, s in lst)
        for i in range(0, len(lst), 250):
            part = lst[i:i + 250]
            groups.append((car.group([o for o, _ in part], sphere=(*c, r)), (*c, r)))
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
        col.append((o18, (*c, rad))); colpts.append(used)
    for i in range(0, len(col), 250):
        part = col[i:i + 250]
        cs = np.array([s_[:3] for _, s_ in part]); c = tuple((cs.max(0) + cs.min(0)) / 2)
        r = max(math.dist(c, s_[:3]) + s_[3] for _, s_ in part)
        groups.append((car.group([o for o, _ in part], sphere=(*c, r)), (*c, r)))
    allc = np.array([g[1][:3] for g in groups]); cc = tuple((allc.max(0) + allc.min(0)) / 2)
    rr = max(math.dist(cc, g[1][:3]) + g[1][3] for g in groups)
    root = car.group([g for g, _ in groups], sphere=(*cc, rr))
    P = np.concatenate(colpts) if colpts else np.zeros((1, 3))
    x0, y0 = P[:, 0].min() - 200, P[:, 1].min() - 200; x1, y1 = P[:, 0].max() + 200, P[:, 1].max() + 200
    ncell = int(math.ceil(max(x1 - x0, y1 - y0) / 100.0)) + 1
    gbuf = car.append(bytes(4 * ncell * ncell))
    if dn:
        # donor: the id-1 node now holds our tree; id-14 extra collision off; its op15 grid resized to our map
        o1 = dn['id1']
        struct.pack_into('<H', car.n, o1 + 8, 1)
        car.setp(o1 + 0x20, root)
        struct.pack_into('<f3ff', car.n, o1 + 0xC, rr * rr, *cc, rr)
        for o in dn['id14']:
            w0 = struct.unpack_from('<I', car.n, o)[0]; struct.pack_into('<I', car.n, o, w0 & 0x3ffff)
        e15 = dn['op15']
        struct.pack_into('<If4f', car.n, e15 + 4, ncell, 100.0, x0, y0, x0 + 100.0 * (ncell - 1), y0 + 100.0 * (ncell - 1))
        car.setp(e15 + 0x1C, gbuf)
    else:
        # entry points: op1 render + collision tree, op15 runtime grid (100-unit cells, filled by the game),
        # op7 object list (animated objects: none)
        g15 = bytearray(0x20)
        struct.pack_into('<IIf4fI', g15, 0, 0xf, ncell, 100.0, x0, y0, x0 + 100.0 * (ncell - 1), y0 + 100.0 * (ncell - 1), BASE + gbuf)
        e15 = car.append(bytes(g15)); car.slots.append(e15 + 0x1C)
        e7 = car.append(struct.pack('<4I', 7, 0, 0, 0))
        hdr = struct.pack('<4I', 3, BASE + root, BASE + e15, BASE + e7)
        car.n[0:16] = hdr
    os.makedirs(outdir, exist_ok=True)
    files = {'NGP': car.ngp_bytes(), 'PTR': car.ptr_bytes(),
             'TEX': LT.tex_bytes(dn['keep_t'] if dn else ()), 'RTX': LT.rtx_bytes(dn['keep_r'] if dn else ())}
    pk, seen = pkp_convert(b['pkp'], scale); files['PKP'] = pk
    for ext, d in files.items(): open(f'{outdir}/{name}.{ext}', 'wb').write(d)
    rep = dict(donor_compacted=dn.get('compacted', 0) if dn else 0, donor_dropped_tex=dn['dropped'] if dn else 0, to4=len(LT.to4), meshes=len(meshes), groups=len(groups), textures=len(LT.map), halved=len(LT.half), missing_tex=len(missing),
               tex_bytes=len(files['TEX']), tex_budget=TEX_BUDGET, clut_blocks=LT.next_cbp, clut_budget=CLUT_BUDGET,
               ngp=len(files['NGP']), ptr=len(files['PTR']), col_pieces=len(col), bsp_nodes=cn, grid=ncell, unhandled=dict(unk), pickups=dict(sorted(seen.items())))
    return rep

if __name__ == '__main__':
    sc = float(sys.argv[4]) if len(sys.argv) > 4 and sys.argv[4] != '-' else 1.15
    print(build(sys.argv[1], sys.argv[2], sys.argv[3], sc, sys.argv[5] if len(sys.argv) > 5 else None))
