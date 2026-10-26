# Story mode for TMBR - plan (2026-10-26)

Ark: story mode (single player) with retail's cutscenes; the online menus host it; each level's story events and
bosses checked against retail; health pads back where retail had them; retail's story map versions as separate
files picked only in story mode. Later: local co-op story (split-screen guests), online co-op.

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
