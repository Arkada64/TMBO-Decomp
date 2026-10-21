#!/usr/bin/env python3
"""
RETAIL: instruction diff, original (disc) vs ours, for one '//@@ NAME' block.
Usage: showdiff.py DRAFTS NAME [header]     (env LANG_SRC=c++ as in fast_match.py)
Prints the draft's C too unless NOC=1. Branch/jump targets are blanked (absolute addresses).
"""
import re, subprocess, sys, os, difflib, importlib.util
from pathlib import Path
drafts, name = sys.argv[1], sys.argv[2]
header = sys.argv[3] if len(sys.argv) > 3 else ""
sys.argv = ["fast_match.py", "/dev/null", "/dev/null", header]   # its main loop sees no blocks
spec = importlib.util.spec_from_file_location("fm", Path(__file__).with_name("fast_match.py"))
fm = importlib.util.module_from_spec(spec)
spec.loader.exec_module(fm)
blocks = re.split(r"^//@@ (\S+)[^\n]*\n", Path(drafts).read_text(), flags=re.M)[1:]
code = [c for n, c in zip(blocks[0::2], blocks[1::2]) if n == name][int(os.environ.get("V", 0))]   # V=n: nth variant
print("result:", fm.check(name, code))
def dis(path, start=None, stop=None):
    args = ["mips-linux-gnu-objdump", "-D" if start is not None else "-d", "-z", "--no-show-raw-insn", "-M", "no-aliases"]
    if start is not None:
        args += ["-b", "binary", "-m", "mips:5900", "-EL", f"--start-address={start}", f"--stop-address={stop}"]
    else:
        args += ["--disassemble=" + name]
    out = subprocess.run(args + [str(path)], capture_output=True, text=True).stdout
    ls = [re.sub(r"\s+", " ", l.split(":", 1)[1]).strip() for l in out.splitlines() if re.match(r"\s+[0-9a-f]+:\t", l)]
    return [re.sub(r"^((?:b|j)\S* .*?)\b(?:0x)?[0-9a-f]+(?: <[^>]*>)?$", r"\1TGT", l) for l in ls]
a, s = fm.orig(name)
theirs = dis(fm.R / "disks/SCUS_971.01.rom", a - fm.BASE, a - fm.BASE + s)
ours = dis(fm.WORK / "f.o")
for l in difflib.unified_diff(theirs, ours, "disc", "ours", n=2, lineterm=""): print(l)
if not os.environ.get("NOC"): print("\n" + code)
