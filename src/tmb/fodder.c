#include "common.h"
#include "m2c_macros.h"

int vehicleInit__7Vehicle_30_0(void*) __asm__("vehicleInit__7Vehicle");
s32 highwayFodderInit__7Vehicle(void* arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, s32* , 0x580) = 3;
    temp_v0 = vehicleInit__7Vehicle_30_0(arg0);
    M2C_FIELD(arg0, s32* , 0x1A44) = 0;
    return temp_v0;
}

void vehicleSaveAndClearPadFlags__7Vehicle_164_3(void*) __asm__("vehicleSaveAndClearPadFlags__7Vehicle");
void updateCheapDriving__13HighwayDriver_164_3(void*) __asm__("updateCheapDriving__13HighwayDriver");
void updateCheapDriving__12FodderDriver_164_3(void*) __asm__("updateCheapDriving__12FodderDriver");
void setupCheapDriving__13HighwayDriver_164_3(void*) __asm__("setupCheapDriving__13HighwayDriver");
void setupCheapDriving__12FodderDriver_164_3(void*) __asm__("setupCheapDriving__12FodderDriver");
void restoreNormalDriving__13HighwayDriver_164_3(void*) __asm__("restoreNormalDriving__13HighwayDriver");
void restoreNormalDriving__12FodderDriver_164_3(void*) __asm__("restoreNormalDriving__12FodderDriver");
s32 fodderUpdateCheapMode__7Vehicle(void* arg0) {
    s32 var_a1;
    s32 var_v0;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void** , 0x2010);
    var_a1 = 0;
    if (temp_a0 != NULL) {
        if (M2C_FIELD(arg0, s32* , 0x1A54) == 0) {
            var_a1 = M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), u8* , 0xE) == 0;
        }
        var_v0 = M2C_FIELD(arg0, s32* , 0x210C);
        if (var_a1 != 0) {
            if (var_v0 == 0) {
                setupCheapDriving__12FodderDriver_164_3(temp_a0);
                M2C_FIELD(arg0, s32* , 0x210C) = 1;
            }
            vehicleSaveAndClearPadFlags__7Vehicle_164_3(arg0);
            updateCheapDriving__12FodderDriver_164_3(M2C_FIELD(arg0, void** , 0x2010));
            var_v0 = M2C_FIELD(arg0, s32* , 0x210C);
        } else if (var_v0 != 0) {
            restoreNormalDriving__12FodderDriver_164_3(temp_a0);
            goto block_22;
        }
    } else {
        if ((M2C_FIELD(arg0, s32* , 0x1A54) == 0) && ((M2C_FIELD(M2C_FIELD(arg0, void** , 0x2018), u8* , 0xE) == 0) || (M2C_FIELD(arg0, f32* , 0x208C) > 400.0f) || ((M2C_FIELD(arg0, f32* , 0x2C4) == 0.0f) && (M2C_FIELD(arg0, f32* , 0x1F8) == 0.0f) && (M2C_FIELD(arg0, f32* , 0x544) == 0.0f)))) {
            var_a1 = 1;
        }
        var_v0 = M2C_FIELD(arg0, s32* , 0x210C);
        if (var_a1 != 0) {
            if (var_v0 == 0) {
                setupCheapDriving__13HighwayDriver_164_3(M2C_FIELD(arg0, void** , 0x200C));
                M2C_FIELD(arg0, s32* , 0x210C) = 1;
            }
            vehicleSaveAndClearPadFlags__7Vehicle_164_3(arg0);
            updateCheapDriving__13HighwayDriver_164_3(M2C_FIELD(arg0, void** , 0x200C));
            var_v0 = M2C_FIELD(arg0, s32* , 0x210C);
        } else if (var_v0 != 0) {
            restoreNormalDriving__13HighwayDriver_164_3(M2C_FIELD(arg0, void** , 0x200C));
block_22:
            M2C_FIELD(arg0, s32* , 0x210C) = 0;
            var_v0 = 0;
        }
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", highwayFodderUpdateInputs__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", fodderInit__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", fodderRespawn__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateInputs__7Vehicle);

s32 fodderGetBlinkerOffState__7Vehicle_98_19(void*) __asm__("fodderGetBlinkerOffState__7Vehicle");
void hierSetSwitch__FP11_hierswitchi_98_19(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");

void fodderLeftTurnSignal__7Vehicleb(void* arg0, s32 arg1) {
    void* temp_a0;

    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2038);
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) != 0)) {
            hierSetSwitch__FP11_hierswitchi_98_19(temp_a0, 0);
            M2C_FIELD(arg0, s32* , 0x20F0) = 0;
        }
        if (M2C_FIELD(arg0, void** , 0x2034) != NULL) {
            M2C_FIELD(arg0, s32* , 0x2128) = 1;
            if (M2C_FIELD(arg0, s32* , 0x20EC) == 0) {
                M2C_FIELD(arg0, s32* , 0x20EC) = 0xF;
            }
        }
    } else {
        M2C_FIELD(arg0, s32* , 0x20EC) = 0;
        if (M2C_FIELD(arg0, void** , 0x2034) != NULL) {
            hierSetSwitch__FP11_hierswitchi_98_19(M2C_FIELD(arg0, void** , 0x2034), fodderGetBlinkerOffState__7Vehicle_98_19(arg0));
        }
    }
}

