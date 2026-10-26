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
#define OPT_MINION 8      /* lobby option (game info +0xC6): Minion ON (off by default since 2026-10-26, Ark: off = car select
                           * skips him, no Minion bots); set on the game mods page (modspage.c) or R3 + Triangle */
int tmbr_MinionOff(void);
#define OPT_HEALTH 16     /* lobby option: health ON (TODO 9, 2026-10-26; off by default = the baked TMA rule) */
extern int tmbr_Opt(int bit);
#define MAXBOTS 7       /* 1 player + 7 bots = the 8 car slots */
#define TMBR_BOTDBG 0
#ifndef TMBR_NAV
#define TMBR_NAV 1
#endif
#define LIST(g) ((char**)((g) + 0x9E690))
#define SORT(g) ((int*)((g) + 0x9E6AC))   /* after the 7-entry AI list (apply_mods.py: 0x139B0C, 0x13C178) */
#define NAI(g) F(g, 0x9FEE4)

extern char* D_004FA030;   /* game */
extern int tmbr_levelIndex;  /* packs.c */
extern char D_003156C0[];  /* net: 8 player slots x 0x220 from +0 */
extern int D_002C07F8[];   /* radar name per character */
extern int scePrintf(const char* fmt, ...);
extern int mathfRandI(int lo, int hi) __asm__("mathfRand__Fii");
extern void pickCruiseZone(char* g, char* v, int i) __asm__("gamePickCruiseZone__7TheGameP7Vehiclei");
extern int tmbr_NavDrive(char* g, char* v, char* t);   /* nav.c */
extern void tmbr_NavRoamFar(char* g, char* v);
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

int tmbr_botCount = 0;     /* bots in the match; the original "3 - humans" rule (AUTO) and USE BOTS are gone */
int tmbr_botDiff = 1;      /* AI difficulty (game+0x9A3D4) used with a chosen count: 0 easy, 1 medium, 2 hard */
static int prevPad;

static int humans(void)
{
    int i, n = 0;
    for (i = 0; i < 8; i++)
        if (F(D_003156C0 + i * 0x220, 0x214) >= 7 && F(D_003156C0 + i * 0x220, 0xC8) == 0) n++;
    return n;
}

extern int tmbr_GuestsWanted(void);   /* guests.c: local split-screen players (count as humans) */
extern int tmbr_IsGuest(char* v), tmbr_GuestSlot(int s);
static int wanted(int mid)
{
    u32 cfg = *(u32*)F(D_003156C0, 0x3148);
    int h = humans() + tmbr_GuestsWanted(), n;
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

static void botsShown(int* c, int* d);
int tmbr_BotsPlanned(void)
{
    int c, d, h = humans();
    if (!F(D_003156C0, 0x3148)) return 0;
    if (netIsHost(D_003156C0)) return wanted(0);
    botsShown(&c, &d);
    if (c > 8 - h) c = 8 - h;
    return c < 0 ? 0 : c;
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
        {   /* (a 12 Pak bot is a Roadkill inside: its marker says 12 PAK) */
            extern int tmbr_IsPak(char* v);
            static const char pakName[] = "12 PAK";
            radarName(0xA + i, tmbr_IsPak(v) ? (int)pakName : D_002C07F8[F(v, 0x20F4) >> 5]);
        }
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
        if (tmbr_GuestSlot(s)) continue;                 /* reserved for a split-screen guest */
        v = netSlotVehicle(D_003156C0, s) - 1;
        if (v >= 0 && v < 8 && tmbr_IsGuest(g + v * 0x31B0)) continue;
        if (v >= 0 && v < 8 && F(F(g, 0x9E670 + v * 4), 0x20D0) == 0) break;
    }
    if (s == 8) return 0;
    if (tmbr_MinionOff() && !tmbr_Opt(0x20) && (F(D_003156C0 + s * 0x220, 0xB4) >> 5) == 15)   /* Minion off: another car */
        F(D_003156C0 + s * 0x220, 0xB4) = mathfRandI(1, 14) << 5;
    veh = gameMakeAI(g, v, F(D_003156C0 + s * 0x220, 0xB4), v, -1, 1);
    if (!veh) return 0;
    netBotObjects(D_003156C0, veh);
    {   /* a 12 Pak bot: his name on the marker / leaderboard (the slot name, +0x18, was the car's: ROADKILL) */
        extern int tmbr_IsPak(char* v);
        if (tmbr_IsPak(veh)) {
            char* nm = D_003156C0 + s * 0x220 + 0x18;
            nm[0] = '1'; nm[1] = '2'; nm[2] = ' '; nm[3] = 'P'; nm[4] = 'A'; nm[5] = 'K'; nm[6] = 0;
        }
    }
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
static int lives, lms, dm, alive, leader, prey;   /* this think's mode state (tmbr_BotsThink) */
#define PREY_CHASERS 2   /* Man Hunt: bots that commit to the prey at once (the rest fight as usual) */
static int lastLife(char* v)
{
    int slot = F(v, 0x2104);
    return lms && lives && slot >= 0 && slot < 8 && F(D_003156C0, 0x2F48 + 4 * slot) >= lives - 1;
}
/* Roles (by AI index, so 3 bots get one of each): brawler = closest target, gets in close (dogfight);
 * sniper = targets ~450 away, holds a 250..550 band and backs off when rushed; roamer = picks the most
 * isolated car nobody else is on, fights like a brawler. Spreads the bots out instead of one mosh pit. */
#define R_BRAWLER 0
#define R_SNIPER 1
#define R_ROAMER 2
#define R_CRUISER 3    /* drives the map (game cruise mode 4) and fights whatever it runs into */
#define CRUISE_SEE 550     /* (was 350: cruisers drove past fights - 2026-10-25 low bot damage) */
/* sight range per role (manhattan units): beyond it a bot cruises instead of crossing the map to a fight */
#define HUNT_SEE(rl) ((rl) == R_CRUISER ? CRUISE_SEE : (rl) == R_SNIPER ? 1000 : (rl) == R_ROAMER ? 1200 : 900)
#define ROLE(v) (role[((int)((char*)(v) - D_004FA030) / 0x31B0) & 7])
/* Per-car personality (Ark, 2026-10-25). Character = car +0x20F4 >> 5 (radar name table D_002C07F8):
 *  Darkside / Yellow Jacket: brawlers - join big fights; their specials are rams, saved for a close lined-up target
 *    (Yellow Jacket: in a pile-up it just fires its special; one on one it singles a car out and turbo-rams it);
 *  Spectre / Mr. Grimm: fragile - one-on-one fighters (sniper / roamer roles), steer clear of brawls. */
#define CH_YELLOWJ 2
#define CH_SPECTRE 4
#define CH_GRIMM 10
#define CH_DARKSIDE 13
#define CH_MANSLAUGHTER 14
static int charOf(char* v) { return (F(v, 0x20F4) >> 5) & 0x1F; }
static int fragile(char* v) { int c = charOf(v); return c == CH_SPECTRE || c == CH_GRIMM; }
/* Per-car guidelines (Ark, 2026-10-25) - tendencies, not scripts: role odds (brawler / sniper / roamer %, the rest
 * cruiser), mid (1: a mid-weight car, prefers smaller fights), and when the special is worth firing: alone on a
 * target solo_min..solo_max away, or at a group (2+ cars round the target) up to grp_max; aim 1 = only when
 * squarely lined up (charged / aimed specials); hp 1 = to weaken (target above half), 2 = to finish (below half).
 * dmg = the special's typical full hit (online numbers, tmbosvr.com/infocharts.html): a target with no more health
 * left than that gets the special. Indexes = car +0x20F4 >> 5 (radar names); 0 = no entry (the old 50 % rule).
 * Darkside / Yellow Jacket: rammer(). */
typedef struct { unsigned char on, b, s, r, mid, aim, hp; short smin, smax, gmax, dmg; } CarAi;
static const CarAi carAi[32] = {
    /*  0 */ { 0 },
    /*  1 Roadkill: snipes / moderate range, charged by confidence */  { 1, 35, 25, 25, 0, 1, 0, 150, 600, 0, 36 },
    /*  2 Yellow Jacket (rammer) */                                     { 1, 45, 0, 40, 0, 0, 0, 0, 0, 0, 30 },
    /*  3 Outlaw: high damage */                                        { 1, 40, 15, 30, 0, 0, 0, 0, 400, 400, 44 },
    /*  4 Spectre: homing through walls */                             { 1, 0, 45, 40, 0, 0, 0, 100, 700, 700, 28 },
    /*  5 Crazy 8: special to weaken */                                 { 1, 45, 10, 30, 0, 0, 1, 0, 450, 450, 40 },
    /*  6 Sweet Tooth: moderate range */                                { 1, 55, 5, 25, 0, 0, 0, 150, 450, 450, 50 },
    /*  7 Brimstone: mid, smaller fights */                             { 1, 25, 20, 40, 1, 0, 0, 0, 350, 350, 37 },
    /*  8 Junkyard Dog: groups, moderate snipes */                      { 1, 50, 10, 25, 0, 0, 0, 200, 450, 500, 25 },
    /*  9 Shadow: bomb for snipes and groups */                         { 1, 35, 20, 30, 0, 0, 0, 250, 600, 600, 33 },
    /* 10 Mr. Grimm: lines it up */                                     { 1, 0, 45, 40, 0, 1, 0, 150, 600, 600, 42 },
    /* 11 Axel: groups (War Wheel solo: later) */                       { 1, 40, 10, 35, 0, 0, 0, 0, 300, 350, 22 },
    /* 12 Warthog: weaken / finish */                                   { 1, 55, 5, 25, 0, 0, 2, 0, 300, 300, 120 },
    /* 13 Darkside (rammer) */                                          { 1, 60, 0, 25, 0, 0, 0, 0, 0, 0, 38 },
    /* 14 Manslaughter: dead on, into groups */                         { 1, 55, 5, 25, 0, 1, 0, 0, 400, 400, 90 },
    { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 },
    /* 31 12 Pak (0x7E0): mid, sniper special */                        { 1, 25, 20, 40, 1, 1, 0, 250, 700, 700, 36 },
};
#define CAI(v) (&carAi[charOf(v)])
static int rammer(char* v) { int c = charOf(v); return c == CH_DARKSIDE || c == CH_YELLOWJ; }
static int cpx[8], cpy[8], cvx[8], cvy[8]; static unsigned char cok[8];   /* every car, per frame (x4 units) */
static int iabs(int x) { return x < 0 ? -x : x; }
static int hunted[8], crowd[8];
static short ramT[8];              /* frames of turbo left for a special ram (Darkside, Yellow Jacket) */
static short setupT[8];            /* frames after a freeze: the next weapon pick goes for a big hit */
static signed char tslT[8], tslDir[8];    /* Darkside's T-slide in progress */
static int frzAt[8] = { -100, -100, -100, -100, -100, -100, -100, -100 };   /* thinkTick of each bot's last freeze request */
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
static short chaseT[8], giveUpT[8]; static signed char giveUpK[8];  /* long chases of a human: give up for a while */
#define HUMAN_MAX_BOTS 2   /* bots on one human at once (log 2026-10-24: down two lives first in a big fight) */

/* Roles change during the match: every 15..40 s a bot rolls a new one (brawler 35 %, sniper 15 %, roamer
 * 30 %, cruiser 20 %, re-rolled once if every other bot already has it), and a sniper that keeps getting caught up close
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
    /* brawler 35 %, sniper 15 %, roamer 30 %, cruiser 20 % (cruiser was 35 %: bots spent too long not fighting) */
    int r = mathfRandI(0, 99), n = r < 35 ? R_BRAWLER : r < 50 ? R_SNIPER : r < 80 ? R_ROAMER : R_CRUISER, i, same = 0, bots = 0;
    char* me = g + k * 0x31B0;
    if (CAI(me)->on) {                                        /* the car's own role odds */
        const CarAi* c = CAI(me);
        n = r < c->b ? R_BRAWLER : r < c->b + c->s ? R_SNIPER : r < c->b + c->s + c->r ? R_ROAMER : R_CRUISER;
    }
    for (i = 0; i < NAI(g); i++) {
        char* b = LIST(g)[i];
        int j;
        if (!b || (j = (int)(b - g) / 0x31B0) == k || j < 0 || j > 7) continue;
        bots++;
        if (role[j] == n) same++;
    }
    if (bots && same == bots && !CAI(me)->on) n = (n + 1 + mathfRandI(0, 2)) % 4;   /* (personalities keep theirs) */
    role[k] = n;
    roleT[k] = 30 + mathfRandI(0, 50);
    rushT[k] = 0;
    if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d role %s\n", k, n == R_BRAWLER ? "brawler" : n == R_SNIPER ? "sniper" : n == R_ROAMER ? "roamer" : "cruiser");
}
static int dbgCalls[8], dbgHb[8], dbgWhy[8], dbgShots[8];   /* TMBR_BOTDBG: AI frames seen by the hook, handbrake frames */
static int dbgBits(float f) { union { float f; int i; } u; u.f = f; return u.i; }
#define SPECIAL_CHANCE 30 /* % of the time a bot may pick its special when it chooses a weapon (FFA) */

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
#define OPT_TEAMS4 4      /* four teams */
extern void netSendGameInfo(void* net, int to) __asm__("func_00174988");
extern int tmbr_levelSerial;
int tmbr_Opt(int bit)
{
    char* gi = GINFO();
    return gi && (gi[0xC6] & bit);
}
int tmbr_MinionOff(void) { return !tmbr_Opt(OPT_MINION); }
/* bot count / difficulty for everyone's lobby: game info byte +0xC7 = 0x80 | count | difficulty << 3 */
static void botsShown(int* c, int* d)
{
    char* gi = GINFO();
    if (netIsHost(D_003156C0) || !gi || !(gi[0xC7] & 0x80)) { *c = tmbr_botCount; *d = tmbr_botDiff; return; }
    *c = gi[0xC7] & 7; *d = (gi[0xC7] >> 3) & 3;
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
    {
        char bb = (char)(0x80 | (tmbr_botCount & 7) | (tmbr_botDiff & 3) << 3);
        if (gi[0xC7] != bb) { gi[0xC7] = bb; flip = 1; }
    }
    if (flip || want != has) netSendGameInfo(D_003156C0, -1);
}
/* host: set / clear option bits (story.c) */
void tmbr_OptSet(int bits, int on)
{
    char* gi = GINFO();
    int cur, want;
    if (!gi) return;
    cur = gi[0xC6] & bits;
    want = on ? bits : 0;
    if (cur != want) optSync(cur ^ want);
}
extern int tmbr_TeamOf(char* v);         /* teams.c */
extern void tmbr_TeamsFrame(void);
extern void tmbr_TeamsLobby(char* lineA, char* lineB);
extern void tmbr_TeamsBotJoined(int slot, int car);
extern void tmbr_TeamsBotLeft(char* v);

