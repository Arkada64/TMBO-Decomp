#include "common.h"
#include "m2c_macros.h"

void reset__9UiMemCardb_2C_0(void*, unsigned char) __asm__("reset__9UiMemCardb");
s32 __9UiMemCard(void* arg0) {
    reset__9UiMemCardb_2C_0(arg0, 1U);
    return (s32) arg0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", reset__9UiMemCardb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", loop__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", showButtonPrompt__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", initialStartup__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", savePrefs__9UiMemCardi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", loadPrefs__9UiMemCardi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", saveEndurance__9UiMemCardi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", saveGame__9UiMemCardi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", loadGame__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", prep__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", handleInput__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", textSize__9UiMemCardbbb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", calcCurSaveSize__9UiMemCard);

void textSize__9UiMemCardbbb_164_21(void*, unsigned char, unsigned char, unsigned char) __asm__("textSize__9UiMemCardbbb");
void setButtonPrompt__9UiMemCardPCc_164_21(void*, void*) __asm__("setButtonPrompt__9UiMemCardPCc");
int prep__9UiMemCard_164_21(void*) __asm__("prep__9UiMemCard");
void fontSpritePrintCentered__FiPc_164_21(int, void*) __asm__("fontSpritePrintCentered__FiPc");
void fontSetCursorAtSubPixel__Fiii_164_21(int, int, int) __asm__("fontSetCursorAtSubPixel__Fiii");
M2C_UNK sprintf_164_21() __asm__("sprintf");
extern u8 D_004F0E00_164_21[] __asm__("D_004F0E00");
extern u8 D_004FB460_164_21[] __asm__("D_004FB460");
extern u8 ERROR_PROMPT_954_164_21[4] __asm__("ERROR_PROMPT_954");

s32 ErrorScreen__9UiMemCardPcT1(void* arg0, void* arg1, void* arg2) {
    u8 sp[0x40];
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;
    void* temp_a1;
    void** var_s2;

    setButtonPrompt__9UiMemCardPCc_164_21(arg0, ((u8*)D_004F0E00_164_21));
    textSize__9UiMemCardbbb_164_21(arg0, 1U, 0U, 0U);
    fontSetCursorAtSubPixel__Fiii_164_21(0, M2C_FIELD(arg0, s32* , 0x128) * 0x10, M2C_FIELD(arg0, s32* , 0x12C) * 0x10);
    fontSpritePrintCentered__FiPc_164_21(0, arg1);
    if (arg2 != NULL) {
        fontSetCursorAtSubPixel__Fiii_164_21(0, M2C_FIELD(arg0, s32* , 0x128) * 0x10, (M2C_FIELD(arg0, s32* , 0x12C) + M2C_FIELD(arg0, s32* , 0x11C)) * 0x10);
        fontSpritePrintCentered__FiPc_164_21(0, arg2);
        sprintf_164_21(sp, ((u8*)D_004FB460_164_21), arg0 + 0x148);
        fontSetCursorAtSubPixel__Fiii_164_21(0, M2C_FIELD(arg0, s32* , 0x128) * 0x10, (M2C_FIELD(arg0, s32* , 0x12C) + (M2C_FIELD(arg0, s32* , 0x11C) * 2)) * 0x10);
        fontSpritePrintCentered__FiPc_164_21(0, sp);
    }
    var_s0 = 0;
    var_s2 = ((u8*)ERROR_PROMPT_954_164_21);
    M2C_FIELD(arg0, s32* , 0xAC) = (s32) (M2C_FIELD(arg0, s32* , 0xAC) | 3);
    do {
        temp_v0 = M2C_FIELD(arg0, s32* , 0x11C) * (var_s0 + 3);
        var_s0 += 1;
        fontSetCursorAtSubPixel__Fiii_164_21(0, M2C_FIELD(arg0, s32* , 0x128) * 0x10, (M2C_FIELD(arg0, s32* , 0x12C) + temp_v0) * 0x10);
        temp_a1 = *var_s2;
        var_s2 +=0x1;
        fontSpritePrintCentered__FiPc_164_21(0, temp_a1);
    } while (var_s0 < 2);
    var_v0 = M2C_FIELD(arg0, s32* , 0x144);
    if (var_v0 != 0) {
        var_v0 = prep__9UiMemCard_164_21(arg0);
        M2C_FIELD(arg0, s32* , 0) = 0;
    }
    return var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", cardPulledOutScreen__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", finishShellLoop__Fv);

void finishShellLoop__Fv_94_34(void) __asm__("finishShellLoop__Fv");
void fontDmaFontData__Fv_94_34(void) __asm__("fontDmaFontData__Fv");
void particleDraw__Fi_94_34(int) __asm__("particleDraw__Fi");
M2C_UNK sceGsSyncPath_94_34() __asm__("sceGsSyncPath");
M2C_UNK sceGsSyncVCallback_94_34() __asm__("sceGsSyncVCallback");
void setFlipBufActive__Fb_94_34(unsigned char) __asm__("setFlipBufActive__Fb");
void setFlipOddEven__Fi_94_34(int) __asm__("setFlipOddEven__Fi");
s32 shellOverlaysGetOddEven__Fv_94_34(void) __asm__("shellOverlaysGetOddEven__Fv");
extern u8 iFlipBufferCB__Fi_94_34[] __asm__("iFlipBufferCB__Fi");

void startInterupt__9UiMemCard(void* arg0) {
    if (M2C_FIELD(arg0, s32* , 0x114) != 0) {
        setFlipBufActive__Fb_94_34(1);
        setFlipOddEven__Fi_94_34(shellOverlaysGetOddEven__Fv_94_34() ^ 1);
        if (M2C_FIELD(arg0, s32* , 0x1EC) == 0) {
            sceGsSyncVCallback_94_34(((u8*)iFlipBufferCB__Fi_94_34));
            M2C_FIELD(arg0, s32* , 0x1EC) = 1;
        }
        particleDraw__Fi_94_34(0);
        sceGsSyncPath_94_34(0, 0);
        fontDmaFontData__Fv_94_34();
        sceGsSyncPath_94_34(0, 0);
        finishShellLoop__Fv_94_34();
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", disableInterupt__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", saveGameData__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", saveGlobalData__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", loadGlobalData__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", checkSizeOnAllCards__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", DEBUGCheckedUnformat__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", selectPort__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", handleFormat__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", checkSizeRemaining__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", chooseSpOrCoop__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", selectGame__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", selectLevel__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", askToSaveEndurance__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", chooseToSave__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", printSavedGameList__9UiMemCardRbP17TmCoopMemCardDataP15TmSpMemCardDatab);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", getLevelNames__9UiMemCardiPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", selectSaveSlot__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", askOverwrite__9UiMemCard);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/uimemcard", doStandardAccessChecks__9UiMemCardP9_MCStatus);

void setMaxSelect__9UiMemCardi(void* arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32* , 0xBC);
    M2C_FIELD(arg0, s32* , 0xB8) = arg1;
    M2C_FIELD(arg0, s32* , 0xBC) = (s32) ((temp_v0 >= arg1) ? arg1 : temp_v0);
}

s32 strcpy_2C_83() __asm__("strcpy");

s32 setButtonPrompt__9UiMemCardPCc(void* arg0, void* arg1) {
    s32 temp_v0;

    temp_v0 = strcpy_2C_83(arg0 + 0x168);
    M2C_FIELD(arg0, s32* , 0x1E8) = 0;
    return temp_v0;
}
