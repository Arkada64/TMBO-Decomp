/* TMB-Reloaded mod: STORY run, phase 1 (reference/wip/STORY_PLAN.md, Ark 2026-10-26).
 * The host turns it on in the waiting room (R3 + Square). It plays retail's story level order, the same for
 * every driver (retail Shell::m_nextLevelMap):
 *   JUNKYARD -> SUBURBS | FREEWAY -> HIGHWAY LOOP | DOWNTOWN -> MINION'S STADIUM -> PRISON PASSAGE
 *   -> SNOWY ROADS | DRIVE-IN -> SKYSCRAPERS -> WARHAWK'S ROOF
 * Each level is Last Man Standing, humans vs bots (teams.c bot mode), 3 lives, with retail's AI count for that
 * level (retail SelectAICars: shell +0x19DDC table), distinct random drivers that are not a human's car, Minion
 * only on his stadium (alone there, like retail). Win (the bots' team is out) -> the next level; at a fork the
 * host picks with L3 in the waiting room. Lose -> the same level again. No movies / bosses yet
 * (phases 2-4). Host only: the level goes to everyone in the game info (shell +0x23AC), bots are host-made. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern int sprintf(char* d, const char* f, ...);
extern int strlen(const char* s);
extern int scePrintf(const char* fmt, ...);
extern int mathfRandI(int lo, int hi) __asm__("mathfRand__Fii");
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern int netIsHost(void* net) __asm__("func_001734B8");
extern void netSendGameInfo(void* net, int to) __asm__("func_00174988");
extern int tmbr_GuestSlot(int s);
extern char D_003156C0[];
extern char* D_004FA03C;     /* shell */
extern int tmbr_levelSerial, tmbr_levelIndex, tmbr_botCount;
extern int tmbr_Opt(int bit);
extern void tmbr_OptSet(int bits, int on);         /* bots.c */
extern void tmbr_TeamsBotMode(int on);             /* teams.c */
extern int tmbr_TeamsWinner(void);                 /* teams.c: 0 = humans' team, 1 = bots', -1 none */

#ifndef TMBR_STORYLEVEL
#define TMBR_STORYLEVEL -1
#endif
/* Warhawk's boss cars (0x200 / 0x220) as AI: TMBO's gameMakeAI turns both into Roadkill (test g116: vehicle id 0x20),
 * so the roof keeps 6 ordinary bots until the boss code is wired (phase 4) */
#ifndef BOSSSTEP
#define BOSSSTEP 9
#endif
#ifndef BOSSTRACE
#define BOSSTRACE 0
#endif
#ifndef ROOF_BOSS
#define ROOF_BOSS 0
#endif
#define OPT_STORY 0x20
#define OPT_TEAMS 2
#define OPT_TEAMS4 4
#define END 21
#define LIVES 3
#define LEVEL() F(D_004FA03C + 0x18000, 0x23AC)

static const signed char NEXT[21][2] = {           /* retail m_nextLevelMap (21 = the end) */
    { 6, 5 }, { 0, 2 }, { 6, 5 }, { 8, 12 }, { 20, 20 }, { 14, 14 }, { 14, 14 }, { END, END }, { 4, 4 },
    { END, END }, { END, END }, { END, END }, { 4, 4 }, { END, END }, { 3, 3 }, { 0, 0 },
    { END, END }, { END, END }, { END, END }, { END, END }, { END, END } };
static const char AICOUNT[21] = { 8, 7, 7, 8, 8, 7, 8, 8, 8, 8, 8, 8, 8, 8, 6, 6, 6, 6, 6, 8, 6 };
static const char* const NAME[21] = { "SUBURBS", "JUNKYARD", "FREEWAY", "PRISON PASSAGE", "SKYSCRAPERS",
    "DOWNTOWN", "HIGHWAY LOOP", "ELEVATORS", "SNOWY ROADS", "POWER PLANT", "DOGPOUND", "SEWERS", "DRIVE-IN",
    "MINI FREEWAY", "MINION STADIUM", "PRISON SHIP", "ASYLUM", "MINICITY", "MINIBURB", "JUNK2", "WARHAWK ROOF" };

static int level = 1, stage = 1, fork = -1, playedSerial = -1, doneSerial = -1, wasOn, prevPad, introDone;
static char msg[32];
static int movN, movI, movBuilt;      /* story movies (phase 2, below) */
int tmbr_StoryMoviesDone(void);

/* Progress on the memory card (Ark: a story run is saved): retail's co-op save file (TwistedMemoryCard at shell
 * +0x19E60, "<dir>/coopFile", 0x24-byte records with an 18-bit checksum in word +8 bits 12..29), which TMBO never
 * uses. Record 0 = ours: 'TMBS', level, stage, fork, finished flag. Read when STORY is switched on (a run in
 * progress continues), written after every won level. R3 + L3 in the waiting room starts a new run. */
typedef struct { unsigned magic; signed char level, stage, fork, finished; unsigned ck; unsigned runs; unsigned pad[5]; } StorySave;
extern int coopSave(void* tmc, unsigned slot, void* d) __asm__("func_001B01B8");
extern int coopList(void* tmc, void* d, unsigned* n) __asm__("coopGetGameListing__17TwistedMemoryCardP17TmCoopMemCardDataRUi");
#define TMC (D_004FA03C + 0x19E60)
#define SAVE_MAGIC 0x53424D54
static StorySave saves[16];
static unsigned runs;
static int saveRetry;           /* the first save on a card without the file returns 0 (test g93); the next one works */
static void saveRun(void)
{
    StorySave* r = &saves[0];
    int i, ok;
    for (i = 0; i < (int)sizeof(StorySave); i++) ((char*)r)[i] = 0;
    r->magic = SAVE_MAGIC; r->level = level; r->stage = stage; r->fork = fork; r->runs = runs;
    ok = coopSave(TMC, 0, r);
    saveRetry = ok ? 0 : saveRetry + 1;
    scePrintf("TMBR story: saved stage %d %s -> %d\n", stage, NAME[level], ok);
}
static int loadRun(void)
{
    unsigned n = 0;
    int ok = coopList(TMC, saves, &n);
    scePrintf("TMBR story: card read %d, %d records, magic %x\n", ok, n, n ? saves[0].magic : 0);
    if (!ok || !n || n > 16 || saves[0].magic != SAVE_MAGIC || saves[0].level < 0 || saves[0].level > 20) return 0;
    level = saves[0].level; stage = saves[0].stage; fork = saves[0].fork; runs = saves[0].runs;
    return 1;
}

