cd ~/tmbo_decomp
echo "== still running:"; pgrep -af "perm_run|fixup|apply_fix" | grep -v pgrep
echo "== permuter:"; tail -2 logs/perm_run3.txt; echo "solved this run: $(grep -c SOLVED logs/perm_run3.txt)"
echo "== fixup 2 (signedness):"; tail -1 logs/fixup2.txt
echo "== apply 2:"; tail -3 logs/apply_fix2.txt
echo "== asm left:"; grep -rhoE '^ *INCLUDE_ASM' src | wc -l; grep -cE '^ *INCLUDE_ASM' src/online/net.c
git log --oneline | head -3
