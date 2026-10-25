# callers of a function in an ELF (jal scan): callgraph.py ELF name [depth]
import sys, struct, bisect
sys.path.insert(0, '.')
from bench import elf_symbols
d = open(sys.argv[1], 'rb').read()
s = elf_symbols(sys.argv[1])
fun = sorted((v, n) for n, (v, sz, t) in s.items() if t == 2 and not n.endswith('.NON_MATCHING'))
fa = [a for a, _ in fun]
phoff, = struct.unpack_from('<I', d, 0x1C)
t, off, va, pa, fs, ms = struct.unpack_from('<IIIIII', d, phoff)
calls = {}
for o in range(0, fs, 4):
    w = struct.unpack_from('<I', d, off + o)[0]
    if w >> 26 == 3:
        tgt = ((va + o) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
        k = bisect.bisect_right(fa, va + o) - 1
        calls.setdefault(tgt, set()).add(fun[k][1])
def up(name, depth, pad=''):
    if depth < 0: return
    cs = sorted(calls.get(s[name][0], ()))
    print(pad + name, '<-', ', '.join(cs[:8]) + (' ...' if len(cs) > 8 else ''))
    for c in cs[:4]: up(c, depth - 1, pad + '  ')
up(sys.argv[2], int(sys.argv[3]) if len(sys.argv) > 3 else 4)
