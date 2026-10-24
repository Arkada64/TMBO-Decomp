#!/bin/bash
# Lost maps test disc: TMBR_TEST.iso with the five converted Lost / Harbor City maps swapped into the DEATH1-5
# arena slots (built on DEATH4's shared assets: weapons, pickup models, effects).
#   Elevators -> City of the Dead, Snowy Roads -> Suburban Terror, Power Plant -> Carnival of Darkness,
#   Dogpound -> Death Port, Sewers -> Stadium Slaughter
#   bash cloud/lost2/mklost.sh      (after mktest.sh)
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; S=cloud/lost2; O=packs/lost2; mkdir -p $O
python3 - <<'PY'
import sys, struct, zlib, os
sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp")
from ngpdb import rawfile
S, O = "cloud/lost2", "packs/lost2"
SLOTS = {"HCGD": "DEATH1", "HCSU": "DEATH2", "HCSC": "DEATH3", "HCND": "DEATH4", "HCST": "DEATH5"}
def wrap(orig, data):
    """re-pack into the game's zip-like container, header copied from the original disc file"""
    nl, xl = struct.unpack_from('<HH', orig, 26)
    c = zlib.compressobj(9, zlib.DEFLATED, -15); comp = c.compress(data) + c.flush()
    crc = zlib.crc32(data) & 0xffffffff
    loc = bytearray(orig[:30 + nl + xl]); struct.pack_into('<III', loc, 14, crc, len(comp), len(data))
    cs_old = struct.unpack_from('<I', orig, 18)[0]
    tail = bytearray(orig[30 + nl + xl + cs_old:])
    cd = tail.find(b'PK\x01\x02'); struct.pack_into('<III', tail, cd + 16, crc, len(comp), len(data))
    eo = tail.find(b'PK\x05\x06'); struct.pack_into('<I', tail, eo + 16, len(loc) + len(comp))
    return bytes(loc) + comp + bytes(tail)
args = []
for src, lv in SLOTS.items():
    for ext in ("NGP", "PTR", "TEX", "RTX"):
        orig = rawfile("online", f"/LVL/{lv}.{ext}")
        data = open(f"{S}/{src}.{ext}", "rb").read()
        zipped = orig[2:4] == b"\x03\x04"
        out = wrap(orig, data) if zipped else data
        open(f"{O}/{lv}.{ext}", "wb").write(out)
        args.append(f"/LVL/{lv}.{ext}={O}/{lv}.{ext}")
        print(lv, ext, "zip" if zipped else "raw", len(data), "->", len(out))
    for ext in ("PKP", "PTS", "PUP"):
        os.system(f'cp "{S}/{src}.{ext}" "{O}/{lv}.{ext}"'); args.append(f"/PTS/{lv}.{ext}={O}/{lv}.{ext}")
    zn = {"DEATH1": 7, "DEATH2": 8, "DEATH3": 9, "DEATH4": 10, "DEATH5": 11}[lv]
    os.system(f'cp "{S}/{src}.ZN" "{O}/ZN{zn:02d}.BIN"'); args.append(f"/PCAR/ZN{zn:02d}.BIN={O}/ZN{zn:02d}.BIN")
open(f"{O}/args.txt", "w").write(" ".join(args))
PY
python3 mkswap.py test/TMBR_TEST.iso test/TMBR_LOST.iso $(cat $O/args.txt) | tail -3
printf '@echo off\r\nset P=C:\\Users\\Ark\\Desktop\\TMBO Ready2Play Edition\r\n"%%P%%\\pcsx2-qt.exe" -elf "%%~dp0TMBR_TEST.ELF" -- "%%~dp0TMBR_LOST.iso"\r\nfor /f %%%%t in ('"'"'powershell -NoProfile -Command Get-Date -Format yyyyMMdd_HHmmss'"'"') do set TS=%%%%t\r\ncopy /y "%%P%%\\logs\\emulog.txt" "%%~dp0..\\logs_runs\\TMBR_LOST_%%TS%%.txt" > nul\r\n' > "test/Run TMBR_LOST.bat"
ls -la test/TMBR_LOST.iso; echo LOST_DONE
