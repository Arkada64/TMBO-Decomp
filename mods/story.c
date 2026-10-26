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
    n = (level == 14 ? 1 : level == 20 ? 2 : AICOUNT[level]) + (tmbr_Opt(0x40) ? 1 : 0);   /* (roof: the boss pair) */   /* + the ally bot (GAME MODS ALLY BOT) */
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
        if (level == 14 && first) c = 15;
        if (level == 20) {                                /* Warhawk's roof: retail's two boss cars 0x200 / 0x220 only */
            if (first) c = 16; else if (!(used & 1 << 17)) c = 17; else continue;
        }
        for (k = 0; !c && k < 200; k++) {
            int r = mathfRandI(1, 14);
            if (!(used & 1 << r)) c = r;
        }
        if (!c) c = 1;
        used |= 1 << c;
        first = 0;
        F(D_003156C0 + s * 0x220, 0xB4) = c << 5;
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
