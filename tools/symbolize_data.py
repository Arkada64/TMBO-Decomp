#!/usr/bin/env python3
# ruff: noqa
"""
symbolize_data.py MATCHING_ELF : turn raw in-image pointers in asm/data/*.s into symbol references so they
move in a shifted build. `.word 0x004DF2B8` -> `.word P_004DF2B8`, with P_004DF2B8 defined relative to the
object it points into (symbase.py) in config/US/data_ptrs_shiftable.txt. Bytes are unchanged in a normal link.
Skips objects that look like tables of 16-bit pairs. Idempotent (re-defines P_ symbols from earlier runs).
Must be re-run after every `configure.py split/generate` (those re-run splat and rewrite asm/).
"""

import re
import sys
import collections
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from symbase import Base

R = Path.home() / "tmbo_decomp"
B = Base(sys.argv[1])
LO, HI = 0x100000, 0x725694 + 4
WORD = re.compile(
    r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s*\.word\s+)(0x[0-9A-Fa-f]+)\b(.*)$"
)
FLOAT = re.compile(
    r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*)\.float\s+\S+\s*$"
)


def shortpair(v):
    hi = v >> 16
    if hi == 0:
        return False
    return hi < 0x10 or (hi < 0x400 and not (LO >> 16) <= hi <= (HI >> 16))


defs, stats = {}, collections.Counter()


def define(v):
    name = f"P_{v:08X}"
    if name not in defs:
        defs[name] = f"{name} = {B.expr(v)};"
    return name


SHORT = re.compile(
    r"^(\s*)/\* [0-9A-F]+ ([0-9A-F]{8}) \*/\s*\.short\s+(0x[0-9A-Fa-f]+)\s*$"
)
ASCIZ = re.compile(r"^(\s*)/\* [0-9A-F]+ ([0-9A-F]{8}) \*/\s*\.asciz\s+\"(.*)\"\s*$")
RAW = re.compile(r"^\s*/\* ([0-9A-F]{8}) \*/\s*$")


def solid(v):
    """only accept split/mis-typed words that land on a known symbol or inside a sized object"""
    if v in B.exact:
        return True
    import bisect as _b

    i = _b.bisect_right(B.a, v) - 1
    return any(
        B.s[j][0] <= v < B.s[j][0] + B.s[j][1] for j in range(i, max(i - 8, -1), -1)
    )


def merge_split_words(L):
    """g++ 2.x pointer-to-member structs etc. come out as two .short lines; 4-byte pointers sometimes as
    a 3-char .asciz: turn the ones that decode to a real in-image address back into one .word"""
    out, i, n = [], 0, 0
    while i < len(L):
        m1 = SHORT.match(L[i])
        m2 = SHORT.match(L[i + 1]) if m1 and i + 1 < len(L) else None
        if (
            m1
            and m2
            and int(m1.group(2), 16) % 4 == 0
            and int(m2.group(2), 16) == int(m1.group(2), 16) + 2
        ):
            v = int(m1.group(3), 16) | (int(m2.group(3), 16) << 16)
            if LO <= v < HI and v % 4 == 0 and solid(v):
                va = int(m1.group(2), 16)
                out.append(
                    f"{m1.group(1)}/* {va - 0x100000:X} {va:08X} {v.to_bytes(4, 'little').hex().upper()} */ .word 0x{v:08X}"
                )
                i += 2
                n += 1
                continue
        ma = ASCIZ.match(L[i])
        mr = RAW.match(L[i + 1]) if ma and i + 1 < len(L) else None
        if ma and mr and int(ma.group(2), 16) % 4 == 0:
            v = int.from_bytes(bytes.fromhex(mr.group(1)), "little")
            if LO <= v < HI and v % 4 == 0 and solid(v):
                va = int(ma.group(2), 16)
                out.append(
                    f"{ma.group(1)}/* {va - 0x100000:X} {va:08X} {mr.group(1)} */ .word 0x{v:08X}"
                )
                i += 2
                n += 1
                continue
        out.append(L[i])
        i += 1
    return out, n


