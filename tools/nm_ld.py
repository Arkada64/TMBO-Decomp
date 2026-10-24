#!/usr/bin/env python3
"""Shiftable NON_MATCHING link: keep every position-sensitive thing where the game expects it modulo 0x80.
The game reads some data out of .text with 128-bit loads and DMA-copies aligned buffers (a 0x28-byte text growth
gave full-screen green bars; a misaligned bss gave "NO CONTROLLER IN CONTROLLER PORT 1"). So:
  - each C object's .text keeps its original size when the C is smaller (padded), and grows only in whole
    0x80 steps when it is bigger;
  - the C float literals (.lit4/.lit8, gp-relative under the SN assembler's -G8) go after the game's .sdata,
    padded to a multiple of 0x80, so .sbss/.bss move by 0x80 steps only.
Original sizes come from the matching build's map.  Usage: nm_ld.py MAP LDSCRIPT"""
import re, sys
mp, ld = sys.argv[1], sys.argv[2]
orig = {}
for m in re.finditer(r"^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(build/src/\S+\.c\.o)", open(mp).read(), re.M):
    orig[m.group(3)] = int(m.group(2), 16)
out = []; n = 0
for l in open(ld).read().splitlines():
    m = re.match(r"^(\s*)(build/src/\S+\.c\.o)\(\.text\);$", l)
    if m and m.group(2) in orig:
        ind, o, sz = m.group(1), m.group(2), orig[m.group(2)]
        sym = "__nm_" + re.sub(r"\W", "_", o)
        out += [f"{ind}{sym} = .;", l,
                f"{ind}. = {sym} + ((. - {sym}) <= 0x{sz:X} ? 0x{sz:X} : 0x{sz:X} + ALIGN(. - {sym} - 0x{sz:X}, 0x80));"]
        n += 1; continue
    if re.match(r"^\s*build/asm/data/3F9600\.sdata\.s\.o\(\.sdata\);$", l):
        ind = re.match(r"^(\s*)", l).group(1)
        out += [l, f"{ind}__nm_lit = .;", f"{ind}*(.lit4);", f"{ind}*(.lit8);",
                f"{ind}. = __nm_lit + ALIGN(. - __nm_lit, 0x80);"]
        continue
    out.append(l)
open(ld, "w").write("\n".join(out) + "\n")
print(f"nm_ld: {n} C objects size-guarded, literals after .sdata")
