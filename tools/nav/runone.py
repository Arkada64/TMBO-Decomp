import sys, time, pickle, numpy as np
from navgen import *
name = sys.argv[1]; t = time.time()
L = Level(f'online_{name}.ngp'); L.walk(); S = sources(L)
R = rasterize(L, 4.0, S); H = surfaces(R)
np.save(f'{name}_H.npy', H)
pickle.dump({k: R[k] for k in ('x0', 'y0', 'nx', 'ny', 'step')}, open(f'{name}_R.pkl', 'wb'))
print(name, 'grid', R['nx'], R['ny'], 'ground %.2f multi %.3f' % (np.isfinite(H[0]).mean(), np.isfinite(H[1]).mean()), '%.1fs' % (time.time() - t), flush=True)
