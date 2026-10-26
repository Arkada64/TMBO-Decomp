#!/bin/bash
# map the multiplayer level list: kill the running stress loop, one 3P run pressing RIGHT on the level screen with pictures
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/rlvl.txt; R=cloud/in/retail
echo "start $(date)" > $L
pkill -f rstress_go.sh; pkill -INT -f "qbrun.py cloud/in/retail"; sleep 20
while pgrep -f "tools/qb/qbrun.py" > /dev/null; do sleep 10; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
bash $R/rbuild.sh $R/rq_lvl.json test/QUICKR.ELF >> $L 2>&1
QB_PADS=4 python3 tools/qb/qbrun.py $R/qb_rlvl.json --iso "Twisted Metal - Black.iso" --elf test/QUICKR.ELF > cloud/qb_out/rl_run.txt 2>&1
d=$(grep OUT cloud/qb_out/rl_run.txt | awk '{print $2}')
echo "RL DONE $d $(date)" >> $L
exec bash cloud/in/night.sh 4
