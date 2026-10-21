#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timerInit__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timerEndOfRealTimeProcessing__Fv);

extern u8 fieldCount_8_6[4] __asm__("fieldCount");

void timerSetFieldCount__Fi(s32 arg0) {
    (*(s32*)fieldCount_8_6) = arg0;
}

s32 timerGetCurTics__Fv_20_10(void) __asm__("timerGetCurTics__Fv");
extern u8 begFrameTics_20_10[4] __asm__("begFrameTics");

void timerSetFrameStart__Fv(void) {
    (*(s32*)begFrameTics_20_10) = timerGetCurTics__Fv_20_10();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timer1Handler__FPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timerWaitForMinUpdateRate__FPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timerGetCurTics__Fv);

extern u8 lastFrameHZ_8_21[4] __asm__("lastFrameHZ");

s32 timerGetUpdateRate__Fv(void) {
    return (*(s32*)lastFrameHZ_8_21);
}

extern u8 fieldCount_8_24[4] __asm__("fieldCount");

s32 timerGetFieldCount__Fv(void) {
    return (*(s32*)fieldCount_8_24);
}

extern u8 fieldsLastFrame_8_27[4] __asm__("fieldsLastFrame");

s32 timerGetFieldsLastFrame__Fv(void) {
    return (*(s32*)fieldsLastFrame_8_27);
}

extern u8 fieldCount_10_31[4] __asm__("fieldCount");
extern u8 fieldsLastFrame_10_31[4] __asm__("fieldsLastFrame");
extern u8 oldFieldCount_10_31[4] __asm__("oldFieldCount");

void timerSetFieldsLastFrame__Fi(s32 arg0) {
    (*(s32*)fieldsLastFrame_10_31) = arg0;
    (*(s32*)fieldCount_10_31) = (*(s32*)oldFieldCount_10_31);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/timer", timerSetMinUpdateRate__Fi);

extern u8 minUpdateRate_8_36[4] __asm__("minUpdateRate");

s32 timerGetMinUpdateRate__Fv(void) {
    return (*(s32*)minUpdateRate_8_36);
}

extern u8 begFrameTics_8_39[4] __asm__("begFrameTics");

s32 timerGetFrameStart__Fv(void) {
    return (*(s32*)begFrameTics_8_39);
}

extern u8 lastFrameTics_18_43[4] __asm__("lastFrameTics");

f32 timerGetFrameTime__Fv(void) {
    return (f32) (*(s32*)lastFrameTics_18_43) / 576.0f;
}

extern u8 overloadScaleValue_8_46[4] __asm__("overloadScaleValue");

f32 timerGetOverloadScale__Fv(void) {
    return (*(f32*)overloadScaleValue_8_46);
}
