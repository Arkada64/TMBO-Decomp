#include "common.h"

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", updateScream__19AmbientSoundManageriP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", requestScream__19AmbientSoundManageriP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A70B0);

#include "m2c_macros.h"
void* __14StreamingSound(void* arg0) {
    M2C_FIELD(arg0, s32* , 0x40) = 4;
    M2C_FIELD(arg0, f32* , 0x24) = 1.0f;
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A72F0);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", updateStreamingSound__14StreamingSound);

#include "m2c_macros.h"
M2C_UNK __14StreamingSound_gSound() __asm__("__14StreamingSound");

void* __17SFXStreamingSound(void* arg0) {
    __14StreamingSound_gSound();
    M2C_FIELD(arg0, f32* , 0x28) = 2.0f;
    return arg0;
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A7570);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_dState() __asm__("timerGetFieldCount__Fv");

void setState__14StreamingSound18_ambientSoundState(void* arg0, s32 arg1) {
    M2C_FIELD_V1(arg0, s32* , 0x40) = arg1;
    if (arg1 == 0) {
        M2C_FIELD_V1(arg0, s32* , 0xC) = timerGetFieldCount__Fv_dState();
    } else if (arg1 == 3) {
        M2C_FIELD_V1(arg0, s32* , 8) = timerGetFieldCount__Fv_dState();
    }
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", updateSFXStreamingSound__17SFXStreamingSound);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A7A38);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A7F00);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A8278);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", playBlimpExplosion__14ExplosionSoundP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", playPizzaManExplosion__14ExplosionSoundP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A8518);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A8548);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A8570);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", updateErrantLoops__17ErrantLoopManager);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", playDestructibleSound__FP8_fvectoriiii);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", playCityLampDestroyedSound__FP8_fvector);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A87B8);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_1A8870() __asm__("timerGetFieldCount__Fv");

void func_001A8870(s32* arg0) {
    *arg0 = timerGetFieldCount__Fv_1A8870();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", playLightPoleBounceSound__17TimberDebrisSoundP8_fvectorf);

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A89C0);

#include "m2c_macros.h"
s32 timerGetFieldCount__Fv_1A8A28() __asm__("timerGetFieldCount__Fv");

void func_001A8A28(s32* arg0) {
    *arg0 = timerGetFieldCount__Fv_1A8A28();
}

INCLUDE_ASM("/home/ark/tmbo_decomp/asm/nonmatchings/tmb/sound_part3", func_001A8A50);
