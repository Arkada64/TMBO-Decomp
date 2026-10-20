#include "common.h"

#include "m2c_macros.h"
s32 func_002A8DD8_2201C8() __asm__("func_002A8DD8");
M2C_UNK sceMcInit_2201C8() __asm__("sceMcInit");

s32 func_002201C8(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if ((M2C_FIELD(arg0, s32* , 0) < 0) && ((temp_v0 = func_002A8DD8_2201C8("cdrom0:\\MOD\\MCMAN.IRX;1", 0, 0), M2C_FIELD(arg0, s32* , 0) = temp_v0, (temp_v0 < 0)) || (temp_v0_2 = func_002A8DD8_2201C8("cdrom0:\\MOD\\MCSERV.IRX;1", 0, 0), M2C_FIELD(arg0, s32* , 4) = temp_v0_2, (temp_v0_2 < 0)))) {
        return 0;
    }
    sceMcInit_2201C8();
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/online/after_mathv0_72", func_00220240);

void func_002202E0(void) {
}
