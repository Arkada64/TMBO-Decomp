#!/bin/bash
# Working-C status run (no PCSX2): newest tools from GitHub main, every compiling draft in as NON_MATCHING,
# normal build byte-identical, NM shiftable ELF built -> D:\TMB Decomp\test\NM_TEST.ELF. Log: cloud/out/nm_go.txt
# (copy of D:\TMB Decomp\cloud\in\nm2\nm_go.sh, 2026-10-31; takes ~25 min)
W="/mnt/d/TMB Decomp"; L="$W/cloud/out/nm_go.txt"; T=/home/ark/nmtools
echo "start $(date)" > "$L"
cd ~/tmbo_decomp && git fetch -q reloaded >> "$L" 2>&1 || echo "fetch failed" >> "$L"
rm -rf $T; mkdir -p $T && git archive reloaded/main tools/nm_apply.py tools/nm_ld.py tools/nm_build.sh tools/nm tools/qb | tar -x -C $T || { echo "archive failed" >> "$L"; exit 1; }
cd $T/tools
sed -i 's#/mnt/c/Users/Ark/Desktop/TMB Decomp#/mnt/d/TMB Decomp#g' nm_build.sh
sed -i "s#cp \"\$W/cloud/in/nm_apply.py\" tools/#cp $T/tools/nm_apply.py tools/#; s#cp \"\$W/cloud/in/bytefix.py\" tools/#cp $T/tools/nm/bytefix.py tools/#; s#cp \"\$W\"/cloud/in/hand/\*.c logs/hand/#cp $T/tools/nm/hand/*.c logs/hand/#; s#cp \"\$W/cloud/in/nm_ld.py\" tools/#cp $T/tools/nm_ld.py tools/#" nm_build.sh
bash nm_build.sh >> "$L" 2>&1
python3 - >> "$L" 2>&1 <<'PY'
import json; s=json.load(open('/home/ark/nmhome/tmbo_decomp/logs/nm/summary.json')); print('TOTAL', s['total'])
PY
echo "NMGO DONE $(date)" >> "$L"
