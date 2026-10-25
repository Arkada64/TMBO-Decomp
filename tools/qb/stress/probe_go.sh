#!/bin/bash
# stress-test probes between night rounds: level list + lobby flow pictures (minimized), then the night run again
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/probe.txt
echo "waiting for a gap in the night run $(date)" > $L
while pgrep -f "tools/qb/qbrun.py" > /dev/null; do sleep 15; done
bash cloud/in/stopall.sh > /dev/null 2>&1; sleep 5
cp cloud/in/stress/qbrun_pics.py tools/qb/qbrun.py
for s in qb_levels qb_lobbyflow; do
  python3 tools/qb/qbrun.py cloud/in/stress/$s.json --iso test/TMBR_TEST.iso --elf test/TMBR_TEST.ELF > cloud/qb_out/probe_$s.txt 2>&1
  echo "$s: $(grep OUT cloud/qb_out/probe_$s.txt)" >> $L
done
echo "night restart $(date)" >> $L
exec bash cloud/in/night.sh 5
