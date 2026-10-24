# Working-C pipeline (toward the PC build)
- `../nm_apply.py`: puts compiling m2c drafts in as `#ifdef NON_MATCHING` alternatives to `INCLUDE_ASM`.
- `../nm_build.sh`: private copy (~/nmhome), normal build must stay byte-identical, then the shiftable build with
  mods and `-DNON_MATCHING` -> `test/NM_TEST.ELF`. C float literals go after the game's .sdata (gp-relative).
- On the test PC: `cloud/in/nm_test.sh FILES` (build + quick-boot into retail Snowy Roads),
  `cloud/in/nm_loop.sh N FILES` (repeat; a TLB fault inside one of our C functions puts it on
  `cloud/in/nm_skip.txt` and goes again; stops when clean or when a fault needs a look).
- Note: PCSX2 reports the start of the recompiled block as the fault pc, so the function is right, the
  instruction is not.
