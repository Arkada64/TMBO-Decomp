#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", utilGenerateRandomNormalizedVector__FP8_fvectorf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00222D38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleInitializeMaximums__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00222DC8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleLensFlareAddToDeBounceList__FP9HierLight);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleGetLensFlareInfo__FPP17HierLensFlareListPii);

#include "m2c_macros.h"
#include "m2c_macros.h"
extern M2C_UNK D_004FB6E0_s__Fii __asm__("D_004FB6E0");

void particleSetLensFlareNumEntries__Fii(s32 arg0, s32 arg1)
{
  unsigned char *new_var2;
  M2C_UNK *new_var;
  new_var2 = &D_004FB6E0_s__Fii;
  new_var = ((arg1 & 1) * 4) + new_var2;
  *new_var = arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00222FE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00223178);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleLensFlareRender__FP6QwDatai);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00223A08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", loadColors__FPUiP13_ParticleTypePUsii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", loadMatrixIfNecessary__FPUiP13_ParticleTypeii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", linePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", linePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", spritePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00224138);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", texSpritePacketInit__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", texSpritePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00224D08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00225050);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_002250E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", stripePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", electricArcPacketBuild__FP13_ParticleTypebPUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", electricArcPacketUpdate__FiPUiP8_fvectorPA3_fT2);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00225B28);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", sprinePacketBuild__FP13_ParticleType);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00226188);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", lensFlarePacketBuild__FP13_ParticleTypei);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_002268F8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00226B08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00226C98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00226CE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00227038);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00227670);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00227818);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00227FC0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_002280C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00228610);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleMove__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleInitFx__Fif);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2D60);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2D98);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2DB0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2DF8);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2E40);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", D_004F2E88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particlePostInitFx__FP8_fvectorP13_ParticleTypef);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleCreateFx__FP8_fvectorifPA3_ff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleCreateFx__FP8_fvectorPA3_fifT0T1bf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_00229F70);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleScrapeSparks__FP8_fvectorT0T0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleGetParticle__Fi);

#include "m2c_macros.h"
#include "m2c_macros.h"
M2C_UNK plightDestroy__FP11_pointlight_22A6D8() __asm__("plightDestroy__FP11_pointlight");
extern M2C_UNK D_00631D80_22A6D8 __asm__("D_00631D80");

void func_0022A6D8(s32 arg0)
{
  s32 temp_a0;
  u8 *new_var;
  void *temp_s0;
  if (arg0 > 0)
  {
    temp_s0 = &D_00631D80_22A6D8;
    temp_s0 = (arg0 * 0x2E80) + temp_s0;
    new_var = (u8 *) temp_s0;
    temp_a0 = *((s32 *) (new_var + 0x2E6C));
    *((s16 *) (new_var + 0x2D76)) = 0;
    *((s32 *) (new_var + 0x2D70)) = (s32) ((*((s32 *) (new_var + 0x2D70))) | 4);
 do { } while (0);
    if (temp_a0 != 0)
    {
      plightDestroy__FP11_pointlight_22A6D8(temp_a0);
      *((s32 *) (new_var + 0x2E6C)) = 0;
    }
  }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022A730);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022A8E0);

void particleUpdatePickupFX__FP3_csi(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleElectricArc__FP8_fvectorT0UiUiffffiUiUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleElectricArcOnSphere__FP8_fvectorPA3_fT0fPUiiffiUiUiT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleFlatArcs__FP8_fvectorT0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022B590);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleElectricArcAddPair__FiP8_fvectorT1i);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022B8B0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022BC98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleUpdateRain__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022BE88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleRainShelter__Fii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleCreateFlyingFrags__FP8_fvectorfii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particleCreateFadingFlame__FP8_fvectoriT0f);

#include "m2c_macros.h"
void* particleGetParticle__Fi_22C7C0() __asm__("particleGetParticle__Fi");

void func_0022C7C0(s32 arg0) {
    void* temp_a0;
    void* temp_v0;

    if (arg0 != -1) {
        temp_v0 = particleGetParticle__Fi_22C7C0();
        if ((M2C_FIELD(temp_v0, s32* , 0x2DBC) == 0x48) && (M2C_FIELD(temp_v0, s32* , 0x2E70) > 0)) {
            temp_a0 = M2C_FIELD(temp_v0, void** , 0x2E7C);
            M2C_FIELD(temp_v0, s32* , 0x2DC0) = (s32) (M2C_FIELD(temp_v0, s32* , 0x2DC0) & 0xFFFFFDFF);
            if (temp_a0 != NULL) {
                M2C_FIELD(temp_a0, s32* , 0x2DC0) = (s32) (M2C_FIELD(temp_a0, s32* , 0x2DC0) & 0xFFFFFDFF);
            }
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022C830);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", particlePrepDraw__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022CA48);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/particle", func_0022CD00);
