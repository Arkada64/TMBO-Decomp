#include "common.h"
#include "m2c_macros.h"

extern u8 bossShieldModelScale_18_0[4] __asm__("bossShieldModelScale");
extern u8 bossShieldModelSwitch_18_0[4] __asm__("bossShieldModelSwitch");
extern u8 state_18_0[4] __asm__("state");
extern u8 theBoss_18_0[4] __asm__("theBoss");
extern u8 theCLUT_18_0[4] __asm__("theCLUT");

void forceFieldInitBefore__Fv(void) {
    (*(s32*)theBoss_18_0) = 0;
    (*(s32*)theCLUT_18_0) = 0;
    (*(s32*)state_18_0) = 0;
    (*(s32*)bossShieldModelSwitch_18_0) = 0;
    (*(s32*)bossShieldModelScale_18_0) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/forceField", forceFieldCreate__FPA3_A3_fP8_fvectorifffff);

extern u8 state_8_9[4] __asm__("state");

void forceFieldSetState__Fi(s32 arg0) {
    (*(s32*)state_8_9) = arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/forceField", forceFieldTakeHit__FP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/forceField", forceFieldUpdate__Fv);
