#!/usr/bin/env python3
"""
Show original vs compiled (full SN toolchain) side by side for the first draft of each named function.
Usage: diff_draft.py DRAFTS.c NAME [NAME ...]
"""
import re, struct, subprocess, sys, tempfile, difflib
from pathlib import Path
R = Path.home() / "tmbo_decomp"
ROM = (R / "disks/SCUS_971.96.rom").read_bytes()
SN = "tools/compilers/ee-gcc2.95.3-114"
W = R / "logs/fast"; W.mkdir(parents=True, exist_ok=True)
blocks = re.split(r"^//@@ (\S+)[^\n]*\n", Path(sys.argv[1]).read_text(), flags=re.M)[1:]
first = {}
for n, c in zip(blocks[0::2], blocks[1::2]): first.setdefault(n, c)

def dis(b, vma):
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(b); f.flush()
        o = subprocess.run(["mips-linux-gnu-objdump", "-D", "-b", "binary", "-mmips:5900", "-EL", "-M", "no-aliases",
                            f"--adjust-vma={vma}", f.name], capture_output=True, text=True).stdout
    return [re.sub(r"0x[0-9a-f]+|-?\d+", "#", l.split("\t", 2)[-1].strip()) + "   " + l.split("\t", 2)[-1].strip()
            for l in o.splitlines() if re.match(r"\s+[0-9a-f]+:\t", l)]

for name in sys.argv[2:]:
    (W / "d.c").write_text(f'#include "online/net.h"\n{first[name]}')
    subprocess.run([f"{R / SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", "-O2", "-G0", "-Wa,-G8",
                    "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "logs/fast/d.c", "-o", "logs/fast/d.o"], cwd=R)
    nm = subprocess.run(["mips-linux-gnu-nm", "-S", "logs/fast/d.o"], cwd=R, capture_output=True, text=True).stdout
    off, size = next((int(p[0], 16), int(p[1], 16)) for p in (l.split() for l in nm.splitlines()) if len(p) == 4 and p[3] == name)
    text = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", "logs/fast/d.o", "/dev/stdout"],
                          cwd=R, capture_output=True).stdout
    t = next((R / "asm/nonmatchings").rglob(f"{name}.s")).read_text()
    a = int(re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", t).group(1), 16)
    s = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    o, m = dis(ROM[a - 0x100000:][:s], a), dis(text[off:off + size], a)
    print(f"===== {name}: original {s // 4} insns, ours {size // 4}   (- original only, + ours only)")
    for l in difflib.unified_diff([x.split("   ", 1)[0] for x in o], [x.split("   ", 1)[0] for x in m], lineterm="", n=1):
        if not l.startswith(("---", "+++")): print("   " + l)
