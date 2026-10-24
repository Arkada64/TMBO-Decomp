import sys, struct, collections
sys.path.insert(0, '/home/claude/lost')
from bdd import bdd
from hocollect import collect
def walk(path):
    b = bdd(path); n = b['ngp']; u = lambda o: struct.unpack_from('<I', n, o)[0]
    ne = u(0); eps = [u(4 + 4 * i) for i in range(ne)]
    out = {}
    for e in eps:
        log = []
        collect(n, e, log=log)
        ops = collections.Counter(op for d, o, op, k in log)
        out[e] = (u(e) & 0x3f, ops, len(log))
    return b, eps, out
if __name__ == '__main__':
    for f in sys.argv[1:]:
        b, eps, out = walk(f)
        print(f.split('/')[-1], 'entries', [hex(e) for e in eps])
        for e, (op, ops, nn) in out.items():
            print('  %x op%d: %d nodes %s' % (e, op, nn, dict(sorted(ops.items()))))
