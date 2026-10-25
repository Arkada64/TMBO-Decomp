#!/bin/bash
# Unattended working-C cleanup (run while nobody is playing):  bash cloud/in/night.sh [HOURS]   (default 10)
# Repeats until the all-files C build boots clean, the time runs out, or someone opens PCSX2:
#   1. build every file's C drafts (minus cloud/in/nm_skip.txt) and boot-test a match (nm_test.sh, ~25 min)
#   2. clean (frames logged, no TLB faults)                         -> done
#   3. the first fault is inside one of our C functions             -> skip it, go again (1 round)
#   4. otherwise (fault in asm, hang, exit): halve the files with C until one file is left, then halve that
#      file's functions until one is left (bisect)                  -> skip it, go again
# Every skip is a line in cloud/in/nm_skip.txt with the reason. Log: cloud/qb_out/night.txt (opens in Notepad).
cd "/mnt/c/Users/Ark/Desktop/TMB Decomp"
L=cloud/qb_out/night.txt; NH=/home/ark/nmhome/tmbo_decomp
END=$(( $(date +%s) + ${1:-10} * 3600 ))
echo "start $(date), until $(date -d @$END)" > $L
touch cloud/in/nm_skip.txt
skips() { grep -v '^#' cloud/in/nm_skip.txt | awk '{print $1}' | paste -sd, -; }
playing() { tasklist.exe | grep -qi pcsx2; }
timeup() { [ $(date +%s) -ge $END ]; }

# run_test EXTRA_SKIPS FILE... : build + boot. Sets RES (clean / fault / hang / nobuild) and PCS (fault pcs).
run_test() {
  local extra=$1; shift
  RES=nobuild; PCS=""
  NM_SKIP="$(skips)${extra:+,$extra}" bash cloud/in/nm_test.sh "$@" > /dev/null 2>&1
  grep -q NM_DONE cloud/qb_out/nm.txt || { echo "    build failed: $(grep -vE '^\s*$' cloud/qb_out/nm.txt | tail -2 | tr '\n' ' ')" >> $L; return; }
  local d=$(grep OUT cloud/qb_out/nm_run.txt 2>/dev/null | awk '{print $2}' | xargs basename 2>/dev/null)
  [ -z "$d" ] && { RES=hang; echo "    no run (PCSX2 did not start?)" >> $L; return; }
  local p=$(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt) t=$(grep -c 'TLB Miss' cloud/qb_out/$d/emulog.txt)
  PCS=$(grep 'TLB Miss' cloud/qb_out/$d/emulog.txt | head -1 | sed 's/.*pc=0x\([0-9a-f]*\).*/\1/')
  if [ "$t" -gt 0 ]; then RES=fault; elif [ "$p" -gt 3 ]; then RES=clean; else RES=hang; fi
  echo "    run $d: $RES (frames $p, faults $t${PCS:+, first pc $PCS})" >> $L
}

# the files that get C (summary of the last full build)
files_with_c() {
  python3 - "$NH/logs/nm/summary.json" <<'P'
import json, sys
s = json.load(open(sys.argv[1]))["files"]
print(" ".join(f for f, v in sorted(s.items()) if v["used"] > 0))
P
}

round=0
while ! timeup; do
  playing && { echo "PCSX2 is open - stopping (someone is playing) $(date)" >> $L; break; }
  round=$((round + 1)); echo "round $round $(date +%H:%M): all files" >> $L
  run_test "" ; [ $RES = nobuild ] && break
  ALL=($(files_with_c)); echo "    files with C: ${#ALL[@]}, skipped drafts: $(skips | tr ',' '\n' | grep -c .)" >> $L
  [ $RES = clean ] && { echo "CLEAN: the all-files C build boots to a match $(date)" >> $L; break; }
  if [ $RES = fault ] && [ -n "$PCS" ]; then
    fn=$(python3 cloud/in/symnm.py $PCS | awk '{print $3}' | head -1)
    case "$fn" in
      ""|*.NON_MATCHING) ;;                                    # asm: the bad data came from a caller - bisect
      *) if ! grep -q "^$fn " cloud/in/nm_skip.txt; then
           echo "$fn  # night $(date +%m-%d): fault pc $PCS inside it" >> cloud/in/nm_skip.txt
           echo "    skip $fn (fault inside it)" >> $L; continue
         fi ;;
    esac
  fi
  # bisect the files
  cand=("${ALL[@]}"); echo "  bisecting ${#cand[@]} files ($RES)" >> $L
  while [ ${#cand[@]} -gt 1 ] && ! timeup && ! playing; do
    h=$(( ${#cand[@]} / 2 )); A=("${cand[@]:0:$h}"); B=("${cand[@]:$h}")
    echo "  files ${#A[@]} of ${#cand[@]}: ${A[0]} .. ${A[$((h-1))]}" >> $L
    run_test "" "${A[@]}"
    if [ $RES = clean ]; then
      run_test "" "${B[@]}"
      if [ $RES = clean ]; then echo "  both halves boot alone: the fault needs C in both - stopping the bisect" >> $L; cand=(); break; fi
      cand=("${B[@]}")
    else cand=("${A[@]}"); fi
  done
  [ ${#cand[@]} -ne 1 ] && { echo "  no single file found - stopping $(date)" >> $L; break; }
  F=${cand[0]}; echo "  culprit file: $F" >> $L
  # bisect that file's functions (their NM markers in the private copy: the last bisect build had that file)
  fn=($(grep -o 'NM:[A-Za-z0-9_]*' "$NH/$F" | cut -c4-)); echo "  bisecting ${#fn[@]} functions in $F" >> $L
  while [ ${#fn[@]} -gt 1 ] && ! timeup && ! playing; do
    h=$(( ${#fn[@]} / 2 )); A=("${fn[@]:0:$h}"); B=("${fn[@]:$h}")
    run_test "$(IFS=,; echo "${B[*]}")" "$F"                 # only the first half in C
    if [ $RES = clean ]; then fn=("${B[@]}"); else fn=("${A[@]}"); fi
  done
  [ ${#fn[@]} -ne 1 ] && { echo "  stopped before one function was left" >> $L; break; }
  echo "${fn[0]}  # night $(date +%m-%d): bisect in $F" >> cloud/in/nm_skip.txt
  echo "    skip ${fn[0]} (bisect)" >> $L
done
echo "end $(date): $(skips | tr ',' '\n' | grep -c .) drafts skipped in total" >> $L
notepad.exe 'C:\Users\Ark\Desktop\TMB Decomp\cloud\qb_out\night.txt' &
sleep 3
