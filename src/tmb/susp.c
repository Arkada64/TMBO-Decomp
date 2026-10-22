#include "common.h"
#include "m2c_macros.h"

M2C_UNK suspCheckLanding__7Vehicle_40_2() __asm__("suspCheckLanding__7Vehicle");
M2C_UNK suspCheckPitchAndRoll__7Vehicle_40_2() __asm__("suspCheckPitchAndRoll__7Vehicle");
M2C_UNK suspCheckSMC__7Vehicle_40_2() __asm__("suspCheckSMC__7Vehicle");
M2C_UNK suspCheckTireHeight__7Vehicle_40_2() __asm__("suspCheckTireHeight__7Vehicle");
M2C_UNK suspCheckTireRotation__7Vehicle_40_2() __asm__("suspCheckTireRotation__7Vehicle");

void suspUpdateSuspension__7Vehicle(s32 arg0) {
    suspCheckSMC__7Vehicle_40_2();
    suspCheckLanding__7Vehicle_40_2(arg0);
    suspCheckTireRotation__7Vehicle_40_2(arg0);
    suspCheckPitchAndRoll__7Vehicle_40_2(arg0);
    suspCheckTireHeight__7Vehicle_40_2(arg0);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckSMC__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckLanding__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckPitchAndRoll__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckTireHeight__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckTireRotation__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCreateSuspensionMat__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspSetBump__7Vehiclefi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/susp", suspCheckRandomBump__7VehicleiP8_tireDat);
