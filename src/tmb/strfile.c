#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/strfile", strFileOpen__FP7StrFilePc);

M2C_UNK sceCdStStop_30_3() __asm__("sceCdStStop");
M2C_UNK sceSifFreeIopHeap_30_3() __asm__("sceSifFreeIopHeap");

s32 strFileClose__FP7StrFile(void* arg0) {
    sceCdStStop_30_3();
    sceSifFreeIopHeap_30_3(M2C_FIELD(arg0, s32* , 0x24));
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/strfile", strFileRead__FP7StrFilePvi);
