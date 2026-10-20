#!/usr/bin/env python3
"""Sanity check for match_versions.py output: within a retail file, matches should keep order."""

import csv
import collections
from pathlib import Path

D = Path.home() / "tmbo_decomp/reference/match"
rows = [r for r in csv.DictReader(open(D / "mapping.csv")) if r["retail_name"]]
byfile = collections.defaultdict(list)
for r in rows:
    byfile[r["retail_file"]].append(
        (int(r["retail_addr"], 16), int(r["online_addr"], 16), r["method"])
    )
bad, tot = collections.Counter(), collections.Counter()
for lst in byfile.values():
    lst.sort()
    rank = {o: i for i, o in enumerate(sorted(o for _, o, _ in lst))}
    for i, (_, oa, m) in enumerate(lst):
        tot[m] += 1
        bad[m] += abs(rank[oa] - i) > 1
print("method            total  out-of-order")
for m in sorted(tot, key=lambda k: -tot[k]):
    print(f"{m:16s} {tot[m]:6d} {bad[m]:6d} ({100 * bad[m] / tot[m]:.1f}%)")
print("\nkey gameplay files:")
for r in csv.DictReader(open(D / "retail_files.csv")):
    if (
        r["retail_file"].split("/")[-1]
        in "vehicle weap collis texm game ui shell launch sound hud boss pickup destruct mathf".split()
    ):
        print(
            f"  {r['retail_file']:20s} {r['found_in_online']:>4}/{r['functions']:<4} fn  {r['pct_bytes']:>5}% bytes"
        )
