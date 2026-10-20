#include "common.h"

#include "m2c_macros.h"
void func_001AC7C8(void* arg0) {
    s32 var_v0;
    void* var_a0;

    var_a0 = arg0;
    var_v0 = 0xA;
    do {
        M2C_FIELD(var_a0, s32* , 0) = 0;
        var_v0 -= 1;
        M2C_FIELD(var_a0, s32* , 8) = 0;
        var_a0 += 0x110;
    } while (var_v0 != 0);
}

#include "m2c_macros.h"
s32 func_00213F80_1AC7F8() __asm__("func_00213F80");
M2C_UNK hierCsAddToCsList__FP3_cs_1AC7F8() __asm__("hierCsAddToCsList__FP3_cs");

void func_001AC7F8(void* arg0) {
    s32 temp_v0;
    s32 var_s1;
    void* var_s0;

    var_s1 = 0xA;
    var_s0 = arg0;
    do {
        var_s1 -= 1;
        temp_v0 = func_00213F80_1AC7F8();
        M2C_FIELD(var_s0, s32* , 8) = temp_v0;
        hierCsAddToCsList__FP3_cs_1AC7F8(temp_v0);
        var_s0 += 0x110;
    } while (var_s1 != 0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", func_001AC840);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", BlowDebris__16TimberDebrisPoolP12DestructiblefP8_fvectorP10TakeHitDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", func_001ACA28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", Init__12TimberDebrisP12Destructible);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", Deactivate__12TimberDebris);
