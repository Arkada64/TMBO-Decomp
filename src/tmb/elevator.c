#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/elevator", Init__8Elevator);

#include "m2c_macros.h"
void func_001318E8(s32 arg0) {
    s32 var_v0;
    s32* var_a0;

    var_a0 = arg0 + 0x4C;
    var_v0 = 3;
    do {
        *var_a0 = 0;
        var_v0 -= 1;
        var_a0 -=0x1;
    } while (var_v0 >= 0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/elevator", func_00131918);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/elevator", func_00131DB0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/elevator", func_00131F08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/elevator", func_00131FB8);
