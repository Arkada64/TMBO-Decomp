#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightFindLight__FP11_pointlight);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022E8D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightCreate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightDestroy__FP11_pointlight);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightParaActivate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightParaActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightParaDeactivate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightActivate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightIsActive__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightDeActivate__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetPosition__FP11_pointlightfff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022EA20);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetBeamAngle__FP11_pointlightf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022EAF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetRange__FP11_pointlightf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetColor__FP11_pointlightfff);

#include "m2c_macros.h"
extern M2C_UNK D_004B9F50_ht__Fv __asm__("D_004B9F50");

M2C_UNK* plightGetParaLight__Fv(void) {
    return &D_004B9F50_ht__Fv;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightInObject__FPA3_fP9_fvector4T1fT1P3_cs);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F050);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F088);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F110);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F198);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F228);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F390);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightUpdateParaLights__Fv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightGetParaLight__FiPfT1T1T1T1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetParaLight__Fifffff);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightSetTODParaLight__Fifffff);

void plightUpdateLights__Fv(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022F888);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightRenderObj__Fv);

#include "m2c_macros.h"
extern M2C_UNK D_004BA050_tr__Fv __asm__("D_004BA050");

M2C_UNK* plightGetPktPtr__Fv(void) {
    return &D_004BA050_tr__Fv;
}
