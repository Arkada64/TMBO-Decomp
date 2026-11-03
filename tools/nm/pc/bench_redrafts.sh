#!/bin/bash
# recompile every draft for the bench (no boot: the plain build and its snapshot don't change) with the current
# bytefix / hand C, in a private tree (~/benchhome), then link cloud/bench/DRAFTS2.ELF
W="/mnt/d/TMB Decomp"; L="$W/cloud/qb_out/redrafts.txt"
H=/home/ark/benchhome; D=$H/tmbo_decomp; O=$H/bench_o
echo "start $(date)" > "$L"
mkdir -p $H; rsync -a --delete --exclude 'logs/perm*' --exclude 'logs/fast' /home/ark/tmbo_decomp/ $D/
cd $D && git checkout -q -- src
grep -rlI "/home/ark/tmbo_decomp" build.ninja config src tools 2>/dev/null | xargs -r sed -i "s#/home/ark/tmbo_decomp#$D#g"
mkdir -p logs tools/mods logs/hand
cp "$W/mods/apply_mods.py" tools/mods/; cp "$W/cloud/in/nm_apply.py" tools/; cp "$W/cloud/in/bytefix3.py" tools/bytefix.py
cp "$W"/cloud/in/hand/*.c logs/hand/ 2>/dev/null
source .venv/bin/activate
rm -rf $O; HOME=$H NM_BENCH_OUT=$O python3 tools/nm_apply.py 2>&1 | tail -2 >> "$L"
echo "objects: $(ls $O | wc -l)" >> "$L"
python3 "$W/cloud/in/bench_img.py" "$W/cloud/bench/BASE.ELF" $O "$W/cloud/bench/DRAFTS2.ELF" >> "$L" 2>&1
echo "REDRAFTS DONE $(date)" >> "$L"
