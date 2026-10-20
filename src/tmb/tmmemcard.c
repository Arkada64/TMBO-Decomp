#include "common.h"

#include "m2c_macros.h"
M2C_UNK __10MemoryCard_ryCard() __asm__("__10MemoryCard");

void* __17TwistedMemoryCard(void* arg0) {
    __10MemoryCard_ryCard();
    M2C_FIELD(arg0, s32* , 0x78) = 1;
    M2C_FIELD(arg0, s32* , 0x7C) = 0;
    M2C_FIELD(arg0, s32* , 0x80) = 0;
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", prep__17TwistedMemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", doesTwistedDirectoryExist__17TwistedMemoryCardR9_MCStatus);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", doesTwistedSaveExist__17TwistedMemoryCardR9_MCStatus);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", doesGlobalDataExist__17TwistedMemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", func_001AF5F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", doesCoopSaveExist__17TwistedMemoryCard);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", saveGlobalData__17TwistedMemoryCardP19TmGlobalMemCardDatabb);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", func_001AFB98);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", spGetGameListing__17TwistedMemoryCardP15TmSpMemCardDataRUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", func_001AFE10);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", coopGetGameListing__17TwistedMemoryCardP17TmCoopMemCardDataRUi);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", func_001B01B8);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/tmmemcard", getChecksum__17TwistedMemoryCardPvi);
