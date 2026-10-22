#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", iLoadbarCB__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", updateBarVSyncCallback__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", getFIFOindex__FP5ViBufPv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", setD3_CHCR__FUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", setD4_CHCR__FUi);

void scTag2__FP5QWORDPvUiUi(s64* arg0, s64 arg1, s64 arg2, s64 arg3) {
    *arg0 = (arg1 << 0x20) | ((u64) (arg2 << 0x20) >> 4) | ((u64) (arg3 << 0x20) >> 0x20);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufCreate__FP5ViBufPUI80T1iP9TimeStampi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufReset__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufBeginPut__FP5ViBufPPUcPiT1T2);

M2C_UNK SignalSema_50_18() __asm__("SignalSema");
M2C_UNK WaitSema_50_18() __asm__("WaitSema");

void viBufEndPut__FP5ViBufi(void* arg0, s32 arg1) {
    WaitSema_50_18(M2C_FIELD(arg0, s32* , 0x40));
    M2C_FIELD(arg0, s32* , 0x14) = (s32) (M2C_FIELD(arg0, s32* , 0x14) + arg1);
    M2C_FIELD(arg0, s64* , 0x48) = (s64) (arg1 + M2C_FIELD(arg0, s64* , 0x48));
    SignalSema_50_18(M2C_FIELD(arg0, s32* , 0x40));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufAddDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufStopDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufRestartDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufDelete__FP5ViBuf);

M2C_UNK SignalSema_40_32() __asm__("SignalSema");
M2C_UNK WaitSema_40_32() __asm__("WaitSema");

s32 viBufIsActive__FP5ViBuf(void* arg0) {
    s32 temp_s1;

    WaitSema_40_32(M2C_FIELD(arg0, s32* , 0x40));
    temp_s1 = M2C_FIELD(arg0, s32* , 0x44);
    SignalSema_40_32(M2C_FIELD(arg0, s32* , 0x40));
    return temp_s1;
}

M2C_UNK SignalSema_4C_35() __asm__("SignalSema");
M2C_UNK WaitSema_4C_35() __asm__("WaitSema");

s32 viBufCount__FP5ViBuf(void* arg0) {
    s32 temp_s1;

    WaitSema_4C_35(M2C_FIELD(arg0, s32* , 0x40));
    temp_s1 = (M2C_FIELD(arg0, s32* , 0x10) << 0xB) + M2C_FIELD(arg0, s32* , 0x14);
    SignalSema_4C_35(M2C_FIELD(arg0, s32* , 0x40));
    return temp_s1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufFlush__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufModifyPts__FP5ViBufP9TimeStamp);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufPutTs__FP5ViBufP9TimeStamp);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/vibuf", viBufGetTs__FP5ViBufP9TimeStamp);
