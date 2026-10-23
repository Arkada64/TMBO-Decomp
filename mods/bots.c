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
#ifndef TMBR_NAV
#define TMBR_NAV 1
#endif
#define LIST(g) ((char**)((g) + 0x9E690))
#define SORT(g) ((int*)((g) + 0x9E6A8))
#define NAI(g) F(g, 0x9FEE4)

extern char* D_004FA030;   /* game */
extern int tmbr_levelIndex;  /* packs.c */
extern char D_003156C0[];  /* net: 8 player slots x 0x220 from +0 */
extern int D_002C07F8[];   /* radar name per character */
extern int scePrintf(const char* fmt, ...);
extern int mathfRandI(int lo, int hi) __asm__("mathfRand__Fii");
extern void pickCruiseZone(char* g, char* v, int i) __asm__("gamePickCruiseZone__7TheGameP7Vehiclei");
extern int tmbr_NavDrive(char* g, char* v, char* t);   /* nav.c */
extern void tmbr_NavFrame(void);
extern unsigned int tmbr_Cycles(void);              /* perf.c */
extern void tmbr_PerfAdd(int slot, unsigned int start);
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

int tmbr_BotsPlanned(void) { return F(D_003156C0, 0x3148) ? wanted(0) : 0; }

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
    tmbr_TeamsBotJoined(s, (int)(veh - g) / 0x31B0);
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
    tmbr_TeamsBotLeft(v);
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
/* Synchronous entry (game info bit 5): everyone loads the level at the same time and waits on the scoreboard
 * screen (net state 0xA) until every player has loaded (client +0x214 == 0xA); then the host sets game info
 * bit 0 and goes to state 0xB (func_00138C90 0x138FD8). Bots made at the host's game start went out while the
 * others were still loading. So in that mode the host makes them at the go instead (tmbr_SyncGo, hooked over
 * that state change): everyone is loaded and still held. It keeps the hold SYNC_HOLD more frames so the bots
 * reach every machine, then lets the match start. Bots are frozen while held (tmbr_AiUpdate). */
#define SYNC_HOLD 90
static int syncPending, syncHold;
static int syncEntry(void) { return F(D_003156C0, 0x3148) && (*(u32*)F(D_003156C0, 0x3148) >> 5 & 1); }
extern void netSetState(void* net, int state) __asm__("func_00173570");
void tmbr_SyncGo(void* net, int state)
{
    char* gi = (char*)F(D_003156C0, 0x3148);
    if (syncPending) {
        syncPending = 0;
        balance(0);
        syncHold = NAI(D_004FA030) > 0 ? SYNC_HOLD : 0;
        scePrintf("TMBR bots: everyone loaded, %d humans, %d bots, hold %d\n", humans(), NAI(D_004FA030), syncHold);
    }
    if (syncHold > 0) {
        syncHold--;
        if (gi) F(gi, 0) &= ~1;            /* not started yet (set just before this call) */
        return;
    }
    netSetState(net, state);
}
int tmbr_BotsSpawn(void* net, int slot)
{
    if (tmbr_botCount >= 0) F(D_004FA030, 0x9A3D4) = tmbr_botDiff;
    syncHold = 0;
    if (syncEntry()) {
        syncPending = 1;
        scePrintf("TMBR bots: synchronous entry, bots when everyone has loaded\n");
        return 1;
    }
    syncPending = 0;
    balance(0);
    scePrintf("TMBR bots: start, %d humans, %d bots (setting %d)\n", humans(), NAI(D_004FA030), tmbr_botCount);
    return 1;
}

