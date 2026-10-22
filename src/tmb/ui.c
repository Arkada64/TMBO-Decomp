#include "common.h"
#include "m2c_macros.h"

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiMain__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", setPov__Ffff);

extern u8 shell_38_4[4] __asm__("shell");

void offsetButtonLegend__Ff(f32 fparg0) {
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x3660), f32* , 0x10) = fparg0;
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x3690), f32* , 0x10) = fparg0;
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x36C0), f32* , 0x10) = fparg0;
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x36F0), f32* , 0x10) = fparg0;
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x3720), f32* , 0x10) = fparg0;
    M2C_FIELD(M2C_FIELD((*(void**)shell_38_4), void** , 0x3750), f32* , 0x10) = fparg0;
}

extern u8 circle_btn_BC_7[4] __asm__("circle_btn");
extern u8 down_btn_BC_7[4] __asm__("down_btn");
extern u8 left_btn_BC_7[4] __asm__("left_btn");
extern u8 right_btn_BC_7[4] __asm__("right_btn");
extern u8 save_circle_btn_BC_7[4] __asm__("save_circle_btn");
extern u8 save_left_btn_BC_7[4] __asm__("save_left_btn");
extern u8 save_right_btn_BC_7[4] __asm__("save_right_btn");
extern u8 save_square_btn_BC_7[4] __asm__("save_square_btn");
extern u8 save_triangle_btn_BC_7[4] __asm__("save_triangle_btn");
extern u8 save_up_btn_BC_7[4] __asm__("save_up_btn");
extern u8 save_x_btn_BC_7[4] __asm__("save_x_btn");
extern u8 square_btn_BC_7[4] __asm__("square_btn");
extern u8 triangle_btn_BC_7[4] __asm__("triangle_btn");
extern u8 up_btn_BC_7[4] __asm__("up_btn");
extern u8 x_btn_BC_7[4] __asm__("x_btn");

void delayButtonPress__Fv(void) {
    if ((*(s32*)x_btn_BC_7) != 0) {
        (*(s32*)x_btn_BC_7) = 0;
        (*(s32*)save_x_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)circle_btn_BC_7) != 0) {
        (*(s32*)circle_btn_BC_7) = 0;
        (*(s32*)save_circle_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)triangle_btn_BC_7) != 0) {
        (*(s32*)triangle_btn_BC_7) = 0;
        (*(s32*)save_triangle_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)square_btn_BC_7) != 0) {
        (*(s32*)square_btn_BC_7) = 0;
        (*(s32*)save_square_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)left_btn_BC_7) != 0) {
        (*(s32*)left_btn_BC_7) = 0;
        (*(s32*)save_left_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)right_btn_BC_7) != 0) {
        (*(s32*)right_btn_BC_7) = 0;
        (*(s32*)save_right_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)up_btn_BC_7) != 0) {
        (*(s32*)up_btn_BC_7) = 0;
        (*(s32*)save_up_btn_BC_7) = 1;
        return;
    }
    if ((*(s32*)down_btn_BC_7) != 0) {
        (*(s32*)down_btn_BC_7) = 0;
    }
}

extern u8 circle_btn_C4_10[4] __asm__("circle_btn");
extern u8 down_btn_C4_10[4] __asm__("down_btn");
extern u8 left_btn_C4_10[4] __asm__("left_btn");
extern u8 right_btn_C4_10[4] __asm__("right_btn");
extern u8 save_circle_btn_C4_10[4] __asm__("save_circle_btn");
extern u8 save_down_btn_C4_10[4] __asm__("save_down_btn");
extern u8 save_left_btn_C4_10[4] __asm__("save_left_btn");
extern u8 save_right_btn_C4_10[4] __asm__("save_right_btn");
extern u8 save_square_btn_C4_10[4] __asm__("save_square_btn");
extern u8 save_triangle_btn_C4_10[4] __asm__("save_triangle_btn");
extern u8 save_up_btn_C4_10[4] __asm__("save_up_btn");
extern u8 save_x_btn_C4_10[4] __asm__("save_x_btn");
extern u8 square_btn_C4_10[4] __asm__("square_btn");
extern u8 triangle_btn_C4_10[4] __asm__("triangle_btn");
extern u8 up_btn_C4_10[4] __asm__("up_btn");
extern u8 x_btn_C4_10[4] __asm__("x_btn");

