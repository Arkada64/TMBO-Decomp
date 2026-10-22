/* TMB-Reloaded mod: choose how many bots (AI cars) play in an online match, in any mode (incl. Last Man Standing).
 * Online's rule (func_001399A8 at game start, func_00176EA0 on joins/leaves, host only, "USE BOTS" on):
 * bots = 3 - humans, at most 2. Its AI list game+0x9E690 has 2 entries.
 * Here: the AI list grows to MAXBOTS entries (into game+0x9E698.., unused online: retail's longer list) and the
 * AI sort list game+0x9FC98 (2 entries, then the level type) moves to game+0x9E6A8 (apply_mods.py patches).
 * Count: tmbr_botCount < 0 = the original rule; otherwise that many bots (capped by free player slots) in every
 * mode, whatever "USE BOTS" says. In the waiting room the host holds R3 and taps R1 / L1 (AUTO, 0..6; shown as a
 * "BOTS" line); the count is kept for the next matches. Bots are made by the game's own code (func_0013A7B8 + func_001756A0), so they are
 * synced to clients as before.
 * Not yet: remote players only see the weapons of bots 1-2 correctly (the net weapon/kill messages encode the
 * owner as -2/-3); bot-vs-bot targeting. */
typedef unsigned int u32;
#define F(p, off) (*(int*)((char*)(p) + (off)))
#define MAXBOTS 6
#define TMBR_BOTDBG 0
#define LIST(g) ((char**)((g) + 0x9E690))
#define SORT(g) ((int*)((g) + 0x9E6A8))
#define NAI(g) F(g, 0x9FEE4)

extern char* D_004FA030;   /* game */
extern char D_003156C0[];  /* net: 8 player slots x 0x220 from +0 */
extern int D_002C07F8[];   /* radar name per character */
extern int scePrintf(const char* fmt, ...);
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern int netIsHost(void* net) __asm__("func_001734B8");
extern int netSlotVehicle(void* net, int slot) __asm__("func_00174268");
extern char* gameMakeAI(char* game, int v, int name, int v2, int cam, int ai) __asm__("func_0013A7B8");
extern int netBotObjects(void* net, char* veh) __asm__("func_001756A0");
extern void weapKill(void* w) __asm__("func_001EFF98");
extern void gameFx(void* p) __asm__("func_00128F48");
extern void vehFlag(int on, int idx) __asm__("func_001FDE10");
extern void vehNetDrop(char* v) __asm__("func_001DC130");
extern void vehicleDisable(char* v) __asm__("vehicleDisable__7Vehicle");
extern void radarName(int slot, int name) __asm__("func_0014ECE8");

int tmbr_botCount = -1;    /* -1: original rule */
int tmbr_botDiff = 1;      /* AI difficulty (game+0x9A3D4) used with a chosen count: 0 easy, 1 medium, 2 hard */
static int prevPad;

static int humans(void)
{
    int i, n = 0;
    for (i = 0; i < 8; i++)
        if (F(D_003156C0 + i * 0x220, 0x214) >= 7 && F(D_003156C0 + i * 0x220, 0xC8) == 0) n++;
    return n;
}

static int wanted(int mid)
{
    u32 cfg = *(u32*)F(D_003156C0, 0x3148);
    int h = humans(), n;
    if (tmbr_botCount < 0) {
        if (!(cfg >> 13 & 1)) return 0;
        if (mid && ((cfg >> 1) & 0xF) == 1) return -1;  /* original: no changes mid-match in that mode */
        n = 3 - h;
        if (n > 2) n = 2;
    } else {
        n = tmbr_botCount;
    }
    if (n > 8 - h) n = 8 - h;
    if (n > MAXBOTS) n = MAXBOTS;
    return n < 0 ? 0 : n;
}

