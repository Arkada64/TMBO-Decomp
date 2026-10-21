#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationTransitionInto__FR11_animHandlefi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FB808);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FB998);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FBB18);

void animationSetChain__FR11_animHandleT0(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FBCF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationGetCurrentTime__FR11_animHandle);

#include "m2c_macros.h"
f32 animationCalculatePlayTime__FR11_animHandle(void *arg0)
{
  f32 temp_f2;
  f32 var_f0;
  void *new_var;
  void *temp_v0;
  void *temp_v0_2;
  var_f0 = 0.0f;
  if ((*((s32 *) (((u8 *) arg0) + 0))) != 0)
  {
    temp_v0 = *((void **) (((u8 *) arg0) + 4));
    new_var = *((void **) (((u8 *) temp_v0) + 4));
    temp_f2 = *((f32 *) (((u8 *) temp_v0) + 0x1C));
    temp_v0_2 = new_var;
    if (temp_f2 != 0.0f)
    {
      var_f0 = ((*((f32 *) (((u8 *) temp_v0_2) + 8))) - (*((f32 *) (((u8 *) temp_v0_2) + 4)))) / fabsf(temp_f2);
    }
  }
  return var_f0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationStart__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationStartReverse__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationSetToFrame__FR11_animHandlef);

#include "m2c_macros.h"
f32 animationGetCurrentTime__FR11_animHandle_1FC0A8() __asm__("animationGetCurrentTime__FR11_animHandle");

f32 func_001FC0A8(s32* arg0) {
    f32 var_f0;

    var_f0 = -1.0f;
    if (*arg0 != 0) {
        var_f0 = animationGetCurrentTime__FR11_animHandle_1FC0A8();
    }
    return var_f0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationSetToPercent__FR11_animHandlef);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FC170);

#include "m2c_macros.h"
f32 animationCalculatePlayTime__FR11_animHandle_Handle() __asm__("animationCalculatePlayTime__FR11_animHandle");
s32 timerGetFieldCount__Fv_Handle() __asm__("timerGetFieldCount__Fv");

void animationPause__FR11_animHandle(void* arg0) {
    s32 temp_v0;
    void* temp_v1;
    void* temp_v1_2;

    if ((M2C_FIELD(arg0, s32* , 0) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void** , 4), u8* , 0x28) != 0)) {
        temp_v0 = timerGetFieldCount__Fv_Handle();
        temp_v1 = M2C_FIELD(arg0, void** , 4);
        M2C_FIELD(temp_v1, s32* , 0x14) = (s32) (temp_v0 - M2C_FIELD(temp_v1, s32* , 0x14));
        M2C_FIELD(M2C_FIELD(arg0, void** , 4), f32* , 0x20) = animationCalculatePlayTime__FR11_animHandle_Handle(arg0);
        temp_v1_2 = M2C_FIELD(arg0, void** , 4);
        M2C_FIELD(temp_v1_2, s32* , 0x24) = (s32) (temp_v0 - M2C_FIELD(temp_v1_2, s32* , 0x14));
        M2C_FIELD(M2C_FIELD(arg0, void** , 4), u8* , 0x28) = 0U;
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationResume__FR11_animHandle);

#include "m2c_macros.h"
void animationLoop__FR11_animHandleb(void *arg0, unsigned int arg1)
{
  void **new_var;
  if ((*((s32 *) (((u8 *) arg0) + 0))) != 0)
  {
    *((s8 *) (((u8 *) (*(new_var = &(*((void **) (((u8 *) arg0) + 4)))))) + 0x29)) = arg1;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FC328);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationResetSpeed__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationSetToBeginning__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationSetToEnd__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FC558);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationGetDirection__FR11_animHandle);

#include "m2c_macros.h"
f32 func_001FC688(void *arg0)
{
  void *temp_v1;
  u8 *new_var;
  temp_v1 = *((void **) (((u8 *) arg0) + 0));
  if (temp_v1 != 0)
  {
    new_var = (u8 *) ((*((s32 *) (((u8 *) temp_v1) + 0x20))) + ((*((s16 *) (((u8 *) arg0) + 8))) * 4));
    return *((f32 *) (((u8 *) (*((void **) (new_var + 8)))) + 8));
  }
  return 0.0f;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationIsRunning__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationSetTotalRunTime__FR11_animHandlef);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationGetTotalRunTime__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationGetFrameAtPercent__FR11_animHandlef);

#include "m2c_macros.h"
#include "m2c_macros.h"
void animationSetIterations__FR11_animHandleUs(void *arg0, s32 arg1)
{
  int new_var;
  new_var = arg1 & 0xFFFF;
  if ((*((s32 *) (((u8 *) arg0) + 0))) != 0)
  {
    *((s16 *) (((u8 *) (*((void **) (((u8 *) arg0) + 4)))) + 0x2A)) = (s16) new_var;
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationCheckDirty__FP17_animCharInstanceP14_animtransform);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationClearDirty__FP17_animCharInstanceP14_animtransform);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FCA80);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", evaluateBetweenKeyframes__FP8_animkeyf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FCBD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationUpdateFromControlNode__FP16_animControlNodeP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationUpdateActiveTree__FP9_hierheadP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FD180);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationAddToActiveTree__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FD878);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FD8D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FDB08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationManager__FP8_animmgr);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FDD48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", animationRunGlobal__Fv);

#include "m2c_macros.h"
extern M2C_UNK D_00465EA0_1FDE10 __asm__("D_00465EA0");

void func_001FDE10(s32 arg0, s32 arg1) {
    *((arg1 * 0x1) + &D_00465EA0_1FDE10) = arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FDE28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FDF30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/animChan", func_001FDF68);
