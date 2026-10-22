#include "common.h"
#include "m2c_macros.h"

void InitBefore__16TimberDebrisPool(void* arg0) {
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

int hierCsAddToCsList__FP3_cs_48_2(void*) __asm__("hierCsAddToCsList__FP3_cs");
int csCreate__Fv_48_2(void) __asm__("csCreate__Fv");
s32 InitAfter__16TimberDebrisPool(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    void* var_s0;

    var_s1 = 0xA;
    var_s0 = arg0;
    do {
        var_s1 -= 1;
        temp_v0_2 = csCreate__Fv_48_2();
        M2C_FIELD(var_s0, s32* , 8) = temp_v0_2;
        temp_v0 = hierCsAddToCsList__FP3_cs_48_2((void* ) temp_v0_2);
        var_s0 += 0x110;
    } while (var_s1 != 0);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", Update__16TimberDebrisPool);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", BlowDebris__16TimberDebrisPoolP12DestructiblefP8_fvectorP10TakeHitDat);

s32 skipInstanceProxy__FP9_hierhead(void* arg0) {
    if ((M2C_FIELD(arg0, s32* , 0) & 0xFFFC0000) == 0x68280000) {
        return M2C_FIELD(arg0, s32* , 0x20);
    }
    return (s32) arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", Init__12TimberDebrisP12Destructible);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", TestHAT__12TimberDebrisP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", Update__12TimberDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", Deactivate__12TimberDebris);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timberdebris", func_00189C80);
