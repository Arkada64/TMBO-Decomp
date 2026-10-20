#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010C788);

#include "m2c_macros.h"
s32 func_0010C8F8(void* arg0) {
    s32 var_v1;
    void* var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (M2C_FIELD(var_a0, s8* , 0x1C) != 0) {
        do {
            var_a0 += 0x20;
            var_v1 += 1;
        } while (M2C_FIELD(var_a0, s8* , 0x1C) != 0);
    }
    return var_v1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010C930);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitLevelsGroups__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiCheckGroups__FP8GroupDat);

#include "m2c_macros.h"
s32 attractiInitSuburbGroups__FP8GroupDat(void) {
    return 0x3A;
}

#include "m2c_macros.h"
s32 attractiInitJunkyardGroups__FP8GroupDat(void) {
    return 0x2E;
}

#include "m2c_macros.h"
s32 attractiInitFreewayGroups__FP8GroupDat(void) {
    return 0x3E;
}

#include "m2c_macros.h"
s32 attractiInitPrisonGroups__FP8GroupDat(void) {
    return 0x3D;
}

#include "m2c_macros.h"
s32 attractiInitRoofbossGroups__FP8GroupDat(void) {
    return 2;
}

#include "m2c_macros.h"
s32 attractiInitRooftopGroups__FP8GroupDat(void) {
    return 0x26;
}

#include "m2c_macros.h"
s32 attractiInitCityGroups__FP8GroupDat(void) {
    return 0x2D;
}

#include "m2c_macros.h"
s32 attractiInitLoopGroups__FP8GroupDat(void) {
    return 0x13;
}

#include "m2c_macros.h"
s32 attractiInitAlpineGroups__FP8GroupDat(void) {
    return 0xB;
}

#include "m2c_macros.h"
s32 attractiInitDriveInGroups__FP8GroupDat(void) {
    return 0xE;
}

#include "m2c_macros.h"
s32 attractiInitStadiumGroups__FP8GroupDat(void) {
    return 0x1D;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitDefaultGroups__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitGroupInfo__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitGroupIndirection__FPii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInsertIndirection__FPiiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010D418);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitFleeSpotInfo__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitSuburbFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitJunkyardFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010D6E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitPrisonFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", attractiInitRooftopFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010D8C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010D958);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010D9E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attracti", func_0010DA70);
