#!/usr/bin/env python3
"""asmcmp.py ONLINE_FUNC RETAIL_FUNC : side-by-side normalized diff of the two builds' versions of a function."""
import re, sys, difflib
from pathlib import Path
def load(repo, name):
    p = next((Path(repo).expanduser() / "asm").rglob(f"{name}.s"), None)
    if p is None:
        # function inside a bigger asm file (retail keeps whole files): cut it out
        for f in (Path(repo).expanduser() / "asm").rglob("*.s"):
            t = f.read_text(errors="ignore")
            m = re.search(rf"glabel {re.escape(name)}\b(.*?)(?=\n\s*(?:glabel|endlabel|\.size)\s)", t, re.S)
            if m: return norm(m.group(1))
        return []
    return norm(p.read_text())
def norm(t):
    out = []
    for l in t.splitlines():
        m = re.match(r"\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+(.*)", l)
        if not m: continue
        ins = re.sub(r"\s+", " ", m.group(2)).strip()
        ins = re.sub(r"\b(D_|func_|jtbl_|\.L)[0-9A-F]{6,8}\w*", r"\1?", ins)
        out.append((m.group(1), ins))
    return out
a, b = load("~/tmbo_decomp", sys.argv[1]), load("~/tmb_decomp", sys.argv[2])
print(f"online {sys.argv[1]}: {len(a)} insns | retail {sys.argv[2]}: {len(b)} insns")
sm = difflib.SequenceMatcher(None, [x[1] for x in a], [x[1] for x in b], autojunk=False)
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == "equal":
        for k in range(i1, i2): print(f"   {a[k][0]}  {a[k][1]:48} | {b[j1 + k - i1][1]}")
    else:
        for k in range(max(i2 - i1, j2 - j1)):
            l = f"{a[i1 + k][0]}  {a[i1 + k][1]}" if i1 + k < i2 else ""
            r = b[j1 + k][1] if j1 + k < j2 else ""
            print(f"!! {l:58} | {r}")