/* AI index of every bot = its list position: vehicle, sort list, brain, net objects, radar */
static void reindex(char* g)
{
    int i;
    for (i = 0; i < NAI(g); i++) {
        char* v = LIST(g)[i];
        SORT(g)[i] = i;
        if (!v) continue;
        if (F(v, 0x2014)) F(F(v, 0x2014), 0x4B4) = i;
        if (F(v, 0x2100) != i) {
            F(v, 0x2100) = i;
            if (F(v, 0x20D8)) *(int*)F(v, 0x20D8) = F(v, 0x20F4) | (i + 1) << 16;
            if (F(v, 0x20D0)) *(char*)(F(v, 0x20D0) + 0x2F) = i;
            if (F(v, 0x20D4)) *(char*)(F(v, 0x20D4) + 0x11) = i;
        }
        radarName(0xA + i, D_002C07F8[F(v, 0x20F4) >> 5]);
    }
}

/* func_00175588 without its 2-bot limit */
static int addBot(void)
{
    char* g = D_004FA030;
    int s, v = 0;
    char* veh;
    if (NAI(g) >= MAXBOTS) return 0;
    for (s = 0; s < 8; s++) {
        if (F(D_003156C0 + s * 0x220, 0x214) != 0) continue;
        v = netSlotVehicle(D_003156C0, s) - 1;
        if (v >= 0 && v < 8 && F(F(g, 0x9E670 + v * 4), 0x20D0) == 0) break;
    }
    if (s == 8) return 0;
    veh = gameMakeAI(g, v, F(D_003156C0 + s * 0x220, 0xB4), v, -1, 1);
    if (!veh) return 0;
    netBotObjects(D_003156C0, veh);
    return 1;
}

/* func_0013EED0 for any number of bots: v = that bot, or 0 = the last one */
char* tmbr_BotRemove(char* g, char* v)
{
    int i, k, n = NAI(g);
    for (k = 0; k < MAXBOTS && LIST(g)[k] != v; k++)
        ;
    if (!v) {
        for (k = MAXBOTS - 1; k >= 0 && !LIST(g)[k]; k--)
            ;
        if (k < 0) { NAI(g) = 0; return 0; }
        v = LIST(g)[k];
    } else {
        char* w = g + 0x68000;
        if (k == MAXBOTS) return 0;
        for (i = 0; i < 200; i++, w += 0x210)
            if (F(w, 0x43C0) && (char*)F(w, 0x44F0) == v) { weapKill(w + 0x43C0); F(w, 0x43C0) = 0; }
        for (i = 0; i < 5; i++) gameFx(g + 0x9A3E0 + i * 0xB30);
        F(v, 0x31A4) = -1;
    }
    for (i = k; i < MAXBOTS - 1; i++) LIST(g)[i] = LIST(g)[i + 1];
    LIST(g)[MAXBOTS - 1] = 0;
    for (i = 0; i < 8; i++)
        if (g + i * 0x31B0 == v) vehFlag(0, i + 1);
    if (F(v, 0x20D0)) *(char*)(F(v, 0x20D0) + 0x2E) = 0;
    F(v, 0x590) = 0;
    vehNetDrop(v);
    vehicleDisable(v);
    F(g, 0x9FD04) = 0;
    if (n > 0) { F(g, 0x9FD00) = 0; NAI(g) = n - 1; }
    reindex(g);
    return v;
}

static void balance(int mid)
{
    char* g = D_004FA030;
    int want = wanted(mid), guard = 8;
    if (want < 0) return;
    while (NAI(g) < want && guard-- && addBot())
        ;
    while (NAI(g) > want && guard-- > 0) tmbr_BotRemove(g, 0);
    reindex(g);
}

/* game start (func_001399A8, host only; replaces the two func_00175588 calls) */
int tmbr_BotsSpawn(void* net, int slot)
{
    if (tmbr_botCount >= 0) F(D_004FA030, 0x9A3D4) = tmbr_botDiff;
    balance(0);
    scePrintf("TMBR bots: start, %d humans, %d bots (setting %d)\n", humans(), NAI(D_004FA030), tmbr_botCount);
    return 1;
}

