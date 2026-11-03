#!/bin/bash
# retail probe between night runs: build the harness ELF, boot retail TMB minimized with pictures, then the night run
W="/mnt/d/TMB Decomp"; cd "$W"; L=cloud/qb_out/rmp.txt
echo "waiting for a gap $(date)" > $L
while pgrep -f "tools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
sed -i 's/\r$//' cloud/in/retail/rbuild.sh
cp cloud/in/retail/qbrun_r.py tools/qb/qbrun.py
bash cloud/in/retail/rbuild.sh cloud/in/retail/rq_mp.json test/QUICKR.ELF >> $L 2>&1
QB_PADS=4 python3 tools/qb/qbrun.py cloud/in/retail/qb_rmp.json --iso "Twisted Metal - Black.iso" --elf test/QUICKR.ELF > cloud/qb_out/rmp_run.txt 2>&1
tail -3 cloud/qb_out/rmp_run.txt >> $L
d=$(grep OUT cloud/qb_out/rmp_run.txt | awk '{print $2}'); grep -c "TMBR r" $d/emulog.txt >> $L
echo "RMP DONE $d $(date)" >> $L
exec bash cloud/in/night.sh 4
