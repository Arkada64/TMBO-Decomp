#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_00109810);

void func_00109DC8(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_00109DD0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_00109EB0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_00109EE0);

#include "m2c_macros.h"
extern s32 D_002B8AD4_109F20 __asm__("D_002B8AD4");

void func_00109F20(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    if (M2C_FIELD(arg3, s8* , 0x15) != 0) {
        D_002B8AD4_109F20 = 3;
        return;
    }
    D_002B8AD4_109F20 = 4;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_00109F48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A090);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A0A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A100);

#include "m2c_macros.h"
void* func_0010A1F0(void* arg0) {
    M2C_FIELD(arg0, s32* , 0xD4) = 0;
    M2C_FIELD(arg0, s32* , 0) = -1;
    M2C_FIELD(arg0, s32* , 0xD8) = 0;
    M2C_FIELD(arg0, s32* , 0xE0) = 0;
    M2C_FIELD(arg0, s32* , 0xE4) = 0;
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A210);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A2A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A380);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A588);

#include "m2c_macros.h"
s32 func_0010A678(void* arg0) {
    return M2C_FIELD_V1(arg0, s32* , 0xD4);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A680);

#include "m2c_macros.h"
M2C_UNK func_0028B414_10A748() __asm__("func_0028B414");

void func_0010A748(void* arg0) {
    func_0028B414_10A748();
    M2C_FIELD_V1(arg0, s32* , 0xD4) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A770);

#include "m2c_macros.h"
void func_0010A7D8(void* arg0, s32 arg1) {
    M2C_FIELD_V1(arg0, s32* , 0xDC) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A7E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A8B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A938);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010A9C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010AA00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010AB98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010ABB8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010ABF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010AD30);

#include "m2c_macros.h"
M2C_UNK func_0010A1F0_10AE80() __asm__("func_0010A1F0");
extern M2C_UNK D_002B8A00_10AE80 __asm__("D_002B8A00");

void func_0010AE80(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 != 0) {
            func_0010A1F0_10AE80(&D_002B8A00_10AE80);
        }
    }
}

#include "m2c_macros.h"
M2C_UNK func_0010AE80_10AEB0() __asm__("func_0010AE80");

void func_0010AEB0(void) {
    func_0010AE80_10AEB0(1, 0xFFFF);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_ai_03", func_0010AED0);
