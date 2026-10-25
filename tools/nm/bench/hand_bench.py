#!/usr/bin/env python3
"""hand_bench.py HAND.c... : compile each //@@ block of hand-written C as <name>__c (as the bench drafts are) and link
them into cloud/bench/HAND.ELF against cloud/bench/BASE.ELF, for the bench to test before they go in."""
import os, re, shutil, subprocess, sys
R = "/home/ark/tmbo_decomp"; SN = "tools/compilers/ee-gcc2.95.3-114"; W = "/mnt/c/Users/Ark/Desktop/TMB Decomp"
CF = ["-O2", "-G0", "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "-isystem", "include/gcc/gcc-lib",
      "-isystem", "include/sdk", "-isystem", "include/sdk/common", "-isystem", "include/sdk/ee"]
out = "/home/ark/nmhome/hand_o"; shutil.rmtree(out, ignore_errors=True); os.makedirs(out)
for f in sys.argv[1:]:
    t = open(f).read()
    parts = re.split(r"^//@@ (\S+)[^\n]*\n", t, flags=re.M)[1:]
    for n, c in zip(parts[0::2], parts[1::2]):
        open(f"{R}/logs/nm/hb.c", "w").write(f'#include "common.h"\n#define {n} {n}__c\n{c}')
        r = subprocess.run([f"{R}/{SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", *CF, "logs/nm/hb.c",
                            "-o", f"{out}/{n}.o"], cwd=R, capture_output=True, text=True)
        print(n, "compiled" if r.returncode == 0 else "COMPILE ERROR:\n" + (r.stdout + r.stderr)[-1500:])
r = subprocess.run(["python3", f"{W}/cloud/in/bench_img.py", f"{W}/cloud/bench/BASE.ELF", out, f"{W}/cloud/bench/HAND.ELF"],
                   capture_output=True, text=True)
print(r.stdout + r.stderr)
