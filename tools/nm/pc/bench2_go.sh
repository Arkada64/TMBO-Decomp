#!/bin/bash
# function test bench, take 2: the plain build (no C, the game's layout untouched) + its mid-match savestate, and
# every draft compiled on its own into a separate image (bench_img.py). Waits for iso_go.sh, then the night run.
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/bench2_go.txt
echo "waiting for the ISO build $(date)" > $L
until grep -q "night restart" cloud/qb_out/iso_go.txt 2>/dev/null; do sleep 30; done
sleep 10; bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
echo "start $(date)" >> $L
cp cloud/in/nm_apply_b2.py cloud/in/nm_apply.py
O=/home/ark/nmhome/bench_o; rm -rf $O
NM_BENCH_OUT=$O QB_KEEP_STATE=1 bash cloud/in/nm_test.sh
grep -E "TOTAL|identical|NM_DONE" cloud/qb_out/nm.txt | tail -3 >> $L
echo "draft objects: $(ls $O | wc -l)" >> $L
d=$(grep OUT cloud/qb_out/nm_run.txt | awk '{print $2}' | xargs basename 2>/dev/null)
mkdir -p cloud/bench; rm -f cloud/bench/*
if [ -n "$d" ] && [ -f cloud/qb_out/$d/state.p2s ]; then
  python3 cloud/in/bench_img.py test/NM_TEST.ELF $O cloud/bench/DRAFTS.ELF >> $L 2>&1
  cp test/NM_TEST.ELF cloud/bench/BASE.ELF; mv cloud/qb_out/$d/state.p2s cloud/bench/state.p2s
  echo "BENCH READY $d (frames $(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt), faults $(grep -c 'TLB Miss' cloud/qb_out/$d/emulog.txt))" >> $L
else echo "no bench state: $(tail -3 cloud/qb_out/nm_run.txt | tr '\n' ' ')" >> $L; fi
echo "night restart $(date)" >> $L
exec bash cloud/in/night.sh 6
