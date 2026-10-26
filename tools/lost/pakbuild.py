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

    # 12 Pak's rear hatches / trunk lid ride on Roadkill's animated panels (PAK_HATCH=0 turns it off): Roadkill's
    # left / right rear panels and trunk lid are bones of his animation characters (the launcher comes out under
    # them); their damage-state op31 gets 12 Pak's hatch of that state instead, and the hatch leaves the body.
    # Ark 2026-10-26: back left = homing / fire, back right = power, trunk = gas cans (napalm).
    HATCH = [('L', 0x2bcd0), ('R', 0x34fc0), ('T', 0x58b50)] if os.environ.get('PAK_HATCH', '2') == '1' else []
    excl = set()
    for _, r in HATCH:
        for st in range(3):
            excl |= set(collect(n, r, st, lod=0))
    # PAK_HATCH=2 (default, Ark 2026-10-26: Roadkill's panels opened for the wrong weapons): each hatch is a 3-frame
    # switch of our own (closed / half / open, the panel turned about its hinge) with attach id 39 (car 32 + type 7:
    # vehicle +0x2A20 + sub * 4) and a sub no weapon uses; mods/skins.c opens it for its weapons:
    # sub 9 left rear panel (fire), sub 11 right rear panel (homing, power), sub 12 trunk lid (gas can, rico).
    # The panels' damage variants (op19 0x2af30 / 0x342f0 / 0x35cc0) leave the body; the switch shows the clean one.
    import math
    HSW = [] if os.environ.get('PAK_HATCH', '2') != '2' else [
        (9, 0x2af30, (-2.91, 0.0, 0.40), (0, 1, 0), 70.0),
        (11, 0x342f0, (2.94, 0.0, 0.40), (0, 1, 0), -70.0),
        (12, 0x35cc0, (0.0, -5.33, 0.77), (1, 0, 0), -60.0)]
    for _, op19, _, _, _ in HSW:
        for st in range(4):
            excl |= set(collect(n, op19, st, lod=0))

    def meshes(root, state, skip=excl):
        out = []
        for h in collect(n, root, state, lod=0):
            m = hd.get(h)
            if m is None or h in SKIP_MESH or h in skip or not m['strips'] or not (set(m['texrefs']) - SKIP_TEX):
                continue
            out.append(h)
        return out

    def turned(h, piv, ax, deg):
        """mesh h turned deg degrees about the axis through piv (12 Pak's car space, x right y forward z up)"""
        m = hd[h]; a = math.radians(deg); c, sn = math.cos(a), math.sin(a)
        ux, uy, uz = ax
        def rot(v, around):
            x, y, z = (v[0] - around[0], v[1] - around[1], v[2] - around[2])
            d = ux * x + uy * y + uz * z
            cx, cy, cz = uy * z - uz * y, uz * x - ux * z, ux * y - uy * x
            return (x * c + cx * sn + ux * d * (1 - c) + around[0], y * c + cy * sn + uy * d * (1 - c) + around[1],
                    z * c + cz * sn + uz * d * (1 - c) + around[2])
        key = (h, deg)
        if key not in built:
            m2 = dict(m, pos=[rot(p, piv) for p in m['pos']], nrm=[rot(q, (0, 0, 0)) for q in m.get('nrm', [])])
            m2 = strip_filter(m2)
            m2 = dict(m2, twosided=False, bake=False, hflags=m2.get('hflags', 0) & ~0x0E)
            blob, slots, pairs, sph = hierobject(m2, scale, [tb.gs_ctx(k) for k in m2['texrefs']])
            built[key] = car.append(blob, slots, pairs)
        return built[key]
    switches = []
    for sub, op19, piv, ax, deg in HSW:
        hs = [h for h in collect(n, op19, 0, lod=0) if h in hd and hd[h]['strips']]
        kids = [car.group([turned(h, piv, ax, deg * f) for h in hs]) for f in (0.0, 0.5, 1.0)]
        sw = car.append(struct.pack('<IIBBBB', 6 | (sub << 7) | (39 << 18), 0, 0, 0, 0, 3) + b'\0' * 12 + b'\0' * 8)
        for i, k in enumerate(kids):
            car.setp(sw + 0xc + 4 * i, k)
        switches.append(sw)
        print('hatch switch sub', sub, 'meshes', len(hs))
    dead = []
    for st, g in enumerate(STATES):
        k = u32(car.n, g + 8) & 0xffff
        from tmbtree_walk import subtree_slots
        for slot, tgt in subtree_slots(car, g):
            if (u32(car.n, tgt) & 0x3f) == 0:
                dead.append(mesh_extent(car.n, tgt))
        hs = meshes(ROOT_HI, st)
        newg = car.group([node(h) for h in hs] + switches, sphere=struct.unpack_from('<3ff', car.n, g + 0x10))
        struct.pack_into('<H', car.n, g + 8, 1)
        car.setp(g + 0x20, newg)
        for i in range(1, k):
            struct.pack_into('<I', car.n, g + 0x20 + 4 * i, 0)
        print('state', st, len(hs), 'meshes')
    if HATCH:
        from tmbtree_walk import kid_slots
        f32 = lambda o: struct.unpack_from('<f', car.n, o)[0]
        op7 = next(u32(car.n, 4 + 4 * i) - 0x980000 for i in range(u32(car.n, 0)) if (u32(car.n, u32(car.n, 4 + 4 * i) - 0x980000) & 0x3f) == 7)
        done = set()
        for i in range(u32(car.n, op7 + 4)):
            c = u32(car.n, op7 + 8 + 4 * i) - 0x980000
            b = car.P(c + 0x2c)
            if b is None or (u32(car.n, b) & 0x3f) != 17:
                continue
            for sl in kid_slots(car.n, b):
                d = car.P(sl)
                if d is None or (u32(car.n, d) & 0x3f) != 31:
                    continue
                ms = []
                for k in kid_slots(car.n, d):
                    t = car.P(k)
                    while t is not None and (u32(car.n, t) & 0x3f) == 3:      # translate wrapper (trunk states)
                        t = car.P(t + 0x1c)
                    if t is not None and (u32(car.n, t) & 0x3f) == 0:
                        ms.append((k, t))
                if len(ms) < 2:
                    continue
                x, y = f32(ms[0][1] + 0x10), f32(ms[0][1] + 0x14)
                side = 'L' if x < -1.5 and -7 < y < -5 else 'R' if x > 1.5 and -7 < y < -5 else 'T' if abs(x) < 0.5 and -7.6 < y < -6.6 else None
                if side is None or side in done:
                    continue
                done.add(side)
                root = dict(HATCH)[side]
                for st, (k, t) in enumerate(ms):
                    hs = meshes(root, min(st, 2), skip=set())
                    dead.append(mesh_extent(car.n, t))
                    car.setp(k, car.group([node(h) for h in hs], sphere=(f32(t + 0x10), f32(t + 0x14), f32(t + 0x18), f32(t + 0x1c) + 1.0)))
                print('hatch', side, 'char', hex(c), 'states', len(ms), 'meshes', len(meshes(root, 0, skip=set())))
                break
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
        # Roadkill's weapon hardware stays (the weapon mounts are still Roadkill's): the roof gun turret and
        # its barrels (character 0, not the driver), the rear launcher / missile parts and the rocket rack.
        # His body panels, doors, hood, trunk lid, gas cap and driver stay hidden.
        KEEP = [(0x13a0, 0x2760), (0x39b80, 0x3d630), (0x41070, 0x4c180)]
        if os.environ.get('PAK_ACAR'):
            KEEP = [(0x10, 0x800), (0x29090, 0x2cb80), (0x305c0, 0x3b6d0)]   # RKA: same parts, its offsets
        if os.environ.get('PAK_ARMS') == '1':    # Roadkill's weapon hardware: dropped (looked wrong), kept for reference
            kept = {o for a, b in KEEP for o in range(a, b, 16) if (u32(car.n, o) & 0x3f) == 0}
            wheels |= kept
            print('Roadkill weapon parts kept:', len(kept))
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
    if os.environ.get('PAK_MOUNTS', '1') == '1':
        # Roadkill's roof reticle (antenna character, its meshes up to z 4) sits above 12 Pak's lower roof, and his
        # power missiles come out of his front rocket rack (character with a mesh at y 7.2, hidden here): both
        # characters go under a translate node (Ark 2026-10-26: reticle floats above the roof, power by the gun;
        # power belongs at the back right).
        from tmbtree_walk import kid_slots
        f32 = lambda o: struct.unpack_from('<f', car.n, o)[0]
        op7 = next(u32(car.n, 4 + 4 * i) - 0x980000 for i in range(u32(car.n, 0)) if (u32(car.n, u32(car.n, 4 + 4 * i) - 0x980000) & 0x3f) == 7)
        chars = [u32(car.n, op7 + 8 + 4 * i) - 0x980000 for i in range(u32(car.n, op7 + 4))]
        def first_mesh(c):
            b = car.P(c + 0x2c); st = [b]; seen = set()
            while st:
                o = st.pop()
                if o is None or o in seen: continue
                seen.add(o)
                if (u32(car.n, o) & 0x3f) == 0: return (f32(o + 0x10), f32(o + 0x14), f32(o + 0x18))
                st += [car.P(sl) for sl in kid_slots(car.n, o)]
            return None
        MOVE = {'antenna': (1.15, 0.0, -1.8), 'rack': (2.0, -18.6, -0.9)}
        for c in chars[:10]:
            fm = first_mesh(c)
            if fm is None: continue
            kind = 'antenna' if fm[2] > 3.5 else 'rack' if fm[1] > 6.5 and abs(fm[0]) < 0.5 and fm[2] < 0.5 else None
            if not kind: continue
            refs = [o for o in range(0, op7, 4) if u32(car.n, o) == c + 0x980000]
            for r in refs:
                dx, dy, dz = MOVE[kind]
                t = car.append(struct.pack('<IIIIfffI', 3, 0, 1, 0, dx, dy, dz, 0))
                car.setp(t + 0x1c, c)
                car.setp(r, t)
            print('moved', kind, hex(c), 'refs', len(refs))
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
