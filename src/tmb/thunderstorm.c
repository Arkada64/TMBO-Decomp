#include "common.h"
#include "m2c_macros.h"

extern u8 ThunderstormHandle_C_1[4] __asm__("ThunderstormHandle");

void thunderstormInit__Fv(void) {
    (*(s32*)ThunderstormHandle_C_1) = -1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/thunderstorm", thunderstormCreate__FP8_fvectorf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/thunderstorm", thunderstormHitInit__Fi);

extern u8 LightningNumTargets_34_9[4] __asm__("LightningNumTargets");
extern u8 LightningTarget_34_9[] __asm__("LightningTarget");

s32 thunderstormHit__FP8_fvector(void* arg0) {
    s32 var_v0;
    void** temp_v1;

    var_v0 = (*(s32*)LightningNumTargets_34_9) < 0xA;
    if (var_v0 != 0) {
        var_v0 = (s32) ((u8*)LightningTarget_34_9);
        temp_v1 = ((*(s32*)LightningNumTargets_34_9) * 4) + (s32) ((u8*)LightningTarget_34_9);
        (*(s32*)LightningNumTargets_34_9) += 1;
        *temp_v1 = arg0;
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/thunderstorm", thunderstormGetCloudPos__FP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/thunderstorm", thunderstormUpdate__Fv);
