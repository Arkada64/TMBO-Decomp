#!/usr/bin/env python3
"""
Syntax-check '//@@ NAME' blocks with the host gcc (no SN compiler needed) and tally error kinds.
Usage: syntax_check.py DRAFTS.c [header] [--show N]
"""
import re, subprocess, sys, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
header = "online/net.h"
show = int(sys.argv[sys.argv.index("--show") + 1]) if "--show" in sys.argv else 0
blocks = re.split(r"^//@@ (\S+)[^\n]*\n", Path(sys.argv[1]).read_text(), flags=re.M)[1:]
kinds, examples, bad = collections.Counter(), collections.defaultdict(list), []
for name, code in zip(blocks[0::2], blocks[1::2]):
    (R / "logs/syn.c").write_text(f'#include "{header}"\n{code}')
    r = subprocess.run(["gcc", "-fsyntax-only", "-std=gnu89", "-w", "-Wno-error", "-fno-builtin",
                        "-Wno-implicit-function-declaration", "-Wno-int-conversion", "-Wno-incompatible-pointer-types",
                        "-Iinclude", "-isystem", "include/gcc", "logs/syn.c"], cwd=R, capture_output=True, text=True)
    errs = [l for l in r.stderr.splitlines() if " error: " in l]
    if not errs: continue
    bad.append(name)
    k = re.sub(r"[‘'][^’']*[’']", "'X'", errs[0].split(" error: ", 1)[1])
    kinds[k] += 1
    if len(examples[k]) < 2: examples[k].append(f"{name}: {errs[0].split(' error: ', 1)[1]}")
print(f"{len(bad)} of {len(blocks) // 2} drafts have errors")
for k, n in kinds.most_common(12):
    print(f"{n:4d}  {k}")
    for e in examples[k][:show]: print(f"        e.g. {e}")
