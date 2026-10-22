#!/usr/bin/env python3
# ruff: noqa
"""
tools/mods/apply_pnach.py SHIFT_ELF BASE_SYMS SHIFT_SYMS PNACH SECTIONS_FILE
Bake PCSX2 pnach patches (written for the ORIGINAL online ELF, CRC C54E5CF2) into a shiftable/modded ELF.
PCSX2 only applies a pnach to the exact original game, so modded builds lose the community patches
(revival-server DNS, bugfixes, ...). This translates each patch to the moved build and writes it into
the ELF file:
  - patch address -> same offset inside the same symbol in the new build
  - j/jal values -> target translated; `lui` of an in-image address paired with the next write's
    ori/addiu -> translated as a pair; anything else is written as-is
Limits:
  - written into the file = applied once at boot. Fine for code and constant data. A 'continuous'
    patch on a variable the game rewrites at runtime only sets its initial value; those are listed.
  - conditional (D) codes are not supported: such sections are rejected.
BASE_SYMS / SHIFT_SYMS: `mips-linux-gnu-nm -n -S` of the matching ELF and of the shifted ELF.
"""

import sys, re, struct, bisect

elf, base_syms, shift_syms, pnach, sections_file = sys.argv[1:6]


def load(p):
    s = []
    for l in open(p):
        f = l.split()
        if len(f) == 4:
            a, z, t, n = f
            z = int(z, 16)
        elif len(f) == 3:
            a, t, n = f
            z = 0
        else:
            continue
        if t in "Aa" or n.startswith("."):
            continue
        s.append((int(a, 16), z, n))
    s.sort()
    return s


B = load(base_syms)
S = {n: a for a, z, n in load(shift_syms)}
BA = [a for a, z, n in B]


def tr(addr):
    i = bisect.bisect_right(BA, addr) - 1
    for j in range(i, max(i - 8, -1), -1):  # prefer the sized object that contains it
        a, z, n = B[j]
        if a <= addr < a + max(z, 1) and n in S:
            return S[n] + (addr - a)
    for j in range(
        i, max(i - 64, -1), -1
    ):  # else nearest preceding symbol present in both
        a, z, n = B[j]
        if n in S:
            return S[n] + (addr - a)
    raise SystemExit(f"cannot translate {addr:08X}")


INIMG = lambda v: 0x100000 <= v < 0x725694
want = [l.strip() for l in open(sections_file) if l.strip() and not l.startswith("#")]
secs, cur = {}, None
for l in open(pnach, encoding="utf-8", errors="replace"):
    l = l.split("//")[0].strip()
    m = re.match(r"\[(.*)\]", l)
    if m:
        cur = m.group(1).strip()
        secs.setdefault(cur, [])
        continue
    m = re.match(
        r"patch=(\d),EE,([0-9A-Fa-f]{8}),(word|extended|short|byte),([0-9A-Fa-f]{1,8})",
        l,
    )
    if m and cur:
        secs[cur].append(
            (int(m.group(1)), m.group(2).upper(), m.group(3), int(m.group(4), 16))
        )
d = bytearray(open(elf, "rb").read())
(phoff,) = struct.unpack_from("<I", d, 0x1C)
phsz, phn = struct.unpack_from("<HH", d, 0x2A)
SEGS = [struct.unpack_from("<IIIII", d, phoff + i * phsz) for i in range(phn)]
SEGS = [
    (va, off, fsz) for t, off, va, pa, fsz in SEGS if t == 1
]  # PT_LOAD: (vaddr, file offset, file size)


def fofs(va):
    for sva, off, fsz in SEGS:
        if sva <= va < sva + fsz:
            return off + va - sva
    raise AssertionError(f"{va:08X} not in the file image")


def put(va, val, size):
    struct.pack_into(
        {4: "<I", 2: "<H", 1: "<B"}[size], d, fofs(va), val & ((1 << (8 * size)) - 1)
    )


warn = []
# The original (matching) ELF, to find the `lui` that a patched low half pairs with
import os

bd = open(
    os.environ.get("BASE_ELF", os.path.join(os.path.dirname(base_syms), "base.elf")),
    "rb",
).read()
(b_phoff,) = struct.unpack_from("<I", bd, 0x1C)
b_off, b_va, _, b_fsz = struct.unpack_from("<IIII", bd, b_phoff + 4)


def bget(va):
    return (
        struct.unpack_from("<I", bd, b_off + va - b_va)[0]
        if 0 <= va - b_va < b_fsz - 3
        else None
    )


def sget(va):
    return struct.unpack_from("<I", d, fofs(va))[0]


LO_OPS = (
    {0x9, 0xD, 0x1E, 0x1F}
    | set(range(0x20, 0x30))
    | {0x31, 0x35, 0x37, 0x39, 0x3D, 0x3F}
)


