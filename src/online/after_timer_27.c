#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_00268260_159F28() __asm__("func_00268260");

void func_00159F28(void* arg0, void* arg1) {
    s32 temp_a0;
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg1, s32* , 0x20B4);
    if ((temp_v1 == 1) || (temp_v1 == 4)) {
        temp_a0 = M2C_FIELD(arg0, s32* , 0x580);
        if (temp_a0 >= 0) {
            func_00268260_159F28(temp_a0);
            M2C_FIELD(arg0, s32* , 0x580) = -1;
        }
    }
}

void func_00159F80(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_timer_27", func_00159F88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_timer_27", func_0015A0B8);
