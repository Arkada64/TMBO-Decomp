"""12 Pak (Twisted Metal: Lost, Head-On ETE HC_STOCK.BDD) onto TMB's Roadkill (RKP/RKA): the body damage states and
the far LOD body are replaced; Roadkill's wheels, weapon mounts, characters, destroyed debris and shadow stay.
The two cars share their wheel layout (12 Pak's wheels sit at +-3.6, 5.6 / -4.6, Roadkill's at +-3.2, 5.5 / -4.6).
  python3 pakbuild.py RKDIR HC_STOCK.BDD OUTDIR      (RKDIR holds the car as STP.NGP/PTR/TEX/RTX, P or A files)
PAK_HALF=1 stores every new texture at half size (ACAR budget)."""
import sys, os, struct
from bdd import bdd
from homesh import find_packets, decode
from hocollect import collect
from tmbcar import Car, mesh_extent, u32
from textconv import TexBuilder
from meshconv import hierobject

ROOT_HI, ROOT_LO = 0x469d0, 0x3a0
SKIP_TEX = {0xb1a44, 0xcaf58,          # 12 Pak's wheels (Roadkill's are kept)
            0x88de8,                   # its shadow
            0xc1fa8, 0x11d370, 0x8fed0}  # headlight / exhaust effects
SKIP_MESH = {0x1db0}                   # light cone
STATES = [0x12db0, 0x208c0, 0x2ca80]   # Roadkill RKP: op31 0x32270 body damage-state groups
LOD1 = 0x5e830                         # far LOD group: body 0x5cf20 + shadow 0x5e310
LOD1_BODY = 0x5cf20
if os.environ.get('PAK_ACAR'):         # RKA (other players' copy): same tree, other offsets
    STATES, LOD1, LOD1_BODY = [0xc300, 0x169f0, 0x1f460], 0x4c7b0, 0x4aea0


def strip_filter(m):
    """drop the strips drawn with a skipped texture; keep the used textures only (texsel tags remapped)"""
    keep_refs = [t for t in m['texrefs'] if t not in SKIP_TEX]
    if len(keep_refs) == len(m['texrefs']):
        return m
    remap = {i: keep_refs.index(t) for i, t in enumerate(m['texrefs']) if t in keep_refs}
    cur, out = 0, []
    for s in m['strips']:
        if s['tag'][3]:
            cur = (s['tag'][3] - 1) // 3
        if cur not in remap:
            continue
        t = list(s['tag'])
        if t[3]:
            t[3] = 1 + 3 * remap[cur]
        out.append(dict(s, tag=tuple(t)))
    if out and not out[0]['tag'][3]:
        t = list(out[0]['tag']); t[3] = 1 + 3 * remap.get(cur, 0); out[0] = dict(out[0], tag=tuple(t))
    return dict(m, texrefs=keep_refs, strips=out)


def main(rkdir, bddpath, outdir, scale=1.0):
    rd = lambda e: open(os.path.join(rkdir, 'STP.' + e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), rd('TEX'), rd('RTX'))
    s = bdd(bddpath); n = s['ngp']
    half = [0x1003a0, 0x1004a4, 0x890e4] if os.environ.get('PAK_HALF') else []
    tb = TexBuilder(car.tex, car.rtx, s['tex'], car.max_tex_id() + 1, {}, half, [0x1004a4])   # 16 colours: CLUT room
    hd = {}
    for o in find_packets(n):
        m = decode(n, o)
        if m['hdr'] is not None:
            hd[m['hdr']] = m
    built = {}

    def node(h):
        if h not in built:
            m = strip_filter(hd[h])
            m = dict(m, twosided=os.environ.get('PAK_TWOSIDED', '0') == '1' and not (m.get('hflags', 0) & 0x800000), bake=False, hflags=m.get('hflags', 0) & ~0x0E)
            blob, slots, pairs, sph = hierobject(m, scale, [tb.gs_ctx(k) for k in m['texrefs']])
            built[h] = car.append(blob, slots, pairs)
        return built[h]

    def meshes(root, state):
        out = []
        for h in collect(n, root, state, lod=0):
            m = hd.get(h)
            if m is None or h in SKIP_MESH or not m['strips'] or not (set(m['texrefs']) - SKIP_TEX):
                continue
            out.append(h)
        return out

    dead = []
    for st, g in enumerate(STATES):
        k = u32(car.n, g + 8) & 0xffff
        from tmbtree_walk import subtree_slots
        for slot, tgt in subtree_slots(car, g):
            if (u32(car.n, tgt) & 0x3f) == 0:
                dead.append(mesh_extent(car.n, tgt))
        hs = meshes(ROOT_HI, st)
        newg = car.group([node(h) for h in hs], sphere=struct.unpack_from('<3ff', car.n, g + 0x10))
        struct.pack_into('<H', car.n, g + 8, 1)
        car.setp(g + 0x20, newg)
        for i in range(1, k):
            struct.pack_into('<I', car.n, g + 0x20 + 4 * i, 0)
        print('state', st, len(hs), 'meshes')
    # far LOD: its body mesh -> 12 Pak's low LOD
    for i in range(u32(car.n, LOD1 + 8) & 0xffff):
        if car.P(LOD1 + 0x20 + 4 * i) == LOD1_BODY:
            dead.append(mesh_extent(car.n, LOD1_BODY))
            car.setp(LOD1 + 0x20 + 4 * i, node(ROOT_LO))
    before = len(car.n)
    dropped = car.compact(sorted(set(dead)))
    print('ngp %d -> %d (orig %d), dropped %d, new textures %d, CLUT blocks %d' % (
        before, len(car.n), len(rd('NGP')), dropped, len(tb.new_tex), tb.next_cbp))
    os.makedirs(outdir, exist_ok=True)
    for e, b in (('NGP', car.ngp_bytes()), ('PTR', car.ptr_bytes()), ('TEX', tb.tex_bytes()), ('RTX', tb.rtx_bytes())):
        open(os.path.join(outdir, 'STP.' + e), 'wb').write(b)
        print(e, len(b))


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], float(sys.argv[4]) if len(sys.argv) > 4 else 1.0)
