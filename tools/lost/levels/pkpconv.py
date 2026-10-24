"""Head-On PKP (pickups) -> TMB online PKP.
Head-On: 'xx 20 28 12', 3 x u32 count, then 64-byte records {xyz, ..., u32 type @+0x2C}; type = the exe's
pickup list (0x1e3d40): 0 Machine Gun, 1 Fire Missile, 2 Homing, 3 Swarmer, 4 Ricochet, 5 Power Missile,
6 Health 30%, 7 Environment Attack, 8 Remote Bomb, 9 Full Health, 10 Mega Gun.
TMB online (func_0017BC80): magic 0x08152000, u32 count, 20-byte records {u32 type, float x, y, z, w}; type ->
model 5000+type -> weapon (D_00330408): 0 -> slot 0, 1 fire, 2 homing, 3 -> slot 5 (skill weapon pickup),
4 napalm, 5 ricochet, 6 power, 7 / 8 not weapons (health kinds), 9 -> slot 8.
  python3 pkpconv.py HC_xx.BDD OUT.PKP [scale=1.15]"""
import sys, struct, collections
sys.path.insert(0, '/home/claude/lost')
from bdd import bdd

HO2TMB = {0: None,   # machine gun (no Black equivalent): dropped
          1: 1,      # fire missile
          2: 2,      # homing
          3: None,   # swarmer (not in Black): dropped
          4: 5,      # ricochet
          5: 6,      # power missile
          6: 7,      # health 30% -> health (7 / 8: which is partial vs full unverified)
          7: 9,      # environment attack -> slot 8 (unverified)
          8: 3,      # remote bomb (not in Black) -> skill weapon pickup
          9: 7,      # full health -> health
          10: None}  # mega gun: dropped

def convert(pkp, scale=1.15):
    n = struct.unpack_from('<I', pkp, 4)[0]
    out = bytearray(); kept = 0
    seen = collections.Counter()
    for i in range(n):
        o = 16 + 64 * i
        x, y, z = struct.unpack_from('<3f', pkp, o)
        t = struct.unpack_from('<I', pkp, o + 0x2C)[0]
        tt = HO2TMB.get(t); seen[(t, tt)] += 1
        if tt is None: continue
        out += struct.pack('<I4f', tt, x * scale, y * scale, z * scale, 0.0); kept += 1
    return struct.pack('<II', 0x08152000, kept) + bytes(out) + b'\0' * 15, seen

if __name__ == '__main__':
    b = bdd(sys.argv[1]); sc = float(sys.argv[3]) if len(sys.argv) > 3 else 1.15
    d, seen = convert(b['pkp'], sc)
    open(sys.argv[2], 'wb').write(d)
    print(sys.argv[2], len(d), 'bytes', dict(sorted(seen.items())))
