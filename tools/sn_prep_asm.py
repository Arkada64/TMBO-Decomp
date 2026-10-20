#!/usr/bin/env python3
"""
Prepare INCLUDE_ASM files for SN's assembler (used by tools/sn_cc.sh), in place on a temp copy:
  - %gp_rel(SYM)($gp) -> (SYM)   SN's as only understands the short gp-relative form
  - declare each such SYM small (.extern SYM, 4) so SN's as (run with -G8) keeps it gp-relative
    instead of expanding it to a lui/$at pair.
Usage: sn_prep_asm.py DIR
"""
import re, sys
from pathlib import Path
GP = re.compile(r"%gp_rel\(([^)]+)\)\(\$(?:gp|28)\)")
for f in Path(sys.argv[1]).glob("*.s"):
    t = f.read_text()
    syms = sorted(set(GP.findall(t)))
    if syms:
        t = "".join(f".extern {s}, 4\n" for s in syms) + GP.sub(r"(\1)", t)
        f.write_text(t)
