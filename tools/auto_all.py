#!/usr/bin/env python3
"""
Run automatic matching over every C file that still has INCLUDE_ASM functions.
Per file: m2c drafts -> fast check with SN -> apply matches -> real build must be byte-identical
(else one-at-a-time via batch_try) -> commit. Safe to stop and re-run; it resumes on what's left.
Usage: auto_all.py [only_path_substring]
"""
import re, subprocess, sys, time
from pathlib import Path
R = Path.home() / "tmbo_decomp"
OUT = R / "logs/auto"; OUT.mkdir(parents=True, exist_ok=True)
only = sys.argv[1] if len(sys.argv) > 1 else ""
sh = lambda c: subprocess.run(c, shell=True, cwd=R, capture_output=True, text=True)

def build_ok():
    (R / "build/SCUS_971.96.rom").unlink(missing_ok=True)
    if sh("ninja > logs/ninja.log 2>&1").returncode: return False
    return (R / "disks/SCUS_971.96.rom").read_bytes() == (R / "build/SCUS_971.96.rom").read_bytes()

files = sorted(p for p in (R / "src").rglob("*.c") if "INCLUDE_ASM" in p.read_text() and only in str(p))
total, t0 = 0, time.time()
assert build_ok(), "build must be byte-identical before starting"
for i, src in enumerate(files, 1):
    rel = src.relative_to(R); slug = str(rel).replace("/", "_")
    hdr = "online/net.h" if rel.as_posix() == "src/online/net.c" else "common.h"
    left = src.read_text().count("INCLUDE_ASM(")
    sh(f"python3 tools/auto_m2c.py {rel} {hdr} logs/auto/{slug}.drafts.c")
    sh(f"python3 tools/fast_match.py logs/auto/{slug}.drafts.c logs/auto/{slug}.matched.c {hdr}")
    m = OUT / f"{slug}.matched.c"
    cand = len(re.findall(r"^//@@ ", m.read_text(), re.M)) if m.exists() else 0
    kept = 0
    if cand:
        before = src.read_text()
        sh(f"python3 tools/apply_c.py {rel} logs/auto/{slug}.matched.c")
        if build_ok():
            kept = cand
        else:
            src.write_text(before)
            out = sh(f"python3 tools/batch_try.py {rel} logs/auto/{slug}.matched.c").stdout
            k = re.search(r"^kept (\d+)", out, re.M); kept = int(k.group(1)) if k else 0
            if not build_ok(): src.write_text(before); kept = 0; build_ok()
        if kept:
            sh(f'git add -A && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Auto-match {kept} functions in {rel}"')
    total += kept
    print(f"[{i}/{len(files)}] {rel}: {left} asm, {cand} candidates, {kept} kept  (total {total}, {time.time() - t0:.0f}s)", flush=True)
print(f"\nDONE: {total} functions matched across {len(files)} files; build byte-identical: {build_ok()}")
