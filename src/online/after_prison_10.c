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

#include "m2c_macros.h"
void* func_00213FF8_127B58() __asm__("func_00213FF8");
M2C_UNK hierCsAddToCsList__FP3_cs_127B58() __asm__("hierCsAddToCsList__FP3_cs");
M2C_UNK hierSetCsEpNode__FP3_csP9_hierhead_127B58() __asm__("hierSetCsEpNode__FP3_csP9_hierhead");
extern M2C_UNK D_002B9528_127B58 __asm__("D_002B9528");

void* func_00127B58(s32 arg0, s32 arg1) {
    s32* temp_s0;
    void* temp_s1;

    temp_s0 = (arg1 * 0x1) + &D_002B9528_127B58;
    temp_s1 = func_00213FF8_127B58(arg1, *temp_s0);
    *temp_s0 += 1;
    if (temp_s1 != NULL) {
        M2C_FIELD(temp_s1, s8* , 0xC) = 1;
        hierSetCsEpNode__FP3_csP9_hierhead_127B58(temp_s1, arg0);
        hierCsAddToCsList__FP3_cs_127B58(temp_s1);
    }
    return temp_s1;
}

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_prison_10", D_004E0598);
