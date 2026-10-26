#!/bin/bash
# split-screen guests test: build (guests.c + hooks), Suburbs 130 %, 1 guest (2 views) and 3 guests (4 views), pictures
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/guests.txt; S=cloud/in/split
echo "waiting for a gap $(date)" >> $L
while pgrep -f "[t]ools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
cp $S/guests_g1.c mods/guests.c; cp $S/bots_g1.c mods/bots.c; cp $S/bots_g1.c cloud/in/bots_v5.c
cp $S/freecam_g1.c mods/freecam.c; cp $S/apply_mods_g1.py mods/apply_mods.py; cp $S/splitpatch2.py $S/splitpatch.py
rm -f test/TRAFFIC_TEST.ELF
bash mods_copy_build.sh > $S/build.txt 2>&1
[ -f test/TRAFFIC_TEST.ELF ] || { echo "build failed"; tail -30 $S/build.txt >> $L; exec bash cloud/in/night.sh 4; }
mv test/TRAFFIC_TEST.ELF test/SPLIT_BASE.ELF; echo "built $(date)" >> $L
for gn in ${GUESTS:-1 3}; do
  python3 $S/splitpatch.py test/SPLIT_BASE.ELF test/SPLIT.ELF 0 $gn 4 10 6 >> $L
  QB_PADS=4 QB_EECYCLE=1 python3 tools/qb/qbrun.py cloud/in/stress/qb_stress_suburbs.json --iso test/TMBR_TEST.iso --elf test/SPLIT.ELF > $S/run.txt 2>&1
  d=$(grep OUT $S/run.txt | awk '{print $2}')
  echo "== guests $gn ($d) TLB $(grep -c 'TLB Miss' $d/emulog.txt)" >> $L
  grep -a "TMBR guests\|TMBR split\|TMBR bots: start\|xception" $d/emulog.txt | cut -c14- | head -12 >> $L
  grep -a "TMBR perf" $d/emulog.txt | tail -4 | cut -c13-100 >> $L
done
echo "GUESTS DONE $(date)" >> $L
exec bash cloud/in/night.sh 4
