# mkdisc.py: when a directory's extent is full, move it to the end of the image with one more sector
# (root record, its "." record, the L/M path tables updated).
p = "/mnt/d/TMB Decomp/mkdisc.py"
s = open(p).read()
old = '''        tail = dirrecs(secs[last])[1]
'''
new = '''        tail = dirrecs(secs[last])[1]
        need = sum(34 + len(os.path.basename(f)) + 2 for f in flist)
        free = (S - tail) + S * (len(secs) - 1 - last)
        if need > free:                      # relocate the directory to the end, one sector bigger
            newpl = lba; secs.append(bytearray(S)); lba += len(secs)
            relocate_dir(iso, pvd, rl, rs, dname, pl, newpl, len(secs) * S, secs)
            pl = newpl
'''
assert old in s
s = s.replace(old, new, 1)
helper = '''
def relocate_dir(iso, pvd, rl, rs, name, oldl, newl, newsize, secs):
    """point every reference of directory NAME (old extent oldl) at newl / newsize"""
    def fix(rec_sec, o):
        struct.pack_into("<I", rec_sec, o + 2, newl); struct.pack_into(">I", rec_sec, o + 6, newl)
        struct.pack_into("<I", rec_sec, o + 10, newsize); struct.pack_into(">I", rec_sec, o + 14, newsize)
    for k in range(rs // S):                       # root directory record
        iso.seek((rl + k) * S); d = bytearray(iso.read(S))
        recs, _ = dirrecs(d)
        hit = False
        for o, r in recs:
            if r[33:33 + r[32]].decode("ascii", "replace") == name: fix(d, o); hit = True
        if hit: iso.seek((rl + k) * S); iso.write(d)
    recs, _ = dirrecs(secs[0])                     # its own "." record
    fix(secs[0], recs[0][0])
    ptsize = struct.unpack_from("<I", pvd, 132)[0]
    for off, big in ((140, False), (144, False), (148, True), (152, True)):
        loc = struct.unpack_from(">I" if big else "<I", pvd, off)[0]
        if not loc: continue
        iso.seek(loc * S); t = bytearray(iso.read((ptsize + S - 1) // S * S))
        o = 0
        while o < ptsize:
            ln = t[o]
            if ln == 0: break
            nm = t[o + 8:o + 8 + ln].decode("ascii", "replace")
            if nm == name: struct.pack_into(">I" if big else "<I", t, o + 2, newl)
            o += 8 + ln + (ln & 1)
        iso.seek(loc * S); iso.write(t)
    print(f"  \\\\{name}: directory moved {oldl} -> {newl} ({newsize} bytes)")

'''
s = s.replace("def build(out, files):", helper + "def build(out, files):", 1)
open(p, "w").write(s); print("reloc patched")
