#!/usr/bin/env python3
"""callers.py REPO REGEX : for each function symbol matching REGEX, list its callers (jal) in that repo's asm.
Also lists symbols referenced only by address (function pointers / vtables: lui/addiu %hi/%lo)."""
import re, sys, collections
from pathlib import Path
repo, pat = Path(sys.argv[1]).expanduser(), re.compile(sys.argv[2])
calls, refs = collections.defaultdict(set), collections.defaultdict(set)
for f in (repo / "asm").rglob("*.s"):
    t = f.read_text(errors="ignore"); cur = f.stem
    for l in t.splitlines():
        m = re.match(r"\s*glabel (\w+)", l) or re.match(r"\s*\.?(?:glabel|.globl|nonmatching)\s+(\w+)", l)
        if m and not m.group(1).startswith("."): cur = m.group(1).rstrip(",")
        m = re.search(r"\bjal\s+(\w+)", l)
        if m: calls[m.group(1)].add(cur); continue
        m = re.search(r"%(?:hi|lo)\((\w+)\)", l)
        if m: refs[m.group(1)].add(cur)
# C files: calls in matched code
for f in (repo / "src").rglob("*.c*"):
    t = f.read_text(errors="ignore")
    for m in re.finditer(r"__asm__\(\"(\w+)\"\)", t): pass
    cur = None
    for l in t.splitlines():
        m = re.match(r"^[A-Za-z][^;=]*?\b(\w+)\([^;]*\)\s*\{?\s*$", l)
        if m and not l.startswith((" ", "\t")): cur = m.group(1)
        for c in re.findall(r"\b(\w+?)(?:_[0-9A-Za-z_]{6})?\(", l):
            if cur and c != cur: calls[c].add(cur + "(C)")
names = set()
for l in (repo / "config/US/symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);.*type:func", l)
    if m and pat.search(m.group(1)): names.add((int(m.group(2), 16), m.group(1)))
for a, n in sorted(names):
    c = sorted(calls.get(n, ())); r = sorted(refs.get(n, ()))
    print(f"{a:08X} {n}\n    called by: {', '.join(c) or '-'}" + (f"\n    address taken in: {', '.join(r)}" if r else ""))
