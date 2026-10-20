#!/usr/bin/env python3
"""
Try C variants of functions with the Online compiler (SN ProDG 2.95.3-114 -O2 -G0) in isolation.
VARIANTS file: blocks start with '//@@ NAME LABEL'. Each block is compiled alone with the header.
Prints MATCH or a side-by-side diff (relocated fields masked) per variant.
Usage: try_variants.py VARIANTS.c [header]
"""
import re, struct, subprocess, sys, os
from pathlib import Path
R = Path.home() / "tmbo_decomp"
ROM = (R / "disks/SCUS_971.96.rom").read_bytes()
WORK = R / "logs/variants"; WORK.mkdir(parents=True, exist_ok=True)
os.system(f"rm -rf {WORK}/include && cp -r {R}/include {WORK}/include")
SN = "tools/compilers/ee-gcc2.95.3-114"
header = sys.argv[2] if len(sys.argv) > 2 else "online/net.h"
RMASK = {"R_MIPS_26": 0x03FFFFFF, "R_MIPS_HI16": 0xFFFF, "R_MIPS_LO16": 0xFFFF, "R_MIPS_GPREL16": 0xFFFF}

def orig(name):
    for line in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
        m = re.match(rf"\s*{re.escape(name)}\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", line)
        if m: a, s = int(m.group(1), 16), int(m.group(2), 16); return a, ROM[a - 0x100000:][:s]
    f = next((R / "asm").rglob(f"{name}.s"))
    t = f.read_text()
    s = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    a = int(re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", t).group(1), 16)
    return a, ROM[a - 0x100000:][:s]

def dis(words, addr):
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".bin") as tf:
        tf.write(b"".join(struct.pack("<I", w) for w in words)); tf.flush()
        out = subprocess.run(["mips-linux-gnu-objdump", "-D", "-b", "binary", "-mmips:5900", "-EL", "-M", "no-aliases",
                              f"--adjust-vma=0x{addr:X}", tf.name], capture_output=True, text=True).stdout
    return [l.split("\t", 2)[-1].strip() for l in out.splitlines() if re.match(r"\s+[0-9a-f]+:\t", l)]

blocks = re.split(r"^//@@ (\S+) ?(\S*)\n", Path(sys.argv[1]).read_text(), flags=re.M)[1:]
for name, label, code in zip(blocks[0::3], blocks[1::3], blocks[2::3]):
    (WORK / "v.c").write_text(f'#include "{header}"\n{code}')
    rel = os.path.relpath(R / SN, WORK)
    r = subprocess.run([f"{R / SN}/bin/ee-gcc.exe", f"-B{rel}/lib/gcc-lib/ee/2.95.3/", "-S", "-O2", "-G0",
                        "-Iinclude", "v.c", "-o", "v.s"], cwd=WORK, capture_output=True, text=True)
    if r.returncode: print(f"{name} [{label}] COMPILE FAILED: {r.stderr.strip()[-300:]}"); continue
    s = (WORK / "v.s").read_text()
    s = re.sub(r"^(\s+)move\s+(\$[0-9a-z]+),\s*(\$[0-9a-z]+)\s*$", r"\1daddu\t\2,\3,$0", s, flags=re.M)
    (WORK / "v.s").write_text(s)
    subprocess.run(["mips-linux-gnu-as", "-EL", "-march=5900", "-G0", "-no-pad-sections", "-mabi=eabi",
                    "v.s", "-o", "v.o"], cwd=WORK, check=True)
    nm = subprocess.run(["mips-linux-gnu-nm", "-S", "v.o"], cwd=WORK, capture_output=True, text=True).stdout
    sym = next((l.split() for l in nm.splitlines() if l.split()[-1] == name and len(l.split()) == 4), None)
    text = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", "v.o", "/dev/stdout"],
                          cwd=WORK, capture_output=True).stdout
    relocs = {}
    for l in subprocess.run(["mips-linux-gnu-readelf", "-rW", "v.o"], cwd=WORK, capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"\s*([0-9a-f]+)\s+[0-9a-f]+\s+(R_MIPS_\w+)", l)
        if m: relocs.setdefault(int(m.group(1), 16), RMASK.get(m.group(2), 0))
    off, size = int(sym[0], 16), int(sym[1], 16)
    addr, o = orig(name)
    mine = [struct.unpack_from("<I", text, off + i)[0] for i in range(0, size, 4)]
    theirs = [struct.unpack_from("<I", o, i)[0] for i in range(0, len(o), 4)]
    same = len(mine) == len(theirs) and all((a & ~relocs.get(off + 4 * i, 0)) == (b & ~relocs.get(off + 4 * i, 0))
                                            for i, (a, b) in enumerate(zip(mine, theirs)))
    if same: print(f"MATCH     {name} [{label}]"); continue
    print(f"DIFFERENT {name} [{label}]  size {size} vs {len(o)}")
    dm, do = dis(mine, addr), dis(theirs, addr)
    for i in range(max(len(dm), len(do))):
        a = do[i] if i < len(do) else ""; b = dm[i] if i < len(dm) else ""
        msk = ~relocs.get(off + 4 * i, 0)
        eq = i < len(mine) and i < len(theirs) and (mine[i] & msk) == (theirs[i] & msk)
        print(f"   {'  ' if eq else '>>'} {a:38s} | {b}")