/* players joined/left (replaces func_00176EA0) */
void tmbr_BotsRebalance(void* net)
{
    if (!netIsHost(D_003156C0) || (F(D_003156C0, 0x1BB4) != 0xB && F(D_003156C0, 0x1BB4) != 0xA) || syncPending || syncHold > 0) return;
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
/* Roles (by AI index, so 3 bots get one of each): brawler = closest target, gets in close (dogfight);
 * sniper = targets ~450 away, holds a 250..550 band and backs off when rushed; roamer = picks the most
 * isolated car nobody else is on, fights like a brawler. Spreads the bots out instead of one mosh pit. */
#define R_BRAWLER 0
#define R_SNIPER 1
#define R_ROAMER 2
#define R_CRUISER 3    /* drives the map (game cruise mode 4) and fights whatever it runs into */
#define CRUISE_SEE 350
/* sight range per role (manhattan units): beyond it a bot cruises instead of crossing the map to a fight */
#define HUNT_SEE(rl) ((rl) == R_CRUISER ? CRUISE_SEE : (rl) == R_SNIPER ? 1000 : (rl) == R_ROAMER ? 1200 : 900)
#define ROLE(v) (role[((int)((char*)(v) - D_004FA030) / 0x31B0) & 7])
static int hunted[8], crowd[8];
/* health in percent (vehicle+0x404 health, +0x3F0 max; floats, converted without float literals) */
static int hpPct(char* v)
{
    int h = (int)*(float*)(v + 0x404), m = (int)*(float*)(v + 0x3F0);
    if (m <= 0) return 100;
    if (h < 0) h = 0;
    return h * 100 / m;
}
static short shieldT[8];
static signed char retreated[8];  /* already retreated this life */         /* frames a bot has been under its respawn shield */
static signed char role[8];          /* by vehicle index */
static short roleT[8], rushT[8];
static short fightT[8], leaveT[8];  /* think ticks (0.5 s) in a fight / left of a breakaway */

/* Roles change during the match: every 15..40 s a bot rolls a new one (brawler 30 %, sniper 15 %, roamer
 * 20 %, cruiser 35 %, re-rolled once if every other bot already has it), and a sniper that keeps getting caught up close
 * (target < 150 for 3 s) turns brawler on the spot. */
/* Cruise to an empty part of the map: gamePickCruiseZone picks the nearest candidate zone, or the farthest when
 * the driver is in flee mode (3); so pick with the mode set to 3 for that one call, then cruise (4). */
static void cruiseFar(char* g, char* b, char* drv)
{
    if (F(drv, 4) != 4) driverSetMode(drv, 4);
    F(drv, 4) = 3;
    pickCruiseZone(g, b, 0);
    F(drv, 4) = 4;
}

static void rollRole(char* g, int k)
{
    int r = mathfRandI(0, 99), n = r < 30 ? R_BRAWLER : r < 45 ? R_SNIPER : r < 65 ? R_ROAMER : R_CRUISER, i, same = 0, bots = 0;
    for (i = 0; i < NAI(g); i++) {
        char* b = LIST(g)[i];
        int j;
        if (!b || (j = (int)(b - g) / 0x31B0) == k || j < 0 || j > 7) continue;
        bots++;
        if (role[j] == n) same++;
    }
    if (bots && same == bots) n = (n + 1 + mathfRandI(0, 2)) % 4;
    role[k] = n;
    roleT[k] = 30 + mathfRandI(0, 50);
    rushT[k] = 0;
    if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d role %s\n", k, n == R_BRAWLER ? "brawler" : n == R_SNIPER ? "sniper" : n == R_ROAMER ? "roamer" : "cruiser");
}
static int dbgCalls[8], dbgHb[8], dbgWhy[8], dbgShots[8];   /* TMBR_BOTDBG: AI frames seen by the hook, handbrake frames */
static int dbgBits(float f) { union { float f; int i; } u; u.f = f; return u.i; }
#define SPECIAL_CHANCE 50 /* % of the time a bot may pick its special when it chooses a weapon (FFA) */

#define POS(v) ((void*)(F(v, 0x2028) + 0x10))
static int live(char* v) { return (F(v, 0x590) == 1 || F(v, 0x590) == 2) && F(v, 0x2028); }

/* ---- lobby options, shared through the game info (the net object the host sends to every machine, 0xC8 bytes,
 * func_00174988). Byte +0xC6 is unused by the game: TMBR flags, bit 0 traffic on, bit 1 teams. Word 0 bit 12 is
 * the game's own (cut) "teams on" switch: with it lock-on skips teammates (func_0015A650), radar blips and car
 * markers use team colours, teammate damage is not credited. Team of a player = client struct +0x14
 * (D_003156C0 + slot*0x220), never set or sent by the game: every machine sets slot & 1 for all 8 slots, so no
 * sync is needed. Bots: same rule by their vehicle's slot (+0x20C0), logged at match start. */
#define GINFO() (*(char**)(D_003156C0 + 0x3148))
#define OPT_TRAFFIC 1      /* traffic ON (off by default) */
#define OPT_TEAMS 2
extern void netSendGameInfo(void* net, int to) __asm__("func_00174988");
extern int tmbr_levelSerial;
int tmbr_Opt(int bit)
{
    char* gi = GINFO();
    return gi && (gi[0xC6] & bit);
}
static void optSync(int flip)
{
    char* gi = GINFO();
    int want, has;
    if (!gi) return;
    gi[0xC6] ^= flip;
    want = (gi[0xC6] & OPT_TEAMS) != 0;
    has = (F(gi, 0) >> 12) & 1;
    if (want != has) F(gi, 0) ^= 0x1000;   /* the mode presets clear it: put it back */
    if (flip || want != has) netSendGameInfo(D_003156C0, -1);
}
extern int tmbr_TeamOf(char* v);         /* teams.c */
extern void tmbr_TeamsFrame(void);
extern void tmbr_TeamsLobby(char* lineA, char* lineB);
extern void tmbr_TeamsBotJoined(int slot, int car);
extern void tmbr_TeamsBotLeft(char* v);

void tmbr_BotsThink(void)
{
    char* g = D_004FA030;
    int i, k;
    if (g) tmbr_TeamsFrame();
    if (tmbr_botCount < 0 || !g || NAI(g) <= 0 || !netIsHost(D_003156C0)) return;
#if TMBR_NAV
    tmbr_NavFrame();
#endif
    if (++thinkTick % 30) return;
    F(g, 0x9A3D4) = tmbr_botDiff;   /* AI difficulty: 0 (online's value) never lets a bot line up a normal shot */
    /* how many bots hunt each car, how crowded each car is */
    for (k = 0; k < 8; k++) { hunted[k] = 0; crowd[k] = 0; }
    for (i = 0; i < NAI(g); i++) {
        char *b = LIST(g)[i], *dv, *t;
        if (b && live(b) && (dv = (char*)F(b, 0x2018)) && (t = (char*)F(dv, 0xB4))) {
            k = (int)(t - g) / 0x31B0;
            if (k >= 0 && k < 8) hunted[k]++;
        }
    }
    for (k = 0; k < 8; k++) {
        char* v = g + k * 0x31B0;
        int j;
        if (!live(v)) continue;
        for (j = 0; j < 8; j++)
            if (j != k && live(g + j * 0x31B0) && (int)manhat(POS(v), POS(g + j * 0x31B0)) < 400) crowd[k]++;
    }
    for (i = 0; i < NAI(g); i++) {
        char *b = LIST(g)[i], *drv, *cur, *best = 0;
        int d, sc, bestS = 0x7FFFFFF, curS = -1, rl, ci = -1;   /* ints: float literals would need .lit4 (gp) */
        if (!b || !live(b) || !(drv = (char*)F(b, 0x2018))) continue;
        if (*(signed char*)(b + 0x497) >= 4) continue;   /* respawn shield: cruising (tmbr_AiUpdate) */
        cur = (char*)F(drv, 0xB4);
        {
            int k2 = (int)(b - g) / 0x31B0 & 7;
            if (--roleT[k2] <= 0) rollRole(g, k2);
            if (role[k2] == R_SNIPER && cur && (int)manhat(POS(b), POS(cur)) < 150) {
                if (++rushT[k2] >= 6) { role[k2] = R_BRAWLER; roleT[k2] = 30 + mathfRandI(0, 30);
                    if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d sniper rushed -> brawler\n", k2); }
            } else rushT[k2] = 0;
        }
        rl = ROLE(b);
        {
            /* Breakaway: like players leaving a brawl, a bot that has been fighting for a while, or is in a
             * pile-up (3+ other cars within 400), may drive off for 8-15 s (game cruise mode, ignores targets)
             * and come back fresh. Checked every 0.5 s: after 20 s of fighting 10 %, in a pile-up 6 %. */
            int k2 = (int)(b - g) / 0x31B0 & 7, pile = crowd[k2] >= 3, retreat;
            if (leaveT[k2] > 0) {
                leaveT[k2]--;
                if (F(drv, 4) != 4) cruiseFar(g, b, drv);
                continue;
            }
            if (cur && (int)manhat(POS(b), POS(cur)) < 600) fightT[k2]++; else fightT[k2] = 0;
            /* retreat: hurt (< 35 %) and two or more cars on it -> break away (25 % per check) */
            /* online has no health to recover, so a retreat is short (8-15 s) and once per life */
            if (hpPct(b) >= 90) retreated[k2] = 0;
            retreat = !retreated[k2] && hpPct(b) < 35 && hunted[k2] >= 2 && mathfRandI(0, 99) < 25;
            if (retreat) retreated[k2] = 1;
            if (retreat || (fightT[k2] > 40 && mathfRandI(0, 99) < 10) || (pile && fightT[k2] > 6 && mathfRandI(0, 99) < 15)) {
                leaveT[k2] = 16 + mathfRandI(0, 14);
                fightT[k2] = 0;
                cruiseFar(g, b, drv);       /* to the far side of the map: spreads the bots out */
                if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d breaks away (%s)\n", k2, pile ? "pile-up" : "long fight");
                continue;
            }
        }
        if (cur) ci = (int)(cur - g) / 0x31B0;
        for (k = 0; k < 8; k++) {
            char* v = g + k * 0x31B0;
            int others;
            if (v == b || !live(v)) continue;
            if (tmbr_Opt(OPT_TEAMS) && tmbr_TeamOf(v) == tmbr_TeamOf(b)) continue;   /* teammate */
            d = (int)manhat(POS(b), POS(v));
            others = hunted[k] - (k == ci);              /* other bots already on it */
            if (rl == R_CRUISER) sc = d;
            else if (rl == R_SNIPER) sc = (d > 450 ? d - 450 : 450 - d) + others * 250;    /* likes 450 away */
            else if (rl == R_ROAMER) sc = d / 2 + others * 600 + crowd[k] * 500;      /* lone targets */
            else sc = d + others * 200 + crowd[k] * 150;                                  /* brawler (avoids pile-ups) */
            sc -= (100 - hpPct(v)) * (rl == R_CRUISER ? 1 : 3);   /* finish off damaged cars (up to -300) */
            if (v == cur) curS = sc;
            if (sc < bestS) { bestS = sc; best = v; }
        }
        if (!best) continue;
        if (curS >= 0 && curS * 2 < bestS * 3) best = cur;  /* keep fighting unless clearly better */
        {
            /* Every role only hunts what is within its sight range; past that it cruises the map instead of
             * driving to wherever everyone else is (on big maps the whole match ended up in one spot).
             * Once hunting, it follows the target out to 1.5x the range before letting it go. */
            int bd = (int)manhat(POS(b), POS(best)), see = HUNT_SEE(rl);
            if (bd > (rl == R_CRUISER ? see * 2 : see * 3 / 2) || (F(drv, 4) == 4 && bd > see)) {
                if (F(drv, 4) != 4) {
                    if (mathfRandI(0, 1)) cruiseFar(g, b, drv);
                    else driverSetMode(drv, 4);
                }
                continue;
            }
        }
        if (F(drv, 4) != 5) driverSetMode(drv, 5);
        if ((char*)F(drv, 0xB4) != best) driverSetTarget(drv, best);
    }
    /* debug: per-bot state every 2 s (TMBR_BOTDBG) */
    if (TMBR_BOTDBG && thinkTick % 120 == 0)
        for (i = 0; i < NAI(g) && i < MAXBOTS; i++) {
            char *b = LIST(g)[i], *br, *dv, *t;
            if (!b || !(br = (char*)F(b, 0x2014)) || !(dv = (char*)F(b, 0x2018))) continue;
            t = (char*)F(dv, 0xB4);
            {
                int vi = (int)(b - g) / 0x31B0 & 7;
                unsigned char* pd = (unsigned char*)b + 0x594;
                scePrintf("TMBR botdbg %d: mode %d tgt %x(%d) dist %d brg %08x | atk %d tmr %d ok %d grp %d noLos %d see %d stuck %d diff %d | calls %d hb %d shots %d why %d pad %d%d%d%d%d%d\n",
                    i, F(dv, 4), (u32)t, t ? F(t, 0x590) : -1, (int)*(float*)(br + 0x20), dbgBits(*(float*)(br + 0x24)),
                    F(br, 0x414), F(br, 0x488), F(br, 0x60C), F(dv, 0x270), F(br, 0x4B0), F(br, 0x598), F(b, 0x444),
                    F(g, 0x9A3D4), dbgCalls[vi], dbgHb[vi], dbgShots[vi], dbgWhy[vi], pd[2], pd[4], pd[6], pd[8], pd[9], pd[0xA]);
            }
        }
}

/* The whole AI frame (func_00101F88, called from vehicleUpdate) reads the target's attractor group as
 * game+0x9FD40[target AI/human index] (aiOkToHuntUsingLOS, func_0012E798, ...), which only holds humans'
 * groups: for a bot target put its own group there for the duration of the frame. */
extern int aiFrame(char* v) __asm__("func_00101F88");
extern void hierSetSwitch(void* sw, int i) __asm__("hierSetSwitch__FP11_hierswitchi");
extern void shieldSoundStop(void* snd) __asm__("func_001957E0");
/* end the shield the way func_001DD0C8 does (that only ends it for humans by timer, bots by byte 0x498):
 * clearing byte 0x497 alone left the shield effect on the car forever */
static void shieldOff(char* v)
{
    F(v, 0x464) = 0;
    *(signed char*)(v + 0x497) = 0;
    hierSetSwitch((void*)F(v, 0x2068), 0);
    hierSetSwitch((void*)F(v, 0x206C), 0);
    shieldSoundStop(v + 0x2F50);
}

/* Combat steering. The log (Ark, 2026-10-22) showed bots parked in attack state 6 (aiLineUpShot) for 20+ s
 * at 20-300 units from their target, braking with no steer: state 6 waits for brain->aimed (target within
 * 35 deg ahead) and never times out, while the hunt driving at close range only brakes. And the original only
 * lets AI 0 pull the handbrake (func_00130D68 checks aiOrPlayerIdx == 0, past 120 deg).
 * After the AI frame has written its pad bytes (vehicle+0x594, read by the physics later in the frame), when
 * a hunting bot's target is within CS_DIST: gas on, no brake (the AI's close-range driving brakes to a halt);
 * more than CS_AIM off the nose: steer hard toward it; past CS_HB pull the handbrake (pad[2]) in bursts of HB_HOLD
 * frames with HB_REST frames between, so it whips round instead of spinning. Inside CS_AIM the AI aims.
 * Watchdog: state 6 for more than STALL frames goes back to weapon choice (state 1).
 * Floats are compared as bit patterns (no .lit4 literals): positive IEEE floats order like ints. */
#define PAD(v) ((unsigned char*)(v) + 0x594)
#define CS_AIM  0x3EB33333   /* 0.35 rad, ~20 deg */
#define CS_HB   0x3F333333   /* 0.7 rad, ~40 deg */
#define CS_DIST 0x44160000   /* 600.0 */
#define HB_HOLD 24
#define HB_REST 20
#define STALL 240
#define TURBO_FAR 0x43C80000  /* 400.0: lined up and this far away -> turbo in */
#define FIRE_ANG 0x3F19999A   /* 0.6 rad, ~34 deg */
#define FIRE_DIST 0x43FA0000  /* 500.0 */
#define CS_PIVOT 0x3F800000  /* 1.0 rad, ~57 deg */
#define REVERSE 40
#define DF_CLOSE 0x42F00000  /* 120.0: closer than this with the target way off the nose = overshoot */
#define DF_ROOM 0x43480000   /* 200.0: enough room to swing back */
#define DF_LINED 0x3E99999A  /* 0.3 rad: the target's nose points at us (brain+0x28) */
#define DF_EXT 50
#define DF_REV 0x42700000   /* 60.0 */
#define SN_MIN 0x43480000    /* 200.0 */
#define SN_FAR 0x43AF0000    /* 350.0 */
#define SN_MAX 0x440C0000    /* 560.0 */
#define SN_BEHIND 0x40200000 /* 2.5 rad */
#define DF_SWING 30
static signed char ph[8];
static short phT[8];
static signed char hbTimer[8];
static int fbits(float f) { union { float f; int i; } u; u.f = f; return u.i; }
extern void aiSetAttackState(char* v, int st) __asm__("aiSetAttackState__7Vehicle12_attackState");

static void aggressiveTurn(char* g, char* v, char* t)
{
    char* br = (char*)F(v, 0x2014);
    char* drv = (char*)F(v, 0x2018);
    unsigned char* pad = PAD(v);
    int idx = (int)(v - g) / 0x31B0, st, b, a, d, tf;
    if (idx < 0 || idx > 7 || !br || !drv) return;
    st = F(br, 0x414);
    b = fbits(*(float*)(br + 0x24));
    a = b & 0x7FFFFFFF;
    d = fbits(*(float*)(br + 0x20));
    tf = fbits(*(float*)(br + 0x28)) & 0x7FFFFFFF;
    if (hbTimer[idx] < 0) hbTimer[idx]++;
    if (st == 6 && F(br, 0x488) > STALL) { dbgWhy[idx] = 4; aiSetAttackState(v, 1); return; }
    if (F(drv, 4) != 5) { dbgWhy[idx] = 10 + F(drv, 4); return; }
    /* Trigger-happy: the original only fires once aiLineUpShot is satisfied (aimed within 35 deg, per-weapon
     * bearing / pitch / range, fairness gate), so in a moving fight state 7 almost never comes (1 sample in
     * 600 in Ark's log). Most weapons home: fire when roughly lined up, in range, and in sight. */
    if ((st == 5 || st == 6) && a < FIRE_ANG && d >= 0 && d < FIRE_DIST && (F(br, 0x598) || F(br, 0x4B0) < 10)) {
        aiSetAttackState(v, 7); dbgShots[idx]++;
    }
    if (F(v, 0x444) >= 60) { dbgWhy[idx] = 3; return; }        /* stuck: the AI's own reverse/turn */
    if (d < 0 || d > CS_DIST) { dbgWhy[idx] = 5; ph[idx] = 0; return; }
    pad[4] = 1; pad[6] = 0; pad[8] = 0;                         /* in a fight: stay on the gas */
    if (ph[idx] == 1 || ph[idx] == 4 || (a < CS_AIM && d > TURBO_FAR)) pad[7] = 1;   /* turbo: extend, run, close in */
    if (ROLE(v) == R_SNIPER) {
        /* sniper: rushed (< SN_MIN) -> run (target behind us) until SN_FAR, then swing round; in the band,
         * coast so it lingers and shoots; beyond the band, the attack logic below closes in */
        if (ph[idx] == 4) {
            if (d > SN_FAR) { ph[idx] = 2; phT[idx] = 0; }
            else {
                pad[2] = 0; pad[9] = 0; pad[0xA] = 0;
                if (a < SN_BEHIND) { if (b > 0) pad[9] = 1; else pad[0xA] = 1; }  /* turn away */
                else if (tf < DF_LINED) { if ((thinkTick / 12) & 1) pad[9] = 1; else pad[0xA] = 1; }
                dbgWhy[idx] = 30;
                return;
            }
        } else if (d < SN_MIN && ph[idx] == 0) { ph[idx] = 4; return; }
        else if (d < SN_MAX && a < CS_HB && (thinkTick & 3) == 0) pad[4] = 0;  /* in the band, roughly facing: ease off (gas 3 of 4 frames; full coasting crawled) */
    }
    if (a < CS_AIM && ph[idx] != 1 && ph[idx] != 4) { dbgWhy[idx] = 6; ph[idx] = 0; return; }               /* nearly lined up: the AI aims */
    /* ---- dogfight: like PvP, keep speed and fight for the angle ----
     * phase 0 attack: gas, steer at the target, handbrake bursts past CS_HB (as before).
     * Target far off the nose (> CS_PIVOT): if it is close (< DF_CLOSE) we overshot, so EXTEND: drive on,
     * wheel straight, weaving if the target has us lined up, until there is room (> DF_ROOM) or DF_EXT frames;
     * then SWING: gas + handbrake + full lock (a high-speed handbrake turn) until the nose is within CS_HB or
     * DF_SWING frames. A swing that did not bring the nose round goes to REVERSE (3-point turn) once. */
    dbgWhy[idx] = 7;
    if (ph[idx] == 3) {                                         /* reverse out */
        if (--phT[idx] <= 0) ph[idx] = 0;
        pad[4] = 0; pad[8] = 0; pad[6] = 1; pad[2] = 0;
        if (b > 0) { pad[9] = 1; pad[0xA] = 0; } else { pad[0xA] = 1; pad[9] = 0; }
        dbgWhy[idx] = 9;
        return;
    }
    if (ph[idx] == 1) {                                         /* extend */
        pad[2] = 0; pad[9] = 0; pad[0xA] = 0;
        if (tf < DF_LINED) {                                    /* they have us lined up: jink */
            if ((phT[idx] / 12) & 1) pad[9] = 1; else pad[0xA] = 1;
        }
        dbgWhy[idx] = 20;
        if (++phT[idx] > DF_EXT || d > DF_ROOM || a < CS_HB) { ph[idx] = 2; phT[idx] = 0; }
        return;
    }
    if (b > 0) { pad[0xA] = 1; pad[9] = 0; } else { pad[9] = 1; pad[0xA] = 0; }  /* bearing > 0 = right */
    pad[2] = 0;
    if (ph[idx] == 2) {                                         /* swing */
        pad[2] = 1; dbgHb[idx]++;
        dbgWhy[idx] = 21;
        if (a < CS_HB) ph[idx] = 0;
        else if (++phT[idx] > DF_SWING) {                    /* nose did not come round */
            if (d < DF_REV) { ph[idx] = 3; phT[idx] = REVERSE; } else { ph[idx] = 0; hbTimer[idx] = -HB_REST; }
        }
        return;
    }
    if (a >= CS_PIVOT) {
        ph[idx] = d < DF_CLOSE ? 1 : 2; phT[idx] = 0;
        return;
    }
    if (a >= CS_HB && hbTimer[idx] >= 0) {
        if (++hbTimer[idx] > HB_HOLD) hbTimer[idx] = -HB_REST;
        else { pad[2] = 1; dbgHb[idx]++; }                      /* handbrake */
    } else if (hbTimer[idx] > 0) hbTimer[idx] = -HB_REST;
}

/* Wall unstick (all bot modes, after every other steering): every 30 frames compare the bot's position with
 * the last sample; two samples in a row with < 3 units of travel while it wants to drive = pinned (against a wall,
 * on a ledge: the game's own stuck counter (0x444) misses a car that keeps sliding along a wall). Then reverse
 * with the wheel turned for 0.75 s and drive out with it turned the other way for 0.4 s; the side alternates
 * each time. The nav planner gets a fresh path afterwards (it replans when its timer runs out / target moves). */
#define UNSTICK_REV 45
#define UNSTICK_FWD 25
static float stkPos[8][4];
static int stkTick[8], stkCount[8], unstT[8], unstSide[8], crawl[8];
static void unstick(char* g, char* v)
{
    int i = (int)(v - g) / 0x31B0 & 7;
    unsigned char* pad = PAD(v);
    float* p;
    if (!F(v, 0x2028)) return;
    p = (float*)POS(v);
    if (unstT[i] > 0) {
        unstT[i]--;
        pad[2] = 0; pad[7] = 0; pad[8] = 0;
        if (unstT[i] >= UNSTICK_FWD) { pad[4] = 0; pad[6] = 1; }
        else { pad[4] = 1; pad[6] = 0; }
        pad[9] = 0; pad[0xA] = 0;
        if ((unstT[i] >= UNSTICK_FWD) == (unstSide[i] != 0)) pad[9] = 1; else pad[0xA] = 1;
        return;
    }
    if (++stkTick[i] < 30) return;
    stkTick[i] = 0;
    if ((pad[4] || pad[6]) && fbits(manhat(p, stkPos[i])) < 0x40400000) {        /* < 3.0 */
        if (++stkCount[i] >= 2) {
            stkCount[i] = 0;
            unstT[i] = UNSTICK_REV + UNSTICK_FWD;
            unstSide[i] ^= 1;
            scePrintf("TMBR unstick: bot %d at %d %d %d, mode %d, level %d\n", i, (int)p[0], (int)p[1], (int)p[2],
                F(v, 0x2018) ? F(F(v, 0x2018), 4) : -1, tmbr_levelIndex);
        }
    } else {
        stkCount[i] = 0;
        /* crawling (driving, 3..12 units per 0.5 s) for 3 s: log what the bot is doing */
        if (pad[4] && fbits(manhat(p, stkPos[i])) < 0x41400000) {
            if (++crawl[i] == 6)
                scePrintf("TMBR crawl: bot %d at %d %d %d, mode %d, role %d, hp %d, atk %d, pad %d%d%d%d\n", i, (int)p[0], (int)p[1], (int)p[2],
                    F(v, 0x2018) ? F(F(v, 0x2018), 4) : -1, ROLE(v), hpPct(v), F(v, 0x2014) ? F(F(v, 0x2014), 0x414) : -1,
                    pad[2], pad[4], pad[6], pad[8]);
        } else crawl[i] = 0;
    }
    stkPos[i][0] = p[0]; stkPos[i][1] = p[1]; stkPos[i][2] = p[2];
}

static int aiUpdate(char* v);
extern void padClear(char* v) __asm__("vehicleSaveAndClearPadFlags__7Vehicle");
int tmbr_AiUpdate(char* v)
{
    int r;
    if (F(D_003156C0, 0x1BB4) == 0xA && F(v, 0x2014)) { padClear(v); return 0; }   /* sync hold: bots frozen */
    r = aiUpdate(v);
    if (tmbr_botCount >= 0 && F(v, 0x2014) && D_004FA030) unstick(D_004FA030, v);
    return r;
}

static int aiUpdate(char* v)
{
    char* g = D_004FA030;
    char* drv = (char*)F(v, 0x2018);
    char* t = drv ? (char*)F(drv, 0xB4) : 0;
    int k, save = 0, swap, r;
    unsigned int t0;
    dbgCalls[(int)(v - g) / 0x31B0 & 7]++;
    if (tmbr_botCount >= 0 && F(v, 0x2014) && *(signed char*)(v + 0x497) >= 4 && drv) {
        /* respawn shield (shield.s: byte 0x497 >= 4, weapons locked): cruise until it drops, no fighting */
        int si = (int)(v - g) / 0x31B0 & 7;
        if (F(drv, 4) != 4) { driverSetMode(drv, 4); pickCruiseZone(g, v, 0); }
        if (shieldT[si] == 0) scePrintf("TMBR shield: bot %d on (20B4 %d 498 %d 464 %d)\n", si, F(v, 0x20B4), *(signed char*)(v + 0x498), F(v, 0x464));
        if (++shieldT[si] > 600) { shieldOff(v); shieldT[si] = 0; scePrintf("TMBR shield: bot %d off\n", si); }    /* 10 s, like the players' shield */
        t0 = tmbr_Cycles(); r = aiFrame(v); tmbr_PerfAdd(1, t0);
        return r;
    }
    shieldT[(int)(v - g) / 0x31B0 & 7] = 0;
    if (tmbr_botCount >= 0 && F(v, 0x2014)) {
        /* No fleeing: hunt mode (func_00108618) switches to flee (mode 3, then cruise) when healthScore <
         * fleeHealth; online there is no health pickup to flee to, and our think tick forced hunt back every
         * 0.5 s: stop-and-go. fleeHealth (brain+0x48) = 0.0 */
        F(F(v, 0x2014), 0x48) = 0;
        if (drv && t && F(drv, 4) >= 2 && F(drv, 4) <= 4 && !(F(drv, 4) == 4 && (ROLE(v) == R_CRUISER || leaveT[(int)(v - g) / 0x31B0 & 7] > 0))) { driverSetMode(drv, 5); driverSetTarget(drv, t); }
    }
    if (tmbr_botCount < 0 || !t || !F(t, 0x2028)) { t0 = tmbr_Cycles(); r = aiFrame(v); tmbr_PerfAdd(1, t0); return r; }
    swap = F(t, 0x590) == 2;
    k = F(t, 0x2100) & 7;
    if (swap) {
        save = F(g, 0x9FD40 + k * 4);
        F(g, 0x9FD40 + k * 4) = attractGroupAt(g + 0x30970, POS(t));
    }
    t0 = tmbr_Cycles();
    r = aiFrame(v);
    tmbr_PerfAdd(1, t0);
    if (swap) F(g, 0x9FD40 + k * 4) = save;
    t0 = tmbr_Cycles();
#if TMBR_NAV
    if (tmbr_NavDrive(g, v, t)) { tmbr_PerfAdd(2, t0); return r; }
#endif
    aggressiveTurn(g, v, t);
    tmbr_PerfAdd(2, t0);
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
extern void tmbr_SkinsLobby(void);       /* skins.c */
extern void tmbr_PedNamesInit(void);     /* packs.c */
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern int sprintf(char* d, const char* f, ...);

/* waiting room (func_001B2B68 -> func_001C5768 every frame): host hotkeys R3 + R1/L1 and a "BOTS" line.
 * Count steps AUTO (original rule) -> 0 .. MAXBOTS. */
/* Two lines fit under the settings box (rows 10 and 11, about 28 characters each). Normal view: BOTS, then
 * TRAFFIC / TEAMS; with teams on it alternates every 3 s with the two team rosters. Holding R3 shows the
 * controls instead (two pages, 2 s each, when teams are on). */
static int lobbyTick;
static void lobbyLines(const char* a, const char* b)
{
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 10 * 0x100);
    fontPrint(0, a);
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 11 * 0x100);
    fontPrint(0, b);
}
void tmbr_LobbyFrame(void)
{
    int pad = 0, pressed, host, teams;
    char buf[48], buf2[48], ra[40], rb[40];
    lobbyFrame();
    tmbr_SkinsLobby();
    tmbr_PedNamesInit();
    host = netIsHost(D_003156C0);
    teams = tmbr_Opt(OPT_TEAMS);
    tmbr_TeamsLobby(ra, rb);                 /* teams.c: team pick input + rosters */
    lobbyTick++;
    /* raw pad, active high: R3 0x4, Up 0x10, Down 0x40, L2 0x100, R2 0x200, L1 0x400, R1 0x800 */
    pad = inputGetPadButtons(0) & 0xF55;
    pressed = pad & ~prevPad;
    prevPad = pad;
    if (pad & 0x4) {
        if (teams && (lobbyTick / 120) & 1)
            lobbyLines("LEFT/RIGHT : MY TEAM", host ? "SELECT : BOT TEAMS" : "(HOLD R3)");
        else if (host) lobbyLines("L1/R1 BOTS  L2/R2 SKILL", "UP TRAFFIC  DOWN TEAMS");
        else lobbyLines("HOST SETS BOTS, TRAFFIC", "AND TEAMS");
    } else if (teams && (lobbyTick / 180) & 1) {
        lobbyLines(ra, rb);
    } else {
        if (tmbr_botCount < 0) sprintf(buf, "BOTS : AUTO");
        else sprintf(buf, "BOTS : %d  %s", tmbr_botCount, tmbr_botDiff == 0 ? "EASY" : tmbr_botDiff == 1 ? "MEDIUM" : "HARD");
        sprintf(buf2, "TRAFFIC %s  TEAMS %s", tmbr_Opt(OPT_TRAFFIC) ? "ON" : "OFF", teams ? "ON" : "OFF");
        lobbyLines(buf, buf2);
    }
    if (!host) return;
    if ((pad & 0x4) && (pressed & 0x50)) {
        optSync(((pressed & 0x10) ? OPT_TRAFFIC : 0) | ((pressed & 0x40) ? OPT_TEAMS : 0));
        scePrintf("TMBR lobby: traffic %s, teams %s\n", tmbr_Opt(OPT_TRAFFIC) ? "on" : "off", tmbr_Opt(OPT_TEAMS) ? "on" : "off");
    } else optSync(0);
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
}
