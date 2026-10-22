#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", printTestListing__10MemoryCardiPA31_c);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", __10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", initialize__10MemoryCardPcT1T1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", getCardInfo__10MemoryCardPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", createUserDirectory__10MemoryCardbb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", createIconFiles__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", scrambleIconFiles__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", unscrambleIconFiles__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", createEmptyFile__10MemoryCardPCc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", doesFileExist__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", getFileAttr__10MemoryCardPc);

int getFileAttr__10MemoryCardPc_20_30(void*, void*) __asm__("getFileAttr__10MemoryCardPc");
s32 isFileClosed__10MemoryCardPc(void* arg0, void* arg1) {
    return getFileAttr__10MemoryCardPc_20_30(arg0, arg1) != 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", deleteUserDirectory__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", getUserDirectoryListing__10MemoryCardPA31_cPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", writeSaveDataSinglePlayer__10MemoryCardPiP14MemoryCardData);

void mcRead__10MemoryCardPvi_6C_36(void*, void*, int) __asm__("mcRead__10MemoryCardPvi");
M2C_UNK memset_6C_36() __asm__("memset");
M2C_UNK printf_6C_36() __asm__("printf");
extern u8 D_004F2F18_6C_36[] __asm__("D_004F2F18");

s32 readSaveDataSinglePlayer__10MemoryCardP14MemoryCardData(void* arg0, void* arg1) {
    memset_6C_36(arg1, 0, 0x10);
    mcRead__10MemoryCardPvi_6C_36(arg0, arg1, 0x10);
    printf_6C_36(((u8*)D_004F2F18_6C_36), M2C_FIELD(arg1, s32* , 0), M2C_FIELD(arg1, s32* , 4), M2C_FIELD(arg1, s32* , 0xC), M2C_FIELD(arg1, s32* , 8));
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", formatMemoryCard__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", unformatMemoryCard__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", getDirNameFromUserName__10MemoryCardPcT1);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", checkMemoryCardStatus__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", returnAvailableSpace__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", returnUserDirectoryMemoryConsumption__10MemoryCardPcPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", mcSeek__10MemoryCardii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", setSlot__10MemoryCardii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", listDirectory__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", saveFileToHost__10MemoryCardPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", makeFillerFile__10MemoryCardi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", Sjis2Ascii__FPUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", Sjis2AsciiString__FPUcPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", IsSjis__FPUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", IsAscii__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", Ascii2Sjis__FUc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", AsciiString2Sjis__FPUcPUs);

s32 SwapShort__FUs(u16 arg0) {
    u32 temp_v0;

    temp_v0 = arg0 & 0xFFFF;
    return (s32) (s16) ((temp_v0 << 8) | (temp_v0 >> 8));
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", mcClose__10MemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", mcOpen__10MemoryCardPcib);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", mcWrite__10MemoryCardPvi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/memCard", mcRead__10MemoryCardPvi);
