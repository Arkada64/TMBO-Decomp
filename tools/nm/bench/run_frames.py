import sys, json, struct
sys.path.insert(0, '.')
from bench import Bench
U = '/mnt/user-data/uploads/cloud/bench/'
frames = int(sys.argv[1])
b = Bench(U + 'BASE.ELF', U + 'DRAFTS.ELF', U + 'state.p2s', per=6, limit=3000000)
g = struct.unpack_from('<I', b.ee.ram, b.syms['D_004FA030'][0] & 0x1FFFFFF)[0]
b.run_root('func_00138C90', (g,))
for f in range(frames):                   # consecutive frames from the snapshot (no reset: the game moves on)
    b.run_root('func_00183580')
res = b.report()
json.dump(res, open('run4.json', 'w'), indent=1)
