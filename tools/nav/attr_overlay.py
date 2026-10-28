"""attr_overlay.py NAME PTS OUT.png [NAVDIR] : route map (all walkable components) + attractor graph."""
import sys, pickle, numpy as np
import os; _d = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, _d); sys.path.insert(0, os.path.join(_d, '../peds'))
import navbuild, pts as ptsmod
from PIL import Image, ImageDraw, ImageFont
EXC = dict(freeway=[(-90, 150, -2910, -2070, -1e9, 10.5), (-640, -380, 1580, 1780, 100, 1e9)],
           junkyard=[(-430, -320, -570, -450, -1e9, 1e9)])
name, ptsf, out = sys.argv[1:4]
D = sys.argv[4] if len(sys.argv) > 4 else '.'   # folder with NAME_H.npy / NAME_R.pkl
H = np.load(f'{D}/{name}_H.npy'); R = pickle.load(open(f'{D}/{name}_R.pkl', 'rb'))
for xa, xb, ya, yb, zl, zt in EXC.get(name, []):
    ia, ib = int((xa - R["x0"]) / R["step"]), int((xb - R["x0"]) / R["step"]) + 1
    ja, jb = int((ya - R["y0"]) / R["step"]), int((yb - R["y0"]) / R["step"]) + 1
    sub = H[:, ja:jb, ia:ib]; cut = np.isfinite(sub) & (sub < zt) & (sub > zl); sub[cut] = np.nan
lat = 8
G = navbuild.build(H, R, lat)
rec, z, nb = G['rec'], G['z'], G['nb']; N = len(rec)
comp = -np.ones(N, int); sizes = []
for s in range(N):
    if comp[s] >= 0: continue
    c = len(sizes); st = [s]; comp[s] = c; n = 0
    while st:
        a = st.pop(); n += 1
        for b in nb[a]:
            if b >= 0 and comp[b] < 0: comp[b] = c; st.append(b)
    sizes.append(n)
sizes = np.array(sizes); main = sizes.argmax()
# world coords of nodes
X = R['x0'] + rec[:, 4] * R['step']; Y = R['y0'] + rec[:, 3] * R['step']
# base image: hill-shaded top surface, no-ground = soft slate (not dark)
top = H[0].astype(float); g = np.isfinite(top)
zz = np.where(g, top, np.nanmin(top[g])); lo, hi = np.percentile(zz[g], 2), np.percentile(zz[g], 98)
gy, gx = np.gradient(zz, R['step']); shade = np.clip(0.6 + (-gx - gy) * 0.3 / np.sqrt(1 + gx*gx + gy*gy), 0.35, 1)
v = np.clip((zz - lo) / max(hi - lo, 1), 0, 1)
img = np.zeros(zz.shape + (3,)); img[..., 0] = 120 + 110 * v; img[..., 1] = 120 + 105 * v; img[..., 2] = 112 + 90 * v
img *= shade[..., None]; img[~g] = (150, 160, 180)
ny, nx = zz.shape
S = max(1, round(1600 / max(nx, ny)))   # upscale small grids so lines are readable
im = Image.fromarray(img[::-1].clip(0, 255).astype(np.uint8)).resize((nx * S, ny * S), Image.NEAREST)
d = ImageDraw.Draw(im)
P = lambda x, y: ((x - R['x0']) / R['step'] * S, (ny - 1 - (y - R['y0']) / R['step']) * S)
PAL = [(255, 150, 40), (230, 70, 200), (60, 200, 220), (240, 220, 40), (150, 110, 255), (255, 90, 90), (120, 230, 120)]
col = {main: (40, 170, 60)}
A = ptsmod.parse(open(ptsf, 'rb').read())
snap = []
for a in A:
    x, y, zp = a['p']; dd = (X - x) ** 2 + (Y - y) ** 2 + ((z - zp) * 2) ** 2
    m = int(dd.argmin()); snap.append(comp[m] if (X[m]-x)**2 + (Y[m]-y)**2 < 48**2 and abs(z[m]-zp) < 24 else -1)
order = [c for c in np.argsort(-sizes) if c != main and c in snap]   # only parts the attractor graph uses
for k, c in enumerate(order): col[c] = PAL[k % len(PAL)]
for n in range(N):
    c = comp[n]
    if c not in col: continue
    q = P(X[n], Y[n]); r = max(1, S * lat // 4)
    d.rectangle([q[0] - r, q[1] - r, q[0] + r, q[1] + r], fill=col[c])
nj = 0
for i, a in enumerate(A):
    for k in a['links']:
        if k >= len(A) or k < i and i in A[k]['links']: continue
        ca, cb = snap[i], snap[k]
        if ca >= 0 and ca == cb: fill, w = (255, 255, 255), max(1, S)
        elif ca >= 0 and cb >= 0: fill, w = (255, 230, 0), 3 * S; nj += 1          # crosses route-map parts: jump link
        else: fill, w = (255, 60, 60), 2 * S                                    # an end is off the route map
        d.line([P(*a['p'][:2]), P(*A[k]['p'][:2])], fill=fill, width=w)
for i, a in enumerate(A):
    q = P(*a['p'][:2]); r = 3 * S
    d.ellipse([q[0] - r, q[1] - r, q[0] + r, q[1] + r], fill=(30, 90, 230) if snap[i] >= 0 else (255, 60, 60), outline=(255, 255, 255))
# legend (light panel)
f = ImageFont.load_default()
L = [((40, 170, 60), 'route map (what bots use now)'), ((255, 150, 40), 'other drivable parts with attractors (not on the route map)'),
     ((255, 255, 255), 'attractor link inside one part'), ((255, 230, 0), 'attractor link joining two parts (jump link)'),
     ((255, 60, 60), 'attractor point / link off the route map')]
d.rectangle([8, 8, 330, 16 + 16 * len(L) + 16], fill=(235, 235, 225), outline=(90, 90, 90))
d.text((16, 12), f'{name.upper()}: {len(A)} attractors, {nj} jump links', fill=(20, 20, 20), font=f)
for k, (c, t) in enumerate(L):
    y = 30 + 16 * k; d.rectangle([16, y, 28, y + 10], fill=c, outline=(60, 60, 60)); d.text((36, y - 1), t, fill=(20, 20, 20), font=f)
im.save(out)
print(name, 'nodes', N, 'parts', len(sizes), 'main', sizes[main], 'shown', len(order), 'attr', len(A), 'off', snap.count(-1), 'jumps', nj, im.size)
