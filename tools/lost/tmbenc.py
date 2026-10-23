"""Encode a mesh into a TMB HierObject (op0) VIF packet.
mesh: {'batches': [ {'pool': [(x,y,z)...], 'strips': [ {'tag': (nloop?,prim,regs,texsel), 'v': [(nx,ny,nz,idx),(r,g,b,a),(u,v)]...} ]} ]}"""
import struct
def vif_packet(batches):
    w=[]  # words after the DMA tag's first 2 words
    for bi,b in enumerate(batches):
        if bi>0: w+=[0x01000404,0x11000000]
        w+=[0x600100b4,len(b['pool'])]
        if bi==0: first_two=w[:2]; w=[]
        w.append(0x680040b5|(len(b['pool'])&0xff)<<16)
        for p in b['pool']: w+=list(struct.unpack('<3I',struct.pack('<3f',*p)))
        w+=[0x14000000,0x00000000,0x01000103]
        for s in b['strips']:
            n=len(s['v'])
            prim,regs,texsel=s['tag'][1],s['tag'][2],s['tag'][3]
            w+=[0x6c018000,0x8000|n,prim,regs,texsel]
            w.append(0x6e00c001|(n<<16)); w+=[struct.unpack('<I',struct.pack('<3bB',*v[0]))[0] for v in s['v']]
            w.append(0x6e00c002|(n<<16)); w+=[struct.unpack('<I',struct.pack('<4B',*v[1]))[0] for v in s['v']]
            w.append(0x75008003|(n<<16)); w+=[struct.unpack('<I',struct.pack('<2h',*v[2]))[0] for v in s['v']]
            w.append(0x17000000)
    w.append(0x01000404)
    while len(w)%4: w.append(0)
    qwc=len(w)//4
    return struct.pack('<4I',0x60000000|qwc,0,*first_two)+struct.pack('<%dI'%len(w),*w)
