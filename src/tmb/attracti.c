#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiReadPointsFromDisk__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiWritePointsToDisk__Fv);

s32 attractiCountPoints__FP12AttractPoint(void* arg0) {
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

s32 attractiCountStartPoints__FP10StartPoint(s16* arg0) {
    s16* var_a0;
    s32 var_v1;

    var_a0 = arg0;
    var_v1 = 0;
    if (*var_a0 >= 0) {
        do {
            var_a0 +=0x2;
            var_v1 += 1;
        } while (*var_a0 >= 0);
    }
    return var_v1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitLevelsGroups__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiCheckGroups__FP8GroupDat);

s32 attractiInitSuburbGroups__FP8GroupDat(void* arg0) {
    return 0x3A;
}

s32 attractiInitJunkyardGroups__FP8GroupDat(void* arg0) {
    return 0x2E;
}

s32 attractiInitFreewayGroups__FP8GroupDat(void* arg0) {
    return 0x3E;
}

s32 attractiInitPrisonGroups__FP8GroupDat(void* arg0) {
    return 0x3D;
}

s32 attractiInitRoofbossGroups__FP8GroupDat(void* arg0) {
    return 2;
}

s32 attractiInitRooftopGroups__FP8GroupDat(void* arg0) {
    return 0x26;
}

s32 attractiInitCityGroups__FP8GroupDat(void* arg0) {
    return 0x2D;
}

s32 attractiInitLoopGroups__FP8GroupDat(void* arg0) {
    return 0x13;
}

s32 attractiInitAlpineGroups__FP8GroupDat(void* arg0) {
    return 0xB;
}

s32 attractiInitDriveInGroups__FP8GroupDat(void* arg0) {
    return 0xE;
}

s32 attractiInitStadiumGroups__FP8GroupDat(void* arg0) {
    return 0x1D;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitDefaultGroups__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitGroupInfo__FP8GroupDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitGroupIndirection__FPii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInsertIndirection__FPiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitLevelsFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitFleeSpotInfo__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitSuburbFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitJunkyardFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitFreewayFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitPrisonFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitRooftopFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitCityFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitLoopFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitAlpineFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitDriveInFleeSpots__FP12_fleeSpotDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attracti", attractiInitDefaultFleeSpots__FP12_fleeSpotDat);
