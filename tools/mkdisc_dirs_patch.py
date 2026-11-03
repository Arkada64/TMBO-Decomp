# replaces build() in mkdisc.py: files can go to \PCAR (default) or \ACAR ("ACAR/NAME" argument); when the last
# used directory sector is full, the next (empty) sector of the directory's extent is used.
import re
p = "/mnt/d/TMB Decomp/mkdisc.py"
s = open(p).read()
i = s.index("def build(out, files):")
j = s.index('if __name__ == "__main__":')
new = '''def build(out, files):
    base_iso()
    shutil.copyfile(BASEISO, out)
    iso = open(out, "r+b")
    iso.seek(16 * S); pvd = bytearray(iso.read(S))
    vol = struct.unpack_from("<I", pvd, 80)[0]
    root = pvd[156:190]
    rl, rs = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    lba = vol
    bydir = {}
    for f in files:
        d, _, n = f.rpartition("/")
        d = d.upper() if d.upper() in ("PCAR", "ACAR") else "PCAR"
        bydir.setdefault(d, []).append(n if d != "PCAR" or "/" not in f else n)
    for dname, flist in bydir.items():
        pl, ps = find(iso, rl, rs, dname)
        secs = []
        for s_ in range(ps // S):
            iso.seek((pl + s_) * S); secs.append(bytearray(iso.read(S)))
        last, tmpl = 0, None
        for k, sec in enumerate(secs):
            recs, end = dirrecs(sec)
            if recs: last, tmpl = k, recs[-1][1]
        tail = dirrecs(secs[last])[1]
        existing = {r[33:33 + r[32]].decode() for sec in secs for o, r in dirrecs(sec)[0]}
        for f in flist:
            name = os.path.basename(f).upper()
            data = open(f, "rb").read()
            r = record(name, lba, len(data), tmpl)
            if name + ";1" in existing: raise SystemExit(f"{name} already in \\\\{dname} (rebuild from the base)")
            if tail + len(r) > S:
                last += 1; tail = 0
                if last >= len(secs): raise SystemExit(f"no room left in the \\\\{dname} directory")
            secs[last][tail:tail + len(r)] = r; tail += len(r)
            iso.seek(lba * S); iso.write(data + b"\\0" * (-len(data) % S))
            print(f"  \\\\{dname}\\\\{name}: LBA {lba}, {len(data)} bytes")
            lba += (len(data) + S - 1) // S
        for k, sec in enumerate(secs):
            iso.seek((pl + k) * S); iso.write(sec)
        print(f"  \\\\{dname}: sector {last} free bytes left {S - tail}")
    struct.pack_into("<I", pvd, 80, lba); struct.pack_into(">I", pvd, 84, lba)
    iso.seek(16 * S); iso.write(pvd)
    iso.seek(lba * S - 1); iso.write(b"\\0") if os.path.getsize(out) < lba * S else None
    iso.close()
    print(f"{out}: volume {vol} -> {lba} sectors")

'''
s = s[:i] + new + s[j:]
open(p, "w").write(s)
print("patched")
