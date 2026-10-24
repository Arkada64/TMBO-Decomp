"""Head-On level walk with transforms: collect op0 meshes with world matrices (row vectors, like navgen)."""
import sys, struct, collections, numpy as np
sys.path.insert(0, '/home/claude/lost')
KNOWN = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 13, 14, 17, 18, 19, 20, 24, 26, 27, 31}
def instances(n):
    """world-object records {1, 0, node, 0, 4x4 matrix} (a table near the end of the ngp): extra roots"""
    N = len(n); u = lambda o: struct.unpack_from('<I', n, o)[0]; out = []
    for o in range(0, N - 0x50, 16):
        if u(o) == 1 and u(o + 4) == 0 and u(o + 12) == 0 and 0 < u(o + 8) < N and u(o + 8) % 16 == 0:
            M = np.array(struct.unpack_from('<16f', n, o + 16), np.float64).reshape(4, 4)
            if abs(M[3, 3] - 1) < 1e-4 and np.abs(M[:3, 3]).max() < 1e-4 and abs(np.linalg.det(M[:3, :3]) - 1) < 0.05:
                out.append((u(o + 8), M))
    return out
def walk(n, log=False):
    N = len(n); u = lambda o: struct.unpack_from('<I', n, o)[0]; u16 = lambda o: struct.unpack_from('<H', n, o)[0]
    ok = lambda p: 0 < p < N and p % 16 == 0
    mat = lambda o: np.array(struct.unpack_from('<16f', n, o), np.float64).reshape(4, 4)
    meshes = []; stats = collections.Counter(); unk = collections.Counter(); seen = set()
    stack = [(u(4 + 4 * i), np.eye(4), 0) for i in range(u(0))]
    stack += [(o, M, 0) for o, M in instances(n)]
    while stack:
        o, M, dep = stack.pop()
        if not ok(o) or dep > 60 or not np.isfinite(M).all() or np.abs(M).max() > 1e5: continue
        if (o, M.tobytes()) in seen: continue
        seen.add((o, M.tobytes()))
        op = u(o) & 0x3f
        if op not in KNOWN: continue
        stats[op] += 1; kids = []
        if op == 0: meshes.append((o, M)); continue
        if op == 1: kids = [u(o + 0x20 + 4 * i) for i in range(u16(o + 8))]
        elif op == 2: kids = [u(o + 0x28)] if u16(o + 4) else []
        elif op == 3:
            T = np.eye(4); T[3, :3] = struct.unpack_from('<3f', n, o + 0x10); M = T @ M
            kids = [u(o + 0x1c + 4 * i) for i in range(u16(o + 8))]
        elif op == 4: M = mat(o + 0x10) @ M; kids = [u(o + 0x50 + 4 * i) for i in range(u16(o + 8))]
        elif op in (5, 6): kids = [u(o + 0xc + 4 * i) for i in range(n[o + 0xb])]
        elif op == 13:
            k = o + 0x20
            if u(o + 0x20) == 0x3f800000: M = mat(o + 0x20) @ M; k = o + 0xa0
            while ok(u(k)): kids.append(u(k)); k += 4
        elif op == 7: kids = [u(o + 4)] + [u(o + 0x20 + 4 * i) for i in range(u16(o + 0xc))]   # +8: op8 (no meshes)
        elif op == 17: kids = [u(o + 0x2c + 4 * i) for i in range(u16(o + 0x28))]
        elif op == 18:
            tr = struct.unpack_from('<3f', n, o + 0x10); sc = struct.unpack_from('<3f', n, o + 0x20)
            S = np.diag([sc[0], sc[1], sc[2], 1.0]); S[3, :3] = tr; M = S @ M
            kids = [u(o + 0x2c + 4 * i) for i in range(u16(o + 8))]
        elif op == 19: kids = [u(o + 0x10)]
        elif op == 20: kids = [u(o + 8)]
        elif op == 31: kids = [u(o + 0x1c)]
        else: unk[op] += 1
        if len(kids) > 512: continue
        for k in kids:
            if ok(k): stack.append((k, M, dep + 1))
    return meshes, stats, unk
