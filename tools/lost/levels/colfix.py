"""Replace the collision trees of an already merged Lost map (cloud/lost2 HC*.NGP / PTR) with exact ones
(lvcol2.build_piece_auto): the old trees are cut out of the NGP (tmbcar.Car.compact remaps every pointer / PTR slot)
and the new ones go to OUT_PREFIX.COL, a blob for high RAM (COLBASE, past 32 MB: the exact trees are 2-4x bigger and
the NGP slot is fixed); op18 roots point there (no PTR slot: the game never relocates). Disc: \\PCAR\\ZCHC<xx>.BIN. Render meshes, textures, grid, the
donor parts stay byte for byte (the repo's lvbuild.py does not reproduce lost2's NGP exactly, so no full rebuild).
op18 <-> Head-On piece: lvbuild made one op18 per piece in collision_objects order with centre / radius from the
piece's vertices; matched here by that centre / radius.
  python3 colfix.py HC_xx.BDD IN_PREFIX OUT_PREFIX      (prefix = path without .NGP / .PTR)"""
import sys, os, struct, time
import numpy as np
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.dirname(HERE), '/home/claude/lost']
from bdd import bdd
from hocol import piece, collision_objects
from tmbcar import Car, u32, BASE
from lvcol import encode
import lvcol2
COLBASE = 0x3000000                  # mods/lostslots.c LOSTCOL (128 MB EE)


def old_tree(n, root):
    seen, st = set(), [root]
    while st:
        o = st.pop()
        if o in seen: continue
        seen.add(o)
        f, b = u32(n, o), u32(n, o + 4)
        for x in (f, b):
            if x: st.append(x - BASE)
    return seen


def main(bddp, inp, outp, scale=1.15):
    t0 = time.time()
    b = bdd(bddp); hn = b['ngp']
    pcs = []
    for node, op, M, bb in collision_objects(hn):
        if op != 26: continue
        V, Tr, F = piece(hn, node)
        if not len(Tr): continue
        Wv = (np.c_[V, np.ones(len(V))] @ M)[:, :3] * scale
        if np.abs(Wv).max() > 50000: continue
        used = Wv[np.unique(Tr)]
        c = (used.max(0) + used.min(0)) / 2; rad = float(np.linalg.norm(used - c, axis=1).max()) + 1.0
        pcs.append((Wv, Tr, c, rad))
    car = Car(open(inp + '.NGP', 'rb').read(), open(inp + '.PTR', 'rb').read(), b'', b'')
    n = car.n
    from hcbuild import traverse_check
    seen, bad = traverse_check(bytes(n), car.slots)
    o18 = sorted(o for o in seen if u32(n, o) & 0x3f == 18)
    key = lambda c, r: (round(float(c[0]), 1), round(float(c[1]), 1), round(float(c[2]), 1), round(float(r), 1))
    bykey = {}
    for i, (W, T, c, r) in enumerate(pcs):
        bykey.setdefault(key(np.float32(c), np.float32(r)), []).append(i)
    dead = set(); oldn = newn = 0; miss = 0; done = 0
    col = bytearray(16); trees = []                   # the high-RAM blob (LOSTCOL), header filled below
    slots = set(car.slots)
    for o in o18:
        r = struct.unpack_from('<f', n, o + 8)[0]; c = struct.unpack_from('<3f', n, o + 0x10)
        ids = bykey.get(key(np.float32(c), np.float32(r)))
        if not ids:
            miss += 1; continue
        W, T, _, _ = pcs[ids.pop(0)]
        res = lvcol2.build_piece_auto(W, T)
        if res is None:
            continue
        nodes, root, prs = res
        old = old_tree(n, u32(n, o + 0xC) - BASE); dead |= old; oldn += len(old)
        while len(col) % 16: col.append(0)
        pos = len(col)
        blob, _, _ = encode(nodes, root, COLBASE + pos)
        col += blob; newn += len(blob) // 0x20
        trees.append(COLBASE + pos)
        struct.pack_into('<I', car.n, o + 0xC, len(trees))   # tree number for now (not a pointer: kept by compact)
        slots.discard(o + 0xC); done += 1
    car.slots = sorted(slots)
    runs = []
    for o in sorted(dead):
        if runs and runs[-1][1] == o: runs[-1][1] = o + 0x20
        else: runs.append([o, o + 0x20])
    dr = [(a, b_) for a, b_ in runs if a % 16 == 0 and b_ % 16 == 0]
    size0 = len(car.n)
    dropped = car.compact(dr)
    n = car.n
    seen2, bad2 = traverse_check(bytes(n), car.slots)
    fixed = 0
    for o in seen2:
        if u32(n, o) & 0x3f == 18 and 1 <= u32(n, o + 0xC) <= len(trees):
            struct.pack_into('<I', n, o + 0xC, trees[u32(n, o + 0xC) - 1]); fixed += 1
    assert fixed == len(trees), (fixed, len(trees))
    struct.pack_into('<4I', col, 0, 0x314C4F43, COLBASE, len(col), 0)
    col += b'\0' * (-len(col) % 2048)
    open(outp + '.NGP', 'wb').write(car.ngp_bytes())
    open(outp + '.PTR', 'wb').write(car.ptr_bytes())
    open(outp + '.COL', 'wb').write(bytes(col))
    print('%s: op18 %d, replaced %d, unmatched %d; tree nodes %d -> %d (COL %.2f MB at %#x); NGP %.2f MB (was %.2f); '
          'dropped slots %d; bad slots after %d; %.0fs' % (os.path.basename(outp), len(o18), done, miss, oldn, newn,
          len(col) / 1e6, COLBASE, len(car.n) / 1e6, size0 / 1e6, dropped, len(bad2), time.time() - t0))


if __name__ == '__main__':
    main(*sys.argv[1:4])
