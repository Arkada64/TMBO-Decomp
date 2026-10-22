# TMB-Reloaded: hook stub for mods/packs.c. func_00188930 (level TEX load) calls func_0023D560(vram, 0) at
# 0x1889E4 with the shell in $s0; apply_mods.py points that jal here. Pass the shell as the 3rd argument.
.set noat
.set noreorder
.section .text, "ax"
.align 3
.globl tmbr_LevelTexInitStub
tmbr_LevelTexInitStub:
    j       tmbr_LevelTexInit
    daddu   $6, $16, $0
