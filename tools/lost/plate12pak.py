"""Paint '12 Pak' over the unused 'Black Razer' car-name plate (SHELL1.TEX texture 58, name switch child 15),
built from the game's own typewriter glyphs: '1','2' and 'P' from texture 55 (car select numbers / OPPONENTS),
thickened and scaled to the plate size; 'a','k' from the 'Roadkill' plate."""
import sys, struct, numpy as np
from PIL import Image, ImageFilter
from tmbprev import load, image
from hotex import clut_unswizzle
d, out = sys.argv[1], sys.argv[2]
prev = sys.argv[3] if len(sys.argv) > 3 else None
n, t, r, byid, clut = load(d)
def tex(tid, node):
    q = struct.unpack_from('<Q', n, node + 0x70)[0]
    return image(t, r, byid, clut, tid, (q >> 37) & 0x3fff)[::-1].astype(np.float32)
t55 = tex(55, 0x71ad0); t58 = tex(58, 0x71830)
def glyph(a, r0, r1, c0, c1, base, scale=1.0, thick=0, th=420):
    g = a[r0:r1, c0:c1].copy()
    core = Image.fromarray(((g[..., :3].sum(2) > th) * 255).astype(np.uint8))
    m = np.asarray(core.filter(ImageFilter.MaxFilter(5)).filter(ImageFilter.GaussianBlur(1.5)), np.float32) / 255
    g *= np.clip(m * 1.5, 0, 1)[..., None]            # glyph + its glow only (no scratches / neighbours)
    if scale != 1.0 or thick:
        im = [Image.fromarray(g[..., k].astype(np.uint8)) for k in range(4)]
        if scale != 1.0:
            sz = (round(g.shape[1] * scale), round(g.shape[0] * scale))
            im = [x.resize(sz, Image.BICUBIC) for x in im]
        g = np.stack([np.asarray(x, np.float32) for x in im], -1)
        if thick:                                     # embolden: max with a 1-px right shift
            h = g.copy(); h[:, 1:] = np.maximum(h[:, 1:], g[:, :-1]); g = h
        base = (base - r0) * scale
    else:
        base = base - r0
    return g, base                          # patch, baseline row within it
S = 25 / 22
G = [glyph(t55, 213, 248, 214, 230, 242, S, 1, 300), glyph(t55, 213, 248, 229, 250, 242, S, 1, 280), None,
     glyph(t55, 63, 97, 24, 48, 91, S, 1), glyph(t58, 3, 42, 56, 79, 34), glyph(t58, 3, 42, 100, 122, 34)]
R0, R1, C0, C1 = 203, 251, 4, 255           # Black Razer box (upright)
H, W = R1 - R0, C1 - C0
can = np.zeros((H, W, 4), np.float32)
x, base = 10, 34                           # same left edge/baseline as the other plates
for g in G:
    if g is None: x += 10; continue
    p, b = g; top = int(round(base - b)); h, w = p.shape[:2]
    y0, y1 = max(0, top), min(H, top + h)
    can[y0:y1, x:x + w] = np.maximum(can[y0:y1, x:x + w], p[y0 - top:y1 - top])
    x += w - 3
o = clut[(struct.unpack_from('<Q', n, 0x71830 + 0x70)[0] >> 37) & 0x3fff][0]
pal = np.array(clut_unswizzle([tuple(p) for p in np.frombuffer(r[o+16:o+16+1024], np.uint8).reshape(256, 4)]), np.int32)
flat = can.reshape(-1, 4).astype(np.int32)
new = ((flat[:, None, :] - pal[None]) ** 2 * np.array([1, 1, 1, 2])).sum(-1).argmin(1).astype(np.uint8).reshape(H, W)
x = byid[58]; off = x['off'] + 0x80
idx = np.frombuffer(t[off:off+65536], np.uint8).reshape(256, 256).copy(); up = idx[::-1]
up[R0:R1, C0:C1] = new
t2 = bytearray(t); t2[off:off+65536] = up[::-1].tobytes(); open(out, 'wb').write(t2)
if prev:
    a = pal[up].astype(np.uint8)[100:256]; im = Image.fromarray(a); bg = Image.new('RGBA', im.size, (0, 0, 0, 255))
    im.putalpha(im.split()[3].point(lambda v: min(255, v * 2))); bg.alpha_composite(im)
    bg.resize((im.width * 3, im.height * 3), Image.NEAREST).save(prev)
