"""Build a TMB Sweet Tooth (STP) skin from Twisted Metal: Lost's Gold Tooth (Head-On ETE HC_CHROM.BDD).
  python3 gtbuild.py STPDIR HC_CHROM.BDD OUTDIR [scale]
GT_STATES=a,b,c picks the Gold Tooth damage state used for each Sweet Tooth body state (default 0,0,0:
size stays under the original STP.NGP; 0,1,2 is ~25 KB bigger).
Replaces the body meshes of the three body damage states and the far LOD body; everything else (wheels,
weapon mounts, special, shadow, collision) stays Sweet Tooth's."""
import sys, os, struct
from bdd import bdd
from homesh import find_packets, decode
from hocollect import collect
from tmbcar import Car, mesh_extent, u32
from textconv import TexBuilder
from meshconv import hierobject

SKIP_TEX = {0x8a480, 0xc1fa8, 0x84320,          # headlight flares, turbo / exhaust flames (Head-On effects)
            0x87f40, 0x8bba8, 0xa2888}          # far-LOD wheels / underside (Sweet Tooth's wheels are kept)
# same truck art as Sweet Tooth's own sheets: reuse those palettes (car CLUT space is tight: STP uses 76 blocks)
REUSE = {0xb0448: 45, 0xa91b8: 49, 0x8dc74: 45, 0x9e768: 5}
GT_EXTRA = [0x1230, 0x3bd0, 0x3e0]              # Gold Tooth's head, eyes, arm with the cone (under the op17 root)
if os.environ.get('GT_GOLD_PAL'):                # put the gold body texture on Sweet Tooth's body palette too
    REUSE[0x73ff0] = int(os.environ['GT_GOLD_PAL'])
HALF = [int(x, 16) for x in os.environ.get('GT_HALF', '').split(',') if x]   # e.g. b0448,a91b8
GT_HI, GT_LO = 0x28ef0, 0x5980
STP_STATES = [0xa940, 0x152b0, 0x1ede0]          # op31 id209 damage-state groups (3 meshes each)
STP_LOD1 = 0x55650                               # far LOD body group
STP_LOD1_KEEP = [0x54b60, 0x55620]               # its non-body kids (light, shadow)
STP_HIDE = [0x296f0, 0x2a640]
# Most of Sweet Tooth's body is character parts (op25: rear box + doors, clown head, cab pieces, the special's
# robot), drawn over Gold Tooth: every remaining mesh textured only from these sheets gets an empty packet.
BLANK_TEX = {1, 2, 3, 6, 7, 8}
# Sweet Tooth's animated parts (op25 character instances; a character's meshes precede its instance node).
# The fender and side-compartment characters carry the mechanical arms the weapons sit on: keep their
# metal (sheet 2) pieces, blank only their body panels. The rest (clown head, driver, rear box, debris,
# special / far-LOD bodies) is blanked whole.
CHARS = [0x25640, 0x2f500, 0x344c0, 0x36400, 0x38890, 0x3c370, 0x3e880, 0x3ffa0, 0x4ba20, 0x50960, 0x52eb0,
         0x91c20, 0x96e90, 0xa01a0, 0xa2a90]
ARM_CHARS = {0x2f500, 0x344c0, 0x36400, 0x38890, 0x3c370, 0x3e880}
STP_ALT_LOD = 0x941a0                            # switch 217 child 1 (the special's form): show Gold Tooth there too                    # Sweet Tooth's rear doors / bumper pieces (Gold Tooth has its own)


def hide_meshes(car, root, empty, dead):
    """repoint every op0 under root (through any relocated slot inside the subtree's nodes) to an empty group"""
    from tmbtree_walk import subtree_slots
    for slot, tgt in subtree_slots(car, root):
        if (u32(car.n, tgt) & 0x3f) == 0:
            dead.append(mesh_extent(car.n, tgt))
            car.setp(slot, empty)


