#include "common.h"

#include "m2c_macros.h"
void func_001AC7C8(void* arg0) {
    s32 var_v0;
    void* var_a0;

    var_a0 = arg0;
    var_v0 = 0xA;
    do {
        M2C_FIELD_V1(var_a0, s32* , 0) = 0;
        var_v0 -= 1;
        M2C_FIELD_V1(var_a0, s32* , 8) = 0;
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
        M2C_FIELD_V1(var_s0, s32* , 8) = temp_v0;
        hierCsAddToCsList__FP3_cs_1AC7F8(temp_v0);
        var_s0 += 0x110;
    } while (var_s1 != 0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", func_001AC840);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", BlowDebris__16TimberDebrisPoolP12DestructiblefP8_fvectorP10TakeHitDat);

#include "m2c_macros.h"
void* func_001ACA28(void* arg0) {
    if ((M2C_FIELD(arg0, s32* , 0) & 0xFFFC0000) == 0x68280000) {
        return M2C_FIELD(arg0, void** , 0x20);
    }
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/timberdebris", Init__12TimberDebrisP12Destructible);

#include "m2c_macros.h"
f32 hdHatTest__FP8_fvectorT0P14ColorUnionType_Debris() __asm__("hdHatTest__FP8_fvectorT0P14ColorUnionType");
f32 terrainGetQuickHAT__FP8_fvector_Debris() __asm__("terrainGetQuickHAT__FP8_fvector");

f32 Deactivate__12TimberDebris(void *arg0, M2C_UNK arg1, void *arg2)
{
  s32 temp_v1;
  temp_v1 = (((u32) (*(*((u32 **) (((u8 *) arg0) + 4))))) >> 7) & 0x7FF;
  switch (temp_v1)
  {
    case 0:
      *((s32 *) (((u8 *) arg2) + 0)) = 0;
      *((f32 *) (((u8 *) arg2) + 8)) = 1.0f;
 do { *((s32 *) (((u8 *) arg2) + 4)) = 0; return terrainGetQuickHAT__FP8_fvector_Debris(arg1, arg2); } while (0);

    case 1:
      return hdHatTest__FP8_fvectorT0P14ColorUnionType_Debris(arg1, arg2, 0);

    default:
      return 0.0f;

  }

}
