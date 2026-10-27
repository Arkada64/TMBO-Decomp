"""Textured preview of a built TMB level (top view) from the TMB files only: TEX linear PSMT8/PSMT4 + RTX CLUTs.
  python3 lvtexprev.py DIR NAME OUT.png [px=1600] [--crop x0,y0,x1,y1 world units]
- Walks the arena: the callback-id-1 node (for a donor-merged file the NGP's first entry is the donor's root,
  which only reaches DEATH4's sky / assets); standalone stage-1 files (no id-1 node) fall back to entry 0.
- Records are parsed the way texmRelocate / texmResRelocate do: stop at the first sizew-0 record. A CLUT that the
  game would never load (behind a premature sizew 0) shows as magenta; a missing texture id as cyan.
- Every triangle is rasterized with per-pixel UVs (not one texel per triangle), so a wrong swizzle / CLUT order
  shows as noise. Also writes OUT_sheet.png: the 64 biggest arena textures, each with the CLUT its meshes use."""
import sys, os, struct
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.dirname(HERE)); sys.path.insert(0, '/home/claude/lost')
from tmbmesh import decode
from textconv import tex_rec_size, rtx_rec_size
from hotex import clut_unswizzle
from PIL import Image
BASE = 0x980000
def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def game_records(d, first, size_fn):
    """as the game: records until sizew 0 (that one included, sized from its gs)"""
    o, out = first, []
    while o + 16 <= len(d):
        sz, key, gs = struct.unpack_from('<IIQ', d, o)
        if sz == 0:
            if gs: out.append((o, size_fn(gs), gs))
            break
        out.append((o, sz * 4, gs)); o += sz * 4
    return out


def tmb_cluts(r):
    cl = {}
    for o, b, gs in game_records(r, 0, rtx_rec_size):
        if ((gs >> 48) & 0xff) != 8: continue           # VRAM-resident textures (PSMT8H / 4HL / 4HH)
        a, tw, th = (gs >> 16) & 0xffff, (gs >> 40) & 15, (gs >> 44) & 15; ne = (1 << tw) * (1 << th)
        p = [tuple(x) for x in np.frombuffer(r[o + 16:o + 16 + 4 * ne], np.uint8).reshape(ne, 4)]
        cl[a] = np.array(clut_unswizzle(p) if ne == 256 else p, np.uint8)
    return cl


