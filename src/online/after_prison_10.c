#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_00127188);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_00127330);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_001274D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_00127650);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_00127AF8);

#include "m2c_macros.h"
void* func_00213F80_127B00() __asm__("func_00213F80");
M2C_UNK hierCsAddToCsList__FP3_cs_127B00() __asm__("hierCsAddToCsList__FP3_cs");
M2C_UNK hierSetCsEpNode__FP3_csP9_hierhead_127B00() __asm__("hierSetCsEpNode__FP3_csP9_hierhead");

void* func_00127B00(s32 arg0) {
    void* temp_v0;

    temp_v0 = func_00213F80_127B00();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8* , 0xC) = 1;
        hierSetCsEpNode__FP3_csP9_hierhead_127B00(temp_v0, arg0);
        hierCsAddToCsList__FP3_cs_127B00(temp_v0);
    }
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", func_00127B58);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", D_004E0598);
