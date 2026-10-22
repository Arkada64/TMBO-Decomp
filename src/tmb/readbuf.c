#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/readbuf", readBufCreate__FP7ReadBuf);

void readBufDelete__FP7ReadBuf(void) {
}

s32 readBufBeginPut__FP7ReadBufPPUc(void* arg0, void** arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32* , 0x50008) - M2C_FIELD(arg0, s32* , 0x50004);
    if (temp_v1 != 0) {
        *arg1 = arg0 + M2C_FIELD(arg0, s32* , 0x50000);
    }
    return temp_v1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/readbuf", readBufEndPut__FP7ReadBufi);

s32 readBufBeginGet__FP7ReadBufPPUc(void* arg0, void** arg1) {
    s32 temp_a0;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, s32* , 0x50004);
    if (temp_a2 != 0) {
        temp_a0 = M2C_FIELD(arg0, s32* , 0x50008);
        *arg1 = arg0 + ((s32) ((M2C_FIELD(arg0, s32* , 0x50000) - temp_a2) + temp_a0) % temp_a0);
    }
    return temp_a2;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/readbuf", readBufEndGet__FP7ReadBufi);
