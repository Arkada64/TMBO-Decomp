/* TMB-Reloaded mod: free camera for spectators.
 * Hook (tools/mods/apply_mods.py): the game's per-frame camera update call (func_001166B8 at 0x1395E0 in
 * func_00138C90) goes to tmbr_CameraUpdate, which runs it and then, while free cam is on, replaces viewport
 * 0's camera with ours.
 * On while spectating (tmbr_spectating, set by tmbr_SpecMark in camera_pnach.s when the game switches a dead
 * player to the spectator camera; cleared at match start) or the spectator POV (5). R3 turns it on/off while spectating.
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
int tmbr_hudStart;  /* set by tmbr_InitPOV (camera_pnach.s) at match start: frames until the weapon list default */
static int fc_on;          /* spectator turned it on with R3 */
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
#define IN_R3 0x0004
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
extern void tmbr_SkinsFrame(void);
extern void tmbr_BotsThink(void);
extern unsigned int tmbr_Cycles(void);              /* perf.c */
extern void tmbr_PerfAdd(int slot, unsigned int start);
extern void tmbr_PerfFrame(void);
extern void tmbr_PedsRetype(void);           /* packs.c */
extern int scePrintf(const char* fmt, ...);

#define TMBR_RFDBG 1   /* rear-fire debug log */
#ifndef TMBR_TRAFFIC_ON
#define TMBR_TRAFFIC_ON 1   /* traffic (traffic.c) per-frame update (on since the 2026-10-23 test round) */
#endif
static void hudDefault(void)
{
    /* Weapon bay: start in the list view (what Select+Right = func_00145818 cycles to from the default: HUD
     * (game + 0x97B50 + viewport * 0xA20) +0x7F4, 0 -> 1). Set a few frames after match start, after the HUD
     * init; only from the default, so a player's own choice stays. */
    if (tmbr_hudStart > 0 && --tmbr_hudStart == 0) {
        extern char* D_004FA030;
        char* gg = D_004FA030;
        int vp;
        if (gg)
            for (vp = 0; vp < 4; vp++)
                if (*(int*)(gg + 0x97B50 + vp * 0xA20 + 0x7F4) == 0) *(int*)(gg + 0x97B50 + vp * 0xA20 + 0x7F4) = 1;
    }
}

#ifdef TMBR_PNACH
/* vanilla pnach: one shared hook, each pnach section switches its part on (tmbr_en lives in the cave,
 * written by that section only): [0] spectator free cam, [1] damage reports, [2] weapon list default */
extern int tmbr_en[3];
extern void tmbr_DamageReportTick(void);   /* dmgreport.c */
#endif
void tmbr_CameraUpdate(char *cam)
{
    int b, pad, pressed, i;
    float *m, *out, lx, ly, rx, ry, speed;
    char *cs;

#if TMBR_TRAFFIC_ON
    tmbr_SkinsFrame();   /* skins.c: 12 Pak's armed special */
    { unsigned int t0 = tmbr_Cycles(); tmbr_TrafficUpdate(); tmbr_PerfAdd(3, t0); } /* traffic.c: per-frame traffic cars (after the game's vehicle loops); off in stable */
#endif
#ifdef TMBR_PNACH
    if (tmbr_en[1]) tmbr_DamageReportTick();
    if (tmbr_en[2]) hudDefault();
#else
    hudDefault();
    { unsigned int t0 = tmbr_Cycles(); tmbr_BotsThink(); tmbr_PerfAdd(0, t0); } /* bots.c: free-for-all targets (not in the pnach build) */
    tmbr_PerfFrame();     /* perf.c: per-frame cost log every 5 s */
    tmbr_PedsRetype();    /* packs.c: inmates into SHIP / ASYLUM ped groups after load */
    {   /* debug (rear fire via L1+Down does nothing, the d-pad combo works): when a human's combo state is 3
         * (rear fire) log the fields func_001E4690 / the launcher check, for 20 frames */
        extern char* D_004FA030;
        static int rfFrames, rfHold[8], rfShot[8];
        char* g = D_004FA030;
        int k;
        if (g)
            for (k = 0; k < 8; k++) {
                char* v = g + k * 0x31B0;
                char* c = *(char**)(v + 0x2010);
                if (*(int*)(v + 0x590) != 1 || !c) continue;
                if (*(int*)c == 3) { rfFrames = 90; rfHold[k] = *(int*)(v + 0x21B4) == 1 ? 60 : 0; rfShot[k] = *(int*)(v + 0x2244); }  /* only when the game accepted it (weapon ready) */
                /* Rear fire: state 3 sets the launcher's rear flag (v+0x21B4), which the launcher clears on its own
                 * 21-frame tick, so the fire press has 0..1/3 s to arrive: fine right after the d-pad combo, too
                 * short after L1+Down (let go of L1, then fire). Keep the flag up for 1 s or until a shot. */
                if (rfHold[k] > 0) {
                    if (*(int*)(v + 0x2244) < rfShot[k]) rfHold[k] = 0;    /* fired (time since last shot reset) */
                    else { rfHold[k]--; *(int*)(v + 0x21B4) = 1; rfShot[k] = *(int*)(v + 0x2244); }
                }
                if (TMBR_RFDBG && rfFrames > 0) {
                    rfFrames--;
                    scePrintf("TMBR rf: st %d w %d t2244 %d need %d flag21B4 %d 225C %d A8 %d CC %d 214 %d 27C %d 258 %d pad %d%d%d%d raw %x hold %d\n",
                        *(int*)c, *(int*)(v + 0x21B0), *(int*)(v + 0x2244), *(int*)(v + 0x21B8 + 4 * *(int*)(v + 0x21B0)),
                        *(int*)(v + 0x21B4), *(int*)(v + 0x225C), *(int*)(v + 0x21B0 + 0xA8), *(int*)(v + 0x21B0 + 0xCC),
                        *(int*)(v + 0x21B0 + 0x214), *(int*)(v + 0x21B0 + 0x27C), *(int*)(v + 0x21B0 + 0x258),
                        v[0x594 + 0xD], v[0x594 + 0xE], v[0x594 + 0xF], v[0x5A1], inputGetPadButtons(0), rfHold[k]);
                }
            }
    }
#endif
    cameraUpdate(cam);
#ifdef TMBR_PNACH
    if (!tmbr_en[0]) return;
#endif

    pad = inputGetPadButtons(0);
    b = pad & (IN_SELECT | IN_L3 | IN_R3);
    pressed = b & ~prev_buttons;
    prev_buttons = b;
#ifdef TMBR_FREECAM_ANYTIME
    if ((b & IN_L3) && (pressed & IN_SELECT)) { fc_anytime = !fc_anytime; pressed = 0; }
#endif
    /* Spectating: the dead-player hook (tmbr_spectating) or viewport 0's camera POV = 5 (spectator; cam+0 holds
     * the POV per viewport). Free cam starts OFF; R3 turns it on/off. Select stays the game's (it already does
     * something in the spectator view, so the old Select toggle never got through). */
    {
        int spec = tmbr_spectating || *(int*)cam == 5;
        static int lastSpec = -1, lastPov = -1;
        if (spec != lastSpec || *(int*)cam != lastPov) {
            scePrintf("TMBR freecam: spectating %d (hook %d, pov %d)\n", spec, tmbr_spectating, *(int*)cam);
            lastSpec = spec; lastPov = *(int*)cam;
        }
        if (!spec) fc_on = 0;
        else if (pressed & IN_R3) fc_on = !fc_on;
        if (!((spec && fc_on) || fc_anytime)) { fc_init = 0; return; }
    }
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
