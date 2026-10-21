#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", init__12FodderDriverP15AttractorPoints);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00134DD0);

#include "m2c_macros.h"
M2C_UNK removeOccupant__12AttractPointP7Vehicle_134F60() __asm__("removeOccupant__12AttractPointP7Vehicle");

void func_00134F60(void* arg0) {
    removeOccupant__12AttractPointP7Vehicle_134F60(M2C_FIELD_V1(arg0, s32* , 0xC), M2C_FIELD_V1(arg0, s32* , 0));
    M2C_FIELD_V1(arg0, s32* , 8) = 0;
}

void setupCheapDriving__12FodderDriver(void) {
}

#include "m2c_macros.h"
M2C_UNK updatePosition__12FodderDriverb_Driver() __asm__("updatePosition__12FodderDriverb");
M2C_UNK updateSteering__12FodderDriver_Driver() __asm__("updateSteering__12FodderDriver");

void updateCheapDriving__12FodderDriver(void** arg0) {
    void* temp_v1;

    updateSteering__12FodderDriver_Driver();
    updatePosition__12FodderDriverb_Driver(arg0, 0);
    temp_v1 = *arg0;
    M2C_FIELD(temp_v1, s32* , 0x17D8) = (s32) (M2C_FIELD(temp_v1, s32* , 0x17D8) + 1);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", updatePosition__12FodderDriverb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_001351B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", updateSteering__12FodderDriver);

#include "m2c_macros.h"
M2C_UNK addOccupant__12AttractPointP7Vehicle_tPoint() __asm__("addOccupant__12AttractPointP7Vehicle");
M2C_UNK removeOccupant__12AttractPointP7Vehicle_tPoint() __asm__("removeOccupant__12AttractPointP7Vehicle");

void reattach__12FodderDriverP12AttractPoint(void* arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0xC);
    if (temp_a0 != arg1) {
        removeOccupant__12AttractPointP7Vehicle_tPoint(temp_a0, M2C_FIELD_V1(arg0, s32* , 0));
        M2C_FIELD_V1(arg0, s32* , 0xC) = arg1;
        addOccupant__12AttractPointP7Vehicle_tPoint(arg1, M2C_FIELD_V1(arg0, s32* , 0));
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", getClosestCarInPath__12FodderDriverPf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135718);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135940);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_001359A8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135B40);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", isFourWayIntersectionClear__12FodderDriver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135D68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135E00);

#include "m2c_macros.h"
void forceFullCollis__12FodderDriver(void** arg0) {
    M2C_FIELD_V1(*arg0, s32* , 0x17D0) = 0;
    M2C_FIELD_V1(*arg0, s32* , 0x1A64) = 1;
}

#include "m2c_macros.h"
void vectorCrossUp__12FodderDriverP8_fvectorT1(s32 arg0, void *arg1, void *arg2)
{
  *((f32 *) (((u8 *) arg1) + 0)) = (f32) (*((f32 *) (((u8 *) arg2) + 4)));
  *((f32 *) (((u8 *) arg1) + 4)) = (f32) (-(*((f32 *) (((u8 *) arg2) + 0))));
  *((s32 *) (((u8 *) arg1) + 8)) = 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", getHalfLaneWidth__12FodderDriverP12AttractPoint);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodderdriver", func_00135FD8);