int tmbr_StoryOn(void) { return tmbr_Opt(OPT_STORY); }
int tmbr_StoryLevel(void) { return level; }

static void start(int fresh)
{
    level = 1; stage = 1; fork = -1; msg[0] = 0; introDone = 0;
    playedSerial = doneSerial = tmbr_levelSerial;
    if (!fresh && loadRun()) { scePrintf("TMBR story: continue, stage %d %s\n", stage, NAME[level]); return; }
#if TMBR_STORYLEVEL >= 0
    level = TMBR_STORYLEVEL; scePrintf("TMBR story: test start at %s\n", NAME[level]); return;   /* test build only */
#endif
    if (fresh) { runs++; saveRun(); }
    scePrintf("TMBR story: new run, %s\n", NAME[level]);
}

/* waiting-room line (bots.c extraLines) */
void tmbr_StoryLine(char* b)
{
    b[0] = 0;
    if (!tmbr_Opt(OPT_STORY)) return;
    if (msg[0]) { sprintf(b, "%s", msg); return; }
    if (fork >= 0 && NEXT[fork][0] != NEXT[fork][1])
        sprintf(b, "STAGE %d: %s  (L3)", stage, NAME[level]);
    else
        sprintf(b, "STAGE %d: %s", stage, NAME[level]);
}

/* the match just played (host, waiting room): advance on a win, retry on a loss */
static void result(void)
{
    int w;
    if (playedSerial == tmbr_levelSerial || tmbr_levelIndex != level) { playedSerial = tmbr_levelSerial; return; }
    playedSerial = tmbr_levelSerial;
    w = tmbr_TeamsWinner();
    if (w != 0) {
        sprintf(msg, "TRY AGAIN: %s", NAME[level]);
        scePrintf("TMBR story: lost %s (winner %d), again\n", NAME[level], w);
        return;
    }
    scePrintf("TMBR story: won %s\n", NAME[level]);
    if (NEXT[level][0] == END) {
        sprintf(msg, "STORY COMPLETE!");
        fork = -1; level = 1; stage = 1;
        saveRun();
        return;
    }
    fork = level;
    level = NEXT[level][0];
    stage++;
    msg[0] = 0;
    saveRun();
}

/* host, every waiting-room frame (bots.c tmbr_LobbyFrame) */
void tmbr_StoryLobby(void)
{
    char* gi = *(char**)(D_003156C0 + 0x3148);
    int pad, pressed, on, n;
    if (!gi || !D_004FA03C || !netIsHost(D_003156C0)) return;
    pad = inputGetPadButtons(0) & 0x8006;            /* L3 0x2, R3 0x4, Square 0x8000 */
    pressed = pad & ~prevPad;
    prevPad = pad;
    if ((pad & 0x4) && (pressed & 0x8000)) tmbr_OptSet(OPT_STORY, !tmbr_Opt(OPT_STORY));
    {   extern int tmbr_singlePlayer;                    /* menu.c: SINGLE PLAYER lands here with STORY on */
        if (tmbr_singlePlayer == 1) { tmbr_singlePlayer = 2; tmbr_OptSet(OPT_STORY, 1); scePrintf("TMBR story: single player room\n"); } }
    on = tmbr_Opt(OPT_STORY);
    if (on && !wasOn) start(0);
    if (on && (pad & 0x4) && (pressed & 0x2)) start(1);                   /* R3 + L3: a new run */
    if (!on && wasOn) tmbr_TeamsBotMode(0);
    wasOn = on;
    if (!on) return;
    result();
    {   static int key = -1, wait;                     /* the stage's movies, a second after the room is up */
        if (key != stage * 32 + level) { key = stage * 32 + level; movBuilt = 0; wait = 0; }
        if (++wait > 60) tmbr_StoryMoviesDone();
    }
    {   static int wait;
        if (saveRetry && ++wait >= 30) { wait = 0; if (saveRetry < 5) saveRun(); else saveRetry = 0; } }
    if (!(pad & 0x4) && (pressed & 0x2) && fork >= 0 && NEXT[fork][0] != NEXT[fork][1]) {
        level = level == NEXT[fork][0] ? NEXT[fork][1] : NEXT[fork][0];
        msg[0] = 0;
        saveRun();
        scePrintf("TMBR story: branch -> %s\n", NAME[level]);
    }
    /* the rules of a story level */
    n = (level == 14 ? 1 : level == 20 && ROOF_BOSS ? 2 : AICOUNT[level]) + (tmbr_Opt(0x40) ? 1 : 0);   /* + the ally bot (GAME MODS ALLY BOT) */
    tmbr_botCount = n > 7 ? 7 : n;
    tmbr_OptSet(OPT_TEAMS, 1);
    tmbr_OptSet(OPT_TEAMS4, 0);
    tmbr_TeamsBotMode(1);
    {
        int ch = 0;
        if (LEVEL() != level) { LEVEL() = level; ch = 1; }
        if (((F(gi, 0) >> 1) & 0xF) != 3) { F(gi, 0) = (F(gi, 0) & ~0x1E) | 3 << 1; ch = 1; }
        if (((unsigned char*)gi)[5] != LIVES) { gi[5] = LIVES; ch = 1; }
        {   static int carsFor = -1;                     /* the bots' cars follow the level (the room picked them for the first) */
            extern int tmbr_StoryCars(void);
            if (carsFor != level) { carsFor = level; tmbr_StoryCars(); ch = 1; }
        }
        if (ch) { netSendGameInfo(D_003156C0, -1); scePrintf("TMBR story: %s, %d bots\n", NAME[level], tmbr_botCount); }
    }
}