def mount_meshes(car):
    """op0 nodes reachable from the weapon mount nodes (ids 4001-4006, 4100): node = a pointer target, its child
    pointers = the relocated slots between it and the next target"""
    import bisect
    starts = sorted({car.P(sl) for sl in car.slots if car.P(sl) is not None} |
                    {u32(car.n, 4 + 4 * i) - 0x980000 for i in range(u32(car.n, 0))})
    slots = sorted(car.slots)
    def kids(o):
        i = bisect.bisect_right(starts, o)
        end = starts[i] if i < len(starts) else len(car.n)
        a = bisect.bisect_left(slots, o)
        out = []
        while a < len(slots) and slots[a] < end:
            t = car.P(slots[a])
            if t is not None:
                out.append(t)
            a += 1
        return out
    roots = [o for o in starts if o < len(car.n) and (u32(car.n, o) >> 18) in (4001, 4002, 4003, 4004, 4005, 4006, 4100)]
    seen, st, mesh = set(), list(roots), set()
    while st:
        o = st.pop()
        if o in seen:
            continue
        seen.add(o)
        if (u32(car.n, o) & 0x3f) == 0:
            mesh.add(o)
            continue
        st += kids(o)
    return mesh


def main(stpdir, bddpath, outdir, scale=1.15, gt_states=(0, 0, 0)):
    rd = lambda e: open(os.path.join(stpdir, 'STP.' + e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), rd('TEX'), rd('RTX'))
    s = bdd(bddpath)
    n = s['ngp']
    tb = TexBuilder(car.tex, car.rtx, s['tex'], car.max_tex_id() + 1, REUSE, HALF,
                    [] if os.environ.get('GT_GOLD_PAL') else [0x73ff0])
    hdr2pk = {}
    for o in find_packets(n):
        m = decode(n, o)
        if m['hdr'] is not None:
            hdr2pk[m['hdr']] = (o, m)
    built = {}
    for h in GT_EXTRA:                 # head / eyes / arm: no env map (their shine came out black in places)
        if h in hdr2pk:
            hdr2pk[h][1]['hflags'] &= ~0x0E

    def node_for(h):
        if h in built:
            return built[h]
        built[h] = build(hdr2pk[h][1])
        return built[h]

    def build(m):
        ctx = [tb.gs_ctx(k) for k in m['texrefs']]
        if m.get('hflags', 0) & 0x0E and os.environ.get('GT_ENV', '0') == '1' and len(ctx) == 1:
            ctx = ctx * 2      # env-mapped: TMB's env path reads a second texture slot (the reflection map)
        from meshconv import BAKE, TWOSIDED
        m = dict(m, bake=BAKE and m['texrefs'] == [0x73ff0],
                 twosided=TWOSIDED and not (m.get('hflags', 0) & 0x800000))   # bit 23 clear = no culling in Head-On
        blob, slots, pairs, sph = hierobject(m, scale, ctx)
        return car.append(blob, slots, pairs), sph

    def meshes(root, state):
        out = []
        for h in collect(n, root, state, lod=0):
            if h not in hdr2pk:
                continue
            m = hdr2pk[h][1]
            if set(m['texrefs']) & SKIP_TEX or not m['strips']:
                continue
            out.append(h)
        return out

    dead = []
    # body damage states
    for st, g in enumerate(STP_STATES):
        k = u32(car.n, g + 8) & 0xffff
        for i in range(k):
            t = car.P(g + 0x20 + 4 * i)
            if t is not None and (u32(car.n, t) & 0x3f) == 0:
                dead.append(mesh_extent(car.n, t))
        hs = meshes(GT_HI, gt_states[st]) + GT_EXTRA
        kids = [node_for(h)[0] for h in hs]
        from winpatch import patch
        pm = patch([hdr2pk[h][1] for h in hs if h not in GT_EXTRA])   # close the open rear side window
        if pm and not os.environ.get('GT_NOWINDOW'):
            kids.append(build(pm)[0])
        sph = struct.unpack_from('<3ff', car.n, g + 0x10)
        newg = car.group(kids, sphere=sph)
        struct.pack_into('<HH', car.n, g + 8, 1, u32(car.n, g + 8) >> 16)
        car.setp(g + 0x20, newg)
        for i in range(1, k):
            struct.pack_into('<I', car.n, g + 0x20 + 4 * i, 0)
        print('state', st, len(hs), 'meshes')
    # far LOD
    k = u32(car.n, STP_LOD1 + 8) & 0xffff
    for i in range(k):
        t = car.P(STP_LOD1 + 0x20 + 4 * i)
        if t is not None and (u32(car.n, t) & 0x3f) == 0:
            dead.append(mesh_extent(car.n, t))
    lo = [node_for(h)[0] for h in meshes(GT_LO, 0)]
    kids = lo + STP_LOD1_KEEP
    for i in range(k):
        struct.pack_into('<I', car.n, STP_LOD1 + 0x20 + 4 * i, 0)
    sph = struct.unpack_from('<3ff', car.n, STP_LOD1 + 0x10)
    newg = car.group(kids, sphere=sph)
    struct.pack_into('<H', car.n, STP_LOD1 + 8, 1)
    car.setp(STP_LOD1 + 0x20, newg)
    print('lod1', len(lo), 'meshes')
    empty = car.group([])
    for r in STP_HIDE:
        hide_meshes(car, r, empty, dead)
    # Sweet Tooth's side weapon mounts (missiles shown resting on the car) sit in the air beside Gold Tooth's
    # narrower cab: move them in against the cab side
    for rot, x in ((0x4ba90, -3.6), (0x4bb10, 3.6)):
        if os.environ.get('GT_MOVEMOUNTS') and (u32(car.n, rot) & 0x3f) == 4:
            struct.pack_into('<f', car.n, rot + 0x40, x)
            struct.pack_into('<f', car.n, rot + 0x48, 0.3)
    # special form: both LOD children -> Gold Tooth state 0
    g0 = car.P(STP_STATES[0] + 0x20)
    for i in range(struct.unpack_from('<i', car.n, STP_ALT_LOD + 4)[0]):
        car.setp(STP_ALT_LOD + 0x28 + 0x10 * i, g0)
    # blank the remaining Sweet Tooth body meshes
    nopk = car.append(struct.pack('<4I', 0x60000001, 0, 0, 0) + struct.pack('<4I', 0x01000404, 0, 0, 0))
    deadset = {a for a, b in dead}
    keep = mount_meshes(car)
    print('weapon mount meshes kept', len(keep))
    nb = 0
    global BL
    BL = []
    for nd in sorted({a - 0x50 - 2 * i for a, g in car.pairs for i in range(5) if (a - 0x50 - 2 * i) % 16 == 0}):
        if nd in deadset or nd in keep or nd >= len(car.n) or (u32(car.n, nd) & 0x3f) != 0:
            continue
        nt = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
        ts = {struct.unpack_from('<H', car.n, nd + 0x50 + 2 * k)[0] for k in range(nt)}
        if not ts or not ts <= BLANK_TEX or u32(car.n, nd + 4) - 0x980000 != nd + 0x70 + 0x30 * nt:
            continue
        import bisect
        ch = CHARS[bisect.bisect_left(CHARS, nd)] if nd < CHARS[-1] else None
        if ch in ARM_CHARS and (2 in ts or os.environ.get('GT_PANELS')) and not os.environ.get('GT_NOARMS'):
            continue
        cx, cy = struct.unpack_from('<2f', car.n, nd + 0x10)
        if os.environ.get('GT_KEEPGUNS') and abs(cx) >= 4.0 and cy >= 4.5:   # Sweet Tooth's fender guns (stick out of Gold Tooth)
            continue
        a, b = mesh_extent(car.n, nd)
        dead.append((nd + 0x70 + 0x30 * nt, b))
        car.setp(nd + 4, nopk)
        struct.pack_into('<I', car.n, nd + 0xc, u32(car.n, nd + 0xc) & 0xFFFF)
        nb += 1
        BL.append(nd)
    print('blanked', nb, 'Sweet Tooth meshes')
    if os.environ.get('GT_DUMPBLANK'): open(os.environ['GT_DUMPBLANK'],'w').write(' '.join('%x'%x for x in BL))
    before = len(car.n)
    dropped = car.compact(sorted(set(dead)))
    print('ngp %d -> %d bytes (orig %d), %d dangling pointers cleared, %d slots, %d tex pairs, %d new textures' % (
        before, len(car.n), len(rd('NGP')), dropped, len(car.slots), len(car.pairs), len(tb.new_tex)))
    print('CLUT blocks', tb.next_cbp, 'new CLUTs', len(tb.new_rtx), {hex(k): v[4] for k, v in tb.map.items()})
    os.makedirs(outdir, exist_ok=True)
    w = lambda e, b: open(os.path.join(outdir, 'STP.' + e), 'wb').write(b)
    w('NGP', car.ngp_bytes())
    w('PTR', car.ptr_bytes())
    w('TEX', tb.tex_bytes())
    w('RTX', tb.rtx_bytes())


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], float(sys.argv[4]) if len(sys.argv) > 4 else 1.15,
         tuple(int(x) for x in os.environ.get('GT_STATES', '0,1,2').split(',')))
