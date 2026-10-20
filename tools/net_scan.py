#!/usr/bin/env python3
"""Scan SCUS_971.96 for network message names, pointer tables naming them, and code using them."""
import re, struct, sys, collections
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from strrefs import Img

img = Img(Path.home() / "tmbo_decomp/disks/SCUS_971.96")
d = img.d

def vaddr(off):
    for lo, hi, o in img.secs:
        if o <= off < o + (hi - lo): return lo + off - o

# 1. every NET_-ish identifier string
names = {}
for m in re.finditer(rb"[\x20-\x7e]{4,}", d):
    s = m.group().decode()
    for tok in re.findall(r"\bNET_[A-Z0-9_]+\b", s):
        names.setdefault(tok, []).append((vaddr(m.start()), s[:90]))
print(f"== {len(names)} distinct NET_ identifiers")
for k in sorted(names): print(f"  {k:40s} {names[k][0][1]!r}")

# 2. pointer tables: runs of >=4 consecutive words pointing at strings
print("\n== pointer tables to identifier-like strings")
for lo, hi, off in img.secs:
    words = struct.unpack_from(f"<{(hi-lo)//4}I", d, off)
    run = []
    for i, w in enumerate(words + (0,)):
        s = img.cstr(w) if w else None
        if s and re.fullmatch(r"[A-Za-z_][A-Za-z0-9_ ]{2,40}", s):
            run.append((lo + 4 * i, s))
        else:
            if len(run) >= 4 and any("NET" in x or "Net" in x or "MSG" in x for _, x in run):
                print(f"  table @0x{run[0][0]:08X} ({len(run)} entries): " + ", ".join(x for _, x in run[:60]))
            run = []
