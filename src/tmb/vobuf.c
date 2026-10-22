#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufCreate__FP5VoBufP6VoDataP5VoTagi);

void voBufDelete__FP5VoBuf(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufReset__FP5VoBuf);

s32 voBufIsFull__FP5VoBuf(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xC) == M2C_FIELD(arg0, s32* , 0x10);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufIncCount__FP5VoBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufGetData__FP5VoBuf);

s32 voBufIsEmpty__FP5VoBuf(void* arg0) {
    return M2C_FIELD(arg0, s32* , 0xC) == 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufGetTag__FP5VoBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vobuf", voBufDecCount__FP5VoBuf);
