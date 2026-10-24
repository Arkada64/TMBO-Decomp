#!/bin/bash
# Working-C test build in a private copy (~/nmhome/tmbo_decomp, so the permuter can keep using ~/tmbo_decomp):
#   1. nm_apply.py puts every compiling m2c draft in as an #ifdef NON_MATCHING alternative to its INCLUDE_ASM
#   2. the normal build must still be byte-identical
#   3. the shiftable build with mods and -DNON_MATCHING -> TMB Decomp/test/NM_TEST.ELF
#   bash tools/nm_build.sh [SRC.c ...]       (default: all files with drafts)
set -e -o pipefail
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"
SRC=/home/ark/tmbo_decomp; NH=/home/ark/nmhome; D=$NH/tmbo_decomp
mkdir -p $NH
rsync -a --delete --exclude 'logs/perm*' --exclude 'logs/fast' $SRC/ $D/
cd $D
git checkout -q -- src
grep -rlI "/home/ark/tmbo_decomp" build.ninja config src tools 2>/dev/null | xargs -r sed -i "s#/home/ark/tmbo_decomp#$D#g"
mkdir -p logs tools/mods mods
rm -f mods/*.c; cp "$W"/mods/*.s "$W"/mods/*.c "$W"/mods/*.pnach "$W"/mods/*_sections.txt "$W"/mods/postlink.txt mods/
cp "$W/mods/apply_mods.py" "$W/mods/apply_pnach.py" "$W/mods/bps.py" tools/mods/
cp "$W/build_shiftable.sh" tools/
cp "$W/cloud/in/nm_apply.py" tools/
source .venv/bin/activate
HOME=$NH python3 tools/nm_apply.py "$@" | tail -3
rm -f build/SCUS_971.96.rom; ninja > logs/nm_base.log 2>&1 || { tail -5 logs/nm_base.log; exit 1; }
cmp -s build/SCUS_971.96.rom disks/SCUS_971.96.rom && echo "normal build: byte-identical" || { echo "normal build NOT identical"; exit 1; }
# alignment-safe link for the C replacements (tools/nm_ld.py: text growth in 0x80 steps, literals after .sdata)
cp "$W/cloud/in/nm_ld.py" tools/ && python3 tools/nm_ld.py build/SCUS_971.96.map config/US/SCUS_971.96.ld "$@"
# -DNON_MATCHING for the shiftable link only (build.ninja is restored by build_shiftable.sh)
sed -i 's#^grep -q data_ptrs_shiftable#[ "${NONMATCHING:-0}" = 1 ] \&\& sed -i "s|tools/sn_cc.sh -c |tools/sn_cc.sh -c -DNON_MATCHING |" build.ninja\n&#' tools/build_shiftable.sh
rm -f build/SCUS_971.96.shift.elf
# (its closing "normal build restored" check fails here: the link script keeps the C guards; that is fine,
#  this copy is rebuilt from scratch every time)
HOME=$NH NONMATCHING=1 bash tools/build_shiftable.sh 2>&1 | grep -vE "RWX|^\[" | tail -15 || true
[ -f build/SCUS_971.96.shift.elf ] || { echo "no shift ELF"; exit 1; }
cp build/SCUS_971.96.shift.elf "$W/test/NM_TEST.ELF" && echo "NM_TEST.ELF updated"
echo NM_DONE
