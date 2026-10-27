"""Untextured preview of a built (or retail) TMB car NGP as the game would draw it at rest, to check where weapon
models / lights end up (HC_MOUNTS). python3 carview.py DIR CODE out.png [--time T] [--views side,top,front,iso]
Draws entry point 0 with: LOD kid 0, op31 kid 0 (damage state 0 etc.), op6 switches on their first drawable kid
(weapon switches on the weapon), op17 bones in the exported pose (or the character animations at time T),
op3 / op4 transforms. Colours: grey = car, red = weapon models (op1 id 4001..), orange = machine guns (4100),
yellow dots = op5 lights, blue = other character meshes still drawn."""
import sys, struct, argparse
import numpy as np
from tmbcar import Car, u32, BASE
from hcbuild import kids
from tmbmesh import decode, triangles
import hcmounts
from trender import render


def collect(car, t_anim=None):
    n = car.n
    R = u32(n, u32(n, 4) - BASE) >> 18
    out = []                                   # (pos Nx3, tris, colour)
    lights = []
    st = [(u32(n, 4) - BASE, np.eye(3), np.zeros(3), 'car', None, ())]
    while st:
        o, M, t, kind, vals, ch = st.pop()
        if o in ch or len(ch) > 60:
            continue
        ch = ch + (o,)
        h = u32(n, o); op = h & 0x3f
        if op == 0:
            try:
                m = decode(bytes(n), o)
            except Exception:
                continue
            if not m['pos']:
                continue
            P = np.asarray(m['pos'], float) @ M + t
            tr = [(a, b, c) for a, b, c, s, _ in triangles(m)]
            if tr:
                out.append((P, tr, kind))
            continue
        if op == 5:
            lights.append(t.copy()); continue
        if op == 1 and (h >> 18) >= 4000:
            kind = 'gun' if (h >> 18) == 4100 else 'weapon'
        if op == 25:
            if kind == 'car':
                kind = 'char'
            if t_anim is not None:
                trk = hcmounts.char_tracks(car, o)
                vals = {c: hcmounts.track_value(v, t_anim) for c, v in trk.items()} if trk else None
        if op == 17:
            Rm, tt = hcmounts.bone_local(n, o, vals)
            t = tt @ M + t; M = Rm @ M
        else:
            x = hcmounts._xf(n, o)
            if x is not None:
                Rm, tt = x
                t = tt @ M + t; M = Rm @ M
        ks = kids(car, o)
        if op == 2:
            ks = ks[:1]
        elif op == 31:
            ks = [k for k in ks if u32(n, k) & 0x3f != 9][:1]
        elif op == 6:                          # effect switches (shield / freeze shells, flames: id R+14, R+15 ..)
            rel = (h >> 18) - R                  # stay off; weapons / guns / lights / brake lights on their 1st kid
            ks = [k for k in ks if u32(n, k) & 0x3f != 9][:1] if (h >> 18) == 0 or rel in (7, 9, 10, 13) else []
        if op == 1 and (h >> 18) == R + 5:       # shadow
            ks = []
        for k in ks:
            st.append((k, M, t, kind, vals, ch))
    return out, lights


COL = {'car': (0.75, 0.75, 0.75), 'weapon': (1.0, 0.15, 0.1), 'gun': (1.0, 0.6, 0.1), 'char': (0.3, 0.4, 1.0)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('dir'); ap.add_argument('code'); ap.add_argument('out')
    ap.add_argument('--time', type=float, default=None)
    ap.add_argument('--views', default='side,top,front,iso')
    ap.add_argument('--size', type=int, default=360)
    a = ap.parse_args()
    rd = lambda e: open('%s/%s.%s' % (a.dir, a.code, e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), b'', b'')
    parts, lights = collect(car, a.time)
    ms = [dict(pos=P, tris=tr, col=COL[k]) for P, tr, k in parts]
    for L in lights:                           # a small yellow octahedron per light
        r = 0.35
        P = np.array([[r, 0, 0], [-r, 0, 0], [0, r, 0], [0, -r, 0], [0, 0, r], [0, 0, -r]]) + L
        ms.append(dict(pos=P, tris=[(0, 2, 4), (2, 1, 4), (1, 3, 4), (3, 0, 4), (2, 0, 5), (1, 2, 5), (3, 1, 5), (0, 3, 5)],
                       col=(1.0, 1.0, 0.0)))
    render(ms, a.out, a.size, tuple(a.views.split(',')))
    print('%d meshes, %d lights' % (len(parts), len(lights)))


if __name__ == '__main__':
    main()
