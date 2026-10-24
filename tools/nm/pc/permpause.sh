#!/bin/bash
# permpause.sh STOP|CONT : pause / resume the permuter run (all its processes)
for p in $(pgrep -f "perm_run|permuter|ee-gcc|cc1|decomp-permuter"); do [ "$p" != $$ ] && kill -$1 $p 2>/dev/null; done
ps -eo stat,cmd | grep -E "perm_run.py" | grep -v grep | cut -c1-50