/* bots' cars (guests.c tmbr_BotCars, host, after the game's random pick): distinct, not a human's car, Minion only
 * (and alone) on his stadium. Returns 1 when it set them (no 12 Pak bots in a story run). */
int tmbr_StoryCars(void)
{
    int s, k, used = 0, first = 1;
    if (!tmbr_Opt(OPT_STORY)) return 0;
    for (s = 0; s < 8; s++)
        if (F(D_003156C0 + s * 0x220, 0x10) != -1 || tmbr_GuestSlot(s)) used |= 1 << (F(D_003156C0 + s * 0x220, 0xB4) >> 5);
    for (s = 0; s < 8; s++) {
        int c = 0;
        if (F(D_003156C0 + s * 0x220, 0x10) != -1 || tmbr_GuestSlot(s)) continue;
        if (level == 14) c = 15;                          /* Minion's stadium: Minion in every free slot (one bot comes) */
        if (level == 20 && ROOF_BOSS) c = (used & 1 << 16) ? 17 : 16;  /* Warhawk's roof: retail's boss cars 0x200 / 0x220 only, in
                                                           * every free slot (the bot spawner may take any of them) */
        for (k = 0; !c && k < 200; k++) {
            int r = mathfRandI(1, 14);
            if (!(used & 1 << r)) c = r;
        }
        if (!c) c = 1;
        used |= 1 << c;
        if (level == 20 && ROOF_BOSS && c == 17) used &= ~(3 << 16);  /* (alternate 16, 17, 16, ...) */
        first = 0;
        F(D_003156C0 + s * 0x220, 0xB4) = c << 5;
        if (level == 20) scePrintf("TMBR story: roof bot slot %d car %x\n", s, c << 5);
    }
    return 1;
}

/* ---- phase 2: retail's story movies (reference/wip/STORY_MOVIES.md) ----
 * Played in the waiting room (tmbr_StoryLobby, once per stage, a second after the room shows: TMBO's own clips
 * only play inside menu screens - the loading screen attempts froze or never started, tests g100-g104), host side
 * for now: the character's intro (X??A) before the first
 * Junkyard, ??ARENA before Minion's stadium, X??B before Prison Passage, ??ROOF before Warhawk's roof, then the
 * level's LLn clip. The character is this console's car (12 Pak = a Roadkill: Roadkill's movies). A movie that is not
 * on the disc is skipped (the game's file lookup first), so a disc without retail's \MOV\ files plays nothing.
 * Player: see tmbr_StoryMoviesDone. */
extern int fileSearch(void* f, const char* name) __asm__("func_00201910");   /* the game's disc file lookup (strFileOpen uses it) */
extern int movieRequested __asm__("D_004FB068");    /* set by the player, cleared when the clip ends (the UI loop decodes while set) */
extern int netGetMyClientIndex(void* net) __asm__("netGetMyClientIndex");
static const signed char MOVSLOT[17] = { -1, 4, 9, 2, 6, 5, 13, 1, 0, 8, 3, 10, 11, 7, 12, -1, -1 };  /* car type -> slot */
static const char* const ARENA[14] = { "BR", "PR", "SW", "GR", "JD", "NF", "BM", "DF", "SS", "TX", "AX", "WH", "BL", "ST" };
static const signed char LLNUM[21] = { 1, 0, 2, 6, 7, 3, 4, -1, 8, -1, -1, -1, 9, -1, 5, -1, -1, -1, -1, -1, 10 };
static char movQ[4][16];
static int movFile[32];                            /* sceCdlFILE (+ slack) */
static void movAdd(const char* name) { if (movN < 4) sprintf(movQ[movN++], "%s", name); }
static void movBuild(void)
{
    int me, car, slot;
    char nm[16];
    movN = movI = 0;
    if (!tmbr_Opt(OPT_STORY) || LEVEL() != level) return;
    me = netGetMyClientIndex(D_003156C0);
    car = me >= 0 && me < 8 ? F(D_003156C0 + me * 0x220, 0xB4) >> 5 : 1;
    slot = car > 0 && car < 17 ? MOVSLOT[car] : -1;
    if (slot >= 0) {
        if (level == 1 && stage == 1 && !introDone && slot != 10 && slot != 11 && slot != 12) { sprintf(nm, "X%02dA", slot + 1); movAdd(nm); }
        if (level == 14) { sprintf(nm, "%sARENA", ARENA[slot]); movAdd(nm); }
        if (level == 3 && (slot < 9 || slot == 13)) { sprintf(nm, "X%02dB", slot + 1); movAdd(nm); }
        if (level == 20) { sprintf(nm, "%sROOF", ARENA[slot]); movAdd(nm); }
    }
    if (LLNUM[level] >= 0) { sprintf(nm, "LL%d", LLNUM[level]); movAdd(nm); }
    introDone = 1;
    scePrintf("TMBR story: %d movies for %s (car %d)\n", movN, NAME[level], car);
}
void tmbr_StoryMoviesReset(void) { movBuilt = 0; }
/* Started through the game's own movie request so it begins at the UI loop's movie point (calling the player from
 * the state function froze the game, blocking or not - tests g101 / g102): nextMovie -1 is the "incog" clip (audio,
 * not skippable), whose 16-byte name mov/incog.pss (D_004EF7C0) holds ours for the duration (names are at most 15
 * characters: mov/jdarena.pss). movieEnable (D_004FB5A0) = 1 starts it on the loop's next playMovie call;
 * movieRequested (D_004FB068) is up while it plays. */
