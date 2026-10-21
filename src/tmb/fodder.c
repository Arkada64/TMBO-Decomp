#include "common.h"

#include "m2c_macros.h"
M2C_UNK func_001D6F78_133EF0() __asm__("func_001D6F78");

void func_00133EF0(void *arg0)
{
  *((s32 *) (((u8 *) arg0) + 0x590)) = 3;
  func_001D6F78_133EF0();
 do { *((s32 *) (((u8 *) arg0) + 0x1A54)) = 0; } while (0);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateCheapMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00134088);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_001343D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00134480);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateInputs__7Vehicle);

#include "m2c_macros.h"
s32 fodderGetBlinkerOffState__7Vehicle_1346C0() __asm__("fodderGetBlinkerOffState__7Vehicle");
M2C_UNK hierSetSwitch__FP11_hierswitchi_1346C0() __asm__("hierSetSwitch__FP11_hierswitchi");

void func_001346C0(void* arg0, s32 arg1) {
    void* temp_a0;

    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2054);
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) != 0)) {
            hierSetSwitch__FP11_hierswitchi_1346C0(temp_a0, 0);
            M2C_FIELD(arg0, s32* , 0x213C) = 0;
        }
        if (M2C_FIELD(arg0, void** , 0x2050) != NULL) {
            M2C_FIELD(arg0, s32* , 0x2174) = 1;
            if (M2C_FIELD(arg0, s32* , 0x2138) == 0) {
                M2C_FIELD(arg0, s32* , 0x2138) = 0xF;
            }
        }
    } else {
        M2C_FIELD(arg0, s32* , 0x2138) = 0;
        if (M2C_FIELD(arg0, void** , 0x2050) != NULL) {
            hierSetSwitch__FP11_hierswitchi_1346C0(M2C_FIELD(arg0, void** , 0x2050), fodderGetBlinkerOffState__7Vehicle_1346C0(arg0));
        }
    }
}

#include "m2c_macros.h"
s32 fodderGetBlinkerOffState__7Vehicle_134750() __asm__("fodderGetBlinkerOffState__7Vehicle");
M2C_UNK hierSetSwitch__FP11_hierswitchi_134750() __asm__("hierSetSwitch__FP11_hierswitchi");

void func_00134750(void* arg0, s32 arg1) {
    void* temp_a0;

    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2050);
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) != 0)) {
            hierSetSwitch__FP11_hierswitchi_134750(temp_a0, 0);
            M2C_FIELD(arg0, s32* , 0x2138) = 0;
        }
        if (M2C_FIELD(arg0, void** , 0x2054) != NULL) {
            M2C_FIELD(arg0, s32* , 0x2174) = 1;
            if (M2C_FIELD(arg0, s32* , 0x213C) == 0) {
                M2C_FIELD(arg0, s32* , 0x213C) = 0xF;
            }
        }
    } else {
        M2C_FIELD(arg0, s32* , 0x213C) = 0;
        if (M2C_FIELD(arg0, void** , 0x2054) != NULL) {
            hierSetSwitch__FP11_hierswitchi_134750(M2C_FIELD(arg0, void** , 0x2054), fodderGetBlinkerOffState__7Vehicle_134750(arg0));
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateBlinkers__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderGetBlinkerOffState__7Vehicle);

#include "m2c_macros.h"
s32 fodderGetBlinkerOnState__7Vehicle(void* arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = M2C_FIELD_V1(arg0, s32* , 0x20AC);
    var_v1 = 1;
    if (temp_v0 != 0) {
        var_v1 = ((temp_v0 ^ 1) != 0) ? 0 : 2;
    }
    return var_v1;
}

#include "m2c_macros.h"
M2C_UNK hierSetSwitch__FP11_hierswitchi_hicleb() __asm__("hierSetSwitch__FP11_hierswitchi");

void fodderBrakeLights__7Vehicleb(void* arg0, s32 arg1) {
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    void* temp_a0;
    void* temp_a0_2;

    M2C_FIELD(arg0, s32* , 0x2178) = arg1;
    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2054);
        M2C_FIELD(arg0, s32* , 0x2140) = 0x1E;
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) == 0)) {
            temp_v0 = M2C_FIELD(arg0, s32* , 0x20AC);
            var_a1 = 3;
            if (temp_v0 != 0) {
                var_a1 = ((temp_v0 ^ 1) != 0) ? 0 : 4;
            }
            hierSetSwitch__FP11_hierswitchi_hicleb(temp_a0, var_a1);
        }
        temp_a0_2 = M2C_FIELD(arg0, void** , 0x2050);
        if ((temp_a0_2 != NULL) && (M2C_FIELD(temp_a0_2, u8* , 8) == 0)) {
            temp_v0_2 = M2C_FIELD(arg0, s32* , 0x20AC);
            var_a1_2 = 3;
            if (temp_v0_2 != 0) {
                var_a1_2 = ((temp_v0_2 ^ 1) != 0) ? 0 : 4;
            }
            hierSetSwitch__FP11_hierswitchi_hicleb(temp_a0_2, var_a1_2);
        }
    }
}

#include "m2c_macros.h"
M2C_UNK hierSetSwitch__FP11_hierswitchi_ehicle() __asm__("hierSetSwitch__FP11_hierswitchi");

void fodderUpdateBrakeLights__7Vehicle(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;
    void* temp_a0;
    void* temp_a0_2;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x2140);
    if ((temp_v1 != 0) && (M2C_FIELD(arg0, s32* , 0x2178) == 0) && (temp_v0 = temp_v1 - M2C_FIELD(arg0, s32* , 0x2114), M2C_FIELD(arg0, s32* , 0x2140) = temp_v0, (temp_v0 <= 0))) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2054);
        M2C_FIELD(arg0, s32* , 0x2140) = 0;
        if ((temp_a0 != NULL) && ((u8) M2C_FIELD(temp_a0, u8* , 8) >= 3U)) {
            hierSetSwitch__FP11_hierswitchi_ehicle(temp_a0, 0);
        }
        temp_a0_2 = M2C_FIELD(arg0, void** , 0x2050);
        if (temp_a0_2 != NULL) {
            if ((u8) M2C_FIELD(temp_a0_2, u8* , 8) >= 3U) {
                hierSetSwitch__FP11_hierswitchi_ehicle(temp_a0_2, 0);
            }
        }
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderTakeHit__7VehicleP8_fvectorii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", highwayFodderSetHeadlights__7Vehicle);
