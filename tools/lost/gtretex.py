"""Gold Tooth as a RETEXTURE of TMB's own Sweet Tooth model: every texel of the body sheets is repainted with
Head-On's gold reflection map, looked up by the normal of the Sweet Tooth surface that uses it (the same
lookup Head-On does per frame, baked once for a chase camera), plus a faint copy of the original's fine
detail (panel seams). Cut-out (alpha 0) texels stay cut out. Model files are untouched.
  python3 gtretex.py STPDIR HC_CHROM.BDD OUTDIR"""
import sys, os, struct
import numpy as np
from PIL import Image
from tmbcar import Car, u32
from tmbmesh import decode
from textconv import records, rtx_rec_size, tex_rec_size
from hotex import clut_unswizzle, textures
from bdd import bdd

SHEETS = [1, 2, 6, 3]          # body art 1/2, mechanical 6/3
DETAIL = float(os.environ.get('GT_DETAIL', '0.2'))


def env_uv(nx, ny, nz):
    return 0.5 + 0.45 * (0.85 * nx + 0.15 * ny), 0.66 - 0.30 * nz + 0.05 * ny


def main(stpdir, bddpath, outdir):
    rd = lambda e: open(os.path.join(stpdir, 'STP.' + e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), rd('TEX'), rd('RTX'))
    tex, rtx = bytearray(car.tex), bytearray(car.rtx)
    env = textures(bdd(bddpath)['tex'])[0x73ff0]['img'][:, :, :3]
    from PIL import ImageFilter
    env = np.asarray(Image.fromarray(env).filter(ImageFilter.GaussianBlur(2.5)), float)
    # keep the map's light/dark pattern, but grade it onto a rich gold ramp (deep -> gold -> pale highlight)
    L = np.clip((env @ [0.3, 0.55, 0.15]) / 255.0, 0, 1)
    L = np.clip((L - 0.15) / 0.75, 0, 1)
    ramp = np.array([[70, 45, 8], [165, 115, 25], [225, 175, 55], [250, 220, 120], [255, 248, 210]], float)
    x = L * (len(ramp) - 1); i0 = np.minimum(x.astype(int), len(ramp) - 2); f = (x - i0)[..., None]
    env = ramp[i0] * (1 - f) + ramp[i0 + 1] * f
    EH, EW = env.shape[:2]
    # sheets: tid -> record + clut
    trec = {gs & 0xffff: (o, b, gs) for o, b, gs, k in records(car.tex, tex_rec_size)}
    rrec = {(gs >> 16) & 0xffff: (o, b, gs) for o, b, gs, k in records(car.rtx, rtx_rec_size)}
    cbp_of = {}
    nodes = {}
    for a, g in car.pairs:
        tid = struct.unpack_from('<H', car.n, a)[0]
        cbp_of[tid] = (struct.unpack_from('<Q', car.n, g)[0] >> 37) & 0x3fff
        nd = a - 0x50 - 2 * ((a - 0x50) % 16 // 2) if False else None
    # mesh nodes: a texture pair slot a = node+0x50+2i, node 16-aligned
    for a, g in car.pairs:
        for i in range(5):
            nd = a - 0x50 - 2 * i
            if nd % 16 == 0 and (u32(car.n, nd) & 0x3f) == 0 and g == nd + 0x70 + 0x30 * i:
                nodes[nd] = struct.unpack_from('<H', car.n, nd + 0x5a)[0]
    S = {}
    for tid in SHEETS:
        o, b, gs = trec[tid]
        psm, w, h = (gs >> 32) & 0x3f, 1 << ((gs >> 40) & 15), 1 << ((gs >> 44) & 15)
        raw = np.frombuffer(bytes(tex[o + 0x80:o + b]), np.uint8)
        if psm == 0x14:
            idx = np.empty(len(raw) * 2, np.uint8); idx[0::2] = raw & 15; idx[1::2] = raw >> 4
        else:
            idx = raw.copy()
        idx = idx[:w * h].reshape(h, w)
        co, cb, cgs = rrec[cbp_of[tid]]
        ne = (1 << ((cgs >> 40) & 15)) * (1 << ((cgs >> 44) & 15))
        pal = [tuple(x) for x in np.frombuffer(bytes(rtx[co + 16:co + 16 + 4 * ne]), np.uint8).reshape(ne, 4)]
        pal = np.array(clut_unswizzle(pal) if ne == 256 else pal, np.uint8)
        S[tid] = dict(o=o, psm=psm, w=w, h=h, idx=idx, pal=pal, co=co, ne=ne, img=pal[idx],
                      acc=np.zeros((h, w, 3)), cnt=np.zeros((h, w)))
    # bake: rasterize every triangle in texel space
    for nd, nt in nodes.items():
        tids = [struct.unpack_from('<H', car.n, nd + 0x50 + 2 * k)[0] for k in range(nt)]
        try:
            m = decode(car.n, nd)
        except Exception:
            continue
        cur = 0
        for s in m['strips']:
            if s['tag'][3]:
                cur = (s['tag'][3] - 1) // 3
            tid = tids[cur] if cur < len(tids) else None
            if tid not in S or not s['uv'] or not s['nv']:
                continue
            T = S[tid]
            for i in range(2, len(s['nv'])):
                c3 = [i - 2, i - 1, i]
                uv = np.array([(-s['uv'][k][0] / 4096 * T['w'], -s['uv'][k][1] / 4096 * T['h']) for k in c3])
                nrm = np.array([s['nv'][k][:3] for k in c3], float) / 127.0
                x0, y0 = np.floor(uv.min(0)).astype(int); x1, y1 = np.ceil(uv.max(0)).astype(int)
                if x1 - x0 > 2 * T['w'] or y1 - y0 > 2 * T['h']:
                    continue
                xs, ys = np.meshgrid(np.arange(x0, x1 + 1) + 0.5, np.arange(y0, y1 + 1) + 0.5)
                (ax, ay), (bx, by), (cx, cy) = uv
                d = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay)
                if abs(d) < 1e-9:
                    continue
                l1 = ((xs - ax) * (cy - ay) - (cx - ax) * (ys - ay)) / d
                l2 = ((bx - ax) * (ys - ay) - (xs - ax) * (by - ay)) / d
                l0 = 1 - l1 - l2
                inside = (l0 >= -0.05) & (l1 >= -0.05) & (l2 >= -0.05)
                if not inside.any():
                    continue
                n = l0[..., None] * nrm[0] + l1[..., None] * nrm[1] + l2[..., None] * nrm[2]
                n /= np.linalg.norm(n, axis=-1, keepdims=True) + 1e-9
                eu, ev = env_uv(n[..., 0], n[..., 1], n[..., 2])
                col = env[(np.clip(ev, 0, 0.999) * EH).astype(int), (np.clip(eu, 0, 0.999) * EW).astype(int)]
                tx = (np.floor(xs).astype(int)) % T['w']; ty = (np.floor(ys).astype(int)) % T['h']
                np.add.at(T['acc'], (ty[inside], tx[inside]), col[inside])
                np.add.at(T['cnt'], (ty[inside], tx[inside]), 1)
    from PIL import ImageFilter
    for tid, T in S.items():
        cov = T['cnt'] > 0
        new = np.zeros((T['h'], T['w'], 3))
        new[cov] = T['acc'][cov] / T['cnt'][cov][:, None]
        mean = new[cov].mean(0) if cov.any() else np.array([200, 160, 70.])
        new[~cov] = mean
        # faint fine detail from the original (seams, grilles): high-pass of its brightness
        L = T['img'][:, :, :3].astype(float) @ [0.3, 0.55, 0.15]
        Lb = np.asarray(Image.fromarray(L.astype(np.uint8)).filter(ImageFilter.GaussianBlur(2)), float)
        new = new * (1 + DETAIL * np.clip((L - Lb) / 64.0, -1, 0.5))[..., None]
        new = new.clip(0, 255).astype(np.uint8)
        cut = T['img'][:, :, 3] == 0
        ncol = T['ne'] - 1
        q = Image.fromarray(new).quantize(ncol, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
        qi = np.asarray(q, np.uint8).copy()
        qp = np.array(q.getpalette()[:3 * ncol], np.uint8).reshape(-1, 3)
        qp = np.vstack([qp, np.zeros((ncol - len(qp), 3), np.uint8)]) if len(qp) < ncol else qp
        pal = np.zeros((T['ne'], 4), np.uint8); pal[:ncol, :3] = qp; pal[:ncol, 3] = 255
        qi[cut] = ncol                                   # last entry: transparent
        T['newimg'] = np.concatenate([new, np.where(cut, 0, 255)[..., None].astype(np.uint8)], 2)
        flat = qi.reshape(-1)
        if T['psm'] == 0x14:
            data = (flat[0::2] | (flat[1::2] << 4)).astype(np.uint8).tobytes()
        else:
            data = flat.tobytes()
        tex[T['o'] + 0x80:T['o'] + 0x80 + len(data)] = data
        pl = [tuple(x) for x in pal]
        pl = clut_unswizzle(pl) if T['ne'] == 256 else pl
        rtx[T['co'] + 16:T['co'] + 16 + 4 * T['ne']] = np.array(pl, np.uint8).tobytes()
        print('sheet', tid, '%dx%d' % (T['w'], T['h']), 'covered %.0f%%' % (100 * cov.mean()))
    os.makedirs(outdir, exist_ok=True)
    for e, b in (('NGP', car.n), ('PTR', rd('PTR')), ('TEX', tex), ('RTX', rtx)):
        open(os.path.join(outdir, 'STP.' + e), 'wb').write(bytes(b))
    M = Image.new('RGBA', (sum(T['w'] for T in S.values()), max(T['h'] for T in S.values())))
    x = 0
    for T in S.values():
        M.paste(Image.fromarray(T['newimg']), (x, 0)); x += T['w']
    M.save(os.path.join(outdir, 'sheets.png'))


if __name__ == '__main__':
    main(*sys.argv[1:4])
