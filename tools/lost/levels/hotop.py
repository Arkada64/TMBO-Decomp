import sys, numpy as np
sys.path.insert(0, '/home/claude/hc'); sys.path.insert(0, '/home/claude/lost')
from hotx import walk
from homesh import decode, triangles
from horender import render
def world_tris(n):
    ms, st, unk = walk(n); out = []
    for o, M in ms:
        # op0 node -> its DMA packet: the 'ret' tag after the header
        q = o
        while q < o + 0x400 and not ((int.from_bytes(n[q:q+4], 'little') >> 16) == 0x6000 and int.from_bytes(n[q+4:q+8], 'little') == 0): q += 16
        try: m = decode(n, q)
        except Exception: continue
        P = np.array(m['pos'], float)
        if not len(P): continue
        W = np.c_[P, np.ones(len(P))] @ M
        for (a, _), (b, _), (c, _) in triangles(m): out.append((W[a, :3], W[b, :3], W[c, :3]))
    return np.array(out)
if __name__ == '__main__':
    for f in sys.argv[1:]:
        n = open(f'/home/claude/hc/{f}.ngp', 'rb').read()
        T = world_tris(n)
        e = np.max(np.abs(T - np.roll(T, 1, axis=1)).sum(2), 1)
        T = T[e < 1500]
        print(f, len(T), render(T, f'/home/claude/hc/{f}_top.png'))
