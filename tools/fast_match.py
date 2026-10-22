#!/usr/bin/env python3
"""
RETAIL (SCUS-97101) fast matching: compile each '//@@ NAME label' block ALONE with the retail
toolchain (Sony EE-GCC 2.9, same flags as build.ninja), compare to the disc with relocated fields
masked. Writes the matching blocks to OUT (first match per NAME).
NAME is the symbol as it appears in the object/asm, i.e. MANGLED for C++ (Init__5Comboi).
Usage: fast_match.py DRAFTS OUT [header]
  header: include path for every block (e.g. tmb/combo.hpp), '' for none.
  LANG_SRC=c++ (default if header ends in .hpp) compiles as C++, else C. Drafts from m2c are C and
  can declare mangled names directly, since those are valid C identifiers.
Env: FLAGS (extra cc flags), ONLY_NAMES (comma list), NEAR_OUT (json of same-size near misses),
     VERBOSE=1 (per-function result), SHOW_ERR=1 (compiler errors).
"""
import re, struct, subprocess, sys, os, time, json, collections
from pathlib import Path
R = Path.home() / "tmb_decomp"
ROM = (R / "disks/SCUS_971.01.rom").read_bytes()
BASE = 0x100000                      # main segment: rom 0x0 = vram 0x100000
WORK = R / "logs/fast" / str(os.getpid()); WORK.mkdir(parents=True, exist_ok=True)   # per process: parallel-safe
import atexit, shutil; atexit.register(shutil.rmtree, WORK, True)
CC = [str(R / "tools/ee-gcc2.9/bin/ee-gcc"), "-c", "-Iinclude", "-isystem", "include/gcc",
      "-isystem", "include/gcc/gcc-lib", "-isystem", "include/sdk", "-isystem", "include/sdk/common",
      "-isystem", "include/sdk/ee", "-O2", "-G8", "-fno-exceptions"]
header = sys.argv[3] if len(sys.argv) > 3 else ""
CPP = os.environ.get("LANG_SRC", "c++" if header.endswith((".hpp", ".hh")) else "c") == "c++"
RMASK = {"R_MIPS_26": 0x03FFFFFF, "R_MIPS_HI16": 0xFFFF, "R_MIPS_LO16": 0xFFFF, "R_MIPS_GPREL16": 0xFFFF,
         "R_MIPS_LITERAL": 0xFFFF}

addr_size = {}
for l in (R / "config/US/symbol_addrs.txt").read_text().splitlines():
    m = re.match(r"\s*(\S+)\s*=\s*(0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)", l)
    if m: addr_size[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))
_asm = None
def orig(name):
    """address, size of the original function: symbol_addrs first, else the whole-file asm."""
    global _asm
    if name in addr_size: return addr_size[name]
    if _asm is None:
        _asm = {}
        for p in (R / "asm").rglob("*.s"):
            for m in re.finditer(r"nonmatching (\S+), (0x[0-9A-F]+)\s+glabel \S+\s+/\* [0-9A-F]+ ([0-9A-F]{8})",
                                 p.read_text(errors="replace")):
                _asm[m.group(1)] = (int(m.group(3), 16), int(m.group(2), 16))
    return _asm[name]

def check(name, code):
    src = WORK / ("f.cpp" if CPP else "f.c")
    src.write_text((f'#include "{header}"\n' if header else "") + code)
    obj = WORK / "f.o"; obj.unlink(missing_ok=True)
    r = subprocess.run([*CC, *(["-x", "c++"] if CPP else []), *os.environ.get("FLAGS", "").split(),
                        str(src.relative_to(R)), "-o", str(obj.relative_to(R))], cwd=R, capture_output=True, text=True)
    if r.returncode or not obj.exists():
        if os.environ.get("SHOW_ERR"): print(name, r.stderr[-2000:])
        return "compile error"
    nm = subprocess.run(["mips-linux-gnu-nm", "-S", str(obj)], capture_output=True, text=True).stdout
    sym = next((l.split() for l in nm.splitlines() if len(l.split()) == 4 and l.split()[3] == name), None)
    if not sym: return "symbol missing"
    off, size = int(sym[0], 16), int(sym[1], 16)
    try: a, s = orig(name)
    except KeyError: return "no original"
    text = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", str(obj), "/dev/stdout"],
                          capture_output=True).stdout
    if size != s:
        # a lone trailing nop is alignment padding, counted on one side only; compare without it
        longer = text[off:off + size] if size > s else ROM[a - BASE:][:s]
        if abs(size - s) == 4 and longer[-4:] == b"\0\0\0\0": s = min(size, s)
        else: return f"size {size} vs {s}"
    mask, sec = {}, False
    for l in subprocess.run(["mips-linux-gnu-readelf", "-rW", str(obj)], capture_output=True, text=True).stdout.splitlines():
        if l.startswith("Relocation section"): sec = "'.rel.text'" in l
        m = re.match(r"\s*([0-9a-f]+)\s+[0-9a-f]+\s+(R_MIPS_\w+)", l)
        if m and sec: mask[int(m.group(1), 16)] = RMASK.get(m.group(2), 0)
    bad = sum((struct.unpack_from("<I", text, off + i)[0] & ~mask.get(off + i, 0)) !=
              (struct.unpack_from("<I", ROM, a - BASE + i)[0] & ~mask.get(off + i, 0)) for i in range(0, s, 4))
    return "MATCH" if bad == 0 else f"{bad} insns differ"

parts = re.split(r"^//@@ (\S+)([^\n]*)\n", Path(sys.argv[1]).read_text(), flags=re.M)[1:]
label = {}
blocks = []
for n, lab, c in zip(parts[0::3], parts[1::3], parts[2::3]):
    blocks += [n, c]; label.setdefault((n, c), lab.strip())
matched, results, t0 = {}, {}, time.time()
only = set(os.environ["ONLY_NAMES"].split(",")) if os.environ.get("ONLY_NAMES") else None
near = {}
for name, code in zip(blocks[0::2], blocks[1::2]):
    if name in matched or (only is not None and name not in only): continue
    res = check(name, code)
    results.setdefault(name, []).append(res)
    if os.environ.get("VERBOSE"): print(f"{name}: {res}")
    if res == "MATCH": matched[name] = code
    elif (m := re.match(r"(\d+) insns differ", res)) and (name not in near or int(m.group(1)) < near[name][0]):
        near[name] = (int(m.group(1)), code)
if os.environ.get("NEAR_OUT"):
    Path(os.environ["NEAR_OUT"]).write_text(json.dumps({n: {"diff": d, "code": c} for n, (d, c) in near.items()}))
Path(sys.argv[2]).write_text("".join(f"//@@ {n} {label.get((n, c), '')}\n{c.rstrip()}\n" for n, c in matched.items()))
tally = collections.Counter("MATCH" if "MATCH" in rs else re.sub(r"\d+", "N", rs[-1]) for rs in results.values())
print(f"checked {len(results)} functions in {time.time() - t0:.0f}s: {dict(tally)}")
deltas = {}
for n, rs in results.items():
    ds = [int(m.group(1)) - int(m.group(2)) for r in rs if (m := re.match(r"size (\d+) vs (\d+)", r))]
    if ds and "MATCH" not in rs: deltas[n] = min(ds, key=abs) // 4
if deltas:
    print("size off by (insns, ours-orig):", dict(sorted(collections.Counter(deltas.values()).items())))
    print("closest:", sorted(deltas.items(), key=lambda kv: abs(kv[1]))[:12])
print("matched:", list(matched))
