#!/usr/bin/env python3
"""test_pnach.py: write PCSX2 patch files for the BASE/SHIFT test ELFs (their CRCs differ from the disc),
carrying over the revival-server essentials (DNS, bugfixes, skip intros) with addresses translated
into the shifted build via the symbol tables."""
import struct, re, bisect
from pathlib import Path
R = Path.home() / "tmbo_decomp"; T = Path("/mnt/d/TMB Decomp/test")
SRC = Path("/mnt/d/TMBR/emulator/PCSX2/patches/SCUS-97196_C54E5CF2.pnach")
def crc(p):
    d = p.read_bytes(); d += b"\0" * (-len(d) % 4); c = 0
    for (w,) in struct.iter_unpack("<I", d): c ^= w
    return c
def syms(p):
    out = {}
    for l in open(p):
        s = l.split()
        if len(s) == 3 and s[1] not in "Aa": out[s[2]] = int(s[0], 16)
    return out
base, shift = syms(R / "logs/shift_nm_base.txt"), syms(R / "logs/shift_nm_shift2.txt")
order = sorted((a, n) for n, a in base.items() if n in shift)
addrs = [a for a, _ in order]
def tr(a):
    i = bisect.bisect_right(addrs, a) - 1
    a0, n = order[i]; return shift[n] + (a - a0)
want = ("Force Revival Server DNS", "Bugfixes & Improvements", "Skip Intros")
sections, cur = [], None
for l in SRC.read_text().splitlines():
    m = re.match(r"\[(.*)\]", l.strip())
    if m: cur = [m.group(1).strip(), []] if m.group(1).strip() in want else None; sections.append(cur) if cur else None; continue
    if cur is not None: cur[1].append(l)
for elf, f in (("BASE_TEST.ELF", lambda a: a), ("SHIFT_TEST.ELF", tr)):
    c = crc(T / elf); lines = [f"gametitle=TMB Online test build {elf} [{c:08X}]", ""]
    for name, body in sections:
        lines.append(f"[{name}]")
        for l in body:
            m = re.match(r"(patch=\d,EE,)([0-9A-Fa-f])([0-9A-Fa-f]{7})(,.*)", l)
            if m:
                a = f(int(m.group(3), 16)); l = f"{m.group(1)}{m.group(2)}{a:07X}{m.group(4)}"
            lines.append(l)
        lines.append("")
    out = T / f"{c:08X}.pnach"; out.write_text("\n".join(lines))
    print(elf, f"CRC {c:08X} ->", out.name)
