#!/bin/bash
# One test build for everything: TMB Decomp/test/TMBR_TEST.ELF (all mods: traffic on, bots, peds, cameras,
# Gold Tooth toggle) + TMBR_TEST.iso (online disc + content packs + Gold Tooth \PCAR\ZZP.*) + Run TMBR_TEST.bat.
#   bash "/mnt/c/Users/Ark/Desktop/TMB Decomp/mktest.sh"          (CLEAN=1 also removes the old test files)
set -e -o pipefail
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"
cd "$W"
rm -f test/TRAFFIC_TEST.ELF
bash mods_copy_build.sh | tail -4
cp test/TRAFFIC_TEST.ELF test/TMBR_TEST.ELF
B="ZZP.NGP ZZP.PTR ZZP.RTX ZZP.TEX ACAR/ZZA.NGP ACAR/ZZA.PTR ACAR/ZZA.RTX ACAR/ZZA.TEX ZTP.NGP ZTP.PTR ZTP.RTX ZTP.TEX ACAR/ZTA.NGP ACAR/ZTA.PTR ACAR/ZTA.RTX ACAR/ZTA.TEX ZVP.NGP ZVP.PTR ZVP.RTX ZVP.TEX ACAR/ZVA.NGP ACAR/ZVA.PTR ACAR/ZVA.RTX ACAR/ZVA.TEX ZXP.NGP ZXP.PTR ZXP.RTX ZXP.TEX ACAR/ZXA.NGP ACAR/ZXA.PTR ACAR/ZXA.RTX ACAR/ZXA.TEX ZWP.NGP ZWP.PTR ZWP.RTX ZWP.TEX ACAR/ZWA.NGP ACAR/ZWA.PTR ACAR/ZWA.RTX ACAR/ZWA.TEX ZUP.NGP ZUP.PTR ZUP.RTX ZUP.TEX ACAR/ZUA.NGP ACAR/ZUA.PTR ACAR/ZUA.RTX ACAR/ZUA.TEX ZFP0.BIN ZFP1.BIN ZRP0.BIN ZRP1.BIN ZRP2.BIN ZAP0.BIN ZAP1.BIN ZSP0.BIN ZSP1.BIN ZSF0.BIN ZSF1.BIN ZSF2.BIN ZYP.NGP ZYP.PTR ZYP.RTX ZYP.TEX ACAR/ZYA.NGP ACAR/ZYA.PTR ACAR/ZYA.RTX ACAR/ZYA.TEX PTS/ZZASYLUM.PED PTS/ZZSHIP.PED SHELL/SHELL1.TEX SHELL/SHELL1.NGP SHELL/SHELL1.PTR $(cd packs && ls ZN??.BIN 2>/dev/null | tr "\n" " ") $(cd packs && ls MOV/*.PSS 2>/dev/null | tr "\n" " ")"
cd packs && rm -f ../test/TMBR_TEST.iso
python3 ../mkdisc.py ../test/TMBR_TEST.iso $B | tail -3
cd .. && python3 checkdisc.py test/TMBR_TEST.iso $B | tail -1
printf '@echo off\r\nset P=C:\\Users\\Ark\\Desktop\\TMBO Ready2Play Edition\r\n"%%P%%\\pcsx2-qt.exe" -elf "%%~dp0TMBR_TEST.ELF" -- "%%~dp0TMBR_TEST.iso"\r\nfor /f %%%%t in ('"'"'powershell -NoProfile -Command Get-Date -Format yyyyMMdd_HHmmss'"'"') do set TS=%%%%t\r\ncopy /y "%%P%%\\logs\\emulog.txt" "%%~dp0..\\logs_runs\\TMBR_TEST_%%TS%%.txt" > nul\r\n' > "test/Run TMBR_TEST.bat"
if [ "${CLEAN:-0}" = 1 ]; then
  cd test
  for f in *; do
    case "$f" in STABLE.ELF|"Run STABLE.bat"|TMBR_TEST.ELF|TMBR_TEST.iso|"Run TMBR_TEST.bat"|TRAFFIC_TEST.ELF) ;; *) rm -f -- "$f" ;; esac
  done
  rm -rf ../cloud/goldtooth/? 2>/dev/null || true
  cd ..
fi
ls test
echo MKTEST_DONE
