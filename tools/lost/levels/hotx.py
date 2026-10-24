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
def children(n, o):
    """Head-On child layouts -> [(child, local matrix or None, alt)]; alt = a far LOD / other damage state"""
    N = len(n); u = lambda q: struct.unpack_from('<I', n, q)[0]; u16 = lambda q: struct.unpack_from('<H', n, q)[0]
    ok = lambda p: 0 < p < N and p % 16 == 0
    mat = lambda q: np.array(struct.unpack_from('<16f', n, q), np.float64).reshape(4, 4)
    op = u(o) & 0x3f; L = None; kids = []; alt = []
    if op == 1: kids = [u(o + 0x20 + 4 * i) for i in range(u16(o + 8))]
    elif op == 2:
        c = u16(o + 4); kids = [u(o + 0x28 + 0x10 * i) for i in range(c)] if c < 16 else []; alt = list(range(1, len(kids)))
    elif op == 3:
        L = np.eye(4); L[3, :3] = struct.unpack_from('<3f', n, o + 0x10)
        kids = [u(o + 0x1c + 4 * i) for i in range(u16(o + 8))]
    elif op == 4: L = mat(o + 0x10); kids = [u(o + 0x50 + 4 * i) for i in range(u16(o + 8))]
    elif op in (5, 6): kids = [u(o + 0xc + 4 * i) for i in range(n[o + 0xb])]
    elif op == 13:
        k = o + 0x20
        if u(o + 0x20) == 0x3f800000: L = mat(o + 0x20); k = o + 0xa0
        while ok(u(k)) and len(kids) < 64: kids.append(u(k)); k += 4
    elif op == 7: kids = [u(o + 4)] + [u(o + 0x20 + 4 * i) for i in range(u16(o + 0xc))]
    elif op == 17: kids = [u(o + 0x2c + 4 * i) for i in range(u16(o + 0x28))]
    elif op == 18:
        tr = struct.unpack_from('<3f', n, o + 0x10); sc = struct.unpack_from('<3f', n, o + 0x20)
        L = np.diag([sc[0], sc[1], sc[2], 1.0]); L[3, :3] = tr
        kids = [u(o + 0x2c + 4 * i) for i in range(u16(o + 8))]
    elif op == 19:
        c = n[o + 8]; kids = [u(o + 0x10 + 0xc * i) for i in range(c)] if c < 16 else []; alt = list(range(1, len(kids)))
    elif op == 20: kids = [u(o + 8)]
    elif op == 31: kids = [u(o + 0x1c)]
    if len(kids) > 512: return []
    return [(k, L, i in alt) for i, k in enumerate(kids) if ok(k)]

def walk(n, log=False):
    """first LOD / first damage state from the entry points and the world-object table, then every mesh the walk
    missed placed by climbing its parents (any node layout we know) up to a node the walk placed"""
    N = len(n); u = lambda o: struct.unpack_from('<I', n, o)[0]
    ok = lambda p: 0 < p < N and p % 16 == 0
    meshes = []; stats = collections.Counter(); unk = collections.Counter(); seen = set(); placed = {}
    stack = [(u(4 + 4 * i), np.eye(4), 0) for i in range(u(0))]
    stack += [(o, M, 0) for o, M in instances(n)]
    while stack:
        o, M, dep = stack.pop()
        if not ok(o) or dep > 60 or not np.isfinite(M).all() or np.abs(M).max() > 1e5: continue
        if (o, M.tobytes()) in seen: continue
        seen.add((o, M.tobytes()))
        op = u(o) & 0x3f
        if op not in KNOWN: continue
        stats[op] += 1
        placed.setdefault(o, M)
        if op == 0: meshes.append((o, M)); continue
        if op not in (1, 2, 3, 4, 5, 6, 7, 13, 17, 18, 19, 20, 31): unk[op] += 1; continue
        for k, L, alt in children(n, o):
            if alt: continue
            stack.append((k, (L @ M) if L is not None else M, dep + 1))
    # ---- climb: parent edges from every plausible node in the file
    parent = {}
    for o in range(0, N - 0x40, 16):
        op = u(o) & 0x3f
        if op not in (1, 2, 3, 4, 7, 13, 17, 18, 19, 20, 31) or (u(o) >> 6) & 0xfff: continue
        try: ks = children(n, o)
        except Exception: continue
        if not ks or any((u(k) & 0x3f) not in KNOWN for k, _, _ in ks): continue
        for k, L, alt in ks: parent.setdefault(k, (o, L, alt))
    have = {o for o, _ in meshes}; extra = 0
    for o in range(0, N - 16, 16):
        if o in have or o not in parent or (u(o) & 0x3f) != 0 or u(o + 8) != 0: continue
        chain = []; x = o; bad = False
        while x not in placed and x in parent and len(chain) < 40:
            p, L, alt = parent[x]
            if alt: bad = True; break
            chain.append(L); x = p
        if bad or x not in placed: continue
        M = placed[x]
        for L in reversed(chain):
            if L is not None: M = L @ M
        if np.isfinite(M).all() and np.abs(M).max() < 1e5:
            meshes.append((o, M)); extra += 1
    stats['climbed'] = extra
    return meshes, stats, unk
