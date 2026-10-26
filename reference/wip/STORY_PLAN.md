# Story mode for TMBR - plan (2026-10-26)

Ark: story mode (single player) with retail's cutscenes; the online menus host it; each level's story events and
bosses checked against retail; health pads back where retail had them; retail's story map versions as separate
files picked only in story mode. Later: local co-op story (split-screen guests), online co-op.

## Modded characters in story (Ark 2026-10-26)
A modded character (12 Pak, the Harbor City cars, ...) uses the story files of the character it borrows its stats
from: intro / ending movies, story blurbs and the loading screen quotes (12 Pak = Roadkill's). So no story path
ever asks for a file that does not exist.

## Menu layout Ark wants (2026-10-26)
- Main menu: two lines, SINGLE PLAYER and ONLINE.
  - SINGLE PLAYER -> SOLO or SPLIT-SCREEN CO-OP: the story run offline (alone, or with guests on controllers 2-4).
  - ONLINE -> the game's online / LAN choice as today; co-op STORY becomes a game mode there (next to Deathmatch,
    Last Man Standing, ...), so the R3 + Square lobby toggle of phase 1 is a stopgap.
- Single player must not need a network setup: it runs the same host path offline (alone in a LAN room or a
  local session), with the room screens skipped / hidden.
- Today's main menu (boot): INTERNET / LAN / OPTIONS, textured labels in the shell model (not font strings), UI
  state 8 = func_001B91B8 (3-position cursor, select -> state 9 which branches on it). LAN goes through
  "Initialize network hardware" -> CREATE GAME (name / password / max players) -> waiting room (state 0x21).
- Correction: the main menu is UI state 6 (func_001B8C10, cursor 3 / 4 / 5 at shell +0x19BE4 + 6*4); state 8 is
  another screen that shares the label meshes' neighbourhood.
- DONE 2026-10-26 (mods/menu.c, tools/lost/menulabels.py -> packs/SHELL1.TEX): main page SINGLE PLAYER / ONLINE /
  OPTIONS, ONLINE -> online page INTERNET / LAN / OPTIONS, TRIANGLE back. SINGLE PLAYER takes the LAN way and sets
  tmbr_singlePlayer (its own SOLO / CO-OP flow next).
- Plan: (1) state 8 shows SINGLE PLAYER / ONLINE / OPTIONS (new label textures in SHELL1.TEX, like the other shell
  texture edits); ONLINE opens a second page INTERNET / LAN (same screen, labels swapped, back returns).
  (2) SINGLE PLAYER -> SOLO / SPLIT-SCREEN CO-OP; both run the LAN host path with the network screens auto-
  accepted (game name filled in, no password) and land in the waiting room with STORY on; CO-OP opens the guest
  join (START on controllers 2-4) there. (3) Online: STORY as a game mode in the settings editor (type list
  2..5 + story), replacing the R3 + Square toggle.

