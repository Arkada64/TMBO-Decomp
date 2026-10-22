#!/bin/bash
# tools/make_tester_patch.sh: package the last build_shiftable.sh release for testers.
# Output (in the TMB Decomp folder, release/): TMBR_<version>.bps + README.txt
#  - The .bps turns the tester's OWN original SCUS_971.96 (copied off their disc) into the TMB-Reloaded ELF.
#  - Apply with Floating IPS (Flips) or any BPS patcher; then boot with PCSX2: pcsx2-qt -elf TMBR.elf -- <disc>
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"
cd ~/tmbo_decomp && source .venv/bin/activate
[ -f build/TMBR.elf ] || { echo "run tools/build_shiftable.sh first"; exit 1; }
V=$(cat build/TMBR.version); TAG=$(echo "$V" | awk '{print $2}')
mkdir -p "$W/release"
python3 tools/mods/bps.py make disks/SCUS_971.96 build/TMBR.elf "$W/release/TMBR_$TAG.bps"
cat > "$W/release/README.txt" <<EOF
$V

1. Copy SCUS_971.96 off your Twisted Metal: Black Online disc (NTSC-U, SCUS-97196).
2. Patch it with TMBR_$TAG.bps using Floating IPS (Flips) or any BPS patcher -> TMBR.elf
   (the patcher refuses if your SCUS_971.96 is not the original)
3. Boot: pcsx2-qt.exe -elf "path\to\TMBR.elf" -- "path\to\your disc image"
Everyone in a lobby must use the same build ($TAG).
Built in: revival server DNS, bugfixes & improvements, skip intros, 16:9 (set PCSX2 to 16:9),
community balance (Axel / Crazy 8 / Warthog), TMA rules (no ENV pickups, no health pickups - always on,
no button toggle). Respawn Shield (TMA rules: longer spawn shield).
Quick moves: hold L1 + d-pad Up = freeze, Right = shield, Left = mine, Down = rear fire;
hold R1 + d-pad Right = charged mine, Left = invisibility. The old combos still work.
Free cam when spectating: left stick move, right stick look, L2/R2 down/up, hold R1 faster, Select = normal view.
Default camera is the 2nd view (what Select+Down gave you before).
L1/R1 switch weapons only on a quick tap; holding them (for a quick move or not) never switches; L1+R1 together still jumps.
You do NOT need the community .pnach for this build (PCSX2 won't apply it to a modded ELF anyway).
EOF
ls -la "$W/release"
