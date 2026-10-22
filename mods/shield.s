# TMB-Reloaded mod: Respawn Shield (port of the community "TMA Ruleset/ Respawn Shield" v0.2 by Aced14).
# The pnach version stored this code over TrafficDirector::init (0x1B0688) and therefore had to NOP the
# InitializeFodderCars call (0x1881A8) and func_001B0978's call (0x138D10). Here the same code lives in its
# own object, so traffic code is untouched. Hooks: tools/mods/apply_mods.py (each original instruction is
# replaced by a j/jal to one of these, same size; tmbr_ret_* labels mark the return points).
# Byte 0x497 of a vehicle is the shield state used by all hooks (set to 4 at spawn).
# Differences from the pnach: tmbr_shield_c restores the displaced `addiu $7, $0, 1` before overriding it,
# and tmbr_shield_d returns to 0x155AC0 (re-runs `daddu $4, $18, $0`) instead of 0x155AC4.
.set noat
.set noreorder
.section .text, "ax"
.align 3

.globl tmbr_shield_spawn                # from 0x1DC07C (spawn): give the respawned vehicle the shield
tmbr_shield_spawn:
    ori     $4, $0, 0x4
    lui     $5, %hi(D_0033C460 + 0x484)
    addiu   $5, $5, %lo(D_0033C460 + 0x484)
    beql    $5, $7, 1f
    sb      $4, 0x13($7)
1:  j       tmbr_ret_1DC084
    addiu   $6, $17, 0x200              # displaced

# Shield length (func_001DD0C8, matched C - hooked after linking by mods/postlink.txt, which also changes the
# compare at 0x1DD158 to use $25): 0xB5 frames normally, 0x259 while the shield state byte 0x497 is >= 4.
.globl tmbr_shield_timer                # from 0x1DD0D8 (j here; 0x1DD0DC runs in the delay slot)
tmbr_shield_timer:
    slti    $25, $2, 0x4
    bnez    $25, 1f
    ori     $25, $0, 0xB5
    ori     $25, $0, 0x259
1:  j       0x1DD0E0
    sq      $17, 0x10($29)              # displaced (0x1DD0D8)

.globl tmbr_shield_c                    # from 0x1E472C
tmbr_shield_c:
    addiu   $7, $0, 0x1                 # displaced (restored)
    lb      $2, 0x497($18)
    slti    $2, $2, 0x4
    bnel    $2, $0, 1f
    lui     $7, 0x1
1:  j       tmbr_ret_1E4734
    addiu   $2, $0, 0xC

.globl tmbr_shield_d                    # from 0x155AB8 (was: jal func_0015A2D8)
tmbr_shield_d:
    lb      $5, -0x1D19($18)
    slti    $5, $5, 0x4
    beql    $5, $0, 1f
    nop
    jal     func_0015A2D8
    daddu   $5, $19, $0
1:  j       tmbr_ret_155AC0
    nop

.globl tmbr_shield_e                    # from 0x156E08 (function entry)
tmbr_shield_e:
    lb      $2, 0x497($5)
    slti    $2, $2, 0x4
    bnez    $2, 1f
    ori     $2, $0, 0xC0
    lw      $3, 0x20F4($5)
    bne     $2, $3, 2f
    lw      $2, 0x21B0($5)
    slti    $2, $2, 0x2
    beqz    $2, 2f
    lw      $2, 0x24B4($5)
    bnez    $2, 2f
1:  lui     $2, %hi(D_00317274)         # displaced (was in the hook's delay slot, $2 got clobbered)
    j       tmbr_ret_156E10
    addiu   $29, $29, -0x120            # displaced
    addiu   $0, $0, %lo(D_00317274)     # never executed: pairs the %hi above for the linker
2:  j       func_001927C8
    daddu   $4, $5, $0

.globl tmbr_shield_f                    # from 0x155340
tmbr_shield_f:
    lb      $3, 0x497($19)
    slti    $3, $3, 0x4
    beql    $3, $0, 1f
    sw      $0, 0xCC($18)
1:  j       tmbr_ret_155348
    lw      $3, %gp_rel(D_004F9B7C)($28)    # displaced

.globl tmbr_shield_hearse               # from 0x1E4E14 (was: jal activateHearseMachineGunPopupSound)
tmbr_shield_hearse:
    lb      $2, 0x497($16)
    slti    $2, $2, 0x4
    beql    $2, $0, 1f
    nop
    j       activateHearseMachineGunPopupSound__FP7Vehicle
    nop
1:  jr      $31
    sw      $0, 0x2778($16)

.globl tmbr_shield_h                    # from 0x122D88
tmbr_shield_h:
    lb      $2, 0x497($18)
    slti    $2, $2, 0x4
    beql    $2, $0, 1f
    ori     $20, $0, 0x0
1:  j       tmbr_ret_122D8C
    lw      $3, 0x20F4($18)             # displaced
.align 3