/* ---- HEALTH : OFF (TODO 9, Ark 2026-10-26: no health on the map at all; ON = as the game has it). Pickups live
 * at game +0x86340 (Pickups): slot i (0..0x68) in use when its word at +4i is set, its cs at +0x60 + i*0x18; the
 * type is the cs's hier node id - 5000 (TakeHit: 7 health, 17 full health). With health off their cs is not drawn
 * (cs +0xC = 0, every frame - the respawn would show them again) and touching one does nothing (TakeHit wrapped at
 * its three calls: collis 0x11F0DC, net events 0x167378 / 0x167454). */
extern int pickupsTakeHit(char* p, char* v, char* cs, int b) __asm__("TakeHit__7PickupsP7VehicleP3_csb");
static int pickupType(char* cs)
{
    char* hh = cs ? *(char**)cs : 0;
    return hh ? (int)(*(unsigned*)hh >> 18) - 5000 : -1;
}
static int healthType(int t) { return t == 7 || t == 17; }
/* environment pickups (type 8) are gone for good (TODO 10, Ark: no option) - on Suburbs / Snowy Roads / Mini
 * Suburbs that pickup is the storm cloud, so the cloud goes with it */
#define ENV_PICKUP 8
int tmbr_PickupHit(char* p, char* v, char* cs, int b)
{
    int t = pickupType(cs);
    if (t == ENV_PICKUP) return 0;
    if (!tmbr_Opt(OPT_HEALTH) && healthType(t)) return 0;
    return pickupsTakeHit(p, v, cs, b);
}
static void healthFrame(void)
{
    static int shown = -1, envShown = -1;
    char* p;
    int i, n = 0, e = 0, off = !tmbr_Opt(OPT_HEALTH);
    {   /* the baked TMA rule "No Health Pickups (always on)" makes the add-health function (func_001E32D8) return at
         * once (jr ra; nop): HEALTH : ON puts its first two instructions back, OFF the rule's again */
        extern void FlushCache(int mode) __asm__("FlushCache");
        static int patched = -1;
        unsigned* fn = (unsigned*)0x1E32D8;
        if (off != patched) {
            fn[0] = off ? 0x03E00008u : 0x27BDFFC0u;
            fn[1] = off ? 0x00000000u : 0x700014A9u;
            FlushCache(0); FlushCache(2);
            patched = off;
            scePrintf("TMBR health: pickups and healing %s\n", off ? "off (TMA rule)" : "on");
        }
    }
    if (!D_004FA030) return;
    p = D_004FA030 + 0x86340;
    for (i = 0; i < 0x68; i++) {
        char* cs;
        if (!F(p, 4 * i)) continue;
        cs = (char*)F(p, 0x60 + i * 0x18);
        if ((u32)cs < 0x100000 || (u32)cs >= 0x2000000) continue;
        {
            int t = pickupType(cs);
            if (t == ENV_PICKUP) { cs[0xC] = 0; e++; }
            else if (off && healthType(t)) { cs[0xC] = 0; n++; }
        }
    }
    if (off && n != shown) { shown = n; scePrintf("TMBR health: off, %d health pickups hidden\n", n); }
    if (e != envShown) { envShown = e; scePrintf("TMBR pickups: %d environment pickups hidden\n", e); }
}

