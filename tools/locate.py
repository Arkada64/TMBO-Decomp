#!/usr/bin/env python3
"""
Assign every Online function to a source file using matched neighbours.
  - matched function            -> its retail file
  - unmatched, same file both sides -> that file (new/edited function inside a retail file)
  - unmatched run between different files / no neighbours -> 'online/<region>' (new code)
Writes reference/match/online_files.csv: addr,size,name,file,how
Usage: locate.py [ADDR ...]   (print the file for specific addresses)
"""
import csv, sys, re
from pathlib import Path
R = Path.home() / "tmbo_decomp"
rows = list(csv.DictReader(open(R / "reference/match/mapping.csv")))
rows.sort(key=lambda r: int(r["online_addr"], 16))
n = len(rows)
prev_file = [None] * n; next_file = [None] * n
last = None
for i, r in enumerate(rows):
    prev_file[i] = last
    if r["retail_file"]: last = r["retail_file"]
last = None
for i in range(n - 1, -1, -1):
    next_file[i] = last
    if rows[i]["retail_file"]: last = rows[i]["retail_file"]
out = []
for i, r in enumerate(rows):
    if r["retail_file"]:
        f, how = r["retail_file"], "matched"
    elif prev_file[i] and prev_file[i] == next_file[i]:
        f, how = prev_file[i], "inside"
    else:
        f, how = None, "new"
    out.append([r["online_addr"], r["online_size"], re.sub(r"__.*", "", r["retail_name"]) or "", f, how])
# name contiguous 'new' runs after the file before them, so they get stable, readable groups
run_id = 0
for i, o in enumerate(out):
    if o[3] is None:
        if i == 0 or out[i - 1][4] != "new":
            run_id += 1
            label = f"online/after_{(prev_file[i] or 'start').split('/')[-1]}_{run_id:02d}"
        o[3] = label
with open(R / "reference/match/online_files.csv", "w", newline="") as fh:
    w = csv.writer(fh); w.writerow(["online_addr", "online_size", "name", "file", "how"]); w.writerows(out)
if len(sys.argv) > 1:
    idx = {o[0].upper(): o for o in out}
    for a in sys.argv[1:]:
        o = idx.get("0X" + a.upper().removeprefix("0X").zfill(8))
        print(f"{a}: {o[3]} ({o[4]}) {o[2]}" if o else f"{a}: ?")
else:
    import collections
    c = collections.Counter(o[4] for o in out); print(c)
    newruns = collections.Counter(o[3] for o in out if o[4] == "new")
    print(f"{len(newruns)} new-code regions; largest:")
    for k, v in newruns.most_common(12):
        sz = sum(int(o[1], 16) for o in out if o[3] == k)
        print(f"   {k:45s} {v:4d} funcs {sz // 1024:4d} KB")
