#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00242658);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00242930);

#include "m2c_macros.h"
M2C_UNK func_0023B890_Info14() __asm__("func_0023B890");

void viewGetTOD__FPiPfP10_todInfo14(void) {
    func_0023B890_Info14();
}

#include "m2c_macros.h"
M2C_UNK func_0023BAC0_FifPvf() __asm__("func_0023BAC0");

void viewSetTOD__FifPvf(void) {
    func_0023BAC0_FifPvf();
}

#include "m2c_macros.h"
extern char D_004CFB90_ot__Fi __asm__("D_004CFB90");

s32 viewGetRot__Fi(s32 arg0)
{
  M2C_UNK *new_var;
  new_var = (arg0 * 0x10) + (&D_004CFB90_ot__Fi);
  return (*new_var) + 0x60;
}

#include "m2c_macros.h"
extern M2C_UNK D_004CFB90_at__Fi __asm__("D_004CFB90");

s32 viewGetMat__Fi(s32 arg0) {
    return *((arg0 * 0x4) + &D_004CFB90_at__Fi) + 0x20;
}

#include "m2c_macros.h"
extern M2C_UNK D_004CFB90_ns__Fi __asm__("D_004CFB90");

s32 viewGetTrans__Fi(s32 arg0) {
    return *((arg0 * 0x4) + &D_004CFB90_ns__Fi) + 0x10;
}

#include "m2c_macros.h"
extern volatile unsigned char D_004CFB90_ectori __asm__("D_004CFB90");

void viewSetRot__FP8_fvectori(void *arg0, s32 arg1)
{
  void **temp_a1;
  temp_a1 = (arg1 * 0x10) + (&D_004CFB90_ectori);
  *((f32 *) (((u8 *) (*temp_a1)) + 0x60)) = (f32) (*((f32 *) (((u8 *) arg0) + 0)));
  *((f32 *) (((u8 *) (*temp_a1)) + 0x64)) = (f32) (*((f32 *) (((u8 *) arg0) + 4)));
  *((f32 *) (((u8 *) (*temp_a1)) + 0x68)) = (f32) (*((f32 *) (((u8 *) arg0) + 8)));
}

#include "m2c_macros.h"
extern unsigned char D_004CFB90_ectori __asm__("D_004CFB90");

void viewSetTrans__FP8_fvectori(void *arg0, s32 arg1)
{
  void **temp_a1;
  temp_a1 = (arg1 * 0x10) + (&D_004CFB90_ectori);
  *((f32 *) (((u8 *) (*temp_a1)) + 0x10)) = (f32) (*((f32 *) (((u8 *) arg0) + 0)));
  *((f32 *) (((u8 *) (*temp_a1)) + 0x14)) = (f32) (*((f32 *) (((u8 *) arg0) + 4)));
  *((f32 *) (((u8 *) (*temp_a1)) + 0x18)) = (f32) (*((f32 *) (((u8 *) arg0) + 8)));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetCurView__Fv);

#include "m2c_macros.h"
extern unsigned char D_004CFB90_Cs__Fi __asm__("D_004CFB90");

s32 viewGetViewCs__Fi(s32 arg0)
{
  M2C_UNK *new_var;
  new_var = ((2 * arg0) * 8) + (&D_004CFB90_Cs__Fi);
  return *new_var;
}

#include "m2c_macros.h"
extern unsigned char D_0048CC70_tx__Fi __asm__("D_0048CC70");

void *viewGetWorldCtx__Fi(s32 arg0)
{
  M2C_UNK *new_var;
  new_var = ((16 * (15 * arg0)) & 0xFFFFFFFFFFFFFFFFu) + (&D_0048CC70_tx__Fi);
  return new_var;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00242F30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetAmbientVol__Fiffff);

#include "m2c_macros.h"
extern char D_0048CC90_ns__Fi __asm__("D_0048CC90");

void *viewGetWeTrans__Fi(s32 arg0)
{
  return (arg0 * 0xF0) + (&D_0048CC90_ns__Fi);
}

#include "m2c_macros.h"
extern volatile unsigned char D_0048CCA0_at__Fi __asm__("D_0048CCA0");

