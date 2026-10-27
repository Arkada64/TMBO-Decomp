# Story phase 2: movies - retail movie tables, story flow, TMBO player

Research notes (read-only pass over retail splat asm + TMBO asm). All addresses are EE RAM.
"shell+X" below means `shell + 0x18000 + X` unless written as a full offset (retail globals via $gp).

## 1. Filename construction (retail)

- `Shell::formatMovieFilename(char* out, const char* dir, const char* name, const char* ext)` 0x162C28
  (static, no `this`): `sprintf(out, "%s/%s.%s", dir, name, ext)` (fmt D_004E80D0), then uppercases `out`.
  Always called with dir = "mov" (D_004FAFF0), ext = "pss" (D_004FAFF8) -> `"MOV/X01A.PSS"`.
- `strFileOpen(StrFile*, char*)` 0x1EE8D8: '/' -> '\\', uppercase, `sprintf("%s%s%s", "\\", path, ";1")`
  -> `\MOV\X01A.PSS;1`, then `fileCdSearchFile` + `sceCdStStart`. So the on-disc name is `\MOV\<NAME>.PSS;1`.
- Name "none" is a sentinel: callers strcmp the formatted name against "MOV/NONE.PSS" (D_004EB228) and
  then play mov/none.pss with audio=0 (it is a short black clip). nextMovie 0x88 = "mov/none.pss" (black).
- TMBO has the same helper: `formatMovieFilename` 0x189E50, "mov" D_004FA640, "pss" D_004FA648.

## 2. Character index

`characterMovieNum` = car-select slot (0..13) = `getCarSelNumFromID(carValue) - 1`
(getCarSelNumFromID 0x19DDA0 searches shell+0x22C8[16], i.e. full offset shell+0x1A2C8, for the player's
car value `shell+0x1DA4`). The table is filled in the Shell constructor (stores around 0x15F51C):

| slot | car value | type (>>5) | car (carNames 0x4464A0) | intro (a) | midgame (b) | ending (c) | arena | roof |
|---|---|---|---|---|---|---|---|---|
| 0 | 0x100 | 8 | Junkyard Dog | X01A | X01B | X01C | BRARENA | BRROOF |
| 1 | 0x0E0 | 7 | Brimstone | X02A | X02B | X02C | PRARENA | PRROOF |
| 2 | 0x060 | 3 | Outlaw | X03A | X03B | X03C | SWARENA | SWROOF |
| 3 | 0x140 | 10 | Mr. Grimm | X04A | X04B | X04C | GRARENA | GRROOF |
| 4 | 0x020 | 1 | Roadkill | X05A | X05B | X05C | JDARENA | JDROOF |
| 5 | 0x0A0 | 5 | Crazy 8 | X06A | X06B | X06C | NFARENA | NFROOF |
| 6 | 0x080 | 4 | Spectre | X07A | X07B | X07C | BMARENA | BMROOF |
| 7 | 0x1A0 | 13 | Darkside | X08A | X08B | X08C | DFARENA | DFROOF |
| 8 | 0x120 | 9 | Shadow | X09A | X09B | X09C | SSARENA | SSROOF |
| 9 | 0x040 | 2 | Yellow Jacket | X10A | none | X10C | TXARENA | TXROOF |
| 10 | 0x160 | 11 | Axel | none | none | X11C | AXARENA | AXROOF |
| 11 | 0x180 | 12 | Warthog | none | none | X12C | WHARENA | WHROOF |
| 12 | 0x1C0 | 14 | Manslaughter | none | none | X13C | BLARENA | BLROOF |
| 13 | 0x0C0 | 6 | Sweet Tooth | X14A | X14B | X14C | STARENA | STROOF |
| 14 | 0x1E0 | 15 | Minion | - | - | - | - | - |
| 15 | 0x200 | 16 | Warhawk/DarkHawk | - | - | - | - | - |

