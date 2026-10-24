"""Head-On level TEX -> textures. Records: a texture (key k), its mip levels (same key, smaller), then its CLUT
(key 0). Pixels are the PSMCT32 upload of PSMT8 / PSMT4 data (GS-swizzled), any number of 8 KB pages: decoded
page by page (CT32 page 64x32 words = T8 page 128x64 = T4 page 128x128, pages row-major in both)."""
import sys, struct
import numpy as np
sys.path.insert(0, '/home/claude/lost')
from texfile import recs
from gsmem import ct32_word, t8_byte, t4_nib
from hotex import clut_unswizzle

def _maps():
    # memory byte -> upload byte (CT32 page, row-major 64x32 words)
    up = np.empty(8192, np.int64)
    for y in range(32):
        for x in range(64):
            wd = ct32_word(x, y)
            for b in range(4): up[wd * 4 + b] = (y * 64 + x) * 4 + b
    t8 = np.array([[up[t8_byte(x, y)] for x in range(128)] for y in range(64)], np.int64)
    t4 = np.array([[t4_nib(x, y) for x in range(128)] for y in range(128)], np.int64)
    t4b = up[t4 >> 1]; t4hi = (t4 & 1).astype(bool)
    return t8, t4b, t4hi
T8MAP, T4B, T4HI = _maps()

def decode_pixels(raw, w_words, h_words, bpp):
    """raw = upload bytes of a w x h CT32 rect -> index image"""
    pw, ph = max(1, w_words // 64), max(1, h_words // 32)
    if w_words < 64 or h_words < 32:            # smaller than a page: pad the rect to a page
        buf = np.zeros(8192, np.uint8)
        a = np.frombuffer(raw[:w_words * h_words * 4], np.uint8).reshape(h_words, w_words * 4)
        buf.reshape(32, 256)[:h_words, :w_words * 4] = a
        pages = [[buf]]
    else:
        a = np.frombuffer(raw[:w_words * h_words * 4], np.uint8).reshape(h_words, w_words * 4)
        pages = [[a[py * 32:(py + 1) * 32, px * 256:(px + 1) * 256].reshape(-1) for px in range(pw)] for py in range(ph)]
    if bpp == 8:
        W, H = 2 * w_words, 2 * h_words
        tiles = [[p[T8MAP] for p in row] for row in pages]
    else:
        W, H = 2 * w_words, 4 * h_words
        tiles = [[np.where(T4HI, p[T4B] >> 4, p[T4B] & 15) for p in row] for row in pages]
    img = np.block(tiles)
    return img[:H, :W].astype(np.uint8)

def textures(t):
    cl, rs, end = recs(t)
    out = {}
    i = 0
    while i < len(rs):
        r = rs[i]
        if r['key'] == 0: i += 1; continue
        j = i + 1
        while j < len(rs) and rs[j]['key'] == r['key']: j += 1      # mip levels
        if j >= len(rs): break
        c = rs[j]
        nent = (1 << c['tw']) * (1 << c['th'])
        bpp = 4 if nent == 16 else 8
        p = [struct.unpack_from('<4B', t, c['off'] + 0x80 + 4 * k) for k in range(nent)]
        if bpp == 8: p = clut_unswizzle(p)
        raw = t[r['off'] + 0x80:r['off'] + r['bytes']]
        idx = decode_pixels(raw, 1 << r['tw'], 1 << r['th'], bpp)
        P = np.array(p, np.uint16); P[:, 3] = np.minimum(255, P[:, 3] * 2)
        img = P[idx].astype(np.uint8)
        out[r['key']] = dict(img=img, idx=idx.reshape(-1), bpp=bpp, w=img.shape[1], h=img.shape[0], pal=np.array(p, np.uint8),
                             clutraw=bytes(t[c['off'] + 0x80:c['off'] + 0x80 + 4 * nent]), ctw=c['tw'], cth=c['th'],
                             mips=j - i - 1)
        i = j + 1
    return out
