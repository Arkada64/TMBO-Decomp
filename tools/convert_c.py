#!/usr/bin/env python3
"""
Turn eligible asm text segments (reference/wip/c_plan.json) into C files, keeping the build byte-identical.
Tries files in groups; a group that breaks the build is split in half until each bad file is isolated.
Usage: convert_c.py [group_size]
"""
import json, re, subprocess, sys, time
from pathlib import Path
R = Path.home() / "tmbo_decomp"; YP = R / "config/US/SCUS_971.96.yaml"
BASE = YP.read_text()
plan = json.loads((R / "reference/wip/c_plan.json").read_text())
G = int(sys.argv[1]) if len(sys.argv) > 1 else 32

def yaml_for(entries):
    y = BASE
    for p in entries:
        y, k = re.subn(rf"^(\s*- \[0x{p['off'] - 0x100000:06X}), asm, {re.escape(p['name'])}\]$", r"\1, c, " + p["name"] + "]", y, flags=re.M)
        assert k == 1, p["name"]
    ro = [p for p in entries if p["ro_start"]]
    if ro:
        m = re.search(r"((?:^      - \[0x[0-9A-F]+, \.?rodata(?:, \S+)?\]\n)+)", y, re.M)
        cur = [(int(a, 16), b) for a, b in re.findall(r"- \[0x([0-9A-F]+), (\.?rodata(?:, \S+)?)\]", m.group(1))]
        ends = {}
        for p in ro:
            cur.append((p["ro_start"] - 0x100000, f".rodata, {p['name']}"))
            ends[p["ro_end"] - 0x100000] = True
        named = {o for o, b in cur if b != "rodata"}
        for e in ends:
            if e not in named: cur.append((e, "rodata"))
        cur = sorted(set(cur))
        out, last = [], None
        for o, b in cur:
            if b == "rodata" and (o in named or last == "rodata"): continue
            out.append(f"      - [0x{o:06X}, {b}]"); last = b
        y = y[:m.start(1)] + "\n".join(out) + "\n" + y[m.end(1):]
    return y

def build(entries):
    YP.write_text(yaml_for(entries))
    subprocess.run("./configure.py distclean >/dev/null 2>&1; ./configure.py generate > logs/gen.log 2>&1", shell=True, cwd=R)
    (R / "build/SCUS_971.96.rom").unlink(missing_ok=True)
    ok = subprocess.run("ninja > logs/ninja.log 2>&1", shell=True, cwd=R).returncode == 0
    return ok and (R / "disks/SCUS_971.96.rom").read_bytes() == (R / "build/SCUS_971.96.rom").read_bytes()

accepted, rejected, t0 = [], [], time.time()
def attempt(group):
    if build(accepted + group):
        accepted.extend(group); print(f"  +{len(group)} ok  (total {len(accepted)}, {time.time() - t0:.0f}s)", flush=True); return
    if len(group) == 1:
        rejected.append(group[0]["name"]); print(f"  x {group[0]['name']}", flush=True); return
    attempt(group[:len(group) // 2]); attempt(group[len(group) // 2:])
for i in range(0, len(plan), G):
    attempt(plan[i:i + G])
final = build(accepted)
for n in rejected:
    (R / f"src/{n}.c").unlink(missing_ok=True)
print(f"\nconverted {len(accepted)} files, rejected {len(rejected)}: {rejected}\nfinal build byte-identical: {final}")
