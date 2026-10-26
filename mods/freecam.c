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

/* ---- split-screen stress test (experimental disc): more views, each extra one following another car ----
 * Online never shows more than 1 view, but kept retail's machinery: viewSetNumViews, viewCreate (the viewport
 * layouts retail's gameReestablishViews uses: 2 views 1 / 2 (top / bottom; 0xE is the rear mirror), 4 views
 * 0xA..0xD), the Camera's per-viewport cameras (count at cam+0x43E0, Camera::Init func_00116038 takes each one's cs
 * from viewGetViewCs) and the render loop over the views.
 * tmbr_split[1] = views (0/1 = off, 2, or 3/4 = the 4-way layout like retail's 3 player), set in the ELF by
 * tools/qb/split/splitpatch.py (tmbr_split[0] is its tag). 5 s after the level starts, views 1.. follow the
 * other live cars (bots first); a view whose car is gone moves to the next live one. View 0 stays the player's.
 * Only HUD and input for view 0: this measures the rendering + camera cost of split screen with full bots. */
int tmbr_split[2] = { 0x54494C53, 0 };   /* "SLIT" */
extern void viewSetNumViews(int n) __asm__("viewSetNumViews__Fi");
extern void viewCreate(int vp, int idx) __asm__("func_00242658");
extern void camFollow(char* cam, int i, char* v, void* cs) __asm__("SetCameraToFollowVehicle__6CameraiP7VehicleP3_cs");
extern void camPov(char* cam, int i, int pov) __asm__("SetCameraPOV__6Camerai10_cameraPOV");
extern void camInit(char* cam) __asm__("func_00116038");
extern int tmbr_GuestsWanted(void), tmbr_GuestCount(void);   /* guests.c */
extern void tmbr_GuestsMake(int views), tmbr_GuestsReset(void);
extern int tmbr_levelSerial;
static int splitSerial = -1, splitWait, splitN;
static char* splitCar[4];

/* ---- widescreen (Ark 2026-10-25: the 4:3 picture leaves black bars on a 16:9 screen; PCSX2 only, see TODO) ----
 * Every view gets a 4/3 wider horizontal field of view with the same vertical one, and PCSX2 shows the picture at
 * 16:9 (gamesettings.py: AspectRatio). viewSetFov(view, a, b): a is the projection distance (the function does
 * atan(x / a)), b the vertical scale - a x 3/4 and b x 4/3 (test 2026-10-26: same view of the same car, the
 * picture 4/3 wider, the height the same). Applied 0.5 s after the level starts and when the split-screen views
 * are made (viewCreate resets them).
 * tmbr_wide[1]: 1 on (default), 0 off; tests: 8 = 2 views both on the player, view 1 widened. */
int tmbr_wide[2] = { 0x45444957, 0 };   /* "WIDE" - off by default until the HUD is laid out for 16:9 (2026-10-26: the
                                         * 3D-placed HUD parts moved inward and the online score sat on the weapon list) */
