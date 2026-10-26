#!/usr/bin/env python3
"""tracegen.py OUTDIR : quick-boot scripts for the traffic route trace (TRAFFIC_TRACE build): host a match on each
traffic level with traffic ON and no bots, then sit still ~100 s while traffic.c logs every car every 0.5 s."""
import json, sys, os
base = json.load(open(os.path.join(os.path.dirname(__file__), '../qb/stress/qb_stress_suburbs.json')))['steps']
pre, post = base[:17], base[17:]            # level list is up after step 16
i = [k for k, s in enumerate(post) if s[0] == 'R3+R1']
post = post[:i[0] + 2] + post[i[-1] + 2:]   # one bot (a match needs 2 cars to start)
post = post[:post.index(['', 1500]) + 1]      # up to the match start; then wait
LV = dict(suburb=('RIGHT', 0), freeway=('RIGHT', 2), city=('RIGHT', 5), loop=('RIGHT', 6), minicity=('LEFT', 4), miniburb=('LEFT', 3))
for name, (key, n) in LV.items():
    steps = pre + sum([[[key, 6], ['', 240]] for _ in range(n)], []) + post + [['CROSS', 6], ['', 120]] * 8 + [['', 7000]]   # (CROSS starts the match, as in the stress runs)
    json.dump({'steps': steps, 'stop': 165 + 4 * n + 110}, open(os.path.join(sys.argv[1], f'qb_trace_{name}.json'), 'w'))
print('ok')
