# Quick moves: hold L1 or R1 and tap a d-pad direction (classic combos still work).
#   L1+Up freeze, L1+Right shield, L1+Left mine, L1+Down rear fire
#   R1+Right charged mine, R1+Left cloak (invisibility)
# Hooked by apply_mods.py: the only call of Combo::Update (func_00123F38, at 0x17BF00 in func_0017BE80)
# goes to tmbr_ComboUpdate, which runs the original Update and then checks the shortcuts.
# Combo layout (include/tmb/combo.hpp, bools are 4 bytes): 0x0 state, 0x4 pad_index, 0x8 updates_since_last_combo,
# 0xC..0x1C secret code fields + cur_frame, 0x20 delta_time (mine charge, 60 = full), 0x2C mine_ready,
# 0x30 check_codes, 8 input buffers of 60 ints from 0x34 (stride 0xF0; the two analog left/right ones reset to 1).

.set noreorder
.section .text, "ax"

.globl tmbr_ComboUpdate
tmbr_ComboUpdate:
    addiu   $29, $29, -0x40
    sq      $31, 0x30($29)
    sq      $18, 0x20($29)
    sq      $17, 0x10($29)
    sq      $16, 0x0($29)
    jal     func_00123F38               # original Combo::Update(this, vehicle)
    daddu   $16, $4, $0

    # read d-pad and shoulder buttons: bit 0x10 << i for i = 0..7 (UP RIGHT DOWN LEFT L2 R2 L1 R1)
    daddu   $17, $0, $0
    ori     $18, $0, 0x10
1:  lw      $5, 0x4($16)
    jal     inputGetInput__Fii
    daddu   $4, $18, $0
    beql    $2, $0, 2f
    nop
    or      $17, $17, $18
2:  sll     $18, $18, 1
    slti    $2, $18, 0x1000
    bnez    $2, 1b
    nop

    # tap = directions pressed now but not last frame (per pad)
    lw      $2, 0x4($16)
    andi    $2, $2, 0x7
    lui     $3, %hi(tmbr_prevDpad)
    addiu   $3, $3, %lo(tmbr_prevDpad)
    addu    $3, $3, $2
    lbu     $4, 0x0($3)
    andi    $5, $17, 0xF0
    srl     $6, $5, 4
    sb      $6, 0x0($3)
    sll     $4, $4, 4
    nor     $4, $4, $0
    and     $5, $5, $4                  # $5 = tap (INPUT_UP 0x10, RIGHT 0x20, DOWN 0x40, LEFT 0x80)
    beqz    $5, 9f
    andi    $6, $17, 0xF00              # $6 = shoulders (L2 0x100, R2 0x200, L1 0x400, R1 0x800)

    # a direction was tapped while L1/R1 is held: that hold is for a move, not a weapon switch
    lw      $2, 0x4($16)
    andi    $2, $2, 0x7
    lui     $3, %hi(tmbr_qmUsed)
    addiu   $3, $3, %lo(tmbr_qmUsed)
    addu    $3, $3, $2
    lbu     $4, 0x0($3)
    srl     $9, $6, 10
    andi    $9, $9, 0x3                 # bit 0 = L1, bit 1 = R1
    or      $4, $4, $9
    sb      $4, 0x0($3)

    daddu   $7, $0, $0                  # $7 = combo type, $8 = mine charge
    daddu   $8, $0, $0
    ori     $2, $0, 0x400
    bne     $6, $2, 5f
    ori     $2, $0, 0x800
    # L1 held
    andi    $2, $5, 0x10
    bnez    $2, 8f
    ori     $7, $0, 0x1                 # freeze
    andi    $2, $5, 0x20
    bnez    $2, 8f
    ori     $7, $0, 0x7                 # shield
    andi    $2, $5, 0x80
    bnez    $2, 8f
    ori     $7, $0, 0x4                 # mine
    andi    $2, $5, 0x40
    bnez    $2, 8f
    ori     $7, $0, 0x3                 # rear fire
    b       9f
    nop
5:  bne     $6, $2, 9f
    nop
    # R1 held
    andi    $2, $5, 0x20
    beqz    $2, 6f
    andi    $2, $5, 0x80
    ori     $7, $0, 0x4                 # charged mine
    b       8f
    ori     $8, $0, 60
6:  beqz    $2, 9f
    nop
    ori     $7, $0, 0x8                 # cloak

    # fire it: set the state, then clear the combo buffers like Combo::ClearCombo (inlined in the game)
8:  sw      $7, 0x0($16)
    sw      $0, 0x8($16)
    sw      $0, 0xC($16)
    sw      $0, 0x10($16)
    sw      $0, 0x14($16)
    sw      $0, 0x18($16)
    sw      $0, 0x1C($16)
    sw      $0, 0x2C($16)
    sw      $0, 0x30($16)
    sw      $8, 0x20($16)               # mine charge (0 = normal, 60 = fully charged)
    daddu   $2, $16, $0
    ori     $3, $0, 60
    ori     $4, $0, 1
