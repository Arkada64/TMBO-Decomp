# ruff: noqa
"""Loops in one online asm function that step a register by 0x31B0: the calls inside each loop body."""
import re, sys, csv
R = "/home/ark/tmbo_decomp/"
names = {row["online_addr"][2:].upper().zfill(8): row["retail_name"] for row in csv.DictReader(open(R + "reference/match/mapping.csv")) if row["retail_name"]}
nice = lambda t: names.get(t[5:], t) if t.startswith("func_") else t
f, fn = sys.argv[1], sys.argv[2]
lines, on = [], False
for l in open(R + f, errors="replace"):
    if l.startswith("glabel "): on = l.split()[1] == fn
    if on: lines.append(l.rstrip())
ins = []
for l in lines:
    m = re.search(r"/\* \w+ (\w{8}) \w{8} \*/\s+(\S+)\s*(.*)", l)
    if m: ins.append((int(m.group(1), 16), m.group(2), m.group(3)))
    m2 = re.match(r"\s*(\.L[0-9A-F]+):", l)
    if m2: ins.append((None, "label", m2.group(1)))
lab = {}
for k, (a, op, arg) in enumerate(ins):
    if op == "label": lab[arg] = next(x[0] for x in ins[k:] if x[0] is not None)
for k, (a, op, arg) in enumerate(ins):
    if op.startswith("b") and op not in ("break",):
        t = re.search(r"(\.L[0-9A-F]+)", arg)
        if t and t.group(1) in lab and lab[t.group(1)] < a:          # backward branch = loop
            lo = lab[t.group(1)]
            body = [x for x in ins if x[0] is not None and lo <= x[0] <= a]
            if any("0x31B0" in x[2] for x in body):
                calls = [nice(x[2].split()[0]) for x in body if x[1] == "jal"]
                print(f"loop {hex(lo)}..{hex(a)} ({len(body)} insns): {', '.join(dict.fromkeys(calls))}")
