#!/usr/bin/env python3
"""
Identify the compiler: compile draft functions with each candidate compiler/flag set and compare
against the original bytes, masking only fields the linker fills in (relocations).
Usage: compiler_matrix.py DRAFTS.c HEADER   (run from repo root)
"""
import re, struct, subprocess, sys, os, itertools
from pathlib import Path
R = Path.home() / "tmbo_decomp"
ROM = (R / "disks/SCUS_971.96.rom").read_bytes()
WORK = R / "logs/matrix"; WORK.mkdir(parents=True, exist_ok=True)
drafts, header = Path(sys.argv[1]).read_text(), sys.argv[2]
names = re.findall(r"^//@@ (\S+)", drafts, re.M)
(WORK / "t.c").write_text(f'#include "{header}"\n' + re.sub(r"^//@@ .*\n", "", drafts, flags=re.M))
os.system(f"rm -rf {WORK}/include && cp -r {R}/include {WORK}/include")

def orig_func(name):
    t = next((R / "asm").rglob(f"{name}.s")).read_text()
    size = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    addr = int(re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", t).group(1), 16)
    return ROM[addr - 0x100000:][:size]

C = R / "tools/compilers"
compilers = {
    "sce-2.9-991111 (retail)": [str(R / "tools/ee-gcc2.9/bin/ee-gcc")],
    "sce-2.96": [str(R / "tools/ee-gcc2.96/bin/ee-gcc")],
    "sce-3.2-030926": [str(C / "ee-gcc3.2-030926/bin/ee-gcc")],
    "sce-3.2-040921": [str(C / "ee-gcc3.2-040921/bin/ee-gcc")],
}
# SN ProDG (Windows): -B to their helper dir, given relative to WORK so the .exe can resolve it
for name, d, ver in [("sn-2.95.2-273a", "ee-gcc2.95.2-273a", "2.95.2"),
                     ("sn-2.95.3-107", "ps2_compilers/ee-gcc2.95.3-107", "2.95.3"),
                     ("sn-2.95.3-114", "ee-gcc2.95.3-114", "2.95.3"),
                     ("sn-2.95.3-136", "ee-gcc2.95.3-136", "2.95.3")]:
    compilers[name] = [str(C / d / "bin/ee-gcc.exe"), f"-B../../tools/compilers/{d}/lib/gcc-lib/ee/{ver}/"]
flagsets = ["-O2 -G0", "-O2 -G8", "-O1 -G0", "-O2 -G0 -fno-common"]
RMASK = {"R_MIPS_26": 0x03FFFFFF, "R_MIPS_HI16": 0xFFFF, "R_MIPS_LO16": 0xFFFF, "R_MIPS_GPREL16": 0xFFFF}

def compare(obj):
    syms = {}
    for l in subprocess.run(["mips-linux-gnu-nm", "-S", obj], capture_output=True, text=True).stdout.splitlines():
        p = l.split()
        if len(p) == 4 and p[2] in "Tt": syms[p[3]] = (int(p[0], 16), int(p[1], 16))
    text = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", obj, "/dev/stdout"], capture_output=True).stdout
    relocs = {}
    out = subprocess.run(["mips-linux-gnu-readelf", "-rW", obj], capture_output=True, text=True).stdout
    sec = None
    for l in out.splitlines():
        if l.startswith("Relocation section"): sec = ".rel.text" in l or ".rela.text" in l
        m = re.match(r"\s*([0-9a-f]+)\s+[0-9a-f]+\s+(R_MIPS_\w+)", l)
        if m and sec: relocs[int(m.group(1), 16)] = RMASK.get(m.group(2), 0)
    res = {}
    for n in names:
        if n not in syms: res[n] = "missing"; continue
        off, size = syms[n]; o = orig_func(n)
        if size != len(o): res[n] = f"size {size} vs {len(o)}"; continue
        bad = 0
        for i in range(0, size, 4):
            a, = struct.unpack_from("<I", text, off + i); b, = struct.unpack_from("<I", o, i)
            m = ~relocs.get(off + i, 0) & 0xFFFFFFFF
            bad += (a & m) != (b & m)
        res[n] = "MATCH" if bad == 0 else f"{bad} insns differ"
    return res

if os.environ.get("ONLY"):
    compilers = {k: v for k, v in compilers.items() if os.environ["ONLY"] in k}
for (cname, cmd), fl in itertools.product(compilers.items(), flagsets):
    obj = WORK / "t.o"; obj.unlink(missing_ok=True)
    # Windows .exe compilers get relative paths (they can't see Linux absolute paths)
    r = subprocess.run(cmd + ["-c", *fl.split(), "-Iinclude", "-x", "c", "t.c", "-o", "t.o"],
                       cwd=WORK, capture_output=True, text=True)
    if r.returncode or not obj.exists():
        print(f"{cname:24s} {fl:22s} COMPILE FAILED: {(r.stderr or r.stdout).strip().splitlines()[-1:]}")
        continue
    res = compare(str(obj))
    score = sum(v == "MATCH" for v in res.values())
    print(f"{cname:24s} {fl:22s} {score}/{len(names)}  " + "  ".join(f"{k}={v}" for k, v in res.items() if v != "MATCH"))
