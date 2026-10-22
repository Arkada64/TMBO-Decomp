# TMB-Reloaded: hook stubs for mods/packs.c (apply_mods.py points the jals here); they pass the shell ($s0).
# func_00188930 (level TEX load) calls func_0023D560(vram, 0) at 0x1889E4: shell as the 3rd argument.
# func_00188688 (level RTX load) calls func_0023EC80(vram, rtx, 0) at 0x18873C: shell as the 4th argument.
.set noat
.set noreorder
.section .text, "ax"
.align 3
.globl tmbr_LevelTexInitStub
tmbr_LevelTexInitStub:
    j       tmbr_LevelTexInit
    daddu   $6, $16, $0
.globl tmbr_LevelRtxStub
tmbr_LevelRtxStub:
    j       tmbr_LevelRtxInit
    daddu   $7, $16, $0
