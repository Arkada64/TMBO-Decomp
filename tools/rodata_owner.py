#!/usr/bin/env python3
"""
Which .rodata belongs to a code range? Lists rodata symbols (D_/jtbl_) referenced from inside
[lo, hi) and from outside, so a file's contiguous rodata block can be cut cleanly.
Usage: rodata_owner.py LO HI   (VRAM, hex)
"""
import re, sys, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
RO_LO, RO_HI = 0x004DEE00, 0x004F949C
refs = collections.defaultdict(set)   # symbol addr -> {'in','out'}
for f in (R / "asm").rglob("*.s"):
    if "/data/" in str(f): continue
    for m in re.finditer(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/[^\n]*?\b(?:D|jtbl)_([0-9A-F]{8})", f.read_text()):
        a, s = int(m.group(1), 16), int(m.group(2), 16)
        if RO_LO <= s < RO_HI:
            refs[s].add("in" if lo <= a < hi else "out")
ins = sorted(s for s, w in refs.items() if "in" in w)
print(f"rodata symbols used by the range: {len(ins)}, span 0x{ins[0]:08X}..0x{ins[-1]:08X}")
shared = [s for s in ins if "out" in refs[s]]
print(f"  also used from outside: {len(shared)} {[hex(s) for s in shared[:10]]}")
inside_span = [s for s in refs if ins[0] <= s <= ins[-1]]
foreign = sorted(s for s in inside_span if "in" not in refs[s])
print(f"  symbols inside that span used only by other code: {len(foreign)} {[hex(s) for s in foreign[:10]]}")
# densest contiguous cluster of 'in' symbols (gaps > 0x400 split clusters)
clusters, cur = [], [ins[0]]
for s in ins[1:]:
    if s - cur[-1] > 0x400: clusters.append(cur); cur = [s]
    else: cur.append(s)
clusters.append(cur)
for c in clusters:
    print(f"  cluster 0x{c[0]:08X}..0x{c[-1]:08X}  ({len(c)} syms)")
