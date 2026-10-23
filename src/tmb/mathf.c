#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D258);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulVec4x4__FPA3_fP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D300);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulTransVec4x4__FPA3_fP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulMatrix__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulMatrixTP__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulMatrix3x3__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMulMatrixTP3x3__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfAddMatrix3x3__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfAddMatrixTP3x3__FPA3_fT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D688);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D6E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfScaleMatrix3x3__FPA3_fT0f);

#include "m2c_macros.h"
void func_0021D798(void *arg0, void *arg1)
{
  *((f32 *) (((u8 *) arg0) + 0)) = (f32) (*((f32 *) (((u8 *) arg1) + 4)));
  *((f32 *) (((u8 *) arg0) + 4)) = (f32) (-(*((f32 *) (((u8 *) arg1) + 0))));
  *((s32 *) (((u8 *) arg0) + 8)) = 0;
}

#include "m2c_macros.h"
void func_0021D7B8(void* arg0, void* arg1) {
    M2C_FIELD(arg0, s32* , 0) = 0;
    M2C_FIELD(arg0, f32* , 4) = (f32) M2C_FIELD(arg1, f32* , 8);
    M2C_FIELD(arg0, f32* , 8) = (f32) -M2C_FIELD(arg1, f32* , 4);
}

#include "m2c_macros.h"
f32 mathfPlaneTest__FP6_planeP8_fvector(void* arg0, void* arg1) {
    return ((M2C_FIELD(arg0, f32* , 0) * M2C_FIELD(arg1, f32* , 0)) + (M2C_FIELD(arg0, f32* , 4) * M2C_FIELD(arg1, f32* , 4)) + (M2C_FIELD(arg0, f32* , 8) * M2C_FIELD(arg1, f32* , 8))) - M2C_FIELD(arg0, f32* , 0xC);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D810);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfTransposeMatrix__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfInverseMatrix__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021D9B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRotAxisToMatrix__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021DB18);

#include "m2c_macros.h"
M2C_UNK func_0021DB18_21DE90() __asm__("func_0021DB18");
M2C_UNK mathfUnitMatrixAsm__FPA3_f_21DE90() __asm__("mathfUnitMatrixAsm__FPA3_f");

void func_0021DE90(s32 arg0, M2C_UNK arg1) {
    u8 sp[0x40];
    mathfUnitMatrixAsm__FPA3_f_21DE90(sp);
    func_0021DB18_21DE90(arg0, sp, arg1);
}

#include "m2c_macros.h"
void mathfCopyVector__FP8_fvectorT0(void* arg0, void* arg1) {
    M2C_FIELD(arg0, f32* , 0) = (f32) M2C_FIELD(arg1, f32* , 0);
    M2C_FIELD(arg0, f32* , 4) = (f32) M2C_FIELD(arg1, f32* , 4);
    M2C_FIELD(arg0, f32* , 8) = (f32) M2C_FIELD(arg1, f32* , 8);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfCopyMatrixNotAligned__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfCopyMatrix__FPA3_fT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfUnitMatrixAsm__FPA3_f);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021DFC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021E028);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRotMatrixRPH__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRotMatrixPRH__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRotMatrixRPHNoTrans__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfHPtoVector__FP8_fvectorff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfViewScreenMatrix__FPA3_fT0T0fffffffffff);

void func_0021E6F8(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfDist2__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfDist3__FP8_fvectorT0);

#include "m2c_macros.h"
f32 mathfDist2Squared__FP8_fvectorT0(void *arg0, void *arg1)
{
  f32 *new_var;
  f32 temp_f0;
  f32 temp_f1;
  new_var = (f32 *) (((u8 *) arg1) + 0);
  ;
  temp_f0 = (*new_var) - (*((f32 *) (((u8 *) arg0) + 0)));
  return (temp_f0 * temp_f0) + (((*((f32 *) (((u8 *) arg1) + 4))) - (*((f32 *) (((u8 *) arg0) + 4)))) * ((*((f32 *) (((u8 *) arg1) + 4))) - (*((f32 *) (((u8 *) arg0) + 4)))));
}

#include "m2c_macros.h"
f32 mathfDist3Squared__FP8_fvectorT0(void* arg0, void* arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;

    temp_f0 = M2C_FIELD(arg1, f32* , 0) - M2C_FIELD(arg0, f32* , 0);
    temp_f2 = M2C_FIELD(arg1, f32* , 4) - M2C_FIELD(arg0, f32* , 4);
    temp_f1 = M2C_FIELD(arg1, f32* , 8) - M2C_FIELD(arg0, f32* , 8);
    return (temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f1 * temp_f1);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfManhatDist__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfManhatDist2D__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021E968);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021E9E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EA80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EAB0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRotationFromVector__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EB98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EBC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfPitchFromPointToPoint__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EC18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfMatrixFromNormal__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021ED28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021ED78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EE78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021EFF0);

#include "m2c_macros.h"
u32 func_00248028_21F098() __asm__("func_00248028");
extern M2C_UNK D_004B3C60_21F098 __asm__("D_004B3C60");

s32 func_0021F098(s32 arg0, s32 arg1)
{
  int new_var;
  new_var = 1;
  if (new_var)
  {
    if (arg0 < arg1)
    {
      return arg0 + (func_00248028_21F098(&D_004B3C60_21F098) % ((u32) ((arg1 - arg0) + new_var)));
    }
  }
  return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F100);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfRand__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F210);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfTransform3dTo2d__FiP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F420);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F688);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F6E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F758);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F778);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F7F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F878);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021F928);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfConcatQuaternions__FP8_fvectorT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021FA88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", func_0021FAF8);

#include "m2c_macros.h"
void func_0021FB70(void* arg0, void* arg1) {
    f32 temp_f0;
    f32 temp_f1;

    M2C_FIELD(arg0, f32* , 0) = (f32) (2.0f * ((M2C_FIELD(arg1, f32* , 0) * M2C_FIELD(arg1, f32* , 4)) - (M2C_FIELD(arg1, f32* , 8) * M2C_FIELD(arg1, f32* , 0xC))));
    temp_f0 = M2C_FIELD(arg1, f32* , 0);
    temp_f1 = M2C_FIELD(arg1, f32* , 8);
    M2C_FIELD(arg0, f32* , 4) = (f32) (1.0f - (2.0f * ((temp_f0 * temp_f0) + (temp_f1 * temp_f1))));
    M2C_FIELD(arg0, f32* , 8) = (f32) (2.0f * ((M2C_FIELD(arg1, f32* , 4) * M2C_FIELD(arg1, f32* , 8)) + (M2C_FIELD(arg1, f32* , 0) * M2C_FIELD(arg1, f32* , 0xC))));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/mathf", mathfQuaternionToMatrix4x4__FPA3_fP8_fvector);
