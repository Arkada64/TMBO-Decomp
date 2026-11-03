#!/bin/bash
# Overnight (2026-10-24): after the view.c bisect finishes, put working C into every file that has drafts,
# check the normal build stays byte-identical, build the C version (test/NM_TEST.ELF), boot-test it once,
# then resume the permuter. Log: cloud/qb_out/overnight.txt
cd "/mnt/d/TMB Decomp"
L=cloud/qb_out/overnight.txt; echo "start $(date)" > $L
while pgrep -f nm_bisect.sh > /dev/null; do sleep 60; done
echo "bisect done $(date): $(grep CULPRIT cloud/qb_out/nm_bisect.txt)" >> $L
export NM_SKIP=$(grep -v '^#' cloud/in/nm_skip.txt | awk '{print $1}' | paste -sd, -)
bash cloud/in/nm_build.sh > cloud/qb_out/nm_all.txt 2>&1
grep -E "TOTAL|byte-identical|NOT identical|NM_DONE|FAILED|Error|error:" cloud/qb_out/nm_all.txt | grep -v warning | head -20 >> $L
cp /home/ark/nmhome/tmbo_decomp/logs/nm/summary.json cloud/qb_out/nm_all_summary.json 2>/dev/null
if grep -q NM_DONE cloud/qb_out/nm_all.txt && ! tasklist.exe | grep -qi pcsx2; then
  python3 tools/qb/qbrun.py cloud/in/qb_su.json --iso test/TMBR_TEST.iso --elf test/NM_TEST.ELF > cloud/qb_out/nm_all_run.txt 2>&1
  d=$(grep OUT cloud/qb_out/nm_all_run.txt | awk '{print $2}' | xargs basename 2>/dev/null)
  [ -n "$d" ] && echo "boot test $d: qb steps $(grep -c 'TMBR qb' cloud/qb_out/$d/emulog.txt), perf $(grep -c 'TMBR perf' cloud/qb_out/$d/emulog.txt), tlb $(grep -c 'TLB Miss' cloud/qb_out/$d/emulog.txt)" >> $L
fi
bash cloud/in/permpause.sh CONT > /dev/null 2>&1
echo "permuter resumed; end $(date)" >> $L