def tmb_textures(t):
    tex = {}
    for o, b, gs in game_records(t, u32(t, 4) * 16, tex_rec_size):
        tid, psm, tw, th = gs & 0xffff, (gs >> 32) & 0x3f, (gs >> 40) & 15, (gs >> 44) & 15
        if psm not in (0x13, 0x14): continue
        w, h = 1 << tw, 1 << th
        pay = np.frombuffer(t[o + 0x80:o + 0x80 + (w * h if psm == 0x13 else w * h // 2)], np.uint8)
        idx = pay if psm == 0x13 else np.stack([pay & 15, pay >> 4], 1).reshape(-1)
        tex[tid] = idx.reshape(h, w)
    return tex


def arena_root(n):
    from ngptrav import traverse
    ne = u32(n, 0)
    try:
        for o, op, i1, i2 in traverse(n, [4 + 4 * i for i in range(ne)]):
            if i1 == 1: return o, True
    except Exception:
        pass
    return u32(n, 4) - BASE, False


def arena_meshes(n, root):
    u16 = lambda o: struct.unpack_from('<H', n, o)[0]
    P = lambda s: (u32(n, s) - BASE) if BASE <= u32(n, s) < BASE + len(n) else None
    st, seen, out = [root], set(), []
    while st:
        o = st.pop()
        if o is None or o in seen: continue
        seen.add(o); op = u32(n, o) & 0x3f
        if op == 1: st += [P(o + 0x20 + 4 * i) for i in range(u16(o + 8))]
        elif op == 0: out.append(o)
    return out


def run(d, name, out, px=1600, crop=None):
    n = open(f'{d}/{name}.NGP', 'rb').read(); t = open(f'{d}/{name}.TEX', 'rb').read(); r = open(f'{d}/{name}.RTX', 'rb').read()
    cl, tex = tmb_cluts(r), tmb_textures(t)
    root, merged = arena_root(n)
    meshes = arena_meshes(n, root)
    tris = []; used = {}; miss_c = set(); miss_t = set()
    for o in meshes:
        m = decode(n, o); P = np.array(m['pos'])
        nt = struct.unpack_from('<H', n, o + 0x5a)[0]
        ctx = []
        for i in range(nt):
            tid = struct.unpack_from('<H', n, o + 0x50 + 2 * i)[0]; t0 = struct.unpack_from('<Q', n, o + 0x70 + 0x30 * i)[0]
            ctx.append((tid, (t0 >> 37) & 0x3fff))
        cur = 0
        for s in m['strips']:
            if s['tag'][3]: cur = (s['tag'][3] - 1) // 3
            if not ctx: continue
            key = ctx[min(cur, len(ctx) - 1)]
            used[key] = used.get(key, 0) + 1
            if key[0] not in tex: miss_t.add(key[0])
            elif key[1] not in cl: miss_c.add(key[1])
            idxs = [v[3] + s['base'] for v in s['nv']]
            for i in range(2, len(idxs)):
                tri = P[[idxs[i - 2], idxs[i - 1], idxs[i]]]
                if np.abs(tri - np.roll(tri, 1, 0)).sum(1).max() > 1700: continue
                uv = np.array([s['uv'][j] for j in (i - 2, i - 1, i)], float) / 4096.0
                tris.append((tri, uv, key))
    T = np.array([a for a, _, _ in tris])
    if crop: x0, y0, x1, y1 = crop
    else:
        xs, ys = T[..., 0], T[..., 1]
        x0, x1, y0, y1 = np.percentile(xs, 1), np.percentile(xs, 99), np.percentile(ys, 1), np.percentile(ys, 99)
    s = px / max(x1 - x0, y1 - y0); W, H = int((x1 - x0) * s) + 20, int((y1 - y0) * s) + 20
    img = np.zeros((H, W, 3), np.uint8); img[:] = (10, 10, 14)
    zb = np.full((H, W), -1e30)
    for k in np.argsort(T[..., 2].mean(1)):
        tri, uv, (tid, cbp) = tris[k]
        X = (tri[:, 0] - x0) * s + 10; Y = H - ((tri[:, 1] - y0) * s + 10)
        bx0, bx1 = max(0, int(np.floor(X.min()))), min(W - 1, int(np.ceil(X.max())))
        by0, by1 = max(0, int(np.floor(Y.min()))), min(H - 1, int(np.ceil(Y.max())))
        if bx1 < bx0 or by1 < by0: continue
        den = (Y[1] - Y[2]) * (X[0] - X[2]) + (X[2] - X[1]) * (Y[0] - Y[2])
        if abs(den) < 1e-9: continue
        gx, gy = np.meshgrid(np.arange(bx0, bx1 + 1) + 0.5, np.arange(by0, by1 + 1) + 0.5)
        a = ((Y[1] - Y[2]) * (gx - X[2]) + (X[2] - X[1]) * (gy - Y[2])) / den
        b = ((Y[2] - Y[0]) * (gx - X[2]) + (X[0] - X[2]) * (gy - Y[2])) / den
        c = 1 - a - b
        ins = (a >= -0.01) & (b >= -0.01) & (c >= -0.01)
        if not ins.any(): continue
        z = a * tri[0, 2] + b * tri[1, 2] + c * tri[2, 2]
        ins &= z >= zb[by0:by1 + 1, bx0:bx1 + 1]
        if not ins.any(): continue
        if tid not in tex: col = np.array([0, 255, 255], np.uint8)[None].repeat(ins.sum(), 0)
        elif cbp not in cl: col = np.array([255, 0, 255], np.uint8)[None].repeat(ins.sum(), 0)
        else:
            idx = tex[tid]; pal = cl[cbp]; h, w = idx.shape
            u = a[ins] * uv[0, 0] + b[ins] * uv[1, 0] + c[ins] * uv[2, 0]
            v = a[ins] * uv[0, 1] + b[ins] * uv[1, 1] + c[ins] * uv[2, 1]
            ii = idx[(np.floor(v * h).astype(int)) % h, (np.floor(u * w).astype(int)) % w]
            col = pal[np.minimum(ii, len(pal) - 1)][:, :3]
        sub = img[by0:by1 + 1, bx0:bx1 + 1]; sub[ins] = col
        zz = zb[by0:by1 + 1, bx0:bx1 + 1]; zz[ins] = z[ins]
    Image.fromarray(img).save(out)
    # texture sheet: the biggest arena textures with their CLUTs
    ks = sorted(used, key=lambda k: -(tex[k[0]].size if k[0] in tex else 0))[:64]
    cell, cols = 128, 8
    sh = Image.new('RGB', (cols * cell, ((len(ks) + cols - 1) // cols) * cell), (40, 40, 40))
    for i, (tid, cbp) in enumerate(ks):
        if tid in tex and cbp in cl:
            pal = cl[cbp]; im = pal[np.minimum(tex[tid], len(pal) - 1)][:, :, :3]
        else:
            im = np.zeros((8, 8, 3), np.uint8); im[:] = (255, 0, 255) if tid in tex else (0, 255, 255)
        sh.paste(Image.fromarray(im).resize((cell - 2, cell - 2), Image.NEAREST), ((i % cols) * cell, (i // cols) * cell))
    sh.save(out[:-4] + '_sheet.png')
    print(out, 'arena root', hex(root), 'merged' if merged else 'entry 0', 'meshes', len(meshes), 'tris', len(T),
          'textures', len(used), 'CLUTs not loaded', len(miss_c), 'texture ids missing', len(miss_t))
    return dict(miss_c=miss_c, miss_t=miss_t)


if __name__ == '__main__':
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    crop = None
    if '--crop' in sys.argv: crop = [float(v) for v in sys.argv[sys.argv.index('--crop') + 1].split(',')]; a = [x for x in a if ',' not in x]
    run(a[0], a[1], a[2], int(a[3]) if len(a) > 3 else 1600, crop)
