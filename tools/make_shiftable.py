#!/usr/bin/env python3
"""
make_shiftable.py NM_OF_MATCHING_ELF : rewrite splat's absolute auto symbols that point INSIDE the program
image (0x100000 .. end of bss) as offsets from the nearest real symbol, so they move with the code/data
when a function changes size. Hardware/scratchpad addresses stay absolute.
Writes config/US/undefined_syms_shiftable.txt (use instead of undefined_syms_auto.txt + undefined_funcs.txt).
"""
import re, sys, bisect
from pathlib import Path
R = Path.home() / "tmbo_decomp"
nm = [l.split() for l in open(sys.argv[1]) if len(l.split()) == 3]
real = sorted((int(a, 16), n) for a, t, n in nm if t not in "Aa" and not n.startswith((".", "$")))
addrs = [a for a, _ in real]
lo, hi = 0x100000, max(int(a, 16) for a, t, n in nm if n == "main_VRAM_END") if any(n == "main_VRAM_END" for _, _, n in nm) else 0x625694
out, moved = [], 0
for f in ("undefined_syms_auto.txt", "undefined_funcs.txt"):
    for l in (R / "config/US" / f).read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", l)
        if not m: out.append(l); continue
        name, v = m.group(1), int(m.group(2), 16)
        if lo <= v < hi:
            i = bisect.bisect_right(addrs, v) - 1
            while i >= 0 and real[i][1] == name: i -= 1
            base_a, base_n = real[i]
            out.append(f"{name} = {base_n} + 0x{v - base_a:X};"); moved += 1
        else:
            out.append(l)
(R / "config/US/undefined_syms_shiftable.txt").write_text("\n".join(out) + "\n")
print(f"{moved} in-image absolute symbols made relative; image range {lo:#x}-{hi:#x}")
