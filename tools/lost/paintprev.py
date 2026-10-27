"""Paint preview (mods/skins.c tmbr_CarRtxInit): the same hue turn on a car's RTX CLUTs, written next to copies of
its files.  python3 paintprev.py SRCDIR CODE OUTDIR STEP  -> OUTDIR/CODE.{NGP,PTR,TEX,RTX} with the RTX recoloured"""
import sys, os, struct, shutil
PAINT_STEPS, PAINT_S, PAINT_V = 24, 80, 40
def turn(r, g, b, t):
    mx, mn = max(r, g, b), min(r, g, b); d = mx - mn
    if mx < PAINT_V or d * 255 < PAINT_S * mx: return r, g, b
    tq = lambda a, q: int(a / q)                        # C division (truncates)
    if mx == r:
        h = tq((g - b) * 256, d); h += 1536 if h < 0 else 0
    elif mx == g: h = 512 + tq((b - r) * 256, d)
    else: h = 1024 + tq((r - g) * 256, d)
    h = (h + t) % 1536; f = h & 255
    x = mn + d * f // 256; y = mx - d * f // 256
    return [(mx, x, mn), (y, mx, mn), (mn, mx, x), (mn, y, mx), (x, mn, mx), (mx, mn, y)][min(h >> 8, 5)]
def recolour(rtx, step):
    d = bytearray(rtx); o = 0; t = step * 1536 // PAINT_STEPS
    while o + 16 <= len(d):
        sz, lo, hi = struct.unpack_from('<III', d, o + 0)[0], *struct.unpack_from('<II', d, o + 8)
        if not sz and not lo and not hi: break
        if (hi >> 16) & 0xFF == 0x08:
            ne = (sz * 4 - 16) // 4 if sz else (1 << ((hi >> 8) & 15)) * (1 << ((hi >> 12) & 15))
            for k in range(ne):
                p = o + 16 + 4 * k
                if p + 4 > len(d): break
                d[p:p + 3] = bytes(turn(d[p], d[p + 1], d[p + 2], t))
        if not sz: break
        o += sz * 4
    return bytes(d)
if __name__ == '__main__':
    src, code, out, step = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4])
    os.makedirs(out, exist_ok=True)
    for e in ('NGP', 'PTR', 'TEX'): shutil.copy(os.path.join(src, code + '.' + e), os.path.join(out, code + '.' + e))
    open(os.path.join(out, code + '.RTX'), 'wb').write(recolour(open(os.path.join(src, code + '.RTX'), 'rb').read(), step))
