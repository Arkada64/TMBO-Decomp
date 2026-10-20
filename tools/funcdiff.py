#!/usr/bin/env python3
"""
Compare decompiled functions against the original, byte for byte.
Usage: funcdiff.py NAME [NAME ...]   (run after ninja; reads asm/nonmatchings for address/size)
"""
import re, sys, subprocess, tempfile
from pathlib import Path
R = Path.home() / "tmbo_decomp"
orig = (R / "disks/SCUS_971.96.rom").read_bytes()
built = (R / "build/SCUS_971.96.rom").read_bytes()

def info(name):
    f = next((R / "asm/nonmatchings").rglob(f"{name}.s"), None)
    t = f.read_text()
    size = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    addr = int(re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", t).group(1), 16)
    return addr, size

def dis(buf, addr):
    with tempfile.NamedTemporaryFile(suffix=".bin") as tf:
        tf.write(buf); tf.flush()
        out = subprocess.run(["mips-linux-gnu-objdump", "-D", "-b", "binary", "-mmips:5900", "-EL",
                              f"--adjust-vma=0x{addr:X}", tf.name], capture_output=True, text=True).stdout
    return [l.split("\t", 2)[-1].strip() for l in out.splitlines() if re.match(r"\s+[0-9a-f]+:\t", l)]

ok = True
for name in sys.argv[1:]:
    addr, size = info(name)
    o, b = orig[addr - 0x100000:][:size], built[addr - 0x100000:][:size]
    if o == b:
        print(f"MATCH     {name} (0x{addr:08X}, {size} bytes)"); continue
    ok = False
    print(f"DIFFERENT {name} (0x{addr:08X}, {size} bytes)")
    do, db = dis(o, addr), dis(b, addr)
    for i, (x, y) in enumerate(zip(do, db)):
        mark = "  " if x == y else ">>"
        print(f"  {mark} {addr + 4 * i:08X}  {x:40s} | {y}")
sys.exit(0 if ok else 1)
