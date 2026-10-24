#!/usr/bin/env python3
"""Put an ELF on a 2048-byte ISO as the boot file SCUS_971.96 (root dir) and set the volume label.
In place when it fits the old extent, else appended at the end (PVD volume size updated).
  iso_setelf.py ISO ELF [LABEL]"""
import sys, struct, os
iso_p, elf_p = sys.argv[1], sys.argv[2]; label = sys.argv[3] if len(sys.argv) > 3 else None
S = 2048
elf = open(elf_p, "rb").read()
with open(iso_p, "r+b") as f:
    f.seek(16 * S); pvd = bytearray(f.read(S)); assert pvd[1:6] == b"CD001"
    root = pvd[156:156 + 34]; rlba, rsize = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    hit = None
    for s in range(rsize // S):
        f.seek((rlba + s) * S); d = f.read(S); o = 0
        while o < S and d[o]:
            n = d[o]; nm = d[o + 33:o + 33 + d[o + 32]].decode("ascii", "replace")
            if nm.split(";")[0] == "SCUS_971.96": hit = ((rlba + s) * S + o, struct.unpack_from("<I", d, o + 2)[0], struct.unpack_from("<I", d, o + 10)[0])
            o += n
    assert hit, "SCUS_971.96 not in the root directory"
    rec, lba, size = hit
    if (len(elf) + S - 1) // S <= (size + S - 1) // S:
        new = lba
    else:
        f.seek(0, 2); end = f.tell(); assert end % S == 0; new = end // S
    f.seek(new * S); f.write(elf + b"\0" * (-len(elf) % S))
    f.seek(rec + 2); f.write(struct.pack("<I", new) + struct.pack(">I", new) + struct.pack("<I", len(elf)) + struct.pack(">I", len(elf)))
    f.seek(0, 2); vol = f.tell() // S
    struct.pack_into("<I", pvd, 80, vol); struct.pack_into(">I", pvd, 84, vol)
    if label: pvd[40:72] = label.upper().encode("ascii")[:32].ljust(32, b" ")
    f.seek(16 * S); f.write(pvd)
    print(f"SCUS_971.96: {size} -> {len(elf)} bytes at LBA {new} ({'in place' if new == lba else 'appended'}); volume {vol} sectors"
          + (f", label {label.upper()}" if label else ""))
