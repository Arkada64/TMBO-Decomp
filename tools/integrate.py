#!/usr/bin/env python3
"""
RETAIL: put standalone matches (logs/drafts/X.match.c) into the real build for a segment that is
already a `c` segment with INCLUDE_ASM lines (see convert.sh). Tries all matches at once; if the
ROM's sha1 is wrong, bisects. Keeps only what gives a byte-identical ROM.
Usage: integrate.py X [MATCHFILE]      (X = segment name under tmb/, e.g. timer)
"""
import re, subprocess, sys, hashlib
from pathlib import Path
R = Path.home() / "tmb_decomp"
SHA1 = re.search(r"^sha1: (\w+)", (R / "config/US/SCUS_971.01.yaml").read_text(), re.M).group(1)
seg = sys.argv[1]
src = R / f"src/tmb/{seg}.c"
mf = Path(sys.argv[2]) if len(sys.argv) > 2 else R / f"logs/drafts/{seg}.match.c"
blocks = re.split(r"^//@@ (\S+)[^\n]*\n", mf.read_text(), flags=re.M)[1:]
matches = {n: c.replace('#include "m2c_macros.h"\n', "").strip() for n, c in zip(blocks[0::2], blocks[1::2])}
base = src.read_text()
present = set(re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', base, re.M))
cands = [n for n in matches if n in present]

def render(names):
    t = base
    if names and '#include "m2c_macros.h"' not in t:
        t = t.replace('#include "common.h"\n', '#include "common.h"\n#include "m2c_macros.h"\n', 1)
    for n in names:
        t = re.sub(rf'^INCLUDE_ASM\("[^"]*", {re.escape(n)}\);$', lambda m: matches[n], t, count=1, flags=re.M)
    return t

def ok(names):
    src.write_text(render(names))
    rom = R / "build/SCUS_971.01.rom"; rom.unlink(missing_ok=True)
    r = subprocess.run("ninja > logs/ninja.log 2>&1", shell=True, cwd=R)
    return r.returncode == 0 and rom.exists() and hashlib.sha1(rom.read_bytes()).hexdigest() == SHA1

def solve(names):
    """largest set found by bisection whose combination still builds byte-identical"""
    if not names: return []
    if ok(names): return names
    if len(names) == 1: return []
    h = len(names) // 2
    a = solve(names[:h])
    return a + solve_with(a, names[h:])

def solve_with(kept, names):
    if not names: return []
    if ok(kept + names): return names
    if len(names) == 1: return []
    h = len(names) // 2
    a = solve_with(kept, names[:h])
    return a + solve_with(kept + a, names[h:])

if not ok([]):
    print("baseline does NOT build byte-identical; fix that first (see logs/ninja.log)"); sys.exit(1)
kept = solve(cands)
src.write_text(render(kept))
final = ok(kept)
print(f"{seg}: {len(kept)}/{len(cands)} matches kept; byte-identical: {final}")
if not final: src.write_text(base); ok([]); sys.exit(1)
