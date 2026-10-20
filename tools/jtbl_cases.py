#!/usr/bin/env python3
"""For a function using a jump table, list each case index -> calls/strings in that case's code range."""
import re, sys, struct
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from strrefs import Img
R = Path.home() / "tmbo_decomp"
img = Img(R / "disks/SCUS_971.96")
fn = sys.argv[1]; base = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0   # base: value subtracted before indexing
asm = (R / "asm/text.s").read_text()
body = re.search(rf"nonmatching {fn},.*?endlabel {fn}\n", asm, re.S).group(0)
ins = []   # (addr, text)
for l in body.splitlines():
    m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(.*)", l)
    if m: ins.append((int(m.group(1), 16), m.group(2)))
end = ins[-1][0] + 4
names = {}
import csv
for r in csv.DictReader(open(R / "reference/match/mapping.csv")):
    if r["retail_name"]:
        sure = r["method"] in ("exact", "masked", "strings", "callgraph") or float(r["score"] or 0) >= 0.85
        names[int(r["online_addr"], 16)] = re.sub(r"__.*", "", r["retail_name"]) + ("" if sure else "?")
# every jump table: bound = nearest preceding sltiu, base = preceding addiu -N on same reg (if any)
tables = []
for k, (a, x) in enumerate(ins):
    m = re.search(r"%hi\(jtbl_([0-9A-F]{8})\)", x)
    if not m: continue
    n, b = 64, 0
    for _, y in reversed(ins[max(0, k - 8):k]):
        s = re.match(r"sltiu\s+\S+,\s*(\S+),\s*(0x[0-9A-F]+|\d+)", y)
        if s:
            n = int(s.group(2), 0); reg = s.group(1)
            for _, z in reversed(ins[max(0, k - 12):k]):
                d = re.match(rf"addiu\s+\{reg},\s*\S+,\s*(-0x[0-9A-F]+|-\d+)", z)
                if d: b = -int(d.group(1), 0); break
            break
    tables.append((a, int(m.group(1), 16), n, b))
all_starts = {a for a, _, _, _ in tables}
for _, jaddr, n, _ in tables:
    all_starts |= {t for t in (img.word(jaddr + 4 * i) for i in range(n)) if ins[0][0] <= t < end}
starts = sorted(all_starts)
for at, jaddr, n, base in tables:
  targets = [img.word(jaddr + 4 * i) for i in range(n)]
  print(f"\n{fn}: jump table @0x{jaddr:08X} (used at 0x{at:08X}), {n} entries, index = value - {base}")
  for i, t in enumerate(targets):
    if not (ins[0][0] <= t < end):
        print(f"  case {i + base:3d}: (default)"); continue
    nxt = next((s for s in starts if s > t), end)
    rng = [x for a, x in ins if t <= a < nxt]
    calls = []
    for x in rng:
        m = re.match(r"jal\s+(\S+)", x)
        if m:
            c = m.group(1)
            c = names.get(int(c[5:], 16), c) if c.startswith("func_") else re.sub(r"__.*", "", c)
            if c not in calls: calls.append(c)
    shared = " (shares code)" if targets.count(t) > 1 else ""
    print(f"  case {i + base:3d}: @0x{t:08X} {len(rng):3d} insns  {', '.join(calls[:6]) or '-'}{shared}")
