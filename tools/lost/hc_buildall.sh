#!/bin/bash
# all Harbor City cars with their own wheels (hcbuild.py --own-wheels)
cd /home/claude/tmb-reloaded/tools/lost
H=/mnt/user-data/uploads/cloud/hc; G=/mnt/user-data/uploads/cloud/headon/HC_CHROM.BDD
GT="--env bake --add 0x1230,0x3bd0,0x3e0 --skip-tex 8a480,c1fa8,84320"
run() { name=$1; shift; mkdir -p /tmp/claude-0/hc_$name/out; out=$5
  python3 hcbuild.py "$@" --own-wheels > /tmp/claude-0/hc_$name/build_$out.log 2>&1 || echo "FAIL $out"; }
# Thumper (Ark 2026-10-26): guns at its own two barrels (front, on the hood), Brimstone's special / zealot hidden
export HC_MG_DONOR=2.35,7.40,0.37
run thumper  $H PCP $H/THUMP.BDD  /tmp/claude-0/hc_thumper/out ZUP --hide-ids 4006,4011 --hide-node 0x427b0
run thumper  $H PCA $H/THUMP.BDD  /tmp/claude-0/hc_thumper/out ZUA --half --hide-ids 4006,4011 --hide-node 0x3bd30
unset HC_MG_DONOR
run cop      $H DCP $H/COP.BDD    /tmp/claude-0/hc_cop/out ZVP
run cop      $H DCA $H/COP.BDD    /tmp/claude-0/hc_cop/out ZVA --half
# Outlaw 2's siren lights: Outlaw's beacons on his light bar, alternated by mods/skins.c (Ark 2026-10-27)
python3 sirens.py /tmp/claude-0/hc_cop/out ZVP; python3 sirens.py /tmp/claude-0/hc_cop/out ZVA
# Old Pickup (Ark 2026-10-26: "still has pieces of Junkyard Dog"): JD's roof lamp box and its long roof beam hidden
# (Ark 2026-10-26 23:09: the spawn shield hides parts of it) shells 1.0 outside the body box instead of 0.4
export HC_SHELL_MARGIN=1.0
run pickup   $H TTP $H/PICKUP.BDD /tmp/claude-0/hc_pickup/out ZXP --hide-node 0x69b30,0x628e0
run pickup   $H TTA $H/PICKUP.BDD /tmp/claude-0/hc_pickup/out ZXA --half --hide-node 0x62e80,0x5bc30
unset HC_SHELL_MARGIN
run pviper   $H SPP $H/PVIPER.BDD /tmp/claude-0/hc_pviper/out ZWP
run pviper   $H SPA $H/PVIPER.BDD /tmp/claude-0/hc_pviper/out ZWA --half
# Twister (Ark 2026-10-26): no gun on the model - the guns beside the nose, above the front wing
export HC_MG_DONOR=0.9,7.2,-2.7
run twister  $H SUP $H/TWIST.BDD  /tmp/claude-0/hc_twister/out ZTP --hide-node 0x67ae0
run twister  $H SUA $H/TWIST.BDD  /tmp/claude-0/hc_twister/out ZTA --half --hide-node 0x5d6a0
unset HC_MG_DONOR
run goldtooth $H STP $G /tmp/claude-0/hc_goldtooth/out ZZP $GT --head 0x1230,0x3bd0:@0x50800 --glow 0x3bd0 --skip 0x197c0 --robot 0x45a60:@0x91c20 --robot-far 0x2a820:@0x94160 --reuse b0448:45,a91b8:49,8dc74:45,9e768:5 --half-keys b0448
run goldtooth $H STA $G /tmp/claude-0/hc_goldtooth/out ZZA $GT --head 0x1230,0x3bd0:@0x4efc0 --glow 0x3bd0 --skip 0x197c0 --robot 0x45a60:@0x8a210 --robot-far 0x2a820:@0x8c750 --reuse b0448:53,a91b8:57,8dc74:53,9e768:5 --half
