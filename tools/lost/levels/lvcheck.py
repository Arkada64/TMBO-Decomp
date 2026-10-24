"""Check a built TMB level: walk the NGP (entry point -> op1 groups -> op0), decode every mesh with the TMB decoder,
verify PTR slots / texture pairs / TEX ids, and render a top-down view (texture average colours).
  python3 lvcheck.py DIR NAME"""
import sys, os, struct, collections
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.dirname(HERE)); sys.path.insert(0, '/home/claude/lost')
from tmbmesh import decode, triangles
from textconv import records, tex_rec_size
from PIL import Image, ImageDraw
BASE = 0x980000
def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def check(d, name):
    n = open(f'{d}/{name}.NGP', 'rb').read(); p = open(f'{d}/{name}.PTR', 'rb').read(); t = open(f'{d}/{name}.TEX', 'rb').read()
    N = u32(p, 0); slots = [u32(p, 4 + 4 * i) for i in range(N)]; M = u32(p, 4 + 4 * N)
    pairs = [(u32(p, 8 + 4 * N + 8 * i), u32(p, 12 + 4 * N + 8 * i)) for i in range(M)]
    bad = sum(1 for s in slots if not (BASE <= u32(n, s) < BASE + len(n)))
    ids = {gs & 0xffff for o, b, gs, k in records(t, tex_rec_size)}
    pid = {struct.unpack_from('<H', n, a)[0] for a, g in pairs}
    root = u32(n, 4) - BASE
    meshes = []; st = [root]
    while st:
        o = st.pop(); op = u32(n, o) & 0x3f
        if op == 1: st += [u32(n, o + 0x20 + 4 * i) - BASE for i in range(struct.unpack_from('<H', n, o + 8)[0])]
        elif op == 0: meshes.append(o)
    tris = []
    for o in meshes:
        m = decode(n, o)
        P = np.array(m['pos'])
        for i0, i1, i2, s, _ in triangles(m): tris.append(P[[i0, i1, i2]])
    T = np.array(tris)
    print(name, 'slots', N, 'bad slots', bad, 'tex pairs', M, 'tex ids', len(ids), 'ids missing', len(pid - ids), 'meshes', len(meshes), 'tris', len(T))
    e = np.max(np.abs(T - np.roll(T, 1, axis=1)).sum(2), 1); T = T[e < 1700]   # sky dome
    xs, ys, zs = T[..., 0], T[..., 1], T[..., 2]
    x0, x1, y0, y1 = np.percentile(xs, 1), np.percentile(xs, 99), np.percentile(ys, 1), np.percentile(ys, 99)
    s = 1200 / max(x1 - x0, y1 - y0); W, H = int((x1 - x0) * s) + 20, int((y1 - y0) * s) + 20
    im = Image.new('RGB', (W, H), (10, 10, 14)); dr = ImageDraw.Draw(im)
    z = zs.mean(1); lo, hi = np.percentile(z, 2), np.percentile(z, 98)
    for i in np.argsort(z):
        k = min(max((z[i] - lo) / max(hi - lo, 1e-6), 0), 1)
        dr.polygon([((q[0] - x0) * s + 10, H - ((q[1] - y0) * s + 10)) for q in T[i]], fill=(int(40 + 200 * k), int(80 + 150 * k), int(150 - 80 * k)))
    im.save(f'{d}/{name}_check.png')
if __name__ == '__main__':
    check(sys.argv[1], sys.argv[2])