void *viewGetWeMat__Fi(s32 arg0)
{
  return (arg0 * 0xF0) + (&D_0048CCA0_at__Fi);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00242FE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetSky__Fi);

#include "m2c_macros.h"
s32 viewGameIsInRearViewMode__Fv_2430E0() __asm__("viewGameIsInRearViewMode__Fv");
extern M2C_UNK D_0048CC70_2430E0 __asm__("D_0048CC70");

void func_002430E0(void* arg0, s32 arg1) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    void* temp_v1;
    void* temp_v1_2;
    void* temp_v1_3;

    temp_v1 = (arg1 * 0x3c) + &D_0048CC70_2430E0;
    temp_v0 = M2C_FIELD(temp_v1, void** , 4);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0);
        M2C_FIELD(M2C_FIELD(temp_v1, void** , 4), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4);
        M2C_FIELD(M2C_FIELD(temp_v1, void** , 4), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8);
        if ((viewGameIsInRearViewMode__Fv_2430E0() != 0) && (arg1 == 0)) {
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF4), f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF4), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF4), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8);
        }
    }
    temp_v1_2 = (arg1 * 0x3c) + &D_0048CC70_2430E0;
    temp_v0_2 = M2C_FIELD(temp_v1_2, void** , 8);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0);
        M2C_FIELD(M2C_FIELD(temp_v1_2, void** , 8), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4);
        M2C_FIELD(M2C_FIELD(temp_v1_2, void** , 8), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8);
        if ((viewGameIsInRearViewMode__Fv_2430E0() != 0) && (arg1 == 0)) {
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF8), f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF8), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xF8), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8);
        }
    }
    temp_v1_3 = (arg1 * 0x3c) + &D_0048CC70_2430E0;
    temp_v0_3 = M2C_FIELD(temp_v1_3, void** , 0xC);
    if ((temp_v0_3 != NULL) && (M2C_FIELD(temp_v0_3, f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0), M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xC), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4), M2C_FIELD(M2C_FIELD(temp_v1_3, void** , 0xC), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8), (viewGameIsInRearViewMode__Fv_2430E0() != 0))) {
        if (arg1 == 0) {
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xFC), f32* , 0x10) = (f32) M2C_FIELD(arg0, f32* , 0);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xFC), f32* , 0x14) = (f32) M2C_FIELD(arg0, f32* , 4);
            M2C_FIELD(M2C_FIELD(&D_0048CC70_2430E0, void** , 0xFC), f32* , 0x18) = (f32) M2C_FIELD(arg0, f32* , 8);
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetSkyNode__FP9_hierheadi);

#include "m2c_macros.h"
extern M2C_UNK D_002B7368__fT0T0 __asm__("D_002B7368");
extern M2C_UNK D_002B73B0__fT0T0 __asm__("D_002B73B0");
extern M2C_UNK D_002B7458__fT0T0 __asm__("D_002B7458");
extern M2C_UNK D_002B7C88__fT0T0 __asm__("D_002B7C88");
extern M2C_UNK D_002B7CD0__fT0T0 __asm__("D_002B7CD0");

