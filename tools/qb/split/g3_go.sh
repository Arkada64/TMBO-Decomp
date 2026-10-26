#!/bin/bash
# guest car-select test: build (guests pick on the real car select, reticle charging), Suburbs 130 %, multitap,
# controller 2 presses START in the waiting room, picks 2 cars right, confirms; pictures of the pick and the match
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/g3.txt; S=cloud/in/g3
echo "waiting for a gap $(date)" >> $L
while pgrep -f "[t]ools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
for f in guests bots skins freecam quickboot; do cp $S/${f}_g3.c mods/$f.c; done
cp $S/bots_g3.c cloud/in/bots_v5.c; cp $S/apply_mods_g3.py mods/apply_mods.py; cp $S/qbrun_g3.py tools/qb/qbrun.py
rm -f test/TRAFFIC_TEST.ELF
bash mods_copy_build.sh > $S/build.txt 2>&1
[ -f test/TRAFFIC_TEST.ELF ] || { echo "build failed"; grep -i -B3 -A3 "error" $S/build.txt | head -40 >> $L; exec bash cloud/in/night.sh 4; }
mv test/TRAFFIC_TEST.ELF test/SPLIT_BASE.ELF; echo "built $(date)" >> $L
python3 cloud/in/split/splitpatch.py test/SPLIT_BASE.ELF test/SPLIT.ELF 0 >> $L
QB_PADS=4 QB_EECYCLE=1 python3 tools/qb/qbrun.py $S/qb_guestpick.json --iso test/TMBR_TEST.iso --elf test/SPLIT.ELF > $S/run.txt 2>&1
d=$(grep OUT $S/run.txt | awk '{print $2}')
echo "== guestpick ($d) TLB $(grep -c 'TLB Miss' $d/emulog.txt)" >> $L
grep -a "TMBR guests\|TMBR split\|TMBR charge\|TMBR wide\|xception" $d/emulog.txt | cut -c14- | head -30 >> $L
tail -3 $S/run.txt >> $L
echo "G3 DONE $(date)" >> $L
exec bash cloud/in/night.sh 4
