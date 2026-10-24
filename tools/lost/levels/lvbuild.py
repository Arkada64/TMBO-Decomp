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
    def __init__(self, T):
        self.T = T; self.map = {}; self.recs = []; self.cluts = []; self.next_cbp = 0; self.next_id = 1
        self.half = set()
    def size(self, k):
        t = self.T[k]; h, w = t['h'], t['w']
        if k in self.half: h, w = h // 2, w // 2
        return w * h // (2 if t['bpp'] == 4 else 1)
    def plan(self, keys):
        """halve the biggest textures until the set fits the level TEX slot"""
        keys = [k for k in keys if k in self.T]
        def total(): return sum(self.size(k) + 0x80 for k in keys)
        order = sorted(keys, key=lambda k: -self.size(k))
        i = 0
        while total() > TEX_BUDGET * 0.97 and i < len(order) * 3:
            k = order[i % len(order)]
            t = self.T[k]
            if k not in self.half and t['w'] >= 32 and t['h'] >= 32: self.half.add(k)
            i += 1
        cl = sum(clut_blocks(self.T[k]['ctw'], self.T[k]['cth']) for k in keys)
        return total(), cl
    def add(self, key):
        if key in self.map: return self.map[key]
        t = self.T[key]; h, w = t['h'], t['w']
        idx = t['idx'].reshape(h, w)
        if key in self.half: idx = idx[::2, ::2]; h, w = h // 2, w // 2
        idx = idx.reshape(-1).astype(np.uint8)
        if t['bpp'] == 8: payload, psm = idx.tobytes(), 0x13
        else: payload, psm = (idx[0::2] | (idx[1::2] << 4)).astype(np.uint8).tobytes(), 0x14
        tid = self.next_id; self.next_id += 1
        tw, th = w.bit_length() - 1, h.bit_length() - 1
        nbytes = len(payload)
        self.recs.append((tid, psm, tw, th, payload))
        c = bytearray(t['clutraw'])
        for i in range(3, len(c), 4): c[i] = min(255, c[i] * 2)
        cbp = self.next_cbp; self.next_cbp += clut_blocks(t['ctw'], t['cth'])
        rgs = (cbp << 16) | (t['ctw'] << 40) | (t['cth'] << 44) | (0x08 << 48) | (0x01 << 56)
        self.cluts.append(struct.pack('<IIQ', (16 + len(c)) // 4, 0, rgs) + bytes(c))
        self.map[key] = (tid, psm, w, h, cbp)
        return self.map[key]
    def gs_ctx(self, key):
        tid, psm, w, h, cbp = self.add(key)
        return tid, struct.pack('<Q', tex0(psm, w, h, cbp)) + struct.pack('<II', 6, 0) + TEX1 + b'\0' * 16
    def tex_bytes(self):
        sizes = sorted({len(p) for *_, p in self.recs})
        bins = [1 << max(8, (s - 1).bit_length()) for s in sizes]
        classes = sorted(set(bins))
        cnt = collections.Counter()
        recs = []
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
    def rtx_bytes(self):
        out = join(self.cluts)
        return bytes(out + b'\0' * (-len(out) % 2048))

def build(path, outdir, name, scale=1.15):
    b = bdd(path); n = b['ngp']
    meshes, unk = placed_meshes(n, scale)
    T = textures(b['tex'])
    keys = sorted({k for m in meshes for k in m['texrefs']})
    missing = [k for k in keys if k not in T]
    meshes = [m for m in meshes if all(k in T for k in m['texrefs'])]
    LT = LevelTex(T)
    tex_total, clut_total = LT.plan(keys)
    car = Car(struct.pack('<4I', 1, 0, 0, 0), struct.pack('<II', 0, 0), b'', b'')
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
    allc = np.array([g[1][:3] for g in groups]); cc = tuple((allc.max(0) + allc.min(0)) / 2)
    rr = max(math.dist(cc, g[1][:3]) + g[1][3] for g in groups)
    root = car.group([g for g, _ in groups], sphere=(*cc, rr))
    struct.pack_into('<I', car.n, 4, BASE + root)
    os.makedirs(outdir, exist_ok=True)
    files = {'NGP': car.ngp_bytes(), 'PTR': car.ptr_bytes(), 'TEX': LT.tex_bytes(), 'RTX': LT.rtx_bytes()}
    pk, seen = pkp_convert(b['pkp'], scale); files['PKP'] = pk
    for ext, d in files.items(): open(f'{outdir}/{name}.{ext}', 'wb').write(d)
    rep = dict(meshes=len(meshes), groups=len(groups), textures=len(LT.map), halved=len(LT.half), missing_tex=len(missing),
               tex_bytes=len(files['TEX']), tex_budget=TEX_BUDGET, clut_blocks=LT.next_cbp, clut_budget=CLUT_BUDGET,
               ngp=len(files['NGP']), ptr=len(files['PTR']), unhandled=dict(unk), pickups=dict(sorted(seen.items())))
    return rep

if __name__ == '__main__':
    sc = float(sys.argv[4]) if len(sys.argv) > 4 else 1.15
    print(build(sys.argv[1], sys.argv[2], sys.argv[3], sc))