extern char incogName[] __asm__("D_004EF7C0");
extern int nextMovie __asm__("D_004FA718");
extern int movieEnable __asm__("D_004FB5A0");
extern int movieDelay __asm__("D_004FA728");
static char incogSave[16];
static int movPending, movDbg;
/* the UI loop's playMovie call (0x1B40D4, func_001CE9B0; apply_mods.py): our request goes in right before it, so no
 * state code between can overwrite nextMovie / movieEnable (test g106: a request made from the room never started) */
extern void playMovie(void) __asm__("func_001CE9B0");
void tmbr_PlayMovie(void)
{
    if (movPending) {
        extern int D_004FB06C, D_004FA778, D_004FA3A4;
        movPending = 0;
        nextMovie = -1; movieDelay = 0; movieEnable = 1;
        scePrintf("TMBR story: movie start (finished %d key %d ok %d)\n", D_004FB06C, D_004FA778, D_004FA3A4);
        movDbg = 8;
    }
    playMovie();
    if (movDbg > 0) {                                     /* (debug: what the game made of the request) */
        extern int D_004FA71C, D_004FB06C;
        movDbg--;
        scePrintf("TMBR story: after playMovie next %d enable %d req %d bytes %d finished %d\n", nextMovie, movieEnable, movieRequested, D_004FA71C, D_004FB06C);
    }
}
static int movPhase, movT;
int tmbr_StoryMoviesDone(void)
{
    int i;
    if (!movBuilt) { movBuilt = 1; movBuild(); movPhase = 0; }
    if (movPhase == 1) {                                  /* requested: wait for the start, then for the end */
        movT++;
        if (movieRequested) { if (movT < 100000) movT = 100000; return 0; }
        if (movT < 100000 && movT < 120) return 0;        /* not started yet (gives up after 2 s) */
        for (i = 0; i < 16; i++) incogName[i] = incogSave[i];
        scePrintf("TMBR story: movie %s (%d)\n", movT >= 100000 ? "done" : "did not start", movT % 100000);
        movPhase = 0;
    }
    while (movI < movN) {
        char f[64];
        const char* n = movQ[movI++];
        sprintf(f, "%cMOV%c%s.PSS;1", 92, 92, n);   /* (backslash as a number) */
        if (!fileSearch(movFile, f)) { scePrintf("TMBR story: no %s on the disc\n", n); continue; }
        for (i = 0; i < 16; i++) incogSave[i] = incogName[i];
        sprintf(f, "mov/%s.pss", n);
        if (strlen(f) > 15) { scePrintf("TMBR story: name too long %s\n", f); continue; }
        sprintf(incogName, "%s", f);
        movPending = 1;                                   /* tmbr_PlayMovie sets the request right before the game's call */
        movPhase = 1; movT = 0;
        {   extern int D_004FB06C, D_004FA778, D_004FA3A4;
            scePrintf("TMBR story: movie %s requested (finished %d key %d ok %d req %d)\n", f, D_004FB06C, D_004FA778, D_004FA3A4, movieRequested); }
        return 0;
    }
    return 1;
}

/* ---- Prison Passage, retail's story sequence (reference/wip/STORY_PRISON.md; Ark 2026-10-26: in retail you start
 * locked on the ship to the prison, the AI spread out, timed events; online Prison Passage skips it) ----
 * The Prison level object's state machine survives in TMBO; online skips it in three places, undone here in a story
 * run on level 3 only (hooks in apply_mods.py):
 *   init (0x1386C8 -> func_0017D4D0): net+0x1BB4 / D_00317274 cleared around it -> state 0, island 6000 out;
 *   state 0 (0x17DAFC -> func_0017DB90): AI 2+ held (disabled) on the moored ship for 60 s, then the departure
 *     (door anims, state 1, AI 2-3 placed on start points 2-3 and enabled, transition points);
 *   state 2 (0x17DB24 -> func_0017DFE8): the dock; then AI 4+ placed on points 4.. and enabled. */
