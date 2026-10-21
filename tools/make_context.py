#!/usr/bin/env python3
"""
RETAIL: m2c context of prototypes for every function in symbol_addrs.txt whose mangled name
decodes (gcc2_mangle.py). Return types are unknown, so they are `int` (m2c only uses v0 when read).
Usage: make_context.py [OUT]   (default logs/ctx/retail_protos.h)
"""
import re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from gcc2_mangle import params
R = Path.home() / "tmb_decomp"
out = Path(sys.argv[1]) if len(sys.argv) > 1 else R / "logs/ctx/retail_protos.h"
out.parent.mkdir(parents=True, exist_ok=True)
lines, n, bad = [], 0, 0
for l in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\S+)\s*=\s*0x[0-9A-Fa-f]+;.*type:func", l)
    if not m or "__" not in m.group(1): continue
    ps = params(m.group(1))
    if ps is None or (ps and ps[0] == "..."): bad += 1; continue
    lines.append(f"int {m.group(1)}({', '.join(ps) or 'void'});"); n += 1
out.write_text("\n".join(lines) + "\n")
print(f"{n} prototypes -> {out} ({bad} names not decodable)")