/* players joined/left (replaces func_00176EA0) */
void tmbr_BotsRebalance(void* net)
{
    if (!netIsHost(D_003156C0) || F(D_003156C0, 0x1BB4) != 0xB) return;
    balance(1);
    scePrintf("TMBR bots: rebalance, %d humans, %d bots\n", humans(), NAI(D_004FA030));
}

/* ---- free-for-all brains (only when the host picked a number, AUTO = original behaviour) ----
 * The original only lets bots hunt humans (func_00130E88 mode 5 picks the nearest net player; new bots start
 * aimed at vehicle 0 = the host: the dogpile). Every half second each bot hunts the nearest other live car,
 * bot or human (sticky unless something is clearly closer). The driver plans its route with the target's
 * attractor group game+0x9FD40[target AI/human index], which only holds humans' groups: tmbr_AiUpdate
 * (hooked over vehicleUpdate's call of the AI frame) puts the bot target's own group there for the frame. */
extern void driverSetMode(char* drv, int mode) __asm__("func_00130E88");
extern void driverSetTarget(char* drv, char* target) __asm__("func_00130C00");
extern int attractGroupAt(void* points, void* pos) __asm__("func_0010B950");
extern float manhat(void* a, void* b) __asm__("mathfManhatDist__FP8_fvectorT0");
static int thinkTick;
#define SPECIAL_CHANCE 35 /* % of the time a bot may pick its special when it chooses a weapon (FFA) */

#define POS(v) ((void*)(F(v, 0x2028) + 0x10))
static int live(char* v) { return (F(v, 0x590) == 1 || F(v, 0x590) == 2) && F(v, 0x2028); }

void tmbr_BotsThink(void)
{
    char* g = D_004FA030;
    int i, k;
    if (tmbr_botCount < 0 || !g || NAI(g) <= 0 || ++thinkTick % 30) return;
    if (!netIsHost(D_003156C0)) return;
    F(g, 0x9A3D4) = tmbr_botDiff;   /* AI difficulty: 0 (online's value) never lets a bot line up a normal shot */
    for (i = 0; i < NAI(g); i++) {
        char *b = LIST(g)[i], *drv, *cur, *best = 0;
        int d, bestD = 0x7FFFFFF, curD = -1;   /* ints: float literals would need .lit4 (gp) */
        if (!b || !live(b) || !(drv = (char*)F(b, 0x2018))) continue;
        cur = (char*)F(drv, 0xB4);
        for (k = 0; k < 8; k++) {
            char* v = g + k * 0x31B0;
            if (v == b || !live(v)) continue;
            d = (int)manhat(POS(b), POS(v));
            if (v == cur) curD = d;
            if (d < bestD) { bestD = d; best = v; }
        }
        if (!best) continue;
        if (curD >= 0 && curD * 2 < bestD * 3) best = cur;  /* keep fighting unless clearly closer */
        if (F(drv, 4) != 5) driverSetMode(drv, 5);
        if ((char*)F(drv, 0xB4) != best) driverSetTarget(drv, best);
    }
    /* debug: per-bot state every 2 s (TMBR_BOTDBG) */
    if (TMBR_BOTDBG && thinkTick % 120 == 0)
        for (i = 0; i < NAI(g) && i < MAXBOTS; i++) {
            char *b = LIST(g)[i], *br, *dv, *t;
            if (!b || !(br = (char*)F(b, 0x2014)) || !(dv = (char*)F(b, 0x2018))) continue;
            t = (char*)F(dv, 0xB4);
            scePrintf("TMBR botdbg %d: mode %d tgt %x(%d) dist %d ang %d | atk %d ok60C %d grp270 %d noLos %d see598 %d wpn %d drv %d/%d/%d diff %d tgt49B %d tgt496 %d\n",
                i, F(dv, 4), (u32)t, t ? F(t, 0x590) : -1, (int)*(float*)(br + 0x20), (int)(*(float*)(br + 0x28) * 100),
                F(br, 0x414), F(br, 0x60C), F(dv, 0x270), F(br, 0x4B0), F(br, 0x598), F(br, 0x47C),
                F(dv, 0x250), F(dv, 0x254), F(dv, 0x258), F(g, 0x9A3D4), t ? *(char*)(t + 0x49B) : -1, t ? *(char*)(t + 0x496) : -1);
        }
}

