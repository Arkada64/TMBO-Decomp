#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", func_00136C88);

#include "m2c_macros.h"
int initAfter__12FreewayTrain_136CE0(void*) __asm__("initAfter__12FreewayTrain");
int animationSetToPercent__FR11_animHandlef_136CE0(void*, float) __asm__("animationSetToPercent__FR11_animHandlef");
M2C_UNK func_001FBCF8_136CE0() __asm__("func_001FBCF8");

void func_00136CE0(s32 arg0) {
    u8 sp[0x10];
    initAfter__12FreewayTrain_136CE0(arg0 + 0x60);
    initAfter__12FreewayTrain_136CE0(arg0 + 0x1E0);
    func_001FBCF8_136CE0(sp, 0x2849, 0, 1);
    animationSetToPercent__FR11_animHandlef_136CE0(sp, 0.0f);
    func_001FBCF8_136CE0(arg0 + 0x50, 0x17DF, 0, 0);
}

#include "m2c_macros.h"
M2C_UNK func_00136D88_136D48() __asm__("func_00136D88");
M2C_UNK func_00136E70_136D48() __asm__("func_00136E70");
M2C_UNK func_001375C0_136D48() __asm__("func_001375C0");

void func_00136D48(s32 arg0) {
    func_00136D88_136D48();
    func_00136E70_136D48(arg0);
    func_001375C0_136D48(arg0 + 0x60);
    func_001375C0_136D48(arg0 + 0x1E0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", func_00136D88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", func_00136E70);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", D_004E22E0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", D_004E2300);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", D_004E2330);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/freeway", D_004E2340);
