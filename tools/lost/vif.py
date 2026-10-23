import struct
def u32(d,o): return struct.unpack_from('<I',d,o)[0]
VL={0:4,1:2,2:1,3:2}  # bytes per component; vl=3 is V4-5 special
def unpack_size(vn,vl,num):
    if vn==3 and vl==3: return 2*num
    return (vn+1)*VL[vl]*num
def parse(d,o,end,log=print):
    """yield (offset, cmd, num, imm, payload_offset, payload_len)"""
    out=[]
    while o<end:
        c=u32(d,o); cmd=(c>>24)&0x7f; num=(c>>16)&0xff; imm=c&0xffff
        p=o+4; plen=0
        if cmd>=0x60:
            vn=(cmd>>2)&3; vl=cmd&3; n=num or 256
            plen=(unpack_size(vn,vl,n)+3)&~3
        elif cmd==0x20: plen=4
        elif cmd in (0x30,0x31): plen=16
        elif cmd==0x4a: plen=(num or 256)*8
        elif cmd in (0x50,0x51): plen=(imm or 65536)*16
        elif cmd in (0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x10,0x11,0x13,0x14,0x15,0x17): plen=0
        else:
            out.append((o,'BAD',c)); break
        out.append((o,cmd,num,imm,p,plen))
        o=p+plen
    return out
if __name__=='__main__':
    import sys
    from bdd import bdd
    n=bdd(sys.argv[1])['ngp']; s=int(sys.argv[2],16); e=int(sys.argv[3],16)
    for r in parse(n,s,e):
        if r[1]=='BAD': print(hex(r[0]),'BAD',hex(r[2])); break
        o,cmd,num,imm,p,pl=r
        print(hex(o),hex(cmd),num,hex(imm),pl)
