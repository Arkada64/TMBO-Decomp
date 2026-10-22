#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverInit__6DriverP7VehicleP15AttractorPoints13AttractDriver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverInitTurnInfo__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverInitToPoint__6Driveri);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverUpdate__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverUpdateNextPoint__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetOffsetFromPoint__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverInitPointInfo__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverUpdatePointInfo__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetNextPoint__6Driveri);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetInitialGuessNextPoint__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetRandomNextPoint__6Driverb);

int driverGetLookAheadPos__6DriverP8_fvectori_40_33(void*, void*, int) __asm__("driverGetLookAheadPos__6DriverP8_fvectori");
int driverGetLongRangePoint__6DriverP8_fvectorii_40_33(void*, void*, int, int) __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
s32 driverGetFleeNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    return driverGetLongRangePoint__6DriverP8_fvectorii_40_33(arg0, sp, M2C_FIELD(arg0, s32* , 0x200), driverGetLookAheadPos__6DriverP8_fvectori_40_33(arg0, sp, M2C_FIELD(arg0, s32* , 0x210)));
}

int driverGetLookAheadPos__6DriverP8_fvectori_40_36(void*, void*, int) __asm__("driverGetLookAheadPos__6DriverP8_fvectori");
int driverGetLongRangePoint__6DriverP8_fvectorii_40_36(void*, void*, int, int) __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
s32 driverGetCruiseNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    return driverGetLongRangePoint__6DriverP8_fvectorii_40_36(arg0, sp, M2C_FIELD(arg0, s32* , 0x200), driverGetLookAheadPos__6DriverP8_fvectori_40_36(arg0, sp, M2C_FIELD(arg0, s32* , 0x210)));
}

int driverGetLookAheadPos__6DriverP8_fvectori_78_39(void*, void*, int) __asm__("driverGetLookAheadPos__6DriverP8_fvectori");
int driverGetLongRangePoint__6DriverP8_fvectorii_78_39(void*, void*, int, int) __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
int attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_78_39(void*, void*) __asm__("attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector");
s32 driverGetHuntNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    s32 var_v0;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0xB8);
    if (M2C_FIELD(arg0, s32* , 0x2AC) != 0) {
        var_v0 = driverGetLookAheadPos__6DriverP8_fvectori_78_39(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_78_39(temp_a0, M2C_FIELD(arg0, void** , 0x160)));
    } else {
        var_v0 = driverGetLookAheadPos__6DriverP8_fvectori_78_39(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_78_39(temp_a0, M2C_FIELD(arg0, void** , 0x164)));
    }
    return driverGetLongRangePoint__6DriverP8_fvectorii_78_39(arg0, sp, M2C_FIELD(arg0, s32* , 0x200), var_v0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetLookAheadPos__6DriverP8_fvectori);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetNextClosestPointToLookAheadVector__6DriverP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetLongRangePoint__6DriverP8_fvectorii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverCalcLookahead__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverCalcNextPointTurn__6Driver);

f32 driverCalcDistFromLine__6DriverP8_fvectorT1T1_5C_63(void*, void*, void*, void*) __asm__("driverCalcDistFromLine__6DriverP8_fvectorT1T1");

void driverCalcDistFromRoadCenter__6Driverb(void* arg0, s32 arg1) {
    s32 var_a2;
    void* var_a1;

    if (arg1 != 0) {
        var_a2 = arg0 + 0x10;
        var_a1 = arg0 + 0x20;
    } else {
        var_a1 = arg0 + 0x10;
        var_a2 = *M2C_FIELD(arg0, s32** , 0xB8) + (M2C_FIELD(arg0, s32* , 0x208) << 5);
    }
    M2C_FIELD(arg0, f32* , 0x54) = driverCalcDistFromLine__6DriverP8_fvectorT1T1_5C_63(arg0, var_a1, var_a2, M2C_FIELD(arg0, s32* , 0x174) + 0x10);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverCalcDistFromLine__6DriverP8_fvectorT1T1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetNewPointThisSideOfPlane__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverGetPointInFrontOfVehicle__6DriverP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverSetPlayerToHunt__6DriverP7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverInitTurn__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverIsVehicleDoneTurning__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverSmoothlyTurn__6Driverf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverSetDrivingMode__6Driver12_drivingMode);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverCheckDrivingLOS__6Driver);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverSetLineDriving__6Driverb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/driver", driverMustSnipe__6Driver);

int attractGetSnipePoint__15AttractorPointsi_30_95(void*, int) __asm__("attractGetSnipePoint__15AttractorPointsi");
s32 driverGetSnipePoint__6Driver(void* arg0) {
    s32 temp_v0;

    temp_v0 = attractGetSnipePoint__15AttractorPointsi_30_95(M2C_FIELD(arg0, void** , 0xB8), M2C_FIELD(arg0, s32* , 0x214));
    M2C_FIELD(arg0, s32* , 0x20C) = temp_v0;
    return temp_v0;
}
