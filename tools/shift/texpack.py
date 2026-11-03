# ruff: noqa
"""
Stage 2 of a pack: TEX + RTX subsets for the textures the pack's NGP uses, renumbered/re-laid out, and the
pack's texture-id slots + GS (TEX0) words patched to match. Run after mkpack.py.
  python3 texpack.py LEVEL NAME
TEX0 fields: TBP0 0-13, TBW 14-19, PSM 20-25, TW 26-29, TH 30-33, TCC 34, TFX 35-36, CBP 37-50, CPSM 51-54,
  CSM 55, CSA 56-60, CLD 61-63.  RTX "res" textures = PSM 0x1B/0x24/0x2C (8H/4HL/4HH), else CLUT region.
"""
import sys, struct, json, collections
from ngpdb import get, w
from texfile import recs
OUT = "/mnt/d/TMB Decomp/packs/"
RES_PSM = {0x1B, 0x24, 0x2C}

def rec_psm(r): return (r["gs"] >> 32) & 0x3F       # bits 32-37 of the record word, as texmResRelocate tests
def blocks(r, res):
    tw, th = r["tw"], r["th"]
    if res:
        x = 1 << tw; x = 0x40 if x <= 0x3F else x
        return max(1, (x << th) >> 6)
    return max(0x40, (1 << tw) << th) >> 6

def build(lvl, name):
    ngp = bytearray(open(OUT + name + ".NGP", "rb").read())
    ptr = open(OUT + name + ".PTR", "rb").read()
    n = w(ptr, 0); m = w(ptr, 4 + 4 * n)
    pairs = [(w(ptr, 8 + 4 * n + 8 * i), w(ptr, 12 + 4 * n + 8 * i)) for i in range(m)]
    ltex, lrtx = get("retail", lvl, "TEX"), get("retail", lvl, "RTX")
    tcls, trecs, _ = recs(ltex)
    _, rrecs, _ = recs(lrtx)
    rrecs = [r for r in rrecs]  # RTX starts at 0 (second word = 0)
    # --- texture ids used
    used = sorted({struct.unpack_from("<H", ngp, a)[0] for a, g in pairs if a})
    byid = {}
    for r in trecs: byid.setdefault(r["id"], r)
    rres_byid = {r["id"]: r for r in rrecs if r["id"] and rec_psm(r) in RES_PSM}
    missing = [i for i in used if i not in byid and i not in rres_byid]
    idmap = {old: new for new, old in enumerate(used, 1)}
    # --- GS words: CLUTs (CBP) and res textures (TBP0)
    gsw = [(g, struct.unpack_from("<Q", ngp, g)[0]) for a, g in pairs if g]
    cbps = sorted({(q >> 37) & 0x3FFF for g, q in gsw})
    restbp = sorted({q & 0x3FFF for g, q in gsw if ((q >> 20) & 0x3F) in RES_PSM})
    clut_by_addr = {r["addr"]: r for r in rrecs if rec_psm(r) not in RES_PSM}
    res_by_addr = {r["addr"]: r for r in rrecs if rec_psm(r) in RES_PSM}
    need_clut = [clut_by_addr[a] for a in cbps if a in clut_by_addr]
    need_res = [res_by_addr[a] for a in restbp if a in res_by_addr]
    miss_clut = [a for a in cbps if a not in clut_by_addr]
    miss_res = [a for a in restbp if a not in res_by_addr]
    # --- new RTX: CLUT region and res region, sequential from 0 in original order
    newaddr_clut, newaddr_res, pos_c, pos_r = {}, {}, 0, 0
    rtx = bytearray()
    for r in sorted(need_clut, key=lambda r: r["addr"]):
        newaddr_clut[r["addr"]] = pos_c; rec = bytearray(lrtx[r["off"]:r["off"] + r["bytes"]])
        struct.pack_into("<H", rec, 0xA, pos_c); pos_c += blocks(r, False); rtx += rec
    for r in sorted(need_res, key=lambda r: r["addr"]):
        newaddr_res[r["addr"]] = pos_r; rec = bytearray(lrtx[r["off"]:r["off"] + r["bytes"]])
        struct.pack_into("<H", rec, 0xA, pos_r); struct.pack_into("<H", rec, 8, idmap.get(r["id"], 0))
        pos_r += blocks(r, True); rtx += rec
    rtx += b"\0" * 16                                   # terminator record (sizew 0)
    rtx += b"\0" * (-len(rtx) % 128)
    # --- new TEX: header with the classes the chosen records use, then the records
    chosen = [byid[i] for i in used if i in byid]
    cls_old = sorted({r["gs"] >> 59 for r in chosen})
    cls_new = {c: k for k, c in enumerate(cls_old)}
    counts = collections.Counter(r["gs"] >> 59 for r in chosen)
    hdr = struct.pack("<II", len(cls_old), 0) + b"".join(struct.pack("<II", counts[c], tcls[c][1]) for c in cls_old)
    recq = (len(hdr) + 127) // 128 * 8
    hdr = struct.pack("<II", len(cls_old), recq) + hdr[8:]
    tex = bytearray(hdr + b"\0" * (recq * 16 - len(hdr)))
    for r in chosen:
        rec = bytearray(ltex[r["off"]:r["off"] + r["bytes"]])
        gs = struct.unpack_from("<Q", rec, 8)[0]
        gs = (gs & ~0xFFFF & ((1 << 59) - 1)) | idmap[r["id"]] | (cls_new[gs >> 59] << 59)
        struct.pack_into("<Q", rec, 8, gs); tex += rec
    tex += b"\0" * 16
    tex += b"\0" * (-len(tex) % 128)
    # --- patch NGP: ids, CBP, res TBP0
    for a, g in pairs:
        if a:
            old = struct.unpack_from("<H", ngp, a)[0]
            if old in idmap: struct.pack_into("<H", ngp, a, idmap[old])
        if g:
            q = struct.unpack_from("<Q", ngp, g)[0]
            cbp = (q >> 37) & 0x3FFF
            if cbp in newaddr_clut: q = (q & ~(0x3FFF << 37)) | (newaddr_clut[cbp] << 37)
            if ((q >> 20) & 0x3F) in RES_PSM and (q & 0x3FFF) in newaddr_res:
                q = (q & ~0x3FFF) | newaddr_res[q & 0x3FFF]
            struct.pack_into("<Q", ngp, g, q)
    open(OUT + name + ".NGP", "wb").write(ngp)
    open(OUT + name + ".TEX", "wb").write(tex)
    open(OUT + name + ".RTX", "wb").write(rtx)
    rep = json.load(open(OUT + name + ".json"))
    rep.update({"tex_ids": len(used), "tex_missing": missing, "tex_bytes": len(tex), "classes": [(counts[c], tcls[c][1]) for c in cls_old],
                "clut": len(need_clut), "clut_missing": miss_clut, "res": len(need_res), "res_missing": miss_res,
                "rtx_bytes": len(rtx), "clut_blocks": pos_c, "res_blocks": pos_r,
                "psms": sorted({hex((q >> 20) & 0x3F) for g, q in gsw})})
    json.dump(rep, open(OUT + name + ".json", "w"), indent=1)
    return rep

if __name__ == "__main__":
    rep = build(sys.argv[1], sys.argv[2])
    print({k: rep[k] for k in ("tex_ids", "tex_missing", "tex_bytes", "classes", "clut", "clut_missing", "res", "res_missing", "rtx_bytes", "clut_blocks", "res_blocks", "psms")})