/* The whole AI frame (func_00101F88, called from vehicleUpdate) reads the target's attractor group as
 * game+0x9FD40[target AI/human index] (aiOkToHuntUsingLOS, func_0012E798, ...), which only holds humans'
 * groups: for a bot target put its own group there for the duration of the frame. */
extern int aiFrame(char* v) __asm__("func_00101F88");

/* Handbrake turns. Left alone, a bot whose target is off to the side brakes and slowly swings round
 * (func_00102948), and only AI 0 ever pulls the handbrake (func_00130D68 checks aiOrPlayerIdx == 0, and only
 * past 120 deg). With a chosen count, after the AI frame has written its pad bytes (vehicle+0x594, read by the
 * physics later in the frame): when a hunting bot is in its attack states, the target is near and 40..150 deg
 * off the nose, pull the handbrake (pad[2]), steer hard toward it and stay on the gas. Bursts of at most
 * HB_HOLD frames then HB_REST frames of normal driving, so it whips round instead of spinning in place.
 * Floats are compared as bit patterns (no .lit4 literals): positive IEEE floats order like ints. */
#define PAD(v) ((unsigned char*)(v) + 0x594)
#define HB_MIN  0x3F333333   /* 0.7 rad, ~40 deg */
#define HB_MAX  0x40266666   /* 2.6 rad, ~150 deg (beyond that the AI's own rear/reverse logic is better) */
#define HB_DIST 0x43FA0000   /* 500.0 */
#define HB_HOLD 18
#define HB_REST 40
static signed char hbTimer[8];
static int fbits(float f) { union { float f; int i; } u; u.f = f; return u.i; }

static void aggressiveTurn(char* g, char* v, char* t)
{
    char* br = (char*)F(v, 0x2014);
    char* drv = (char*)F(v, 0x2018);
    unsigned char* pad = PAD(v);
    int idx = (int)(v - g) / 0x31B0, st, b, a, d;
    if (idx < 0 || idx > 7 || !br || !drv) return;
    if (hbTimer[idx] < 0) { hbTimer[idx]++; return; }           /* resting */
    st = F(br, 0x414);
    b = fbits(*(float*)(br + 0x24));
    a = b & 0x7FFFFFFF;
    d = fbits(*(float*)(br + 0x20));
    if (F(drv, 4) != 5 || st < 4 || st > 7 || F(v, 0x444) >= 60 || d < 0 || d > HB_DIST || a < HB_MIN || a > HB_MAX) {
        if (hbTimer[idx] > 0) hbTimer[idx] = -HB_REST;          /* a burst just ended */
        return;
    }
    if (++hbTimer[idx] > HB_HOLD) { hbTimer[idx] = -HB_REST; return; }
    pad[2] = 1;                                                 /* handbrake */
    if (b > 0) { pad[0xA] = 1; pad[9] = 0; } else { pad[9] = 1; pad[0xA] = 0; }  /* bearing > 0 = right */
    pad[4] = 1; pad[6] = 0; pad[8] = 0;                         /* gas, no brake */
}

