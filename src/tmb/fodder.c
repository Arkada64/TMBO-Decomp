#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00133EF0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateCheapMode__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00134088);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_001343D8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00134480);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateInputs__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_001346C0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", func_00134750);

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

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderBrakeLights__7Vehicleb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderUpdateBrakeLights__7Vehicle);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", fodderTakeHit__7VehicleP8_fvectorii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/fodder", highwayFodderSetHeadlights__7Vehicle);
