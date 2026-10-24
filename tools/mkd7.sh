#!/bin/bash
# DEATH7 test disc: TMBR_TEST.iso with the unused DEATH7 arena swapped in for DEATH6 (pick DEATH6 in the lobby).
#   bash cloud/in/mkd7.sh      (after mktest.sh)
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"
cd "$W"
mkdir -p packs/d7
python3 - <<'PY'
import sys, struct, os
sys.path.insert(0, "/mnt/c/Users/Ark/Desktop/TMB Decomp")
from isols import opener, walk
on = opener("/mnt/c/Users/Ark/Desktop/TMB Decomp/Twisted Metal - Black Online.bin")
pvd = on(16); root = pvd[156:190]
lba, = struct.unpack_from('<I', root, 2); size, = struct.unpack_from('<I', root, 10)
files = {n: (l, s) for n, l, s in walk(on, lba, size, '/', [])}
pups = sorted(n for n in files if n.endswith('.PUP'))
print("levels with a .PUP:", len(pups), [p.split('/')[-1] for p in pups][:30])
for n in ['/LVL/DEATH7.NGP', '/LVL/DEATH7.PTR', '/LVL/DEATH7.TEX', '/LVL/DEATH7.RTX', '/PTS/DEATH7.PTS', '/PTS/DEATH7.PED',
          '/PTS/DEATH7.PKP', '/PTS/DEATH7.HLI', '/RST/DEATH7.RST']:
    l, s = files[n]
    d = on(l, (s + 2047) // 2048)[:s]
    open("packs/d7/" + n.split('/')[-1], "wb").write(d)
    print(n, s)
PY
cp cloud/in/ZN12_D7.BIN packs/d7/ZN12.BIN
D=packs/d7
python3 mkswap.py test/TMBR_TEST.iso test/TMBR_D7.iso \
  /LVL/DEATH6.NGP=$D/DEATH7.NGP /LVL/DEATH6.PTR=$D/DEATH7.PTR /LVL/DEATH6.TEX=$D/DEATH7.TEX /LVL/DEATH6.RTX=$D/DEATH7.RTX \
  /PTS/DEATH6.PTS=$D/DEATH7.PTS /PTS/DEATH6.PED=$D/DEATH7.PED /PTS/DEATH6.PKP=$D/DEATH7.PKP /PTS/DEATH6.HLI=$D/DEATH7.HLI \
  /RST/DEATH6.RST=$D/DEATH7.RST /PCAR/ZN12.BIN=$D/ZN12.BIN | tail -3
printf '@echo off\r\nset P=C:\\Users\\Ark\\Desktop\\TMBO Ready2Play Edition\r\n"%%P%%\\pcsx2-qt.exe" -elf "%%~dp0TMBR_TEST.ELF" -- "%%~dp0TMBR_D7.iso"\r\nfor /f %%%%t in ('"'"'powershell -NoProfile -Command Get-Date -Format yyyyMMdd_HHmmss'"'"') do set TS=%%%%t\r\ncopy /y "%%P%%\\logs\\emulog.txt" "%%~dp0..\\logs_runs\\TMBR_D7_%%TS%%.txt" > nul\r\n' > "test/Run TMBR_D7.bat"
ls -la test/TMBR_D7.iso
echo D7_DONE
