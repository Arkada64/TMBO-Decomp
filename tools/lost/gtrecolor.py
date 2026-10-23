"""Gold Tooth as a recolour of TMB's own Sweet Tooth (keeps every Sweet Tooth part: weapon arms, compartments,
animated head, special): the body sheets' palettes are mapped onto a gold ramp by brightness.
  python3 gtrecolor.py STPDIR HC_CHROM.BDD OUTDIR
GT_HEAD=1 also swaps Sweet Tooth's clown head for Gold Tooth's (static, from Head-On)."""
import sys, os, struct
import numpy as np
from tmbcar import Car, mesh_extent, u32
from textconv import records, rtx_rec_size
from hotex import clut_unswizzle

GOLD_CLUTS = [49, 45, 9, 37]          # sheets 1, 2 (body art), 3, 6 (mechanical)
DARK, MID, LIGHT = np.array([45, 30, 6]), np.array([190, 140, 45]), np.array([255, 236, 170])


def gold(rgb):
    L = (rgb @ np.array([0.30, 0.55, 0.15])) / 255.0
    L = np.clip((L - 0.08) / 0.8, 0, 1) ** 0.85
    lo = DARK + (MID - DARK) * np.clip(L / 0.6, 0, 1)[:, None]
    hi = MID + (LIGHT - MID) * np.clip((L - 0.6) / 0.4, 0, 1)[:, None]
    return np.where((L < 0.6)[:, None], lo, hi).clip(0, 255).astype(np.uint8)


def recolor(rtx):
    r = bytearray(rtx)
    for o, b, gs, k in records(rtx, rtx_rec_size):
        a = (gs >> 16) & 0xffff
        if a not in GOLD_CLUTS:
            continue
        ne = (1 << ((gs >> 40) & 15)) * (1 << ((gs >> 44) & 15))
        p = np.frombuffer(bytes(r[o + 16:o + 16 + 4 * ne]), np.uint8).reshape(ne, 4).copy()
        p[:, :3] = gold(p[:, :3].astype(float))     # per entry: CLUT order doesn't matter
        r[o + 16:o + 16 + 4 * ne] = p.tobytes()
    return bytes(r)


def main(stpdir, bddpath, outdir):
    rd = lambda e: open(os.path.join(stpdir, 'STP.' + e), 'rb').read()
    ngp, ptr, tex, rtx = rd('NGP'), rd('PTR'), rd('TEX'), recolor(rd('RTX'))
    if os.environ.get('GT_HEAD'):
        import gtbuild
        car = Car(ngp, ptr, tex, rtx)
        from bdd import bdd
        from homesh import find_packets, decode
        from textconv import TexBuilder
        from meshconv import hierobject
        s = bdd(bddpath); n = s['ngp']
        tb = TexBuilder(car.tex, car.rtx, s['tex'], car.max_tex_id() + 1, gtbuild.REUSE, [], [0x73ff0])
        hd = {}
        for o in find_packets(n):
            m = decode(n, o)
            if m['hdr'] is not None:
                hd[m['hdr']] = m
        kids = []
        for h in (0x1230, 0x3bd0):
            m = dict(hd[h], hflags=hd[h]['hflags'] & ~0x0E, bake=hd[h]['texrefs'] == [0x73ff0], twosided=True)
            blob, sl, pr, sph = hierobject(m, 1.15, [tb.gs_ctx(k) for k in m['texrefs']])
            kids.append(car.append(blob, sl, pr))
        for g in gtbuild.STP_STATES:                         # head rides on the body groups
            k = u32(car.n, g + 8) & 0xffff
            old = [car.P(g + 0x20 + 4 * i) for i in range(k)]
            newg = car.group(old + kids, sphere=struct.unpack_from('<3ff', car.n, g + 0x10))
            for i in range(k):
                struct.pack_into('<I', car.n, g + 0x20 + 4 * i, 0)
            struct.pack_into('<H', car.n, g + 8, 1)
            car.setp(g + 0x20, newg)
        nopk = car.append(struct.pack('<4I', 0x60000001, 0, 0, 0) + struct.pack('<4I', 0x01000404, 0, 0, 0))
        for nd in (0x4bc10,):                               # Sweet Tooth's clown head (character 0x50960)
            car.setp(nd + 4, nopk)
            struct.pack_into('<I', car.n, nd + 0xc, u32(car.n, nd + 0xc) & 0xFFFF)
        ngp, ptr, tex, rtx = car.ngp_bytes(), car.ptr_bytes(), tb.tex_bytes(), recolor(tb.rtx_bytes())
    os.makedirs(outdir, exist_ok=True)
    for e, b in (('NGP', ngp), ('PTR', ptr), ('TEX', tex), ('RTX', rtx)):
        open(os.path.join(outdir, 'STP.' + e), 'wb').write(b)
    print('ngp', len(ngp), 'tex', len(tex), 'rtx', len(rtx))


if __name__ == '__main__':
    main(*sys.argv[1:4])
