#!/bin/bash
# RETAIL whole-project draft pass: m2c drafts + standalone matching for every asm/tmb/*.s.
# Resumable (skips files already done). Output per file in logs/drafts/: X.c (drafts),
# X.match.c (matched blocks), X.near.json (same-size near misses, for the permuter later).
# Summary: logs/retail_auto.txt. Usage: bash tools/retail_auto.sh [jobs]   (default 4)
cd ~/tmb_decomp && source .venv/bin/activate
J=${1:-4}
mkdir -p logs/drafts
[ -f logs/ctx/retail_protos.h ] || python3 tools/make_context.py
one() {
  f=$1; n=$(basename "$f" .s); d=logs/drafts
  [ -f "$d/$n.done" ] && exit 0
  python3 tools/auto_m2c.py "$f" "$d/$n.c" > "$d/$n.log" 2>&1
  NEAR_OUT="$d/$n.near.json" python3 tools/fast_match.py "$d/$n.c" "$d/$n.match.c" '' >> "$d/$n.log" 2>&1
  m=$(grep -c "^//@@ " "$d/$n.match.c" 2>/dev/null); m=${m:-0}
  echo "$n: $m matched | $(head -1 "$d/$n.log" | cut -c1-90)" >> logs/retail_auto.txt
  touch "$d/$n.done"
}
export -f one
echo "== start $(date) jobs=$J" >> logs/retail_auto.txt
ls -S -r asm/tmb/*.s | xargs -P "$J" -I{} bash -c 'one {}'
total=$(cat logs/drafts/*.match.c 2>/dev/null | grep -c '^//@@ ')
echo "== RETAIL AUTO DONE $(date): $total functions match standalone" | tee -a logs/retail_auto.txt
