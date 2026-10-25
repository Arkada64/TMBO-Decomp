# elfcrc.py ELF... : PCSX2's game CRC of an ELF (XOR of all 32-bit words), as used in gamesettings/<serial>_<CRC>.ini
import struct, sys
def crc(p):
    d = open(p, 'rb').read(); d += b'\0' * (-len(d) % 4)
    c = 0
    for (w,) in struct.iter_unpack('<I', d): c ^= w
    return c
if __name__ == '__main__':
    for p in sys.argv[1:]: print('%08X' % crc(p), p)
