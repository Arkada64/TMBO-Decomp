#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierGetLastGSCtx__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00211D80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00212430);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00212810);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierObjectNode__FP11_hierobjectP14_hierstackinfoP10_hierstackPP9_hierheadi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierTranslateNode__FP14_hiertranslateP14_hierstackinfoP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierRotateNode__FP11_hierrotateP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00212E80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCharInstNode__FP17_animCharInstanceP10_hierstackPP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierTerrainNode__FP12_terrainnodePP9_hierheadP10_hierstack);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierBurnManKludge);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213218);

#include "m2c_macros.h"
M2C_UNK func_0022A6D8_ocator() __asm__("func_0022A6D8");
extern M2C_UNK D_004AD3F0_ocator __asm__("D_004AD3F0");

void hierKillLocator(s32 arg0, s32* arg1) {
    s32** temp_s0;

    temp_s0 = (arg0 * 0x1) + &D_004AD3F0_ocator;
    func_0022A6D8_ocator(*temp_s0);
    *temp_s0 = arg1;
    *arg1 = (*arg1 & 0x3FFFF) | (arg0 << 0x12);
}

#include "m2c_macros.h"
extern M2C_UNK D_004AD3F0___FUii __asm__("D_004AD3F0");

void hierRegisterLocator__FUii(s32 arg0, s32 arg1) {
    u32 temp_v1;

    temp_v1 = arg0 - 0x1D4C;
    if (temp_v1 < 0x20U) {
        *((temp_v1 * 0x1) + &D_004AD3F0___FUii) = arg1;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_002134D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierParticleNode);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierScaleNode);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCheckVifComplete__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierWaitForVif1__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", vu0HierRotateAsm__FPA3_A3_fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", vu0FovTestResAsm__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213928);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierPushAsm__FPP9_hierheadiUiUiPUifP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierPop__FP14_hierstackinfoPP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213A30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierLod__FP8_hierlodfPP9_hierheadP10_hierstackP14_hierstackinfo);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCtrlNode);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213D78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213E48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierDisableFov__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213F80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00213FF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCsAddToCsList__FP3_cs);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214088);

#include "m2c_macros.h"
void hierSetCsEpNode__FP3_csP9_hierhead(s32* arg0, s32 arg1) {
    *arg0 = arg1;
}

#include "m2c_macros.h"
void hierCsPtLightMe__FP3_csi(void* arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8* , 0xF) = 1;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCsPoolInit__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierCsGetList__Fv);

#include "m2c_macros.h"
void hierSetCsDrawMe__FP3_csUc(void *arg0, s32 arg1)
{
  int new_var;
  new_var = arg1 & 0xFF;
  if (arg0 != 0)
  {
    *((s8 *) (((u8 *) arg0) + 0xC)) = (s8) new_var;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierSetTraversalCallback__FPFP3_csP11_hierobjectPA3_fP8_fvector_v);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierInitCs__FP3_cs);

#include "m2c_macros.h"
void hierSetSwitch__FP11_hierswitchi(void* arg0, s32 arg1) {
    if ((arg0 != NULL) && ((M2C_FIELD(arg0, s32* , 0) & 0x3F) == 6) && (arg1 < (s32) M2C_FIELD(arg0, u8* , 0xB))) {
        M2C_FIELD(arg0, s8* , 8) = (s8) arg1;
    }
}

#include "m2c_macros.h"
extern M2C_UNK D_004B12F0_ectori __asm__("D_004B12F0");

void hierSetCameraVehiclePos__FP8_fvectori(void *arg0, s32 arg1)
{
  void *temp_a1;
  u8 *new_var2;
  M2C_UNK *new_var3;
  u8 *new_var;
  f32 *new_var4;
  f32 *new_var5;
  new_var3 = &D_004B12F0_ectori;
  new_var = (u8 *) arg0;
  temp_a1 = new_var3;
  temp_a1 = (arg1 * 0x10) + temp_a1;
  *((f32 *) (((u8 *) temp_a1) + 0)) = (f32) (*((f32 *) (new_var + 0)));
  new_var2 = ((u8 *) temp_a1) + 8;
  new_var5 = (f32 *) (((u8 *) temp_a1) + 4);
  new_var4 = (f32 *) (new_var + 4);
  *new_var5 = (f32) (*new_var4);
  *((f32 *) new_var2) = (f32) (*((f32 *) (new_var + 8)));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierSetKlod__Ff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierGetKlod__Fv);

#include "m2c_macros.h"
extern M2C_UNK D_00566480_dr__Fv __asm__("D_00566480");

M2C_UNK* hierGetBigBufAddr__Fv(void) {
    return &D_00566480_dr__Fv;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214290);

#include "m2c_macros.h"
s32 func_00214298(s32 arg0)
{
  int new_var;
  s32 var_a1;
  var_a1 = 0;
  if (((u32) (arg0 + 0xFF680000)) <= 0x0128566FU)
  {
    var_a1 = (new_var = arg0 & 3) == 0;
  }
  return var_a1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_002142C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214300);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214338);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214348);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214360);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214370);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", vu0GetNearRangeAsm__FP6QwData);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", hierFlushObjQ__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214430);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/hierc", func_00214470);
