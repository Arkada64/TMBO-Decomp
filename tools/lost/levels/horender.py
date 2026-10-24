import sys, struct, numpy as np
sys.path.insert(0, '/home/claude/lost')
from homesh import find_packets, decode, triangles
from PIL import Image, ImageDraw
def tris_of(n):
    out = []; bad = 0
    for o in find_packets(n):
        try: m = decode(n, o)
        except Exception: bad += 1; continue
        P = m['pos']
        for (a, _), (b, _), (c, _) in triangles(m):
            out.append((P[a], P[b], P[c]))
    return np.array(out, np.float64), bad
def render(T, path, px=1400):
    xs = T[:, :, 0]; ys = T[:, :, 1]; zs = T[:, :, 2]
    x0, x1, y0, y1 = np.percentile(xs, 0.5), np.percentile(xs, 99.5), np.percentile(ys, 0.5), np.percentile(ys, 99.5)
    s = px / max(x1 - x0, y1 - y0)
    W, H = int((x1 - x0) * s) + 20, int((y1 - y0) * s) + 20
    im = Image.new('RGB', (W, H), (10, 10, 14)); dr = ImageDraw.Draw(im)
    z = zs.mean(1); zlo, zhi = np.percentile(z, 2), np.percentile(z, 98)
    order = np.argsort(z)
    for i in order:
        t = T[i]
        e1 = t[1] - t[0]; e2 = t[2] - t[0]; nz = e1[0] * e2[1] - e1[1] * e2[0]
        k = min(max((z[i] - zlo) / max(zhi - zlo, 1e-6), 0), 1)
        col = (int(40 + 200 * k), int(80 + 150 * k), int(150 - 80 * k))
        pts = [((p[0] - x0) * s + 10, H - ((p[1] - y0) * s + 10)) for p in t]
        dr.polygon(pts, fill=col)
    im.save(path); return (x0, x1, y0, y1, zlo, zhi)
if __name__ == '__main__':
    for f in sys.argv[1:]:
        n = open(f'/home/claude/hc/{f}.ngp', 'rb').read()
        T, bad = tris_of(n)
        print(f, 'tris', len(T), 'bad packets', bad, 'bounds', render(T, f'/home/claude/hc/{f}_top.png') if len(T) else None)