void viewSetVUPacketMat__FPA3_fT0T0(void* arg0, void* arg1, void* arg2) {
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0) = (s32) M2C_FIELD_V1(arg0, s32* , 0);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 4) = (s32) M2C_FIELD_V1(arg0, s32* , 0x10);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 8) = (s32) M2C_FIELD_V1(arg0, s32* , 0x20);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0xC) = (s32) M2C_FIELD_V1(arg0, s32* , 0x30);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x10) = (s32) M2C_FIELD_V1(arg0, s32* , 4);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x14) = (s32) M2C_FIELD_V1(arg0, s32* , 0x14);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x18) = (s32) M2C_FIELD_V1(arg0, s32* , 0x24);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x1C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x34);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x20) = (s32) M2C_FIELD_V1(arg0, s32* , 8);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x24) = (s32) M2C_FIELD_V1(arg0, s32* , 0x18);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x28) = (s32) M2C_FIELD_V1(arg0, s32* , 0x28);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x2C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x38);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x30) = (s32) M2C_FIELD_V1(arg0, s32* , 0xC);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x34) = (s32) M2C_FIELD_V1(arg0, s32* , 0x1C);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x38) = (s32) M2C_FIELD_V1(arg0, s32* , 0x2C);
    M2C_FIELD_V1(&D_002B7368__fT0T0, s32* , 0x3C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x3C);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0) = (s32) M2C_FIELD_V1(arg1, s32* , 0);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 4) = (s32) M2C_FIELD_V1(arg1, s32* , 0x10);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 8) = (s32) M2C_FIELD_V1(arg1, s32* , 0x20);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0xC) = (s32) M2C_FIELD_V1(arg1, s32* , 0x30);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x10) = (s32) M2C_FIELD_V1(arg1, s32* , 4);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x14) = (s32) M2C_FIELD_V1(arg1, s32* , 0x14);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x18) = (s32) M2C_FIELD_V1(arg1, s32* , 0x24);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x1C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x34);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x20) = (s32) M2C_FIELD_V1(arg1, s32* , 8);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x24) = (s32) M2C_FIELD_V1(arg1, s32* , 0x18);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x28) = (s32) M2C_FIELD_V1(arg1, s32* , 0x28);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x2C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x38);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x30) = (s32) M2C_FIELD_V1(arg1, s32* , 0xC);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x34) = (s32) M2C_FIELD_V1(arg1, s32* , 0x1C);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x38) = (s32) M2C_FIELD_V1(arg1, s32* , 0x2C);
    M2C_FIELD_V1(&D_002B73B0__fT0T0, s32* , 0x3C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x3C);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0) = (s32) M2C_FIELD_V1(arg2, s32* , 0);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 4) = (s32) M2C_FIELD_V1(arg2, s32* , 0x10);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 8) = (s32) M2C_FIELD_V1(arg2, s32* , 0x20);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0xC) = (s32) M2C_FIELD_V1(arg2, s32* , 0x30);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x10) = (s32) M2C_FIELD_V1(arg2, s32* , 4);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x14) = (s32) M2C_FIELD_V1(arg2, s32* , 0x14);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x18) = (s32) M2C_FIELD_V1(arg2, s32* , 0x24);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x1C) = (s32) M2C_FIELD_V1(arg2, s32* , 0x34);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x20) = (s32) M2C_FIELD_V1(arg2, s32* , 8);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x24) = (s32) M2C_FIELD_V1(arg2, s32* , 0x18);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x28) = (s32) M2C_FIELD_V1(arg2, s32* , 0x28);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x2C) = (s32) M2C_FIELD_V1(arg2, s32* , 0x38);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x30) = (s32) M2C_FIELD_V1(arg2, s32* , 0xC);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x34) = (s32) M2C_FIELD_V1(arg2, s32* , 0x1C);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x38) = (s32) M2C_FIELD_V1(arg2, s32* , 0x2C);
    M2C_FIELD_V1(&D_002B7458__fT0T0, s32* , 0x3C) = (s32) M2C_FIELD_V1(arg2, s32* , 0x3C);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0) = (s32) M2C_FIELD_V1(arg0, s32* , 0);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 4) = (s32) M2C_FIELD_V1(arg0, s32* , 0x10);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 8) = (s32) M2C_FIELD_V1(arg0, s32* , 0x20);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0xC) = (s32) M2C_FIELD_V1(arg0, s32* , 0x30);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x10) = (s32) M2C_FIELD_V1(arg0, s32* , 4);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x14) = (s32) M2C_FIELD_V1(arg0, s32* , 0x14);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x18) = (s32) M2C_FIELD_V1(arg0, s32* , 0x24);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x1C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x34);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x20) = (s32) M2C_FIELD_V1(arg0, s32* , 8);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x24) = (s32) M2C_FIELD_V1(arg0, s32* , 0x18);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x28) = (s32) M2C_FIELD_V1(arg0, s32* , 0x28);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x2C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x38);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x30) = (s32) M2C_FIELD_V1(arg0, s32* , 0xC);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x34) = (s32) M2C_FIELD_V1(arg0, s32* , 0x1C);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x38) = (s32) M2C_FIELD_V1(arg0, s32* , 0x2C);
    M2C_FIELD_V1(&D_002B7C88__fT0T0, s32* , 0x3C) = (s32) M2C_FIELD_V1(arg0, s32* , 0x3C);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0) = (s32) M2C_FIELD_V1(arg1, s32* , 0);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 4) = (s32) M2C_FIELD_V1(arg1, s32* , 0x10);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 8) = (s32) M2C_FIELD_V1(arg1, s32* , 0x20);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0xC) = (s32) M2C_FIELD_V1(arg1, s32* , 0x30);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x10) = (s32) M2C_FIELD_V1(arg1, s32* , 4);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x14) = (s32) M2C_FIELD_V1(arg1, s32* , 0x14);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x18) = (s32) M2C_FIELD_V1(arg1, s32* , 0x24);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x1C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x34);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x20) = (s32) M2C_FIELD_V1(arg1, s32* , 8);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x24) = (s32) M2C_FIELD_V1(arg1, s32* , 0x18);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x28) = (s32) M2C_FIELD_V1(arg1, s32* , 0x28);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x2C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x38);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x30) = (s32) M2C_FIELD_V1(arg1, s32* , 0xC);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x34) = (s32) M2C_FIELD_V1(arg1, s32* , 0x1C);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x38) = (s32) M2C_FIELD_V1(arg1, s32* , 0x2C);
    M2C_FIELD_V1(&D_002B7CD0__fT0T0, s32* , 0x3C) = (s32) M2C_FIELD_V1(arg1, s32* , 0x3C);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewApplySwap__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetBgColor__FUlUlUlUl);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetTODBgColor__FUlUlUlUl);

