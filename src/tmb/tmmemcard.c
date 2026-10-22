#include "common.h"
#include "m2c_macros.h"

s32 __17TwistedMemoryCard(void* arg0) {
    __10MemoryCard(arg0);
    M2C_FIELD(arg0, s32* , 0x6C) = 1;
    M2C_FIELD(arg0, s32* , 0x70) = 0;
    M2C_FIELD(arg0, s32* , 0x74) = 0;
    return (s32) arg0;
}

void initialize__10MemoryCardPcT1T1_44_3(void*, void*, void*, void*) __asm__("initialize__10MemoryCardPcT1T1");
extern u8 D_004EAE30_44_3[] __asm__("D_004EAE30");
extern u8 D_004EAE40_44_3[] __asm__("D_004EAE40");
extern u8 D_004EAE50_44_3[] __asm__("D_004EAE50");

s32 prep__17TwistedMemoryCard(void* arg0) {
    if (M2C_FIELD(arg0, s32* , 0x6C) != 0) {
        M2C_FIELD(arg0, s32* , 0x6C) = 0;
        initialize__10MemoryCardPcT1T1_44_3(arg0, ((u8*)D_004EAE30_44_3), ((u8*)D_004EAE40_44_3), ((u8*)D_004EAE50_44_3));
    }
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", doesTwistedDirectoryExist__17TwistedMemoryCardR9_MCStatus);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", doesTwistedSaveExist__17TwistedMemoryCardR9_MCStatus);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", doesGlobalDataExist__17TwistedMemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", doesCoopSaveExist__17TwistedMemoryCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", saveGlobalData__17TwistedMemoryCardP19TmGlobalMemCardDatabb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", loadGlobalData__17TwistedMemoryCardP19TmGlobalMemCardData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", spGetGameListing__17TwistedMemoryCardP15TmSpMemCardDataRUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", spSaveGame__17TwistedMemoryCardUiP15TmSpMemCardData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", coopGetGameListing__17TwistedMemoryCardP17TmCoopMemCardDataRUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", coopSaveGame__17TwistedMemoryCardUiP17TmCoopMemCardData);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tmmemcard", getChecksum__17TwistedMemoryCardPvi);
