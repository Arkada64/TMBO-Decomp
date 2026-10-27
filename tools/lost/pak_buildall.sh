#!/bin/bash
# 12 Pak on Roadkill, both copies (pakbuild.py, own wheels): /tmp/claude-0/pak_own/out/ZYP.* (RKP) and ZYA.* (RKA)
cd /home/claude/tmb-reloaded/tools/lost
H=/mnt/user-data/uploads/cloud/hc; B=/mnt/user-data/uploads/cloud/headon/HC_STOCK.BDD; O=/tmp/claude-0/pak_own
mkdir -p $O/rkp $O/rka $O/out $O/tmpp $O/tmpa
for e in NGP PTR TEX RTX; do cp -f $H/RKP.$e $O/rkp/STP.$e; cp -f $H/RKA.$e $O/rka/STP.$e; done
PAK_OWNWHEELS=1 python3 pakbuild.py $O/rkp $B $O/tmpp > $O/build_ZYP.log 2>&1 || echo "FAIL ZYP"
PAK_OWNWHEELS=1 PAK_ACAR=1 python3 pakbuild.py $O/rka $B $O/tmpa > $O/build_ZYA.log 2>&1 || echo "FAIL ZYA"
for e in NGP PTR TEX RTX; do mv -f $O/tmpp/STP.$e $O/out/ZYP.$e; mv -f $O/tmpa/STP.$e $O/out/ZYA.$e; done
rmdir $O/tmpp $O/tmpa
