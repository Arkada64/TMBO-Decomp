/* TMB-Reloaded mod: STORY run, phase 1 (reference/wip/STORY_PLAN.md, Ark 2026-10-26).
 * The host turns it on in the waiting room (R3 + Square). It plays retail's story level order, the same for
 * every driver (retail Shell::m_nextLevelMap):
 *   JUNKYARD -> SUBURBS | FREEWAY -> HIGHWAY LOOP | DOWNTOWN -> MINION'S STADIUM -> PRISON PASSAGE
 *   -> SNOWY ROADS | DRIVE-IN -> SKYSCRAPERS -> WARHAWK'S ROOF
 * Each level is Last Man Standing, humans vs bots (teams.c bot mode), 3 lives, with retail's AI count for that
 * level (retail SelectAICars: shell +0x19DDC table), distinct random drivers that are not a human's car, Minion
 * only on his stadium (alone there, like retail). Win (the bots' team is out) -> the next level; at a fork the
 * host picks with L3 in the waiting room. Lose -> the same level again. No movies / bosses / save yet
 * (phases 2-4). Host only: the level goes to everyone in the game info (shell +0x23AC), bots are host-made. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern int sprintf(char* d, const char* f, ...);
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

static int level = 1, stage = 1, fork = -1, playedSerial = -1, doneSerial = -1, wasOn, prevPad;
static char msg[32];

int tmbr_StoryOn(void) { return tmbr_Opt(OPT_STORY); }
int tmbr_StoryLevel(void) { return level; }

static void start(void)
{
    level = 1; stage = 1; fork = -1; msg[0] = 0;
    playedSerial = doneSerial = tmbr_levelSerial;
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
        return;
    }
    fork = level;
    level = NEXT[level][0];
    stage++;
    msg[0] = 0;
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
    if (on && !wasOn) start();
    if (!on && wasOn) tmbr_TeamsBotMode(0);
    wasOn = on;
    if (!on) return;
    result();
    if (!(pad & 0x4) && (pressed & 0x2) && fork >= 0 && NEXT[fork][0] != NEXT[fork][1]) {
        level = level == NEXT[fork][0] ? NEXT[fork][1] : NEXT[fork][0];
        msg[0] = 0;
        scePrintf("TMBR story: branch -> %s\n", NAME[level]);
    }
    /* the rules of a story level */
    n = level == 14 ? 1 : AICOUNT[level];
    tmbr_botCount = n > 7 ? 7 : n;
    tmbr_OptSet(OPT_TEAMS, 1);
    tmbr_OptSet(OPT_TEAMS4, 0);
    tmbr_TeamsBotMode(1);
    {
        int ch = 0;
        if (LEVEL() != level) { LEVEL() = level; ch = 1; }
        if (((F(gi, 0) >> 1) & 0xF) != 3) { F(gi, 0) = (F(gi, 0) & ~0x1E) | 3 << 1; ch = 1; }
        if (((unsigned char*)gi)[5] != LIVES) { gi[5] = LIVES; ch = 1; }
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
