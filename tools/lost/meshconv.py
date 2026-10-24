"""Head-On mesh (homesh.decode) -> TMB HierObject (op0) node bytes."""
import struct, math
from tmbenc import vif_packet

POOL_MAX = 180
COLOR_SCALE = 0.32
import os
ENV_MAP = os.environ.get('GT_ENV', '0') == '1'
BAKE = os.environ.get('GT_BAKE', '1') == '1'     # bake the reflection-map lookup into the UVs (static shine)
TWOSIDED = os.environ.get('GT_TWOSIDED', '1') == '1'
STRIP_MAX = 36          # longest strip seen in TMB car data
TEMPLATE_20 = bytes.fromhex('00000000000000000000803f0000803f'
                            'ffffffffffffffffffffffffffff0000'
                            '0000803f0000803f0000803f0000803f')


def c5(v):
    r, g, b, a = v & 31, (v >> 5) & 31, (v >> 10) & 31, (v >> 15) & 1
    k = COLOR_SCALE    # Head-On prelit colours are ~3x TMB's (Gold Tooth body 80, Sweet Tooth body avg 25)
    return (int((r << 3) * k), int((g << 3) * k), int((b << 3) * k), 0x80 if a else 0)


def strips_of(m, scale):
    """split Head-On strips at restart pairs -> list of (tag, [(posidx, nrm, rgba, uv)])"""
    out = []
    for s in m['strips']:
        n = len(s['idx'])
        cuts = [0] + sorted(k for k in s['brk'] if k - 1 not in s['brk']) + [n]
        first = True
        for a, b in zip(cuts, cuts[1:]):
            if b - a < 3:
                continue
            vs = []
            for i in range(a, b):
                pi = s['idx'][i]
                nx, ny, nz = m['nrm'][pi] if pi < len(m['nrm']) else (0, 0, 1)
                col = s['col'][i] if i < len(s['col']) else 0xFFFF
                rgba = c5(col) if col <= 0xFFFF else tuple(int(((col >> (8 * k)) & 255) * (COLOR_SCALE if k < 3 and not s.get('noscale') else 1)) for k in range(4))
                uv = s['uv'][i] if i < len(s['uv']) else (0, 0)
                if m.get('bake'):
                    # Head-On looks the body texture up by the view-space normal (a reflection map: city lights,
                    # dark sky at the top). Bake that lookup for a chase camera, kept in the bright lower band.
                    u = 0.5 + 0.45 * (0.85 * nx + 0.15 * ny)
                    v = 0.66 - 0.30 * nz + 0.05 * ny
                    uv = (int(-u * 4096), int(-v * 4096))
                vs.append((pi, (nx, ny, nz), rgba, uv))
            tag = list(s['tag'])
            if not first:
                tag[3] = 0
            first = False
            segs = [vs]
            if m.get('twosided'):
                # Head-On draws this object without backface culling: add the back faces (reversed strip;
                # an even-length strip gets a leading duplicate so the winding really flips)
                rv = vs[::-1]
                segs.append(rv if len(rv) % 2 else [rv[0]] + rv)
            for seg in segs:
                # split long strips; pieces start on even offsets so the winding is kept
                i = 0
                while i < len(seg) - 2:
                    piece = seg[i:i + STRIP_MAX]
                    out.append((tuple(tag), piece))
                    tag[3] = 0
                    i += STRIP_MAX - 2
    return out


def batches_of(m, scale):
    pos = [(x * scale, y * scale, z * scale) for x, y, z in m['pos']]
    bs, cur, local = [], None, {}
    for tag, vs in strips_of(m, scale):
        need = {v[0] for v in vs if v[0] not in local}
        if cur is None or len(cur['pool']) + len(need) > POOL_MAX:
            cur = {'pool': [], 'strips': []}
            bs.append(cur)
            local = {}
        for v in vs:
            if v[0] not in local:
                local[v[0]] = len(cur['pool'])
                cur['pool'].append(pos[v[0]])
        sv = []
        for pi, (nx, ny, nz), rgba, uv in vs:
            q = lambda f: max(-127, min(127, int(round(f * 127))))
            sv.append(((q(nx), q(ny), q(nz), local[pi]), rgba, uv))
        cur['strips'].append({'tag': (0x8000 | len(sv), tag[1], tag[2], tag[3]), 'v': sv})
    return bs, pos


def hierobject(m, scale, gsctx):
    """gsctx: list of (tex id, 0x30-byte gs context). Returns (bytes, rel_slots, rel_pairs)"""
    bs, pos = batches_of(m, scale)
    pk = vif_packet(bs, env=bool(m.get('env')))
    used = [p for b in bs for p in b['pool']]
    xs, ys, zs = zip(*used)
    cx, cy, cz = (max(xs) + min(xs)) / 2, (max(ys) + min(ys)) / 2, (max(zs) + min(zs)) / 2
    r = max(math.sqrt((x - cx) ** 2 + (y - cy) ** 2 + (z - cz) ** 2) for x, y, z in used)
    nsv = sum(len(s['v']) for b in bs for s in b['strips'])
    alpha = any(s['tag'][1] & 0x200000 for b in bs for s in b['strips'])   # ABE bit (prim bit 6)
    if 'alpha' in m: alpha = m['alpha']      # levels: only meshes with really translucent textures
    flags = (min(nsv, 0xFFFF) << 16) | (0 if m.get('level') else 0x0100) | (0x8000 if alpha else 0)
    if m.get('env'):
        flags |= 0x06     # retail TMB reflective meshes: 0x106 (envMapSize 3), one texture = the reflection map
    elif ENV_MAP:   # envMapSize (bits 1-3): same bitfield in Head-On's object flags; TMB's VU1 code has an env-map path
        flags |= m.get('hflags', 0) & 0x0E
    nt = len(gsctx)
    hsize = 0x70 + 0x30 * nt
    h = bytearray(hsize)
    struct.pack_into('<IIfI3ff', h, 0, 0, hsize, r * r, flags, cx, cy, cz, r)
    h[0x20:0x50] = TEMPLATE_20
    for i, (tid, ctx) in enumerate(gsctx):
        struct.pack_into('<H', h, 0x50 + 2 * i, tid)
        h[0x70 + 0x30 * i:0xa0 + 0x30 * i] = ctx
    struct.pack_into('<H', h, 0x5a, nt)
    pairs = [(0x50 + 2 * i, 0x70 + 0x30 * i) for i in range(nt)]
    return bytes(h) + pk, [4], pairs, (cx, cy, cz, r)
