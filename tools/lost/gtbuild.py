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
REUSE = {0xb0448: 45, 0xa91b8: 49, 0x8dc74: 45}
if os.environ.get('GT_GOLD_PAL'):                # put the gold body texture on Sweet Tooth's body palette too
    REUSE[0x73ff0] = int(os.environ['GT_GOLD_PAL'])
HALF = [int(x, 16) for x in os.environ.get('GT_HALF', '').split(',') if x]   # e.g. b0448,a91b8
GT_HI, GT_LO = 0x28ef0, 0x5980
STP_STATES = [0xa940, 0x152b0, 0x1ede0]          # op31 id209 damage-state groups (3 meshes each)
STP_LOD1 = 0x55650                               # far LOD body group
STP_LOD1_KEEP = [0x54b60, 0x55620]               # its non-body kids (light, shadow)


def main(stpdir, bddpath, outdir, scale=1.15, gt_states=(0, 0, 0)):
    rd = lambda e: open(os.path.join(stpdir, 'STP.' + e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), rd('TEX'), rd('RTX'))
    s = bdd(bddpath)
    n = s['ngp']
    tb = TexBuilder(car.tex, car.rtx, s['tex'], car.max_tex_id() + 1, REUSE, HALF)
    hdr2pk = {}
    for o in find_packets(n):
        m = decode(n, o)
        if m['hdr'] is not None:
            hdr2pk[m['hdr']] = (o, m)
    built = {}

    def node_for(h):
        if h in built:
            return built[h]
        o, m = hdr2pk[h]
        ctx = [tb.gs_ctx(k) for k in m['texrefs']]
        blob, slots, pairs, sph = hierobject(m, scale, ctx)
        built[h] = (car.append(blob, slots, pairs), sph)
        return built[h]

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
        hs = meshes(GT_HI, gt_states[st])
        kids = [node_for(h)[0] for h in hs]
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
    before = len(car.n)
    dropped = car.compact(sorted(set(dead)))
    print('ngp %d -> %d bytes (orig %d), %d dangling pointers cleared, %d slots, %d tex pairs, %d new textures' % (
        before, len(car.n), len(rd('NGP')), dropped, len(car.slots), len(car.pairs), len(tb.new_tex)))
    print('CLUT blocks', tb.next_cbp, 'new CLUTs', len(tb.new_rtx))
    os.makedirs(outdir, exist_ok=True)
    w = lambda e, b: open(os.path.join(outdir, 'STP.' + e), 'wb').write(b)
    w('NGP', car.ngp_bytes())
    w('PTR', car.ptr_bytes())
    w('TEX', tb.tex_bytes())
    w('RTX', tb.rtx_bytes())


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], float(sys.argv[4]) if len(sys.argv) > 4 else 1.15,
         tuple(int(x) for x in os.environ.get('GT_STATES', '0,0,0').split(',')))
