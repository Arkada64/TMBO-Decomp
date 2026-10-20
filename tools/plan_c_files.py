#!/usr/bin/env python3
"""
Plan which asm text segments can become C files for automatic matching.
Eligible = SN-compiled game code (register saves use `sq`; Sony libs use `sd`) AND its .rodata is a
clean contiguous block referenced only by that file (or it uses no .rodata).
Writes reference/wip/c_plan.json: [{name, off, end, ro_start, ro_end}] (ro_* None when no rodata).
"""
import re, json, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
Y = (R / "config/US/SCUS_971.96.yaml").read_text()
RO_LO, RO_HI = 0x004DEE00, 0x004F949C
segs = [(int(m.group(1), 16) + 0x100000, m.group(2), m.group(3))
        for m in re.finditer(r"^\s*- \[0x([0-9A-F]+), (asm|c), (\S+)\]", Y, re.M)]
text_end = 0x2AC080
segs = [(o, k, n, (segs[i + 1][0] if i + 1 < len(segs) else text_end)) for i, (o, k, n) in enumerate(segs)]

# every rodata symbol and who references it
ro_syms = set()
for f in R.glob("asm/**/*.s"):
    for m in re.finditer(r"^\s*dlabel ((?:D|jtbl)_([0-9A-F]{8}))", f.read_text(), re.M):
        a = int(m.group(2), 16)
        if RO_LO <= a < RO_HI: ro_syms.add(a)
ro_sorted = sorted(ro_syms)
users = collections.defaultdict(set)
for f in R.glob("asm/**/*.s"):
    if "/data/" in str(f): continue
    for m in re.finditer(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/[^\n]*?\b(?:D|jtbl)_([0-9A-F]{8})", f.read_text()):
        s = int(m.group(2), 16)
        if RO_LO <= s < RO_HI: users[s].add(int(m.group(1), 16))

def owner(addr):
    for o, k, n, e in segs:
        if o <= addr < e: return n
plan, why = [], collections.Counter()
for o, k, n, e in segs:
    if k != "asm": continue
    if n.startswith(("sdk/", "gcc/", "newlib/")): why["library path"] += 1; continue
    t = (R / f"asm/{n}.s").read_text() if (R / f"asm/{n}.s").exists() else ""
    sq, sd = len(re.findall(r"\bsq\s+\$(?:31|ra),", t)), len(re.findall(r"\bsd\s+\$(?:31|ra),", t))
    if sq <= sd: why["not SN-compiled (Sony lib)"] += 1; continue
    mine = sorted(s for s, us in users.items() if any(o <= u < e for u in us))
    if not mine:
        plan.append(dict(name=n, off=o, end=e, ro_start=None, ro_end=None)); why["ok, no rodata"] += 1; continue
    if any(owner(u) != n for s in mine for u in users[s]): why["rodata shared with other files"] += 1; continue
    i0, i1 = ro_sorted.index(mine[0]), ro_sorted.index(mine[-1])
    span = ro_sorted[i0:i1 + 1]
    if any(s not in mine and users.get(s) for s in span): why["rodata interleaved with others"] += 1; continue
    ro_end = ro_sorted[i1 + 1] if i1 + 1 < len(ro_sorted) else RO_HI
    plan.append(dict(name=n, off=o, end=e, ro_start=mine[0], ro_end=ro_end)); why["ok, own rodata"] += 1
(R / "reference/wip/c_plan.json").write_text(json.dumps(plan, indent=0))
print(dict(why))
fn = sum(len(re.findall(r"^\s*glabel ", (R / f"asm/{p['name']}.s").read_text(), re.M)) for p in plan)
print(f"eligible files: {len(plan)}, functions in them: {fn}, code: {sum(p['end'] - p['off'] for p in plan) // 1024} KB")
