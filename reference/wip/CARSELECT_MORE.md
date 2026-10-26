# Car select: more than 16 spots (TMBO) — research 2026-10-26

Goal: ~6 extra Harbor City characters on car select, each previewing a donor car, name printed with the font.
All addresses are TMBO (asm in /home/claude/tmbo/asm). Read-only research; nothing patched yet.

## 1. What bounds / indexes car select by position (carSelPos = D_004FA7D8)

### Position list and what follows it
- **shell+0x1A2F0[16]** (shell = *D_004FA03C) = car values (type << 5). Filled by the **Shell constructor
  `__5Shell` (0x186E40)** with literals at 0x1870EC..0x18715C (`sw` to 0x22F0..0x232C off shell+0x18000):
  `0x100 0xE0 0x60 0x140 0x20 0xA0 0x80 0x1A0 0x120 0x40 0x160 0x180 0x1C0 0xC0 0x1E0 0x200`.
  Entry 15 was 0x200 (type 16, the cut Warhawk / "Black Razer" spot), not 0. It is **not** copied from D_004EFBF0
  (the skins.c header says so; that is wrong).
- **Right after it is live data**: shell+0x1A330 is zeroed by the same constructor (0x187000), shell+0x1A334 /
  0x1A338 / 0x1A33C are read by the HUD (hud.s 0x145128.. many) and ui 0x1CF6F4. **No room to grow the list in place.**
  Retail: same list at shell+0x1A2C8 (getCarSelNumFromID 0x19DDA0 scans 14).
- **D_004EFBF0** (rodata, 16 words: 0x20,0x40,..,0x1E0,0) is a *type-sorted* name lookup, not the car select
  order. Used only for car names: 0x1BCF2C / 0x1CAEF0 (lobby "forced car" setting, 1-based 4-bit index) and
  0x1C5EA4 (player list, game info +0x3148 bits 22..25). Word 16+ (0x4EFC30) is the font charset table — never
  index it past 15. Side bug: skins.c's Minion hop does `car = D_004EFBF0[carSelPos]` — wrong table (shell order
  differs, e.g. pos 13 = 0xC0 in the shell, 0x1C0 here); only the one-frame engine sound is affected.

### Everything in the frame func func_001CB4C8 (0x1CB4C8)
| addr | what | bound / array |
|---|---|---|
| 0x1CB4D0..0x1CB508 | shell+0x1A2F0[pos] -> playShellCarsEngineSound (jal 0x1CB50C = tmbr_CarSelectSound) | list[16] |
| 0x1CB59C, 0x1CB694, 0x1CB8AC | hierSetSwitch(shell+0xC3C, pos) name plate (hooked: tmbr_PreviewSwitch) | 19 children |
| 0x1CB65C | same switch, pos **or 0x12** (child 18 while the arrow anim D_004FA92C/D_004FA930 runs) | |
| 0x1CB5B4, 0x1CB5F4, 0x1CB648, 0x1CB67C | shell+0xC40 arrow switch, D_004FA930 0..5 | not by pos |
| 0x1CB768 | `jal func_001CE628` — called once per move, before the step (only call site in car select) | |
| 0x1CB784 / 0x1CB7B0 | wrap constants (orig 0xE; **patched to 0xF**) right: pos==max -> 0; left: 0 -> max | |
| 0x1CB7C4..0x1CB7F0 | **D_004FA718 = D_0045CBE0[pos]** (+ D_004FA728 = D_004FB5A0 = 1): camera movie id | D_0045CBE0[16] |
| 0x1CB82C..0x1CB858 | shell+0x1A2F0[pos] -> func_0019D140 (announcer voice by car value; switch on value, unknown = silent) | list[16] |
| 0x1CB81C | (D_004FA734 == 0 path) func_0019CBC0 sfx instead of voice | |
| 0x1CB904..0x1CB948 | confirm: client(+0xA4) = shell+0x1A2F0[pos]; jal func_00173570(net,1) at 0x1CB944 (= tmbr_CarSelNet) | list[16] |
| 0x1CB9C4 | back: func_00173570(net,1) (= tmbr_CarSelNet) | |

- **D_0045CBE0[16]** (.data 0x45CBE0) filled at UI init func_001CF188 (0x1CF568..0x1CF628) with
  `5,6,..,0x13` for pos 0..14; **entry 15 is never written (0)**. Followed by **D_0045CC20 (live**, used 0x1B44E4,
  0x1CA794, 0x1CD7B0) — no room either. Only other reader: 0x1CB7C4.
- **D_004FA718** = "next movie": 5..0x14 -> car-stand camera clips `cs1..cs16` (D_004EF550) or quick-move
  `ci1_cs..ci16_cs` (D_004EF5D8, when func_001CE628 set D_004FA78C). Range check at 0x1CEA48:
  `(id-5) < 0x10`; anything else (0) = no clip, the picture stays where it was. **So the "preview" is a
  pre-rendered PSS fly-to-stand clip, not a 3D model.** 12 Pak (pos 15, id 0) just keeps the last clip's frame.

### Outside the frame func
- **Car select entry**, func_001C5768 at 0x1C6F4C..0x1C7140: switch on own client+0xA4 -> (carSelPos, D_004FA718)
  hardcoded pairs (0x100->0/5, ..., 0x20->4/9, ..., 0x1E0->14/0x13, **0x200->15/0x14**). Unknown values keep the
  old pos. A donor value maps back to the donor's pos (12 Pak today re-enters on Roadkill, pos 4).
