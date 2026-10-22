#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/reset", __5reset11CREATOR_KEY);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/reset", writeKeys__5resetPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/reset", readKey__5resetPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/reset", oldStyleRead__5resetPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/reset", SetDefaultGroundHeight__7TheGamef);

M2C_UNK __rtti_si_4C_18() __asm__("__rtti_si");
M2C_UNK __tf8resetcom_4C_18() __asm__("__tf8resetcom");
extern u8 D_004FAC60_4C_18[] __asm__("D_004FAC60");
extern u8 __ti5reset_4C_18[] __asm__("__ti5reset");
extern u8 __ti8resetcom_4C_18[4] __asm__("__ti8resetcom");

s32* __tf5reset(void) {
    if ((*(s32*)__ti5reset_4C_18) == 0) {
        __tf8resetcom_4C_18();
        __rtti_si_4C_18(((u8*)__ti5reset_4C_18), ((u8*)D_004FAC60_4C_18), ((u8*)__ti8resetcom_4C_18));
    }
    return ((u8*)__ti5reset_4C_18);
}