s32 fodderGetBlinkerOffState__7Vehicle_98_22(void*) __asm__("fodderGetBlinkerOffState__7Vehicle");
void hierSetSwitch__FP11_hierswitchi_98_22(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");

void fodderRightTurnSignal__7Vehicleb(void* arg0, s32 arg1) {
    void* temp_a0;

    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2034);
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) != 0)) {
            hierSetSwitch__FP11_hierswitchi_98_22(temp_a0, 0);
            M2C_FIELD(arg0, s32* , 0x20EC) = 0;
        }
        if (M2C_FIELD(arg0, void** , 0x2038) != NULL) {
            M2C_FIELD(arg0, s32* , 0x2128) = 1;
            if (M2C_FIELD(arg0, s32* , 0x20F0) == 0) {
                M2C_FIELD(arg0, s32* , 0x20F0) = 0xF;
            }
        }
    } else {
        M2C_FIELD(arg0, s32* , 0x20F0) = 0;
        if (M2C_FIELD(arg0, void** , 0x2038) != NULL) {
            hierSetSwitch__FP11_hierswitchi_98_22(M2C_FIELD(arg0, void** , 0x2038), fodderGetBlinkerOffState__7Vehicle_98_22(arg0));
        }
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateBlinkers__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", fodderGetBlinkerOffState__7Vehicle);

s32 fodderGetBlinkerOnState__7Vehicle(void* arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = M2C_FIELD(arg0, s32* , 0x2090);
    var_v1 = 1;
    if (temp_v0 != 0) {
        var_v1 = ((temp_v0 ^ 1) != 0) ? 0 : 2;
    }
    return var_v1;
}

void hierSetSwitch__FP11_hierswitchi_A4_30(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");

void fodderBrakeLights__7Vehicleb(void* arg0, s32 arg1) {
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    void* temp_a0;
    void* temp_a0_2;

    M2C_FIELD(arg0, s32* , 0x212C) = arg1;
    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2038);
        M2C_FIELD(arg0, s32* , 0x20F4) = 0x1E;
        if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) == 0)) {
            temp_v0 = M2C_FIELD(arg0, s32* , 0x2090);
            var_a1 = 3;
            if (temp_v0 != 0) {
                var_a1 = ((temp_v0 ^ 1) != 0) ? 0 : 4;
            }
            hierSetSwitch__FP11_hierswitchi_A4_30(temp_a0, var_a1);
        }
        temp_a0_2 = M2C_FIELD(arg0, void** , 0x2034);
        if ((temp_a0_2 != NULL) && (M2C_FIELD(temp_a0_2, u8* , 8) == 0)) {
            temp_v0_2 = M2C_FIELD(arg0, s32* , 0x2090);
            var_a1_2 = 3;
            if (temp_v0_2 != 0) {
                var_a1_2 = ((temp_v0_2 ^ 1) != 0) ? 0 : 4;
            }
            hierSetSwitch__FP11_hierswitchi_A4_30(temp_a0_2, var_a1_2);
        }
    }
}

void hierSetSwitch__FP11_hierswitchi_94_32(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");
void fodderUpdateBrakeLights__7Vehicle(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;
    void* temp_a0;
    void* temp_a0_2;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x20F4);
    if ((temp_v1 != 0) && (M2C_FIELD(arg0, s32* , 0x212C) == 0) && (temp_v0 = temp_v1 - M2C_FIELD(arg0, s32* , 0x20C8), M2C_FIELD(arg0, s32* , 0x20F4) = temp_v0, (temp_v0 <= 0))) {
        temp_a0 = M2C_FIELD(arg0, void** , 0x2038);
        M2C_FIELD(arg0, s32* , 0x20F4) = 0;
        if ((temp_a0 != NULL) && ((u8) M2C_FIELD(temp_a0, u8* , 8) >= 3U)) {
            hierSetSwitch__FP11_hierswitchi_94_32(temp_a0, 0);
        }
        temp_a0_2 = M2C_FIELD(arg0, void** , 0x2034);
        if (temp_a0_2 != NULL) {
            if ((u8) M2C_FIELD(temp_a0_2, u8* , 8) >= 3U) {
                hierSetSwitch__FP11_hierswitchi_94_32(temp_a0_2, 0);
            }
        }
    }
}