extern char* D_004FA030;
extern int D_00317274;
extern void prisonInitAfter(char* p) __asm__("func_0017D4D0");
extern void prisonState0(char* p) __asm__("func_0017DB90");
extern void prisonState2(char* p) __asm__("func_0017DFE8");
extern void vehDisable(char* v) __asm__("vehicleDisable__7Vehicle");
extern void vehEnable(char* v, int t) __asm__("vehicleEnable__7Vehicle12VehicleTypes");
extern void animStart(void* h, int b) __asm__("animationStart__FR11_animHandleb");
extern int startInRange(void* pts, int lo, int hi) __asm__("func_0010BFD8");
extern void placeAt(char* g, char* v, int idx) __asm__("func_0013D7B8");
extern void prisonTransPts(char* p) __asm__("prisonUpdateTransitionPoints__6Prison");
extern int fieldsLast(void) __asm__("timerGetFieldsLastFrame__Fv");
#define PRISON_STORY() (tmbr_Opt(OPT_STORY) && D_004FA030 && F(D_004FA030, 0x9FCA0) == 3)
#define NAI_ F(D_004FA030, 0x9FEE4)
#define AIV(i) (*(char**)(D_004FA030 + 0x9E690 + 4 * (i)))
#define PTS (D_004FA030 + 0x30970)
static int prisonDocked;
static void prisonPlace(int i, int lo, int hi)
{
    char* v = AIV(i);
    int idx;
    if (!v || hi <= lo) return;
    idx = startInRange(PTS, lo, hi);
    placeAt(D_004FA030, v, idx);
    vehEnable(v, 2);
    scePrintf("TMBR prison: AI %d out at start point %d\n", i, idx);
}
void tmbr_PrisonInitAfter(char* p)
{
    int a, b;
    if (!PRISON_STORY()) { prisonInitAfter(p); return; }
    a = F(D_003156C0, 0x1BB4); b = D_00317274;
    F(D_003156C0, 0x1BB4) = 0; D_00317274 = 0;
    prisonInitAfter(p);
    F(D_003156C0, 0x1BB4) = a; D_00317274 = b;
    prisonDocked = 0;
    scePrintf("TMBR prison: story start, state %d, island %d, AI %d, mode %d\n", F(p, 0xF8), (int)*(float*)(*(char**)p + 0x14), NAI_, F(D_004FA030, 0x9A3D0));
}
void tmbr_PrisonState0(char* p)
{
    int i, n;
    if (!PRISON_STORY()) { prisonState0(p); return; }
    n = NAI_;
    for (i = 2; i < n && i < 8; i++) {                      /* AI 2+ wait off the ship (bots made late too) */
        char* v = AIV(i);
        if (v && F(v, 0x590)) { vehDisable(v); scePrintf("TMBR prison: AI %d held\n", i); }
    }
    F(p, 0x100) += fieldsLast();
    if (F(p, 0x100) <= 3600) return;                         /* about 60 s at the quay */
    animStart((char*)p + 0x14, 1);
    for (i = 0; i < 6; i++) animStart((char*)p + 0x80 + 0xC * i, 1);
    F(p, 0xF8) = 1;
    prisonPlace(2, 2, 4); prisonPlace(3, 2, 4);
    prisonTransPts(p);
    scePrintf("TMBR prison: the ship leaves\n");
}
void tmbr_PrisonState2(char* p)
{
    int n, i;
    if (!PRISON_STORY()) { prisonState2(p); return; }
    n = NAI_;
    if (n > 4) NAI_ = 4;                                     /* (skips TMBO's bare enable loop) */
    prisonState2(p);
    NAI_ = n;
    if (F(p, 0xF8) >= 3 && !prisonDocked) {
        prisonDocked = 1;
        scePrintf("TMBR prison: docked\n");
        for (i = 4; i < n && i < 8; i++) prisonPlace(i, 4, F(PTS, 0x24C));
    }
}

/* ---- phase 4: Warhawk's roof boss (reference/wip/STORY_BOSSES.md) ----
 * TMBO keeps retail's FinalBoss code (game+0x97120) but never calls it: InitAfterDbLoad's level-20 case is gone. Hooked at
 * the switch's common tail (0x1387FC, plightActivate): on the roof with the story on and both boss cars loaded (0x200 the
 * boss body, 0x220 the tanker), run retail's InitBossBefore / forceFieldInitBefore / InitBossAfter; then every frame
 * UpdateBoss + forceFieldUpdate (tmbr_BossFrame from bots.c). */
extern void plightActivate(void) __asm__("plightActivate__Fv");
extern char* vehFromName(char* g, int name, int dup) __asm__("GetVehicleFromName__7TheGameii");
extern void bossInitBefore(char* b) __asm__("func_00111E48");
extern void bossInitAfter(char* b) __asm__("func_00111ED8");
extern void bossUpdate(char* b) __asm__("func_001123C0");
extern void ffInitBefore(void) __asm__("func_001360D8");
extern void ffUpdate(void) __asm__("forceFieldUpdate__Fv");
extern int tmbr_levelSerial;
static int bossSer = -1;
/* GetVehicleFromName(g, name, dup) matches +0x20F0 == dup, but TMBO's +0x20F0 is the load index (vehicle 1 = 0x200 is
 * load 1), so retail's (0x200, 0) / (0x220, 0) lookups in the boss code find nothing: those calls (InitBossAfter,
 * forceField, UpdateBoss, TakeHit) come here - the boss cars by name only, the first one (the bots get slots 1 / 2) */
char* tmbr_BossVehName(char* g, int name, int dup)
{
    int k;
    char* v = vehFromName(g, name, dup);
    if (v || (name != 0x200 && name != 0x220)) return v;
    for (k = 0; k < 8; k++) if (F(g + k * 0x31B0, 0x20F4) == name) return g + k * 0x31B0;
    return 0;
}
static int bossOn(void)
{
    char* g = D_004FA030;
    return g && ROOF_BOSS && tmbr_Opt(OPT_STORY) && F(g, 0x9FCA0) == 20;
}
static void minionLevelInit(void);                 /* Minion's stadium (below) */
static void minionFrame(void);
static int minionHit(char* v, void* pos, int dmg, int att);
void tmbr_LevelInitAfter(void)
{
    char* g = D_004FA030;
    plightActivate();
    bossSer = -1;
    minionLevelInit();
    if (!bossOn()) return;
    {
        char* b = g + 0x97120;
        char *v0 = tmbr_BossVehName(g, 0x200, 0), *v1 = tmbr_BossVehName(g, 0x220, 0);
        int hier = F(b, 0x9C);
        scePrintf("TMBR boss: roof init, boss car %x tanker %x hier %x\n", (int)v0, (int)v1, hier);
        if (!v0 || !v1 || !hier) return;     /* InitBossAfter dereferences vehicle 0x200 without a check */
        if (BOSSSTEP >= 1) bossInitBefore(b);
        scePrintf("TMBR boss: init before done\n");
        F(b, 0x9C) = hier;                   /* (retail runs InitBossBefore before the db load fills it) */
        if (BOSSSTEP >= 2) ffInitBefore();
        scePrintf("TMBR boss: force field before done\n");
        if (BOSSSTEP < 3) return;            /* (test builds: stop here) */
        bossInitAfter(b);
        bossSer = tmbr_levelSerial;
        scePrintf("TMBR boss: up, state %d health %d cs %x\n", F(b, 0x10), F(b, 0x1C), F(b, 0xE0));
    }
}
void tmbr_BossFrame(void)
{
    char* g = D_004FA030;
    static int tk;
    minionFrame();
    if (bossSer < 0 || bossSer != tmbr_levelSerial || !bossOn()) return;
    bossUpdate(g + 0x97120);
    ffUpdate();
    if (++tk % 600 == 0) scePrintf("TMBR boss: state %d health %d shield hits %d\n", F(g + 0x97120, 0x10), F(g + 0x97120, 0x1C), F(g + 0x97120, 0x3C));
}
/* FinalBoss TakeHit's end (0x114D5C, rtReturnToShell(0, 0xF0)): the boss is down -> the humans' team wins the stage */
void tmbr_BossWon(int a, int b)
{
    extern void tmbr_TeamsForceWin(int team);
    scePrintf("TMBR boss: down\n");
    tmbr_TeamsForceWin(0);
}
/* Vehicle hits, story bosses first (apply_mods.py: the interactive hit dispatch 0x14F184 and the three network hit
 * events 0x167D38 / 0x167DA0 / 0x167EC4 come here, then go on to dmgreport.c's tmbr_TakeHit, which calls the game's
 * vehicleTakeHit func_001E1C40(car, pos, damage, attacker id, x). Before 2026-10-26 the dispatch had two patches,
 * this one and tmbr_TakeHit's: the later one won, so this wrapper never ran.)
 *  - Minion's stadium: retail's minionTakeHit (below) for the shielded AI Minion; a hit it absorbs is not applied;
 *  - the tanker (vehicle 0x220): TMBO's vehicleTakeHit still tests "0x220 on level 20" but lost retail's
 *    tankerTakeHit call: after the normal hit, tankerTakeHit (func_001E3188) - near the boss it blows up into the
 *    boss (damage 0x29A: one of the three shield hits) */
