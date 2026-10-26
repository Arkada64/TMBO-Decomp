# TMB-Reloaded mod: no rumble while VIBRATION is off in the options (Ark 2026-10-26: the pad rumbled a lot with it
# off). The option only clears the "use actuator" flag of pad index 0 (inputSetPlayerActuator(0, D_004FA878 != 0)),
# but a player's car rumbles the pad index stored in its player struct (+0x7B4), which online is the car slot
# (func_0017BDD8: +0x7B4 = vehicle +0x2100), so any slot other than 0 ignored the setting.
# Hook (tools/mods/apply_mods.py): inputSetActuator's first instruction becomes `j tmbr_Actuator`; the second
# (lui $2) runs in its delay slot and is redone here.
.set noat
.set noreorder
.section .text, "ax"
.align 3

.globl tmbr_Actuator
tmbr_Actuator:
    lui     $2, %hi(D_004FA878)          # vibration option (non-zero = on)
    lw      $2, %lo(D_004FA878)($2)
    bnez    $2, 1f
    nop
    jr      $31                          # off: never start a motor
    nop
1:  addiu   $29, $29, -0x40
    j       inputSetActuator__FiUcUci + 8
    lui     $2, %hi(D_00612CA0)
