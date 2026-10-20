#!/usr/bin/env python3
"""
Try decompiled functions in the real build, one at a time; keep only byte-identical results.
FILE blocks: '//@@ NAME [label]' followed by C. Several blocks per NAME = variants, tried in order.
Usage: batch_try.py SRC.c FILE
"""
import re, subprocess, sys
from pathlib import Path
src, blocks = Path(sys.argv[1]), re.split(r"^//@@ (\S+)[^\n]*\n", Path(sys.argv[2]).read_text(), flags=re.M)[1:]
variants = {}
for name, code in zip(blocks[0::2], blocks[1::2]):
    variants.setdefault(name, []).append(code.rstrip() + "\n")

def build_matches():
    r = subprocess.run(["ninja"], capture_output=True, text=True)
    if r.returncode: return False, (r.stdout + r.stderr).strip().splitlines()[-1:]
    same = Path("disks/SCUS_971.96.rom").read_bytes() == Path("build/SCUS_971.96.rom").read_bytes()
    return same, []

kept, failed = [], []
for name, codes in variants.items():
    before = src.read_text()
    pat = re.compile(rf'^INCLUDE_ASM\("[^"]*", {re.escape(name)}\);\n', re.M)
    if not pat.search(before): print(f"{name}: not INCLUDE_ASM (already C?)"); continue
    ok = False
    for i, code in enumerate(codes):
        src.write_text(pat.sub(lambda m: code, before, count=1))
        ok, err = build_matches()
        print(f"{name} v{i + 1}: {'MATCH' if ok else 'no' + (' (' + err[0][:120] + ')' if err else '')}", flush=True)
        if ok: break
    if ok: kept.append(name)
    else: src.write_text(before); failed.append(name)
ok, _ = build_matches()
print(f"\nkept {len(kept)}: {kept}\nnot matched {len(failed)}: {failed}\nfinal build byte-identical: {ok}")