## What TMBO still has / lost (checked 2026-10-26)
- Kept: the MPEG movie player (TMBO plays mov/*.pss shell transitions: title, gm, cs1, eye, tv, wait, score ...),
  the boss code (tmb/boss: FinalBoss UpdateTrans / GetClosestPlayer / AddEpNode ...), ROOFBOSS level files, the
  shell's 0x18000+0x2354 story-level slot (written once at boot, read once in ui.s), car / level loading.
- Lost: all story flow. No EvaluateOnePlayerStoryStatus, uiMovies, playCharIntro, uiPlayArena / Midgame / Roof /
  End movies, wonStoryOverlay, levelLoadCharBlurb, single-player save (readSaveDataSinglePlayer), the story
  milepost / movie triggers.
- Disc: retail has 189 movies TMBO lacks (3.03 GB, /MOV), 52 story music streams (/VAG BOSS*, BURB*, FREWY*, JNK*,
  PRISN*, ROOF*, RVR*, SNOW*, DEATH*: ambient / battle / explore, ~600 MB), STGAME.BNK. Levels: same names on
  both discs (online adds DEATH7, FLATLAND); whether the online files dropped story objects (bosses, health pads,
  scripted events) is still to compare file by file.
- Retail references (retail decomp ~/tmb_decomp, symbols): Shell::EvaluateOnePlayerStoryStatus (0x15FEB0; story
  level index shell +0x18000+0x2354 = 0..0x14, lives +0x2370, outcome +0x2308 / +0x2364), Shell::
  m_levelStoryNumMap (0x426570: 2 1 2 5 7 3 3 - 6 - - - 6 - 4 - - - - - 8 -, story stage per level slot),
  uiLoadLevel (0x194C60: story movie per level - jump table on +0x2354 -> nextMovie 0x78..0x82, milepost switch,
  character blurb), uiMovies (0x190760), playCharIntro (0x1938F8), uiPlay*Movie (0x1939F0..0x194338).

## Phases (each one playable on its own)
1. Story run, offline: a STORY choice in the host's lobby (alone + bots). The mod runs retail's level order for the
   chosen character: each level vs retail's opponents for that stage (bots with fixed cars), 3 lives, win = all
   enemies dead, then the next level; lose = retry / quit. Saved to the memory card. No movies yet.
2. Movies: retail's .PSS files onto the test disc (PCSX2 has no disc size problem), played through TMBO's movie
   player at retail's points (character intro, before / after levels, endings). The story music streams too.
3. Story levels: compare retail vs online level files; where they differ (boss objects, scripted events, health
   pads), ship retail's as \LVL\SP_<name>.* and load them only in story mode (like the content packs).
4. Bosses: Minion, the prison ship / mid-level bosses, Warhawk on ROOFBOSS - drive TMBO's surviving boss code
   (FinalBoss) the way retail's story does, check each fight.
5. Co-op: split-screen guests in a story run (TODO 12), then online (13).

## First steps
- Pull retail's story tables: per character the level order and each stage's opponents (shell / ui code around
  EvaluateOnePlayerStoryStatus and the level setup that spawns story enemies), movie numbers per point.
- Decide the lobby entry (a STORY mode line in the game settings, like TRAFFIC / TEAMS).

## Retail story setup, read from retail code (2026-10-26)
- Opponents are NOT fixed per character or stage. SelectAICars__5Shell (retail 0x15EA48): in story mode the AI count
  is a per-level table (shell+0x19DDC + 4*level, filled in __5Shell), then RandomlySelectAI picks that many distinct
  random cars from the 15 drivers (car value = character id << 5, 0x20..0x1E0), never the player's car; Minion
  (0x1E0) only when unlocked (shell+0x1A1C4) or on his own level; after 200 failed picks it pads with Roadkill.
- AI count per level: Suburbs 8, Junkyard 7, Freeway 7, Prison Passage 8, Skyscrapers 8, Downtown 7, Highway Loop 8,
  Elevators-Junk2 8, Minion's Stadium / Prison Ship / Asylum / Mini levels 6, Warhawk's Roof 6.
- Boss overrides: level 14 (Minion's Stadium) = 1 AI, car 0x1E0 (Minion). Level 20 (Warhawk's Roof) = 2 AI,
  cars 0x220 and 0x200 (character ids 17 and 16: the Warhawk boss pieces, not drivers - check TMBO has them).
- The level order is the same for every character (m_nextLevelMap; the player picks a branch in chooseNextLevel);
  characters differ only in movies / endings.
- TMBO has neither SelectAICars nor RandomlySelectAI; our bots.c already spawns bots with chosen cars (+0xB4), so
  phase 1 = drive the existing bot spawner from these tables.

## Phase 1 status (2026-10-26, mods/story.c)
- Host lobby R3 + Square = STORY on/off. On: level = the story level (shell +0x23AC, goes out in the game info),
  Last Man Standing (game info bits 1-4 = 3), 3 lives (+5), teams 2 + HUMANS VS BOTS, bots = retail's count
  (capped at the free slots), distinct random drivers that are not a human's (Minion alone on his stadium),
  no 12 Pak bots. Box line "STAGE n: LEVEL"; at a fork L3 swaps the branch. Win (teams.c winner = humans'
  team) -> next stage; else "TRY AGAIN". Warhawk's Roof is a stand-in (6 bots, no boss) until phase 4.
- Tested (qb g71): toggle -> JUNKYARD, LMS, teams 2, humans vs bots, 6 bots + guest, level loads. Win / loss
  advance not yet seen in a test (needs a played match). No save yet.
- Tested 2026-10-26 (qb g93-g95, STORYTEST build forces a win 40 s in): Junkyard won -> score -> room "won
  JUNKYARD", stage 2 SUBURBS saved; L3 -> FREEWAY saved; STORY off / on reads the card back ("continue, stage 2
  FREEWAY"); Freeway loads with 7 bots. The first save on a card without the file returns 0: retried every 30
  frames (works on the 2nd). R3 + Square no longer opens the room's Square screen (menu.c tmbr_RoomInput).

## Phase 2 status (2026-10-26, story.c tmbr_StoryMoviesDone, guests.c loading screen)
- Movies per retail (reference/wip/STORY_MOVIES.md): intro X??A before the run's first Junkyard, ??ARENA before
  Minion's stadium, X??B before Prison Passage, ??ROOF before the roof, then LLn; on the loading screen before
  the halves fall, every console, this console's car picks the character (12 Pak = Roadkill). Missing files are
  skipped (sceCdSearchFile). Test disc: packs/MOV/*.PSS go into \MOV\ (mktest.sh). Not yet: ending X??C +
  credits after the roof (needs a screen in the room), story music streams.
- Playback status (tests g100-g104, 2026-10-26): NOT WORKING YET. The files are found (the game's lookup
  func_00201910(out, "\\MOV\\X.PSS;1") - note: out first). (1) Calling playMpegMovieWithDB (func_002220B8) from the
  loading-screen state: stream starts ("Stream Buffer ...") and the game freezes when we wait for it to end. (2) The
  blocking player func_00222048: same freeze. (3) The game's own request (nextMovie -1 = the incog slot with our name
  written into its 16-byte string, movieEnable 1; guards finished 1 / key 0 / okToPlay 1 / requested 0) never starts
  in state 0x29. Next idea: play them where TMBO plays its own level clips (LS<level>.PSS, nextMovie 0x46 + level,
  set when PLAY GAME is pressed) - replace that clip's name instead of adding a new start.