void vehicleTakeHit__7VehicleP8_fvectorii_184_35(void*, void*, int, int) __asm__("vehicleTakeHit__7VehicleP8_fvectorii");
void stopFodderEngine__12VehicleSound_184_35(void*) __asm__("stopFodderEngine__12VehicleSound");
int hierSetSwitch__FP11_hierswitchi_184_35(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");
void fodderRightTurnSignal__7Vehicleb_184_35(void*, unsigned char) __asm__("fodderRightTurnSignal__7Vehicleb");
void fodderLeftTurnSignal__7Vehicleb_184_35(void*, unsigned char) __asm__("fodderLeftTurnSignal__7Vehicleb");
int fodderGetBlinkerOnState__7Vehicle_184_35(void*) __asm__("fodderGetBlinkerOnState__7Vehicle");
s32 fodderTakeHit__7VehicleP8_fvectorii(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    f32 temp_f1;
    s32 var_s1;
    void* temp_a0;
    void* temp_a0_2;
    void* temp_v0;
    void* temp_v0_2;
    void* var_v0;

    var_v0 = M2C_FIELD(arg0, void** , 0x580);
    if (var_v0 != NULL) {
        vehicleTakeHit__7VehicleP8_fvectorii_184_35(arg0, arg1, arg2, arg3);
        var_v0 = M2C_FIELD(arg0, void** , 0x2028);
        if (var_v0 != NULL) {
            temp_f1 = M2C_FIELD(arg0, f32* , 0x3F4);
            var_s1 = 0;
            if (temp_f1 > 20.0f) {
                M2C_FIELD(arg0, s32* , 0x2090) = 0;
            } else if (temp_f1 > 0.0f) {
                temp_a0 = M2C_FIELD(arg0, void** , 0x202C);
                M2C_FIELD(arg0, s32* , 0x2090) = 1;
                var_s1 = 1;
                if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, u8* , 8) == 1)) {
                    hierSetSwitch__FP11_hierswitchi_184_35(temp_a0, 2);
                }
                temp_v0 = M2C_FIELD(arg0, void** , 0x2034);
                if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, u8* , 8) != 0)) {
                    var_s1 = fodderGetBlinkerOnState__7Vehicle_184_35(arg0);
                    hierSetSwitch__FP11_hierswitchi_184_35(M2C_FIELD(arg0, void** , 0x2034), var_s1);
                }
                temp_v0_2 = M2C_FIELD(arg0, void** , 0x2038);
                if ((temp_v0_2 != NULL) && (M2C_FIELD(temp_v0_2, u8* , 8) != 0)) {
                    var_s1 = fodderGetBlinkerOnState__7Vehicle_184_35(arg0);
                    hierSetSwitch__FP11_hierswitchi_184_35(M2C_FIELD(arg0, void** , 0x2038), var_s1);
                }
            } else {
                temp_a0_2 = M2C_FIELD(arg0, void** , 0x202C);
                M2C_FIELD(arg0, s32* , 0x2090) = 2;
                var_s1 = 2;
                if (temp_a0_2 != NULL) {
                    hierSetSwitch__FP11_hierswitchi_184_35(temp_a0_2, 0);
                }
                if (M2C_FIELD(arg0, void** , 0x2034) != NULL) {
                    fodderLeftTurnSignal__7Vehicleb_184_35(arg0, 0U);
                    hierSetSwitch__FP11_hierswitchi_184_35(M2C_FIELD(arg0, void** , 0x2034), 0);
                }
                if (M2C_FIELD(arg0, void** , 0x2038) != NULL) {
                    fodderRightTurnSignal__7Vehicleb_184_35(arg0, 0U);
                    hierSetSwitch__FP11_hierswitchi_184_35(M2C_FIELD(arg0, void** , 0x2038), 0);
                }
                stopFodderEngine__12VehicleSound_184_35(arg0 + 0x2B20);
            }
            var_v0 = hierSetSwitch__FP11_hierswitchi_184_35(M2C_FIELD(arg0, void** , 0x2028), var_s1);
        }
    }
    return (s32) var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/fodder", highwayFodderSetHeadlights__7Vehicle);
