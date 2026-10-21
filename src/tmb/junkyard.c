#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", JunkyardAddToSkyList__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", func_00150880);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", func_00150908);

#include "m2c_macros.h"
void func_0022B8B0_er__Fv() __asm__("func_0022B8B0");
extern void *D_00318808_er__Fv __asm__("D_00318808");

void JunkyardInitAfter__Fv(void)
{
  u8 *new_var;
  func_0022B8B0_er__Fv(1);
  new_var = (u8 *) D_00318808_er__Fv;
  *((s32 *) (new_var + 0x14)) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", func_00150AE8);

#include "m2c_macros.h"
extern s16 D_002C12CC_er__Fi __asm__("D_002C12CC");
extern s16 D_002C12CE_er__Fi __asm__("D_002C12CE");

void JunkyardTunnelDoorTrigger__Fi(s32 arg0) {
    if (arg0 != 0) {
        D_002C12CC_er__Fi = 1;
        return;
    }
    D_002C12CE_er__Fi = 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", JunkyardTunnelDoorUpdate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", JunkyardPizzaBoyUpdate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", CheckCarsInPizzaHat__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", junkyardAddPointsAfterJetCrash__Fv);
