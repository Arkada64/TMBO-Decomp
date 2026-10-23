"""Paint '12 Pak' over the unused 'Black Razer' car-name plate (SHELL1.TEX texture 58, name switch child 15)."""
import sys, struct, numpy as np
from PIL import Image, ImageDraw, ImageFont, ImageFilter
from tmbprev import load
from hotex import clut_unswizzle
d = sys.argv[1]                      # dir with STP.NGP/TEX/RTX/PTR (decompressed shell)
out = sys.argv[2]                    # new raw TEX
n, t, r, byid, clut = load(d)
x = byid[58]; off = x['off'] + 0x80
q = struct.unpack_from('<Q', n, 0x71830 + 0x70)[0]; o = clut[(q >> 37) & 0x3fff][0]
pal = np.array(clut_unswizzle([tuple(p) for p in np.frombuffer(r[o+16:o+16+1024], np.uint8).reshape(256, 4)]), np.int32)
idx = np.frombuffer(t[off:off+65536], np.uint8).reshape(256, 256).copy()
up = idx[::-1]                       # upright view
# style from the 'Roadkill' plate (child 4 region rows 205..248 is ours; sample a word's colours)
img = pal[up]
R0, R1, C0, C1 = 203, 251, 4, 255     # Black Razer box (upright)
font = ImageFont.truetype('/usr/share/fonts/truetype/freefont/FreeMonoBold.ttf', int(sys.argv[3]) if len(sys.argv) > 3 else 40)
W, H = C1 - C0, R1 - R0
m = Image.new('L', (W, H), 0); dr = ImageDraw.Draw(m)
txt = '12 Pak'; bb = dr.textbbox((0, 0), txt, font=font)
dr.text(((W - (bb[2]-bb[0]))//2 - bb[0] - 20, (H - (bb[3]-bb[1]))//2 - bb[1]), txt, font=font, fill=255)
core = np.asarray(m, np.float32) / 255
glow = np.asarray(m.filter(ImageFilter.MaxFilter(5)).filter(ImageFilter.GaussianBlur(3)), np.float32) / 255
glow = np.clip(glow * 1.6, 0, 1)
# colours (RGB 0..255, PS2 alpha 0..128): cream core, brown glow, black background
coreC = np.array([235, 220, 175]); glowC = np.array([150, 95, 35])
rgb = glowC[None, None] * glow[..., None]
rgb = rgb * (1 - core[..., None]) + coreC[None, None] * core[..., None]
a = np.clip(np.maximum(glow, core) * 128, 0, 128)
tgt = np.concatenate([rgb, a[..., None]], -1).astype(np.int32)
flat = tgt.reshape(-1, 4)
dist = ((flat[:, None, :] - pal[None, :, :]) ** 2 * np.array([1, 1, 1, 2])).sum(-1)
new = dist.argmin(1).astype(np.uint8).reshape(H, W)
up[R0:R1, C0:C1] = new
idx = up[::-1]
t2 = bytearray(t); t2[off:off+65536] = idx.tobytes()
open(out, 'wb').write(t2)
Image.fromarray(pal[up].astype(np.uint8)[150:256]).resize((512, 212)).save(sys.argv[4] if len(sys.argv) > 4 else '/tmp/p.png')
