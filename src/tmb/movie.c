#include "common.h"
#include "m2c_macros.h"

void dispCreate__FP8_Displayii_68_1(void*, int, int) __asm__("dispCreate__FP8_Displayii");
void initAll__FPc_68_1(void*) __asm__("initAll__FPc");
void readMpeg__FP8VideoDecP7ReadBufP7StrFile_68_1(void*, void*, void*) __asm__("readMpeg__FP8VideoDecP7ReadBufP7StrFile");
M2C_UNK sceSifInitRpc_68_1() __asm__("sceSifInitRpc");
void termAll__Fv_68_1(void) __asm__("termAll__Fv");
void voBufReset__FP5VoBuf_68_1(void*) __asm__("voBufReset__FP5VoBuf");
extern u8 display_68_1[] __asm__("display");
extern u8 infile_68_1[] __asm__("infile");
extern u8 readBuf_68_1[4] __asm__("readBuf");
extern u8 videoDec_68_1[] __asm__("videoDec");
extern u8 voBuf_68_1[] __asm__("voBuf");

void playMpegMovie__FPc(s32 arg0) {
    voBufReset__FP5VoBuf_68_1(((u8*)voBuf_68_1));
    sceSifInitRpc_68_1(0);
    dispCreate__FP8_Displayii_68_1(((u8*)display_68_1), 0x280, 0xE0);
    initAll__FPc_68_1(arg0);
    readMpeg__FP8VideoDecP7ReadBufP7StrFile_68_1(((u8*)videoDec_68_1), (*(s32*)readBuf_68_1), ((u8*)infile_68_1));
    termAll__Fv_68_1();
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", playMpegMovieWithDB__FPcbi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", updateMpegMovieDecoding__Fb);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", readMpeg__FP8VideoDecP7ReadBufP7StrFile);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", switchThread__Fv);

int audioDecIsPreset__FP8AudioDec_34_15(void*) __asm__("audioDecIsPreset__FP8AudioDec");
extern u8 audioDec_34_15[] __asm__("audioDec");
extern u8 isWithAudio_34_15[4] __asm__("isWithAudio");

s32 isAudioOK__Fv(void) {
    if ((*(s32*)isWithAudio_34_15) != 0) {
        return audioDecIsPreset__FP8AudioDec_34_15(((u8*)audioDec_34_15));
    }
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", initAll__FPc);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", termAll__Fv);

void switchThread__Fv_18_24(void) __asm__("switchThread__Fv");
void defMain__Fv(void) {
loop_1:
    switchThread__Fv_18_24();
    goto loop_1;
}

M2C_UNK printf_10_28() __asm__("printf");
extern u8 D_004F2FE0_10_28[] __asm__("D_004F2FE0");

void ErrMessage__FPc(s32 arg0) {
    printf_10_28(((u8*)D_004F2FE0_10_28), arg0);
}

void audioDecSendToIOP__FP8AudioDec_24_30(void*) __asm__("audioDecSendToIOP__FP8AudioDec");
extern u8 audioDec_24_30[] __asm__("audioDec");

s32 proceedAudio__Fv(void) {
    audioDecSendToIOP__FP8AudioDec_24_30(((u8*)audioDec_24_30));
    return 1;
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", loadImage__FPUi);

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/movie", _GLOBAL_$I$movieRequested);
