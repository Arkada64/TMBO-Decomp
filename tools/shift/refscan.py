# ruff: noqa
import struct
import sys

T = "/mnt/d/TMB Decomp/test/"


def load(p):
    d = open(p, "rb").read()
    (shoff,) = struct.unpack_from("<I", d, 0x20)
    (shn,) = struct.unpack_from("<H", d, 0x30)
    (shstr,) = struct.unpack_from("<H", d, 0x32)
    secs = []
    for i in range(shn):
        nm, ty, fl, addr, off, sz = struct.unpack_from("<IIIIII", d, shoff + i * 40)
        secs.append([nm, ty, fl, addr, off, sz])
    so = secs[shstr][4]
    out = []
    for nm, ty, fl, addr, off, sz in secs:
        name = d[so + nm : d.index(b"\0", so + nm)].decode()
        if addr and ty == 1:
            out.append((name, addr, d[off : off + sz], fl))
    return out


A, B = load(T + "S0.ELF"), load(T + "B5.ELF")
ranges = [tuple(int(x, 16) for x in r.split("-")) for r in sys.argv[1:]] or [
    (0x60A000, 0x61A000),
    (0x680000, 0x69D000),
]
inr = lambda v: any(lo <= v < hi for lo, hi in ranges)


def words(secs):
    m = {}
    for name, addr, data, fl in secs:
        for i in range(0, len(data) - 3, 4):
            m[addr + i] = (struct.unpack_from("<I", data, i)[0], name, fl & 4)
    return m


wa, wb = words(A), words(B)
bad = []
for a, (v, name, ex) in sorted(wa.items()):
    if not ex:
        if inr(v):
            bad.append(("data", a, name, v, wb.get(a, (None,))[0]))
        continue
    op = v >> 26
    if op != 0xF:
        continue
    rt = (v >> 16) & 31
    hi = (v & 0xFFFF) << 16
    for k in range(1, 40):
        w = wa.get(a + 4 * k)
        if not w:
            break
        w = w[0]
        o = w >> 26
        rs = (w >> 21) & 31
        r2 = (w >> 16) & 31
        if rs == rt and o in (
            9,
            0xD,
            0x23,
            0x2B,
            0x20,
            0x24,
            0x21,
            0x25,
            0x28,
            0x29,
            0x37,
            0x3F,
            0x31,
            0x39,
            0x1E,
            0x1F,
            0x27,
        ):
            lo = w & 0xFFFF
            val = (
                (hi | lo)
                if o == 0xD
                else (hi + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
            )
            if inr(val):
                vb = wb[a][0]
                wb2 = wb[a + 4 * k][0]
                hb = (vb & 0xFFFF) << 16
                lb = wb2 & 0xFFFF
                valb = (
                    (hb | lb)
                    if o == 0xD
                    else (hb + (lb - 0x10000 if lb & 0x8000 else lb)) & 0xFFFFFFFF
                )
                bad.append(("code", a, name, val, valb))
        if (w >> 26) == 0xF and r2 == rt:
            break
for kind, a, name, v, vb in bad:
    d = None if vb is None else vb - v
    if d != 0x80:
        print(
            f"{kind} {a:08X} {name:8} {v:08X} -> {vb if vb is None else format(vb, '08X')}  delta {d}"
        )
print(len(bad), "refs in range total")
