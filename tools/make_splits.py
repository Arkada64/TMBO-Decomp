#!/usr/bin/env python3
"""Turn reference/match/online_files.csv into .text subsegments in the Online splat yaml."""
import csv, re, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
YAML = R / "config/US/SCUS_971.96.yaml"
rows = sorted(csv.DictReader(open(R / "reference/match/online_files.csv")), key=lambda r: int(r["online_addr"], 16))
rows = [r for r in rows if int(r["online_addr"], 16) >= 0x1000C0]

runs = []   # [start_addr, file, nfuncs]
for r in rows:
    a, f = int(r["online_addr"], 16), r["file"]
    # a real object-file boundary is 8-aligned (EE-GCC); a 4-aligned one can't start a file
    if runs and (runs[-1][1] == f or a % 8): runs[-1][2] += 1
    else: runs.append([a, f, 1])

# a file appearing in several separate runs gets _2, _3 ... (splat needs unique names)
seen = collections.Counter(); segs = []
for a, f, n in runs:
    seen[f] += 1
    name = f if seen[f] == 1 else f"{f}_part{seen[f]}"
    segs.append((a - 0x100000, name, n))
frag = [s for s in segs if re.search(r"_part\d+$", s[1]) and not s[1].startswith("online/")]
print(f"{len(segs)} text subsegments; {sum(1 for s in segs if s[1].startswith('online/'))} new-code regions; "
      f"{len(frag)} retail files split into extra pieces")
for s in frag[:15]: print(f"   piece: 0x{s[0]:06X} {s[1]} ({s[2]} funcs)")

text = YAML.read_text()
block = "\n".join(f"      - [0x{off:06X}, asm, {name}]" for off, name, _ in segs)
new, k = re.subn(r"      - \[0x00C0, asm, text\]\n", block + "\n", text)
assert k == 1, "text placeholder not found"
YAML.write_text(new)
print("yaml updated")
