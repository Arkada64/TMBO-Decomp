#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_freeway_17", func_00137378);

#include "m2c_macros.h"
M2C_UNK timerGetFieldCount__Fv_137450() __asm__("timerGetFieldCount__Fv");

void func_00137450(void) {
    timerGetFieldCount__Fv_137450();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_freeway_17", func_00137470);

#include "m2c_macros.h"
M2C_UNK plightDestroy__FP11_pointlight_1374D8() __asm__("plightDestroy__FP11_pointlight");

void func_001374D8(void* arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0x360);
    if (temp_a0 != 0) {
        plightDestroy__FP11_pointlight_1374D8(temp_a0);
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_freeway_17", func_00137500);