extern int tmbr_TakeHit(char* v, void* pos, int dmg, int att, int x);   /* dmgreport.c */
extern void tankerTakeHit(char* v) __asm__("func_001E3188");
int tmbr_VehTakeHit(char* v, void* pos, int dmg, int att, int x)
{
    int r;
    if (minionHit(v, pos, dmg, att)) return 0;
    r = tmbr_TakeHit(v, pos, dmg, att, x);
    if (v && F(v, 0x20F4) == 0x220 && bossSer >= 0 && bossSer == tmbr_levelSerial && bossOn()) {
        int was = F(v, 0x450);
        tankerTakeHit(v);
        scePrintf("TMBR boss: tanker hit %d (+0x450 %d -> %d), shield hits %d\n", dmg, was, F(v, 0x450), F(D_004FA030 + 0x97120, 0x3C));
    }
    return r;
}

/* ---- Minion's Stadium (level 14): retail's shielded Minion (reference/wip/STORY_BOSSES.md, "Minion's Stadium") ----
 * Retail, for an AI-driven Minion (type +0x580 != 1) on level 0xE:
 *  - vehicleInitDynamics: 250 health (a human Minion 150), big-car geometry, and forceFieldCreate(cs+0x20, cs+0x10,
 *    dup, -14.5, 4, 30, 49, 35) + forceFieldSetState(2) around him (on every spawn: vehicleInit runs on respawn too);
 *  - vehicleTakeHit -> minionTakeHit(v, damage) after the respawn-shield / AI-vs-AI damage cuts: four shield
 *    generators (+0x408..+0x414 in TMBO: 35 / 5 / 25 / 25 hp, set by TMBO's InitDynamics for every Minion) take the
 *    hits that land within 50 (manhattan) of them; while one is up the hit is absorbed (return 1, the normal hit is
 *    skipped); when the last one goes, aggressiveness 100 and "shield down", then hits do damage;
 *  - level 14 InitBefore: forceFieldInitBefore; Update: forceFieldUpdate every frame.
 * TMBO lost all of it (InitDynamics' Minion case has no AI / level branch; minionTakeHit func_001E2A00 has no caller;
 * no level-14 case calls the force field). Here, host only (bots run there), story on, game level 14:
 *  - aiInit's vehicleInit call (0x10011C) -> tmbr_MinionVehInit: after it, an AI Minion gets 250 health (aiInit
 *    copies +0x400 to +0x404 and applies the difficulty after) and the force field (state 2);
 *  - tmbr_VehTakeHit -> minionHit -> func_001E2A00 for the shielded one;
 *  - tmbr_BossFrame (bots.c, every frame) -> minionFrame: forceFieldUpdate; the field follows another AI Minion
 *    when its car is gone / is the ally bot (the ally is only known after its first aiInit);
 *  - tmbr_LevelInitAfter -> minionLevelInit: forceFieldInitBefore.
 * The force-field globals (D_004FB45C theBoss, D_004FB448 mat, D_004FB44C pos, D_004FB46C/70 the shield model,
 * D_004F9770 state) are the ones Warhawk's roof uses; one level never runs both. Clients run none of it. */
#ifndef MINION_SHIELD
#define MINION_SHIELD 1
#endif
#ifndef MINION_BIG               /* retail's big-car geometry for the AI Minion: off (TMBO's model may not match it) */
#define MINION_BIG 0
#endif
extern void vehicleInit(char* v) __asm__("func_001D6F78");
extern void ffCreate(void* mat, void* pos, int dup, float a, float b, float c, float d, float e) __asm__("func_00136100");
extern void ffSetState(int s) __asm__("forceFieldSetState__Fi");
extern int minionTakeHit(char* v, int dmg) __asm__("func_001E2A00");
extern void vehRecomputeDeltas(char* v, int b) __asm__("vehicleRecomputeDeltas__7Vehicleb");
extern int ffBoss __asm__("D_004FB45C");          /* 1 = Minion, 2 = Warhawk, 0 = none */
extern int ffModel __asm__("D_004FB46C");         /* the boss car's shield model switch (+0x2068) */
extern int ffState __asm__("D_004F9770");
extern int tmbr_IsAlly(char* v);                   /* teams.c */
extern int tmbr_SameTeam(char* a, char* b);
static float MINION_FF[5] = { -14.5f, 4.0f, 30.0f, 49.0f, 35.0f };   /* retail's forceFieldCreate floats (f12..f16) */
#if MINION_BIG
static const unsigned MINION_GEO[12][2] = {        /* retail AI Minion (offsets +0x10 for TMBO), float bits */
    { 0x3A4, 0xC10AE560 }, { 0x3A8, 0x41948312 }, { 0x3AC, 0x41948312 }, { 0x3B0, 0x41948312 },
    { 0x3B4, 0x411A8F5C }, { 0x3B8, 0x416570A4 }, { 0x3BC, 0xC23345A2 }, { 0x3C0, 0x41E4D917 },
    { 0x3C4, 0xC2593333 }, { 0x3C8, 0x4209DEDE }, { 0x3D0, 0x40AE4DD3 }, { 0x3D4, 0x40E66666 } };
