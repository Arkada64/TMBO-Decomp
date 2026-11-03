#!/bin/bash
# Working-C boot loop: build with the C drafts, boot a retail match; when the game faults (TLB miss) inside one
# of our C functions, put that function on the skip list (cloud/in/nm_skip.txt) and go again. Stops when a run
# is clean (60 fps lines and no faults), when a fault is outside our C (needs a look), or after N rounds.
#   bash cloud/in/nm_loop.sh N SRC.c ...
cd "/mnt/d/TMB Decomp"
N=$1; shift
touch cloud/in/nm_skip.txt; L=cloud/qb_out/nm_loop.txt; echo "start $(date)" > $L
for r in $(seq 1 $N); do
  tasklist.exe | grep -qi pcsx2 && { echo "round $r: PCSX2 open (someone playing) - stopping" >> $L; break; }
  export NM_SKIP=$(grep -v '^#' cloud/in/nm_skip.txt | awk '{print $1}' | paste -sd, -)
  bash cloud/in/nm_test.sh "$@"
  grep -q NM_DONE cloud/qb_out/nm.txt || { echo "round $r: build failed" >> $L; tail -5 cloud/qb_out/nm.txt >> $L; break; }
  d=$(grep OUT cloud/qb_out/nm_run.txt | awk '{print $2}' | xargs basename 2>/dev/null)
  [ -z "$d" ] && { echo "round $r: no run (see nm_run.txt)" >> $L; break; }
  perf=$(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt)
  pcs=$(grep 'TLB Miss' cloud/qb_out/$d/emulog.txt | sed 's/.*pc=0x\([0-9a-f]*\).*/\1/' | sort | uniq -c | sort -rn | awk '{print $2}' | head -3)
  echo "round $r: run $d, $(grep TOTAL cloud/qb_out/nm.txt | cut -c1-80), perf lines $perf, fault pcs: $pcs" >> $L
  if [ -z "$pcs" ]; then
    [ "$perf" -gt 3 ] && { echo "round $r: CLEAN" >> $L; break; }
    echo "round $r: no faults but no frames either (hang) - needs a look" >> $L; break
  fi
  fn=$(python3 cloud/in/symnm.py $pcs | awk '{print $3}' | head -1)
  case "$fn" in
    *.NON_MATCHING) echo "round $r: fault in asm function $fn (bad data from a C caller?) - needs a look" >> $L; break ;;
  esac
  grep -q "^$fn " cloud/in/nm_skip.txt && { echo "round $r: $fn already skipped - needs a look" >> $L; break; }
  echo "$fn  # faulted at boot $(date +%m-%d) pc $pcs" >> cloud/in/nm_skip.txt
  echo "round $r: skipping $fn" >> $L
done
echo "end $(date)" >> $L
