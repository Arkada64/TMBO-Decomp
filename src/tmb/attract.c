#include "common.h"
#include "m2c_macros.h"

s32 addOccupant__12AttractPointP7Vehicle(void* arg0, void* arg1) {
    void* temp_v0;

    temp_v0 = M2C_FIELD(arg0, void** , 0xC);
    M2C_FIELD(arg1, void** , 0x2014) = temp_v0;
    M2C_FIELD(arg0, void** , 0xC) = arg1;
    return (s32) temp_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", removeOccupant__12AttractPointP7Vehicle);

s32 getNumOccupants__12AttractPoint(void* arg0) {
    s32 var_v0;
    void* var_v1;

    var_v1 = M2C_FIELD(arg0, void** , 0xC);
    var_v0 = 0;
    if (var_v1 != NULL) {
        do {
            var_v1 = M2C_FIELD(var_v1, void** , 0x2014);
            var_v0 += 1;
        } while (var_v1 != NULL);
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractInitBeforeDbLoad__15AttractorPointsP12AttractPointP10StartPoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractInitAfterDbLoad__15AttractorPoints);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetClosestGroupToTestPoint__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetMaxRangeForBeadBetweenGroups__15AttractorPointsii);

int attractGetClosestPointInGroup__15AttractorPointsP8_fvectori_1C_19(void*, void*, int) __asm__("attractGetClosestPointInGroup__15AttractorPointsP8_fvectori");
s32 attractGetClosestPoint__15AttractorPointsP8_fvector(void* arg0, void* arg1) {
    return attractGetClosestPointInGroup__15AttractorPointsP8_fvectori_1C_19(arg0, arg1, -1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetClosestPointInGroup__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetClosestPointInGroupWithPathToIt__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetClosestPointThisSideOfPlane__15AttractorPointsP8_fvectoriT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractInitPoints__15AttractorPointsii);

void attractClearStartPointTakenFlags__15AttractorPoints(void* arg0) {
    s32 temp_a2;
    s32 var_a1;
    void* temp_v0;

    temp_a2 = M2C_FIELD(arg0, s32* , 0x24C);
    var_a1 = 0;
    if (temp_a2 > 0) {
        do {
            temp_v0 = (var_a1 * 4) + M2C_FIELD(arg0, s32* , 4);
            var_a1 += 1;
            M2C_FIELD(temp_v0, s16* , 2) = 0;
        } while (var_a1 < temp_a2);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetStartPoint__15AttractorPoints);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetClosestStartPoint__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetStartPointInRange__15AttractorPointsii);

M2C_UNK attractiInitGroupIndirection__FPii_30_47() __asm__("attractiInitGroupIndirection__FPii");
s32 attractiInitLevelsGroups__FP8GroupDat_30_47() __asm__("attractiInitLevelsGroups__FP8GroupDat");

void attractInitAfterDbLoad__18AttractPointGroups(void* arg0) {
    s32 temp_v0;

    temp_v0 = attractiInitLevelsGroups__FP8GroupDat_30_47();
    M2C_FIELD(arg0, s32* , 0x71A0) = temp_v0;
    attractiInitGroupIndirection__FPii_30_47(arg0 + 0x7080, temp_v0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetCenterOfGroup__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetRandomPositionInGroup__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetRandomTransPoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetSnipePoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/attract", attractGetNumGroupsFromPlayer__15AttractorPointsiP8_fvector);
