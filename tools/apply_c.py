#!/usr/bin/env python3
"""
Replace INCLUDE_ASM lines in a C file with decompiled functions.
Usage: apply_c.py SRC.c FUNCS.c [HEADER_INCLUDE]
FUNCS.c holds blocks introduced by '//@@ NAME' lines; each replaces INCLUDE_ASM(..., NAME);
"""
import re, sys
from pathlib import Path
src, funcs = Path(sys.argv[1]), Path(sys.argv[2]).read_text()
text = src.read_text()
if len(sys.argv) > 3 and sys.argv[3] not in text:
    text = text.replace('#include "common.h"', f'#include "{sys.argv[3]}"', 1)
blocks = re.split(r"^//@@ (\S+)\n", funcs, flags=re.M)[1:]
for name, body in zip(blocks[0::2], blocks[1::2]):
    pat = re.compile(rf'^INCLUDE_ASM\("[^"]*", {re.escape(name)}\);\n', re.M)
    text, n = pat.subn(lambda m: body.rstrip() + "\n", text)
    print(f"{name}: {'replaced' if n else 'NOT FOUND (already C?)'}")
src.write_text(text)
