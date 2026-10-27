# Shiftable build: status handoff (2026-10-21, account 1)

## Where things stand
- **B5** (bss moved +0x80): boots, main menu, controller works (pressure mode entered). FIXED.
- **SHIFT_TEST** (everything after ai.c moved +0x80): main menu + controller work, but **green vertical
  stripes over the menu background** (Sweet Tooth image). LAST OPEN BUG.
- Normal build stays byte-identical after every step.

## Bugs found and fixed this session (all in post-split tooling, staged in this folder)
1. **symbolize_data.py**, new pass `unsymbolize_fake_refs` (runs before the P_ pass):
   - **vutext.data.s**: every word goes back to raw (`/* raw */` marker). It's tables/microcode, not pointers.
   - **RAW_RANGES** = [0x4DD5D8, 0x4DDD40): libkernl's EE-kernel patch code. func_002A20C8 copies it to
     0x80076000 (0x740 bytes) and to 0x82000. These are instruction words.
   - **Data words that point into .sbss/.bss at a label no code references** go back to raw. Examples:
     zlib cpdist halfword pairs 0x00610041 / 0x00530043, which caused the **boot TLB crash in zip
     inflate**; MIPS instruction templates; fixed-point pairs.
   - **gcc_except_table**: the .incbin is expanded to .word lines so the P_ pass symbolizes its code
     addresses (48 words).
   - The P_ pass skips `/* raw */` lines and vutext.
2. **fix_rawlo.py** (new): rewrites raw %lo immediates that spimdisasm couldn't pair with their lui,
   for example `addiu $4,$20,0x2BC0` becomes `%lo(D_00612BC0)`. It only does this when hi+imm equals
   the symbol exactly; 164 fixed. **This was the "no controller" bug**: the pad state machine wrote to
   the old address.
   - INCLUDE_ASM'd .s files are NOT ninja dependencies. fix_rawlo touches the .c files that include
     changed dirs. Initially I had to `find src -name '*.c' -exec touch {} +`.
3. shift_bisect.sh and shift_test3.sh now run symbolize_data.py and then fix_rawlo.py.
   - shift_bisect.sh has new variants:
     - `B8` / `B9`: bss shifted by 0x100 / 0x400.
     - `T<n>`: pad inserted after the n-th `(.text);` line of the ld script.

## Stripe bisect (T<n>: objects n+1.. move)
- T1/T100/T200/T220/T240: stripes. T260/T280/T300: clean. B2 (data only): clean.
- **Culprit is one of text objects 241..260**. These are libpad, libmtap, libmc, after_libmc_84,
  libgcc2_part3, libmc_part2, libmpeg (pack, mpeg, init, init_part2, defhandler, mpc, csc, bit),
  prison_part4, mathf_part2, after_mpc_85, after_bit_86, libipu and after_libipu_87.
  Prime suspects are libmpeg/libipu (the menu background is likely IPU-decoded).
- The next round (T244 T248 T252 T256) was started and may finish on its own. Results go to `sweep.txt`.
  Detect stripes with stripes.py logic: count pixels with g>90, r<70, b<70 in rows 100-380 of the
  savestate Screenshot.png. Stripes ≈ 5200, clean = 0.
- Already checked: data words are clean (S0 vs SHIFT_TEST memory diff is only RNG state), and raw luis
  in libmpeg/libipu are hardware registers. Next: once narrowed to one object, look for position
  dependence. That means DMA from text, IPU/VLC tables in text, code-address arithmetic, or alignment
  > 0x80.

## Automated test loop (no user needed)
- **`bis.sh V1 V2 ...`** (WSL): builds variants into test/ via shift_bisect.sh.
- **`sweep.ps1 -Vs "A,B"`**: runs each ELF for 25 s and logs pressmode (count of "D+A+P" lines, which
  is the controller check: 2 = OK, 0 = broken), padcfg and TLB misses.
- **`sweepss.ps1 -Vs "A,B"`**: runs 75 s with SaveStateOnShutdown, then extracts with ext.sh to
  `test/ss_<V>/` (Screenshot.png and eeMemory.bin).
- **`runss.ps1 V secs`** (pauses on TLB miss) and **`runpine.ps1`** / **`pinedump.ps1`** (PINE memory
  dump 0x100000-0x1000000, 40000 reads per batch).
- All scripts back up and restore PCSX2.ini (`*.bak`).
- **`rebuild2.sh [touch]`**: rebuilds B5 and SHIFT_TEST (NOPS=32).
- Don't run two builds at once. Never run `configure.py generate`.

## Not done yet
- Commit/push the tools: symbase, symbolize_data, fix_rawlo, make_shiftable, scripts, env.py.
- Make shiftable mode a permanent post-split step (`SHIFTABLE=1`).
- test_pnach.py errors because BASE_TEST.ELF was deleted. Harmless, but remove that call.
- Then: traffic mod (port retail FodderParse and the C loader func_00127650), lobby UI, net.c.
