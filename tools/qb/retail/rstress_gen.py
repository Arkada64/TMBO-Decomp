#!/usr/bin/env python3
"""rstress_gen.py N [LEVEL_RIGHTS] > rq_sN.json : retail split-screen stress script - Multi-Player, the N-player
death match options -> free-for-all (2P best of / 3P FFA / 4P FFA), everyone picks the default car, the level (Suburbs + RIGHT presses),
then all N players drive and fire in a loop (no START: never pauses)."""
import json, sys
n = int(sys.argv[1]); rights = int(sys.argv[2]) if len(sys.argv) > 2 else 0
row = {2: 0, 3: 2, 4: 4}[n]
allp = lambda b: [b] * 4
s = [[1200, ""], [8, "START"], [232, ""], [8, "START"], [232, ""], [8, "START"], [832, ""], [8, "DOWN"], [52, ""], [8, "CROSS"], [292, ""],
     [8, "CROSS"], [292, ""]]                                     # Multi-Player, then its first entry (death match)
for _ in range(row): s += [[8, "DOWN"], [52, ""]]
s += [[8, "CROSS"], [292, ""]]
for _ in range(n): s += [[8, *allp("CROSS")], [232, ""]]          # car select, one player after the other
for _ in range(rights): s += [[8, "RIGHT"], [52, ""]]             # level
for _ in range(4): s += [[8, *allp("CROSS")], [292, ""]]          # level + whatever confirm follows (gas in game)
loop = len(s)
s += [[70, *allp("CROSS+R1+LEFT")], [50, *allp("CROSS+L1")], [70, *allp("CROSS+R1+RIGHT")], [40, *allp("CROSS+L1+R1")],
      [30, *allp("SQUARE+LEFT")], [60, *allp("CROSS+R1")]]
print(json.dumps({"keys": [0, 1, 2, 3], "steps": s, "loop_from": loop}))
