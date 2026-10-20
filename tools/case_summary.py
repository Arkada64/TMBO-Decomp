#!/usr/bin/env python3
"""Summarize each `case N:` of the outermost switch in an m2c output: calls, globals, strings."""
import re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from strrefs import Img
R = Path.home() / "tmbo_decomp"
img = Img(R / "disks/SCUS_971.96")
fn = sys.argv[1]
lines = (R / f"reference/m2c/{fn}.c").read_text().splitlines()

# outermost switch = first "switch (" line; its cases sit at that indent + 4
sw = next(i for i, l in enumerate(lines) if re.match(r"\s*switch \(", l))
ind = len(lines[sw]) - len(lines[sw].lstrip())
print(lines[sw].strip())
cases, cur = {}, None
for l in lines[sw + 1:]:
    li = len(l) - len(l.lstrip())
    if li <= ind and l.strip() == "}": break
    m = re.match(r"\s*case (-?(?:0x)?[0-9A-Fa-f]+):", l)
    if m and li == ind + 4:
        cur = int(m.group(1), 0); cases.setdefault(cur, []); continue
    if re.match(r"\s*default:", l) and li == ind + 4: cur = "default"; cases.setdefault(cur, []); continue
    if cur is not None: cases[cur].append(l)
for k in sorted(cases, key=lambda x: (isinstance(x, str), x)):
    body = "\n".join(cases[k])
    calls = list(dict.fromkeys(re.findall(r"\b((?:func_[0-9A-F]{8})|[A-Za-z_]\w*__\w+)\(", body)))
    strs = [img.cstr(int(a, 16)) for a in re.findall(r"&D_([0-9A-F]{8})", body)]
    strs = [s.replace("\n", "\\n")[:70] for s in strs if s]
    short = [re.sub(r"__.*", "", c) for c in calls]
    print(f"case {k}: {', '.join(short[:7]) or '-'}" + (f"   strings: {strs[:2]}" if strs else ""))
