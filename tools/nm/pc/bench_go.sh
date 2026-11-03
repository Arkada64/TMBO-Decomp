#!/bin/bash
# function test bench snapshot: stop the night run, build with every draft linked beside its asm (NM_BENCH=1),
# boot a match with it and keep the mid-match savestate, then restart the night run.
cd "/mnt/d/TMB Decomp"
L=cloud/qb_out/bench_go.txt
echo "start $(date)" > $L
bash cloud/in/stopall.sh >> $L 2>&1
sleep 5
cp cloud/in/nm_apply_b1.py cloud/in/nm_apply.py
cp cloud/in/qbrun_b1.py tools/qb/qbrun.py
NM_BENCH=1 QB_KEEP_STATE=1 bash cloud/in/nm_test.sh
grep -E "TOTAL|NM_DONE|identical|rror" cloud/qb_out/nm.txt | tail -5 >> $L
d=$(grep OUT cloud/qb_out/nm_run.txt | awk '{print $2}' | xargs basename 2>/dev/null)
if [ -n "$d" ] && [ -f cloud/qb_out/$d/state.p2s ]; then
  cp test/NM_TEST.ELF cloud/qb_out/$d/BENCH.ELF
  echo "BENCH READY $d (frames $(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt), faults $(grep -c 'TLB Miss' cloud/qb_out/$d/emulog.txt))" >> $L
  mkdir -p cloud/bench; rm -f cloud/bench/*; cp cloud/qb_out/$d/state.p2s cloud/qb_out/$d/BENCH.ELF cloud/bench/
else
  echo "no bench state: $(tail -3 cloud/qb_out/nm_run.txt | tr '\n' ' ')" >> $L
fi
echo "night restart $(date)" >> $L
exec bash cloud/in/night.sh 6
