#!/usr/bin/env python3
"""
Generate m2c drafts for every INCLUDE_ASM function in a C file, as '//@@ NAME m2c' blocks for
fast_match.py / batch_try.py. Function extern declarations are dropped (calls fall back to C's
implicit declarations, which avoids clashing with real prototypes); data externs already declared
in the header are dropped too.
Usage: auto_m2c.py SRC.c HEADER OUT.c [max_size_bytes]
"""
import re, subprocess, sys
from pathlib import Path
R = Path.home() / "tmbo_decomp"
src, header, out = Path(sys.argv[1]), (R / "include" / sys.argv[2]).read_text(), Path(sys.argv[3])
max_size = int(sys.argv[4]) if len(sys.argv) > 4 else 1 << 30
known = set(re.findall(r"\b(D_[0-9A-F]{8}|func_[0-9A-F]{8}|[a-z]\w+)\b", header))
items = re.findall(r'^INCLUDE_ASM\("([^"]*)", (\S+)\);', src.read_text(), re.M)
blocks, stats = [], {"ok": 0, "error": 0, "too_big": 0, "failed": 0}
for asmdir, name in items:
    f = Path(asmdir) / f"{name}.s"
    t = f.read_text()
    size = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    if size > max_size: stats["too_big"] += 1; continue
    # m2c needs named registers ($ra, $sp...) and the noreorder header to read these files
    REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
           "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
    tmp = Path("/tmp") / f"m2c_{name}.s"
    tmp.write_text(".set noat\n.set noreorder\n" + re.sub(r"\$(\d{1,2})\b(?![0-9A-Fa-f])",
                   lambda m: "$" + REG[int(m.group(1))] if int(m.group(1)) < 32 else m.group(0), t))
    r = subprocess.run([sys.executable, "-m", "m2c.main", "-t", "mips-gcc-c", "--valid-syntax",
                        "--pointer-style", "left", str(tmp), "-f", name], capture_output=True, text=True)
    if r.returncode or not r.stdout.strip(): stats["failed"] += 1; continue
    code = r.stdout
    if "M2C_ERROR" in code: stats["error"] += 1; continue
    lines = []
    for l in code.splitlines():
        if "/* extern */" in l and "(" in l: continue                     # function decls
        m = re.match(r"extern .*?\b(D_[0-9A-F]{8})\b", l)
        if m and m.group(1) in known: continue                           # declared in header
        lines.append(l)
    body = "\n".join(lines).strip()
    # m2c lists only the args it sees used; fill gaps (arg3 alone -> arg0..arg3) so registers line up
    def fill(m):
        params = [p.strip() for p in m.group(2).split(",") if p.strip() and p.strip() != "void"]
        nums = {int(x.group(1)): p for p in params if (x := re.search(r"\barg(\d+)$", p))}
        if not nums or len(nums) != len(params): return m.group(0)
        full = ", ".join(nums.get(i, f"s32 arg{i}") for i in range(max(nums) + 1))
        return f"{m.group(1)}({full}) {{"
    body = re.sub(rf"^(.*\b{re.escape(name)})\((.*)\) \{{", fill, body, count=1, flags=re.M)
    # bare `sp` = address of a local buffer at the bottom of the frame: declare it, sized from
    # the frame minus the 16-byte register save slots
    if re.search(r"\bsp\b", body) and not re.search(r"\bsp\[", body):
        frame = re.search(r"addiu\s+\$29, \$29, -(0x[0-9A-F]+)", t)
        saves = len(re.findall(r"\bsq\s+\$\d+, 0x[0-9A-F]+\(\$29\)", t))
        if frame and int(frame.group(1), 16) - 16 * saves > 0:
            body = re.sub(rf"^(.*\b{re.escape(name)}\(.*\) \{{)$",
                          lambda m: m.group(1) + f"\n    u8 sp[0x{int(frame.group(1), 16) - 16 * saves:X}];",
                          body, count=1, flags=re.M)
    blocks.append(f"//@@ {name} m2c\n#include \"m2c_macros.h\"\n" + body + "\n")
    stats["ok"] += 1
out.write_text("".join(blocks))
print(f"{len(items)} INCLUDE_ASM functions -> drafts written: {stats['ok']}  "
      f"(m2c gave up: {stats['error']}, m2c failed: {stats['failed']}, over size limit: {stats['too_big']})")
