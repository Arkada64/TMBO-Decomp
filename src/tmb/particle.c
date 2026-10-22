#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", utilGenerateRandomNormalizedVector__FP8_fvectorf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", utilGenerateMatrixFromZvector__FPA3_fP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleInitializeMaximums__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleParseTexture__FiP9_hierhead);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleLensFlareAddToDeBounceList__FP9HierLight);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleGetLensFlareInfo__FPP17HierLensFlareListPii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleSetLensFlareNumEntries__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleAddLensFlareToList__FP13_ParticleTypei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleLensFlareTestZbuffer__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleLensFlareRender__FP6QwDatai);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", defaultContextInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", loadColors__FPUiP13_ParticleTypePUsii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", loadMatrixIfNecessary__FPUiP13_ParticleTypeii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", linePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", linePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", spritePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", spritePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", texSpritePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", texSpritePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", kitePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", kitePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", stripePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", stripePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", electricArcPacketBuild__FP13_ParticleTypebPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", electricArcPacketUpdate__FiPUiP8_fvectorPA3_fT2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", sprinePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", sprinePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", lensFlarePacketInit__FP13_ParticleTypei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", lensFlarePacketBuild__FP13_ParticleTypei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleInit__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleInitAfter__Fv);

void mathfCopyVector__FP8_fvectorT0_70_112(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
extern u8 burningManSkelNew_70_112[] __asm__("burningManSkelNew");
extern u8 burningManSkelOld_70_112[] __asm__("burningManSkelOld");

void particleSetBurningManPoint__FP8_fvectori(void* arg0, s32 arg1) {
    s32 temp_v0;
    void* temp_s0;

    if (arg1 < 0xF) {
        temp_v0 = arg1 * 0x10;
        temp_s0 = temp_v0 + ((u8*)burningManSkelNew_70_112);
        mathfCopyVector__FP8_fvectorT0_70_112(temp_v0 + ((u8*)burningManSkelOld_70_112), temp_s0);
        mathfCopyVector__FP8_fvectorT0_70_112(temp_s0, arg0);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleEmitFromBurningMan__FP13_ParticleTypeiiffP8_fvectorT5T5);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleSpawnFrom__FP13_ParticleTypeT0P8_fvectorT2);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", utilUpdateEmitterMatrices__FP11EmitterTypeP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleEmit__FP13_ParticleTypeP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", utilScaleFlame__FP13_ParticleTypef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", emitterMove__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleMove__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleInitFx__Fif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particlePostInitFx__FP8_fvectorP13_ParticleTypef);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleCreateFx__FP8_fvectorifPA3_ff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleCreateFx__FP8_fvectorPA3_fifT0T1bf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleCreateModeledFx__FP8_fvectorP19HierParticleEmitter);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleScrapeSparks__FP8_fvectorT0T0);

extern u8 fx_24_137[] __asm__("fx");

s32 particleGetParticle__Fi(s32 arg0) {
    if (arg0 <= 0) {
        return 0;
    }
    return (s32) ((arg0 * 0x2E80) + ((u8*)fx_24_137));
}

void plightDestroy__FP11_pointlight_58_140(void*) __asm__("plightDestroy__FP11_pointlight");
extern u8 fx_58_140[] __asm__("fx");

void particleKillFx__Fi(s32 arg0) {
    void* temp_a0;
    void* temp_s0;

    if (arg0 > 0) {
        temp_s0 = (arg0 * 0x2E80) + ((u8*)fx_58_140);
        temp_a0 = M2C_FIELD(temp_s0, void** , 0x2E6C);
        M2C_FIELD(temp_s0, s16* , 0x2D76) = 0;
        M2C_FIELD(temp_s0, s32* , 0x2D70) = (s32) (M2C_FIELD(temp_s0, s32* , 0x2D70) | 4);
        if (temp_a0 != NULL) {
            plightDestroy__FP11_pointlight_58_140(temp_a0);
            M2C_FIELD(temp_s0, void** , 0x2E6C) = NULL;
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleKillAllFx__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleInitForReplay__Fv);

void particleUpdatePickupFX__FP3_csi(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleElectricArc__FP8_fvectorT0UiUiffffiUiUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleElectricArcOnSphere__FP8_fvectorPA3_fT0fPUiiffiUiUiT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleFlatArcs__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleElectricArcPairs__Fffi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleElectricArcAddPair__FiP8_fvectorT1i);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particlePrecipitationCreate__Fb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleRainSetPrecipitation__Ff);

int mathfAddVector__FP8_fvectorT0T0_130_163(void*, void*, void*) __asm__("mathfAddVector__FP8_fvectorT0T0");
extern u8 modRainPos_130_163[] __asm__("modRainPos");
extern u8 rainVel_130_163[4] __asm__("rainVel");
extern u8 smokeWind_130_163[] __asm__("smokeWind");

s32 particleUpdateRain__Fv(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 var_f1;
    f32 var_f3;
    f32 var_f4;
    s32 temp_v0;

    M2C_FIELD((*(void**)rainVel_130_163), f32* , 0) = (f32) M2C_FIELD(((u8*)smokeWind_130_163), f32* , 0);
    M2C_FIELD((*(void**)rainVel_130_163), f32* , 4) = (f32) M2C_FIELD(((u8*)smokeWind_130_163), f32* , 4);
    temp_v0 = mathfAddVector__FP8_fvectorT0T0_130_163(((u8*)modRainPos_130_163), ((u8*)modRainPos_130_163), (*(void**)rainVel_130_163));
    var_f4 = M2C_FIELD(((u8*)modRainPos_130_163), f32* , 0);
    if (var_f4 < 0.0f) {
        temp_f0 = var_f4 + 80.0f;
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 0) = temp_f0;
        var_f4 = temp_f0;
    }
    var_f3 = M2C_FIELD(((u8*)modRainPos_130_163), f32* , 4);
    if (var_f3 < 0.0f) {
        temp_f0_2 = var_f3 + 80.0f;
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 4) = temp_f0_2;
        var_f3 = temp_f0_2;
    }
    var_f1 = M2C_FIELD(((u8*)modRainPos_130_163), f32* , 8);
    if (var_f1 < 0.0f) {
        temp_f0_3 = var_f1 + 80.0f;
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 8) = temp_f0_3;
        var_f1 = temp_f0_3;
    }
    if (var_f4 >= 80.0f) {
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 0) = (f32) (var_f4 - 80.0f);
    }
    if (var_f3 >= 80.0f) {
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 4) = (f32) (var_f3 - 80.0f);
    }
    if (var_f1 >= 80.0f) {
        M2C_FIELD(((u8*)modRainPos_130_163), f32* , 8) = (f32) (var_f1 - 80.0f);
    }
    return temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleUpdateRainViewport__FiP3_csb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleRainShelter__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleCreateFlyingFrags__FP8_fvectorfii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleCreateFadingFlame__FP8_fvectoriT0f);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleTruncateFlameThrower__FiP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particlePrepDraw__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleClearBuffers__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/particle", particleDraw__Fi);