int tmbr_AiUpdate(char* v)
{
    char* g = D_004FA030;
    char* drv = (char*)F(v, 0x2018);
    char* t = drv ? (char*)F(drv, 0xB4) : 0;
    int k, save = 0, swap, r;
    if (tmbr_botCount < 0 || !t || !F(t, 0x2028)) return aiFrame(v);
    swap = F(t, 0x590) == 2;
    k = F(t, 0x2100) & 7;
    if (swap) {
        save = F(g, 0x9FD40 + k * 4);
        F(g, 0x9FD40 + k * 4) = attractGroupAt(g + 0x30970, POS(t));
    }
    r = aiFrame(v);
    if (swap) F(g, 0x9FD40 + k * 4) = save;
    aggressiveTurn(g, v, t);
    return r;
}

/* Weapon choice (attack state 1, func_00106440): with the fairness gate gone for bot targets, specials would
 * dominate; let a bot take its special only SPECIAL_CHANCE % of the times it is offered. */
extern int aiGoodWeapon(char* v, int w) __asm__("aiGoodWeaponToPick__7Vehiclei");
extern int mathfRand(int lo, int hi) __asm__("mathfRand__Fii");
int tmbr_AiGoodWeapon(char* v, int w)
{
    if (tmbr_botCount >= 0 && w == 1 && mathfRand(0, 99) >= SPECIAL_CHANCE) return 0;
    return aiGoodWeapon(v, w);
}

/* Fairness gate (aiLineUpShot, func_00106D50, func_00107048): a bot only fires a normal weapon when its target
 * "looks at it" (angle of the target's heading toward the bot, scaled by the bot's state). Fine against humans;
 * two bots circling each other almost never both qualify, so after the opening head-on pass they only fire
 * specials. With a chosen count, a bot target is always fair game. */
extern int aiFairToShoot(char* v) __asm__("aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle");
int tmbr_AiMayShoot(char* v)
{
    char* drv = (char*)F(v, 0x2018);
    char* t = drv ? (char*)F(drv, 0xB4) : 0;
    if (tmbr_botCount >= 0 && t && F(t, 0x590) == 2) return 1;
    return aiFairToShoot(v);
}

extern void lobbyFrame(void) __asm__("func_001C5768");
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern int sprintf(char* d, const char* f, ...);

/* waiting room (func_001B2B68 -> func_001C5768 every frame): host hotkeys R3 + R1/L1 and a "BOTS" line.
 * Count steps AUTO (original rule) -> 0 .. MAXBOTS. */
void tmbr_LobbyFrame(void)
{
    int pad = 0, pressed;
    char buf[48];
    lobbyFrame();
    if (!netIsHost(D_003156C0)) return;
    pad = inputGetPadButtons(0) & 0xF04;  /* raw pad, active high: R3 0x4, L2 0x100, R2 0x200, L1 0x400, R1 0x800 */
    pressed = pad & ~prevPad;
    prevPad = pad;
    if ((pad & 0x4) && (pressed & 0xF00)) {
        if (pressed & 0x800) tmbr_botCount++;
        if (pressed & 0x400) tmbr_botCount--;
        if (pressed & 0x200) tmbr_botDiff++;
        if (pressed & 0x100) tmbr_botDiff--;
        if (tmbr_botCount < -1) tmbr_botCount = -1;
        if (tmbr_botCount > MAXBOTS) tmbr_botCount = MAXBOTS;
        if (tmbr_botDiff < 0) tmbr_botDiff = 0;
        if (tmbr_botDiff > 2) tmbr_botDiff = 2;
        scePrintf("TMBR bots: lobby setting %d, difficulty %d\n", tmbr_botCount, tmbr_botDiff);
    }
    if (tmbr_botCount < 0) sprintf(buf, "BOTS : AUTO  (R3 + L1/R1)");
    else sprintf(buf, "BOTS : %d  %s  (R3 + L1/R1, L2/R2)", tmbr_botCount,
        tmbr_botDiff == 0 ? "EASY" : tmbr_botDiff == 1 ? "MEDIUM" : "HARD");
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 10 * 0x100);
    fontPrint(0, buf);
}