#endif
#define VEH(k) (D_004FA030 + (k) * 0x31B0)
static char* minV;                                 /* the Minion the field is on */
static int minSer = -1;
static int minionLevel(void)
{
    char* g = D_004FA030;
    return MINION_SHIELD && g && tmbr_Opt(OPT_STORY) && F(g, 0x9FCA0) == 14 && netIsHost(D_003156C0);
}
static int minionAi(char* v)
{
    return v && F(v, 0x20F4) == 0x1E0 && F(v, 0x590) == 2 && F(v, 0x2028) && !tmbr_IsAlly(v);
}
static void minionShield(char* v, const char* why)
{
    char* cs = (char*)F(v, 0x2028);
    ffCreate(cs + 0x20, cs + 0x10, F(v, 0x20F0), MINION_FF[0], MINION_FF[1], MINION_FF[2], MINION_FF[3], MINION_FF[4]);
    ffSetState(2);
    minV = v;
    minSer = tmbr_levelSerial;
    scePrintf("TMBR minion: shield up (%s), car %d dup %d, boss %d model %x state %d, generators %d %d %d %d, health %d (shell level %d)\n",
        why, (int)(v - D_004FA030) / 0x31B0, F(v, 0x20F0), ffBoss, ffModel, ffState,
        F(v, 0x408), F(v, 0x40C), F(v, 0x410), F(v, 0x414), (int)*(float*)(v + 0x400), LEVEL());
    if (ffBoss != 1) scePrintf("TMBR minion: forceFieldCreate made no field (shell level not 14 or no shield model +0x2068)\n");
}
static void minionLevelInit(void)
{
    char* g = D_004FA030;
    minV = 0;
    minSer = -1;
    if (!MINION_SHIELD || !g || !tmbr_Opt(OPT_STORY) || F(g, 0x9FCA0) != 14) return;
    ffInitBefore();                                /* retail's level-14 InitBefore */
    scePrintf("TMBR minion: stadium init, force field reset\n");
}
/* aiInit's vehicleInit (0x10011C): every AI spawn and respawn (gameMakeAI, the death sequence func_001E3800) */
void tmbr_MinionVehInit(char* v)
{
    vehicleInit(v);
    if (!minionLevel() || F(v, 0x20F4) != 0x1E0 || F(v, 0x590) != 2) return;
    *(unsigned*)(v + 0x400) = 0x437A0000;           /* 250.0: retail's AI Minion health (TMBO gives every Minion 160) */
#if MINION_BIG
    {   int i;
        for (i = 0; i < 12; i++) *(unsigned*)(v + MINION_GEO[i][0]) = MINION_GEO[i][1];
        vehRecomputeDeltas(v, 1); }
#endif
    if (!F(v, 0x2028)) return;
    if (tmbr_IsAlly(v)) { scePrintf("TMBR minion: car %d is the ally bot, no shield\n", (int)(v - D_004FA030) / 0x31B0); return; }
    if (minV && minV != v && minSer == tmbr_levelSerial && minionAi(minV)) {
        scePrintf("TMBR minion: car %d is a second AI Minion, the shield stays on car %d\n", (int)(v - D_004FA030) / 0x31B0, (int)(minV - D_004FA030) / 0x31B0);
        return;
    }
    minionShield(v, minV == v && minSer == tmbr_levelSerial ? "respawn" : "spawn");
}
/* every frame (tmbr_BossFrame) */
static void minionFrame(void)
{
    static int tk;
    int k;
    if (!minionLevel()) return;
    if (minSer != tmbr_levelSerial) minV = 0;
    if (!minionAi(minV)) {
        char* n = 0;
        for (k = 0; k < 8 && !n; k++) if (minionAi(VEH(k))) n = VEH(k);
        if (n) minionShield(n, minV ? "moved" : "late");
        else if (minV) {
            scePrintf("TMBR minion: the shielded Minion is gone (type %d), field off\n", F(minV, 0x590));
            minV = 0;
            ffInitBefore();
        }
    }
    if (!minV) return;
    if (ffBoss) ffUpdate();
    if (++tk % 600 == 0)
        scePrintf("TMBR minion: state %d, generators %d %d %d %d, health %d\n", ffState,
            F(minV, 0x408), F(minV, 0x40C), F(minV, 0x410), F(minV, 0x414), (int)*(float*)(minV + 0x404));
}
/* a hit on a car (tmbr_VehTakeHit): 1 = the shielded Minion's generators absorbed it (skip the normal hit) */
static int minionHit(char* v, void* pos, int dmg, int att)
{
    char *g = D_004FA030, *a = 0, *info;
    int k, d = dmg, scr = 0, up, s210C, sPos, r, g0;
    if (!v || v != minV || minSer != tmbr_levelSerial || !minionLevel() || F(v, 0x590) != 2 || F(v, 0x20B4) == 2) return 0;
    info = g + 0x2BC10;                            /* the hit info: +0 the hit position (pointer), +8 1 = a local hit */
    for (k = 0; k < 8; k++)                        /* the attacker, as vehicleTakeHit finds it */
        if (F(VEH(k), 0x20FC) == att && F(VEH(k), 0x20D0)) { a = VEH(k); break; }
    if (a && a != v && tmbr_SameTeam(a, v)) return 0;              /* a teammate's hit: tmbr_TakeHit drops it */
    /* vehicleTakeHit's cuts before retail's minionTakeHit call: respawn shield (the mod's rule: byte 0x497 set) -> 0;
     * AI vs AI: the mod lets bots hurt each other in full, the ally bot for half (dmgreport.c) */
    if (*(signed char*)(v + 0x497)) d = 0;
    else if (a && a != v && F(a, 0x590) == 2 && tmbr_IsAlly(a)) d = d / 2 > 0 ? d / 2 : (d > 0);
    up = F(v, 0x408) > 0 || F(v, 0x40C) > 0 || F(v, 0x410) > 0 || F(v, 0x414) > 0;
    sPos = F(info, 0);
    if (!(F(info, 8) == 1 && sPos) && !pos) {      /* nowhere to measure from: the shield just holds */
        scePrintf("TMBR minion: hit %d without a position, %s\n", dmg, up ? "absorbed" : "through");
        return up;
    }
    /* minionTakeHit's HUD messages go to hud +0x210C (the car's screen; a bot has none): the attacker's screen when it
     * is a player on this console, else screen 0. Its generators are measured from *(info+0): network hits leave
     * that stale (the event handler does not set it), so the hit's own position stands in for any non-local hit. */
    s210C = F(v, 0x210C);
    if (a && F(a, 0x20B4) == 1 && (unsigned)F(a, 0x210C) <= 3) scr = F(a, 0x210C);
    F(v, 0x210C) = scr;
    if (!(F(info, 8) == 1 && sPos)) F(info, 0) = (int)pos;
    g0 = F(v, 0x408) + F(v, 0x40C) + F(v, 0x410) + F(v, 0x414);
    r = minionTakeHit(v, d);
    F(v, 0x210C) = s210C;
    F(info, 0) = sPos;
    if (g0 != F(v, 0x408) + F(v, 0x40C) + F(v, 0x410) + F(v, 0x414) || (!r && up))
        scePrintf("TMBR minion: hit %d (%d) by car %d: generators %d %d %d %d, %s\n", dmg, d,
            a ? (int)(a - g) / 0x31B0 : -1, F(v, 0x408), F(v, 0x40C), F(v, 0x410), F(v, 0x414), r ? "absorbed" : "through");
    return r;
}

