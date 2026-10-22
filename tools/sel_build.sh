#!/bin/bash
# sel_build.sh NAME SKIPLIST [env...] : test build with some mod hook groups left out -> test/SEL_NAME.ELF + .bat
# (NAME "normal" = the regular test build -> TRAFFIC_TEST.ELF / FREECAM_TEST.ELF)
cd '/mnt/c/Users/Ark/Desktop/TMB Decomp'
N=$1; S=$2; shift 2; [ "$S" = - ] && S=""     # "-" = skip nothing
env TMBR_TEST=1 TMBR_SKIP="$S" "$@" bash mods_copy_build.sh > copybuild_$N.log 2>&1
echo "$N: done=$(grep -c COPYDONE copybuild_$N.log) $(grep -E 'hooks left out|text pad|rror|FAILED' copybuild_$N.log | head -3 | tr '\n' ' ')"
if [ "$N" = normal ]; then cp test/TRAFFIC_TEST.ELF test/FREECAM_TEST.ELF; exit; fi
cp test/TRAFFIC_TEST.ELF test/SEL_$N.ELF
sed "s/TRAFFIC_TEST.ELF/SEL_$N.ELF/" "test/Run TRAFFIC_TEST.bat" > "test/Run SEL_$N.bat"
