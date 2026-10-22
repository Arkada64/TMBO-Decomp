# TMB-Reloaded: memory budget for the mods.
# crt0 passes the main thread's stack size to SetupThread (originally 0x40000 = 256 KB); the heap ends where
# that stack begins, and starts at the end of .bss. Mod code/data makes the ELF bigger, which shrinks the heap
# by the same amount, and the map selector then ran out of memory (operator new fails -> abort -> back to the
# PS2 menu). apply_mods.py points crt0 at this symbol instead; 0x3C000 gives the heap 16 KB back.
.globl TMBR_STACK_SIZE
.set TMBR_STACK_SIZE, 0x3C000
