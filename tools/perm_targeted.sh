#!/bin/bash
# Queued job: permuter aimed ONLY at the 99 functions that use the 8-slot vehicle array (vehicle_funcs.txt),
# with a wider window (up to 30 differing instructions, 10 min each). These are the functions the
# bigger-vehicle-list mod (traffic, more AI) has to change, so getting them into C pays off directly.
# Run it AFTER decomp_run.sh has finished (both use the same build folder).
#   bash "/mnt/d/TMB Decomp/perm_targeted.sh"
#   watch:  tail -f ~/tmbo_decomp/logs/perm_targeted.txt
set -e
W="/mnt/d/TMB Decomp"
cd ~/tmbo_decomp && source .venv/bin/activate
pgrep -f "tools/perm_run" > /dev/null && { echo "another permuter run is still going - wait for it"; exit 1; }
cp "$W/vehicle_funcs.txt" logs/vehicle_funcs.txt
# same tool, plus a filter on the work list (perm_run.py itself is unchanged)
python3 - <<'EOF'
import re
src = open('tools/perm_run.py').read()
anchor = 'todo = sorted((v["diff"], n) for n, v in near.items() if v["diff"] <= MAXD)'
assert anchor in src
src = src.replace(anchor, anchor + '\nONLY = set(open("logs/vehicle_funcs.txt").read().split())\ntodo = [t for t in todo if t[1] in ONLY]')
# own work dir (logs/perm_t): fresh ranking + retries functions the earlier, narrower runs gave up on
src = src.replace('logs/perm"', 'logs/perm_t"').replace('logs/perm/', 'logs/perm_t/')
open('tools/perm_run_targeted.py', 'w').write(src)
EOF
python3 tools/perm_run_targeted.py 30 600 99 4 > logs/perm_targeted.txt 2>&1
rm -f tools/perm_run_targeted.py
git push -q reloaded HEAD:main >> logs/perm_targeted.txt 2>&1 || true
echo; tail -2 logs/perm_targeted.txt
echo "vehicle-array functions still in asm: $(for f in $(cat logs/vehicle_funcs.txt); do grep -rlq "INCLUDE_ASM(.*, $f);" src && echo $f; done | wc -l) / 99"