#ifndef TMBR_WEAPTEST
#define TMBR_WEAPTEST 0
#endif
#if TMBR_WEAPTEST
/* test build only: the local car keeps ammo in fire / homing / napalm / power / rico; weapon changes logged */
static void weapTest(char* g)
{
    static int last = -1;
    char* v = 0;
    int k, s;
    for (k = 0; k < 8; k++) if (F(g + k * 0x31B0, 0x590) == 1) { v = g + k * 0x31B0; break; }
    if (!v) return;
    for (s = 2; s <= 7; s++) if (s != 5 && F(v, 0x2338 + s * 4) < 3) F(v, 0x2338 + s * 4) = 6;
    if (F(v, 0x21B0) != last) { last = F(v, 0x21B0); scePrintf("TMBR weaptest: car %d (%x) weapon %d\n", k, F(v, 0x20F4), last); }
}
#endif
void tmbr_BotsThink(void)
{
    char* g = D_004FA030;
    int i, k;
    if (g) { tmbr_TeamsFrame(); healthFrame(); }
#if TMBR_WEAPTEST
    if (g) weapTest(g);
#endif
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
    /* game mode (game info word 0 bits 1-4: 1 over, 3 Last Man Standing, 4/5 Man Hunt / Collector, else
     * deathmatch), lives (info byte 5), deaths per car (net +0x2F48 [car +0x2104]), kills (net +0x2F28 [car]) */
    {
        int type = GINFO() ? (F(GINFO(), 0) >> 1) & 0xF : 0, top = -1, topK = 0, second = 0;
        lives = GINFO() ? ((unsigned char*)GINFO())[5] : 0;
        lms = type == 3;
        dm = type != 3 && type != 4 && type != 5;
        alive = 0;
        for (k = 0; k < 8; k++) {
            char* v = g + k * 0x31B0;
            int kk = F(D_003156C0, 0x2F28 + 4 * k);
            if (!live(v)) continue;
            alive++;
            if (kk > topK) { second = topK; topK = kk; top = k; } else if (kk > second) second = kk;
        }
        leader = dm && top >= 0 && topK >= second + 2 ? top : -1;     /* a clear kill leader (2+ ahead) */
        /* Man Hunt (type 4): the prey is the car whose player slot (+0x20C0) is game info byte +0x1A (the
         * radar's fox colour test, hud func_00149D08 0x14A980). Bots have slot -1: only a human can match. */
        prey = -1;
        if (type == 4) {
            int ps = ((signed char*)GINFO())[0x1A];
            for (k = 0; ps >= 0 && k < 8; k++)
                if (live(g + k * 0x31B0) && F(g + k * 0x31B0, 0x20C0) == ps) { prey = k; break; }
        }
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
             * and come back fresh. Checked every 0.5 s: after 12 s of fighting 15 %, in a pile-up (after 3 s) 25 %. */
            int k2 = (int)(b - g) / 0x31B0 & 7, pile = crowd[k2] >= (fragile(b) ? 2 : 3), retreat;   /* fragile cars: 2 is a crowd */
            int endgame = lms && alive <= 3, careful = lastLife(b) && !endgame;
            if (endgame) leaveT[k2] = 0;                 /* Last Man Standing, 3 or fewer left: finish it */
            if (leaveT[k2] > 0) {
                leaveT[k2]--;
                if (F(drv, 4) != 4) cruiseFar(g, b, drv);
                continue;
            }
            if (cur && (int)manhat(POS(b), POS(cur)) < 600) fightT[k2]++; else fightT[k2] = 0;
            /* retreat: hurt (< 35 %) and two or more cars on it -> break away (25 % per check) */
            /* online has no health to recover, so a retreat is short (8-15 s) and once per life */
            if (hpPct(b) >= 90) retreated[k2] = 0;
            {   /* light cars break off earlier, heavy ones later (Spectre 95: 52 %, Darkside 150: 25 %) */
                int mx = (int)*(float*)(b + 0x3F0), at = 35 + (130 - mx) / 2;
                if (at < 20) at = 20;
                if (at > 55) at = 55;
                retreat = !retreated[k2] && hpPct(b) < at && hunted[k2] >= 2 && mathfRandI(0, 99) < 25;
            }
            if (careful)                                 /* last life: back off earlier and more often */
                retreat = !retreated[k2] && hpPct(b) < 50 && hunted[k2] >= 1 && mathfRandI(0, 99) < 40;
            if (retreat) retreated[k2] = 1;
            if (!endgame && (retreat || (fightT[k2] > 24 && mathfRandI(0, 99) < 15) || (pile && fightT[k2] > (fragile(b) ? 2 : 4) && mathfRandI(0, 99) < (fragile(b) ? 60 : 35)))) {
                leaveT[k2] = 20 + mathfRandI(0, 16);       /* 10-18 s: far enough to start a fight elsewhere */
                fightT[k2] = 0;
                cruiseFar(g, b, drv);       /* to the far side of the map: spreads the bots out */
#if TMBR_NAV
                tmbr_NavRoamFar(g, b);
#endif
                if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d breaks away (%s)\n", k2, pile ? "pile-up" : "long fight");
                continue;
            }
        }
        if (cur) ci = (int)(cur - g) / 0x31B0;
        {   /* chasing a human for 15 s without getting within 350: leave that human alone for 10 s */
            int k2 = (int)(b - g) / 0x31B0 & 7;
            if (giveUpT[k2] > 0) giveUpT[k2]--;
            if (cur && F(cur, 0x590) == 1 && ci != prey && (int)manhat(POS(b), POS(cur)) > 350) {
                if (++chaseT[k2] >= 30) { giveUpT[k2] = 20; giveUpK[k2] = ci; chaseT[k2] = 0; cur = 0; ci = -1; }
            } else chaseT[k2] = 0;
        }
        for (k = 0; k < 8; k++) {
            char* v = g + k * 0x31B0;
            int others;
            if (v == b || !live(v)) continue;
            if (tmbr_Opt(OPT_TEAMS) && tmbr_TeamOf(v) == tmbr_TeamOf(b)) continue;   /* teammate */
            d = (int)manhat(POS(b), POS(v));
            others = hunted[k] - (k == ci);              /* other bots already on it */
            if (F(v, 0x590) == 1) {                      /* humans: never more than HUMAN_MAX_BOTS bots at once */
                int k2 = (int)(b - g) / 0x31B0 & 7;
                if (others >= HUMAN_MAX_BOTS && k != prey) continue;
                if (giveUpT[k2] > 0 && giveUpK[k2] == k) continue;
                d += others * 450;
            }
            if (fragile(b)) sc = (rl == R_SNIPER ? (d > 450 ? d - 450 : 450 - d) : d / 2) + others * 700 + crowd[k] * 900;   /* one on one */
            else if (rl == R_CRUISER) sc = d + crowd[k] * 200;
            else if (rl == R_SNIPER) sc = (d > 450 ? d - 450 : 450 - d) + others * 250;    /* likes 450 away */
            else if (rl == R_ROAMER) sc = d / 2 + others * 600 + crowd[k] * 500;      /* lone targets */
            else sc = d + others * 200 + crowd[k] * 250;                                  /* brawler (avoids pile-ups) */
            if (CAI(b)->mid) sc += crowd[k] * 300 + others * 200;                    /* mid cars: smaller fights */
            sc -= (100 - hpPct(v)) * (rl == R_CRUISER ? 1 : 3);   /* finish off damaged cars (up to -300) */
            if (k == leader) sc -= 250;                                /* deathmatch: someone pulling away */
            if (k == prey && others < PREY_CHASERS) sc -= 900;         /* Man Hunt: a couple of bots on the prey */
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
            int chase = prey >= 0 && best == g + prey * 0x31B0;   /* the prey's chasers cross the map for it */
            int keep = F(best, 0x590) == 1 ? see : rl == R_CRUISER ? see * 2 : see * 3 / 2;   /* humans: easier to lose */
            if (!(lms && alive <= 3) && !chase && (bd > keep || (F(drv, 4) == 4 && bd > see))) {
                if (F(drv, 4) != 4) cruiseFar(g, b, drv);   /* far zone: the nearest one was usually the brawl just left */
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
#define AIM_DEAD 0x3D4CCCCD  /* 0.05 rad, ~3 deg */
#define AIM_1    0x3DCCCCCD  /* 0.10 */
#define AIM_2    0x3E19999A  /* 0.15 */
#define AIM_3    0x3E4CCCCD  /* 0.20 */
#define CS_DIST 0x44160000   /* 600.0 */
#define HB_HOLD 24
#define HB_REST 20
#define STALL 240
#define TURBO_FAR 0x43C80000  /* 400.0: lined up and this far away -> turbo in */
#define FIRE_ANG 0x3F19999A   /* 0.6 rad, ~34 deg (homing) */
#define FIRE_TIGHT 0x3E851EB8 /* 0.26 rad, ~15 deg (straight weapons) */
#define FIRE_NEAR 0x43C80000  /* 400.0 */
#define LOCK_ANG 0x3EB33333   /* 0.35 rad, ~20 deg: inside the lock-on reticle */
#define LOCK_T 24             /* frames held there before a homing missile (~0.4 s) */
static unsigned char lockT[8];
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
#define STANDOFF 0x43160000       /* 150.0 */
#define STANDOFF_BRAKE 0x42B40000 /* 90.0 */
static signed char ph[8];
static short phT[8];
static signed char hbTimer[8];
static short standT[8];            /* frames coasting in a standoff */
#define STAND_MAX 40               /* then back on the gas: deep in a fight bots braked and sat (2026-10-25) */
static int fbits(float f) { union { float f; int i; } u; u.f = f; return u.i; }
extern void aiSetAttackState(char* v, int st) __asm__("aiSetAttackState__7Vehicle12_attackState");


/* ---- flank / orbit (Ark 2026-10-25: bot-on-bot duels were mostly handbrake-and-charge head on, trading hits;
 * players in TMA do that sometimes, but mostly flank or circle for a better shot) ----
 * In a close duel (OR_MIN..OR_ENGAGE) with the target's nose on us (brain+0x28 < OR_EXPOSED), a bot decides once per
 * engagement (OR_DECIDE frames): charge (the old head-on pass) or orbit. Charging is likelier for rammers and
 * Manslaughter, with a clear health lead, or when the target is low (go finish it). Orbit: keep the target off the
 * nose at about OR_ANG on whichever side it already is (steer away when it drifts in front, toward when it falls
 * behind; wider when too close, tighter when too far), on the gas, no handbrake; once we are on its flank or
 * behind (its nose more than OR_FLANKED off us) turn in and attack - the normal aim / fire takes over. At most
 * OR_MAX frames, then commit. */
#define OR_MIN      0x42A00000   /*  80.0 */
#define OR_ENGAGE   0x43C80000   /* 400.0 */
#define OR_TIGHT    0x43820000   /* 260.0: farther than this, orbit tighter (close in) */
#define OR_WIDE     0x42F00000   /* 120.0: closer than this, orbit wider */
#define OR_EXPOSED  0x3F32B8C2   /* 0.70 rad (40 deg): the target's nose is on us */
#define OR_FLANKED  0x3F9C61AA   /* 1.22 rad (70 deg): we are on its side / behind */
#define OR_ANG      0x3FA78D36   /* 1.31 rad (75 deg): target this far off our nose while orbiting */
#define OR_ANG_IN   0x3F490FDB   /* 0.79 rad (45 deg): tighter */
#define OR_ANG_OUT  0x3FDF66F3   /* 1.75 rad (100 deg): wider */
#define OR_BAND     0x3E32B8C2   /* 0.17 rad (10 deg) dead band */
#define OR_DECIDE   180
#define OR_MAX      150
static signed char orb[8];       /* 0 undecided, 1 orbiting, 2 charging (this engagement) */
static short orbT[8], orbDec[8];
static int flank(char* g, char* v, char* t, int idx, int b, int a, int d, int tf)
{
    unsigned char* pad = PAD(v);
    int want, side, cut;
    if (orbDec[idx] > 0) orbDec[idx]--;
    if (orbDec[idx] == 0) orb[idx] = 0;
    if (d < OR_MIN || d > OR_ENGAGE || ROLE(v) == R_SNIPER || ph[idx] == 3 || ph[idx] == 4) { if (orb[idx] == 1) orb[idx] = 0; return 0; }
    if (!orb[idx]) {
        int c = 25;                                          /* % chance to charge head on */
        if (rammer(v) || charOf(v) == CH_MANSLAUGHTER) c += 35;
        if (hpPct(v) > hpPct(t) + 25) c += 20;
        if (hpPct(t) < 25) c += 25;
        if (hpPct(v) < 35) c -= 15;
        if (tf >= OR_EXPOSED) return 0;                      /* not facing us: no need to dance, attack */
        orb[idx] = mathfRandI(0, 99) < c ? 2 : 1;
        orbDec[idx] = OR_DECIDE; orbT[idx] = 0;
    }
    if (orb[idx] != 1) return 0;
    if (tf > OR_FLANKED || ++orbT[idx] > OR_MAX) { orb[idx] = 2; orbDec[idx] = OR_DECIDE; return 0; }   /* on its flank (or enough): turn in */
    want = d > OR_TIGHT ? OR_ANG_IN : d < OR_WIDE ? OR_ANG_OUT : OR_ANG;
    side = b > 0 ? 1 : -1;                                   /* target on our right (b > 0) / left */
    pad[4] = 1; pad[6] = 0; pad[2] = 0; pad[7] = 0; pad[8] = 0;
    pad[9] = 0; pad[0xA] = 0;
    cut = a < want - OR_BAND ? -1 : a > want + OR_BAND ? 1 : 0;   /* -1: too far in front, steer away; 1: turn toward */
    if (cut) {
        int right = (side > 0) == (cut > 0);                     /* toward a right-side target = steer right */
        if (right) pad[0xA] = 1; else pad[9] = 1;
    }
    dbgWhy[idx] = 50;
    return 1;
}


/* ---- charging the reticle (Ark 2026-10-26: bots fired the charge-up reticle at once). The slot-5 pickup type 0xB
 * (launcher v+0x21B0: +0 slot, +0x110 slot-5 type, +0x218 armed) arms on one fire press and releases on the next;
 * the longer it is held on the target, the harder it hits (up to ~5 s). Once armed, a bot holds it CH_MIN..CH_MAX
 * frames (longer on a target that is barely moving), keeping the target near the middle; it lets go early when the
 * target has been out of sight / far off the nose for CH_LOST frames. While holding, its fire requests (attack
 * state 7) go back to aiming (5) and the trigger code below leaves it alone. */
#define CH_MIN 90
#define CH_MAX 270
#define CH_LOST 45
static short chT[8], chWant[8], chLost[8];
static int charging(char* g, char* v, int idx)
{
    char* l = v + 0x21B0;
    char* br = (char*)F(v, 0x2014);
    int a, d, seen;
    if (!br || F(l, 0) != 5 || F(l, 0x110) != 0xB || !F(l, 0x218)) { if (chT[idx]) scePrintf("TMBR charge: car %d let go after %d\n", idx, chT[idx]); chT[idx] = 0; return 0; }
    a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF; d = fbits(*(float*)(br + 0x20));
    seen = (F(br, 0x598) || F(br, 0x4B0) < 10) && a < LOCK_ANG && d >= 0;
    if (!chT[idx]) {
        chWant[idx] = mathfRandI(CH_MIN, CH_MAX);
        {   /* target hardly moving: full charge */
            char* drv = (char*)F(v, 0x2018);
            char* t = drv ? (char*)F(drv, 0xB4) : 0;
            int tk = t ? (int)(t - g) / 0x31B0 & 7 : 0;
            if (t && cok[tk] && iabs(cvx[tk]) + iabs(cvy[tk]) < 8) chWant[idx] = CH_MAX;
        }
        chLost[idx] = 0;
        scePrintf("TMBR charge: car %d armed, holding %d\n", idx, chWant[idx]);
    }
    chT[idx]++;
    chLost[idx] = seen ? 0 : chLost[idx] + 1;
    if (chT[idx] >= chWant[idx] || chLost[idx] >= CH_LOST) return 0;   /* release: the normal fire may go */
    if (F(br, 0x414) == 7) aiSetAttackState(v, 5);
    return 1;
}

/* ---- lining up the big straight shots (Ark 2026-10-26: bots fired power missiles / zoomys on the move and mostly
 * missed - they have to be aimed). When the AI weapon is the power missile (6) or the pickup slot holding zoomys
 * (launcher +0x110 type 0xD), in sight and within AS_RANGE, a bot sometimes (AS_CHANCE by difficulty) stops to aim:
 * off the gas, braking while still fast, small steering corrections (more often the further off), and fires when
 * the target is within AS_TIGHT of the nose; it keeps the pose for the rest of the load (AS_GAP between shots),
 * then leaves on turbo (AS_TURBO frames) to get back up to speed. At most AS_MAX frames; a target that gets too
 * close (< AS_MIN) or out of sight for AS_LOST frames ends it. Decided once per pick (the weapon pick time). */
#define AS_RANGE 0x43C80000   /* 400.0 */
#define AS_MIN   0x42C80000   /* 100.0 */
#define AS_TIGHT 0x3D75C28F   /* 0.06 rad, ~3.4 deg */
#define AS_START 0x3EB33333   /* 0.35 rad: only from roughly facing it */
#define AS_MAX 110
#define AS_GAP 24
#define AS_LOST 30
#define AS_TURBO 60
static short asT[8], asLost[8], asGap[8], asTurbo[8], asShots[8];
static int asLast[8];             /* thinkTick of the last aiming frame (the fight logic stopped running: drop it) */
static signed char asOn[8], asPrevW[8], asTry[8];   /* asTry: a decision is pending for the weapon just raised */
static int wpnPicked[8];          /* (defined with the weapon pick below) */
static int bigShot(char* v, char* br)
{
    int w = F(br, 0x47C);
    char* l = v + 0x21B0;
    return w == 6 || (w == 5 && F(l, 0x110) == 0xD);
}
static int aimShot(char* g, char* v, int idx, int b, int a, int d)
{
    static const int chance[3] = { 30, 55, 75 };
    char* br = (char*)F(v, 0x2014);
    unsigned char* pad = PAD(v);
    int seen = F(br, 0x598) || F(br, 0x4B0) < 10, sp, duty;
    if (asTurbo[idx] > 0) { asTurbo[idx]--; pad[4] = 1; pad[6] = 0; pad[7] = 1; }
    {   /* a big shot just came up (the AI's weapon changed to it, whoever picked it): one decision for it */
        int w = F(br, 0x47C) & 7;
        if (w != asPrevW[idx]) {
            asPrevW[idx] = (signed char)w; asTry[idx] = bigShot(v, br);
            if (w == 5) {
                static unsigned int seen5;
                int ty = F(v + 0x21B0, 0x110) & 31;
                if (!(seen5 >> ty & 1)) { seen5 |= 1u << ty; scePrintf("TMBR aim: pickup slot type %d up\n", ty); }
            }
        }
    }
    if (asOn[idx] && thinkTick - asLast[idx] > 10) asOn[idx] = 0;   /* (left the fight meanwhile: start over) */
    asLast[idx] = thinkTick;
    if (!asOn[idx]) {
        if (!asTry[idx] || !bigShot(v, br)) return 0;
        if (d < AS_MIN || d > AS_RANGE || a > AS_START || !seen || (ROLE(v) == R_SNIPER && ph[idx] == 4)) return 0;
        asTry[idx] = 0;
        if (mathfRandI(0, 99) >= chance[tmbr_botDiff < 0 ? 0 : tmbr_botDiff > 2 ? 2 : tmbr_botDiff]) return 0;
        asOn[idx] = 1; asT[idx] = asLost[idx] = asGap[idx] = asShots[idx] = 0;
        scePrintf("TMBR aim: car %d lines up (w %d, d %d)\n", idx, F(br, 0x47C), (int)*(float*)(br + 0x20));
    }
    asLost[idx] = seen ? 0 : asLost[idx] + 1;
    if (!bigShot(v, br) || ++asT[idx] > AS_MAX || asLost[idx] > AS_LOST || d < AS_MIN || d < 0) {
        scePrintf("TMBR aim: car %d done after %d, %d shots\n", idx, asT[idx], asShots[idx]);
        asOn[idx] = 0; asTurbo[idx] = AS_TURBO;
        if (bigShot(v, br)) F(br, 0x47C) = 0;          /* (gave up with it still up: pick again) */
        return 0;
    }
    sp = cok[idx] ? iabs(cvx[idx]) + iabs(cvy[idx]) : 0;
    pad[4] = 0; pad[7] = 0; pad[2] = 0;
    pad[6] = sp > 6;                                   /* brake while still moving (x4 units per frame) */
    pad[9] = 0; pad[0xA] = 0;
    duty = a < AS_TIGHT ? 0 : a < AIM_1 ? 1 : a < AIM_2 ? 2 : 4;
    if (duty && ((asT[idx] + idx) & 3) < duty) { if (b > 0) pad[0xA] = 1; else pad[9] = 1; }
    if (sp <= 6 && a > AIM_3) pad[4] = 1;              /* stopped and far off: creep round on the gas */
    if (asGap[idx] > 0) asGap[idx]--;
    if (a < AS_TIGHT && asGap[idx] == 0 && seen) { aiSetAttackState(v, 7); asShots[idx]++; asGap[idx] = AS_GAP; dbgShots[idx]++; }
    else if (F(br, 0x414) == 7) aiSetAttackState(v, 5);   /* the AI's own fire request waits for the line-up */
    dbgWhy[idx] = 60;
    return 1;
}

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
    /* (2026-10-25 Ark: lots of wild shots with no chance. Straight weapons only when lined up (FIRE_TIGHT ~15 deg)
     * and within FIRE_NEAR; homing (AI weapon 3) keeps the wider cone and range - it turns; the special keeps the
     * game's own line-up rules.) */
    /* lock-on (Ark: bots fired homing before the reticle locked): the target must stay inside LOCK_ANG, in sight,
     * for LOCK_T frames before a homing missile goes - like a player waiting for the red reticle */
    if (d >= 0 && d < FIRE_DIST && a < LOCK_ANG && (F(br, 0x598) || F(br, 0x4B0) < 10)) { if (lockT[idx] < 100) lockT[idx]++; }
    else lockT[idx] = 0;
    if (aimShot(g, v, idx, b, a, d)) return;                  /* stopped, lining up a big straight shot */
    if (charging(g, v, idx)) { /* holding the reticle charge: no trigger */ }
    else if ((st == 5 || st == 6) && d >= 0 && (F(br, 0x598) || F(br, 0x4B0) < 10) && F(br, 0x47C) != 1 &&
        (F(br, 0x47C) == 3 ? (lockT[idx] >= LOCK_T && d < FIRE_DIST) : (a < FIRE_TIGHT && d < FIRE_NEAR))) {
        aiSetAttackState(v, 7); dbgShots[idx]++;
    }
    if (F(v, 0x444) >= 60) { dbgWhy[idx] = 3; return; }        /* stuck: the AI's own reverse/turn */
    if (d < 0 || d > CS_DIST) { dbgWhy[idx] = 5; ph[idx] = 0; return; }
    pad[4] = 1; pad[6] = 0; pad[8] = 0;                         /* in a fight: stay on the gas */
    /* standoff: nose-on and close, a bot coasts (< 150) or brakes (< 90) instead of driving into its target;
     * the original and the old pass rammed and fired point blank */
    /* (2026-10-25: never a full stop any more - in a crowd there is always a car close ahead, and bots braked to
     * a halt and sat. Coast at most STAND_MAX frames; inside STANDOFF_BRAKE veer past it on the gas instead of
     * braking, like a player's strafing pass; the dogfight logic swings back round once it is off the nose.) */
    if (ROLE(v) != R_SNIPER && a < CS_HB && ph[idx] == 0 && d < STANDOFF) {
        if (d < STANDOFF_BRAKE) {
            pad[4] = 1; pad[6] = 0; standT[idx] = 0;
            if (b > 0) { pad[9] = 1; pad[0xA] = 0; } else { pad[0xA] = 1; pad[9] = 0; }   /* steer away: pass it */
            dbgWhy[idx] = 40;
            return;
        }
        if (++standT[idx] < STAND_MAX) { pad[4] = 0; dbgWhy[idx] = 41; }
        else if (standT[idx] > STAND_MAX + 60) standT[idx] = 0;                 /* 1 s on the gas, then may coast again */
    } else standT[idx] = 0;
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
    if (flank(g, v, t, idx, b, a, d, tf)) return;
    if (a < CS_AIM && ph[idx] != 1 && ph[idx] != 4) {
        /* nearly lined up: fine aim (2026-10-25 Ark: the AI's own aim sawed back and forth). No steering inside
         * AIM_DEAD; outside it, steer toward the target only part of the frames, more the further off: 1 in 4 up
         * to ~6 deg, 2 in 4 to ~9 deg, 3 in 4 to ~14 deg, every frame beyond - small corrections settle instead of
         * overshooting at speed. */
        int duty = a < AIM_DEAD ? 0 : a < AIM_1 ? 1 : a < AIM_2 ? 2 : a < AIM_3 ? 3 : 4;
        dbgWhy[idx] = 6; ph[idx] = 0;
        pad[9] = 0; pad[0xA] = 0; pad[2] = 0;
        if (duty && ((thinkTick + idx) & 3) < duty) { if (b > 0) pad[0xA] = 1; else pad[9] = 1; }
        return;
    }
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
static float unstAt[8][4];          /* where each bot last needed an unstick ([3] != 0: set) */
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
            /* stuck again where it got stuck last time (Prison Passage pockets): reversing out is not enough,
             * the route leads straight back in -> drop the target and head for the far side of the map */
            if (unstAt[i][3] != 0 && fbits(manhat(p, unstAt[i])) < 0x43160000) {    /* < 150.0 */
                char* drv = (char*)F(v, 0x2018);
                if (drv) { leaveT[i] = 16 + mathfRandI(0, 10); cruiseFar(g, v, drv); }
#if TMBR_NAV
                tmbr_NavRoamFar(g, v);
#endif
            }
            unstAt[i][0] = p[0]; unstAt[i][1] = p[1]; unstAt[i][2] = p[2]; unstAt[i][3] = p[0] == 0 ? 1 : p[0];
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

/* ---- Dodging: incoming weapons (the weapon table at game+0x6C3C0, 200 x 0x210: +0 in use, +0x130 the firing
 * car, +0x200 its cs, position at cs+0x10; +0x14 is the weapon kind but its numbering isn't mapped yet, so shots
 * are told apart by how they move). Positions are snapshot every frame (tmbr_DodgeFrame, nav.c's frame hook):
 *  - straight (power missile, ricochet, fire missile mostly): will pass within DODGE_MISS in 0.25-1.2 s ->
 *    swerve off its line for ~0.4 s after the reaction delay;
 *  - homing (its heading keeps turning): sidestepping early just gets followed; wait until it is a few frames
 *    out and then turn hard across its path (handbrake) so it overshoots. The wait is the skill: hard turns at
 *    ~8 frames, easy at ~18 (too early, the missile re-aims);
 *  - lobbed (napalm, gas can, remote bomb throw: falling): work out where it lands; if that's on us, drive
 *    away from the landing point until it's down.
 * Each bot rolls once per shot (difficulty: chance, reaction delay). Units: x/y x4, z x16 fixed point. */
#define NW 200
#define DODGE_MISS 45
static int wpx[NW], wpy[NW], wpz[NW], wvx[NW], wvy[NW], wvz[NW], wax[NW];
static unsigned char wok[NW], wturn[NW], wfall[NW];
static int bpx[8], bpy[8];
static unsigned char wSeen[NW], wkCount[32][32];
static short dodgeT[8], reactT[8], judged[8], hWait[8], dodgeHb[8], pendT[8];
static int dodgeX[8], dodgeY[8], dodgeF[8];   /* dodgeF: blend in the car's heading */
static const unsigned char dodgeDelay[3] = { 24, 14, 8 }, dodgeChance[3] = { 30, 55, 80 }, homingTurn[3] = { 18, 12, 8 };
static const float FX[2] = { 4.0f, 16.0f };
void tmbr_DodgeFrame(void)
{
    char* g = D_004FA030;
    int i, x, y, z, vx, vy, vz, c, sp;
    if (!g || tmbr_botCount < 0) return;
    for (i = 0; i < NW; i++) {
        char* w = g + 0x6C3C0 + i * 0x210;
        char* cs = (char*)F(w, 0x200);
        /* +0x200 is not a model pointer for every weapon kind (a float there faulted, log 2026-10-24): RAM only */
        if (!F(w, 0) || (u32)cs < 0x100000 || (u32)cs >= 0x2000000 || ((u32)cs & 3)) { wok[i] = 0; wturn[i] = 0; wfall[i] = 0; continue; }
        x = (int)(*(float*)(cs + 0x10) * FX[0]); y = (int)(*(float*)(cs + 0x14) * FX[0]); z = (int)(*(float*)(cs + 0x18) * FX[1]);
        if (wok[i]) {
            vx = x - wpx[i]; vy = y - wpy[i]; vz = z - wpz[i];
            if (wok[i] >= 2) {
                /* turning: heading change per frame > ~1 degree, three frames running */
                c = wvx[i] * vy - wvy[i] * vx; if (c < 0) c = -c;
                sp = vx * vx + vy * vy;
                if (sp > 16 && c > sp / 50) { if (wturn[i] < 10) wturn[i]++; } else wturn[i] = 0;
                /* falling: vertical speed dropping (gravity), two frames running */
                wax[i] = vz - wvz[i];
                if (wax[i] < -1) { if (wfall[i] < 10) wfall[i]++; } else wfall[i] = 0;
            }
            wvx[i] = vx; wvy[i] = vy; wvz[i] = vz;
        }
        wpx[i] = x; wpy[i] = y; wpz[i] = z;
        if (wok[i] < 3) wok[i]++;
    }
    /* weapon kinds (2026-10-25): which kind each car's shots are, logged the first times each (kind, car, AI weapon)
     * turns up - the map for the shield / freeze dodge and the Spectre balance. "TMBR wk: kind K car C aiw W" */
    for (i = 0; i < NW; i++) {
        char* w = g + 0x6C3C0 + i * 0x210;
        char *own, *obr;
        int kind, ch, aw;
        if (!F(w, 0)) { wSeen[i] = 0; continue; }
        if (wSeen[i]) continue;
        wSeen[i] = 1;
        kind = F(w, 0x14) & 31; own = (char*)F(w, 0x130);
        if (!kind || (u32)own < 0x100000 || (u32)own >= 0x2000000) continue;
        ch = (F(own, 0x20F4) >> 5) & 31;
        obr = (char*)F(own, 0x2014);
        aw = obr && (u32)obr >= 0x100000 && (u32)obr < 0x2000000 ? F(obr, 0x47C) & 7 : 7;
        {   /* shots made within 4 frames of a bot's freeze request: the freeze's kind */
            int oi = (int)(own - g) / 0x31B0 & 7, fz = thinkTick - frzAt[oi] >= 0 && thinkTick - frzAt[oi] < 4;
            if (fz) scePrintf("TMBR wk: FREEZE kind %d car %d\n", kind, ch);
        }
        if (wkCount[kind][ch] < 2) { wkCount[kind][ch]++; scePrintf("TMBR wk: kind %d car %d aiw %d\n", kind, ch, aw); }
    }
    for (i = 0; i < 8; i++) {                       /* every car's position and motion (evade) */
        char* v = g + i * 0x31B0;
        char* cs;
        if (!live(v) || !(cs = (char*)F(v, 0x2028))) { cok[i] = 0; continue; }
        x = (int)(*(float*)(cs + 0x10) * FX[0]); y = (int)(*(float*)(cs + 0x14) * FX[0]);
        if (cok[i]) { cvx[i] = x - cpx[i]; cvy[i] = y - cpy[i]; }
        cpx[i] = x; cpy[i] = y; cok[i] = cok[i] < 2 ? cok[i] + 1 : 2;
    }
}
extern int tmbr_SameTeam(char* a, char* b);
extern float tmbr_NavSteer(char* v, float dx, float dy, int gas);
static void dodgeStart(int k, int vx, int vy, int dx, int dy)
{
    int n = iabs(vx) + iabs(vy);
    if (!n) n = 1;
    if (vx * dy - vy * dx > 0) { dodgeX[k] = -vy * 100 / n; dodgeY[k] = vx * 100 / n; }
    else { dodgeX[k] = vy * 100 / n; dodgeY[k] = -vx * 100 / n; }
}
static void dodge(char* g, char* v)
{
    int k = (int)(v - g) / 0x31B0 & 7, i, x, y, z, fx, fy, n;
    int diff = tmbr_botDiff < 0 ? 0 : tmbr_botDiff > 2 ? 2 : tmbr_botDiff;
    char* cs = (char*)F(v, 0x2028);
    unsigned char* pad = (unsigned char*)v + 0x594;
    x = (int)(*(float*)(cs + 0x10) * FX[0]); y = (int)(*(float*)(cs + 0x14) * FX[0]); z = (int)(*(float*)(cs + 0x18) * FX[1]);
    fx = x - bpx[k]; fy = y - bpy[k];                /* our own motion per frame */
    bpx[k] = x; bpy[k] = y;
    if (*(signed char*)(v + 0x497) >= 4 || F(v, 0x444) >= 30) { dodgeT[k] = reactT[k] = hWait[k] = 0; return; }
    if (dodgeT[k] > 0) {
        int ox = dodgeX[k], oy = dodgeY[k];
        n = iabs(fx) + iabs(fy);
        if (dodgeF[k] && n > 0) { ox += fx * 100 / n; oy += fy * 100 / n; }
        tmbr_NavSteer(v, (float)ox, (float)oy, 1);
        if (dodgeHb[k] > 0) { pad[2] = 1; dodgeHb[k]--; }
        else if (diff == 2) pad[7] = 1;            /* hard: turbo out of it */
        dodgeT[k]--;
        return;
    }
    if (hWait[k]) {                                 /* homing: wait for the moment to turn */
        int w = hWait[k] - 1, vx = wvx[w], vy = wvy[w], dx, dy, sp, t;
        if (wok[w] < 3) { hWait[k] = 0; return; }
        dx = x - wpx[w]; dy = y - wpy[w];
        sp = vx * vx + vy * vy;
        if (sp < 16 || dx * vx + dy * vy <= 0 || iabs(dx) + iabs(dy) > 4 * 900) { hWait[k] = 0; return; }   /* lost us */
        t = (iabs(dx) + iabs(dy)) / (iabs(vx) + iabs(vy) + 1);
        if (t <= homingTurn[diff]) {
            dodgeStart(k, vx, vy, dx, dy);
            dodgeF[k] = 0; dodgeHb[k] = 6; dodgeT[k] = 14; hWait[k] = 0;
            if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d breaks from homing shot %d at %d frames\n", k, w, t);
        }
        return;
    }
    if (reactT[k] > 0) { if (--reactT[k] == 0) dodgeT[k] = pendT[k]; return; }
    for (i = 0; i < NW; i++) {
        char* w = g + 0x6C3C0 + i * 0x210;
        char* own;
        int vx, vy, dx, dy, sp, dot, t, cx, cy, kind;
        if (wok[i] < 3 || !F(w, 0)) continue;
        own = (char*)F(w, 0x130);
        if (own == v || (own && tmbr_SameTeam(own, v))) continue;
        dx = x - wpx[i]; dy = y - wpy[i];
        if (iabs(dx) + iabs(dy) > 4 * 1500) continue;
        vx = wvx[i]; vy = wvy[i];
        sp = vx * vx + vy * vy;
        if (sp < 36) continue;                     /* parked (mines, a remote bomb on the ground) */
        dot = dx * vx + dy * vy;
        if (dot <= 0) continue;                    /* going away */
        kind = wfall[i] >= 2 ? 3 : wturn[i] >= 3 ? 2 : 1;
        if (kind == 3) {                           /* lobbed: where does it come down? */
            int dz = wpz[i] - z, vz = wvz[i], a = wax[i], lx, ly;
            for (t = 1; t < 120; t++) if (dz + vz * t + a * t * t / 2 <= 0) break;
            if (t >= 120 || t < 6) continue;
            lx = wpx[i] + vx * t - (x + fx * t); ly = wpy[i] + vy * t - (y + fy * t);   /* landing vs where we'll be */
            if (iabs(lx) + iabs(ly) > 4 * 90) continue;
            if (judged[k] == i + 1) return;
            judged[k] = i + 1;
            if (mathfRandI(0, 99) >= dodgeChance[diff]) return;
            n = iabs(lx) + iabs(ly); if (!n) { lx = -fy; ly = fx; n = iabs(lx) + iabs(ly) + 1; }
            dodgeX[k] = -lx * 100 / n; dodgeY[k] = -ly * 100 / n;   /* away from the landing point */
            dodgeF[k] = 1; dodgeHb[k] = 0;
            pendT[k] = t + 10 - dodgeDelay[diff];
            if (pendT[k] < 8) pendT[k] = 8;
            reactT[k] = dodgeDelay[diff];
            if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d sees lobbed shot %d landing in %d\n", k, i, t);
            return;
        }
        if (kind == 2) {                           /* homing: coming our way at all? */
            if (iabs(dx * vy - dy * vx) > dot) continue;   /* heading within ~45 degrees of us */
            if (iabs(dx) + iabs(dy) > 4 * 700) continue;
            if (judged[k] == i + 1) return;
            judged[k] = i + 1;
            if (F(w, 0x14) != 14 && mathfRandI(0, 99) >= dodgeChance[diff]) return;   /* a freeze (14): always */
            hWait[k] = i + 1;
            if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d tracks homing shot %d\n", k, i);
            return;
        }
        t = dot / sp;                              /* straight: frames to the closest point */
        if (t < 15 || t > 72) continue;
        cx = dx - vx * t; cy = dy - vy * t;
        if (iabs(cx) + iabs(cy) > 4 * DODGE_MISS * 2) continue;
        if (cx * cx + cy * cy > 16 * DODGE_MISS * DODGE_MISS) continue;
        if (judged[k] == i + 1) return;            /* rolled for this shot already */
        judged[k] = i + 1;
        if (F(w, 0x14) != 14 && mathfRandI(0, 99) >= dodgeChance[diff]) return;       /* a freeze (14): always */
        dodgeStart(k, vx, vy, dx, dy);
        dodgeF[k] = 1; dodgeHb[k] = 0; pendT[k] = 25;
        reactT[k] = dodgeDelay[diff] + mathfRandI(0, dodgeDelay[diff] / 2);
        if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d sees shot %d (%d frames, miss %d)\n", k, i, t, (iabs(cx) + iabs(cy)) / 4);
        return;
    }
}

/* ---- Evading a chaser (2026-10-25: a low-health bot drove in a straight line and let a player pile on with
 * machine guns). An enemy within EV_DIST, behind us (within 45 deg of straight back) and heading at us (within
 * 45 deg), for EV_SEE frames = being chased: turbo and weave (steer side to side in 10-18 frame swings, gas on).
 * Hurt (< 50 %) with the chaser close (< EV_TURN): sometimes a handbrake 180 to turn and fight instead.
 * Not while lined up on our own target ahead (then we are the attacker). Easy: weave only; medium: + turbo;
 * hard: + the 180 more often. */
#define EV_DIST 350
#define EV_SEE 20
#define EV_TURN 160
static short evSeen[8], evT[8], evSw[8], evHb[8]; static signed char evDir[8];
static int evade(char* g, char* v)
{
    int k = (int)(v - g) / 0x31B0 & 7, j, fx = cvx[k], fy = cvy[k], best = -1, bd = 0x7FFFFFFF;
    int diff = tmbr_botDiff < 0 ? 0 : tmbr_botDiff > 2 ? 2 : tmbr_botDiff;
    char *br = (char*)F(v, 0x2014), *drv = (char*)F(v, 0x2018);
    unsigned char* pad = PAD(v);
    if (!br || !drv || !cok[k] || *(signed char*)(v + 0x497) >= 4 || F(v, 0x444) >= 30) { evSeen[k] = evT[k] = 0; return 0; }
    if (evHb[k] > 0) {                                     /* the 180: full lock + handbrake, gas */
        evHb[k]--; pad[2] = 1; pad[4] = 1; pad[6] = 0; pad[7] = 0;
        if (evDir[k] > 0) { pad[9] = 1; pad[0xA] = 0; } else { pad[0xA] = 1; pad[9] = 0; }
        return 1;
    }
    if (iabs(fx) + iabs(fy) < 4 * 2) { evSeen[k] = 0; evT[k] = 0; return 0; }   /* hardly moving */
    for (j = 0; j < 8; j++) {
        char* c = g + j * 0x31B0;
        int dx, dy, dot, crs, mdot, mcrs, d;
        if (j == k || !cok[j] || !live(c)) continue;
        if (tmbr_Opt(OPT_TEAMS) && tmbr_TeamOf(c) == tmbr_TeamOf(v)) continue;
        dx = cpx[j] - cpx[k]; dy = cpy[j] - cpy[k];
        d = iabs(dx) + iabs(dy);
        if (d > 4 * EV_DIST || d >= bd) continue;
        dot = fx * dx + fy * dy; crs = iabs(fx * dy - fy * dx);
        if (dot >= 0 || crs > -dot) continue;              /* not behind us */
        mdot = -(cvx[j] * dx + cvy[j] * dy); mcrs = iabs(cvx[j] * dy - cvy[j] * dx);
        if (mdot <= 0 || mcrs > mdot) continue;            /* not coming at us */
        best = j; bd = d;
    }
    if (best < 0) { if (evSeen[k] > 0) evSeen[k]--; if (evT[k] > 0) evT[k]--; return 0; }
    {   /* lined up on our own target in front, close: keep attacking */
        int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, d = fbits(*(float*)(br + 0x20));
        if (F(drv, 4) == 5 && a < CS_HB && d >= 0 && d < CS_DIST && hpPct(v) >= 50) { evSeen[k] = 0; return 0; }
    }
    if (evSeen[k] < EV_SEE) { evSeen[k]++; return 0; }
    if (evT[k] == 0) {                                     /* a new chase: maybe turn the tables */
        int chance = diff == 2 ? 45 : diff == 1 ? 25 : 0;
        evT[k] = 90;
        if (hpPct(v) < 50 && bd < 4 * EV_TURN && mathfRandI(0, 99) < chance) {
            evHb[k] = 22; evDir[k] = mathfRandI(0, 1) ? 1 : -1; evSeen[k] = 0; evT[k] = 0;
            if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d turns on its chaser %d\n", k, best);
            return 1;
        }
        evSw[k] = 0; evDir[k] = mathfRandI(0, 1) ? 1 : -1;
        if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d evades chaser %d\n", k, best);
    }
    evT[k] = 90;                                           /* refreshed while the chase goes on */
    if (--evSw[k] <= 0) { evSw[k] = 10 + mathfRandI(0, 8); evDir[k] = -evDir[k]; }
    pad[4] = 1; pad[6] = 0; pad[2] = 0;
    if (diff >= 1) pad[7] = 1;                             /* turbo (the game stops it when the bar is empty) */
    if (evDir[k] > 0) { pad[9] = 1; pad[0xA] = 0; } else { pad[0xA] = 1; pad[9] = 0; }
    return 1;
}

/* ---- Turbo (2026-10-25): bots get a passive recharge on top of the game's (empty to full in TB_REFILL frames)
 * and use it like players do: down a straight (driving straight TB_STRAIGHT frames, keeping TB_RESERVE % for
 * escapes), on a ram run (lined up, 150-450 away) and after a target that pulls away. Turbo bar: vehicle +0x2288
 * current, +0x228C max (ints, Hud::updateEnergyAndTurbo 0x144AA8; +0x420 is the energy bar). */
#define TB_REFILL 360
#define TB_STRAIGHT 45
#define TB_RESERVE 35
static int tbAcc[8], tbOx[8], tbOy[8], tbStraight[8], tbLastD[8];
static void turboUse(char* g, char* v, int evading)
{
    int k = (int)(v - g) / 0x31B0 & 7, cur = F(v, 0x2288), max = F(v, 0x228C), pct, fx = cvx[k], fy = cvy[k];
    char *br = (char*)F(v, 0x2014), *drv = (char*)F(v, 0x2018);
    unsigned char* pad = PAD(v);
    if (max <= 0 || !br || !drv) return;
    if (cur < max) {                                       /* passive recharge */
        tbAcc[k] += max;
        while (tbAcc[k] >= TB_REFILL && cur < max) { cur++; tbAcc[k] -= TB_REFILL; }
        F(v, 0x2288) = cur;
    } else tbAcc[k] = 0;
    pct = cur * 100 / max;
    /* driving straight: the motion's direction now vs ~10 frames ago (within ~11 deg), at speed */
    if ((thinkTick % 10) == 0) {
        int dot = fx * tbOx[k] + fy * tbOy[k], crs = iabs(fx * tbOy[k] - fy * tbOx[k]);
        if (iabs(fx) + iabs(fy) >= 4 * 4 && dot > 0 && crs * 5 < dot) tbStraight[k] += 10; else tbStraight[k] = 0;
        tbOx[k] = fx; tbOy[k] = fy;
    }
    if (evading || pad[6] || pad[2] || *(signed char*)(v + 0x497) >= 4) return;   /* (evade does its own) */
    if (tbStraight[k] >= TB_STRAIGHT && pct > TB_RESERVE) pad[7] = 1;           /* open road */
    if (ramT[k] > 0) {                                                          /* special ram (Darkside, Yellow Jacket) */
        int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, d = (int)*(float*)(br + 0x20);
        ramT[k]--; pad[7] = 1;
        /* Darkside's T-slide (side-on hit, 50 vs 38 for a ram - Ark 2026-10-25; experimental): at ~90 out and lined
         * up, 40 % of rams flick the handbrake with full lock for 10 frames so the side lands on the target */
        if (charOf(v) == CH_DARKSIDE && tslT[k] == 0 && d > 50 && d < 100 && a < CS_AIM && mathfRandI(0, 99) < 40) {
            tslT[k] = 10; tslDir[k] = (fbits(*(float*)(br + 0x24)) >> 31) ? -1 : 1;
        }
    }
    if (tslT[k] > 0) {
        tslT[k]--; pad[2] = 1; pad[4] = 1; pad[6] = 0;
        if (tslDir[k] > 0) { pad[0xA] = 1; pad[9] = 0; } else { pad[9] = 1; pad[0xA] = 0; }
    }
    /* on fire (SetCarOnFire 0x1E4FF0: +0x20E0 == 1 burning, +0x470 burn timer): turbo to shake the flames off, as
     * players do (Ark 2026-10-25) - not while lined up close on a target with the upper hand */
    if (F(v, 0x20E0) == 1 && pct > 5) {
        int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, d = (int)*(float*)(br + 0x20);
        char* tg = (char*)F(drv, 0xB4);
        if (!(tg && a < CS_AIM && d > 0 && d < 200 && hpPct(v) > hpPct(tg))) pad[7] = 1;
    }
    if (F(drv, 4) == 5 && F(drv, 0xB4)) {
        int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, d = fbits(*(float*)(br + 0x20)), dist = (int)*(float*)(br + 0x20);
        if (a < CS_AIM && d > STANDOFF && d < 0x43E10000 && pct > 20) pad[7] = 1;   /* ram run: 150..450 */
        if (a < CS_HB && dist > 300 && dist > tbLastD[k] + 2 && pct > 25) pad[7] = 1;   /* it is getting away */
        tbLastD[k] = dist;
    }
}

/* ---- Energy moves (2026-10-25: bots never used any). The vehicle update's energy handler (func_001E4690) takes
 * the move from the player's combo for a human and from brain +0x418 for a bot (combo.hpp COMBO_TYPE_*: 1 freeze,
 * 3 rear fire, 4 mine, 6 gas can, 7 shield, 8 cloak), with the game's own energy rules. The original AI only sets
 * it in narrow cases (aiUpdateAttack, func_00107580); the AI frame clears it, so ours goes in after it.
 *  - shield: a shot that hits within EN_SHIELD_T frames and is not being dodged; only then, and with energy
 *    kept for later unless the hit could kill (a full bar is about two shields - Ark);
 *  - freeze: a lined-up target in range, to set up the big hit (the next weapon pick favours special / power /
 *    napalm / ricochet: setupT), more often on a target getting away or hurt; Darkside and Yellow Jacket freeze
 *    before their special ram;
 *  - mine: dropped on a chaser right behind (the evade code's chase).
 * Energy: vehicle +0x420 (0..100). */
#define EN_FREEZE 1
#define EN_MINE 4
#define EN_SHIELD 7
#define EN_SHIELD_T 12
#define FRZ_CD 900      /* 15 s between a bot's freezes */
static short enCd[8];
extern int aiGoodChoice3(char* v, int w) __asm__("aiIsGoodWeaponChoice__7Vehiclei");
static signed char altFire[8];
static short altCd[8], altChk[8];      /* frames until the special goes after arming its second mode (TODO 7) */
static int incoming(char* g, char* v, int k)
{
    int i, best = 999;
    for (i = 0; i < NW; i++) {
        char* w = g + 0x6C3C0 + i * 0x210;
        char* own;
        int dx, dy, vx, vy, sp, dot, t, cx, cy;
        if (wok[i] < 3 || !F(w, 0)) continue;
        own = (char*)F(w, 0x130);
        if (own == v || (own && tmbr_SameTeam(own, v))) continue;
        {   /* only hits worth a shield: not machine gun (0), fire (2) / homing (3) missiles, 15; the freeze (14) is -
             * weapon kinds from the TMBR wk log 2026-10-25 (napalm 4, power 6, rico 7, pickups 11-13, specials
             * 17 Roadkill, 21 Spectre, 26 Grimm, 27 Axel, 28 Manslaughter; anything not seen yet counts as big) */
            int kd = F(w, 0x14);
            if (kd == 0 || kd == 2 || kd == 3 || kd == 15) continue;          /* (14 is the freeze: worth it) */
        }
        dx = cpx[k] - wpx[i]; dy = cpy[k] - wpy[i];
        if (iabs(dx) + iabs(dy) > 4 * 600) continue;
        vx = wvx[i]; vy = wvy[i]; sp = vx * vx + vy * vy;
        if (sp < 36) continue;
        dot = dx * vx + dy * vy;
        if (dot <= 0 || iabs(dx * vy - dy * vx) * 2 > dot) continue;   /* not coming at us (within ~27 deg) */
        t = dot / sp;
        if (wturn[i] < 3) {                                            /* straight: does it pass close? */
            cx = dx - vx * t; cy = dy - vy * t;
            if (iabs(cx) + iabs(cy) > 4 * 60) continue;
        }
        if (t < best) best = t;
    }
    return best;
}
static void energyUse(char* g, char* v, int evading)
{
    int k = (int)(v - g) / 0x31B0 & 7, en, hp, t;
    char *br = (char*)F(v, 0x2014), *drv = (char*)F(v, 0x2018);
    if (!br || !drv || *(signed char*)(v + 0x497) >= 4 || !cok[k]) return;
    if (enCd[k] > 0) enCd[k]--;
    if (setupT[k] > 0) setupT[k]--;
    if (altCd[k] > 0) altCd[k]--;
    if (altChk[k] > 0 && --altChk[k] == 0 && F(v, 0x21B4))   /* the special clears the flag when it goes (test
                                                              * 2026-10-26: mostly within 0.5 s); if it did not
                                                              * go, drop it so a later forward shot stays forward */
        F(v, 0x21B4) = 0;
    if (altFire[k] > 0 && --altFire[k] == 0) {   /* the second mode flag (launcher +4) and the special now - the
                                                  * special-up combo (energy 9) did not set it for them (test) */
        if (charOf(v) == 9) { *(v + 0x5A3) = 1; F(v, 0x2778) = 1; *(v + 0x5B5) = 0; }
        else if (charOf(v) == 11) { *(v + 0x5A3) = 1; F(v, 0x24F8) = 1; *(v + 0x5B5) = 0; }
        else { F(v, 0x21B4) = 1; altChk[k] = 30; }
        F(br, 0x47C) = 1; aiSetAttackState(v, 7);
    }
    if (enCd[k]) return;
    en = (int)*(float*)(v + 0x420); hp = hpPct(v);
    t = incoming(g, v, k);
    if (t <= EN_SHIELD_T && (!(dodgeT[k] || reactT[k] || hWait[k]) || t <= 5)) {
        if ((hp < 30 && en >= 40) || (en >= 90 && (hp < 70 || mathfRandI(0, 99) < 50))) {
            F(br, 0x418) = EN_SHIELD; enCd[k] = 90;
            if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d shields (hit in %d, energy %d, hp %d)\n", k, t, en, hp);
            return;
        }
    }
    if (evading && en >= 60 && mathfRandI(0, 99) < 3) {           /* (~once a second while chased) */
        F(br, 0x418) = EN_MINE; enCd[k] = 180;
        if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d drops a mine on its chaser\n", k);
        return;
    }
    /* (TODO 7) Outlaw / Manslaughter: second special mode when the AI could fire the special (its own check:
     * aiIsGoodWeaponChoice(v, 1) - +0x22B0 stays 0 for them) */
    if ((charOf(v) == 3 || charOf(v) == CH_MANSLAUGHTER) && F(drv, 4) == 5 && F(drv, 0xB4) && !altFire[k] && !altCd[k] &&
        (thinkTick + k * 11) % 45 == 0) {
        extern int aiGoodChoice2(char* v, int w) __asm__("aiIsGoodWeaponChoice__7Vehiclei");
        char* tg = (char*)F(drv, 0xB4);
        int d = (int)*(float*)(br + 0x20), c = charOf(v), a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF;
        (void)tg;
        if (aiGoodChoice2(v, 1) &&
            ((c == CH_MANSLAUGHTER && d > 0 && d < 200 && a > 0x401B0000 && mathfRandI(0, 99) < 60) ||
             (c == 3 && d > 100 && d < 350 && mathfRandI(0, 99) < 35))) {
            altFire[k] = 3; altCd[k] = 360;       /* (once per 6 s at most) */
            scePrintf("TMBR bots: car %d (char %d) second special mode, d %d\n", k, c, d);
            return;
        }
    }
    /* Shadow / Axel: their second special the same way. The special-up combo (energy 9) only switches it while the
     * special is the selected weapon (+0x21B0 == 1, which a bot's never is between shots) - +0x22B0 stayed 0 for
     * bots (test 2026-10-26), so the old request never fired. altFire sets what the combo would: Shadow +0x5A3 = 1,
     * +0x2778 = 1, +0x5B5 = 0; Axel +0x5A3 = 1, +0x24F8 = 1, +0x5B5 = 0 (func_001E4690 0x1E4D20..). */
    if (F(drv, 4) == 5 && F(drv, 0xB4) && !altFire[k] && !altCd[k] && (thinkTick + k * 11) % 45 == 0 && aiGoodChoice3(v, 1)) {
        char* tg = (char*)F(drv, 0xB4);
        int tk = (int)(tg - g) / 0x31B0 & 7, d = (int)*(float*)(br + 0x20), c = charOf(v);
        if ((c == 9 && crowd[tk] < 2 && d > 0 && d < 300 && mathfRandI(0, 99) < 40) ||
            (c == 11 && crowd[tk] == 0 && d > 0 && d < 250 && mathfRandI(0, 99) < 50)) {
            altFire[k] = 3; altCd[k] = 360;
            scePrintf("TMBR bots: car %d (char %d) alternate special, d %d\n", k, c, d);
            return;
        }
    }
    /* (2026-10-25 Ark: far too many freezes. Now: checked every 1 s, 5 % (hurt / escaping target 15 %, rammer
     * before its ram 25 %), only with energy left for a shield afterwards (>= 80), only when a big hit is ready
     * (special charged, or a rammer), and at most one per FRZ_CD frames.) */
    if (F(drv, 4) == 5 && F(drv, 0xB4) && (thinkTick + k * 7) % 60 == 0 && en >= 80 && (F(v, 0x22B0) == 1 || rammer(v))) {   /* (+0x22B0 stays 0 for bots: in effect rammers only - as tuned) */
        char* tg = (char*)F(drv, 0xB4);
        int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, d = (int)*(float*)(br + 0x20), chance = 5;
        if (a < FIRE_TIGHT && d > 60 && d < 350) {
            if (hpPct(tg) < 40 || d > tbLastD[k] + 2) chance = 15;                 /* hurt or getting away */
            if (rammer(v) && d < 300) chance = 25;                                 /* before the special ram */
            if (mathfRandI(0, 99) < chance) {
                F(br, 0x418) = EN_FREEZE; enCd[k] = FRZ_CD; setupT[k] = 150; frzAt[k] = thinkTick;
                if (TMBR_BOTDBG) scePrintf("TMBR bots: car %d freezes its target at %d\n", k, d);
            }
        }
    }
}


/* ---- wall / hill avoidance (Ark 2026-10-25: bots still drove into hills and walls) ----
 * Every AV_EVERY frames each bot moving forward feels ahead on the baked route map (navbake.c tmbr_NavFeel:
 * drivable links straight on and 45 deg left / right, up to AV_LOOK cells, ~130-160 units). Blocked closer than
 * AV_NEAR cells straight on: steer to the freer side for AV_HOLD frames (both sides equal: keep the side the
 * wheel already turns to). Not while ramming a target dead ahead, reversing, or before the unstick code. */
#define AV_EVERY 4
#define AV_LOOK 4
#define AV_NEAR 3
#define AV_HOLD 8
extern int tmbr_NavFeel(void* p, float fx, float fy, int maxc, int* l, int* r);   /* navbake.c */
extern int tmbr_NavFollowing(char* v);   /* nav.c */
static signed char avDir[8], avT[8];
static void avoid(char* g, char* v)
{
    unsigned char* pad = PAD(v);
    char* br = (char*)F(v, 0x2014);
    char* cs = (char*)F(v, 0x2028);
    int idx = (int)(v - g) / 0x31B0, f, l, r;
    if (idx < 0 || idx > 7 || !cs || !br) return;
    if (avT[idx] > 0) {
        avT[idx]--;
        if (pad[6]) return;
        pad[9] = avDir[idx] < 0; pad[0xA] = avDir[idx] > 0;
        return;
    }
    if ((thinkTick + idx) % AV_EVERY || !pad[4] || pad[6] || tmbr_NavFollowing(v)) return;
    {   /* ramming / shooting a target right ahead: let it */
        int d = fbits(*(float*)(br + 0x20)), a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF;
        if (d >= 0 && d < OR_WIDE && a < CS_AIM) return;
    }
    /* forward = row 1 of the cs rotation (cs+0x20: m[4], m[5]) */
    f = tmbr_NavFeel(cs + 0x10, *(float*)(cs + 0x30), *(float*)(cs + 0x34), AV_LOOK, &l, &r);
    if (f < 0 || f >= AV_NEAR) return;
    avDir[idx] = l > r ? -1 : r > l ? 1 : (pad[9] ? -1 : pad[0xA] ? 1 : ((idx & 1) ? 1 : -1));
    avT[idx] = AV_HOLD;
    pad[9] = avDir[idx] < 0; pad[0xA] = avDir[idx] > 0;
}

static int aiUpdate(char* v);
extern void padClear(char* v) __asm__("vehicleSaveAndClearPadFlags__7Vehicle");
int tmbr_AiUpdate(char* v)
{
    int r;
    if (F(D_003156C0, 0x1BB4) == 0xA && F(v, 0x2014)) { padClear(v); return 0; }   /* sync hold: bots frozen */
    r = aiUpdate(v);
    /* match over (game type 1): the game stops every car - no dodging / unsticking then (log 2026-10-24) */
    if (tmbr_botCount >= 0 && F(v, 0x2014) && D_004FA030 && !(GINFO() && ((F(GINFO(), 0) >> 1) & 0xF) == 1)) {
        int ev = 0;
        dodge(D_004FA030, v);
        if (!dodgeT[(int)(v - D_004FA030) / 0x31B0 & 7]) ev = evade(D_004FA030, v);   /* (a dodge in progress wins) */
        turboUse(D_004FA030, v, ev || dodgeT[(int)(v - D_004FA030) / 0x31B0 & 7]);
        energyUse(D_004FA030, v, ev);
        avoid(D_004FA030, v);
        unstick(D_004FA030, v);
    }
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
#if TMBR_NAV
        tmbr_NavDrive(g, v, 0);          /* roam the route map */
#endif
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
    if (tmbr_botCount < 0 || !t || !F(t, 0x2028)) {
        t0 = tmbr_Cycles(); r = aiFrame(v); tmbr_PerfAdd(1, t0);
#if TMBR_NAV
        if (tmbr_botCount >= 0 && F(v, 0x2014)) tmbr_NavDrive(g, v, 0);
#endif
        return r;
    }
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

/* ---- weapons pass (bots, chosen count) ----
 * The attack state (aiUpdateAttack) keeps the current weapon while aiIsGoodWeaponChoice says it is in range and
 * angle (0x105BA0), else asks aiPickBestWeaponToFireNow (0x105BB0), which takes the first good one in a fixed
 * order: special, power missile (6), ricochet (7), homing (3), napalm (4), fire missile (2), pickup slot (5),
 * and tops the AI's ammo (car +0x2338[w]) back up to 1 so it never runs out. So bots fired their heaviest
 * weapons back to back. Now: heavy weapons (special, power, ricochet, napalm, pickup) have a cooldown per bot,
 * the pick is a weighted draw that favours fire / homing missiles, and a heavy weapon is only held briefly. */
extern int aiGoodChoice(char* v, int w) __asm__("aiIsGoodWeaponChoice__7Vehiclei");
extern void aiPickBest(char* v) __asm__("aiPickBestWeaponToFireNow__7Vehicle");
extern int mathfRandW(int lo, int hi) __asm__("mathfRand__Fii");
static int wpnClock;               /* = thinkTick */
static int wpnReady[8][8];         /* per car, per AI weapon: frame it can be picked again */
/* (wpnPicked[]: frame the current weapon was picked - declared with aimShot above) */
static signed char burstLeft[8];   /* missiles left in the current burst (fire / homing) */
#define BURST_CHANCE 45            /* % of fire / homing picks that start a burst (2026-10-25: chip damage like players) */
#define BURST_GAP 14               /* frames between missiles in a burst (~0.25 s) */
static int heavyW(int w) { return w == 1 || w >= 4; }
static int cooldown(int w)
{
    static const int heavy[3] = { 520, 300, 210 }, light[3] = { 60, 35, 25 };    /* frames: easy, medium, hard (2026-10-25: was 700/450/320, 90/60/40 - bots did little damage) */
    int d = tmbr_botDiff < 0 ? 0 : tmbr_botDiff > 2 ? 2 : tmbr_botDiff;
    if (w == 1) return heavy[d] * 3;                 /* special: ~15 s (medium) - players wait on the recharge (Ark: too many) */
    return heavyW(w) ? heavy[d] : light[d];
}
int tmbr_AiKeepWeapon(char* v, int w)
{
    int k = (int)(v - D_004FA030) / 0x31B0 & 7;
    if (tmbr_botCount < 0) return aiGoodChoice(v, w);
    wpnClock = thinkTick;
    if (heavyW(w) && wpnClock - wpnPicked[k] > 90) return 0;   /* heavy: held 1.5 s at most, then pick again */
    return aiGoodChoice(v, w);
}
void tmbr_AiPickWeapon(char* v)
{
    static const int weight[8] = { 0, 1, 6, 6, 2, 1, 2, 2 };
    char* br = (char*)F(v, 0x2014);
    int k = (int)(v - D_004FA030) / 0x31B0 & 7, w, total = 0, r, ok[8], los, spBoost = 0;
    wpnClock = thinkTick;                     /* frames (tmbr_BotsThink counts every frame) */
    if (tmbr_botCount < 0 || !br) { aiPickBest(v); return; }
    los = F(br, 0x598) || F(br, 0x4B0) < 10;  /* the game's own sight of the target (as the fire check above) */
    for (w = 1; w < 8; w++) {
        ok[w] = (wpnClock >= wpnReady[k][w] || (setupT[k] > 0 && heavyW(w))) && aiGoodChoice(v, w);   /* (frozen target: big hit) */
        if (ok[w] && w == 1 && rammer(v)) {
            /* ram specials: only on a close, lined-up target (then always) - Yellow Jacket in a crowd just fires it */
            char* t = (char*)F(F(v, 0x2018), 0xB4);
            int tk = t ? (int)(t - D_004FA030) / 0x31B0 & 7 : 0, dist = (int)*(float*)(br + 0x20);
            int lined = (fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF) < CS_AIM;
            if (charOf(v) == CH_YELLOWJ && t && crowd[tk] >= 2) { if (mathfRandW(0, 99) >= SPECIAL_CHANCE) ok[w] = 0; }
            else if (!(t && lined && dist > 0 && dist < 300)) ok[w] = 0;
            else ramT[k] = 90;                                /* 1.5 s of turbo into it (turboUse) */
        } else if (ok[w] && w == 1 && CAI(v)->on) {
            /* the car's special: alone in its range band, or at a group within gmax; some must be lined up */
            const CarAi* c = CAI(v);
            char* t = (char*)F(F(v, 0x2018), 0xB4);
            int tk = t ? (int)(t - D_004FA030) / 0x31B0 & 7 : 0, dist = (int)*(float*)(br + 0x20);
            int a = fbits(*(float*)(br + 0x24)) & 0x7FFFFFFF, good;
            good = t && dist > 0 && ((dist >= c->smin && dist <= c->smax) || (crowd[tk] >= 2 && dist <= c->gmax));
            if (c->aim && a >= 0x3E19999A) good = 0;                      /* 0.15 rad: squarely lined up */
            if (c->hp == 1 && t && hpPct(t) < 50) good = 0;               /* to weaken */
            if (c->hp == 2 && t && hpPct(t) >= 50) good = 0;              /* to finish */
            {   /* the special would finish it: sometimes (a third of the time) - not when anything finishes it */
                int th = t ? (int)*(float*)(t + 0x404) : 999;
                if (t && c->dmg && th > 10 && th <= c->dmg && dist > 0 && dist <= (c->smax > 300 ? c->smax : 300) &&
                    !(c->aim && a >= 0x3F19999A) && mathfRandW(0, 99) < 20) good = 1;
            }
            if (!good && mathfRandW(0, 99) >= 3) ok[w] = 0;               /* (now and then anyway: unpredictable) */
            else if (good) spBoost = 1;
        } else if (ok[w] && w == 1 && mathfRandW(0, 99) >= SPECIAL_CHANCE) ok[w] = 0;
        /* in a burst without sight of the target: no fire missiles (straight into the wall); homing missiles
         * may still go - they climb over terrain and keep the chase going. The burst waits, it is not lost. */
        if (ok[w] && w == 2 && burstLeft[k] > 0 && !los) ok[w] = 0;
        if (ok[w]) total += weight[w] * (setupT[k] > 0 && heavyW(w) ? 5 : 1) * (w == 1 && spBoost ? 2 : 1);
    }
    F(br, 0x47C) = 0;
    if (!total) return;
    r = mathfRandW(0, total - 1);
    for (w = 1; w < 8; w++) {
        if (!ok[w]) continue;
        if ((r -= weight[w] * (setupT[k] > 0 && heavyW(w) ? 5 : 1) * (w == 1 && spBoost ? 2 : 1)) < 0) break;
    }
    if (w >= 8) return;
    F(br, 0x47C) = w;
    wpnPicked[k] = wpnClock;
    if (w == 5) {   /* (which pickup types bots fire - zoomys assumed type 0xD for the line-up, 2026-10-26) */
        static unsigned int seen5;
        int ty = F(v + 0x21B0, 0x110) & 31;
        if (!(seen5 >> ty & 1)) { seen5 |= 1u << ty; scePrintf("TMBR aim: pickup slot type %d\n", ty); }
    }
    if (w == 2 || w == 3) {
        /* fire / homing missiles: sometimes a burst of 2-4 back to back, then a longer rest (both light
         * missiles share the timer, so a burst can mix them) */
        int cd;
        if (burstLeft[k] <= 0 && los && mathfRandW(0, 99) < BURST_CHANCE) burstLeft[k] = mathfRandW(2, 4);   /* only in sight */
        if (burstLeft[k] > 0)
            cd = --burstLeft[k] > 0 ? BURST_GAP + mathfRandW(0, 6)                    /* next missile of the burst */
                                    : cooldown(w) * 3 + mathfRandW(0, cooldown(w));    /* burst over: rest ~2 s (medium) */
        else cd = cooldown(w) + mathfRandW(0, cooldown(w) / 3);                       /* a single */
        wpnReady[k][2] = wpnReady[k][3] = wpnClock + cd;
    } else
        wpnReady[k][w] = wpnClock + cooldown(w) + mathfRandW(0, cooldown(w) / 3);
    if (w == 5) F(v, 0x22C0) = mathfRandW(11, 13);            /* as the original: pickup slot type */
    if (F(v, 0x2338 + w * 4) <= 0) F(v, 0x2338 + w * 4) = 1;  /* as the original: AI ammo topped up */
}

/* Fairness gate (aiLineUpShot, func_00106D50, func_00107048): a bot only fires a normal weapon when its target
 * "looks at it" (angle of the target's heading toward the bot, scaled by the bot's state). Fine against humans;
 * two bots circling each other almost never both qualify, so after the opening head-on pass they only fire
 * specials. With a chosen count, every target is fair game. */
extern int aiFairToShoot(char* v) __asm__("aiIsPlayerLookingAtAIEnoughForAIToShoot__7Vehicle");
int tmbr_AiMayShoot(char* v)
{
    char* drv = (char*)F(v, 0x2018);
    char* t = drv ? (char*)F(drv, 0xB4) : 0;
    /* No fairness gate with our bots (2026-10-25): the game only let a bot fire a normal weapon when its target
     * faced it. Bots play like players, and players have no such rule: any target is fair game. */
    if (tmbr_botCount >= 0 && t) return 1;
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
/* Two lines fit under the settings box (rows 10 and 11, about 28 characters each), nothing alternates:
 *   BOTS : 3 MEDIUM  TRAFFIC OFF
 *   YOU: RED TEAM (SELECT: LIST)      <- in your team's colour; "TEAMS OFF (HOLD R3: HELP)" without teams
 * Holding Select shows the two rosters (red / blue), holding R3 the controls. */
extern void tmbr_TeamColor(int t);       /* teams.c */
extern int tmbr_MyTeam(void);
extern const char* tmbr_TeamName(int t);
extern void fontSetColor(int font, int r, int g, int b) __asm__("fontSetColor__Fiiii");
static void lobbyLine(int row, int color, const char* t)   /* color: -1 = the game's tan, 0 red, 1 blue */
{
    if (color < 0) fontSetColor(0, 0x50, 0x44, 0x2C);
    else tmbr_TeamColor(color);
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + row * 0x100);
    fontPrint(0, t);
}
/* The deathmatch settings editor (func_001C7C28) has 8 rows from parallel tables (text, min, max, value
 * pointer, step, value printer jtbl_004EEFC0): row 6 "USE BOTS", row 7 "SYNCHRONOUS ENTRY", and the two were
 * mutually exclusive (bots only in asynchronous games). Row 7 moves into row 6 and the row count is 7
 * (apply_mods.py: 0x1C7C3C; the exclusion at 0x1C8334 is skipped). The waiting room's settings list line
 * "USE BOTS : YES/NO" (both strings) shows our count instead. */
extern u32 D_004EEF28[], D_004EEF48[], D_004EEF68[], D_004EEF88[], D_004EEFA8[], jtbl_004EEFC0[];
extern char D_004EEBC8[], D_004EEBD8[];
static void settingsRows(void)
{
    u32* t[5];
    int k, c, d;
    char line[16];
    /* the per-row tables (8 rows each): labels, step, max, value pointer, draw case. D_004EEFA8 is NOT one of
     * them (the "DEATHMATCH" name strings): copying its [7] into [6] wrote jtbl_004EEFC0[0] = [1], so the game
     * type row drew and behaved as the time-limit row and the game type could not be changed */
    t[0] = D_004EEF28; t[1] = D_004EEF48; t[2] = D_004EEF68; t[3] = D_004EEF88; t[4] = jtbl_004EEFC0;
    if (D_004EEF88[6] != D_004EEF88[7])
        for (k = 0; k < 5; k++) t[k][6] = t[k][7];
    botsShown(&c, &d);
    sprintf(line, "BOTS : %d %s", c, d == 0 ? "EASY" : d == 1 ? "MED" : "HARD");   /* 13 chars max: fits both */
    for (k = 0; line[k]; k++) { D_004EEBC8[k] = line[k]; D_004EEBD8[k] = line[k]; }
    D_004EEBC8[k] = 0; D_004EEBD8[k] = 0;
}
/* The waiting room's game settings box (func_001C5768) ends with the ENTRY line; mods/lobby.s sends that print
 * here with the box row it is on, and traffic / teams / your team follow it inside the box, like BOTS. */
extern int tmbr_botTeamMode;
static void extraLines(int row);
void tmbr_PrintEntryC(int font, const char* s, int row)
{
    fontPrint(font, s);
    extraLines(row);
}
/* Last Man Standing's box has no ENTRY line (it ends with NUMBER OF LIVES, 0x1C6304) and no USE BOTS row
 * (where the other modes show BOTS): BOTS first, then the same lines */
void tmbr_PrintLivesC(int font, const char* s, int row)
{
    char b[24];
    int c, d;
    fontPrint(font, s);
    botsShown(&c, &d);
    sprintf(b, "BOTS : %d %s", c, d == 0 ? "EASY" : d == 1 ? "MED" : "HARD");
    lobbyLine(row + 1, -1, b);
    extraLines(row + 1);
}
static void extraLines(int row)
{
    char b[40];
    int teams = tmbr_Opt(OPT_TEAMS);
    lobbyLine(row + 1, -1, tmbr_Opt(OPT_TRAFFIC) ? "TRAFFIC : ON" : "TRAFFIC : OFF");
    lobbyLine(row + 2, -1, !teams ? "TEAMS : OFF" : tmbr_Opt(OPT_TEAMS4) ? "TEAMS : 4" : "TEAMS : 2");
    lobbyLine(row + 3, -1, tmbr_Opt(OPT_MINION) ? "MINION : ON" : "MINION : OFF");
    lobbyLine(row + 4, -1, tmbr_Opt(OPT_HEALTH) ? "HEALTH : ON" : "HEALTH : OFF");
    row++;
    if (teams) {
        if (tmbr_botTeamMode) sprintf(b, "HUMANS VS BOTS");
        else sprintf(b, "YOU : %s TEAM", tmbr_TeamName(tmbr_MyTeam()));
        lobbyLine(row + 4, tmbr_MyTeam(), b);
    }
    {   /* split-screen guests (guests.c): "P2 SPECTRE P3 ..." */
        extern void tmbr_GuestsLine(char* b);
        char gb[64];
        tmbr_GuestsLine(gb);
        if (gb[0]) { lobbyLine(row + (teams ? 5 : 4), -1, gb); row++; }
    }
    {   /* story run (story.c): "STAGE 2: SUBURBS" */
        extern void tmbr_StoryLine(char* b);
        char sb[40];
        tmbr_StoryLine(sb);
        if (sb[0]) lobbyLine(row + (teams ? 5 : 4), -1, sb);
    }
    fontSetColor(0, 0x50, 0x44, 0x2C);
}
extern void tmbr_GuestsName(void);
void tmbr_LobbyFrame(void)
{
    int pad = 0, pressed, host, teams;
    char ra[40], rb[40];
    settingsRows();
    { extern int tmbr_GuestNaming(void);   /* guests.c: while a guest types a name the keyboard has the screen
                                            * (Ark 2026-10-26: the room's text showed through the keys) */
      if (tmbr_GuestNaming()) { tmbr_GuestsName(); return; } }
    lobbyFrame();
    { extern void tmbr_GuestsLobby(void); tmbr_GuestsLobby(); }   /* guests.c: START on controller 2-4 joins */
    { extern void tmbr_GuestsRows(void); tmbr_GuestsRows(); }     /* guests.c: their rows in the player list */
    tmbr_GuestsName();     /* guests.c: a new guest types a name (opened by the car pick) */
    tmbr_SkinsLobby();
    tmbr_PedNamesInit();
    host = netIsHost(D_003156C0);
    teams = tmbr_Opt(OPT_TEAMS);
    tmbr_TeamsLobby(ra, rb);                 /* teams.c: team pick input (R3 + Left/Right, R3 + Select) + rosters */
    /* raw pad, active high: Select 0x1, R3 0x4, Up 0x10, Down 0x40, L2 0x100, R2 0x200, L1 0x400, R1 0x800 */
    pad = inputGetPadButtons(0) & 0x3F55;            /* (+ Triangle 0x1000: Minion on / off, Circle 0x2000: health) */
    pressed = pad & ~prevPad;
    prevPad = pad;
    if (pad & 0x4) {
        if (!host) {
            lobbyLine(10, -1, teams ? "LEFT/RIGHT : PICK TEAM" : "THE HOST SETS BOTS,");
            lobbyLine(11, -1, teams ? "SELECT : SHOW TEAMS" : "TRAFFIC AND TEAMS");
        } else {
            lobbyLine(10, -1, teams ? "L1R1 BOT LT/RT TEAM SQ STORY" : "L1R1 BOT L2R2 SKILL SQ STORY");
            lobbyLine(11, -1, "UP TRAF DN TEAM TRI MIN O HP");
        }
    } else if (teams && (pad & 0x1)) {
        lobbyLine(10, 0, ra);
        lobbyLine(11, 1, rb);
    } else {
        /* the settings themselves are in the game settings box (tmbr_PrintEntryC); only the key hints here */
        lobbyLine(10, -1, host ? "HOLD R3 : HOST CONTROLS" : teams ? "HOLD R3 : PICK TEAM" : "");
        if (teams) lobbyLine(11, -1, "HOLD SELECT : TEAM LISTS");
    }
    fontSetColor(0, 0x50, 0x44, 0x2C);
    if (!host) return;
    { extern void tmbr_StoryLobby(void); tmbr_StoryLobby(); }   /* story.c: R3 + Square, its level rules */
    if ((pad & 0x4) && (pressed & 0x3050)) {
        {   /* Down cycles: teams off -> 2 teams -> 4 teams -> off; Triangle: Minion on / off */
            int f = (pressed & 0x10) ? OPT_TRAFFIC : 0;
            if (pressed & 0x1000) f |= OPT_MINION;
            if (pressed & 0x2000) f |= OPT_HEALTH;
            if (pressed & 0x40) f |= !tmbr_Opt(OPT_TEAMS) ? OPT_TEAMS : !tmbr_Opt(OPT_TEAMS4) ? OPT_TEAMS4 : (OPT_TEAMS | OPT_TEAMS4);
            optSync(f);
        }
        scePrintf("TMBR lobby: traffic %s, teams %s, minion %s\n", tmbr_Opt(OPT_TRAFFIC) ? "on" : "off", !tmbr_Opt(OPT_TEAMS) ? "off" : tmbr_Opt(OPT_TEAMS4) ? "4" : "2", tmbr_Opt(OPT_MINION) ? "on" : "off");
        scePrintf("TMBR lobby: health %s\n", tmbr_Opt(OPT_HEALTH) ? "on" : "off");
    } else optSync(0);
    if ((pad & 0x4) && (pressed & 0xF00)) {
        if (pressed & 0x800) tmbr_botCount++;
        if (pressed & 0x400) tmbr_botCount--;
        if (pressed & 0x200) tmbr_botDiff++;
        if (pressed & 0x100) tmbr_botDiff--;
        if (tmbr_botCount < 0) tmbr_botCount = 0;
        if (tmbr_botCount > MAXBOTS) tmbr_botCount = MAXBOTS;
        if (tmbr_botDiff < 0) tmbr_botDiff = 0;
        if (tmbr_botDiff > 2) tmbr_botDiff = 2;
        scePrintf("TMBR bots: lobby setting %d, difficulty %d\n", tmbr_botCount, tmbr_botDiff);
    }
}
