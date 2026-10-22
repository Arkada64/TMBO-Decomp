# ruff: noqa
"""
Exact port of retail dbsTraverse (child layout per opcode) for offline databases.
visit(ngp) -> list of (offset, op, id1, id2) for every node the loader callback (dbProcInteractive) sees.
"""
import struct
from ngpdb import w, head, BASE

def u8(d, o): return d[o]
def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def s32(d, o): return struct.unpack_from("<i", d, o)[0]

def traverse(ngp, ep_slot_offsets, callback_all=False, parents=None):
    """parents: optional dict filled with node -> parent node (the node whose child pointer led here)"""
    size = len(ngp)
    def P(slot):                       # pointer stored at slot -> offset or None
        v = w(ngp, slot)
        return v - BASE if BASE <= v < BASE + size else None
    stack = [[s, 1, None] for s in reversed(ep_slot_offsets)]
    out, steps = [], 0
    while stack:
        top = stack[-1]
        node = P(top[0]); top[1] -= 1; par = top[2]
        if top[1] == 0: stack.pop()
        else: top[0] += 4
        while node is not None:
            if parents is not None and node not in parents: parents[node] = par
            steps += 1
            if steps > 5_000_000: raise RuntimeError("runaway traversal")
            word = w(ngp, node); op, id2, id1 = head(word)
            cb = (word & 0xFFFC0000) != 0
            nxt = None
            def kids(count, first_off, rest_off):
                nonlocal nxt
                if count <= 0: return
                nxt = P(node + first_off)
                if count - 1 > 0: stack.append([node + rest_off, count - 1, node])
            if op == 0:
                if cb or callback_all: out.append((node, op, id1, id2))
            elif op == 1:
                n = u16(ngp, node + 8)
                if n:
                    if cb: out.append((node, op, id1, id2))
                    kids(n, 0x20, 0x24)
            elif op == 2:
                n = s32(ngp, node + 4)
                if n:
                    if cb: out.append((node, op, id1, id2))
                    nxt = P(node + 0x28)
                    for i in range(n - 1, 0, -1): stack.append([node + 0x38 + 0x10 * (i - 1), 1, node])
            elif op == 3:
                if cb: out.append((node, op, id1, id2))
                kids(s32(ngp, node + 8), 0x1C, 0x20)
            elif op == 4:
                if cb: out.append((node, op, id1, id2))
                kids(s32(ngp, node + 8), 0x50, 0x54)
            elif op == 17:
                if cb: out.append((node, op, id1, id2))
                kids(s32(ngp, node + 4), 0xCC, 0xD0)
            elif op == 6:
                if cb: out.append((node, op, id1, id2))
                kids(u8(ngp, node + 0xB), 0xC, 0x10)
            elif op == 31:
                out.append((node, op, id1, id2))            # called with or without id (id 0 rewritten)
                for i in range(u8(ngp, node + 9) - 1, -1, -1): stack.append([node + 0xC + 0x14 * i, 1, node])
            elif op == 8:
                stack.append([node + 8, 1, node]); nxt = P(node + 4)
            elif op == 13:
                kids(s32(ngp, node + 4), 0xBC, 0xC0)
            elif op == 23:
                nxt = P(node + 4)
            elif op == 25:
                n = s32(ngp, node + 0x28)
                if n > 0: stack.append([node + 0x2C, n, node])
            elif op == 30:
                if cb: out.append((node, op, id1, id2))
                kids(s32(ngp, node + 8), 0x2C, 0x30)
            par = node; node = nxt
    return out

def visit(ngp):
    n = w(ngp, 0)
    return traverse(ngp, [4 + 4 * i for i in range(n)])

if __name__ == "__main__":
    import sys, collections
    from ngpdb import get
    for tag in ("retail", "online"):
        ngp = get(tag, sys.argv[1], "NGP")
        v = visit(ngp)
        c = collections.Counter()
        for o, op, i1, i2 in v:
            r = "veh" if i1 < 0x401 else "fod" if i1 < 0xBB8 else "ped" if i1 < 0xFA0 else "wpn" if i1 < 0x12C0 else "oth"
            c[r] += 1
        print(tag, sys.argv[1], len(v), "callbacks", dict(c))
        print("  peds:", sorted(collections.Counter((i1, op) for o, op, i1, i2 in v if 3000 <= i1 < 4000).items()))
        fod = sorted(collections.Counter(i1 for o, op, i1, i2 in v if 0x401 <= i1 < 0xBB8).items())
        print("  fodder:", len(fod), "ids", fod[:12])
