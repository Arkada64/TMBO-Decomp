"""Outlaw 2's siren lights (Ark 2026-10-27: Outlaw's flashing beacons on Outlaw 2's own light bar): Outlaw's beacon
lights (op5, SUP 0x662d0 red / 0x660b0 blue: range 3-4, colour (0.65, .05, .05) / (.05, .05, .85)) copied onto the
light bar of the built car, two red on the left half and two blue on the right, under a 2-child switch with attach
id R+7 and sub SUB (registered by the game at vehicle +0x2A20 + SUB * 4); mods/skins.c alternates it (red / blue).
The switch rides next to the headlight switch (R+9): its parent slot gets a group of both.
  python3 sirens.py DIR CODE [x1,x2,y,z]      (in place: DIR/CODE.NGP / .PTR; default bar = Outlaw 2's)"""
import sys, struct
from tmbcar import Car, u32, BASE
from hcbuild import traverse_check

SUB = 12
RED = bytes.fromhex('05000000' '0f000000' '00004040' 'e244dd41') + struct.pack('<4f', 0, 0, 0, 1) + \
    struct.pack('<4f', 0, 0, -1, 0) + struct.pack('<4f', 0.65, 0.05, 0.05, 0.5)
BLUE = bytes.fromhex('05000000' '0f000000' '00008040' 'e07fff41') + struct.pack('<4f', 0, 0, 0, 1) + \
    struct.pack('<4f', 0, 0, -1, 0) + struct.pack('<4f', 0.05, 0.05, 0.85, 0.5)


def main(d, code, bar='1.55,2.15,0.12,2.95'):
    x1, x2, y, z = [float(v) for v in bar.split(',')]
    rd = lambda e: open('%s/%s.%s' % (d, code, e), 'rb').read()
    car = Car(rd('NGP'), rd('PTR'), b'', b'')
    n = car.n
    R = u32(n, u32(n, 4) - BASE) >> 18
    seen, _ = traverse_check(bytes(n), car.slots)
    assert not any(u32(n, o) & 0x3f == 6 and (u32(n, o) >> 18) == R + 7 and (u32(n, o) >> 7) & 0x7ff == SUB
                   for o in seen), 'sirens already added'
    sw9 = next(o for o in seen if u32(n, o) & 0x3f == 6 and (u32(n, o) >> 18) == R + 9)
    pslot = next(s for s in car.slots if car.P(s) == sw9)

    def light(blob, x):
        lo = car.append(blob)
        t = car.append(struct.pack('<IIiI3fI', 3, 0, 1, 0, x, y, z, 0))       # op3 move, one child
        car.setp(t + 0x1c, lo)
        return t
    red = car.group([light(RED, -x1), light(RED, -x2)], sphere=(-(x1 + x2) / 2, y, z, 3.0))
    blue = car.group([light(BLUE, x1), light(BLUE, x2)], sphere=((x1 + x2) / 2, y, z, 3.0))
    sw = car.append(struct.pack('<IIBBBB', 6 | (SUB << 7) | ((R + 7) << 18), 0, 0, 0, 0, 2) + b'\0' * 8)
    car.setp(sw + 0xc, red); car.setp(sw + 0x10, blue)
    g = car.group([sw9, sw], sphere=(0, 0, 0, 30.0))
    car.setp(pslot, g)
    _, bad = traverse_check(bytes(car.n), car.slots)
    assert not bad, bad[:3]
    open('%s/%s.NGP' % (d, code), 'wb').write(car.ngp_bytes())
    open('%s/%s.PTR' % (d, code), 'wb').write(car.ptr_bytes())
    print('%s: siren switch %#x (R+7 sub %d), red at x -%.2f / -%.2f, blue at +, y %.2f z %.2f' % (code, sw, SUB, x1, x2, y, z))


if __name__ == '__main__':
    main(*sys.argv[1:])
