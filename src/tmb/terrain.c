#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", SignOfFloat__Ff);

void terrainTestCollision__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainAddTerrainNode__FP12_terrainnode);

extern u8 numParsedNodes_8_8[4] __asm__("numParsedNodes");

void terrainInitBeforeDbLoad__Fv(void) {
    (*(s32*)numParsedNodes_8_8) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainInitialize__Fv);

extern u8 currentContext_C_11[4] __asm__("currentContext");

void terrainSetContext__FP12_terrainnode(void* arg0) {
    (*(void**)currentContext_C_11) = arg0 + 0x10;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetHAT__FP8_fvectorfP9_hdResultP14ColorUnionType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetHAT2__FP8_fvectorfP9_hdResultP14ColorUnionType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetQuickHAT2__FP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetQuickHAT__FP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", interpTerrainColor__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetMaterial__FP8_fvectorT0P10_bspresultP14ColorUnionType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetHATflat__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetHATsmoothBilinear__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetHATsmoothChaikin__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetNormal__FP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainGetLOS__FP8_fvectorT0P9_hdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainCollision__FP8_fvectorT0P9_hdResult);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainTestCell__FP8_fvectorT0P9_hdResultP15_terraincontextii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainRayTest__FP8_fvectorT0P9_hdResultP15_terraincontext);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainLineSegIntersect__FP8_fvectorT0T0T0PfT4i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainLineSegIntersect2__FP8_fvectorT0T0T0PfT4i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainLineToBoxIntersect__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainIsPointInBox2D__FP8_fvectoriiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainIsPointInBox2D__FP8_fvectorffff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainIsPointInBox__FP8_fvectorT0T0i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainIsectLinePoly__FP8_fvectorT0T0T0T0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainClipLineToBox__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawLine__FP8_fvectorT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawGSLine__FP8_fvectorT0T0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawBox__FP8_fvectorT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawNormal__FP8_fvectorT0fT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawCollisionLines__FP8_fvectorT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawCollisionLines__FP8_fvectorfiT0T0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawGridSpaceLine__FP8_fvectorT0T0P15_terraincontext);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawGridSpaceGSLine__FP8_fvectorT0T0T0P15_terraincontext);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainDrawGridSpaceBox__FP8_fvectorT0T0P15_terraincontext);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainModify__FP8_fvector);

extern u8 twave_34_93[] __asm__("twave");

s32 terrainWaveInit__Fv(void) {
    M2C_UNK* var_v1;
    s32 temp_v0;

    var_v1 = ((u8*)twave_34_93);
    do {
        M2C_FIELD(var_v1, s32* , 0) = 0;
        M2C_FIELD(var_v1, s32* , 4) = 0;
        var_v1 +=0xec;
        temp_v0 = (s32) var_v1 < (s32) (((u8*)twave_34_93) + 0x24E0);
    } while (temp_v0 != 0);
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainRestoreGrid__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainCreateWave__FP8_fvectoriffi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainShockWave__Fffi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUndulate__Fffi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUpdateSimpleSine__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUpdateLinearWave__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUpdateLinearAdaptiveWave__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUpdateShockWave__Fi);

void terrainUpdateEarthQuake__Fi(void) {
}

void terrainUpdateDeform__Fi(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/terrain", terrainTakeHit__FP8_fvectoriPv);
