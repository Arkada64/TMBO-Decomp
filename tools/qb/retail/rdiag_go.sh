#!/bin/bash
W="/mnt/d/TMB Decomp"; cd "$W"; L=cloud/qb_out/rdiag.txt; R=cloud/in/retail
echo "waiting $(date)" > $L
while pgrep -f "tools/qb/qbrun.py" > /dev/null || pgrep -f rstress_go > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
cp $R/retail_qb_v3.c $R/retail_qb.c
bash $R/rbuild.sh $R/rq_diag.json test/QUICKR.ELF >> $L 2>&1
QB_PADS=4 python3 tools/qb/qbrun.py $R/qb_rdiag.json --iso "Twisted Metal - Black.iso" --elf test/QUICKR.ELF > cloud/qb_out/rd_run.txt 2>&1
d=$(grep OUT cloud/qb_out/rd_run.txt | awk '{print $2}')
grep -a "TMBR r" $d/emulog.txt | cut -c14- | tail -20 >> $L
echo "RD DONE $d $(date)" >> $L
exec bash cloud/in/night.sh 4
