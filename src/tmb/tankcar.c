#include "common.h"
#include "m2c_macros.h"

void animationGetHandle__FP11_animHandleUiUiUi_F4_1(void*, unsigned int, unsigned int, unsigned int) __asm__("animationGetHandle__FP11_animHandleUiUiUi");
void animationLoop__FR11_animHandleb_F4_1(void*, unsigned char) __asm__("animationLoop__FR11_animHandleb");
void animationStart__FR11_animHandleb_F4_1(void*, unsigned char) __asm__("animationStart__FR11_animHandleb");
extern u8 leftTrackHandle_F4_1[] __asm__("leftTrackHandle");
extern u8 rightTrackHandle_F4_1[] __asm__("rightTrackHandle");

void tankCarInit__7Vehicle(void* arg0) {
    s32 temp_a2;
    s32* temp_a0;
    s32* temp_v1;

    temp_a2 = M2C_FIELD(arg0, s32* , 0x20A4);
    animationGetHandle__FP11_animHandleUiUiUi_F4_1((temp_a2 * 0xC) + ((u8*)leftTrackHandle_F4_1), 0x180, temp_a2, 0x1A);
    temp_v1 = (M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)leftTrackHandle_F4_1);
    if (*temp_v1 != 0) {
        animationLoop__FR11_animHandleb_F4_1(temp_v1, 1);
        animationStart__FR11_animHandleb_F4_1((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)leftTrackHandle_F4_1), 1);
    }
    animationGetHandle__FP11_animHandleUiUiUi_F4_1((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)rightTrackHandle_F4_1), 0x180, 0, 0x1B);
    temp_a0 = (M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)rightTrackHandle_F4_1);
    if (*temp_a0 != 0) {
        animationLoop__FR11_animHandleb_F4_1(temp_a0, 1);
        animationStart__FR11_animHandleb_F4_1((M2C_FIELD(arg0, s32* , 0x20A4) * 0xC) + ((u8*)rightTrackHandle_F4_1), 1);
    }
}

INCLUDE_ASM("/home/ark/tmb_decomp/asm/nonmatchings/tmb/tankcar", tankCarUpdateTrack__7Vehicle);
