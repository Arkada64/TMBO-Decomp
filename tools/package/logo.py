"""TMBR.exe icon + launcher header from the game's own logo: SHELL1.TEX textures 60-62 ('twisted metal', 'ONLINE',
':BLACK' pieces; stored upside down), assembled (piece 62 at x 372). usage: logo.py SHELL1.TEX.raw SHELL1.RTX outdir"""
import sys, numpy as np
sys.path.insert(0, __file__.rsplit('/', 2)[0] + '/lost')
from textconv import records, tex_rec_size, rtx_records
from hotex import clut_unswizzle
from PIL import Image, ImageDraw
t = open(sys.argv[1], 'rb').read(); r = open(sys.argv[2], 'rb').read(); out = sys.argv[3]
recs = list(records(t, tex_rec_size)); rr, _ = rtx_records(r)
def img(i):
    o, b, gs, k = recs[i]; w, h = 1 << ((gs >> 40) & 15), 1 << ((gs >> 44) & 15)
    idx = np.frombuffer(t[o + 0x80:o + b], np.uint8)[:w * h]
    co, tw, th = rr[i][0], rr[i][3], rr[i][4]; ne = (1 << tw) * (1 << th)
    pal = np.array(clut_unswizzle([tuple(x) for x in np.frombuffer(r[co + 16:co + 16 + 4 * ne], np.uint8).reshape(ne, 4)]), np.uint8)
    a = pal[idx].reshape(h, w, 4)[::-1].copy(); a[..., 3] = np.minimum(255, a[..., 3].astype(int) * 2)
    return Image.fromarray(a, 'RGBA')
c = Image.new('RGBA', (700, 256), (0, 0, 0, 0))
for x, i in ((0, 60), (256, 61), (372, 62)): c.alpha_composite(img(i), (x, 0))
L = c.crop(c.getbbox()); L.save(out + '/logo.png')
tw = L.crop((0, 28, 214, 100)); mt = L.crop((238, 28, 384, 100)); on = L.crop((185, 96, 470, 181))
S = 256; tile = Image.new('RGBA', (S, S), (0, 0, 0, 0))
ImageDraw.Draw(tile).rounded_rectangle((0, 0, S - 1, S - 1), radius=36, fill=(18, 18, 18, 255))
def fit(im, w): return im.resize((w, round(im.size[1] * w / im.size[0])), Image.LANCZOS)
a = fit(tw, 232); tile.alpha_composite(a, (12, 10))
m = fit(mt, 196); tile.alpha_composite(m, (30, 10 + a.size[1] - 6))
o = fit(on, 236); tile.alpha_composite(o, (10, S - o.size[1] - 4))
tile.save(out + '/TMBR.ico', sizes=[(16, 16), (24, 24), (32, 32), (48, 48), (64, 64), (128, 128), (256, 256)])