extern void viewSetFov(int i, float a, float b) __asm__("viewSetFov__Fiff");
extern void viewGetFov(int i, float* a, float* b) __asm__("viewGetFov__FiPfT1");
extern int viewGetNumViews(void) __asm__("viewGetNumViews__Fv");
static float KW[2] = { 1.3333333f, 0.75f };
static float wideSet[4];
static void wideApply(int views)
{
    int i;
    for (i = 0; i < views && i < 4; i++) {
        float a, b;
        if (tmbr_wide[1] == 8 && i == 0) continue;
        viewGetFov(i, &a, &b);
        if (a == wideSet[i]) continue;          /* ours already */
        a = a * KW[1]; b = b * KW[0];
        viewSetFov(i, a, b);
        viewGetFov(i, &a, &b);                  /* what the view reports back now (not exactly what was set: the
                                                 * first test re-widened every second - 2026-10-26) */
        wideSet[i] = a;
        scePrintf("TMBR wide: view %d\n", i);
    }
}
static int wideSerial = -1, wideWait;
static void wideFrame(void)
{
    if (!tmbr_wide[1]) return;
    if (wideSerial != tmbr_levelSerial) { wideSerial = tmbr_levelSerial; wideWait = 30; return; }
    if (wideWait > 0 && --wideWait == 0) wideApply(viewGetNumViews());   /* once (re-checking every second widened again
                                                                          * and again: the read-back differs, 2026-10-26) */
}
static void splitFrame(char* cam)
{
    extern char* D_004FA030;
    char* g = D_004FA030;
    int n = tmbr_split[1], i, k;
    if (tmbr_GuestsWanted() && n < tmbr_GuestsWanted() + 1) n = tmbr_GuestsWanted() + 1;
    if (n < 2 || !g) return;
    if (n > 4) n = 4;
    if (splitSerial != tmbr_levelSerial) { splitSerial = tmbr_levelSerial; splitWait = 300; splitN = 0; tmbr_GuestsReset(); { extern void tmbr_GuestsPreload(void); tmbr_GuestsPreload(); } }
    if (splitWait > 0) {
        if (--splitWait) return;
        splitN = n == 2 ? 2 : 4;
        {   /* (debug: the views' projection before and after the split - the HUD's left parts end up off screen) */
            float a0, b0; viewGetFov(0, &a0, &b0);
            scePrintf("TMBR split: 1P fov %d %d\n", (int)(a0 * 1000), (int)(b0 * 1000));
        }
        viewSetNumViews(splitN);
        {
            int pov0 = *(int*)cam;
            if (splitN == 2) { viewCreate(1, 0); viewCreate(2, 1); }
            else for (i = 0; i < 4; i++) viewCreate(0xA + i, i);
            *(int*)(cam + 0x43E0) = splitN;
            camInit(cam);                     /* every camera's cs from its view; resets camera 0 too: */
            for (k = 0; k < 8; k++) {         /* view 0 back on the local player */
                char* c = g + k * 0x31B0;
                if (*(int*)(c + 0x590) == 1 && *(int*)(c + 0x210C) == 0 && *(int*)(c + 0x2028)) {
                    camFollow(cam, 0, c, *(void**)(c + 0x2028));
                    break;
                }
            }
            camPov(cam, 0, pov0);
            tmbr_GuestsMake(splitN);           /* guests: their own camera + HUD through gameInitCamera */
            {   /* guest HUDs: hud[i] (game + 0x97B50 + i * 0xA20) is built for every view (func_00183580 ->
                 * func_001475F8) but skipped while hud+0 is 0; only hud 0 is set up in online. Start the guests' as a
                 * copy of the player's, on their own car (+0x5E4, set by gameInitCamera). */
                char* h0 = g + 0x97B50;
                int gc = tmbr_GuestCount(), q;
                scePrintf("TMBR split: humans %d, hud0 %x %x %x, hud1 %x %x %x\n", *(int*)(g + 0x98000 + 0x7CAC),
                    *(int*)h0, *(int*)(h0 + 4), *(int*)(h0 + 0x5E4), *(int*)(h0 + 0xA20), *(int*)(h0 + 0xA24), *(int*)(h0 + 0xA20 + 0x5E4));
                for (i = 1; i <= gc && i < splitN; i++) {
                    char* h = h0 + i * 0xA20;
                    int car = *(int*)(h + 0x5E4);
                    if (!car) continue;
                    for (q = 0; q < 0xA20 / 4; q++) ((int*)h)[q] = ((int*)h0)[q];
                    *(int*)(h + 0x5E4) = car;
                }
            }
            if (splitN == 2) {
                /* 2 views (test 2026-10-26): the half-height views get a 4/3 narrower horizontal field than the
                 * single view (projection 608 vs 456, the single view is letterboxed wide): the camera looks pulled in
                 * and the HUD parts placed through the projection slide off the left edge. Give them the single
                 * view's horizontal field, same vertical (the widescreen transform: a x 3/4, b x 4/3). */
                for (i = 0; i < 2; i++) {
                    float a, b;
                    viewGetFov(i, &a, &b);
                    viewSetFov(i, a * KW[1], b * KW[0]);
                    viewGetFov(i, &a, &b);
                    wideSet[i] = a;          /* (so widescreen doesn't widen these again) */
                }
            }
            else if (tmbr_wide[1]) wideApply(splitN);
        }
        for (i = 0; i < 4; i++) splitCar[i] = 0;
        {
            extern int D_004CFB98;
            float a0, b0, a1, b1; viewGetFov(0, &a0, &b0); viewGetFov(1, &a1, &b1);
            scePrintf("TMBR split: 2P fov %d %d / %d %d, display mode %d\n", (int)(a0 * 1000), (int)(b0 * 1000), (int)(a1 * 1000), (int)(b1 * 1000), D_004CFB98);
        }
        scePrintf("TMBR split: %d views (asked %d), cs %x %x %x %x\n", splitN, n, *(int*)(cam + 0x42A0), *(int*)(cam + 0x42A4),
            *(int*)(cam + 0x42A8), *(int*)(cam + 0x42AC));
    }
    if (!splitN) return;
    if (tmbr_wide[1] == 8 && !splitCar[1]) {             /* widescreen test: view 1 on the player too */
        for (k = 0; k < 8; k++) {
            char* c = g + k * 0x31B0;
            if (*(int*)(c + 0x590) == 1 && *(int*)(c + 0x2028)) { splitCar[1] = c; camFollow(cam, 1, c, *(void**)(c + 0x2028)); camPov(cam, 1, *(int*)cam); break; }
        }
        return;
    }
    for (i = 1 + tmbr_GuestCount(); i < splitN; i++) {     /* (views 1..guests are the guests') */
        char* v = splitCar[i];
        if (v && *(int*)(v + 0x590) && *(int*)(v + 0x2028)) continue;
        for (k = 0; k < 8; k++) {     /* next live car not shown yet (not the local player: kind 1 is a human) */
            int j, used = 0;
            char* c = g + ((i + k) & 7) * 0x31B0;
            if (*(int*)(c + 0x590) != 2 || !*(int*)(c + 0x2028)) continue;
            for (j = 1; j < splitN; j++) if (splitCar[j] == c) used = 1;
            if (used && k < 7) continue;
            splitCar[i] = c;
            camFollow(cam, i, c, *(void**)(c + 0x2028));
            camPov(cam, i, *(int*)cam);
            scePrintf("TMBR split: view %d follows car %d\n", i, (int)(c - g) / 0x31B0);
            break;
        }
    }
}

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
#ifndef TMBR_PNACH
    splitFrame(cam);
    wideFrame();
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
