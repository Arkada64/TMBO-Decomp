#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationTransitionInto__FR11_animHandlefi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationTransitionIntoAtTime__FR11_animHandleff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationTransitionIntoAtPercent__FR11_animHandleff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationTransitionIntoAtSamePercent__FR11_animHandlef);

void animationSetChain__FR11_animHandleT0(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetHandle__FP11_animHandleUiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetCurrentTime__FR11_animHandle);

f32 animationCalculatePlayTime__FR11_animHandle(void *arg0)
{
  f32 temp_f2;
  void *new_var;
  f32 var_f0;
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

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationStart__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationStartReverse__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetToFrame__FR11_animHandlef);

f32 animationGetCurrentTime__FR11_animHandle_2C_36() __asm__("animationGetCurrentTime__FR11_animHandle");

f32 animationGetCurrentFrame__FR11_animHandle(s32* arg0) {
    f32 var_f0;

    var_f0 = -1.0f;
    if (*arg0 != 0) {
        var_f0 = animationGetCurrentTime__FR11_animHandle_2C_36();
    }
    return var_f0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetToPercent__FR11_animHandlef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetCurrentPercent__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationPause__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationResume__FR11_animHandle);

s32 animationLoop__FR11_animHandleb(void *arg0, unsigned int arg1)
{
  void *var_v0;
  var_v0 = *((void **) (((u8 *) arg0) + 0));
  if (var_v0 != 0)
  {
    var_v0 = *((void **) (((u8 *) arg0) + 4));
    *((u8 *) (((u8 *) var_v0) + 0x29)) = arg1;
  }
  return (s32) var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetSpeed__FR11_animHandlef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationResetSpeed__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetToBeginning__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetToEnd__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetDirection__FR11_animHandleb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetDirection__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetLastFrame__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationIsRunning__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetTotalRunTime__FR11_animHandlef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetTotalRunTime__FR11_animHandle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationGetFrameAtPercent__FR11_animHandlef);

s32 animationSetIterations__FR11_animHandleUs(void* arg0, u16 arg1) {
    void* var_v0;

    var_v0 = M2C_FIELD(arg0, void** , 0);
    if (var_v0 != NULL) {
        var_v0 = M2C_FIELD(arg0, void** , 4);
        M2C_FIELD(var_v0, s16* , 0x2A) = (s16) (arg1 & 0xFFFF);
    }
    return (s32) var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationCheckDirty__FP17_animCharInstanceP14_animtransform);

void animationClearDirty__FP17_animCharInstanceP14_animtransform(void* arg0, void* arg1) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;
    u8* temp_a0;
    u8* temp_a0_2;
    u8* temp_a0_3;
    u8* temp_a0_4;
    u8* temp_a0_5;
    u8* temp_a0_6;

    temp_v0 = M2C_FIELD(arg1, u16* , 0x12);
    if ((s16) temp_v0 >= 0) {
        temp_a0 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0 << 0x10) >> 0x13);
        *temp_a0 &= ~(1 << ((s16) temp_v0 & 7));
    }
    temp_v0_2 = M2C_FIELD(arg1, u16* , 0x14);
    if ((s16) temp_v0_2 >= 0) {
        temp_a0_2 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0_2 << 0x10) >> 0x13);
        *temp_a0_2 &= ~(1 << ((s16) temp_v0_2 & 7));
    }
    temp_v0_3 = M2C_FIELD(arg1, u16* , 0x16);
    if ((s16) temp_v0_3 >= 0) {
        temp_a0_3 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0_3 << 0x10) >> 0x13);
        *temp_a0_3 &= ~(1 << ((s16) temp_v0_3 & 7));
    }
    temp_v0_4 = M2C_FIELD(arg1, u16* , 0x18);
    if ((s16) temp_v0_4 >= 0) {
        temp_a0_4 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0_4 << 0x10) >> 0x13);
        *temp_a0_4 &= ~(1 << ((s16) temp_v0_4 & 7));
    }
    temp_v0_5 = M2C_FIELD(arg1, u16* , 0x1A);
    if ((s16) temp_v0_5 >= 0) {
        temp_a0_5 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0_5 << 0x10) >> 0x13);
        *temp_a0_5 &= ~(1 << ((s16) temp_v0_5 & 7));
    }
    temp_v0_6 = M2C_FIELD(arg1, u16* , 0x1C);
    if ((s16) temp_v0_6 >= 0) {
        temp_a0_6 = M2C_FIELD(arg0, s32* , 8) + ((s32) (temp_v0_6 << 0x10) >> 0x13);
        *temp_a0_6 &= ~(1 << ((s16) temp_v0_6 & 7));
    }
    M2C_FIELD(arg1, s16* , 0xC0) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", findCurrentKeyframe__FP12_animchannelffPUs);

f32 evaluateBetweenKeyframes__FP8_animkeyf(void* arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 - M2C_FIELD(arg0, f32* , 0);
    return (temp_f12 * ((temp_f12 * ((temp_f12 * M2C_FIELD(arg0, f32* , 4)) + M2C_FIELD(arg0, f32* , 8))) + M2C_FIELD(arg0, f32* , 0xC))) + M2C_FIELD(arg0, f32* , 0x10);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationChannelEvaluate__FP12_animchannelfPUsP21_animationOutputBlock);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationUpdateFromControlNode__FP16_animControlNodeP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationUpdateActiveTree__FP9_hierheadP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationProcessActiveTree__FP9_hierheadP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationAddToActiveTree__FR11_animHandle);

void animationPause__FR11_animHandle_58_98(void*) __asm__("animationPause__FR11_animHandle");
void animationRemoveFromActiveTree__FR11_animHandle(void* arg0) {
    s32* temp_a1;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void** , 0);
    if ((temp_s0 != NULL) && (temp_a1 = M2C_FIELD(temp_s0, s32** , 0x24), (temp_a1 != NULL))) {
        if (((*temp_a1 & 0x3F) == 0x21) && (M2C_FIELD(arg0, s32* , 4) == temp_a1)) {
            animationPause__FR11_animHandle_58_98(arg0);
            M2C_FIELD(temp_s0, s32** , 0x24) = NULL;
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationDoBlend__FP17_animCharInstanceiif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationUpdate__FP10_animationP17_animCharInstance);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationManager__FP8_animmgr);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetInstance__FP8_animmgri);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationRunGlobal__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationInitialize__FP10_animationP17_animCharInstancei);

extern u8 globalAnimation_34_121[] __asm__("globalAnimation");

s32 animationInitGlobal__Fv(void)
{
  u8 *new_var;
  s32 var_v1;
  s32 *var_v0;
  new_var = (u8 *) globalAnimation_34_121;
  var_v1 = 0xD;
  var_v0 = new_var + 0x34;
  do
  {
    *var_v0 = 0;
    var_v1 -= 1;
    var_v0 -= 0x1;
  }
  while (var_v1 >= 0);
  return (s32) var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", animationSetGlobal__FP9_hierheadi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/animChan", _GLOBAL_$I$blendStack);
