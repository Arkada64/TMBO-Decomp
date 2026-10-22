# ruff: noqa
"""
TEX / RTX record files (from retail texmRelocate / texmResRelocate):
  header: u32 nclass, u32 recq (offset of first record in qwords), then nclass x (u32 count, u32 blksize)
  record (qword aligned): u32 sizew (record bytes = sizew*4), u32 key, u64 gs (bits 0-15: tex id for TEX;
  RTX: u16 @+8 tex id, u16 @+0xA vram block addr, bits 40-43 tw, 44-47 th (log2), bits 58-63 kind), payload
  terminator: sizew == 0
"""
import struct, sys, collections
from ngpdb import rawfile, members, get

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

def show(name, d):
    classes, rs, end = recs(d)
    kinds = collections.Counter(hex(r["kind"]) for r in rs)
    ids = [r["id"] for r in rs]
    print(f"{name}: {len(d)} bytes, classes {classes[:6]}{'...' if len(classes) > 6 else ''} ({len(classes)}), "
          f"{len(rs)} records, end {end}, ids {min(ids) if ids else '-'}..{max(ids) if ids else '-'}, kinds {dict(kinds)}")
    for r in rs[:4]:
        print("   ", {k: (hex(v) if isinstance(v, int) else v) for k, v in r.items()})

if __name__ == "__main__":
    def car(ext):
        raw = rawfile("online", f"/PCAR/AXP.{ext}"); ms = members(raw); return ms[0][1] if ms else raw
    show("AXP.TEX", car("TEX")); show("AXP.RTX", car("RTX"))
    for tag in ("retail", "online"):
        show(f"{tag} FREEWAY.TEX", get(tag, "FREEWAY", "TEX"))
        show(f"{tag} FREEWAY.RTX", get(tag, "FREEWAY", "RTX"))
