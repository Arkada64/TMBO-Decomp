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

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleForceAirborne__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleCheckAirborneStart__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleForceLanding__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/axle", axleSetLandingSpeed__7Vehicle);
