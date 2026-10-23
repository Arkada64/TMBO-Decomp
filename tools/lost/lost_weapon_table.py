import re,struct,sys
L=open('/home/claude/lost/headon.dis').read().split('\n')
s=next(i for i,l in enumerate(L) if l.startswith('  1fd4e0:'))
e=s+1565
base={}; fr={}; gr={}; at=0
stores={}
def num(x): return int(x,16) if x.lstrip('-').startswith('0x') else int(x)
for l in L[s:e+2]:
    m=re.search(r'^\s+([0-9a-f]+):\s+[0-9a-f]+\s+(\S+)\s*(.*)$',l)
    if not m: continue
    ad,op,args=m.groups(); a=args.split(',')
    if op=='addu' and a[1]=='$25':
        if a[2] in gr: base[a[0]]=gr[a[2]]-0xb930; continue
    if op=='lui' and a[0]=='$1': at=num(a[1])<<16
    elif op=='ori' and a[0]=='$1' and a[1]=='$1': at|=num(a[2])
    elif op=='mtc1':
        if a[0]=='$1': fr[a[1]]=round(struct.unpack('<f',struct.pack('<I',at&0xffffffff))[0],4)
        elif a[0]=='$0': fr[a[1]]=0.0
        else: fr[a[1]]=('i',gr.get(a[0]))
    elif op=='cvt.s.w':
        v=fr.get(a[1]); fr[a[0]]=float(v[1]) if isinstance(v,tuple) and v[1] is not None else None
    elif op=='mov.s': fr[a[0]]=fr.get(a[1])
    elif op in('lwc1',): fr[a[0]]='mem'
    elif op in('add.s','mul.s','sub.s','div.s'): fr[a[0]]=('expr',op,fr.get(a[1]),fr.get(a[2]))
    elif op in('addiu','daddiu') and a[1] in base: base[a[0]]=base[a[1]]+num(a[2])
    elif op=='addiu' and a[1]=='$0': gr[a[0]]=num(a[2]); base.pop(a[0],None)
    elif op=='dli': gr[a[0]]=num(a[1]); base.pop(a[0],None)
    elif op in('daddu','addu') and a[2]=='$0' and a[1] in base: base[a[0]]=base[a[1]]
    elif op=='swc1':
        mm=re.match(r'(-?\d+)\((\$\d+)\)',a[1])
        if mm and mm.group(2) in base: stores[base[mm.group(2)]+int(mm.group(1))]=('f',fr.get(a[0]),ad)
    elif op in('sw','sh','sb'):
        mm=re.match(r'(-?\d+)\((\$\d+)\)',a[1])
        if mm and mm.group(2) in base: stores[base[mm.group(2)]+int(mm.group(1))]=(op,0 if a[0]=='$0' else gr.get(a[0]),ad)
    elif op in('beq','bne','bnel','beql','jal','j','jr','bgez','blez','bgtz','bltz'): pass
    else:
        if a and a[0] in base: base.pop(a[0],None)
        if a and a[0] in gr: gr.pop(a[0],None)
print('stores',len(stores),'max type',max(stores)//148 if stores else 0)
for t in map(int,sys.argv[1:]):
    print('type',t)
    for f in range(0,148,4):
        v=stores.get(148*t+f)
        if v: print('  +%d'%f, v)
