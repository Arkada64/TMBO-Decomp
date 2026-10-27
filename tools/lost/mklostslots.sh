#!/bin/bash
# Lost / Harbor City maps in their own level-select entries (mods/lostslots.c, reference/wip/LOST_SLOTS.md):
# test/LOSTSLOTS.iso = the normal test disc (mktest.sh's file list) + the five converted maps under their own names.
# Every existing level keeps its own files. The maps run as Dogpound (index 10, files DEATH4 = the conversion donor):
#   \LVL\HC<xx>.NGP/.PTR/.TEX/.RTX   (zip-wrapped like the disc's DEATH4.<ext> when that one is zipped)
#   \PTS\HC<xx>.PKP/.PTS/.PUP        \PCAR\ZNHC<xx>.BIN (bots' route map)
#   xx = SC Carnival of Darkness, SU Suburban Terror, GD City of the Dead, ND Death Port, ST Stadium Slaughter
# Sources: cloud/lost2/HC<xx>.{NGP,PTR,TEX,RTX,PKP,PTS,PUP,ZN}; staged copies in packs/lost3/ (overwritten each
# run, nothing deleted). Needs test/TMBR_TEST.ELF from mktest.sh (or mods_copy_build.sh) built with these mods.
#   bash tools/lost/mklostslots.sh            (from anywhere; works in "TMB Decomp")
set -e -o pipefail
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; S=cloud/lost2; O=packs/lost3
mkdir -p $O/LVL $O/PTS $O/PCAR
python3 - <<'PY'
import sys, struct, zlib, shutil, os
sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp")
from ngpdb import rawfile
S, O = "cloud/lost2", "packs/lost3"
MAPS = ["SC", "SU", "GD", "ND", "ST"]          # Lost's menu order = mods/lostslots.c LCODE
def wrap(orig, data):
    """re-pack into the game's zip-like container, header copied from the original disc file (as mklost.sh)"""
    nl, xl = struct.unpack_from('<HH', orig, 26)
    c = zlib.compressobj(9, zlib.DEFLATED, -15); comp = c.compress(data) + c.flush()
    crc = zlib.crc32(data) & 0xffffffff
    loc = bytearray(orig[:30 + nl + xl]); struct.pack_into('<III', loc, 14, crc, len(comp), len(data))
    cs_old = struct.unpack_from('<I', orig, 18)[0]
    tail = bytearray(orig[30 + nl + xl + cs_old:])
    cd = tail.find(b'PK\x01\x02'); struct.pack_into('<III', tail, cd + 16, crc, len(comp), len(data))
    eo = tail.find(b'PK\x05\x06'); struct.pack_into('<I', tail, eo + 16, len(loc) + len(comp))
    return bytes(loc) + comp + bytes(tail)
def same(a, b):
    return os.path.exists(b) and os.path.getsize(a) == os.path.getsize(b) and open(a, "rb").read() == open(b, "rb").read()
orig = {ext: rawfile("online", f"/LVL/DEATH4.{ext}") for ext in ("NGP", "PTR", "TEX", "RTX")}
args = []
for m in MAPS:
    src = f"{S}/HC{m}"
    need = [f"{src}.{e}" for e in ("NGP", "PTR", "TEX", "RTX", "PKP", "PTS", "PUP", "ZN")]
    miss = [n for n in need if not os.path.exists(n)]
    if miss:
        print(f"HC{m}: skipped, missing {' '.join(miss)}"); continue
    for ext in ("NGP", "PTR", "TEX", "RTX"):
        data = open(f"{src}.{ext}", "rb").read()
        zipped = orig[ext][2:4] == b"\x03\x04"
        out = wrap(orig[ext], data) if zipped else data
        dst = f"{O}/LVL/HC{m}.{ext}"
        if not (os.path.exists(dst) and open(dst, "rb").read() == out):   # unchanged: no rewrite (SSD)
            open(dst, "wb").write(out)
        args.append(f"LVL/HC{m}.{ext}")
        print(f"HC{m}.{ext}", "zip" if zipped else "raw", len(data), "->", len(out))
    for ext in ("PKP", "PTS", "PUP"):
        dst = f"{O}/PTS/HC{m}.{ext}"
        if not same(f"{src}.{ext}", dst): shutil.copyfile(f"{src}.{ext}", dst)
        args.append(f"PTS/HC{m}.{ext}")
    dst = f"{O}/PCAR/ZNHC{m}.BIN"
    if not same(f"{src}.ZN", dst): shutil.copyfile(f"{src}.ZN", dst)
    args.append(f"PCAR/ZNHC{m}.BIN")
open(f"{O}/args.txt", "w").write(" ".join(args))
PY
B=$(grep '^B=' mktest.sh | head -1 | sed 's/^B=//'); B=$(eval echo $B)    # (evaluated in TMB Decomp, as mktest.sh does)
# mkdisc.py takes paths relative to packs/ and puts DIR/NAME into \DIR\NAME. Our files are staged under
# packs/lost3/: a path that is not in packs/ itself is read from packs/lost3/ instead (no copies into packs/).
( cd packs && python3 - ../test/LOSTSLOTS.iso $B $(cat lost3/args.txt) <<'PY'
import sys, os, builtins, runpy
real_open, real_exists, real_size = builtins.open, os.path.exists, os.path.getsize
def r(f):
    return "lost3/" + f if isinstance(f, str) and not real_exists(f) and real_exists("lost3/" + f) else f
builtins.open = lambda f, *a, **k: real_open(r(f), *a, **k)
os.path.exists = lambda f: real_exists(r(f))
os.path.getsize = lambda f: real_size(r(f))
sys.argv = ["../mkdisc.py"] + sys.argv[1:]
runpy.run_path("../mkdisc.py", run_name="__main__")
PY
) | tail -12
printf '@echo off\r\nset P=C:\\Users\\Ark\\Desktop\\TMBO Ready2Play Edition\r\n"%%P%%\\pcsx2-qt.exe" -elf "%%~dp0TMBR_TEST.ELF" -- "%%~dp0LOSTSLOTS.iso"\r\nfor /f %%%%t in ('"'"'powershell -NoProfile -Command Get-Date -Format yyyyMMdd_HHmmss'"'"') do set TS=%%%%t\r\ncopy /y "%%P%%\\logs\\emulog.txt" "%%~dp0..\\logs_runs\\LOSTSLOTS_%%TS%%.txt" > nul\r\n' > "test/Run LOSTSLOTS.bat"
ls -la test/LOSTSLOTS.iso; echo LOSTSLOTS_DONE
