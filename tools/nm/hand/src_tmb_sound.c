//@@ func_00195DA8 hand
/* a level's looping ambient sound at a fixed spot (level type game+0x1A3AC: 8, 11, others), started / steered /
 * stopped by its volume there. The m2c draft lost the position vector and most arguments (bench 10-25: it read
 * a handle from 0xF71). Arguments go in $4-$11 (EE ABI: eight integer registers). */
extern void calcDualMonoMixVolPan_h(float* pos, int a, int b, int* vol, int* pan, int* x) __asm__("calcDualMonoMixVolPan__FP8_fvectoriiRiT3Pi");
extern void sndPlayVolPan_h(int snd, int a, int vol, int pan, int b, int c, void* cb, int* handle) __asm__("snd_PlaySoundVolPanPMPB_CB");
extern void sndSetVolPan_h(int handle, int what, int vol, int pan, int b, int c) __asm__("func_001F9A58");
extern void soundStopSound_h(int* handle) __asm__("soundStopSound__FPUi");
extern char soundPlayCB_h __asm__("soundPlayCB__FUiUl");
extern char* D_004FA03C_h __asm__("D_004FA03C");
extern int D_004FA32C_h __asm__("D_004FA32C");
void func_00195DA8(int* s)
{
    float pos[4];
    int vol = 0, pan = 0, a, b, t = *(int*)(D_004FA03C_h + 0x1A3AC);
    if (t == 8) { pos[0] = 1460.0f; pos[1] = 725.0f; pos[2] = 505.0f; a = 0x4B; b = 0xFA; }
    else if (t == 11) { pos[0] = 546.0f; pos[1] = -544.0f; pos[2] = 16.0f; a = 0xAF; b = 0x44C; }
    else { pos[0] = -824.0f; pos[1] = 789.0f; pos[2] = 146.0f; a = 0x12C; b = 0x3E8; }
    calcDualMonoMixVolPan_h(pos, a, b, &vol, &pan, 0);
    if (vol > 0 && s[0] == 1) {
        if (s[1] == 0) {
            s[1] = -1;
            sndPlayVolPan_h(D_004FA32C_h, 0, vol, pan, 0, 0, &soundPlayCB_h, &s[1]);
        } else if (s[1] != -1)
            sndSetVolPan_h(s[1], 5, vol, pan, 0, 0);
    } else if (s[1] != 0 && s[1] != -1)
        soundStopSound_h(&s[1]);
}
