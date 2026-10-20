#include "common.h"

#include "m2c_macros.h"
void addOccupant__12AttractPointP7Vehicle(void* arg0, void* arg1) {
    M2C_FIELD_V1(arg1, void** , 0x2024) = (void* ) M2C_FIELD_V1(arg0, void** , 0xC);
    M2C_FIELD_V1(arg0, void** , 0xC) = arg1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", removeOccupant__12AttractPointP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010B660);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitBeforeDbLoad__15AttractorPointsP12AttractPointP10StartPoint);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitAfterDbLoad__15AttractorPoints);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010B950);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetMaxRangeForBeadBetweenGroups__15AttractorPointsii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetClosestPoint__15AttractorPointsP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BA78);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BB10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BC10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitPoints__15AttractorPointsii);

#include "m2c_macros.h"
void func_0010BD88(void* arg0) {
    s32 temp_v1;
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32* , 0x24C) > 0) {
        do {
            temp_v1 = var_a1 * 4;
            var_a1 += 1;
            M2C_FIELD((temp_v1 + M2C_FIELD(arg0, s32* , 4)), s16* , 2) = 0;
        } while (var_a1 < M2C_FIELD(arg0, s32* , 0x24C));
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BDC0);

#include "m2c_macros.h"
s32 func_0010BE08(void* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD_V1(arg0, s32* , 0x24C);
    return (arg1 >= temp_v0) ? 0 : temp_v0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BE18);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BEF8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010BFD8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractInitAfterDbLoad__18AttractPointGroups);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetCenterOfGroup__15AttractorPointsP8_fvectori);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010C250);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetRandomTransPoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", attractGetSnipePoint__15AttractorPointsi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/attract", func_0010C458);
