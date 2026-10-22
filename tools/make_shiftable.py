#!/usr/bin/env python3
# ruff: noqa
"""
make_shiftable.py MATCHING_ELF : rewrite splat's absolute auto symbols that point INSIDE the program image
(0x100000 .. end of bss, inclusive) relative to the object they belong to (see symbase.py), so they move
with code/data when something changes size. Hardware/scratchpad addresses stay absolute.
Writes config/US/undefined_syms_shiftable.txt (use instead of undefined_syms_auto.txt + undefined_funcs.txt).
"""

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from symbase import Base

R = Path.home() / "tmbo_decomp"
B = Base(sys.argv[1])
lo, hi = 0x100000, 0x725694
out, moved = [], []
for f in ("undefined_syms_auto.txt", "undefined_funcs.txt"):
    for l in (R / "config/US" / f).read_text().splitlines():
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", l)
        if not m:
            out.append(l)
            continue
        name, v = m.group(1), int(m.group(2), 16)
        if lo <= v <= hi:
            # _crt0 loads $gp from D_005015F0: it must stay equal to the linker's _gp, or every
            # gp-relative access in the game is off by the shift
            e = (
                "_gp"
                if v == 0x5015F0
                else "main_VRAM_END"
                if v == hi
                else B.expr(v, avoid=name)
            )
            out.append(f"{name} = {e};")
            moved.append(f"{name} = {e}")
        else:
            out.append(l)
(R / "config/US/undefined_syms_shiftable.txt").write_text("\n".join(out) + "\n")
print(f"{len(moved)} in-image absolute symbols made relative")
print(*moved, sep="\n")