void retrieveButtonPress__Fv(void) {
    if ((*(s32*)save_x_btn_C4_10) != 0) {
        (*(s32*)save_x_btn_C4_10) = 0;
        (*(s32*)x_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_circle_btn_C4_10) != 0) {
        (*(s32*)save_circle_btn_C4_10) = 0;
        (*(s32*)circle_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_triangle_btn_C4_10) != 0) {
        (*(s32*)save_triangle_btn_C4_10) = 0;
        (*(s32*)triangle_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_square_btn_C4_10) != 0) {
        (*(s32*)save_square_btn_C4_10) = 0;
        (*(s32*)square_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_left_btn_C4_10) != 0) {
        (*(s32*)save_left_btn_C4_10) = 0;
        (*(s32*)left_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_right_btn_C4_10) != 0) {
        (*(s32*)save_right_btn_C4_10) = 0;
        (*(s32*)right_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_up_btn_C4_10) != 0) {
        (*(s32*)save_up_btn_C4_10) = 0;
        (*(s32*)up_btn_C4_10) = 1;
        return;
    }
    if ((*(s32*)save_down_btn_C4_10) != 0) {
        (*(s32*)save_down_btn_C4_10) = 0;
        (*(s32*)down_btn_C4_10) = 1;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiInitScreens__FP3_cs);

void uiFadeAmb__Fif(void) {
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiChangeScreen__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiTitle_Main__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiMovies__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiOptions__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", acceptOptionsSettings__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", setLoadedOptionsSettings__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", initUIOptionsVars__Fv);

s32 loadPrefs__9UiMemCardi_AC_27(void*, int) __asm__("loadPrefs__9UiMemCardi");
void offsetButtonLegend__Ff_AC_27(float) __asm__("offsetButtonLegend__Ff");
void setLoadedOptionsSettings__Fv_AC_27(void) __asm__("setLoadedOptionsSettings__Fv");
void uiGetInput__Fv_AC_27(void) __asm__("uiGetInput__Fv");
extern u8 nextMovie_AC_27[4] __asm__("nextMovie");
extern u8 nextScreen_AC_27[4] __asm__("nextScreen");
extern u8 shell_AC_27[4] __asm__("shell");
extern u8 transitioning_AC_27[4] __asm__("transitioning");
extern u8 uiCheckPads_AC_27[4] __asm__("uiCheckPads");

void uiLoadPrefs__Fv(void) {
    (*(s32*)uiCheckPads_AC_27) = 0;
    uiGetInput__Fv_AC_27();
    offsetButtonLegend__Ff_AC_27(0);
    M2C_FIELD((*(void**)shell_AC_27), s32* , 0x19FA4) = 1;
    if (loadPrefs__9UiMemCardi_AC_27((*(void**)shell_AC_27) + 0x19EC0, 0x54) == 0) {
        if (M2C_FIELD((*(void**)shell_AC_27), s32* , 0x19FE0) != 0) {
            (*(s32*)transitioning_AC_27) = 1;
            (*(s32*)nextScreen_AC_27) = 0xA;
        }
    } else if (M2C_FIELD((*(void**)shell_AC_27), s32* , 0x19FE0) != 0) {
        setLoadedOptionsSettings__Fv_AC_27();
        (*(s32*)transitioning_AC_27) = 1;
        (*(s32*)nextMovie_AC_27) = 0x73;
        (*(s32*)nextScreen_AC_27) = 0;
    }
}

void acceptOptionsSettings__Fv_A8_30(void) __asm__("acceptOptionsSettings__Fv");
void offsetButtonLegend__Ff_A8_30(float) __asm__("offsetButtonLegend__Ff");
s32 savePrefs__9UiMemCardi_A8_30(void*, int) __asm__("savePrefs__9UiMemCardi");
void uiGetInput__Fv_A8_30(void) __asm__("uiGetInput__Fv");
extern u8 nextMovie_A8_30[4] __asm__("nextMovie");
extern u8 nextScreen_A8_30[4] __asm__("nextScreen");
extern u8 shell_A8_30[4] __asm__("shell");
extern u8 transitioning_A8_30[4] __asm__("transitioning");
extern u8 uiCheckPads_A8_30[4] __asm__("uiCheckPads");

void uiSavePrefs__Fv(void) {
    (*(s32*)uiCheckPads_A8_30) = 0;
    uiGetInput__Fv_A8_30();
    offsetButtonLegend__Ff_A8_30(0);
    acceptOptionsSettings__Fv_A8_30();
    M2C_FIELD((*(void**)shell_A8_30), s32* , 0x19FA4) = 1;
    if (savePrefs__9UiMemCardi_A8_30((*(void**)shell_A8_30) + 0x19EC0, 0x54) == 0) {
        if (M2C_FIELD((*(void**)shell_A8_30), s32* , 0x19FE0) != 0) {
            (*(s32*)transitioning_A8_30) = 1;
            (*(s32*)nextScreen_A8_30) = 0xA;
        }
    } else if (M2C_FIELD((*(void**)shell_A8_30), s32* , 0x19FE0) != 0) {
        (*(s32*)transitioning_A8_30) = 1;
        (*(s32*)nextMovie_A8_30) = 0x73;
        (*(s32*)nextScreen_A8_30) = 0;
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", playCharIntro__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiPlayArenaMovie__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiPlayMidgameMovie__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiPlayRoofMovie__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiPlayEndMovie__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiPlayCreditsMovieEtc__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiblackScreen__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", LoadingBarBackground__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiLoadGame__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiLoadLevel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiGameModes_1P__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiGameModes_MP__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiMP_DeathMatch_Options__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", ui4P_DM_Choose_Teams__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiCarSel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uicarStatsUpdate__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiLvlSel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiAiSel__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiGetInput__Fv);

s32 timerGetFieldCount__Fv_60_80(void) __asm__("timerGetFieldCount__Fv");
extern u8 curButtontime_60_80[4] __asm__("curButtontime");
extern u8 deltaButtontime_60_80[4] __asm__("deltaButtontime");
extern u8 prevButtonTime_60_80[4] __asm__("prevButtonTime");
extern u8 shortMovies_60_80[4] __asm__("shortMovies");

void uiButtonTimeDelta__Fv(void) {
    s32 temp_v0;
    s32 temp_v1;

    (*(s32*)prevButtonTime_60_80) = (*(s32*)curButtontime_60_80);
    temp_v0 = timerGetFieldCount__Fv_60_80();
    temp_v1 = temp_v0 - (*(s32*)prevButtonTime_60_80);
    (*(s32*)curButtontime_60_80) = temp_v0;
    (*(s32*)deltaButtontime_60_80) = temp_v1;
    if ((f32) temp_v1 < 60.0f) {
        (*(s32*)shortMovies_60_80) = 1;
        return;
    }
    (*(s32*)shortMovies_60_80) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiSetScreen__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiIncognito__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiFadeCSAlpha__Fiiii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiFadeText__Fii);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiFilmClutter__FP8_fvectorT0);

extern u8 shell_18_95[4] __asm__("shell");

void setAttractMode__Fv(void) {
    M2C_FIELD((*(void**)shell_18_95), s32* , 0x1A35C) = 0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", playMovie__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", textShake__FiPi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", textTrans__Fiiff);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", initUINonPersistantGlobalVars__Fv);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", printGameDescription__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", printHighScore__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", displayWarning__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", getCarSelNumFromID__Fi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", setSliderPositions__Fv);

void hierSetSwitch__FP11_hierswitchi_78_122(void*, int) __asm__("hierSetSwitch__FP11_hierswitchi");
extern u8 shell_78_122[4] __asm__("shell");

void blankSliders__Fi(s32 arg0) {
    hierSetSwitch__FP11_hierswitchi_78_122(M2C_FIELD((*(void**)shell_78_122), s32* , 0x328), 0);
    hierSetSwitch__FP11_hierswitchi_78_122(M2C_FIELD((*(void**)shell_78_122), s32* , 0x32C), 0);
    M2C_FIELD(M2C_FIELD((*(void**)shell_78_122), void** , 0x4650), f32* , 0x10) = -1000.0f;
    if (arg0 == 0) {
        hierSetSwitch__FP11_hierswitchi_78_122(M2C_FIELD((*(void**)shell_78_122), s32* , 0x330), 0);
        M2C_FIELD(M2C_FIELD((*(void**)shell_78_122), void** , 0x4680), f32* , 0x10) = -1000.0f;
    }
}

extern u8 shell_20_124[4] __asm__("shell");

s32 unBlankSliders__Fi(s32 arg0) {
    void* var_v0;

    var_v0 = M2C_FIELD((*(void**)shell_20_124), void** , 0x4650);
    M2C_FIELD(var_v0, s32* , 0x10) = 0;
    if (arg0 == 0) {
        var_v0 = M2C_FIELD((*(void**)shell_20_124), void** , 0x4680);
        M2C_FIELD(var_v0, s32* , 0x10) = 0;
    }
    return (s32) var_v0;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", levelLoadCharBlurb__Fiif);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiFlashButtonLegend__Fi);

extern u8 flashRate_3C_131[4] __asm__("flashRate");
extern u8 flashRateCtr_3C_131[4] __asm__("flashRateCtr");
extern u8 flashState_3C_131[4] __asm__("flashState");

void uiFlashSwap__Fv(void) {
    if ((*(s32*)flashRateCtr_3C_131) >= (*(s32*)flashRate_3C_131)) {
        (*(s32*)flashRateCtr_3C_131) = 0;
        if ((*(s32*)flashState_3C_131) == 0) {
            (*(s32*)flashState_3C_131) = 1;
            return;
        }
        (*(s32*)flashState_3C_131) = 0;
        return;
    }
    (*(s32*)flashRateCtr_3C_131) += 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/ui", uiSetPov__Fib);
