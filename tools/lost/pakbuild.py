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
SKIP_MESH = {0x1db0,                  # light cone
             0x41480, 0x41670, 0x41820, 0x41f60, 0x42150, 0x42300, 0x42530,   # cab poles + caps poking through the roof
             0x2bd70}                  # a side door left hanging open outside the body
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
    # Roadkill's own parts (driver + roof guns, door / hood / side panels, gas cap, rear rack: characters 0..9 of
    # the op7 list, and the meshes laid out before them) get an empty packet; wheels stay
    if os.environ.get('PAK_KEEP_RK') != '1':
        from tmbtree_walk import kid_slots
        op7 = next(u32(car.n, 4 + 4 * i) - 0x980000 for i in range(u32(car.n, 0)) if (u32(car.n, u32(car.n, 4 + 4 * i) - 0x980000) & 0x3f) == 7)
        chars = [u32(car.n, op7 + 8 + 4 * i) - 0x980000 for i in range(u32(car.n, op7 + 4))]
        limit = chars[9]
        wheels = set()
        for o in range(0, limit, 16):
            h = u32(car.n, o)
            if (h & 0x3f) == 4 and 33 <= (h >> 18) <= 36:
                for sl in kid_slots(car.n, o)[:4]:
                    if sl + 4 > len(car.n): continue
                    t = car.P(sl)
                    if t is not None: wheels.add(t)
        # brake / tail lights: Roadkill's switch id 42 (attach type 10 -> vehicle+0x2050: 0 off, 1 braking, 2 ...)
        # stays, its four lamp quads moved onto 12 Pak's four round rear lamps
        from tmbtree_walk import subtree_slots
        brake = set()
        for o in range(0, limit, 16):
            h = u32(car.n, o)
            if (h & 0x3f) == 6 and (h >> 18) == 42 and car.n[o + 0xb] == 3:
                for i in range(3):
                    c = car.P(o + 0xc + 4 * i)
                    if c is None: continue
                    if (u32(car.n, c) & 0x3f) == 0: brake.add(c)
                    brake |= {t for sl, t in subtree_slots(car, c) if (u32(car.n, t) & 0x3f) == 0}
        RK_C = [-2.6, -1.68, 1.77, 2.65]; PK_C = [-1.86, -1.31, 1.40, 1.97]
        from tmbmesh import parse, BASE
        for nd in brake:
            pk = u32(car.n, nd + 4) - BASE; qwc = u32(car.n, pk) & 0xffff
            for r in parse(car.n, pk + 8, pk + 16 + qwc * 16):
                if r[1] == 0x68:
                    for k in range(r[2]):
                        x, y, z = struct.unpack_from('<3f', car.n, r[4] + 12 * k)
                        j = min(range(4), key=lambda q: abs(x - RK_C[q]))
                        struct.pack_into('<3f', car.n, r[4] + 12 * k, PK_C[j] + (x - RK_C[j]) * 0.5,
                                         -8.05 + (y + 8.3) * 0.5, -0.24 + (z - 0.13) * 0.5)
        print('brake light meshes kept and moved:', len(brake))
        wheels |= brake
        deadset = {a for a, b in dead}
        nopk = car.append(struct.pack('<4I', 0x60000001, 0, 0, 0) + struct.pack('<4I', 0x01000404, 0, 0, 0))
        nb = 0
        for a, g in list(car.pairs):
            for i in range(5):
                nd = a - 0x50 - 2 * i
                if nd % 16 or nd >= limit or nd in deadset or nd in wheels or (u32(car.n, nd) & 0x3f) != 0:
                    continue
                if g != nd + 0x70 + 0x30 * i or u32(car.n, nd + 4) - 0x980000 >= len(car.n):
                    continue
                nt = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
                if u32(car.n, nd + 4) - 0x980000 != nd + 0x70 + 0x30 * nt:
                    continue
                a2, b2 = mesh_extent(car.n, nd)
                dead.append((nd + 0x70 + 0x30 * nt, b2)); deadset.add(nd)
                car.setp(nd + 4, nopk)
                struct.pack_into('<I', car.n, nd + 0xc, u32(car.n, nd + 0xc) & 0xFFFF)
                nb += 1
        print('Roadkill parts hidden:', nb, 'meshes (wheels kept:', len(wheels), ')')
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
