#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", __8resetcom);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", __8resetcom11CREATOR_KEY);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", writeKeys__8resetcomPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", write__8resetcomPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", readKey__8resetcomPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", read__8resetcomPc);

s32 oldStyleRead__8resetcomPc(void* arg0, void* arg1) {
    return 0;
}

void init__8resetcom(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", update__8resetcom);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", forceRead__8resetcom);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", forceWrite__8resetcom);

void getFileName__8resetcomPc(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/resetcom", setFileName__8resetcomPc);

extern u8 resetPtr_8_33[4] __asm__("resetPtr");

void setReset__FP8resetcom(void* arg0) {
    (*(void**)resetPtr_8_33) = arg0;
}

extern u8 resetPtr_8_36[4] __asm__("resetPtr");

s32 getReset__Fv(void) {
    return (*(s32*)resetPtr_8_36);
}

void update__8resetcom_1C_39(void*) __asm__("update__8resetcom");
extern u8 resetPtr_1C_39[4] __asm__("resetPtr");

void resetUpdate__Fv(void) {
    if ((*(void**)resetPtr_1C_39) != NULL) {
        update__8resetcom_1C_39((*(void**)resetPtr_1C_39));
    }
}

M2C_UNK __rtti_user_3C_42() __asm__("__rtti_user");
extern u8 D_004F33C0_3C_42[] __asm__("D_004F33C0");
extern u8 __ti8resetcom_3C_42[4] __asm__("__ti8resetcom");

s32* __tf8resetcom(void) {
    if ((*(s32*)__ti8resetcom_3C_42) == 0) {
        __rtti_user_3C_42(((u8*)__ti8resetcom_3C_42), ((u8*)D_004F33C0_3C_42));
    }
    return ((u8*)__ti8resetcom_3C_42);
}
