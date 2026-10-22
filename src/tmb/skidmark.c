#include "common.h"
#include "m2c_macros.h"

void hierCsAddToCsList__FP3_cs_FC_2(void*) __asm__("hierCsAddToCsList__FP3_cs");
void hierInitCs__FP3_cs_FC_2(void*) __asm__("hierInitCs__FP3_cs");
void ilnkListAdd__FP9_ilnklistiPi_FC_2(void*, int, void*) __asm__("ilnkListAdd__FP9_ilnklistiPi");
void ilnkListInit__FP9_ilnklistiPi_FC_2(void*, int, void*) __asm__("ilnkListInit__FP9_ilnklistiPi");
extern u8 skidBuffer_FC_2[] __asm__("skidBuffer");
extern u8 skidCS_FC_2[] __asm__("skidCS");

void skidmarkInit__9SkidMarks(void* arg0) {
    s32 var_s1;
    s32* var_s0;

    ilnkListInit__FP9_ilnklistiPi_FC_2(arg0 + 0x17700, 0x5DC, arg0 + 0x2A7B8);
    var_s1 = 0;
    ilnkListInit__FP9_ilnklistiPi_FC_2(arg0 + 0x1BD50, 0x5DC, arg0 + 0x2A7BC);
    var_s0 = arg0 + 0x29048;
    do {
        *var_s0 = 0;
        ilnkListAdd__FP9_ilnklistiPi_FC_2(arg0 + 0x1BD50, var_s1, arg0 + 0x2A7BC);
        var_s1 += 1;
        var_s0 +=0x1;
    } while (var_s1 < 0x5DC);
    M2C_FIELD(arg0, s32* , 0x203A0) = 0;
    hierInitCs__FP3_cs_FC_2(((u8*)skidCS_FC_2));
    M2C_FIELD(arg0, M2C_UNK*** , 0x203A4) = ((u8*)skidCS_FC_2);
    (*(M2C_UNK**)skidCS_FC_2) = ((u8*)skidBuffer_FC_2);
    hierCsAddToCsList__FP3_cs_FC_2(((u8*)skidCS_FC_2));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", skidmarkUpdate__9SkidMarks);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", skidmarkUpdateVehicleSkidmarks__7Vehicle);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", skidmarkAddSkidMark__7Vehiclei);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", skidmarkValidSkidMaterial__7VehicleP8_tireDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", skidmarkStretchOldSkidMark__7VehicleP8_tireDat);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/skidmark", draw__9SkidMarks);