ROM = (R / "disks/SCUS_971.96.rom").read_bytes()
ANYWORD = re.compile(
    r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*\.word\s+)(\S+)(.*)$"
)


def unsymbolize_offset_tables(L):
    """Sorted tables of big integers (file offsets/sizes) fall in the program's address range, so
    spimdisasm turned them into symbol references. In a shifted build those numbers would change.
    An object whose words are (almost) all increasing and often not 4-aligned is data, not pointers:
    put the raw values back."""
    n = 0
    objs, cur = [], []
    for i, l in enumerate(L):
        if re.match(r"\s*(dlabel|glabel)\s", l) and cur:
            objs.append(cur)
            cur = []
        cur.append(i)
    if cur:
        objs.append(cur)
    for ob in objs:
        ws = [(i, mm) for i in ob if (mm := ANYWORD.match(L[i]))]
        if len(ws) < 16:
            continue
        vals = [int.from_bytes(bytes.fromhex(mm.group(2)), "little") for _, mm in ws]
        inc = sum(b >= a for a, b in zip(vals, vals[1:])) / (len(vals) - 1)
        odd = sum(v % 4 != 0 for v in vals) / len(vals)

        # sorted tables of string pointers look the same: keep those (targets start a string in the image)
        def str_start(v):
            o = v - 0x100000
            return 0 < o < len(ROM) and ROM[o - 1] == 0 and 0x20 <= ROM[o] < 0x7F

        strs = sum(str_start(v) for v in vals) / len(vals)
        if inc >= 0.95 and odd >= 0.2 and strs < 0.5:
            for (i, mm), v in zip(ws, vals):
                if not mm.group(3).startswith("0x"):
                    n += 1
                if "offset-table" not in L[i]:
                    L[i] = f"{mm.group(1)}0x{v:08X} /* offset-table */"
        else:  # undo an earlier run's marking (e.g. string-pointer tables)
            for i, mm in ws:
                if "offset-table" in L[i]:
                    L[i] = L[i].replace(" /* offset-table */", "")
    return n


CODEREFS = set()
for f in (R / "asm").rglob("*.s"):
    if "asm/data" in str(f):
        continue
    CODEREFS.update(
        re.findall(r"%(?:hi|lo|gp_rel)\(([\w.]+)", f.read_text(errors="ignore"))
    )
# machine code embedded in data: libkernl's EE-kernel patch, copied to 0x80076000 (0x740 bytes) and
# 0x82000 (0x28 bytes) by func_002A20C8. Instruction words, never pointers.
RAW_RANGES = [(0x4DD5D8, 0x4DDD40)]
SYMWORD = re.compile(
    r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*\.word\s+)([A-Za-z_][\w.]*)(\s*\+\s*0x[0-9A-Fa-f]+)?\s*$"
)


def unsymbolize_fake_refs(L, fname):
    """spimdisasm symbolizes any word that falls in the address range. Two kinds are not pointers:
    - VU microcode (vutext): every word is an instruction
    - words pointing into .sbss/.bss at a label that no code ever references (halfword pairs such as
      zlib's cpdist table 0x00610041, MIPS instruction templates 0x00621825, fixed-point pairs ...)
    Put the raw value back, marked /* raw */ so the P_ pass leaves it alone."""
    n = 0
    for i, l in enumerate(L):
        ma = ANYWORD.match(l)
        if ma and "/* raw */" not in l:
            va = int(re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8})", l).group(1), 16)
            if any(lo <= va < hi for lo, hi in RAW_RANGES):
                v = int.from_bytes(bytes.fromhex(ma.group(2)), "little")
                L[i] = f"{ma.group(1)}0x{v:08X} /* raw */"
                n += not ma.group(3).startswith("0x")
                continue
        m = SYMWORD.match(l)
        if not m:
            continue
        v = int.from_bytes(bytes.fromhex(m.group(2)), "little")
        if "vutext" in fname or (
            0x4FB400 <= v < 0x725694
            and not m.group(3).startswith("P_")
            and m.group(3) not in CODEREFS
        ):
            L[i] = f"{m.group(1)}0x{v:08X} /* raw */"
            n += 1
    return n


