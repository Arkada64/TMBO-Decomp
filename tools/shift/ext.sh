cd '/mnt/c/Users/Ark/Desktop/TMB Decomp/test' && source ~/tmbo_decomp/.venv/bin/activate
for v in "$@"; do python3 ../ext.py ss_$v.p2s ss_$v; done
