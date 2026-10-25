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
//@@ func_00193AC8 hand
/* volume of a sound by distance (arg dist): inside the near radius (+0x184 -> +0x320) 0..90 %, beyond it 90 % + 10 %
 * of the way to the far edge (+0x330 * 40.909); then 0..0x7FFF, with a random drift (+0xF4 on, +0xF8 current,
 * +0x114 goal, +0x118 step). The m2c draft did the float math on the bit patterns (bench 10-25). */
extern int rand_h(void) __asm__("rand");
extern int D_004FA194_h __asm__("D_004FA194");
static float K193AC8[4] = { 40.909092f, 10.0f, 90.0f, -1.0f };   /* (0x4223A2E9, 0x41200000, 0x42B40000, -1) */
int func_00193AC8(char* s, int dist)
{
    char* p = *(char**)(s + 0x184);
    float d = (float)dist, nearR = *(float*)(p + 0x320), far = *(float*)(p + 0x330) * K193AC8[0], pc;
    int v, vol, r;
    if (nearR < d) pc = (d - nearR) * K193AC8[1] / (far - nearR) + K193AC8[2];
    else pc = (float)(dist * 90) / nearR;
    v = (int)pc;
    vol = v * 0x7FFF / 100;
    if (D_004FA194_h == 0) *(float*)(s + 0x154) = K193AC8[3];
    if ((float)v != *(float*)(s + 0x154)) {
        *(int*)(s + 0xF4) = 0;
        *(int*)(s + 0xF8) = vol;
        return vol;
    }
    if (*(int*)(s + 0xF4)) {
        int step = *(int*)(s + 0x118), cur = *(int*)(s + 0xF8) + step;
        *(int*)(s + 0xF8) = cur;
        if (step > 0 && cur >= *(int*)(s + 0x114)) *(int*)(s + 0xF8) = *(int*)(s + 0x114);
        if (*(int*)(s + 0x118) < 0 && *(int*)(s + 0xF8) <= *(int*)(s + 0x114)) *(int*)(s + 0xF8) = *(int*)(s + 0x114);
        if (*(int*)(s + 0xF8) > 0x7FFF) *(int*)(s + 0xF8) = 0x7FFF;
        vol = *(int*)(s + 0xF8);
        if (vol == *(int*)(s + 0x114)) *(int*)(s + 0xF4) = 0;
        return vol;
    }
    *(int*)(s + 0x118) = rand_h() % *(int*)(s + 0x110) + 6;
    if (*(int*)(s + 0xF8) < vol) *(int*)(s + 0x114) = vol + rand_h() % *(int*)(s + 0x10C);
    else {
        r = rand_h() % *(int*)(s + 0x10C);
        *(int*)(s + 0x118) = -*(int*)(s + 0x118);
        *(int*)(s + 0x114) = vol - r;
    }
    *(int*)(s + 0xF4) = 1;
    return vol;
}
