#!/bin/bash
# stop my automation only (chains, loops, builds, quick-boot runs); the user's own PCSX2 is left alone
for p in $(pgrep -f "night.sh|nm_loop.sh|loop_all.sh|make_final.sh|chain1.sh|nm_test.sh|nm_build.sh|runvars.sh|tools/qb/qbrun.py|mktest.sh|mods_copy_build.sh|build_shiftable.sh"); do
  [ "$p" != $$ ] && kill $p 2>/dev/null
done
pkill -f "ninja" 2>/dev/null
powershell.exe -NoProfile -Command "Get-CimInstance Win32_Process -Filter \"Name='pcsx2-qt.exe'\" | ForEach-Object { if (\$_.CommandLine -match 'QUICK.ELF|NM_TEST.ELF') { Stop-Process -Id \$_.ProcessId -Force; 'killed my pcsx2 ' + \$_.ProcessId } else { 'left alone: ' + \$_.CommandLine } }"
I="/mnt/c/Users/Ark/Desktop/TMBO Ready2Play Edition/inis/PCSX2.ini"
grep -q "StandardVolume = 0" "$I" && [ -f "$I.qbbak" ] && cp "$I.qbbak" "$I" && echo "volume restored"
pgrep -fa "night|nm_loop|loop_all|chain1|qbrun|mktest|nm_build" | grep -v stopall
echo STOPPED
