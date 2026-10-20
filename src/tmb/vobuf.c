#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", func_00244B00);

void voBufDelete__FP5VoBuf(void) {
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", voBufReset__FP5VoBuf);

#include "m2c_macros.h"
s32 voBufIsFull__FP5VoBuf(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xC) == M2C_FIELD(arg0, s32* , 0x10);
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", voBufIncCount__FP5VoBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", voBufGetData__FP5VoBuf);

#include "m2c_macros.h"
s32 voBufIsEmpty__FP5VoBuf(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xC) == 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", func_00244C58);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vobuf", voBufDecCount__FP5VoBuf);
