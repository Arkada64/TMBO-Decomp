"""ASYLUM.PED / SHIP.PED for the online maps that ship without ped spawn groups (their .PED table entries are empty):
one small walking ring around each of up to 20 well spread pickup spots (.PKP = where pickups sit, i.e. open
ground the cars reach). Entries: the inmates packed from retail PRISON (types 9-11, PRISON's behaviours) plus
the level's own type 2.
  python3 mkped.py LEVEL.PKP OUT.PED"""
import sys, struct, math
import numpy as np

MAGIC_PED, MAGIC_PKP = 0x10242000, 0x08152000
RING, RING_R, GROUPS = 5, 14.0, 20
ENTRIES = [(9, 4), (10, 1), (11, 1), (2, 1)]      # (type, behaviour) - PRISON uses 9/4, 10/1, 11/1


def pickups(d):
    assert struct.unpack_from('<I', d, 0)[0] == MAGIC_PKP
    n = struct.unpack_from('<I', d, 4)[0]
    return [struct.unpack_from('<3f', d, 12 + 20 * i) for i in range(n)]


def spread(pts, k):
    P = np.array(pts)
    sel = [int(np.argmin(np.linalg.norm(P - P.mean(0), axis=1)))]
    while len(sel) < min(k, len(P)):
        d = np.min(np.linalg.norm(P[:, None] - P[sel][None], axis=2), axis=1)
        sel.append(int(np.argmax(d)))
    return [pts[i] for i in sel]


def group(c, gi):
    cx, cy, cz = c
    z = cz - 2.0
    pts = [(cx, cy, z)] + [(cx + RING_R * math.cos(2 * math.pi * i / RING), cy + RING_R * math.sin(2 * math.pi * i / RING), z)
                           for i in range(RING)]
    links = [list(range(1, RING + 1))] + [sorted({0, 1 + (i - 1) % RING, 1 + (i + 1) % RING}) for i in range(RING)]
    P = np.array(pts)
    lo, hi = P.min(0) - 60, P.max(0) + 60
    b = struct.pack('<BB', len(pts), 3)
    b += struct.pack('<4f', *lo, 0) + struct.pack('<4f', *hi, 0)
    for p, l in zip(pts, links):
        b += struct.pack('<4f', *p, 0) + bytes([24]) + b'\0' * 7 + bytes((l + [0] * 8)[:8])
    for e in range(3):                                     # 3 spawns per group, ped types in turn
        t, beh = ENTRIES[(gi + e) % len(ENTRIES)]
        b += bytes([1 + (gi + e) % RING, t, beh])
    return b


def main(pkp, out):
    sp = spread(pickups(open(pkp, 'rb').read()), GROUPS)
    d = struct.pack('<I', MAGIC_PED) + bytes([len(sp)]) + b''.join(group(c, i) for i, c in enumerate(sp))
    open(out, 'wb').write(d)
    print(out, len(d), 'bytes,', len(sp), 'groups')


if __name__ == '__main__':
    main(*sys.argv[1:3])
