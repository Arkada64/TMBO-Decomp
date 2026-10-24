#!/bin/bash
# working-C build of the given files + a quick-boot match on retail Snowy Roads with it
cd "/mnt/c/Users/Ark/Desktop/TMB Decomp"
rm -f cloud/qb_out/nm_done.txt
bash cloud/in/nm_build.sh "$@" > cloud/qb_out/nm.txt 2>&1
if grep -q NM_DONE cloud/qb_out/nm.txt; then
  python3 tools/qb/qbrun.py cloud/in/qb_su.json --iso test/TMBR_TEST.iso --elf test/NM_TEST.ELF > cloud/qb_out/nm_run.txt 2>&1
fi
echo done > cloud/qb_out/nm_done.txt