- 0x1B4C1C (func_001B4B20, entering UI state 0x27): hierSetSwitch(shell+0xC3C, pos) — **not hooked yet**.
- 0x1B49E0 (func_001B44E0 reset): hierSetSwitch(shell+0xC30 + 4*shell[0x19C80], pos) — generic, can be C3C — not hooked.
- Memory card save func_001D24F8 (0x1D2768..0x1D2960): scans shell+0x1A2F0 (16) for 0x40/0x160/0x180/0x1C0/0x1E0
  and reads per-position flags **shell+0x1A1B4[16]** (unlock state). Load 0x1D2FD8 uses 0x1A1A0/0x1A2B8/0x1A248.
  Keep entries 0..14 untouched and these stay correct.
- Net: car select only sends the **car value** (client+0xA4, func_00173570 state 1). No position goes over the
  network, no 16-arrays keyed by position in net state. The only small field: lobby forced-car setting, 4-bit
  index into D_004EFBF0 (1..15) — extras can't be a forced car.
- hierSetSwitch (0x214210) ignores index >= child count (byte +0xB): the old child stays shown.

## 2. Preview / name plate

- SHELL1.NGP (decompressed 0xC3B40, pointers = 0x980000 + offset). Name plate switch = node **0x71DC0, id 0x8D24,
  19 children**: 0..15 per position (15 = Black Razer, repainted 12 Pak; child 12 is a 0x30-byte type-1 node,
  the others meshes), **16 = 0x71980, 17 = 0x71AD0 (texture 55: numbers / OPPONENTS), 18 = 0x71C20 (shown during
  the arrow animation)**. Contents of 16..18 not checked visually — render them (tools/lost/tmbprev.py like
  plate12pak.py) before choosing a blank. Arrow switch C40 needs >= 6 children (not located).
- Preview for an extra position = the donor's stand clip: give the extra spot movie id 5 + donorPos (or 0 to stay
  on the current picture when the donor did not change). Engine sound comes from the list value (donor), the
  announcer voice too (would say the donor's name — suppress for extras).
- Name: font print each frame from the car select hook (guests.c already prints "PLAYER n" there via
  fontSetCursorAtSubPixel / func_00203150), plate switch set to a blank child (18 if it is blank, else hide).
  Plate screen position must be measured once.

## 3. Minimal plan: virtual positions (recommended)

Keep the game's carSelPos in 0..15 so no table is ever read out of range; extra characters are "sub-positions"
of game pos 15. Mod state `xpos`: 15 = 12 Pak, 16..15+N = extras (donor value, donor pos, name).

1. **New hook 0x1CB768** `jal func_001CE628` -> `jal tmbr_CarSelStep` (call the original first). dir =
   D_004FA8B0 ? +1 : -1 (same rule as s0). Before the game's step:
   - carSelPos 14, +1 -> xpos = 15. carSelPos 0, -1 -> xpos = 15+N.
   - carSelPos 15, +1, xpos < 15+N -> xpos++, set carSelPos = 14 (game steps to 15).
   - carSelPos 15, -1, xpos > 15 -> xpos--, set carSelPos = 0 (game wraps to 15; wrap constant already 0xF).
   - then write shell+0x1A2F0[15] = value(xpos) and D_0045CBE0[15] = movie(xpos) (0 for 12 Pak / same donor),
     so the game's own reads at 0x1CB7C4, 0x1CB82C and confirm 0x1CB904 pick them up this frame.
2. tmbr_CarSelectSound (0x1CB50C, frame start): keep list[15] = value(xpos) every frame (already does 0x20);
   12 Pak flag = carSelPos==15 && xpos==15; extras: skin id = xpos; print name when xpos >= 16.
3. tmbr_PreviewSwitch: for pos 15 pick child 15 (12 Pak) or the blank child for extras. Also hook
   **0x1B4C1C** and **0x1B49E0** (latter: only remap when sw == *(shell+0xC3C)).
4. Optional **0x1CB854** `jal func_0019D140` -> wrapper that skips the voice for extras.
5. Entry (0x1C6F4C mapping): to land back on the extra, in the first car select frame set carSelPos = 15 and
   xpos = own choice if this console has an extra on (12 Pak has the same gap today).
6. In game: extras are the donor type + a synced id (extend skins.c: NSKIN tables, "\x01SK" message, remote[8][],
   vehCodes swap per client for the model files, lobby name hook tmbr_LobbyCarNameS). guests.c reads
   shell+0x1A2F0[carSelPos] (tmbr_CarSelNet 0x1CB944/9C4 path, tmbr_GuestPickEnd) — fine with virtual pos, but
   a guest's extra choice needs the id passed too.

Patch count: 1 new jal (0x1CB768) + 2 more PreviewSwitch call sites (+1 optional voice). No new constants.

### Alternative: real positions 16..15+N (more patches, more risk)
Wrap consts 0x1CB784/0x1CB7B0 -> 15+N; redirect D_0045CBE0 (lui/addiu at 0x1CB7C4/0x1CB7C8 -> own table
initialised `5..0x13, 0, ...`); hook 0x1CB854 (voice reads shell+0x1A330+ = HUD fields); fix client+0xA4 in
tmbr_CarSelNet for every pick (0x1CB92C reads past the list); skins.c `% (PAK_POS+1)` and D_004EFBF0[carSelPos];
guests.c two shell+0x1A2F0[carSelPos] reads; plate calls for pos >= 19 silently keep the old plate. The frame-start
read at 0x1CB508 would read live HUD words (harmless, value replaced by the hook).

### Risks
- Wrong-table / OOB reads listed above if any code still indexes by a position >= 16.
- Two extras on one donor type are only told apart by the synced id; unmodded clients see the donor.
- Clip choice: a fly-in to the same stand replays; use id 0 when the donor stays the same.