#include "m2c_macros.h"
extern M2C_UNK D_004D0200_T0T0T0 __asm__("D_004D0200");

void viewGetBgColor__FRiT0T0T0(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
  char pad;
  u8 *new_var;
  u8 *new_var2;
  new_var2 = (u8 *) (&D_004D0200_T0T0T0);
  *arg0 = (s32) (*((u8 *) ((new_var = new_var2) + 0x1B0)));
  *arg1 = (s32) (*((u8 *) (new_var2 + 0x1B1)));
  *arg2 = (s32) (*((u8 *) (new_var2 + 0x1B2)));
  *arg3 = (s32) (*((u8 *) (((u8 *) (&D_004D0200_T0T0T0)) + 0x1B3)));
}

#include "m2c_macros.h"
extern volatile unsigned char D_004D0200_Db__Fi __asm__("D_004D0200");

void *viewGetDb__Fi(s32 arg0)
{
  return (arg0 * 0x360) + (&D_004D0200_Db__Fi);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetNumViews__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetNumViews__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewIsRearView__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGameIsInRearViewMode__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewIsRearViewSmall__Fi);

#include "m2c_macros.h"
extern char D_004CFB90_ge__Fi __asm__("D_004CFB90");

s32 viewIsRearViewLarge__Fi(s32 arg0)
{
  s32 *new_var;
  int new_var2;
  new_var2 = 8;
  new_var = (s32 *) (((u8 *) ((&D_004CFB90_ge__Fi) + (arg0 * 0x10))) + new_var2);
  return (*new_var) == 0xF;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewIsRearLargeActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewIsRearSmallActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetRearViewConfig__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243930);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243968);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetCenter__FiPiT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243AA8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetZBuffParams__FiPfT1);

#include "m2c_macros.h"
extern char D_004D00F0_at__Fi __asm__("D_004D00F0");

void *viewGetWorldToScreenMat__Fi(s32 arg0)
{
  if (1)
  {
    return (arg0 << 6) + (&D_004D00F0_at__Fi);
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243B18);

void viewTweakInit__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243B78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetAmbient__Ffff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", func_00243C50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetAmbientFactor__Ff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetFov__FiPfT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewSetFov__Fiff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewComputeNormal__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewToggleSplitScreen__Fbb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetScreenDisplay__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/view", viewGetDef__Fi);

#include "m2c_macros.h"
extern volatile unsigned char D_004CEE40_wports __asm__("D_004CEE40");

void *viewGetDefByName__F10_viewports(s32 arg0)
{
  return (arg0 * 0xB0) + (&D_004CEE40_wports);
}
