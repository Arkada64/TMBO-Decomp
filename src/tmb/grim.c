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

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimForceAirborne__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimCheckAirborneStart__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimForceLanding__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/grim", grimSetLandingSpeed__7Vehicle);
