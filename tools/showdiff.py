#!/usr/bin/env python3
"""showdiff.py NAME... : compile logs/perm/NAME/base.c with SN, diff against target.o (objdump, relocs shown)."""
import subprocess, sys, re, difflib
from pathlib import Path
R = Path.home() / "tmbo_decomp"
def dis(o):
    t = subprocess.run(["mips-linux-gnu-objdump", "-d", "-r", "-z", "--section=.text", str(o)], capture_output=True, text=True).stdout
    out = []
    for l in t.split("\n"):
        m = re.match(r"\s+[0-9a-f]+:\s+[0-9a-f]{8}\s+(.*)", l)
        if m: out.append(re.sub(r"\s+", " ", m.group(1)).strip()); continue
        m = re.match(r"\s+[0-9a-f]+: (R_MIPS\S+)\s+(\S+)", l)
        if m and out: out[-1] += f"   <{m.group(1)[7:]} {m.group(2)}>"
    return out
for name in sys.argv[1:]:
    d = R / "logs/perm" / name
    src = sys.argv and (d / "try.c" if (d / "try.c").exists() else d / "base.c")
    o = Path("/tmp/showdiff.o")
    r = subprocess.run(["bash", str(d / "compile.sh"), str(src), "-o", str(o)], capture_output=True, text=True)
    if r.returncode or not o.exists(): print(f"== {name}: compile failed"); continue
    a, b = dis(d / "target.o"), dis(o)
    print(f"== {name} ({src.name}): target {len(a)} insns, ours {len(b)}")
    i = 0
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal": continue
        lo, hi = max(0, i1 - 2), min(len(a), i2 + 2)
        for k in range(lo, hi):
            print(("  T " if i1 <= k < i2 else "    ") + a[k])
        for k in range(j1, j2): print("  O " + b[k])
        print("  ..")
    o.unlink()
