/* TMB-Reloaded mod: free camera for spectators.
 * Hook (tools/mods/apply_mods.py): the game's per-frame camera update call (func_001166B8 at 0x1395E0 in
 * func_00138C90) goes to tmbr_CameraUpdate, which runs it and then, while free cam is on, replaces viewport
 * 0's camera with ours.
 * On while spectating (tmbr_spectating, set by tmbr_SpecMark in camera_pnach.s when the game switches a dead
 * player to the spectator camera; cleared at match start). Select toggles it off/on while spectating.
 * TMBR_FREECAM_ANYTIME (test builds only): Select + L3 toggles it any time, so it can be tested alone.
 * Controls: left stick move, right stick look, L2/R2 down/up, hold R1 = faster.
 * Camera data: Camera at game+0x27780; viewport i's camera state cs = *(cam + 0x42A0 + 4i):
 *   cs+0x10 position, cs+0x20 4x4 rotation matrix (translation 0), cs+0x60 angles (pitch, roll, heading);
 *   the view (func_00242930, at render time) uses cs+0x10 and cs+0x20.
 *   the update copies cs+0x20 to cam+0x4060 + 0x40i (64 bytes). */
typedef struct { float x, y, z, w; } fvec;
extern int inputGetCtlPadAnalogAxis(int axis, int pad) __asm__("inputGetCtlPadAnalogAxis__Fii");
/* raw pad bits, active high (SELECT 0x1, L3 0x2, L2 0x100, R2 0x200, R1 0x800). inputGetInput takes a
 * game-action id, not a button mask: with it Select/L2/R2/R1 never registered. */
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern void mathfRotMatrixRPH(float *m, fvec *angles) __asm__("mathfRotMatrixRPH__FPA3_fP8_fvector");
extern void cameraUpdate(char *cam) __asm__("func_001166B8");

int tmbr_spectating;
static int fc_off;          /* spectator turned it off with Select */
static int fc_init;
static int fc_anytime;
static int prev_buttons;
static fvec fc_pos, fc_ang;
/* float constants in one table (no compiler literal pool: the SN assembler would put it in gp-relative .lit4) */
static float K[12] = { 1.0f / 128.0f, 0.2f, 0.04f, 0.03f, 1.5f, 2.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f };
#define K_STICK K[0]
#define K_DEAD K[1]
#define K_YAW K[2]
#define K_PITCH K[3]
#define K_PMAX K[4]
#define K_FAST K[5]
#define K_SLOW K[6]
#define K_ONE K[7]
#define K_ZERO K[8]

#define IN_SELECT 0x0001
#define IN_L3 0x0002
#define IN_L2 0x0100
#define IN_R2 0x0200
#define IN_R1 0x0800

static float stick(int axis)
{
    float v = (float)(inputGetCtlPadAnalogAxis(axis, 0) - 128) * K_STICK;
    if (v > -K_DEAD && v < K_DEAD) return K_ZERO;
    return v;
}

extern void tmbr_TrafficUpdate(void);
extern void tmbr_BotsThink(void);

#ifndef TMBR_TRAFFIC_ON
#define TMBR_TRAFFIC_ON 0   /* traffic (traffic.c) per-frame update; the TRAFFIC_DIAG build sets 1 */
#endif
void tmbr_CameraUpdate(char *cam)
{
    int b, pad, pressed, i;
    float *m, *out, lx, ly, rx, ry, speed;
    char *cs;

#if TMBR_TRAFFIC_ON
    tmbr_TrafficUpdate(); /* traffic.c: per-frame traffic cars (after the game's vehicle loops); off in stable */
#endif
#ifndef TMBR_PNACH
    tmbr_BotsThink();     /* bots.c: free-for-all targets (not in the pnach build) */
#endif
    cameraUpdate(cam);

    pad = inputGetPadButtons(0);
    b = pad & (IN_SELECT | IN_L3);
    pressed = b & ~prev_buttons;
    prev_buttons = b;
#ifdef TMBR_FREECAM_ANYTIME
    if ((b & IN_L3) && (pressed & IN_SELECT)) { fc_anytime = !fc_anytime; pressed = 0; }
#endif
    if (!tmbr_spectating) fc_off = 0;
    else if (pressed & IN_SELECT) fc_off = !fc_off;

    if (!((tmbr_spectating && !fc_off) || fc_anytime)) { fc_init = 0; return; }
    cs = *(char **)(cam + 0x42A0);
    if (cs == 0) return;
    m = (float *)(cs + 0x20);
    if (!fc_init) {          /* start where the game's camera is */
        fc_pos = *(fvec *)(cs + 0x10);   /* camera position (the view uses cs+0x10 + the cs+0x20 rotation) */
        fc_ang = *(fvec *)(cs + 0x60);
        fc_ang.y = K_ZERO;
        fc_init = 1;
    }
    lx = stick(2); ly = stick(3); rx = stick(0); ry = stick(1);
    fc_ang.z += rx * K_YAW;
    fc_ang.x -= ry * K_PITCH;      /* stick up = look up */
    if (fc_ang.x > K_PMAX) fc_ang.x = K_PMAX;
    if (fc_ang.x < -K_PMAX) fc_ang.x = -K_PMAX;
    mathfRotMatrixRPH(m, &fc_ang);
    speed = (pad & IN_R1) ? K_FAST : K_SLOW;
    /* RPH matrix: world Z is up; row 1 = forward (cos p sin h, cos p cos h, sin p), row 0 = right */
    fc_pos.x += (m[4] * -ly + m[0] * lx) * speed;
    fc_pos.y += (m[5] * -ly + m[1] * lx) * speed;
    fc_pos.z += (m[6] * -ly + m[2] * lx) * speed;
    if (pad & IN_R2) fc_pos.z += speed;
    if (pad & IN_L2) fc_pos.z -= speed;
    /* (the matrix keeps a zero translation, like the game's: the position lives in cs+0x10) */
    *(fvec *)(cs + 0x10) = fc_pos;
    *(fvec *)(cs + 0x60) = fc_ang;
    out = (float *)(cam + 0x4060);
    for (i = 0; i < 16; i++) out[i] = m[i];
}
