"""TMB car file editing: NGP (stored for BASE), PTR (pointer slots + texture pairs), TEX, RTX.
NGP edits are done by appending new nodes and rewiring pointer slots, then compact() drops unreachable
op0 meshes (header + packet) and rebuilds the PTR."""
import struct, zlib
BASE = 0x980000


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


class Car:
    def __init__(self, ngp, ptr, tex, rtx):
        self.n = bytearray(ngp)
        N = u32(ptr, 0)
        self.slots = [u32(ptr, 4 + 4 * i) for i in range(N)]
        M = u32(ptr, 4 + 4 * N)
        self.pairs = [(u32(ptr, 8 + 4 * N + 8 * i), u32(ptr, 12 + 4 * N + 8 * i)) for i in range(M)]
        self.tex = bytearray(tex)
        self.rtx = bytearray(rtx)

    # ---- NGP helpers
    def P(self, slot):
        v = u32(self.n, slot)
        return v - BASE if BASE <= v < BASE + len(self.n) else None

    def setp(self, slot, off):
        struct.pack_into('<I', self.n, slot, (BASE + off) if off is not None else 0)
        if off is not None and slot not in self.slots:
            self.slots.append(slot)

    def append(self, blob, rel_slots=(), rel_pairs=()):
        while len(self.n) % 16:
            self.n.append(0)
        off = len(self.n)
        self.n += blob
        for s in rel_slots:
            v = u32(self.n, off + s)
            struct.pack_into('<I', self.n, off + s, v + BASE + off)   # rel_slots hold node-relative targets
            self.slots.append(off + s)
        for a, g in rel_pairs:
            self.pairs.append((off + a, off + g))
        return off

    def group(self, kids, sphere=(0, 0, 0, 30.0), flags=1):
        """op1 GROUP; kids = absolute file offsets"""
        b = bytearray(0x20 + 4 * len(kids))
        cx, cy, cz, r = sphere
        struct.pack_into('<IIHHf3ff', b, 0, 1, 0, len(kids), flags, r * r, cx, cy, cz, r)
        off = self.append(bytes(b))
        for i, k in enumerate(kids):
            self.setp(off + 0x20 + 4 * i, k)
        return off

    def max_tex_id(self):
        return max((struct.unpack_from('<H', self.n, a)[0] for a, g in self.pairs), default=0)

    # ---- reachability + compaction
    def reachable_meshes(self):
        """op0 nodes reachable through any pointer chain from the entry points (generic: follow every
        relocated slot inside a reached non-mesh node's extent is not known, so walk by slot ownership)"""
        return None

    def compact(self, dead_ranges):
        """remove byte ranges (sorted, non-overlapping, 16-aligned), remap every slot/pointer"""
        dead = sorted(dead_ranges)
        keep, pos = [], 0
        for a, b in dead:
            if a > pos:
                keep.append((pos, a))
            pos = max(pos, b)
        keep.append((pos, len(self.n)))
        # mapping
        newoff, cur = [], 0
        for a, b in keep:
            newoff.append((a, b, cur))
            cur += b - a
        import bisect
        starts = [k[0] for k in newoff]

        def m(o):
            i = bisect.bisect_right(starts, o) - 1
            if i < 0:
                return None
            a, b, c = newoff[i]
            return c + (o - a) if a <= o < b or (o == b and o == len(self.n)) else None

        out = bytearray()
        for a, b in keep:
            out += self.n[a:b]
        slots, dropped = [], 0
        for s in sorted(set(self.slots)):
            ns = m(s)
            if ns is None:
                continue
            v = u32(self.n, s)
            if v == 0:
                continue
            t = m(v - BASE) if BASE <= v < BASE + len(self.n) + 1 else None
            if t is None:
                struct.pack_into('<I', out, ns, 0)
                dropped += 1
                continue
            struct.pack_into('<I', out, ns, BASE + t)
            slots.append(ns)
        for i in range(u32(self.n, 0)):              # entry points (relocated by the loader, not in the PTR)
            v = u32(self.n, 4 + 4 * i)
            t = m(v - BASE)
            assert t is not None, 'entry point in a removed range'
            struct.pack_into('<I', out, 4 + 4 * i, BASE + t)
        pairs = []
        for a, g in self.pairs:
            na, ng = m(a), m(g)
            if na is not None and ng is not None:
                pairs.append((na, ng))
        self.n, self.slots, self.pairs = out, slots, pairs
        return dropped

    def ptr_bytes(self):
        b = struct.pack('<I', len(self.slots)) + struct.pack('<%dI' % len(self.slots), *sorted(self.slots))
        b += struct.pack('<I', len(self.pairs)) + b''.join(struct.pack('<II', a, g) for a, g in self.pairs)
        return b + b'\0' * 16

    def ngp_bytes(self):
        b = bytes(self.n)
        return b + b'\0' * (-len(b) % 16)


def mesh_extent(n, node):
    """[node, end of its packet) for an op0 HierObject"""
    pk = u32(n, node + 4) - BASE
    qwc = u32(n, pk) & 0xffff
    return node, pk + 16 + qwc * 16
