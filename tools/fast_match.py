#!/usr/bin/env python3
"""
Fast matching: compile each '//@@ NAME label' block ALONE with the full SN toolchain, compare to the
disc (relocated fields masked). Writes the matching blocks to OUT (first match per NAME).
Usage: fast_match.py DRAFTS.c OUT.c [header]
"""
import re, struct, subprocess, sys, os, time
from pathlib import Path
R = Path.home() / "tmbo_decomp"
ROM = (R / "disks/SCUS_971.96.rom").read_bytes()
WORK = R / "logs/fast"; WORK.mkdir(parents=True, exist_ok=True)
SN = "tools/compilers/ee-gcc2.95.3-114"
header = sys.argv[3] if len(sys.argv) > 3 else "online/net.h"
RMASK = {"R_MIPS_26": 0x03FFFFFF, "R_MIPS_HI16": 0xFFFF, "R_MIPS_LO16": 0xFFFF, "R_MIPS_GPREL16": 0xFFFF}
addr_size = {}
for l in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: addr_size[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))

ASM_INDEX = {p.stem: p for p in (R / "asm/nonmatchings").rglob("*.s")}
def orig(name):
    if name in addr_size: return addr_size[name]
    t = ASM_INDEX[name].read_text()
    s = int(re.search(rf"nonmatching {re.escape(name)}, (0x[0-9A-F]+)", t).group(1), 16)
    a = int(re.search(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", t).group(1), 16)
    return a, s

def check(name, code):
    (WORK / "f.c").write_text(f'#include "{header}"\n{code}')
    obj = WORK / "f.o"; obj.unlink(missing_ok=True)
    r = subprocess.run([f"{R / SN}/bin/ee-gcc.exe", f"-B{SN}/lib/gcc-lib/ee/2.95.3/", "-c", "-O2", "-G0", "-Wa,-G8",
                        *os.environ.get("FLAGS", "").split(),
                        "-fno-exceptions", "-Iinclude", "-isystem", "include/gcc", str(WORK.relative_to(R) / "f.c"),
                        "-o", str(obj.relative_to(R))], cwd=R, capture_output=True, text=True)
    if r.returncode or not obj.exists(): return "compile error"
    nm = subprocess.run(["mips-linux-gnu-nm", "-S", str(obj)], capture_output=True, text=True).stdout
    sym = next((l.split() for l in nm.splitlines() if len(l.split()) == 4 and l.split()[3] == name), None)
    if not sym: return "symbol missing"
    off, size = int(sym[0], 16), int(sym[1], 16)
    a, s = orig(name)
    text = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", str(obj), "/dev/stdout"],
                          capture_output=True).stdout
    if size != s:
        # a lone trailing nop is alignment padding, counted on one side only; compare without it
        longer = text[off:off + size] if size > s else ROM[a - 0x100000:][:s]
        if abs(size - s) == 4 and longer[-4:] == b"\0\0\0\0":
            s = min(size, s)
        else:
            return f"size {size} vs {s}"
    mask, sec = {}, False
    for l in subprocess.run(["mips-linux-gnu-readelf", "-rW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        if l.startswith("Relocation section"): sec = "'.rel.text'" in l
        m = re.match(r"\s*([0-9a-f]+)\s+[0-9a-f]+\s+(R_MIPS_\w+)", l)
        if m and sec: mask[int(m.group(1), 16)] = RMASK.get(m.group(2), 0)
    bad = sum((struct.unpack_from("<I", text, off + i)[0] & ~mask.get(off + i, 0)) !=
              (struct.unpack_from("<I", ROM, a - 0x100000 + i)[0] & ~mask.get(off + i, 0)) for i in range(0, s, 4))
    return "MATCH" if bad == 0 else f"{bad} insns differ"

blocks = re.split(r"^//@@ (\S+)[^\n]*\n", Path(sys.argv[1]).read_text(), flags=re.M)[1:]
matched, results, t0 = {}, {}, time.time()
only = set(os.environ["ONLY_NAMES"].split(",")) if os.environ.get("ONLY_NAMES") else None
near = {}   # name -> (insns differing, code) for same-size misses
for name, code in zip(blocks[0::2], blocks[1::2]):
    if name in matched or (only is not None and name not in only): continue
    res = check(name, code)
    results.setdefault(name, []).append(res)
    if res == "MATCH": matched[name] = code
    elif (m := re.match(r"(\d+) insns differ", res)) and (name not in near or int(m.group(1)) < near[name][0]):
        near[name] = (int(m.group(1)), code)
if os.environ.get("NEAR_OUT"):
    import json
    Path(os.environ["NEAR_OUT"]).write_text(json.dumps({n: {"diff": d, "code": c} for n, (d, c) in near.items()}))
Path(sys.argv[2]).write_text("".join(f"//@@ {n}\n{c.rstrip()}\n" for n, c in matched.items()))
tally = {}
for rs in results.values():
    k = "MATCH" if "MATCH" in rs else re.sub(r"\d+", "N", rs[-1]); tally[k] = tally.get(k, 0) + 1
print(f"checked {len(results)} functions in {time.time() - t0:.0f}s: {tally}")
# size mismatches: how far off (ours - original, in instructions), best variant per function
deltas = {}
for n, rs in results.items():
    ds = [int(m.group(1)) - int(m.group(2)) for r in rs if (m := re.match(r"size (\d+) vs (\d+)", r))]
    if ds and "MATCH" not in rs: deltas[n] = min(ds, key=abs) // 4
if deltas:
    import collections
    h = collections.Counter(deltas.values())
    print("size off by (insns, ours-orig):", dict(sorted(h.items())))
    print("closest:", sorted(deltas.items(), key=lambda kv: abs(kv[1]))[:12])
print("matched:", list(matched))
