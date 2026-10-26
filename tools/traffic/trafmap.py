#!/usr/bin/env python3
"""trafmap.py NAVDIR LEVEL [EMULOG ...] -> LEVEL_traffic.png
Top-down map of a level (the nav heightfield NAVDIR/LEVEL_H.npy, hill-shaded: top surface) with the traffic
routes from TRAFFIC_TRACE runs ("TMBR tt" lines: every car every 0.5 s): one line per car, street cars orange,
highway cars cyan; a white ring = where each car first appeared (spawn), a red cross = the spot a car vanished
(destroyed / respawned). Jumps far beyond the car's usual 0.5 s step start a new segment (respawns, teleports)."""
import sys, re, pickle, numpy as np
from PIL import Image, ImageDraw, ImageFont

def base(H, R):
    top = H[0].astype(np.float64); g = np.isfinite(top)
    z = np.where(g, top, np.nanmin(top[g]) if g.any() else 0)
    lo, hi = np.percentile(z[g], 2), np.percentile(z[g], 98)
    gy, gx = np.gradient(z, R['step'])
    shade = np.clip(0.55 + (-gx - gy) * 0.35 / np.sqrt(1 + gx * gx + gy * gy), 0, 1)   # light from the top left
    v = np.clip((z - lo) / max(hi - lo, 1), 0, 1)
    img = np.zeros(z.shape + (3,))
    img[..., 0] = 90 + 120 * v; img[..., 1] = 96 + 114 * v; img[..., 2] = 88 + 90 * v
    img *= shade[..., None]
    img[~g] = (12, 12, 16)
    return Image.fromarray(img[::-1].clip(0, 255).astype(np.uint8))

def tracks(logs, level):
    T = {}
    rx = re.compile(r'TMBR tt (\d+) (\d+) (\d+): (.*)')
    for f in logs:
        for line in open(f, errors='replace'):
            m = rx.search(line)
            if not m or int(m.group(2)) != level: continue
            t, j0 = int(m.group(1)), int(m.group(3))
            for q, c in enumerate(m.group(4).split('|')):
                x, y, z, k = map(int, c.split())
                if k < 0: continue
                T.setdefault((f, j0 + q), []).append((t, x, y, z, k))
    return T

def main():
    nav, name = sys.argv[1], sys.argv[2]
    LEVEL = dict(suburb=0, freeway=2, city=5, loop=6, minicity=17, miniburb=18)
    H = np.load(f'{nav}/{name}_H.npy'); R = pickle.load(open(f'{nav}/{name}_R.pkl', 'rb'))
    im = base(H, R).convert('RGB'); d = ImageDraw.Draw(im); ny = H.shape[1]
    P = lambda x, y: ((x - R['x0']) / R['step'], ny - 1 - (y - R['y0']) / R['step'])
    pts = [a for a in sys.argv[3:] if a.upper().endswith('.PTS')]
    logs = [a for a in sys.argv[3:] if not a.upper().endswith('.PTS')]
    for f in pts:      # the level's attractor points (PTS) + links, faint: the street graph traffic lanes come from
        sys.path.insert(0, __import__('os').path.join(__import__('os').path.dirname(__file__), '../peds'))
        import pts as ptsmod
        G = ptsmod.parse(open(f, 'rb').read())
        for a in G:
            for k in a['links']:
                if k < len(G): d.line([P(*a['p'][:2]), P(*G[k]['p'][:2])], fill=(110, 140, 255), width=1)
        for a in G:
            q = P(*a['p'][:2]); d.ellipse([q[0] - 3, q[1] - 3, q[0] + 3, q[1] + 3], fill=(110, 140, 255))
    # the street points the game loaded ("TMBR tp" lines, TRAFFIC_TRACE builds): the lanes, faint green
    rxp = re.compile(r'TMBR tp (\d+) (\d+): (-?\d+) (-?\d+) (-?\d+) n (-?\d+) k (-?\d+) l (.*)')
    SP = {}
    for f in logs:
        for line in open(f, errors='replace'):
            m = rxp.search(line)
            if m and int(m.group(1)) == LEVEL[name]:
                SP[int(m.group(2))] = (int(m.group(3)), int(m.group(4)), [int(x) for x in m.group(8).split()][:max(0, int(m.group(6)))])
    for i, (x, y, L) in SP.items():
        for k in L:
            if k in SP: d.line([P(x, y), P(*SP[k][:2])], fill=(90, 230, 120), width=2)
            else: q = P(x, y); d.line([q[0], q[1], q[0] + 25, q[1] - 25], fill=(255, 0, 255), width=3)  # link to a missing point
    for i, (x, y, L) in SP.items():
        q = P(x, y); d.ellipse([q[0] - 4, q[1] - 4, q[0] + 4, q[1] + 4], fill=(90, 230, 120))
    T = tracks(logs, LEVEL[name])
    W = max(2, int(max(im.size) / 700))
    nst = nhw = 0
    for key, pts in T.items():
        alive = [p for p in pts if p[4] > 0]
        if not alive: continue
        hw = alive[0][4] == 2; nhw += hw; nst += not hw
        col = (80, 220, 255) if hw else (255, 150, 40)
        steps = sorted(abs(b[1] - a[1]) + abs(b[2] - a[2]) for a, b in zip(alive, alive[1:])) or [0]
        jump = max(150, 4 * steps[len(steps) // 2])     # a respawn / teleport: far more than this car's usual 0.5 s
        seg = [alive[0]]
        def flush():
            if len(seg) > 1: d.line([P(p[1], p[2]) for p in seg], fill=col, width=W)
        for p in alive[1:]:
            if abs(p[1] - seg[-1][1]) + abs(p[2] - seg[-1][2]) > jump or p[0] - seg[-1][0] > 2:
                flush()
                a = P(seg[-1][1], seg[-1][2]); r = 3 * W
                d.line([a[0] - r, a[1] - r, a[0] + r, a[1] + r], fill=(255, 40, 40), width=W)
                d.line([a[0] - r, a[1] + r, a[0] + r, a[1] - r], fill=(255, 40, 40), width=W)
                seg = [p]
            else: seg.append(p)
        flush()
        s = P(alive[0][1], alive[0][2]); r = 4 * W
        d.ellipse([s[0] - r, s[1] - r, s[0] + r, s[1] + r], outline=(255, 255, 255), width=W)
    s = max(1, max(im.size) // 1600)
    if s > 1: im = im.resize((im.size[0] // s, im.size[1] // s), Image.LANCZOS)
    d = ImageDraw.Draw(im)
    try: font = ImageFont.truetype('/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf', 22)
    except Exception: font = None
    d.text((12, 10), f'{name.upper()}  traffic: {nst} street, {nhw} highway  (white ring = spawn, red x = car gone)', fill=(255, 255, 255), font=font)
    im.save(f'{name}_traffic.png'); print(name, 'street', nst, 'highway', nhw, im.size)

if __name__ == '__main__':
    main()
