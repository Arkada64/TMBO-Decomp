#!/bin/bash
# all Harbor City cars with their own wheels (hcbuild.py --own-wheels)
cd /home/claude/tmb-reloaded/tools/lost
H=/mnt/user-data/uploads/cloud/hc; G=/mnt/user-data/uploads/cloud/headon/HC_CHROM.BDD
GT="--env bake --add 0x1230,0x3bd0,0x3e0 --skip-tex 8a480,c1fa8,84320"
run() { name=$1; shift; mkdir -p /tmp/claude-0/hc_$name/out; out=$5
  python3 hcbuild.py "$@" --own-wheels > /tmp/claude-0/hc_$name/build_$out.log 2>&1 || echo "FAIL $out"; }
run thumper  $H PCP $H/THUMP.BDD  /tmp/claude-0/hc_thumper/out ZUP
run thumper  $H PCA $H/THUMP.BDD  /tmp/claude-0/hc_thumper/out ZUA --half
run cop      $H DCP $H/COP.BDD    /tmp/claude-0/hc_cop/out ZVP
run cop      $H DCA $H/COP.BDD    /tmp/claude-0/hc_cop/out ZVA --half
run pickup   $H TTP $H/PICKUP.BDD /tmp/claude-0/hc_pickup/out ZXP
run pickup   $H TTA $H/PICKUP.BDD /tmp/claude-0/hc_pickup/out ZXA --half
run pviper   $H SPP $H/PVIPER.BDD /tmp/claude-0/hc_pviper/out ZWP
run pviper   $H SPA $H/PVIPER.BDD /tmp/claude-0/hc_pviper/out ZWA --half
run twister  $H SUP $H/TWIST.BDD  /tmp/claude-0/hc_twister/out ZTP --hide-node 0x67ae0
run twister  $H SUA $H/TWIST.BDD  /tmp/claude-0/hc_twister/out ZTA --half --hide-node 0x5d6a0
run goldtooth $H STP $G /tmp/claude-0/hc_goldtooth/out ZZP $GT --keep-part @0x91c20 --reuse b0448:45,a91b8:49,8dc74:45,9e768:5 --half-keys b0448
run goldtooth $H STA $G /tmp/claude-0/hc_goldtooth/out ZZA $GT --keep-part @0x8a210 --reuse b0448:53,a91b8:57,8dc74:53,9e768:5 --half