# .gcc_except_table (C++ EH regions: start/end/handler code addresses) is split as an .incbin blob, so its
# code pointers can't move. Expand it to .word lines once; the P_ pass below then symbolizes them.
ET = R / "asm/data/gcc_except_table.s"
if ET.exists() and ".incbin" in ET.read_text():
    t = ET.read_text()
    binp = re.search(r'\.incbin "([^"]+)"', t).group(1)
    blob = Path(binp).read_bytes()
    words = "\n".join(
        f"    /* {0x3F9500 + i:X} {0x4F9500 + i:08X} {blob[i : i + 4].hex().upper()} */ .word 0x{int.from_bytes(blob[i : i + 4], 'little'):08X}"
        for i in range(0, len(blob) - len(blob) % 4, 4)
    )
    tail = "".join(f"\n.byte 0x{c:02X}" for c in blob[len(blob) - len(blob) % 4 :])
    ET.write_text(t.replace(f'.incbin "{binp}"', words + tail))
for f in sorted((R / "asm/data").rglob("*.s")):
    L = f.read_text(errors="ignore").splitlines()
    nuns = unsymbolize_offset_tables(L)
    nfake = unsymbolize_fake_refs(L, f.name)
    stats["un-symbolized fake refs"] += nfake
    nuns += nfake
    stats["un-symbolized offset-table words"] += nuns
    L, nmerged = merge_split_words(L)
    nmerged += nuns
    stats["merged split words"] += nmerged
    objs, cur = [], []
    for i, l in enumerate(L):
        if re.match(r"\s*(dlabel|glabel)\s", l) and cur:
            objs.append(cur)
            cur = []
        cur.append(i)
    if cur:
        objs.append(cur)
    if "vutext" in f.name:
        objs = []  # VU microcode: never pointers
    changed = False
    for ob in objs:
        words = [(i, m) for i in ob if (m := WORD.match(L[i]))]
        # pointers spimdisasm printed as floats (they are denormals): .float -> raw value from the byte comment
        for i in ob:
            mf = FLOAT.match(L[i])
            if mf:
                v = int.from_bytes(bytes.fromhex(mf.group(2)), "little")
                if LO <= v < HI and v % 4 == 0:
                    L[i] = f"{mf.group(1)}.word 0x{v:08X}"
                    words.append((i, WORD.match(L[i])))
        if not words:
            continue
        vals = [int(m.group(3), 16) for _, m in words]
        nz = [v for v in vals if v]
        sjis = sum(
            0x8140 <= (v & 0xFFFF) <= 0x9FFC or 0xE040 <= (v & 0xFFFF) <= 0xEFFC
            for v in nz
        )
        if nz and (sum(shortpair(v) for v in nz) > len(nz) // 2 or sjis > len(nz) // 2):
            stats["skipped (halfword/SJIS table)"] += sum(
                LO <= v < HI and v % 4 == 0 for v in vals
            )
            continue
        for (i, m), v in zip(words, vals):
            if (
                not (LO <= v < HI and v % 4 == 0)
                or "offset-table" in L[i]
                or "/* raw */" in L[i]
            ):
                continue
            bs = v.to_bytes(4, "little")
            # looks like text? (real pointers often do too: 0x004E4A28 = "(JN") -> only skip if it
            # doesn't land on a known symbol / inside a known object
            if (
                all(c == 0 or 0x20 <= c < 0x7F for c in bs)
                and sum(c != 0 for c in bs) >= 2
                and not solid(v)
            ):
                stats["skipped (ASCII)"] += 1
                continue
            name = B.exact.get(v) or define(v)
            L[i] = f"{m.group(1)}{name}{m.group(4)}"
            changed = True
            stats["symbolized"] += 1
    for l in L:
        for v in re.findall(r"\.word\s+P_([0-9A-F]{8})\b", l):
            define(int(v, 16))
    if changed or nmerged:
        f.write_text("\n".join(L) + "\n")
(R / "config/US/data_ptrs_shiftable.txt").write_text(
    "\n".join(sorted(defs.values())) + "\n"
)
print(dict(stats), f"{len(defs)} P_ symbols defined")
