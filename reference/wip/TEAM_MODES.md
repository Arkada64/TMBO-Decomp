# Unused team modes in TMB Online (SCUS-97196) - findings 2026-10-23

Game type = (gameinfo word 0 >> 1) & 0xF, gameinfo = *(D_003156C0 + 0x3148).
Name table D_00320E80 (+0x28): 0 NONE, 1 OVER, 2 DEATHMATCH, 3 LAST MAN STANDING, 4 MAN HUNT, 5 COLLECTOR,
**6 TEAM DEATHMATCH, 7 TEAM LAST MAN STANDING, 8 TEAM FOX HUNT, 9 TEAM COLLECTOR** (func_00174D58 returns the name).

Code that still handles 6-9:
- Waiting-room settings screen (ui.s func_001C5768, jtbl_004EEE00 over types 2..9): "MODE : TEAM DEATHMATCH",
  "MODE : TEAM LAST STANDING", "MODE : TEAM FOX HUNT", "MODE : TEAM COLLECTOR" next to the normal ones.
- HUD: hud.s 0x1468CC branches on type >= 6 (a team-only block); 0x147E70 jump table over types 2..9.
- Collector artifacts (online/after_clapper_09 func_0011A470, 0011B0B8, 0011B1D8, 0011B948, 0011C150):
  type 5 OR 9 -> collector logic.
- Fox hunt prey marker (vehicle func_001DCD48 0x1DCE78): type 4 = man hunt, type 8 = team fox hunt, reads
  client struct +0x14 (D_003156C0 + c*0x220 + 0x14) - likely the team.
- shadow func_00186730 0x186D38 checks 8 too.
- net config parser (func_00172378) reads a "[USER_TEAM]" key; "Default Team" string (func_0016E9A0 area).

Not found yet: how the lobby's create-game menu limits the mode choice to 2..5, where a client's team is set
and sent, friendly-fire / team scoring. Next test: a mod that lets the host pick 6..9 and assigns teams.
