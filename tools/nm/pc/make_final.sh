#!/bin/bash
# Final mod-build disc: stop my automation, final_ps2.sh (bots v5 / nav v5 / peds + mktest), then a standalone ISO
# that boots the mod ELF itself: release/TMB Reloaded/TMB Reloaded.iso (label TMB_RELOADED). Restarts the crash loop.
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; cd "$W"; L=cloud/qb_out/final.txt; exec > $L 2>&1
echo "start $(date)"
bash cloud/in/stopall.sh; sleep 5
tasklist.exe | grep -qi pcsx2 && { echo "PCSX2 is open (you are playing?) - not building"; exit 1; }
t0=$(stat -c %Y test/TMBR_TEST.ELF 2>/dev/null || echo 0)
bash cloud/in/final_ps2.sh || exit 1
[ "$(stat -c %Y test/TMBR_TEST.ELF)" -gt "$t0" ] || { echo "TMBR_TEST.ELF was not rebuilt - stopping"; exit 1; }
ls -la test/TMBR_TEST.ELF test/TMBR_TEST.iso
O="release/TMB Reloaded"; mkdir -p "$O"
cp test/TMBR_TEST.iso "$O/TMB Reloaded.iso"
python3 cloud/in/iso_setelf.py "$O/TMB Reloaded.iso" test/TMBR_TEST.ELF TMB_RELOADED
python3 cloud/in/isopad.py "$O/TMB Reloaded.iso"
cp test/TMBR_TEST.ELF "$O/TMB Reloaded.ELF"
python3 cloud/in/isolist.py "$O/TMB Reloaded.iso" | grep -E "SCUS|image" | head -3
ls -la "$O"
echo "FINAL_ISO_DONE $(date)"
nohup bash cloud/in/loop_all.sh 6 > /dev/null 2>&1 &
explorer.exe 'C:\Users\Ark\Desktop\TMB Decomp\release\TMB Reloaded' &
sleep 2
