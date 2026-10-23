"""Gold Tooth's Head-On body leaves one rear side window open (x<0; the x>0 side has its pane): mirror the
outer-shell triangles of the closed side into the spots the open side doesn't cover."""
import numpy as np

RES, Y0, Y1, Z0, Z1 = 0.05, -12.5, 11.5, -3.0, 5.0
WIN_Y, WIN_Z = (-6.5, -1.0), (0.3, 3.6)    # the rear side window opening
SHELL_X = 2.4          # |x| beyond this = the cab's outer side walls


def tris_full(m):
    out = []
    for s in m['strips']:
        idx = s['idx']; par = 0
        for i in range(2, len(idx)):
            if i in s['brk']:
                if i - 1 not in s['brk']:
                    par = i
                continue
            a, b, c = i - 2, i - 1, i
            if (i - par) % 2:
                a, b = b, a
            out.append((s, (a, b, c)))
    return out


def _side_tris(ms):
    out = {'L': [], 'R': []}
    for m in ms:
        P = np.array(m['pos'], float)
        for s, t in tris_full(m):
            v = P[[s['idx'][k] for k in t]]
            nr = np.cross(v[1] - v[0], v[2] - v[0]); ln = np.linalg.norm(nr)
            cx = v[:, 0].mean()
            if ln == 0 or abs(nr[0] / ln) < 0.3 or abs(cx) < SHELL_X:
                continue
            out['L' if cx < 0 else 'R'].append((m, s, t, v))
    return out


def _mask(tris):
    W, H = int((Y1 - Y0) / RES), int((Z1 - Z0) / RES)
    yy, zz = np.meshgrid(np.arange(W) * RES + Y0, np.arange(H) * RES + Z0)
    mk = np.zeros((H, W), bool)
    for m, s, t, v in tris:
        (y0, z0), (y1, z1), (y2, z2) = v[:, 1:]
        d = (y1 - y0) * (z2 - z0) - (y2 - y0) * (z1 - z0)
        if d == 0:
            continue
        l1 = ((yy - y0) * (z2 - z0) - (y2 - y0) * (zz - z0)) / d
        l2 = ((y1 - y0) * (zz - z0) - (yy - y0) * (z1 - z0)) / d
        mk |= (l1 >= -0.01) & (l2 >= -0.01) & (l1 + l2 <= 1.01)
    return mk


def patch(ms):
    """ms: decoded Head-On meshes of one damage state -> extra mesh (homesh.decode shape) or None"""
    st = _side_tris(ms)
    mk = {k: _mask(v) for k, v in st.items()}
    pos, nrm, strips = [], [], []
    for src, dst in (('R', 'L'), ('L', 'R')):
        H, W = mk[dst].shape
        for m, s, t, v in st[src]:
            cy, cz = v[:, 1].mean(), v[:, 2].mean()
            j, i = int((cy - Y0) / RES), int((cz - Z0) / RES)
            if not (WIN_Y[0] <= cy <= WIN_Y[1] and WIN_Z[0] <= cz <= WIN_Z[1]) or mk[dst][i, j]:
                continue
            base = len(pos)
            a, b, c = t
            for k in (a, c, b):                       # mirrored: swap two corners to keep the winding outward
                pi = s['idx'][k]
                x, y, z = m['pos'][pi]; pos.append((-x, y, z))
                nx, ny, nz = m['nrm'][pi] if pi < len(m['nrm']) else (0, 0, 1)
                nrm.append((-nx, ny, nz))
            strips.append(dict(idx=[base, base + 1, base + 2], brk=set(),
                               col=[s['col'][k] if k < len(s['col']) else 0xFFFF for k in (a, c, b)],
                               uv=[s['uv'][k] if k < len(s['uv']) else (0, 0) for k in (a, c, b)],
                               tag=s['tag'], texsrc=m['texrefs']))
    if not strips:
        return None
    m0 = next(m for m in ms if m['texrefs'] == [0x73ff0])
    strips = [x for x in strips if x.pop('texsrc') == m0['texrefs']]      # gold shell only (one texture)
    return dict(m0, pos=pos, nrm=nrm, strips=strips, hdr=-1) if strips else None
