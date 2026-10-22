#!/usr/bin/env python3
# ruff: noqa
"""
tools/mods/bps.py make SOURCE TARGET OUT.bps   |   bps.py apply SOURCE PATCH.bps OUT
BPS patches (the format Floating IPS / Flips, beat and most ROM patchers apply). Testers patch their OWN
copy of the original SCUS_971.96 from their disc, so no game code is distributed.
"""

import sys, zlib, struct


def vint(n):
    out = bytearray()
    while True:
        x = n & 0x7F
        n >>= 7
        if n == 0:
            out.append(0x80 | x)
            return bytes(out)
        out.append(x)
        n -= 1


def rvint(b, i):
    n, s = 0, 1
    while True:
        x = b[i]
        i += 1
        n += (x & 0x7F) * s
        if x & 0x80:
            return n, i
        s <<= 7
        n += s


def make(src, tgt):
    K = 32
    idx = {}
    for p in range(0, len(src) - K, 4):
        idx.setdefault(src[p : p + K], p)
    out = bytearray(b"BPS1" + vint(len(src)) + vint(len(tgt)) + vint(0))
    lit = bytearray()
    pos = 0
    srel = 0

    def flush():
        if lit:
            out.extend(vint(((len(lit) - 1) << 2) | 1) + lit)
            lit.clear()

    while pos < len(tgt):
        n = 0  # SourceRead: same bytes at the same offset
        while (
            pos + n < len(tgt) and pos + n < len(src) and src[pos + n] == tgt[pos + n]
        ):
            n += 1
        if n >= 8:
            flush()
            out.extend(vint(((n - 1) << 2) | 0))
            pos += n
            continue
        sp = idx.get(bytes(tgt[pos : pos + K])) if pos + K <= len(tgt) else None
        if sp is not None:  # SourceCopy: same bytes elsewhere (moved code/data)
            n = K
            while (
                pos + n < len(tgt) and sp + n < len(src) and src[sp + n] == tgt[pos + n]
            ):
                n += 1
            flush()
            off = sp - srel
            out.extend(vint(((n - 1) << 2) | 2) + vint((abs(off) << 1) | (off < 0)))
            srel = sp + n
            pos += n
            continue
        lit.append(tgt[pos])
        pos += 1
    flush()
    out += struct.pack("<II", zlib.crc32(src), zlib.crc32(tgt))
    out += struct.pack("<I", zlib.crc32(out))
    return bytes(out)


def apply(src, p):
    assert p[:4] == b"BPS1"
    i = 4
    ss, i = rvint(p, i)
    ts, i = rvint(p, i)
    ms, i = rvint(p, i)
    i += ms
    assert ss == len(src), "wrong source file"
    assert struct.unpack_from("<I", p, len(p) - 12)[0] == zlib.crc32(src), (
        "source CRC mismatch (not the original SCUS_971.96?)"
    )
    out = bytearray()
    srel = trel = 0
    while i < len(p) - 12:
        d, i = rvint(p, i)
        cmd, n = d & 3, (d >> 2) + 1
        if cmd == 0:
            out += src[len(out) : len(out) + n]
        elif cmd == 1:
            out += p[i : i + n]
            i += n
        elif cmd == 2:
            o, i = rvint(p, i)
            srel += -(o >> 1) if o & 1 else (o >> 1)
            out += src[srel : srel + n]
            srel += n
        else:
            o, i = rvint(p, i)
            trel += -(o >> 1) if o & 1 else (o >> 1)
            for _ in range(n):
                out.append(out[trel])
                trel += 1
    assert (
        len(out) == ts and zlib.crc32(out) == struct.unpack_from("<I", p, len(p) - 8)[0]
    ), "target CRC mismatch"
    return bytes(out)


if __name__ == "__main__":
    if sys.argv[1] == "make":
        s, t = open(sys.argv[2], "rb").read(), open(sys.argv[3], "rb").read()
        p = make(s, t)
        open(sys.argv[4], "wb").write(p)
        assert apply(s, p) == t
        print(f"{sys.argv[4]}: {len(p)} bytes (verified)")
    else:
        open(sys.argv[4], "wb").write(
            apply(open(sys.argv[2], "rb").read(), open(sys.argv[3], "rb").read())
        )
