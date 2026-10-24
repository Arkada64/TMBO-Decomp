# Vanilla pnach: damage reports for every hit, also on remote players' cars (func_001E1C40 only reports damage
# to the network for cars this console owns, so a hook on that call never sees online opponents).
# Replaces 0x1E2498 `lw $3, 0x20B4($17)` + 0x1E249C `beql $3, $2, 0x1E24D0` (delay: lwc1 $f1, 0x404($17)).
# Live here: $2 (= 2), $f0 (= 0, used on the 0x1E24D0 path), callee-saved s1 victim, s3 attacker, $f22 damage.
.globl tmbr_DmgGate
tmbr_DmgGate:
    addiu   $29, $29, -0x20
    sw      $31, 0x0($29)
    sw      $2, 0x4($29)
    swc1    $f0, 0x8($29)
    daddu   $4, $17, $0                 # victim
    daddu   $5, $19, $0                 # attacker
    jal     tmbr_DmgSeen                # dmgreport.c
    mov.s   $f12, $f22                  # damage
    lw      $31, 0x0($29)
    lw      $2, 0x4($29)
    lwc1    $f0, 0x8($29)
    addiu   $29, $29, 0x20
    lw      $3, 0x20B4($17)             # displaced
    bne     $3, $2, 1f
    nop
    j       tmbr_ret_1E24D0             # remote car: as the beql
    lwc1    $f1, 0x404($17)
1:  j       tmbr_ret_1E24A4
    nop
tmbr_DmgGate_end:
