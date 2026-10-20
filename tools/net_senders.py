#!/usr/bin/env python3
"""Find every DME message send site: which function, which message type, which event id (for events)."""
import re, csv, collections
from pathlib import Path
R = Path.home() / "tmbo_decomp"
MSG = {"D_004F9D84": "#0 gameEvent", "D_004F9D88": "#1 session", "D_004F9D90": "#2 worldEvent",
       "D_004F9D94": "#3 playerInfo", "D_004F9D98": "#4 roster", "D_004F9D80": "#5 chat"}
SEND = "func_00171DD0|func_00171E68|func_00171C90"
WRAP = {"func_00171DD0": "#0 gameEvent (to one)", "func_00171E68": "#0 gameEvent (broadcast)",
        "func_00171C90": "#1 session"}
names = {}
for r in csv.DictReader(open(R / "reference/match/mapping.csv")):
    if r["retail_name"]: names[r["online_addr"]] = re.sub(r"__.*", "", r["retail_name"])
asm = (R / "asm/text.s").read_text()
funcs = re.findall(r"nonmatching (\S+), 0x[0-9A-F]+\n(.*?)endlabel \1\n", asm, re.S)
by_msg = collections.defaultdict(list)
for fn, body in funcs:
    ins = [m.group(1) for m in re.finditer(r"/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(.*)", body)]
    for k, x in enumerate(ins):
        w = re.match(rf"jal\s+({SEND})\b", x)
        if not w or fn in WRAP: continue
        msg = WRAP[w.group(1)]
        window = ins[max(0, k - 40):k + 2]
        lo, hi = (20, 60) if "gameEvent" in msg else (1, 19)
        ev = sorted({int(c, 0) for y in window for c in re.findall(r"addiu\s+\$\w+,\s*\$zero,\s*(0x[0-9A-F]+|\d+)$", y)
                     if lo <= int(c, 0) <= hi})
        addr = "0x" + fn[5:] if fn.startswith("func_") else fn
        label = names.get(addr, fn) if fn.startswith("func_") else re.sub(r"__.*", "", fn)
        by_msg[msg].append((label, fn, ev))
for msg in sorted(by_msg):
    print(f"\n{msg}: {len(by_msg[msg])} send sites")
    for label, fn, ev in by_msg[msg]:
        print(f"   {label:40s} {fn if label != fn else '':16s} event-ids-nearby={ev if ev else '-'}")
