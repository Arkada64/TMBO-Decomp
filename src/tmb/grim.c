#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimUpdate__7Vehicle);

void animationPause__FR11_animHandle_70_7(void*) __asm__("animationPause__FR11_animHandle");
extern u8 grimAirborne_70_7[] __asm__("grimAirborne");
extern u8 grimHandlebar_70_7[] __asm__("grimHandlebar");
extern u8 grimLanding_70_7[] __asm__("grimLanding");

void grimPauseAll__7Vehicle(void* arg0) {
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)grimHandlebar_70_7));
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)grimAirborne_70_7));
    animationPause__FR11_animHandle_70_7((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)grimLanding_70_7));
}

s32 animationIsRunning__FR11_animHandle_AC_10(void *) __asm__("animationIsRunning__FR11_animHandle");
void animationStart__FR11_animHandleb_AC_10(void *, unsigned char) __asm__("animationStart__FR11_animHandleb");
void grimPauseAll__7Vehicle_AC_10(void *) __asm__("grimPauseAll__7Vehicle");
extern u8 grimAirborne_AC_10[] __asm__("grimAirborne");
extern u8 grimLanding_AC_10[] __asm__("grimLanding");
extern u8 grimState_AC_10[] __asm__("grimState");

void grimForceAirborne__7Vehicle(void *arg0)
{
  s32 *new_var;
  if (animationIsRunning__FR11_animHandle_AC_10(((*((s32 *) (((u8 *) arg0) + 0x20A4))) * 0xC) + ((u8 *) grimLanding_AC_10)) == 0)
  {
    if (animationIsRunning__FR11_animHandle_AC_10(((*((s32 *) (((u8 *) arg0) + 0x20A4))) * 0xC) + ((u8 *) grimAirborne_AC_10)) == 0)
    {
      grimPauseAll__7Vehicle_AC_10(arg0);
      new_var = (s32 *) (((u8 *) arg0) + 0x20A4);
      animationStart__FR11_animHandleb_AC_10(((*new_var) * 0xC) + ((u8 *) grimAirborne_AC_10), 1);
    }
    new_var = ((*((s32 *) (((u8 *) arg0) + 0x20A4))) * 4) + ((u8 *) grimState_AC_10);
    *new_var = 1;
  }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimCheckAirborneStart__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimForceLanding__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimSetLandingSpeed__7Vehicle);
