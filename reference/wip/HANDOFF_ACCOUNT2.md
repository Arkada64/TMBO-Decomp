# Handoff to account 2: everything beyond regular decomp (2026-10-22)

Account 1 now only does matching decomp (permuter runs). Everything below is yours. Open items with details:
TODO.md (repo: reference/wip/TODO.md).

## Where things are
- Repo: ~/tmbo_decomp (WSL), remote `reloaded` = github.com/Arkada64/TMB-Reloaded, branch main (latest
  11770a2 + TODO commit). Normal build must stay byte-identical (`ninja`, cmp with disks/SCUS_971.96.rom).
- Mod build: tools/mods_copy_build.sh (private copy ~/modshome/tmbo_decomp, so it can run while the permuter
  uses ~/tmbo_decomp). TMBR_TEST=1 = test build (free cam Select+L3 anytime). Output: TMB Decomp/test/
  TRAFFIC_TEST.ELF (+ FREECAM_TEST.ELF); RELEASE=1 also makes the BPS tester patch.
- Bisect builds: tools/sel_build.sh NAME SKIPGROUPS [ENV=...]  (groups: camera,freecam,tick,qm,shield;
  env: TMBR_NO_PEDS=1, TMBR_NO_POSTLINK=1, TMBR_STACK=0x40000, TMBR_TEXT_PAD=N, TMBR_DEBUG_LOADER=1,
  TMBR_TRAFFIC=1, MODS=0).
- Vanilla pnach: tools/mods/make_pnach.sh -> release/SCUS-97196_C54E5CF2.pnach (all) and release/TMA/ (no
  quick moves / tap switch: a TMA admin ruled quick moves cheating; the user removed tap switch too).
  Never copy pnach files into the user's PCSX2 folder; the user edits that one himself.

## Mod build layout (important)
- Mods are linked AFTER .bss (section .tmbr_mods, 0x40+ gap because crt0's 16-byte .bss clear overshoots).
  Every game address stays original. crt0 is patched: .bss clear ends at main_BSS_END, heap starts at
  main_VRAM_END, stack 0x3C000 (mods/memory.s) to give the heap back.
- Never grow a game function: data moving crashes the map selector (stale data reference somewhere in the
  shiftable build; even MODS=0 + 0x800 .text padding crashes). Hooks replace instructions 1:1; matched-C
  changes go in mods/postlink.txt (word patches after linking).
- Hooks: tools/mods/apply_mods.py (PATCHES / LABELS / ASM_TEXT). Mod code: mods/*.s, mods/freecam.c
  (built with the game's SN compiler; avoid float literals, use a constant table).
- Baked pnach sections: mods/pnach_sections.txt (community) + mods/tmbr_sections.txt (ours, incl. peds).
  Continuous data writes are re-applied every frame by tmbr_pnachTick (hook in sceGsSyncV).

## Status of features (all tested by the user)
- Working: Respawn Shield, quick energy moves, tap weapon switch (+L1/R1 jump), default camera 2nd view,
  spectator free cam, peds on Suburbs/Junkyard, level selector, map loading, skip intros, 16:9.
- Not working / next: peds on Freeway/Prison (data stripped online), traffic (needs synced host-owned
  vehicle array; Freeway online has 60 traffic nodes), AI count rules, the stale data reference.

## Rules from the user
- Do NOT launch PCSX2 on the user's machine; the user runs tests. Read logs from
  C:\Users\Ark\Desktop\TMBO Ready2Play Edition\logs\emulog.txt.
- Minimize round trips; one test round per question; ship BPS patches, not ELFs; ask server admins before
  public tests; everyone in a lobby uses the same build.
- Git identity: -c user.name=Arkada64 -c user.email=esogeneral33@gmail.com.