7:  sw      $0, 0x34($2)                # up
    sw      $0, 0x124($2)               # down
    sw      $0, 0x214($2)               # left
    sw      $0, 0x304($2)               # right
    sw      $0, 0x3F4($2)               # up analog
    sw      $0, 0x4E4($2)               # down analog
    sw      $4, 0x5D4($2)               # left analog
    sw      $4, 0x6C4($2)               # right analog
    addiu   $3, $3, -1
    bnez    $3, 7b
    addiu   $2, $2, 4

9:  lq      $31, 0x30($29)
    lq      $18, 0x20($29)
    lq      $17, 0x10($29)
    lq      $16, 0x0($29)
    jr      $31
    addiu   $29, $29, 0x40

# Weapon switch on L1/R1 only on a tap. Hooked at 0x17BF78 (a beqz, replaced by j) in func_0017BE80, right after it stored the
# shoulder buttons into the vehicle (0x5A1 = L1, 0x5A2 = R1; the weapon switch reads those). While the button
# is held the game sees it released; when it is let go, the game sees one frame of "pressed" only if it was
# a tap: shorter than 15 frames and no d-pad direction tapped during it (a quick move). Holds never switch.
# $2 (R2 state), $3 (L2), $16 (vehicle), $18 (pad) are live here; temporaries $8-$15, $24, $25 are free.
.globl tmbr_ShoulderTap
tmbr_ShoulderTap:
    andi    $8, $18, 0x7
    lui     $9, %hi(tmbr_shPrev)
    addiu   $9, $9, %lo(tmbr_shPrev)
    addu    $9, $9, $8
    lui     $10, %hi(tmbr_qmUsed)
    addiu   $10, $10, %lo(tmbr_qmUsed)
    addu    $10, $10, $8
    lbu     $11, 0x0($9)                # held last frame (bit 0 L1, bit 1 R1)
    lbu     $12, 0x0($10)               # used for a quick move during this hold
    lbu     $13, 0x5A1($16)
    sltu    $13, $0, $13
    lbu     $14, 0x5A2($16)
    sltu    $14, $0, $14
    sll     $14, $14, 1
    or      $13, $13, $14               # held now
    sb      $13, 0x0($9)
    # held for TAP_FRAMES (15 = 1/4 s) or longer: it's a hold, not a tap -> no weapon switch on release
    lui     $24, %hi(tmbr_shTime)
    addiu   $24, $24, %lo(tmbr_shTime)
    sll     $25, $8, 1
    addu    $24, $24, $25               # &tmbr_shTime[pad][0] (L1), [1] (R1)
    andi    $14, $13, 0x1
    beqz    $14, 3f
    daddu   $25, $0, $0                 # not held: counter back to 0
    lbu     $25, 0x0($24)
    addiu   $25, $25, 1
    sltiu   $14, $25, 15
    bnez    $14, 3f
    nop
    ori     $12, $12, 0x1
    ori     $25, $0, 15
3:  sb      $25, 0x0($24)
    andi    $14, $13, 0x2
    beqz    $14, 4f
    daddu   $25, $0, $0
    lbu     $25, 0x1($24)
    addiu   $25, $25, 1
    sltiu   $14, $25, 15
    bnez    $14, 4f
    nop
    ori     $12, $12, 0x2
    ori     $25, $0, 15
4:  sb      $25, 0x1($24)
    nor     $14, $13, $0
    and     $14, $11, $14               # released this frame
    nor     $15, $12, $0
    and     $15, $14, $15               # released and not used: a tap
    and     $12, $12, $13               # forget "used" once released
    ori     $14, $0, 0x3                # L1 + R1 together = jump: the game sees both held (as normal),
    bne     $13, $14, 5f                #  and neither switches weapons when released
    nop
    ori     $12, $12, 0x3
    ori     $15, $0, 0x3
5:  sb      $12, 0x0($10)
    andi    $11, $15, 0x1
    sb      $11, 0x5A1($16)
    srl     $11, $15, 1
    sb      $11, 0x5A2($16)
    beqz    $3, 1f                      # displaced `beqz $3, .L0017C060` ($3 = L2, loaded just before the hook;
    nop                                 #  its delay slot `sb $2, 0x5A4` ran in the hook's delay slot)
    j       tmbr_ret_17BF80
    nop
1:  j       tmbr_ret_17C060
    nop

.section .bss
tmbr_prevDpad: .space 8
tmbr_qmUsed: .space 8
tmbr_shPrev: .space 8
tmbr_shTime: .space 16
