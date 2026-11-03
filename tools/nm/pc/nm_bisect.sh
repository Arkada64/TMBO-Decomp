#!/bin/bash
# Find the C draft that breaks a boot test when the failure points at no function (hang, exit to the BIOS):
# halve the drafts in use until one is left, put it on cloud/in/nm_skip.txt.  bash nm_bisect.sh SRC.c ...
cd "/mnt/d/TMB Decomp"
L=cloud/qb_out/nm_bisect.txt; echo "start $(date)" > $L
base=$(grep -v '^#' cloud/in/nm_skip.txt | awk '{print $1}' | paste -sd, -)
cand=$(for f in "$@"; do grep -o 'NM:[A-Za-z0-9_]*' "$f" | cut -c4-; done)
# (the files were applied by the last build: their NM markers list the drafts in use)
test_skip() {      # $1 = extra skips (comma list); returns 0 when the run is clean
  tasklist.exe | grep -qi pcsx2 && { echo "PCSX2 open - stopping" >> $L; exit 1; }
  NM_SKIP="$base,$1" bash cloud/in/nm_test.sh "${files[@]}" > /dev/null 2>&1
  d=$(grep OUT cloud/qb_out/nm_run.txt | awk '{print $2}' | xargs basename 2>/dev/null)
  [ -z "$d" ] && return 1
  p=$(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt); t=$(grep -c 'TLB Miss' cloud/qb_out/$d/emulog.txt)
  echo "  run $d: perf $p, tlb $t" >> $L
  [ "$p" -gt 3 ] && [ "$t" -eq 0 ]
}
files=("$@")
set -- $cand; n=$#
echo "candidates ($n): $cand" >> $L
while [ $n -gt 1 ]; do
  h=$((n / 2)); first=$(echo $cand | tr ' ' '\n' | head -$h | paste -sd' ' -); second=$(echo $cand | tr ' ' '\n' | tail -n +$((h + 1)) | paste -sd' ' -)
  echo "testing with only the first half in C: $first" >> $L
  set -- "${files[@]}"
  if test_skip "$(echo $second | tr ' ' ',')"; then cand=$second; else cand=$first; fi
  set -- $cand; n=$#
  echo "-> culprit among ($n): $cand" >> $L
done
echo "$cand  # bisect $(date +%m-%d): broke the boot test without a fault pc" >> cloud/in/nm_skip.txt
echo "CULPRIT $cand" >> $L; echo "end $(date)" >> $L
