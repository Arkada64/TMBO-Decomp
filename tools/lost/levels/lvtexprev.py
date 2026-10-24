"""Textured preview of a built TMB level (top view) from the TMB files only: TEX linear PSMT8/PSMT4 + RTX CLUTs."""
import sys, os, struct
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.dirname(HERE)); sys.path.insert(0, '/home/claude/lost')
from tmbmesh import decode, triangles
from textconv import records, tex_rec_size, rtx_rec_size
from hotex import clut_unswizzle
from PIL import Image
BASE = 0x980000
def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def tmb_textures(t, r):
    cl = {}
    for o, b, gs, k in records(r, rtx_rec_size):
        a, tw, th = (gs >> 16) & 0xffff, (gs >> 40) & 15, (gs >> 44) & 15; ne = (1 << tw) * (1 << th)
        p = [tuple(x) for x in np.frombuffer(r[o + 16:o + 16 + 4 * ne], np.uint8).reshape(ne, 4)]
        cl[a] = np.array(clut_unswizzle(p) if ne == 256 else p, np.uint8)
    return cl
def run(d, name, out, px=1600):
    n = open(f'{d}/{name}.NGP', 'rb').read(); t = open(f'{d}/{name}.TEX', 'rb').read(); r = open(f'{d}/{name}.RTX', 'rb').read()
    cl = tmb_textures(t, r)
    tex = {}
    for o, b, gs, k in records(t, tex_rec_size):
        tid, psm, tw, th = gs & 0xffff, (gs >> 32) & 0x3f, (gs >> 40) & 15, (gs >> 44) & 15
        w, h = 1 << tw, 1 << th
        pay = np.frombuffer(t[o + 0x80:o + 0x80 + (w * h if psm == 0x13 else w * h // 2)], np.uint8)
        idx = pay if psm == 0x13 else np.stack([pay & 15, pay >> 4], 1).reshape(-1)
        tex[tid] = (idx.reshape(h, w), psm)
    root = u32(n, 4) - BASE; st = [root]; meshes = []
    while st:
        o = st.pop(); op = u32(n, o) & 0x3f
        if op == 1: st += [u32(n, o + 0x20 + 4 * i) - BASE for i in range(struct.unpack_from('<H', n, o + 8)[0])]
        elif op == 0: meshes.append(o)
    allT = []
    for o in meshes:
        m = decode(n, o); P = np.array(m['pos'])
        nt = struct.unpack_from('<H', n, o + 0x5a)[0]
        ctx = []
        for i in range(nt):
            tid = struct.unpack_from('<H', n, o + 0x50 + 2 * i)[0]; t0 = struct.unpack_from('<Q', n, o + 0x70 + 0x30 * i)[0]
            ctx.append((tid, (t0 >> 37) & 0x3fff))
        cur = 0
        for s in m['strips']:
            if s['tag'][3]: cur = (s['tag'][3] - 1) // 3
            if not ctx: continue
            tid, cbp = ctx[min(cur, len(ctx) - 1)]
            if tid not in tex or cbp not in cl: continue
            idx, psm = tex[tid]; pal = cl[cbp]
            h, w = idx.shape
            idxs = [v[3] + s['base'] for v in s['nv']]
            for i in range(2, len(idxs)):
                tri = P[[idxs[i - 2], idxs[i - 1], idxs[i]]]
                if np.abs(tri - np.roll(tri, 1, 0)).sum(1).max() > 1700: continue
                uv = np.array([s['uv'][j] for j in (i - 2, i - 1, i)], float) / 4096.0
                cu, cv = uv.mean(0)
                col = pal[idx[int(cv * h) % h, int(cu * w) % w]][:3] if len(pal) > idx.max() else (255, 0, 255)
                allT.append((tri, col))
    T = np.array([a for a, _ in allT]); C = [c for _, c in allT]
    xs, ys = T[..., 0], T[..., 1]
    x0, x1, y0, y1 = np.percentile(xs, 1), np.percentile(xs, 99), np.percentile(ys, 1), np.percentile(ys, 99)
    s = px / max(x1 - x0, y1 - y0); W, H = int((x1 - x0) * s) + 20, int((y1 - y0) * s) + 20
    from PIL import ImageDraw
    im = Image.new('RGB', (W, H), (10, 10, 14)); dr = ImageDraw.Draw(im)
    for i in np.argsort(T[..., 2].mean(1)):
        dr.polygon([((q[0] - x0) * s + 10, H - ((q[1] - y0) * s + 10)) for q in T[i]], fill=tuple(int(c) for c in C[i]))
    im.save(out); print(out, len(T), 'tris')
if __name__ == '__main__':
    run(sys.argv[1], sys.argv[2], sys.argv[3])