Car type -> name (carNames / hudCarNames order): 1 Roadkill, 2 Yellow Jacket, 3 Outlaw, 4 Spectre, 5 Crazy 8,
6 Sweet Tooth, 7 Brimstone, 8 Junkyard Dog, 9 Shadow, 10 Mr. Grimm, 11 Axel, 12 Warthog, 13 Darkside,
14 Manslaughter, 15 Minion, 16 Warhawk. Slot >= 14 (`characterNum >= 0xE`) plays no story movie (none.pss).
The arena/roof prefixes are driver initials (PR Preacher, JD John Doe, NF No-Face, BM Bloody Mary, DF Dollface,
TX taxi, ...), which matches the slot mapping. The slot mapping assumes the memory card has not reordered
shell+0x1A2C8 (uimemcard.s also touches that table; probably the unlock state only, not verified).

Tables (8-byte entries; playMovie copies them to the stack):
- intro `x??a` D_004EB730, midgame `x??b` D_004EB7A0, ending `x??c` D_004EB810 (14 entries each)
- arena `??Arena` D_004EB880, roof `??Roof` D_004EB8F8 (15 entries, 15th "none")
- story level-load `ll0..ll10` D_004EBEB8 (11 entries; the splat shows them as .word since they are 3-char strings)
- Movies-menu copies (uiMovies 0x190760): D_004EB048 `mp01..mp14, mpcred` (poster names), D_004EB0C0/
  D_004EB138/D_004EB1B0 = the same a/b/c lists + "credits".
- Others: `cs1..cs16`/`cs10d..` D_004EB970/D_004EB9F8, `ci1..ci16` D_004EBA80, `csN_ci` D_004EBB08, `ciN_cs` D_004EBB90
  (char-select transitions, nextMovie 5..0x14); `ls0..ls20` D_004EBC18, `lk0..lk20` D_004EBCC0,
  `lsnb0..20` D_004EBD68, `lknb0..20` D_004EBE10 (generic level-load clips, nextMovie 0x46+level; 1-in-10 or
  forceBlink picks the blink version; lk*/lknb* when shell+0x1A1CC[level]==1). Fixed: minion.pss 0xCA,
  victory.pss 0xCB, credits.pss 0xC9.

## 3. Retail nextMovie numbers (playMovie 0x19A9F0)

| nextMovie | file | args (audio, allowInterrupt) |
|---|---|---|
| 0x78..0x82 | `mov/ll<n>.pss`, n = nextMovie-0x78 | (0, 0) |
| 0x83 | intro `x??a`[characterMovieNum]; skipped if shell+0x2220[slot] != 0 | (1, 1); none -> (0, 0) |
| 0x84 | arena `??Arena`[slot] | (1, 0) |
| 0x85 | midgame `x??b`[slot] | (1, 1); none -> (0, 0) |
| 0x86 | roof `??Roof`[slot] | (1, 0) |
| 0x87 | ending `x??c`[slot] | (1, 1); none -> (0, 1) |
| 0x88 | mov/none.pss (black) | (0, 0) |
| 0xC9 / 0xCA / 0xCB | credits / minion / victory | (1, 1) / (1, 0) / (1, 0) |

0x84..0x87 recompute `characterNum = (car>>5)-1` and `characterMovieNum = getCarSelNumFromID(car)-1` from
shell+0x1DA4; 0x83 uses the values uiLoadLevel / car select already set.

## 4. When each movie plays (retail story flow)

Story stage = `m_levelStoryNumMap[level]` (0x426570): 0 SUBURBS->2, 1 JUNKYARD->1, 2 FREEWAY->2,
3 PRISON PASSAGE->5, 4 SKYSCRAPERS->7, 5 DOWNTOWN->3, 6 HIGHWAY LOOP->3, 8 SNOWY ROADS->6, 12 DRIVE-IN MOVIE->6,
14 MINIONS STADIUM->4, 20 WARHAWKS ROOF->8, others -1. (Level names: Shell::m_levelScreenName 0x426250.)

