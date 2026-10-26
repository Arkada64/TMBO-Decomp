"""Main menu labels (STORY_PLAN.md menu layout): paint 'SINGLE PLAYER' into SHELL1.TEX texture 3 over the dead
'ACCOUNT' line (Sony online accounts), built from the texture's own small-font glyphs (the INTERNET / LAN / OPTIONS
labels use that font). Copies palette indices (PSMT8), so the glyphs keep their exact look.
  python3 menulabels.py SHELL1.TEX(container) SHELL_DIR_WITH_STP.NGP OUT.TEX [preview.png]
Prints the label rectangles (texture coordinates, upright) for mods/menu.c."""
import sys, struct, zlib, numpy as np
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from textconv import records, tex_rec_size
src, sdir, out = sys.argv[1:4]
b = open(src, 'rb').read()
nl, xl = struct.unpack_from('<HH', b, 26); cs = struct.unpack_from('<I', b, 18)[0]
raw = bytearray(zlib.decompress(b[30 + nl + xl:30 + nl + xl + cs], -15))
rec = next((o, sz, gs) for o, sz, gs, k in records(bytes(raw), tex_rec_size) if gs & 0xffff == 3)
off = rec[0] + 0x80
W = H = 256
idx = np.frombuffer(bytes(raw[off:off + W * H]), np.uint8).reshape(H, W)[::-1].copy()   # upright (f coords)
BG = int(idx[5, 250])
# glyph boxes (upright rows / cols) measured from the texture: band rows, columns
G = {'S': (23, 38, 23, 33), 'I': (49, 64, 8, 15), 'N': (49, 64, 22, 33), 'G': (49, 64, 139, 148),
     'L': (98, 113, 44, 55), 'E': (49, 64, 54, 65), 'P': (121, 136, 40, 52), 'A': (98, 113, 58, 69),
     'Y': (23, 38, 71, 82), 'R': (49, 64, 68, 79)}
PAD = 3
TOP = 226                     # glyph band top in the new line (ACCOUNT line 221..246 cleared)
src_idx = idx.copy()
idx[180:256, :] = BG                # the dead CREATE / ACCOUNT lines (keeps the file within its disc size)
x = 4
for ch in 'SINGLE PLAYER':
    if ch == ' ':
        x += 10; continue
    r0, r1, c0, c1 = G[ch]
    patch = src_idx[r0 - PAD:r1 + PAD, c0 - 2:c1 + 2]
    tgt = idx[TOP - PAD:TOP - PAD + patch.shape[0], x - 2:x - 2 + patch.shape[1]]
    m = patch != BG
    tgt[m] = patch[m]
    x += (c1 - c0) + 4
print('SINGLE PLAYER cols 4..%d rows %d..%d (upright)' % (x - 4, TOP - 4, TOP + 19))
raw[off:off + W * H] = idx[::-1].tobytes()
c = zlib.compressobj(9, zlib.DEFLATED, -15); comp = c.compress(bytes(raw)) + c.flush()
crc = zlib.crc32(bytes(raw)) & 0xffffffff
loc = bytearray(b[:30 + nl + xl]); struct.pack_into('<III', loc, 14, crc, len(comp), len(raw))
tail = bytearray(b[30 + nl + xl + cs:])
cd = tail.find(b'PK\x01\x02'); struct.pack_into('<III', tail, cd + 16, crc, len(comp), len(raw))
pad = max(0, len(b) - (len(loc) + len(comp) + len(tail)))
eo = tail.find(b'PK\x05\x06'); struct.pack_into('<I', tail, eo + 16, len(loc) + len(comp) + pad)
open(out, 'wb').write(bytes(loc) + comp + b'\0' * pad + bytes(tail))
print('out', len(loc) + len(comp) + pad + len(tail), 'orig', len(b))
if len(sys.argv) > 4:
    from PIL import Image
    sys.path.insert(0, '/home/claude/lost')
    from tmbprev import load
    from textconv import rtx_records
    from hotex import clut_unswizzle
    rr = open(sdir + '/STP.RTX', 'rb').read(); R, _ = rtx_records(rr)
    cl = {a: (o, sz) for o, sz, a, tw, th in R}
    n = open(sdir + '/STP.NGP', 'rb').read()
    cbp = (struct.unpack_from('<Q', n, 0x45ae0 + 0x70)[0] >> 37) & 0x3fff
    o, sz = cl[cbp]
    pal = clut_unswizzle([tuple(x) for x in np.frombuffer(rr[o + 16:o + 16 + 1024], np.uint8).reshape(256, 4)])
    Image.fromarray(np.array(pal, np.uint8)[idx][..., :3]).resize((512, 512), Image.NEAREST).save(sys.argv[4])
