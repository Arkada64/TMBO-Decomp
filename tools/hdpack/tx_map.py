# TMB HD pack -> TMBO/TMBR names. PCSX2 names = texhash-cluthash-bits (bits: PSM 6, TW 4, TH 4, TCC 1, ...).
# A 2P TMBR match dumped 467 textures: 369 share texture + CLUT hash with the pack and differ only in TCC (bit 14,
# TMBO draws them with TCC 0) - 11 of them also T8 vs T8H (0x13 / 0x1B, bit 3). Rule: clear bit 14; the observed
# T8H ones get the dump's exact name. Hard links (no copy).
# usage: tx_map.py Textures/SCUS-97101/replacements Textures/SCUS-97196/replacements dumped_2p_match.txt [aliases.txt]
import os, sys
src, dst, dumped = sys.argv[1], sys.argv[2], sys.argv[3]
os.makedirs(dst, exist_ok=True)
seen = {}
for l in open(dumped):
    x = l.strip().split('-')
    if len(x) == 3: seen[(x[0], x[1])] = x[2]
n = links = 0
for f in os.listdir(src):
    base, ext = os.path.splitext(f); x = base.split('-')
    if len(x) == 3:
        b = int(x[2], 16)
        new = seen.get((x[0], x[1])) or '%08x' % (b & ~0x4000)
        if (b ^ int(new, 16)) & ~0x4008: new = '%08x' % (b & ~0x4000)
        name = '%s-%s-%s%s' % (x[0], x[1], new.lower(), ext)
    elif len(x) == 2:                                  # direct-colour textures: hash-bits, same TCC difference
        name = '%s-%08x%s' % (x[0], int(x[1], 16) & ~0x4000, ext)
    else:
        name = f
    t = os.path.join(dst, name)
    if not os.path.exists(t):
        os.link(os.path.join(src, f), t); links += 1
    n += 1
al = 0
if len(sys.argv) > 4:                                  # aliases.txt: same texture, near palette (TMBO recoloured slightly)
    for l in open(sys.argv[4]):
        if l.startswith('#') or not l.strip(): continue
        k, f = l.split(); t = os.path.join(dst, k + os.path.splitext(f)[1])
        if not os.path.exists(t): os.link(os.path.join(src, f), t); al += 1
print('files', n, 'linked', links, 'aliases', al)
