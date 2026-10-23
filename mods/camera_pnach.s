# TMB-Reloaded mods: default camera + per-frame pnach writes.
# Hooks in tools/mods/apply_mods.py.
.set noat
.set noreorder
.section .text, "ax"
.align 3

# Default camera = the view you get after pressing Select+Down once.
# func_001399A8 (match start) sets every viewport's camera POV to 2 with SetCameraPOV; the hook at 0x139D38
# calls this instead: same call, then func_00117B90 = what Select+Down calls (next POV), once.
.globl tmbr_InitPOV
tmbr_InitPOV:
    lui     $1, %hi(tmbr_spectating)    # match start: nobody is spectating (free cam off)
    sw      $0, %lo(tmbr_spectating)($1)
    addiu   $29, $29, -0x30
    sq      $31, 0x20($29)
    sq      $17, 0x10($29)
    sq      $16, 0x0($29)
    daddu   $16, $4, $0                 # camera
    jal     SetCameraPOV__6Camerai10_cameraPOV
    daddu   $17, $5, $0                 # viewport
    daddu   $4, $16, $0
    jal     func_00117B90
    daddu   $5, $17, $0
    ori     $2, $0, 10                  # weapon list default in 10 frames (freecam.c)
    lui     $1, %hi(tmbr_hudStart)
    sw      $2, %lo(tmbr_hudStart)($1)
    lq      $31, 0x20($29)
    lq      $17, 0x10($29)
    lq      $16, 0x0($29)
    jr      $31
    addiu   $29, $29, 0x30
tmbr_InitPOV_end:

# Spectator mark: func_00138C90 switches a dead player's camera to spectating with SetCameraPOV(.., 5)
# (0x139218 `addiu $6, $0, 5`, the value the community "Spectator/ Alternate View" codes change). The hook
# replaces it with a j here (its delay slot `lw $3, 4($22)` still runs); free cam (freecam.c) turns on.
.globl tmbr_SpecMark
tmbr_SpecMark:
    ori     $6, $0, 0x5                 # displaced
    lui     $1, %hi(tmbr_spectating)    # ($2 is live here: only $1 and $6 are used)
    j       tmbr_ret_139220
    sw      $6, %lo(tmbr_spectating)($1) # nonzero = spectating
tmbr_SpecMark_end:

# PCSX2 re-applies 'continuous' pnach writes every frame; for data the game rewrites at runtime (16:9 HUD
# values, ...) baking the value into the ELF is not enough. tools/mods/apply_pnach.py fills this table with
# (address | size << 28, value) pairs (size 0 byte, 1 half, 2 word; address 0 ends it) and this runs once
# per frame: the hook replaces sceGsSyncV's `jal sceGsGetGParam` (0x249F2C) and tail-calls it.
.globl tmbr_pnachTick
tmbr_pnachTick:
    lui     $8, %hi(tmbr_pnachTable)
    addiu   $8, $8, %lo(tmbr_pnachTable)
    lui     $12, 0x0FFF
    ori     $12, $12, 0xFFFF
1:  lw      $9, 0x0($8)
    beqz    $9, 9f
    lw      $10, 0x4($8)
    srl     $11, $9, 28
    and     $9, $9, $12
    beqz    $11, 2f
    addiu   $11, $11, -1
    beqz    $11, 3f
    nop
    b       4f
    sw      $10, 0x0($9)
2:  b       4f
    sb      $10, 0x0($9)
3:  sh      $10, 0x0($9)
4:  b       1b
    addiu   $8, $8, 8
9:  j       sceGsGetGParam
    nop

.align 3
.globl tmbr_pnachTable
tmbr_pnachTable:
    .space 8 * 96                       # filled after linking by apply_pnach.py
    .word 0, 0                          # always-terminator
