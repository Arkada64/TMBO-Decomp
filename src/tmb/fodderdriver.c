#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", init__12FodderDriverP15AttractorPoints);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", initToPoint__12FodderDriverP7Vehiclei);

int removeOccupant__12AttractPointP7Vehicle_30_6(void*, void*) __asm__("removeOccupant__12AttractPointP7Vehicle");
s32 disable__12FodderDriver(void* arg0) {
    s32 temp_v0;

    temp_v0 = removeOccupant__12AttractPointP7Vehicle_30_6(M2C_FIELD(arg0, void** , 0xC), M2C_FIELD(arg0, void** , 0));
    M2C_FIELD(arg0, s32* , 8) = 0;
    return temp_v0;
}

void setupCheapDriving__12FodderDriver(void) {
}

M2C_UNK updatePosition__12FodderDriverb_40_13() __asm__("updatePosition__12FodderDriverb");
M2C_UNK updateSteering__12FodderDriver_40_13() __asm__("updateSteering__12FodderDriver");

void updateCheapDriving__12FodderDriver(void** arg0) {
    void* temp_v1;

    updateSteering__12FodderDriver_40_13();
    updatePosition__12FodderDriverb_40_13(arg0, 0);
    temp_v1 = *arg0;
    M2C_FIELD(temp_v1, s32* , 0x17C8) = (s32) (M2C_FIELD(temp_v1, s32* , 0x17C8) + 1);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", updatePosition__12FodderDriverb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", restoreNormalDriving__12FodderDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", updateSteering__12FodderDriver);

void removeOccupant__12AttractPointP7Vehicle_5C_23(void*, void*) __asm__("removeOccupant__12AttractPointP7Vehicle");
void addOccupant__12AttractPointP7Vehicle_5C_23(void*, void*) __asm__("addOccupant__12AttractPointP7Vehicle");
void reattach__12FodderDriverP12AttractPoint(void* arg0, void* arg1) {
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0xC);
    if (temp_a0 != arg1) {
        removeOccupant__12AttractPointP7Vehicle_5C_23(temp_a0, M2C_FIELD(arg0, void** , 0));
        M2C_FIELD(arg0, void** , 0xC) = arg1;
        addOccupant__12AttractPointP7Vehicle_5C_23(arg1, M2C_FIELD(arg0, void** , 0));
    }
}

void computeLane__12FodderDriver_60_27(void*) __asm__("computeLane__12FodderDriver");
void getRandomNextPoint__12FodderDriver_60_27(void*) __asm__("getRandomNextPoint__12FodderDriver");
void mathfCopyVector__FP8_fvectorT0_60_27(void*, void*) __asm__("mathfCopyVector__FP8_fvectorT0");
void reattach__12FodderDriverP12AttractPoint_60_27(void*, void*) __asm__("reattach__12FodderDriverP12AttractPoint");

void nextSegment__12FodderDriver(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x10) = (s32) M2C_FIELD(arg0, s32* , 0x14);
    M2C_FIELD(arg0, s32* , 0x14) = (s32) M2C_FIELD(arg0, s32* , 0x18);
    mathfCopyVector__FP8_fvectorT0_60_27(arg0 + 0x50, arg0 + 0x60);
    mathfCopyVector__FP8_fvectorT0_60_27(arg0 + 0x20, arg0 + 0x30);
    getRandomNextPoint__12FodderDriver_60_27(arg0);
    computeLane__12FodderDriver_60_27(arg0);
    reattach__12FodderDriverP12AttractPoint_60_27(arg0, M2C_FIELD(arg0, s32* , 0x10));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", getRandomNextPoint__12FodderDriver);

int getClosestCarInPath__12FodderDriverPfP12AttractPoint_64_32(void*, void*, void*) __asm__("getClosestCarInPath__12FodderDriverPfP12AttractPoint");
s32 getClosestCarInPath__12FodderDriverPf(void* arg0, void* arg1) {
    s32 var_v0;

    var_v0 = getClosestCarInPath__12FodderDriverPfP12AttractPoint_64_32(arg0, arg1, M2C_FIELD(arg0, void** , 0x10));
    if (var_v0 == 0) {
        var_v0 = getClosestCarInPath__12FodderDriverPfP12AttractPoint_64_32(arg0, arg1, M2C_FIELD(arg0, void** , 0x14));
        if (var_v0 == 0) {
            var_v0 = getClosestCarInPath__12FodderDriverPfP12AttractPoint_64_32(arg0, arg1, M2C_FIELD(arg0, void** , 0x18));
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", getClosestCarInPath__12FodderDriverPfP12AttractPoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", isThreeWayIntersectionClear__12FodderDriverb);

int isIntersectionClear__12FodderDriverP12AttractPoint_1C_41(void*, void*) __asm__("isIntersectionClear__12FodderDriverP12AttractPoint");
s32 isFourWayIntersectionClear__12FodderDriver(void* arg0) {
    return isIntersectionClear__12FodderDriverP12AttractPoint_1C_41(arg0, M2C_FIELD(arg0, void** , 0x14));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", isIntersectionClear__12FodderDriverP12AttractPoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", computeLane__12FodderDriver);

void forceFullCollis__12FodderDriver(void** arg0) {
    void* temp_v1;

    temp_v1 = *arg0;
    M2C_FIELD(temp_v1, s32* , 0x1A54) = 1;
    M2C_FIELD(temp_v1, s32* , 0x17C0) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", vectorCrossUp__12FodderDriverP8_fvectorT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", getHalfLaneWidth__12FodderDriverP12AttractPoint);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", getDistFromPrev__12FodderDriverP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodderdriver", getDistFromLane__12FodderDriverP8_fvector);
