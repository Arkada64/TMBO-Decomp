#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleUpdate__7Vehicle);

void animationPause__FR11_animHandle_70_7(void*) __asm__("animationPause__FR11_animHandle");
extern u8 axleAirborne_70_7[] __asm__("axleAirborne");
extern u8 axleLanding_70_7[] __asm__("axleLanding");
extern u8 axleTurning_70_7[] __asm__("axleTurning");

void axlePauseAll__7Vehicle(void* arg0) {
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)axleTurning_70_7));
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)axleAirborne_70_7));
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)axleLanding_70_7));
}

s32 animationIsRunning__FR11_animHandle_AC_10(void *) __asm__("animationIsRunning__FR11_animHandle");
void animationStart__FR11_animHandleb_AC_10(void *, unsigned char) __asm__("animationStart__FR11_animHandleb");
void axlePauseAll__7Vehicle_AC_10(void *) __asm__("axlePauseAll__7Vehicle");
extern u8 axleAirborne_AC_10[] __asm__("axleAirborne");
extern u8 axleLanding_AC_10[] __asm__("axleLanding");
extern u8 axleState_AC_10[] __asm__("axleState");

void axleForceAirborne__7Vehicle(void *arg0)
{
  s32 *new_var;
  new_var = ((u8 *) arg0) + 0x20A4;
  if (animationIsRunning__FR11_animHandle_AC_10(((*((s32 *) new_var)) * 0xC) + ((u8 *) axleLanding_AC_10)) == 0)
  {
    if (animationIsRunning__FR11_animHandle_AC_10(((*((s32 *) (((u8 *) arg0) + 0x20A4))) * 0xC) + ((u8 *) axleAirborne_AC_10)) == 0)
    {
      new_var = (s32 *) (((u8 *) arg0) + 0x20A4);
      axlePauseAll__7Vehicle_AC_10(arg0);
      animationStart__FR11_animHandleb_AC_10(((*new_var) * 0xC) + ((u8 *) axleAirborne_AC_10), 1);
    }
    new_var = ((*((s32 *) (((u8 *) arg0) + 0x20A4))) * 4) + ((u8 *) axleState_AC_10);
    *new_var = 1;
  }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleCheckAirborneStart__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleForceLanding__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleSetLandingSpeed__7Vehicle);
