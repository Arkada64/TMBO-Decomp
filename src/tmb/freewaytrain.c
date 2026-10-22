#include "common.h"
#include "m2c_macros.h"

void initBefore__15FreewayTrainCar_40_0(void*) __asm__("initBefore__15FreewayTrainCar");
s32 initBefore__12FreewayTrain(void* arg0) {
    s32 temp_v0;
    void* temp_s1;
    void* var_s0;

    var_s0 = arg0;
    temp_s1 = var_s0 + 0x180;
    do {
        initBefore__15FreewayTrainCar_40_0(var_s0);
        var_s0 += 0x60;
        temp_v0 = (s32) var_s0 < (s32) temp_s1;
    } while (temp_v0 != 0);
    return temp_v0;
}

void initAfter__15FreewayTrainCar_40_3(void*) __asm__("initAfter__15FreewayTrainCar");
s32 initAfter__12FreewayTrain(void* arg0) {
    s32 temp_v0;
    void* temp_s1;
    void* var_s0;

    var_s0 = arg0;
    temp_s1 = var_s0 + 0x180;
    do {
        initAfter__15FreewayTrainCar_40_3(var_s0);
        var_s0 += 0x60;
        temp_v0 = (s32) var_s0 < (s32) temp_s1;
    } while (temp_v0 != 0);
    return temp_v0;
}

void update__15FreewayTrainCar_7C_6(void*) __asm__("update__15FreewayTrainCar");
void initBefore__15FreewayTrainCar_7C_6(void*) __asm__("initBefore__15FreewayTrainCar");
extern u8 g_restartTrains_7C_6[4] __asm__("g_restartTrains");

s32 update__12FreewayTrain(void* arg0) {
    s32 temp_v0;
    void* temp_s1;
    void* var_s0;
    void* var_s0_2;

    if ((*(s32*)g_restartTrains_7C_6) != 0) {
        (*(s32*)g_restartTrains_7C_6) = 0;
        var_s0 = arg0;
        do {
            initBefore__15FreewayTrainCar_7C_6(var_s0);
            var_s0 += 0x60;
        } while ((s32) var_s0 < (s32) (arg0 + 0x180));
    }
    var_s0_2 = arg0;
    temp_s1 = var_s0_2 + 0x180;
    do {
        update__15FreewayTrainCar_7C_6(var_s0_2);
        var_s0_2 += 0x60;
        temp_v0 = (s32) var_s0_2 < (s32) temp_s1;
    } while (temp_v0 != 0);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", addNode__12FreewayTrainiP9_hierhead);

void blowUpCar__15FreewayTrainCarP9_hierheadfP8_fvectori_78_12(void *, void *, float, void *, int) __asm__("blowUpCar__15FreewayTrainCarP9_hierheadfP8_fvectori");
s32 BlowUpCar__12FreewayTrainP9_hierheadifP8_fvector(void *arg0, void *arg1, s32 arg2, f32 fparg0, void *arg3)
{
  s32 temp_a3;
  s32 temp_v0;
  s32 var_s0;
  void *var_s1;
  var_s1 = arg0;
  var_s0 = 0;
  do
  {
    blowUpCar__15FreewayTrainCarP9_hierheadfP8_fvectori_78_12(var_s1, *((void **) (((u8 *) arg1) + 0x14)), fparg0, arg3, var_s0);
    ;
    var_s0 += 1;
    temp_v0 = var_s0 < 4;
    var_s1 += 0x60;
  }
  while (temp_v0 != 0);
  return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", update__15FreewayTrainCar);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", finishExplosion__15FreewayTrainCarP8_fvectorb);

void mathfScaleVector__FP8_fvectorT0f_94_21(void*, void*, float) __asm__("mathfScaleVector__FP8_fvectorT0f");
int mathfCopyVector__FP8_fvectorT0_94_21(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
s32 blowUpCar__15FreewayTrainCarP9_hierheadfP8_fvectori(void* arg0, void* arg1, f32 fparg0, void* arg2, s32 arg3) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = 2;
    var_v1 = M2C_FIELD(arg0, s32* , 0x54);
    if (var_v1 == 2) {
        M2C_FIELD(arg0, s32* , 0x54) = 0;
        var_v1 = 0;
        M2C_FIELD(arg0, s32* , 0x58) = 0;
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s32* , 0x54) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void** , 4), s8* , 8) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void** , 0), s8* , 0xC) = 1;
        mathfScaleVector__FP8_fvectorT0f_94_21(arg0 + 0x30, M2C_FIELD(arg0, s32* , 0x5C) + 0x20, -1.0f);
        var_v0 = mathfCopyVector__FP8_fvectorT0_94_21(M2C_FIELD(arg0, void** , 0) + 0x10, M2C_FIELD(arg0, s32* , 0x5C) + 0x30);
        M2C_FIELD(arg0, s32* , 0x50) = arg3;
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", getPos__15FreewayTrainCarP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", initBefore__15FreewayTrainCar);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", initAfter__15FreewayTrainCar);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", getCarPos__12FreewayTrainiP8_fvector);

void finishExplosion__15FreewayTrainCarP8_fvectorb_44_35(void*, void*, unsigned char) __asm__("finishExplosion__15FreewayTrainCarP8_fvectorb");
void getPos__15FreewayTrainCarP8_fvector_44_35(void*, void*) __asm__("getPos__15FreewayTrainCarP8_fvector");

void popCar__12FreewayTraini(s32 arg0, s32 arg1) {
    u8 sp[0x10];
    s32 temp_s0;

    temp_s0 = (arg1 * 0x60) + arg0;
    getPos__15FreewayTrainCarP8_fvector_44_35(temp_s0, sp);
    finishExplosion__15FreewayTrainCarP8_fvectorb_44_35(temp_s0, sp, 1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/freewaytrain", func_0012EA60);
