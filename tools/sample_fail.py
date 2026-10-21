#!/usr/bin/env python3
"""sample_fail.py [N]: classify why drafts of still-asm functions don't match (random sample)."""
import re, random, subprocess, sys, collections, os
from pathlib import Path
R = Path.home() / "tmbo_decomp"; W = R / "logs/sample"; W.mkdir(parents=True, exist_ok=True)
SN = "tools/compilers/ee-gcc2.95.3-114"
sys.argv += ["80"]; N = int(sys.argv[1])
pool = []
for src in sorted((R / "src").rglob("*.c")):
    names = set(re.findall(r'^INCLUDE_ASM\("[^"]*", (\S+)\);', src.read_text(), re.M))
    d = R / f"logs/auto/{str(src.relative_to(R)).replace('/', '_')}.drafts.c"
    if not names or not d.exists(): continue
    b = re.split(r"^//@@ (\S+)[^\n]*\n", d.read_text(), flags=re.M)[1:]
    seen = set()
    for n, c in zip(b[0::2], b[1::2]):
        if n in names and n not in seen:
            seen.add(n); pool.append((n, c, "online/net.h" if src.name == "net.c" and "online" in str(src) else "common.h"))
random.seed(1); pick = random.sample(pool, min(N, len(pool)))
cat, errs, feats, sizes = collections.Counter(), collections.Counter(), collections.Counter(), []
for n, c, hdr in pick:
    for k, pat in (("float", r"\bf32\b|f64"), ("M2C_FIELD", r"M2C_FIELD"), ("void* arith", r"\bvoid\*"),
                   ("goto", r"\bgoto\b"), ("switch", r"\bswitch\b"), ("M2C_UNK call", r"M2C_UNK \w+\(\)"),
                   ("struct copy", r"M2C_STRUCT_COPY"), ("sp buffer", r"u8 sp\[")):
        if re.search(pat, c): feats[k] += 1
    (W / "f.c").write_text(f'#include "{hdr}"\n{c}')
    r = subprocess.run([f"{R / SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", "-O2", "-G0", "-Wa,-G8",
                        "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", "logs/sample/f.c", "-o", "logs/sample/f.o"],
                       cwd=R, capture_output=True, text=True)
    if r.returncode:
        cat["compile error"] += 1
        ls = [l for l in r.stderr.splitlines() if re.match(r"^logs/sample/f\.c:\d+:", l) and "warning" not in l]
        e = ls[0] if ls else r.stderr.splitlines()[-1]
        e = re.sub(r"^.*?:\d+:\s*", "", e); e = re.sub(r"`\w+'", "`X'", e)
        errs[e[:70]] += 1
    else:
        nm = subprocess.run(["mips-linux-gnu-nm", "-S", str(W / "f.o")], capture_output=True, text=True).stdout
        sym = next((l.split() for l in nm.splitlines() if len(l.split()) == 4 and l.split()[3] == n), None)
        asm = next((R / "asm/nonmatchings").rglob(f"{n}.s"))
        s = int(re.search(rf"nonmatching {re.escape(n)}, (0x[0-9A-F]+)", asm.read_text()).group(1), 16)
        if not sym: cat["compiles, symbol missing"] += 1
        else:
            d = (int(sym[1], 16) - s) // 4
            cat["same size" if abs(d) <= 1 else ("ours bigger" if d > 0 else "ours smaller")] += 1
            if abs(d) > 1: sizes.append(d)
print("categories:", dict(cat))
print("size deltas (insns, ours-target):", sorted(sizes))
print("features (all sampled):", dict(feats))
print("top compile errors:"); [print(f"  {k:4} {e}") for e, k in errs.most_common(15)]
