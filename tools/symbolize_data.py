#!/usr/bin/env python3
"""
symbolize_data.py NM_OF_MATCHING_ELF : turn raw in-image pointers in asm/data/*.s into symbol references so
they move in a shifted build. `.word 0x004DF2B8` -> `.word P_004DF2B8`, with P_004DF2B8 defined relative to
the nearest real symbol (config/US/data_ptrs_shiftable.txt). Bytes are unchanged in a normal link.
Skips objects that look like tables of 16-bit pairs (any word in them is clearly two small shorts).
Idempotent; reports what it changed.
"""
import re, sys, bisect, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
nm = [l.split() for l in open(sys.argv[1]) if len(l.split()) == 3]
real = sorted((int(a, 16), n) for a, t, n in nm if t.isupper() and t != "A" and re.fullmatch(r"[A-Za-z_]\w*", n)
              and not n.startswith("P_"))
addrs = [a for a, _ in real]
by_addr = {}
for a, n in real: by_addr.setdefault(a, n)
LO, HI = 0x100000, 0x625694 + 0x40000
WORD = re.compile(r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s*\.word\s+)(0x[0-9A-Fa-f]+)\b(.*)$")
def shortpair(v):
    hi, lo = v >> 16, v & 0xFFFF
    return hi < 0x10 or (hi < 0x400 and not (LO >> 16) <= hi <= (HI >> 16))
defs, stats = {}, collections.Counter()
for f in sorted((R / "asm/data").rglob("*.s")):
    L = f.read_text(errors="ignore").splitlines()
    # split into objects at dlabel/glabel lines
    objs, cur = [], []
    for i, l in enumerate(L):
        if re.match(r"\s*(dlabel|glabel)\s", l) and cur: objs.append(cur); cur = []
        cur.append(i)
    if cur: objs.append(cur)
    changed = False
    for ob in objs:
        words = [(i, WORD.match(L[i])) for i in ob]
        words = [(i, m) for i, m in words if m]
        if not words: continue
        vals = [int(m.group(3), 16) for _, m in words]
        if any(v and shortpair(v) for v in vals):          # halfword table: leave alone
            stats["skipped (halfword table)"] += sum(LO <= v < HI and v % 4 == 0 for v in vals); continue
        for (i, m), v in zip(words, vals):
            if not (LO <= v < HI and v % 4 == 0): continue
            name = by_addr.get(v)
            if name is None:
                name = f"P_{v:08X}"
                k = bisect.bisect_right(addrs, v) - 1
                defs[name] = f"{name} = {real[k][1]} + 0x{v - real[k][0]:X};"
            L[i] = f"{m.group(1)}{name}{m.group(4)}"; changed = True; stats["symbolized"] += 1
    for l in L:                                            # pointers symbolized by an earlier run
        for v in re.findall(r"\.word\s+P_([0-9A-F]{8})\b", l):
            v = int(v, 16); name = f"P_{v:08X}"
            if name not in defs:
                k = bisect.bisect_right(addrs, v) - 1
                defs[name] = f"{name} = {real[k][1]} + 0x{v - real[k][0]:X};"
    if changed: f.write_text("\n".join(L) + "\n")
(R / "config/US/data_ptrs_shiftable.txt").write_text("\n".join(sorted(defs.values())) + "\n")
print(dict(stats), f"{len(defs)} new P_ symbols")
