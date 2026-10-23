"""TEX / RTX record files (texmRelocate): header u32 nclass, u32 recq (first record in qwords), nclass x (count,
blksize); record: u32 sizew, u32 key, u64 gs (TMB: id 0-15, psm 32-37, tw 40-43, th 44-47, class 59-63), payload."""
import struct

def recs(d):
    ncls, recq = struct.unpack_from("<II", d, 0)
    classes = [struct.unpack_from("<II", d, 8 + 8 * i) for i in range(ncls)]
    o, out = recq * 16, []
    while o + 16 <= len(d):
        sizew, key = struct.unpack_from("<II", d, o)
        if sizew == 0: break
        gs, = struct.unpack_from("<Q", d, o + 8)
        out.append({"off": o, "bytes": sizew * 4, "key": key, "gs": gs, "id": gs & 0xFFFF,
                    "addr": (gs >> 16) & 0xFFFF, "tw": (gs >> 40) & 0xF, "th": (gs >> 44) & 0xF, "kind": gs >> 58})
        o += sizew * 4
    return classes, out, o