#if BOSSTRACE
/* test build only: every call in InitBossAfter (func_00111ED8) goes through a trampoline that logs its number first */
void tmbr_BossTrace(int id) { scePrintf("TMBR boss: init call %d\n", id); }
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT0; tmbr_BT0: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 0; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_00213F80; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT1; tmbr_BT1: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 1; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j hierCsAddToCsList__FP3_cs; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT2; tmbr_BT2: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 2; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_0014F070; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT3; tmbr_BT3: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 3; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_0022F198; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT4; tmbr_BT4: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 4; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_0022EA20; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT5; tmbr_BT5: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 5; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_00136100; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT6; tmbr_BT6: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 6; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j forceFieldSetState__Fi; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT7; tmbr_BT7: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 7; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_0013D788; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT8; tmbr_BT8: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 8; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j initFinalBossSound__14FinalBossSound; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT9; tmbr_BT9: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 9; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j initHelicopterSound__15HelicopterSound; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT10; tmbr_BT10: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 10; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_001FBCF8; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT11; tmbr_BT11: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 11; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_001FBCF8; addiu $29, $29, 0xA0; .set reorder");
__asm__(".text; .align 3; .set noreorder; .globl tmbr_BT12; tmbr_BT12: addiu $29, $29, -0xA0; sq $4, 0($29); sq $5, 0x10($29); sq $6, 0x20($29); sq $7, 0x30($29); sq $31, 0x40($29); sq $8, 0x50($29); sq $9, 0x60($29); swc1 $f12, 0x70($29); swc1 $f13, 0x74($29); swc1 $f14, 0x78($29); swc1 $f15, 0x7C($29); swc1 $f16, 0x80($29); swc1 $f20, 0x84($29); jal tmbr_BossTrace; addiu $4, $0, 12; lq $4, 0($29); lq $5, 0x10($29); lq $6, 0x20($29); lq $7, 0x30($29); lq $31, 0x40($29); lq $8, 0x50($29); lq $9, 0x60($29); lwc1 $f12, 0x70($29); lwc1 $f13, 0x74($29); lwc1 $f14, 0x78($29); lwc1 $f15, 0x7C($29); lwc1 $f16, 0x80($29); lwc1 $f20, 0x84($29); j func_001FBCF8; addiu $29, $29, 0xA0; .set reorder");
#endif

/* Warhawk's roof outside the story (Ark 2026-10-27: "on warhawk i can hear warhawk flying around even tho he isnt
 * spawned"): the roof's Helicopter object still runs its rotor sound (Helicopter::Update 0x141178 -> func_0019BB80:
 * the moving, doppler-shifted helicopter loop) with nothing drawn. Multiplayer gets the roof as a plain arena: that
 * sound is only updated (so only started) in a story run. (g147 tried the ambient stream +0x5A0: not it.) */
extern void heliSound(void* s, void* pos, int a, int b) __asm__("func_0019BB80");
void tmbr_RoofHeliSound(void* s, void* pos, int a, int b)
{
    char* g = D_004FA030;
    if (g && F(g, 0x9FCA0) == 20 && !tmbr_Opt(OPT_STORY)) return;
    heliSound(s, pos, a, b);
}
