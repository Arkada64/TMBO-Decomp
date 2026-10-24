"""Spawn / respawn points for a converted map. TMB picks start and respawn points from the level's PTS points
(attractor points: gameCheckStartPoint -> attractGetRandomTransPoint = a random linked neighbour of a point).
The donor level's PTS keeps its link structure; every used point is moved onto a Head-On AI path point (on the
drivable routes), cycling through them. The PUP (100 power-up spots, 20-byte records after an 8-byte header)
gets the same treatment.
  python3 ptsconv.py HC_xx.BDD DONOR.PTS DONOR.PUP OUT.PTS OUT.PUP [scale]"""
import sys, struct
import numpy as np
sys.path.insert(0, '/home/claude/lost')
from bdd import bdd
def ho_points(b, scale):
    p = b['pts']; n = struct.unpack_from('<I', p, 4)[0]
    return np.array([struct.unpack_from('<3f', p, 16 + 32 * i) for i in range(n)]) * scale
def convert(b, dpts, dpup, scale=1.15):
    H = ho_points(b, scale)
    out = bytearray(dpts); k = 0
    for i in range(480):
        x, y, z = struct.unpack_from('<3f', out, 32 * i)
        if x == 0 and y == 0 and z == 0: continue
        struct.pack_into('<3f', out, 32 * i, *(H[k % len(H)] + [0, 0, 4.0])); k += 1
    pup = bytearray(dpup); n = struct.unpack_from('<I', pup, 4)[0]
    rng = np.random.default_rng(1)
    for i in range(n):
        q = H[(i * 7) % len(H)] + np.r_[rng.uniform(-30, 30, 2), 4.0]
        struct.pack_into('<3f', pup, 8 + 20 * i, *q)
    return bytes(out), bytes(pup), k, len(H)
if __name__ == '__main__':
    sc = float(sys.argv[6]) if len(sys.argv) > 6 else 1.15
    a, p, k, h = convert(bdd(sys.argv[1]), open(sys.argv[2], 'rb').read(), open(sys.argv[3], 'rb').read(), sc)
    open(sys.argv[4], 'wb').write(a); open(sys.argv[5], 'wb').write(p)
    print(sys.argv[4], k, 'points moved onto', h, 'Head-On path points')
