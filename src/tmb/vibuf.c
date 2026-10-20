#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", iLoadbarCB__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", updateBarVSyncCallback__Fi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", getFIFOindex__FP5ViBufPv);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", setD3_CHCR__FUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", setD4_CHCR__FUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", scTag2__FP5QWORDPvUiUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufCreate__FP5ViBufPUI80T1iP9TimeStampi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufReset__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", func_002489E8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", func_00248AE0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufAddDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufStopDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufRestartDMA__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", func_00249180);

#include "m2c_macros.h"
M2C_UNK SignalSema_2491D8() __asm__("SignalSema");
M2C_UNK WaitSema_2491D8() __asm__("WaitSema");

s32 func_002491D8(void* arg0) {
    s32 temp_s1;

    WaitSema_2491D8(M2C_FIELD_V1(arg0, s32* , 0x40));
    temp_s1 = M2C_FIELD_V1(arg0, s32* , 0x44);
    SignalSema_2491D8(M2C_FIELD_V1(arg0, s32* , 0x40));
    return temp_s1;
}

#include "m2c_macros.h"
M2C_UNK SignalSema_5ViBuf() __asm__("SignalSema");
M2C_UNK WaitSema_5ViBuf() __asm__("WaitSema");

s32 viBufCount__FP5ViBuf(void* arg0) {
    s32 temp_s1;

    WaitSema_5ViBuf(M2C_FIELD(arg0, s32* , 0x40));
    temp_s1 = (M2C_FIELD(arg0, s32* , 0x10) << 0xB) + M2C_FIELD(arg0, s32* , 0x14);
    SignalSema_5ViBuf(M2C_FIELD(arg0, s32* , 0x40));
    return temp_s1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufFlush__FP5ViBuf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufModifyPts__FP5ViBufP9TimeStamp);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", viBufPutTs__FP5ViBufP9TimeStamp);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/vibuf", func_00249528);
