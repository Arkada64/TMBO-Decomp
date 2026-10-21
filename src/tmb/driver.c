#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_0012E2E0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_0012E410);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverInitToPoint__6Driveri);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_0012E798);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverUpdateNextPoint__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetOffsetFromPoint__6Driver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverInitPointInfo__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverUpdatePointInfo__6Driver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetNextPoint__6Driveri);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetInitialGuessNextPoint__6Driver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetRandomNextPoint__6Driverb);

#include "m2c_macros.h"
M2C_UNK driverGetLongRangePoint__6DriverP8_fvectorii_Driver() __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
s32 driverGetLookAheadPos__6DriverP8_fvectori_Driver() __asm__("driverGetLookAheadPos__6DriverP8_fvectori");

void driverGetFleeNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    driverGetLongRangePoint__6DriverP8_fvectorii_Driver(arg0, sp, M2C_FIELD(arg0, s32* , 0x200), driverGetLookAheadPos__6DriverP8_fvectori_Driver(arg0, sp, M2C_FIELD(arg0, s32* , 0x210)));
}

#include "m2c_macros.h"
M2C_UNK driverGetLongRangePoint__6DriverP8_fvectorii_Driver() __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
s32 driverGetLookAheadPos__6DriverP8_fvectori_Driver() __asm__("driverGetLookAheadPos__6DriverP8_fvectori");

void driverGetCruiseNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    driverGetLongRangePoint__6DriverP8_fvectorii_Driver(arg0, sp, M2C_FIELD(arg0, s32* , 0x200), driverGetLookAheadPos__6DriverP8_fvectori_Driver(arg0, sp, M2C_FIELD(arg0, s32* , 0x210)));
}

#include "m2c_macros.h"
s32 attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_Driver() __asm__("attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector");
M2C_UNK driverGetLongRangePoint__6DriverP8_fvectorii_Driver() __asm__("driverGetLongRangePoint__6DriverP8_fvectorii");
s32 driverGetLookAheadPos__6DriverP8_fvectori_Driver() __asm__("driverGetLookAheadPos__6DriverP8_fvectori");

void driverGetHuntNextPoint__6Driver(void* arg0) {
    u8 sp[0x10];
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD_V1(arg0, s32* , 0xB8);
    if (M2C_FIELD_V1(arg0, s32* , 0x2AC) != 0) {
        var_v0 = driverGetLookAheadPos__6DriverP8_fvectori_Driver(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_Driver(temp_a0, M2C_FIELD_V1(arg0, s32* , 0x160)));
    } else {
        var_v0 = driverGetLookAheadPos__6DriverP8_fvectori_Driver(arg0, sp, attractGetGroupTestPointIsIn__15AttractorPointsP8_fvector_Driver(temp_a0, M2C_FIELD_V1(arg0, s32* , 0x164)));
    }
    driverGetLongRangePoint__6DriverP8_fvectorii_Driver(arg0, sp, M2C_FIELD_V1(arg0, s32* , 0x200), var_v0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetLookAheadPos__6DriverP8_fvectori);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_0012F8D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetNextClosestPointToLookAheadPos__6DriverP8_fvectorii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetLongRangePoint__6DriverP8_fvectorii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverCalcLookahead__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverCalcNextPointTurn__6Driver);

#include "m2c_macros.h"
f32 driverCalcDistFromLine__6DriverP8_fvectorT1T1_130598() __asm__("driverCalcDistFromLine__6DriverP8_fvectorT1T1");

void func_00130598(void* arg0, s32 arg1) {
    s32 var_a2;
    void* var_a1;

    if (arg1 != 0) {
        var_a2 = arg0 + 0x10;
        var_a1 = arg0 + 0x20;
    } else {
        var_a1 = arg0 + 0x10;
        var_a2 = *M2C_FIELD(arg0, s32** , 0xB8) + (M2C_FIELD(arg0, s32* , 0x208) << 5);
    }
    M2C_FIELD(arg0, f32* , 0x54) = driverCalcDistFromLine__6DriverP8_fvectorT1T1_130598(arg0, var_a1, var_a2, M2C_FIELD(arg0, s32* , 0x174) + 0x10);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverCalcDistFromLine__6DriverP8_fvectorT1T1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetNewPointThisSideOfPlane__6DriverP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetNewPointInFrontOfVehicle__6DriverP7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverGetPointInFrontOfVehicle__6DriverP7Vehicle);

#include "m2c_macros.h"
void func_00130C00(void* arg0, void* arg1) {
    s32 temp_v1;

    M2C_FIELD_V1(arg0, void** , 0xB4) = arg1;
    temp_v1 = M2C_FIELD_V1(arg1, s32* , 0x2028);
    M2C_FIELD_V1(arg0, s32* , 0x160) = (s32) (arg1 + 0x1F30);
    M2C_FIELD_V1(arg0, s32* , 0x170) = temp_v1;
    M2C_FIELD_V1(arg0, s32* , 0x164) = (s32) (temp_v1 + 0x10);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverInitTurn__6Driver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_00130C50);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_00130D68);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", func_00130E88);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverCheckDrivingLOS__6Driver);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverSetLineDriving__6Driverb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/driver", driverMustSnipe__6Driver);

#include "m2c_macros.h"
s32 attractGetSnipePoint__15AttractorPointsi_Driver() __asm__("attractGetSnipePoint__15AttractorPointsi");

void driverGetSnipePoint__6Driver(void* arg0) {
    M2C_FIELD_V1(arg0, s32* , 0x20C) = attractGetSnipePoint__15AttractorPointsi_Driver(M2C_FIELD_V1(arg0, s32* , 0xB8), M2C_FIELD_V1(arg0, s32* , 0x214));
}
