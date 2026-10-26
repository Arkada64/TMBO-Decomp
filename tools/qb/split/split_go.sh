#!/bin/bash
# split-screen stress (experimental): TMBR with extra views following bots (mods/freecam.c tmbr_split), 7 bots +
# traffic, minimized. MAPS / VIEWS / RATES from the environment. Results: cloud/qb_out/split.txt
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/split.txt; S=cloud/in/split
echo "waiting for a gap $(date)" >> $L
while pgrep -f "[t]ools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
if [ ! -f test/SPLIT_BASE.ELF ] || [ "${REBUILD:-0}" = 1 ]; then
  cp $S/freecam_split1.c mods/freecam.c
  rm -f test/TRAFFIC_TEST.ELF
  bash mods_copy_build.sh > $S/build.txt 2>&1
  [ -f test/TRAFFIC_TEST.ELF ] || { echo "build failed"; tail -25 $S/build.txt >> $L; exec bash cloud/in/night.sh 4; }
  mv test/TRAFFIC_TEST.ELF test/SPLIT_BASE.ELF
  echo "built $(date)" >> $L
fi
for m in ${MAPS:-suburbs}; do for ee in ${RATES:-0}; do for v in ${VIEWS:-2 4}; do
  python3 $S/splitpatch.py test/SPLIT_BASE.ELF test/SPLIT.ELF $v >> $L
  QB_EECYCLE=$ee python3 tools/qb/qbrun.py cloud/in/stress/qb_stress_$m.json --iso test/TMBR_TEST.iso --elf test/SPLIT.ELF > $S/run.txt 2>&1
  d=$(grep OUT $S/run.txt | awk '{print $2}')
  echo "== $m EE $ee views $v ($d) bots $(grep -c 'TMBR bots: car' $d/emulog.txt) | $(grep -a 'TMBR split' $d/emulog.txt | cut -c14- | head -4 | tr '\n' ' ') | TLB $(grep -c 'TLB Miss' $d/emulog.txt)" >> $L
  grep -a "TMBR perf" $d/emulog.txt | tail -12 | cut -c13- >> $L
done; done; done
echo "SPLIT DONE $(date)" >> $L
exec bash cloud/in/night.sh 4
