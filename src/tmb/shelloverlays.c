#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", displayDialog__F13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", finishedBestOfBattleLevel__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", allDeadMultPlayBattleLevel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", display34TeamResults__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", display34PlayResults__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", rank34Players__FPiPf);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", twoPBattleEnd__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", selectNextMultPlayBattleLevel__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", selectNext34PlayLevel__FP13_shellOverlay);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", chooseNextLevel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", wonStoryOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", wonLastManStandingLevelOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", updateMemoryCardInput__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", lostLevelOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", CheckForSurety__FPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", saveOnQuitOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", pauseLevelOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", lostEnduranceOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", wonEnduranceOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", wonLevelOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", wonChallengeLevelOverlay__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", checkInputForExit__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", checkInputForPauseExit__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", checkInputForBack__Fi);

void fontSetColor__Fiiii_60_27(int, int, int, int) __asm__("fontSetColor__Fiiii");
void fontSetSize__Fii_60_27(int, int) __asm__("fontSetSize__Fii");
extern u8 gCurrentMenuSelection_60_27[4] __asm__("gCurrentMenuSelection");

void setMenuFont__Fi(s32 arg0) {
    if ((*(s32*)gCurrentMenuSelection_60_27) == arg0) {
        fontSetSize__Fii_60_27(0, 0x12);
        fontSetColor__Fiiii_60_27(0, 0x78, 0x6E, 0);
        return;
    }
    fontSetSize__Fii_60_27(0, 0x10);
    fontSetColor__Fiiii_60_27(0, 0x46, 0x46, 0x46);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", setLevelMenuFont__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", initMapMenu2LevelNum__Fv);

void fontSetColor__Fiiii_30_36(int, int, int, int) __asm__("fontSetColor__Fiiii");
void fontSetSize__Fii_30_36(int, int) __asm__("fontSetSize__Fii");

void setTitleFont__Fv(void) {
    fontSetSize__Fii_30_36(0, 0x16);
    fontSetColor__Fiiii_30_36(0, 0x6E, 0x6E, 0x6E);
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", getCurrentMenuSelection__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", getCurrentLevelMenuSelection__Fii);

extern u8 gPlayerThatPaused_8_44[4] __asm__("gPlayerThatPaused");

void shellSetPlayerThatPaused__Fi(s32 arg0) {
    (*(s32*)gPlayerThatPaused_8_44) = arg0;
}

extern u8 oddEven_C_47[4] __asm__("oddEven");

s32 shellOverlaysGetOddEven__Fv(void) {
    return (*(s32*)oddEven_C_47) != 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/shelloverlays", func_00168160);
