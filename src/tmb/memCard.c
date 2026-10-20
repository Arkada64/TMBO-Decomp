#include "common.h"

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2C28);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2C40);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2C70);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2CA0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2CB0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2CF0);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2D20);

INCLUDE_RODATA("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", D_004F2D30);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", __10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", initialize__10MemoryCardPcT1T1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", getCardInfo__10MemoryCardPi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", createUserDirectory__10MemoryCardbb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", createIconFiles__10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", scrambleIconFiles__10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00220970);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", createEmptyFile__10MemoryCardPCc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", doesFileExist__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", getFileAttr__10MemoryCardPc);

#include "m2c_macros.h"
s32 getFileAttr__10MemoryCardPc_220CE0() __asm__("getFileAttr__10MemoryCardPc");

s32 func_00220CE0(void) {
    return getFileAttr__10MemoryCardPc_220CE0() != 0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", deleteUserDirectory__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", getUserDirectoryListing__10MemoryCardPA31_cPi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00220F98);

#include "m2c_macros.h"
M2C_UNK func_00221E38_220FC0() __asm__("func_00221E38");
M2C_UNK memset_220FC0() __asm__("memset");

s32 func_00220FC0(s32 arg0, M2C_UNK arg1) {
    memset_220FC0(arg1, 0, 0x10);
    func_00221E38_220FC0(arg0, arg1, 0x10);
    return 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", formatMemoryCard__10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", unformatMemoryCard__10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", getDirNameFromUserName__10MemoryCardPcT1);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", checkMemoryCardStatus__10MemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221408);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221470);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_002215C8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", setSlot__10MemoryCardii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221648);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", saveFileToHost__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_002218D0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", Sjis2Ascii__FPUc);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221B98);

#include "m2c_macros.h"
s32 func_00221C40(u8* arg0) {
    u8 temp_v1;

    temp_v1 = *arg0;
    if (((u32) ((temp_v1 + 0x7F) & 0xFF) < 0x1FU) || ((u32) ((temp_v1 + 0x20) & 0xFF) < 0x10U)) {
        return 1;
    }
    return (temp_v1 < 0x81U) ? 0 : -1;
}

#include "m2c_macros.h"
#include "m2c_macros.h"
s32 IsAscii__FPc(u8 *arg0)
{
  unsigned long new_var;
  new_var = (u64) (*arg0);
  return (new_var >> 7) ^ 1;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221C90);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", AsciiString2Sjis__FPUcPUs);

#include "m2c_macros.h"
s16 SwapShort__FUs(s32 arg0) {
    u32 temp_v0;

    temp_v0 = arg0 & 0xFFFF;
    return (s16) ((temp_v0 << 8) | (temp_v0 >> 8));
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221E38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221EA0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", func_00221F08);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/memCard", mcClose__10MemoryCard);
