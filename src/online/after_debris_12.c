#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_0022A6D8_128F48() __asm__("func_0022A6D8");

void func_00128F48(void* arg0) {
    s32 temp_v0;
    s32 var_s1;
    void* var_s0;

    var_s1 = 0x3F;
    var_s0 = arg0 + 0xA20;
    M2C_FIELD(arg0, s32* , 0) = 0;
    M2C_FIELD(arg0, s32* , 4) = 0;
    do {
        var_s1 -= 1;
        M2C_FIELD(M2C_FIELD(var_s0, void** , -0x100), s8* , 0xC) = 0;
        M2C_FIELD(M2C_FIELD(var_s0, void** , -0x100), s32* , 0) = 0;
        temp_v0 = M2C_FIELD(var_s0, s32* , 0);
        if (temp_v0 != -1) {
            func_0022A6D8_128F48(temp_v0);
            M2C_FIELD(var_s0, s32* , 0) = -1;
        }
        var_s0 += 4;
    } while (var_s1 >= 0);
}
