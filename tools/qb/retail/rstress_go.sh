#!/bin/bash
# retail split-screen stress between night runs: 2/3/4 players on Suburbs at the EE cycle rates given (default 0 = 100 %)
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/rstress.txt; R=cloud/in/retail
echo "waiting for a gap $(date)" >> $L
while pgrep -f "tools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
for ee in ${RATES:-0}; do for n in ${PLAYERS:-2 3 4}; do
  bash $R/rbuild.sh $R/${SCR:-rq_s}$n.json test/QUICKR.ELF > /dev/null 2>&1 || { echo "build failed $n" >> $L; continue; }
  QB_EECYCLE=$ee QB_PADS=4 python3 tools/qb/qbrun.py $R/qb_rs.json --iso "Twisted Metal - Black.iso" --elf test/QUICKR.ELF > cloud/qb_out/rs_run.txt 2>&1
  d=$(grep OUT cloud/qb_out/rs_run.txt | awk '{print $2}')
  echo "== ${SCR:-rq_s} players $n ee $ee $d" >> $L; grep -a "TMBR rperf" $d/emulog.txt | tail -14 | cut -c14- >> $L
done; done
echo "RS DONE $(date)" >> $L
exec bash cloud/in/night.sh 4