Win path (EvaluateOnePlayerStoryStatus 0x15FEB0, jtbl_004E7B60 on current level shell+0x2354):
1 Junkyard -> dialog 0xF (pick Suburbs/Freeway); 0/2 -> dialog 0xF (pick Downtown/Loop); 5/6 -> level 14;
14 -> level 3; 3 -> dialog 0xF (pick Snowy Roads/Drive-In); 8/12 -> level 4; 4 -> level 20; 20 -> shell+0x2308=1 (done).

Back in uiMain (0x18E9A8.., when shell+0x2364==1, i.e. returning from a won story level), the screen is chosen from
the NEW level shell+0x2354:
- shell+0x2308==1 (roof won) -> screen 0x6C uiPlayEndMovie 0x193EA8: 0x87 ending (game mode shell+0x235C==1; other
  modes play 0xCB victory), then 0x88 black, then 0xCA minion.pss if this is the first character finished
  (count of shell+0x2290[] == 1), then save / credits (uiPlayCreditsMovieEtc 0x194338 -> 0xC9).
- next == 14 Minion Stadium -> screen 0x6A uiPlayArenaMovie 0x1939F0 -> 0x84 `??Arena`.
- next == 3 Prison Passage -> screen 0x64 uiPlayMidgameMovie 0x193B28 -> 0x85 `x??b`, then 0x88, then saveGame(0x54).
- next == 20 Warhawk roof -> screen 0x6B uiPlayRoofMovie 0x193D70 -> 0x86 `??Roof`.
- otherwise -> screen 0x5A uiLoadLevel.
All four movie screens go to 0x5A uiLoadLevel when done. In game mode 4 (shell+0x235C==4) they play 0x88 instead.

New story: playCharIntro 0x1938F8 -> 0x83 `x??a` (0x88 if shell+0x2220[slot]==2, mode 4, or slot >= 14),
then screen 0x5A.

uiLoadLevel 0x194C60 (screen 0x5A), once per load (`triggeredLevelLoadMovie`), jtbl_004EB5C0 on shell+0x2354:

| level | ll file | nextMovie | milepostSwitch | stage |
|---|---|---|---|---|
| 1 Junkyard | LL0 | 0x78 | 0 | 1 |
| 0 Suburbs | LL1 | 0x79 | 1 | 2 |
| 2 Freeway | LL2 | 0x7A | 1 | 2 |
| 5 Downtown | LL3 | 0x7B | 2 | 3 |
| 6 Highway Loop | LL4 | 0x7C | 2 | 3 |
| 14 Minion Stadium | LL5 | 0x7D | 3 | 4 |
| 3 Prison Passage | LL6 | 0x7E | 4 | 5 |
| 4 Skyscrapers | LL7 | 0x7F | 6 | 7 |
| 8 Snowy Roads | LL8 | 0x80 | 5 | 6 |
| 12 Drive-In | LL9 | 0x81 | 5 | 6 |
| 20 Warhawk Roof | LL10 | 0x82 | 7 | 8 |

Other levels: movieEnable = 0, no movie. The ll clips are character-independent.
The milepost value goes to hierSetSwitch(shell+0x1C2C). The switch is not gated on game mode in this code; I did not
check whether non-story loads reach screen 0x5A.

Per character the full story order is:
X..A -> LL0 Junkyard -> LL1/LL2 -> LL3/LL4 -> ??ARENA + LL5 Stadium -> X..B + LL6 Prison Passage
-> LL8/LL9 -> LL7 Skyscrapers -> ??ROOF + LL10 Roof -> X..C (+ MINION / CREDITS).

## 5. Playing a movie

Retail:
- `playMpegMovieWithDB(char* path, bool withAudio, int allowInterruption)` 0x1DEDA0: stores the flags
  (isWithAudio, gAllowInteruption), opens the stream (initAll 0x1DF500 -> strFileOpen), decodes one step,
  sets `movieRequested = 1` and returns the file size (stored to bytesInMovie; approxMovieFrames = bytes /
  bytesPerMovieFrame). **It does not block.**
