#!/bin/bash
# Rebuild every content pack, verify, and make the test disc. Usage: bash buildpacks.sh
set -e
cd "/mnt/d/TMB Decomp"
for p in "FREEWAY ZFP ped" "PRISON ZRP ped"; do
  set -- $p
  python3 mkpack.py $1 $2 $3 > /dev/null
  python3 texpack.py $1 $2 > /dev/null
  python3 mkblobs.py $1 $2 | python3 -c 'import sys,json; d=json.load(sys.stdin); print(d["level"], d["blobs"], "anims", d["anims"], "level anims", d["level_anims"], "classes", d["tex_classes"])'
  python3 verifyblobs.py $2 | tail -2
done
cd packs && rm -f ../test/TMBO_PEDS_TEST.iso
python3 ../mkdisc.py ../test/TMBO_PEDS_TEST.iso ZFP0.BIN ZFP1.BIN ZRP0.BIN ZRP1.BIN ZRP2.BIN 2>/dev/null | tail -1
cd .. && python3 checkdisc.py test/TMBO_PEDS_TEST.iso ZFP0.BIN ZFP1.BIN ZRP0.BIN ZRP1.BIN ZRP2.BIN | tail -1
