import sys, numpy as np, pickle, time
sys.path.insert(0, '/home/claude/nav')
import navgen
from navbuild import build, pack, preview
src = open('/home/claude/nav/navall.py').read(); exec(src[src.index('def largest'):src.index('table = []')])
for f in sys.argv[1:]:
    t = time.time()
    L = navgen.Level(f'/home/claude/hc/out/{f}.NGP'); L.walk()
    S = navgen.sources(L); R = navgen.rasterize(L, 4.0, S); H = navgen.surfaces(R)
    for lat in (8, 9, 10, 12):
        G = largest(build(H, R, lat)); b = pack(G, R)
        if len(b) <= 894976: break
    open(f'/home/claude/hc/out2/{f}.ZN', 'wb').write(b)
    preview(H, G, R, f'/home/claude/hc/out2/{f}_nav.png')
    print(f, 'bsp', len(L.bsp), 'nodes', len(G['rec']), 'bytes', len(b), 'cell', lat * 4, '%.0fs' % (time.time() - t), flush=True)
