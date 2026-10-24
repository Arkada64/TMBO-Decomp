# TMB-Reloaded: net codes for more than 2 bots (bots mod, MAXBOTS 7).
# The game names a bot in net messages as -2 (game->ais[0]) or -3 (anything else): weapon create/update/
# destroy (func_00171818 -> netWeapon*CB, func_001735E8) and the kill event 0x2B (func_001E1C40 ->
# netMsgGameEventHandler). With 6 bots, bots 2..5 all decoded as ais[1] on the other machines (their shots
# and kills showed up on the wrong car). Code is now -2 - index (-2..-8); apply_mods.py points the game's
# inline encode/decode blocks here. Both routines only touch $1-$3 so they can sit in the middle of the
# game's code without disturbing its live registers.
.set noat
.set noreorder
.section .text, "ax"
.align 3

# $4 = vehicle -> $2 = -2 - (its index in game->ais[]), -3 when not found (the original "other bot" code).
# Clobbers $1, $2, $3.
.globl tmbr_BotCode
tmbr_BotCode:
    lui     $1, %hi(D_004FA030)
    lw      $1, %lo(D_004FA030)($1)
    lui     $2, 0xA
    addu    $1, $1, $2
    addiu   $1, $1, -0x1970          # &game->ais[0] (game + 0x9E690)
    addiu   $2, $0, -2
1:  lw      $3, 0($1)
    beq     $3, $4, 2f
    addiu   $1, $1, 4
    addiu   $2, $2, -1
    slti    $3, $2, -8
    beqz    $3, 1b
    nop
    addiu   $2, $0, -3
2:  jr      $31
    nop

# $2 = code (sign-extended) -> $2 = game->ais[-2 - code] for -2..-8, else 0. Clobbers $1, $2.
.globl tmbr_BotByCode
tmbr_BotByCode:
    addiu   $2, $2, 2
    subu    $2, $0, $2               # index 0..5
    sltiu   $1, $2, 7
    beqz    $1, 3f
    sll     $2, $2, 2
    lui     $1, %hi(D_004FA030)
    lw      $1, %lo(D_004FA030)($1)
    addu    $2, $2, $1
    lui     $1, 0xA
    addu    $2, $2, $1
    jr      $31
    lw      $2, -0x1970($2)
3:  jr      $31
    daddu   $2, $0, $0
