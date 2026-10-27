# retail story movies -> packs/MOV (once; a file already there with the right size is left alone)
import re, os
W = "/mnt/c/Users/Ark/Desktop/TMB Decomp/"
ISO = W + "Twisted Metal - Black.iso"
pat = re.compile(r"^\s*(\d+)\s+(\d+)\s+/MOV/((X\d\d[ABC])|([A-Z][A-Z](ARENA|ROOF))|MINION|VICTORY|CREDITS|(LL\d+))\.PSS$", re.I)
n = done = 0
with open(ISO, "rb") as iso:
    for line in open(W + "ls_retail.txt"):
        m = pat.match(line.rstrip())
        if not m: continue
        lba, size, name = int(m.group(1)), int(m.group(2)), m.group(3).upper()
        dst = W + "packs/MOV/%s.PSS" % name
        n += 1
        if os.path.exists(dst) and os.path.getsize(dst) == size: continue
        iso.seek(lba * 2048); left = size
        with open(dst + ".tmp", "wb") as f:
            while left:
                b = iso.read(min(left, 1 << 22)); f.write(b); left -= len(b)
        os.replace(dst + ".tmp", dst); done += 1
print("movies", n, "extracted", done)
