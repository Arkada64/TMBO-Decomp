#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightFindLight__FP11_pointlight);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", func_0022E8D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/plight", plightCreate__Fv);

#include "m2c_macros.h"
void plightDestroy__FP11_pointlight(void *arg0)
{
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
 do { *((s32 *) (((u8 *) arg0) + 0x30)) = 0; } while (0);
}

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

#include "m2c_macros.h"
float plightSetRange__FP11_pointlightf_22F088(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_22F088(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_22F088(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_22F088(void) __asm__("plightCreate__Fv");
s32 func_0022F088(s32 arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_22F088();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_22F088((void* ) temp_v0, 800.0f);
        plightSetColor__FP11_pointlightfff_22F088((void* ) temp_v0, 255.0f, 255.0f, 230.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 0;
        plightSetBeamAngle__FP11_pointlightf_22F088((void* ) temp_v0, 96.0f);
        M2C_FIELD(temp_v0, s32* , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

#include "m2c_macros.h"
float plightSetRange__FP11_pointlightf_22F110(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_22F110(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_22F110(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_22F110(void) __asm__("plightCreate__Fv");
s32 func_0022F110(s32 arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_22F110();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_22F110((void* ) temp_v0, 800.0f);
        plightSetColor__FP11_pointlightfff_22F110((void* ) temp_v0, 255.0f, 255.0f, 230.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 0;
        plightSetBeamAngle__FP11_pointlightf_22F110((void* ) temp_v0, 96.0f);
        M2C_FIELD(temp_v0, s32* , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

#include "m2c_macros.h"
float plightSetRange__FP11_pointlightf_22F198(void*, float) __asm__("plightSetRange__FP11_pointlightf");
void plightSetColor__FP11_pointlightfff_22F198(void*, float, float, float) __asm__("plightSetColor__FP11_pointlightfff");
void plightSetBeamAngle__FP11_pointlightf_22F198(void*, float) __asm__("plightSetBeamAngle__FP11_pointlightf");
int plightCreate__Fv_22F198(void) __asm__("plightCreate__Fv");
s32 func_0022F198(s32 arg0) {
    s32 temp_v0;

    temp_v0 = plightCreate__Fv_22F198();
    if (temp_v0 != 0) {
        plightSetRange__FP11_pointlightf_22F198((void* ) temp_v0, 1000.0f);
        plightSetColor__FP11_pointlightfff_22F198((void* ) temp_v0, 188.0f, 141.0f, 255.0f);
        M2C_FIELD(temp_v0, s32* , 0x38) = 1;
        plightSetBeamAngle__FP11_pointlightf_22F198((void* ) temp_v0, 126.0f);
        M2C_FIELD(temp_v0, s32* , 0x3C) = arg0;
        M2C_FIELD(temp_v0, s32* , 0x34) = 0;
    }
    return temp_v0;
}

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
