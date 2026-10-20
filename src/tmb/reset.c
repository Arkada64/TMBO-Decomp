#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_00230060_183D88() __asm__("func_00230060");
extern M2C_UNK D_004E9C40_183D88 __asm__("D_004E9C40");

void* func_00183D88(void* arg0) {
    func_00230060_183D88();
    M2C_FIELD_V1(arg0, M2C_UNK** , 0x4094) = &D_004E9C40_183D88;
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/reset", func_00183DC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/reset", func_00183FA8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/reset", func_00184148);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/reset", D_004E9C40);
