import sys, json, struct
sys.path.insert(0, '.')
from bench import Bench
import os
U = os.environ.get('BENCH_DIR', '/mnt/d/TMB Decomp/cloud/bench') + '/'
frames = int(sys.argv[1])
b = Bench(U + 'BASE.ELF', U + (sys.argv[2] if len(sys.argv) > 2 else 'DRAFTS.ELF'), U + 'state.p2s', per=6, limit=3000000)
g = struct.unpack_from('<I', b.ee.ram, b.syms['D_004FA030'][0] & 0x1FFFFFF)[0]
b.run_root('func_00138C90', (g,))
for f in range(frames):                   # consecutive frames from the snapshot (no reset: the game moves on)
    b.run_root('func_00183580')
res = b.report()
json.dump(res, open('run_%s.json' % (sys.argv[2] if len(sys.argv) > 2 else 'drafts'), 'w'), indent=1)
