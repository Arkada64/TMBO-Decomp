#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", calcFrameBufferPositions__24IncognitoEntertainmentGSPQ224IncognitoEntertainmentGS11ieGsDBuffDcsssRsT5T5);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", ieGsSetDefDBuffDc__24IncognitoEntertainmentGSPQ224IncognitoEntertainmentGS11ieGsDBuffDcsP8_viewdefsss);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", ieGsPutDispEnv__24IncognitoEntertainmentGSPQ224IncognitoEntertainmentGS11ieGsDBuffDcii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", ieGsPutDrawEnv__24IncognitoEntertainmentGSPQ224IncognitoEntertainmentGS11ieGsDBuffDcii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", ieGsSwapDBuffDc__24IncognitoEntertainmentGSPQ224IncognitoEntertainmentGS11ieGsDBuffDciii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ieGs", ieGsSetHalfOffsetDc__24IncognitoEntertainmentGSiPQ224IncognitoEntertainmentGS11ieGsDBuffDcUiii);

extern u8 sg_do2Circuit_20_12[4] __asm__("sg_do2Circuit");
extern u8 sg_doHalfTex_20_12[4] __asm__("sg_doHalfTex");

s32 ieGsInitAA__24IncognitoEntertainmentGSb(void* arg0, u8 arg1) {
    if (arg0 != NULL) {
        (*(s32*)sg_doHalfTex_20_12) = 0;
        (*(s32*)sg_do2Circuit_20_12) = 1;
        return 1;
    }
    (*(s32*)sg_do2Circuit_20_12) = 0;
    (*(s32*)sg_doHalfTex_20_12) = 1;
    return 1;
}

void ieGsTweakInit__24IncognitoEntertainmentGSv(void) {
}

void tweakSetGsStuff__24IncognitoEntertainmentGSv(void) {
}

extern u8 sg_do2Circuit_8_19[4] __asm__("sg_do2Circuit");

s32 ieGs2CircuitOnOff__24IncognitoEntertainmentGSv(void* arg0) {
    return (*(s32*)sg_do2Circuit_8_19);
}

extern u8 sg_doHalfTex_8_22[4] __asm__("sg_doHalfTex");

s32 ieGsHalfTexelOffsetOnOff__24IncognitoEntertainmentGSv(void* arg0) {
    return (*(s32*)sg_doHalfTex_8_22);
}
