#!/bin/bash
# stress tests between night rounds: 3 big maps x 7 bots + traffic x EE cycle rate 100 / 130 %, minimized;
# then the night run again. Results: cloud/qb_out/stress.txt (TMBR perf lines per run)
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/stress.txt
echo "waiting for a gap in the night run $(date)" > $L
while pgrep -f "tools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
cp cloud/in/stress/qbrun_ee.py tools/qb/qbrun.py
for m in suburbs freeway prison; do
  for ee in 0 1; do
    QB_EECYCLE=$ee python3 tools/qb/qbrun.py cloud/in/stress/qb_stress_$m.json --iso test/TMBR_TEST.iso --elf test/TMBR_TEST.ELF > cloud/qb_out/stress_run.txt 2>&1
    d=$(grep OUT cloud/qb_out/stress_run.txt | awk '{print $2}')
    echo "== $m EE $ee ($d) bots: $(grep -c 'TMBR bots: car' $d/emulog.txt 2>/dev/null) lobby: $(grep 'lobby setting\|traffic on' $d/emulog.txt | tail -2 | tr '\n' ' ')" >> $L
    grep "TMBR perf" $d/emulog.txt | tail -16 | cut -c13- >> $L
  done
done
echo "night restart $(date)" >> $L
exec bash cloud/in/night.sh 5
