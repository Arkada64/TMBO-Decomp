#!/bin/bash
# Build the shiftable+mods ELF in a private copy of the repo (~/modshome/tmbo_decomp) so it can run while the
# permuter is using ~/tmbo_decomp. Results -> TMB Decomp/test/TRAFFIC_TEST.ELF and TMB Decomp/release/
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"
SRC=/home/ark/tmbo_decomp; MH=/home/ark/modshome; D=$MH/tmbo_decomp
mkdir -p $MH
rsync -a --delete --exclude 'logs/' $SRC/ $D/
cd $D
git checkout -q -- src                       # drop any permuter candidate that was mid-test
grep -rlI "/home/ark/tmbo_decomp" build.ninja config src tools 2>/dev/null | xargs -r sed -i "s#/home/ark/tmbo_decomp#$D#g"
mkdir -p logs tools/mods mods
rm -f mods/*.c; cp "$W"/mods/*.s "$W"/mods/*.c "$W"/mods/*.pnach "$W"/mods/*_sections.txt "$W"/mods/postlink.txt mods/
cp "$W/mods/apply_mods.py" "$W/mods/apply_pnach.py" "$W/mods/bps.py" tools/mods/
cp "$W/build_shiftable.sh" "$W/make_tester_patch.sh" tools/
source .venv/bin/activate
rm -f build/SCUS_971.96.rom; ninja > logs/copy_base.log 2>&1 || { tail -5 logs/copy_base.log; exit 1; }
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "copy: base byte-identical" || echo "copy: base NOT identical"
HOME=$MH TMBR_DEBUG_LOADER=${TMBR_DEBUG_LOADER:-0} bash tools/build_shiftable.sh 2>&1 | grep -vE "RWX|^\[" | tail -40
cp build/SCUS_971.96.shift.elf "$W/test/TRAFFIC_TEST.ELF" && echo "TRAFFIC_TEST.ELF updated"
[ "${RELEASE:-0}" = 1 ] && HOME=$MH bash tools/make_tester_patch.sh
echo COPYDONE
