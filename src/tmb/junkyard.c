#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", JunkyardAddToSkyList__FP9_hierhead);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", func_00150880);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", func_00150908);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/junkyard", JunkyardInitAfter__Fv);

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
