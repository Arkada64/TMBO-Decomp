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


TEXS = None
DONOR_LEN = 0                                  # --donor-len N: meshes whose texture ids are all <= N (the donor's) drawn magenta                                    # --tex: (texture id, CBP) -> RGBA image
FORM = 0
ALLSW = False
#                                      # Sweet Tooth's op6 R+25: 0 truck, 1 robot (--robot)


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
            nt_ = struct.unpack_from('<H', n, o + 0x5a)[0]
            tids_ = [struct.unpack_from('<H', n, o + 0x50 + 2 * i)[0] for i in range(min(nt_, 4))]
            if DONOR_LEN and tids_ and max(tids_) <= DONOR_LEN and kind in ('car', 'char'):
                out.append((P, tr, 'donor')); DONORS.append((o, P.min(0).round(2).tolist(), P.max(0).round(2).tolist(), len(tr), ch, tids_)); continue
            if tr and TEXS is not None:                  # textured: one part per texture select
                nt = struct.unpack_from('<H', n, o + 0x5a)[0]
                imgs = [TEXS(struct.unpack_from('<H', n, o + 0x50 + 2 * i)[0],
                             (struct.unpack_from('<Q', n, o + 0x70 + 0x30 * i)[0] >> 37) & 0x3fff) for i in range(nt)]
                sel, cur = {}, 0
                for s_ in m['strips']:
                    if s_['tag'][3]:
                        cur = (s_['tag'][3] - 1) // 3
                    sel[id(s_)] = cur
                grp = {}
                for a_, b_, c_, s_, (i0, i1, i2) in triangles(m):
                    grp.setdefault(sel[id(s_)], []).append(((a_, b_, c_), [(-s_['uv'][j][0] / 4096, -s_['uv'][j][1] / 4096)
                                                                       if j < len(s_['uv']) else (0, 0) for j in (i0, i1, i2)]))
                for k_, lst in grp.items():
                    out.append((P, [x[0] for x in lst], kind, [x[1] for x in lst], imgs[k_] if k_ < len(imgs) else None))
            elif tr:
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
            vc = struct.unpack_from('<h', n, o + 0x10)[0]
            if vals is not None and vc >= 0 and vals.get(vc, 1.0) == 0:
                continue                         # skeletonTraverse skips a bone whose weight channel is 0
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
        elif op == 6 and ALLSW:
            ks = [k for k in ks if u32(n, k) & 0x3f != 9]
        elif op == 6:                          # effect switches (shield / freeze shells, flames: id R+14, R+15 ..)
            rel = (h >> 18) - R                  # stay off; weapons / guns / lights / brake lights on their 1st kid
            ks = [k for k in ks if u32(n, k) & 0x3f != 9][:1] if (h >> 18) == 0 or rel in (7, 9, 10, 13) else \
                [k for k in ks if u32(n, k) & 0x3f != 9][FORM:FORM + 1] if rel == 25 else []
        if op == 1 and (h >> 18) == R + 5:       # shadow
            ks = []
        for k in ks:
            st.append((k, M, t, kind, vals, ch))
    return out, lights


DONORS = []
COL = {'donor': (1.0, 0.0, 1.0), 'car': (0.75, 0.75, 0.75), 'weapon': (1.0, 0.15, 0.1), 'gun': (1.0, 0.6, 0.1), 'char': (0.3, 0.4, 1.0)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('dir'); ap.add_argument('code'); ap.add_argument('out')
    ap.add_argument('--time', type=float, default=None)
    ap.add_argument('--views', default='side,top,front,iso')
    ap.add_argument('--size', type=int, default=360)
    ap.add_argument('--tex', action='store_true', help='textured (TEX / RTX of the car)')
    ap.add_argument('--rear', action='store_true', help='turned 180 degrees (the front view shows the back)')
    ap.add_argument('--robot', action='store_true', help="Sweet Tooth donors: draw the robot form")
    ap.add_argument('--donor-len', type=lambda x: int(x, 0), default=0, help="highest donor texture id: kept donor meshes magenta + listed")
    ap.add_argument('--all-switch', action='store_true', help='op6 weapon / effect switches: draw every kid')
    a = ap.parse_args()
    rd = lambda e: open('%s/%s.%s' % (a.dir, a.code, e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), b'', b'')
    if a.tex:
        global TEXS
        from textconv import records, tex_rec_size, rtx_records
        from tmbprev import image
        t_, r_ = rd('TEX'), rd('RTX')
        byid = {gs & 0xffff: dict(off=o, bytes=b, gs=gs, tw=(gs >> 40) & 15, th=(gs >> 44) & 15)
                for o, b, gs, k in records(t_, tex_rec_size)}
        rr, _ = rtx_records(r_)
        clut = {a_: (o, sz, tw, th) for o, sz, a_, tw, th in rr}
        TEXS = lambda tid, cbp: image(t_, r_, byid, clut, tid, cbp)
    global FORM, DONOR_LEN, ALLSW
    DONOR_LEN = a.donor_len; ALLSW = a.all_switch
    FORM = 1 if a.robot else 0
    parts, lights = collect(car, a.time)
    if a.rear:
        parts = [(p[0] * np.array([-1, -1, 1]),) + tuple(p[1:]) for p in parts]
        lights = [L * np.array([-1, -1, 1]) for L in lights]
    ms = [dict(pos=p[0], tris=p[1], col=COL[p[2]], **(dict(uvs=p[3], tex=p[4]) if len(p) > 3 and p[2] == 'car' else {}))
          for p in parts]
    for L in lights:                           # a small yellow octahedron per light
        r = 0.35
        P = np.array([[r, 0, 0], [-r, 0, 0], [0, r, 0], [0, -r, 0], [0, 0, r], [0, 0, -r]]) + L
        ms.append(dict(pos=P, tris=[(0, 2, 4), (2, 1, 4), (1, 3, 4), (3, 0, 4), (2, 0, 5), (1, 2, 5), (3, 1, 5), (0, 3, 5)],
                       col=(1.0, 1.0, 0.0)))
    render(ms, a.out, a.size, tuple(a.views.split(',')))
    print('%d meshes, %d lights' % (len(parts), len(lights)))
    for o, lo, hi, nt, ch, ti in DONORS:
        print('donor mesh %#x tex %s tris %d box %s %s path %s' % (o, ti, nt, lo, hi, ' '.join('%#x:%d/%d' % (c, u32(car.n, c) & 0x3f, u32(car.n, c) >> 18) for c in ch[-5:-1])))


if __name__ == '__main__':
    main()