def fix_lo(name, addr, val):
    """A patched addiu/ori/load/store whose base register was set by a `lui` in the original code just before
    it: the address it forms moved in this build. Returns the translated instruction (and fixes the lui)."""
    op = val >> 26
    rs = (val >> 21) & 31
    if op not in LO_OPS or rs == 0:
        return val
    for back in range(1, 7):
        w = bget(addr - 4 * back)
        if w is None:
            return val
        if (w >> 26) == 0xF and ((w >> 16) & 31) == rs:
            break
    else:
        return val
    lo = val & 0xFFFF
    full = ((w & 0xFFFF) << 16) + (
        lo if op == 0xD else (lo - 0x10000 if lo & 0x8000 else lo)
    )
    if not INIMG(full):
        return val
    t = tr(full)
    need = (t >> 16) if op == 0xD else ((t + 0x8000) >> 16)
    la = tr(addr - 4 * back)
    cur = sget(la)
    if (cur >> 26) != 0xF:
        warn.append(
            f"{name}: {addr:08X}: lui moved/missing in the new build, lo-half written unchanged"
        )
        return val
    if (cur & 0xFFFF) != (need & 0xFFFF):
        put(la, (cur & 0xFFFF0000) | (need & 0xFFFF), 4)
    if bd[b_off + full - b_va : b_off + full - b_va + 16] != bytes(
        d[fofs(t) : fofs(t) + 16]
    ):
        warn.append(f"{name}: {addr:08X}: {full:08X} -> {t:08X} data differs (check)")
    print(f"  {name}: lo-half at {addr:08X}: {full:08X} -> {t:08X}")
    return (val & 0xFFFF0000) | (t & 0xFFFF)


TICK = S.get("tmbr_pnachTable")
TICK_N = 96


def add_tick(name, va, val, size):
    if TICK is None:
        warn.append(
            f"{name}: continuous write to data {va:08X} only sets its initial value (no tmbr_pnachTable)"
        )
        return
    for i in range(TICK_N):
        if sget(TICK + 8 * i) == 0:
            put(TICK + 8 * i, va | ({1: 0, 2: 1, 4: 2}[size] << 28), 4)
            put(TICK + 8 * i + 4, val, 4)
            return
    raise SystemExit("tmbr_pnachTable full")


for name in want:
    assert name in secs, f"section not found: {name}"
    ps = secs[name]
    assert all(not (t == "extended" and a[0] in "DE") for _, a, t, _ in ps), (
        f"{name}: conditional codes unsupported"
    )
    k = 0
    while k < len(ps):
        place, a, typ, val = ps[k]
        if typ == "extended":
            size = {"0": 1, "1": 2, "2": 4}[a[0]]
            addr = int(a[1:], 16)
        else:
            size = {"word": 4, "short": 2, "byte": 1}[typ]
            addr = int(a, 16) & 0x0FFFFFFF
        naddr = tr(addr)
        nval = val
        if (
            size == 4 and 0x100000 <= addr < 0x2AC080
        ):  # instructions only (data words left alone)
            op = val >> 26
            if op in (2, 3):  # j / jal
                tgt = (val & 0x3FFFFFF) << 2
                if INIMG(tgt):
                    nval = (val & 0xFC000000) | ((tr(tgt) >> 2) & 0x3FFFFFF)
            elif (
                op == 0xF and INIMG((val & 0xFFFF) << 16) and k + 1 < len(ps)
            ):  # lui of an address
                nxt = ps[k + 1][3]
                rt = (val >> 16) & 31
                if (nxt >> 26) in (0x9, 0xD) and (
                    (nxt >> 21) & 31
                ) == rt:  # addiu/ori rX, rX, lo
                    lo = nxt & 0xFFFF
                    full = ((val & 0xFFFF) << 16) + (
                        lo - 0x10000 if (nxt >> 26) == 9 and lo & 0x8000 else lo
                    )
                    t = tr(full)
                    hi = (t + (0x8000 if (nxt >> 26) == 9 else 0)) >> 16
                    put(naddr, (val & 0xFFFF0000) | (hi & 0xFFFF), 4)
                    na2 = tr(
                        int(ps[k + 1][1][1:], 16)
                        if ps[k + 1][2] == "extended"
                        else int(ps[k + 1][1], 16)
                    )
                    put(na2, (nxt & 0xFFFF0000) | (t & 0xFFFF), 4)
                    k += 2
                    continue
                warn.append(
                    f"{name}: lui {val:08X} at {addr:08X} looks like an address half; written unchanged"
                )
            else:
                nval = fix_lo(name, addr, val)
        if place == 1 and not (0x100000 <= addr < 0x2AC080):
            add_tick(
                name, naddr, nval, size
            )  # re-applied every frame by mods/camera_pnach.s
        put(naddr, nval, size)
        k += 1
    print(f"applied [{name}] ({len(ps)} writes)")
open(elf, "wb").write(d)
for w in warn:
    print("NOTE:", w)
