#!/bin/bash
# RETAIL: move standalone matches into the real build, every segment that has any.
#  1. turn each such `asm` text segment into a `c` segment (splat writes src/tmb/X.c with INCLUDE_ASM)
#  2. check the all-INCLUDE_ASM build is byte-identical; if not, fall back to one segment at a time
#  3. integrate.py per segment (bisects on failure), commit per segment
# Resumable. Log: logs/retail_integrate.txt. Usage: bash tools/retail_integrate.sh
cd ~/tmb_decomp && source .venv/bin/activate
Y=config/US/SCUS_971.01.yaml; L=logs/retail_integrate.txt
T=$'\n\nCo-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>\nClaude-Session: https://claude.ai/code/session_01NDPuYvF2UhuQVqWzE5yi2a'
sha_ok() { rm -f build/*.rom; ninja > logs/ninja.log 2>&1 && \
  [ "$(sha1sum build/SCUS_971.01.rom | cut -d' ' -f1)" = "$(grep -m1 '^sha1:' $Y | cut -d' ' -f2)" ]; }
regen() { ./configure.py split > logs/split.log 2>&1 && ./configure.py generate > logs/generate.log 2>&1; }
segs=()
for m in logs/drafts/*.match.c; do
  n=$(basename "$m" .match.c)
  grep -q '^//@@ ' "$m" || continue
  grep -q "^      - \[0x[0-9A-F]*, asm, tmb/$n\]" $Y && segs+=("$n")
done
echo "== start $(date): ${#segs[@]} segments to convert" | tee -a $L
cp $Y logs/yaml.bak
for n in "${segs[@]}"; do sed -i "s|^\(      - \[0x[0-9A-F]*\), asm, tmb/$n\]|\1, c, tmb/$n]|" $Y; done
regen
if sha_ok; then
  echo "bulk conversion builds byte-identical" | tee -a $L
  git add -A src $Y && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Retail: convert ${#segs[@]} segments to C (INCLUDE_ASM)$T"
else
  echo "bulk conversion NOT byte-identical; converting one at a time" | tee -a $L
  cp logs/yaml.bak $Y; git checkout -q -- src; git clean -fq src; regen
  for n in "${segs[@]}"; do
    sed -i "s|^\(      - \[0x[0-9A-F]*\), asm, tmb/$n\]|\1, c, tmb/$n]|" $Y; regen
    if sha_ok; then echo "$n: converted" | tee -a $L
      git add -A src $Y && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Retail: convert tmb/$n to C (INCLUDE_ASM)$T"
    else echo "$n: conversion breaks the build, skipped" | tee -a $L
      git checkout -q -- $Y; rm -f src/tmb/$n.c; regen
    fi
  done
fi
total=0
for n in "${segs[@]}"; do
  [ -f src/tmb/$n.c ] || continue
  out=$(python3 tools/integrate.py "$n" 2>&1 | tail -1); echo "$out" | tee -a $L
  k=$(echo "$out" | sed -n 's/.*: \([0-9]*\)\/.*/\1/p')
  if [ "${k:-0}" -gt 0 ] && echo "$out" | grep -q 'byte-identical: True'; then
    total=$((total + k))
    git add -A src && git -c user.name=tmbo -c user.email=tmbo@localhost commit -q --no-verify -m "Retail: match $k functions in tmb/$n$T"
  fi
done
sha_ok && ok=True || ok=False
echo "== RETAIL INTEGRATE DONE $(date): $total functions in the build; byte-identical: $ok" | tee -a $L