- uiMain calls `playMovie()` every frame (0x18F394), then, while movieRequested, `updateMpegMovieDecoding(!keyPress)`
  0x1DEE30 (0x18F3B4/0x18F3C4). playMovie starts nothing unless `movieEnable && movieIsCompletelyFinished &&
  !keyPressDuringMovie && delayMovieFlag==0 && okToPlayCopyright==1`. After starting, it sets nextMovie=-2 and
  movieEnable=0.
- uiPlay*Movie pattern (a UI state run each frame): on frame 1 set nextMovie, movieEnable=1, xxxTriggered=1,
  movieTimer=0, gAllowInteruption=0, movieStartTime. On later frames movieTimer++; when `movieTimer >= 11 &&
  !movieIsPlaying`, change screen. After 300 fields it sets gAllowInteruption=1 (allows skipping).

TMBO (same engine):
- `func_002220B8` = playMpegMovieWithDB(char* path, int withAudio, int allowInterruption) -> returns bytes. The path
  is a plain "mov/xxx.pss" string (no table, no index). Calls in TMBO: 0x1CEFB4/0x1CEFE0/0x1CF000/0x1CF0F8.
- `func_001CE9B0` = playMovie() (void, global-driven). It is a compare chain, not a jump table. Handled values:
  -1 incog, 0 intropib/title, 1 ttl_gm, 2 gm_ttl, 3 gm_cs1, 4 cs1_gm, 5..0x14 cs/ci (tables D_004EF550, D_004EF5D8),
  0x45 lseye, 0x46..0x5A ls/lsnb (D_004EF660/D_004EF708; no lk/lknb), 0x70 ttl_eye, 0x71 eye_ttl, 0x72 ttl_tv,
  0x73 tv_ttl, 0x74 ttl_mov, 0x75 wait, 0x76 title, 0x77 gm, **0x78 score** (taken, so retail ll0's number collides),
  0x89 none, 0xC8 copyrt. Any other value starts nothing. TMBO has no table for the story names; the strings are
  absent from the TMBO rodata (string list at 0x4EF7B0..0x4EF8C8).
- uiMain = `func_001B2B68`: playMovie call at 0x1B40D4, updateMpegMovieDecoding (0x222148) at 0x1B40FC/0x1B410C.
- TMBO globals: nextMovie D_004FA718, bytesInMovie D_004FA71C, bytesPerMovieFrame D_004FA720,
  approxMovieFrames D_004FA724, delayMovieFlag D_004FA728 (+cnt D_004FA72C), keyPressDuringMovie D_004FA778,
  shortMovies D_004FA78C, forceBlink D_004FA7B4, okToPlayCopyright D_004FA3A4, movieRequested D_004FB068,
  movieIsCompletelyFinished D_004FB06C, gAllowInteruption D_004FB09C, movieIsPlaying D_004FAE10,
  movieEnable D_004FB5A0. The retail shell+0x2360 equivalent is TMBO shell+0x23B8.
  Find movieTimer and movieStartTime with mapping.csv before use.

Recommendation for TMBO:
- Do not use a blocking loop. Decoding and display happen in uiMain's per-frame
  `updateMpegMovieDecoding` and need the normal frame/vsync flow.
- Copy retail's UI-state pattern: a new story-movie screen (or a hook in the existing load path) that calls
  `func_002220B8("mov/x05a.pss", 1, 1)` once. Before that call, check `D_004FB06C` (finished) and `D_004FA778`, and
  keep `D_004FB5A0` = 0 so playMovie does not start another clip. Store the return value to D_004FA71C. Then wait
  until a few frames have passed and `D_004FAE10` (movieIsPlaying) == 0 before changing screen.
- Alternative: add cases to func_001CE9B0 for new numbers (avoid 0x78; 0x79..0x88 and 0xC9..0xCB are free
  in TMBO) and drive them with nextMovie + movieEnable, as retail does.
- Build names with formatMovieFilename 0x189E50 ("mov", name, "pss"). The new name tables (x??a/b/c, ??Arena,
  ??Roof, ll0..10) must be added to our own data. The files go on the test disc as `\MOV\<NAME>.PSS`.
