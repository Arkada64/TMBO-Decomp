#!/bin/bash
# fast_match self-test: every function upstream already matched (combo/font/mathf) must come out MATCH
# when its whole .cpp is compiled as one block.
cd ~/tmb_decomp && source .venv/bin/activate
mkdir -p logs/fast
: > logs/fast/selftest.c
for f in combo font mathf; do
  for n in $(mips-linux-gnu-nm build/src/tmb/$f.cpp.o | awk '$2=="T"{print $3}'); do
    { echo "//@@ $n"; cat src/tmb/$f.cpp; } >> logs/fast/selftest.c
  done
done
grep -c '^//@@' logs/fast/selftest.c
LANG_SRC=c++ python3 tools/fast_match.py logs/fast/selftest.c logs/fast/selftest_out.c '' | grep -v '^matched:'
