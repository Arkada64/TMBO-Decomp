"""Head-On collision pieces (op26): node {0x1a, 0x10001, end, hdr}; hdr {u32 vertex ptr, u16 ntri, u16 nnode,
s32 origin xyz, f32 scale}; vertices (s16 xyz, world = (v + origin) * scale) sit just before hdr; after hdr:
nnode BVH nodes (s16 aabb min/max + u16) then ntri triangles (u8 i0, i1, i2, u8 flags)."""
import struct
import numpy as np
def piece(n, node):
    u = lambda o: struct.unpack_from('<I', n, o)[0]
    end, h = u(node + 8), u(node + 0xc)
    vp = u(h); ntri = u(h + 4) & 0xffff; nn = u(h + 4) >> 16
    org = np.array(struct.unpack_from('<3i', n, h + 8), float); sc = struct.unpack_from('<f', n, h + 0x14)[0]
    tb = h + 0x18 + 14 * nn
    tris = np.frombuffer(n[tb:tb + 4 * ntri], np.uint8).reshape(ntri, 4)
    nv = int(tris[:, :3].max()) + 1 if ntri else 0
    V = (np.array(struct.unpack_from('<%dh' % (3 * nv), n, vp), float).reshape(nv, 3) + org) * sc
    return V, tris[:, :3].astype(int), tris[:, 3].copy()

def node_matrix(n, o):
    """local transform of a node (row vectors), identity for non-transform nodes"""
    u = lambda q: struct.unpack_from('<I', n, q)[0]
    op = u(o) & 0x3f
    if op == 3:
        T = np.eye(4); T[3, :3] = struct.unpack_from('<3f', n, o + 0x10); return T
    if op == 4:
        return np.array(struct.unpack_from('<16f', n, o + 0x10), float).reshape(4, 4)
    if op == 18:
        tr = struct.unpack_from('<3f', n, o + 0x10); sc = struct.unpack_from('<3f', n, o + 0x20)
        S = np.diag([sc[0], sc[1], sc[2], 1.0]); S[3, :3] = tr; return S
    if op == 13 and u(o + 0x20) == 0x3f800000:
        return np.array(struct.unpack_from('<16f', n, o + 0x20), float).reshape(4, 4)
    return np.eye(4)

def collision_objects(n):
    """the op12 grid entry's object table: {aabb 6f, 0, 0xffff tt nn, nn node pointers root..leaf}
    -> [(leaf node, op, world matrix, aabb)]"""
    u = lambda q: struct.unpack_from('<I', n, q)[0]
    ne = u(0); grid = next((u(4 + 4 * i) for i in range(ne) if u(u(4 + 4 * i)) & 0x3f == 12), None)
    if grid is None: return []
    A, B = u(grid + 0x20), u(grid + 0x24)
    out = []; o = B
    while o < A:
        w7 = u(o + 0x1c)
        if (w7 >> 16) != 0xffff: break
        cnt = w7 & 0xff; path = [u(o + 0x20 + 4 * i) for i in range(cnt)]
        M = np.eye(4)
        for p in path[:-1]: M = node_matrix(n, p) @ M
        out.append((path[-1], u(path[-1]) & 0x3f, M, struct.unpack_from('<6f', n, o)))
        o = (o + 0x20 + 4 * cnt + 3) & ~3
    return out
