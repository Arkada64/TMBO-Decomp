# Unused team modes in TMB Online (SCUS-97196) - findings 2026-10-23

## Game info (network object, pointer at net D_003156C0 + 0x3148, 0xC8 bytes, owned by the host)
word 0:
- bit 0: ?            - bits 1-4: game type (0 NONE, 1 OVER, 2 DM, 3 LMS, 4 MAN HUNT, 5 COLLECTOR,
  **6 TEAM DM, 7 TEAM LMS, 8 TEAM FOX HUNT, 9 TEAM COLLECTOR**; names D_00320E80 / func_00174D58)
- bit 5, bits 6-9 (default 1), bits 10-11 = fox pass rule (0 none, 1 next in order, 2 killer, 3 random; default 2)
- **bit 12 = TEAMS ON** (separate from the type). bit 13, 14, 15, bits 16-21 other options.
- +0x4 max players (default 8), +0x1A fox slot (team 0 / man hunt), **+0x1B fox slot for team 1**, +0x1C ...
Defaults when becoming session master: func_00176CC8 (type 2, teams off, foxes -1).
Host settings copy: func_001C75C0(gameinfo, D_0045FAC8) copies bit 12 and +0x1B through, but nothing ever sets it.

## Team of a player
- client struct D_003156C0 + i*0x220: +0x10 client id, **+0x14 team** (-1 = none), +0x18 name.
- Cleared to -1 on connect (func_0016EF90). The ONLY writer of a real value: entering the waiting room
  (func_001C5430 end) sets *(net+4)+4 = my own client's +0x14 to the "[USER_TEAM]" net-config value
  (parsed in func_00172378 into net+0x1994) or 0. **Teams are never sent to other machines**: every remote
  client stays -1. No team-pick UI exists.

## Code that still works with teams (bit 12 + client +0x14)
- Lock-on / auto-target (func_0015A650, used by every weapon + FireSpecial): skips teammates.
- Damage stats (func_001740B0): teammate damage not credited. Real damage is NOT blocked: friendly fire on.
- Radar blip colour (hud func_00149D08 0x14A924) and car marker colour (func_001DCD48): colour = team (0/1)
  instead of the player colour. Team fox hunt: team 0 fox colour 7, team 1 fox colour 8.
- HUD score list has a type>=6 layout branch (hud func_00145860 0x1468CC); jump table over 2..9 at 0x147E70.
- Team fox hunt: fox death -> new fox picked inside the dead fox's team (func_00172FE8 using
  func_001731A8 next-on-team / func_00173248 random-on-team, writes +0x1A or +0x1B).
- Team collector: after_clapper_09 artifact code treats 9 like 5; drop-artifact input checks 9 (func_00159F88, 0015A0B8).
- Waiting room text "MODE : TEAM ..." (ui func_001C5768).

## What is missing / cut
- Mode choice: the settings editor dispatch (func_001B2B68 0x1B3A64) only has editors for 2..5; any other
  type is reset to Deathmatch (type 2) via func_001C7B60. All four presets clear bit 12.
- Team assignment and sync (above).
- Per-frame net game logic func_00172A90 only runs for 4 (picks the first fox = host) and 5; types >= 6
  skip it, so Team Fox Hunt never picks its first foxes (+0x1A/+0x1B stay -1) and Team Collector skips
  the type-5 net handling.
- No team score / team win strings anywhere ("RED/BLUE TEAM WINS" etc. do not exist).

## Trying it
A pnach cannot: game info is a dynamically allocated net object (pointer) and teams must be set on every
machine. A small mod can (host: after the settings screen set type 6..9 + bit 12; every machine: team =
client id & 1 for all 8 clients, so no sync needed; Team Fox Hunt: host picks +0x1A/+0x1B).
Expected: TDM = DM with team radar colours and no lock-on to teammates (friendly fire still hurts);
TLMS probably plays like DM (no team elimination); TFH needs the first-fox fix; TC like Collector.
