/* TMB-Reloaded mod: team play (the online build's cut team modes, put back together).
 *
 * What the game still had (reference/wip/TEAM_MODES.md): a "teams on" bit in the game info (word 0 bit 12) and a
 * team per player (client struct +0x14). With them, lock-on skips teammates, radar blips / car markers use team
 * colours and teammate damage is not credited. Cut: picking teams, sending them, team score, team win.
 *
 * Here (the lobby switch itself is bots.c: TEAMS on/off, kept in game-info byte +0xC6):
 *  - Team table per player slot (tmbr_team[8], 0 = A, 1 = B). The host owns it and sends it to everyone as a
 *    hidden chat message "\x01TT" + 8 team digits + bot mode, on every change and every 2 s (late joiners).
 *    Players ask for a team with "\x01TQ<team>" (R3 + Left / Right in the lobby); the host applies it.
 *  - Bots: they take free player slots when they spawn (bots.c addBot), so their team goes in the same table.
 *    Bot mode (host, R3 + Select): BALANCED (each bot joins the smaller team) or VS PLAYERS (all humans team A,
 *    all bots team B). The lobby roster shows the bots that will spawn with their teams.
 *  - Every frame of a match every machine writes the table into the client structs (+0x14).
 *  - Team score: kills of the other team (from the kill feed, the same events on every machine), drawn under
 *    the damage report; at the end of the match (game type 1 = over) the winning team. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
#define VSIZE 0x31B0
extern char* D_004FA030;
extern char D_003156C0[];
extern int scePrintf(const char* fmt, ...);
extern int sprintf(char* d, const char* f, ...);
extern int netIsHost(void* net) __asm__("func_001734B8");
extern int netGetMyClientIndex(void* net) __asm__("netGetMyClientIndex");
extern void netChatSend(void* net, const char* text) __asm__("func_00171C08");
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern void fontSetColor(int font, int r, int g, int b) __asm__("fontSetColor__Fiiii");
extern void fontSpritePrintCenteredXY(int font, int x, int y, const char* s) __asm__("fontSpritePrintCenteredXY__FiiiPc");
extern void fontSpriteEnd(int font) __asm__("func_00202C58");
extern void* viewGetCurView(void) __asm__("viewGetCurView__Fv");
extern void viewGetSize(void* view, int* w, int* h) __asm__("func_00243AA8");
extern int tmbr_Opt(int bit);            /* bots.c: lobby options in the game info */
extern int tmbr_BotsPlanned(void);       /* bots.c: how many bots the match will start with */
extern int tmbr_levelSerial;
#define OPT_TEAMS 2
#define OPT_TEAMS4 4                     /* four teams (red, blue, yellow, purple) instead of two */
static int NT(void) { return tmbr_Opt(OPT_TEAMS4) ? 4 : 2; }
static const char* const TEAMNAME[4] = { "RED", "BLUE", "YELLOW", "PURPLE" };
const char* tmbr_TeamName(int t) { return TEAMNAME[t & 3]; }
#define CLIENT(s) (D_003156C0 + (s) * 0x220)
#define HUMAN(s) (F(CLIENT(s), 0x214) >= 7 && F(CLIENT(s), 0xC8) == 0)

int tmbr_team[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };
int tmbr_botTeamMode;                    /* 0 balanced, 1 vs players */
static char botSlot[8];                  /* host: slot taken by a bot this match */
static int sendTick, prevPad, dirty;
static int score[2], scoreSerial = -1, overShown, winner = -1, winShown = -1, lastType;
static signed char rcvVeh[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };   /* clients: car teams from the host */

int tmbr_TeamOf(char* v);
static void sendTable(void)
{
    char m[24];
    int s;
    m[0] = 1; m[1] = 'T'; m[2] = 'T';
    for (s = 0; s < 8; s++) m[3 + s] = '0' + (tmbr_team[s] & 3);
    m[11] = '0' + tmbr_botTeamMode;
    for (s = 0; s < 8; s++) {                 /* per car (bots have no player slot on the clients) */
        char* v = D_004FA030 ? D_004FA030 + s * VSIZE : 0;
        m[12 + s] = v && (F(v, 0x590) == 1 || F(v, 0x590) == 2) ? '0' + (tmbr_TeamOf(v) & 3) : '-';
    }
    m[20] = 0;
    netChatSend(D_003156C0, m);
}

static void setTeam(int s, int t)
{
    if (s < 0 || s > 7 || tmbr_team[s] == t) return;
    tmbr_team[s] = t;
    dirty = 1;
    scePrintf("TMBR teams: slot %d -> team %s\n", s, TEAMNAME[t & 3]);
}

/* chat (skins.c tmbr_ChatHandler): msg points after the \x01 */
void tmbr_TeamsRecv(int client, const char* msg)
{
    int s;
    if (msg[1] == 'T') {                                   /* TT: the host's table */
        if (netIsHost(D_003156C0)) return;
        for (s = 0; s < 8 && msg[2 + s]; s++) tmbr_team[s] = (msg[2 + s] - '0') & 3;
        if (msg[10]) tmbr_botTeamMode = msg[10] == '1';
        if (msg[10]) for (s = 0; s < 8 && msg[11 + s]; s++) rcvVeh[s] = msg[11 + s] == '-' ? -1 : msg[11 + s] - '0';
    } else if (msg[1] == 'Q') {                            /* TQ: a player asks for a team */
        if (!netIsHost(D_003156C0) || tmbr_botTeamMode) return;
        setTeam(client, ((msg[2] - '0') & 3) % NT());
    }
}

int tmbr_TeamOfSlot(int s) { return s >= 0 && s < 8 ? tmbr_team[s] : -1; }

/* team of a car: a bot's slot (host knows it), else its player slot (+0x20C0), else by car index */
static signed char vehSlot[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
int tmbr_TeamOf(char* v)
{
    int s = F(v, 0x20C0), k = (int)(v - D_004FA030) / VSIZE;
    if (k >= 0 && k < 8 && vehSlot[k] >= 0) return tmbr_team[(int)vehSlot[k]] % NT();
    if (s >= 0 && s < 8) return tmbr_team[s] % NT();
    if (k >= 0 && k < 8 && rcvVeh[k] >= 0) return rcvVeh[k] % NT();
    return k % NT();
}

/* Hooks over the game's own team code (it reads client +0x14 through the car's player slot +0x20C0, which is
 * -1 for bots, and only for humans):
 *  - car markers (func_001DCD48 0x1DCE2C) and radar blips (hud func_00149D08 0x14A91C): tmbr_TeamColorS(car)
 *    returns the colour code: 0 = red, 1 = blue (the game's team colours, func_0014C4D8), -1 = the car's own;
 *  - lock-on (func_0015A650 0x15A738): tmbr_SameTeam(shooter, target) = 1 skips that target. */
int tmbr_MarkerTeam(char* v)
{
    if (!tmbr_Opt(OPT_TEAMS) || !v || (F(v, 0x590) != 1 && F(v, 0x590) != 2)) return -1;
    {   /* colour codes for func_0014C4D8: the game's own red 0 / blue 1, ours 0xF02 / 0xF03 (tmbr_HudColor) */
        int t = tmbr_TeamOf(v) % NT();
        return t < 2 ? t : 0xF00 + t;
    }
}
int tmbr_SameTeam(char* a, char* b)
{
    return tmbr_MarkerTeam(a) >= 0 && tmbr_MarkerTeam(a) == tmbr_MarkerTeam(b);
}
/* the callers keep values in argument / temp registers across this point: save them all */
__asm__(".section .text\n.set push\n.set noreorder\n.globl tmbr_TeamColorS\ntmbr_TeamColorS:\n"
        "    addiu $29, $29, -0xC0\n"
        "    sq $31, 0x00($29)\n    sq $5, 0x10($29)\n    sq $6, 0x20($29)\n    sq $7, 0x30($29)\n"
        "    sq $8, 0x40($29)\n    sq $9, 0x50($29)\n    sq $10, 0x60($29)\n    sq $11, 0x70($29)\n"
        "    sq $12, 0x80($29)\n    sq $13, 0x90($29)\n    sq $14, 0xA0($29)\n    sq $15, 0xB0($29)\n"
        "    jal tmbr_MarkerTeam\n    nop\n"
        "    lq $31, 0x00($29)\n    lq $5, 0x10($29)\n    lq $6, 0x20($29)\n    lq $7, 0x30($29)\n"
        "    lq $8, 0x40($29)\n    lq $9, 0x50($29)\n    lq $10, 0x60($29)\n    lq $11, 0x70($29)\n"
        "    lq $12, 0x80($29)\n    lq $13, 0x90($29)\n    lq $14, 0xA0($29)\n    lq $15, 0xB0($29)\n"
        "    jr $31\n    addiu $29, $29, 0xC0\n.set pop\n.previous\n");

/* bots.c addBot: a bot (car index k) took slot s (host) */
void tmbr_TeamsBotJoined(int s, int k)
{
    int t, s2, n[4] = { 0, 0, 0, 0 };
    if (s < 0 || s > 7) return;
    botSlot[s] = 1;
    if (k >= 0 && k < 8) vehSlot[k] = s;
    if (tmbr_botTeamMode) t = 1;
    else {
        for (s2 = 0; s2 < 8; s2++)
            if (s2 != s && (HUMAN(s2) || botSlot[s2])) n[tmbr_team[s2] % NT()]++;
        for (t = 0, s2 = 1; s2 < NT(); s2++) if (n[s2] < n[t]) t = s2;
    }
    setTeam(s, t);
}
void tmbr_TeamsBotLeft(char* v)
{
    int k = (int)(v - D_004FA030) / VSIZE;
    if (k < 0 || k > 7 || vehSlot[k] < 0) return;
    botSlot[(int)vehSlot[k]] = 0;
    vehSlot[k] = -1;
}

/* kill feed (skins.c tmbr_KillMessage): team score now comes from the game's own stats (teamStats) */
void tmbr_TeamsKill(int victim, int killer) { (void)victim; (void)killer; }

/* Team totals from the game's per-car stats (net D_003156C0: kills +0x2F28 [car], score +0x2F88 [car], deaths
 * +0x2F48 [car +0x2104]; limits: kills u16 +0x3098, score +0x308C, lives = game info byte +5; func_001761E8). */
typedef struct { int kills[4], pts[4], members[4], alive[4]; } TeamStats;
static void teamStats(TeamStats* ts)
{
    char *g = D_004FA030, *gi = *(char**)(D_003156C0 + 0x3148);
    int k, lives = gi ? ((unsigned char*)gi)[5] : 0;
    for (k = 0; k < 4; k++) ts->kills[k] = ts->pts[k] = ts->members[k] = ts->alive[k] = 0;
    if (!g) return;
    for (k = 0; k < 8; k++) {
        char* v = g + k * VSIZE;
        int t, d, slot;
        if (!F(v, 0x20D8) || (F(v, 0x590) != 1 && F(v, 0x590) != 2)) continue;
        t = tmbr_TeamOf(v) & 3;
        ts->kills[t] += F(D_003156C0, 0x2F28 + 4 * k);
        ts->pts[t] += F(D_003156C0, 0x2F88 + 4 * k);
        ts->members[t]++;
        slot = F(v, 0x2104);
        d = slot >= 0 && slot < 8 ? F(D_003156C0, 0x2F48 + 4 * slot) : 0;
        if (!lives || d < lives) ts->alive[t]++;
    }
}
static int gameType(void)
{
    char* gi = *(char**)(D_003156C0 + 0x3148);
    return gi ? (F(gi, 0) >> 1) & 0xF : 0;
}
/* the leading team: Last Man Standing = the team still alive, else score (Fox Hunt / Collector) or kills */
static int leader(TeamStats* ts, int type)
{
    int t, best = -1, bv = -1, tie = 0, alive = 0, last = -1;
    if (type == 3) {                                      /* Last Man Standing: the only team still alive */
        for (t = 0; t < NT(); t++) if (ts->members[t] && ts->alive[t]) { alive++; last = t; }
        if (alive == 1) return last;
    }
    for (t = 0; t < NT(); t++) {
        int v = (type == 4 || type == 5) ? ts->pts[t] : ts->kills[t];
        if (!ts->members[t]) continue;
        if (v > bv) { bv = v; best = t; tie = 0; } else if (v == bv) tie = 1;
    }
    return tie ? -1 : best;
}
extern void netEndMatch(void* net, int reason, int x) __asm__("func_00174D78");
/* host: team versions of the limits (a team reaches the kill / score limit together; Last Man Standing ends
 * when one team has nobody left). The game's own player checks still run after ours. */
static void teamLimits(void)
{
    char* gi = *(char**)(D_003156C0 + 0x3148);
    TeamStats ts;
    int type, kl, sl, t;
    if (!gi || !(F(gi, 0) & 1) || (type = gameType()) == 1) return;      /* not started / over */
    teamStats(&ts);
    kl = *(unsigned short*)(D_003156C0 + 0x3098);
    sl = F(D_003156C0, 0x308C);
    for (t = 0; t < NT(); t++) {
        if (kl > 0 && ts.kills[t] >= kl) { winner = t; netEndMatch(D_003156C0, 2, 0); break; }
        if (sl > 0 && ts.pts[t] >= sl) { winner = t; netEndMatch(D_003156C0, 4, 0); break; }
    }
    if (winner < 0 && type == 3 && ((unsigned char*)gi)[5]) {
        int teams = 0, alive = 0, last = -1;
        for (t = 0; t < NT(); t++) if (ts.members[t]) { teams++; if (ts.alive[t]) { alive++; last = t; } }
        if (teams >= 2 && alive <= 1) { winner = last < 0 ? 0 : last; netEndMatch(D_003156C0, 3, 0); }
    }
    if (winner >= 0) scePrintf("TMBR teams: %s team reached the limit, match over\n", TEAMNAME[winner & 3]);
}

/* every frame of a match (bots.c tmbr_BotsThink, all machines) */
void tmbr_TeamsFrame(void)
{
    int s, k;
    char* g = D_004FA030;
    if (!tmbr_Opt(OPT_TEAMS) || !g) return;
    if (scoreSerial != tmbr_levelSerial) {
        scoreSerial = tmbr_levelSerial;
        score[0] = score[1] = 0;
        overShown = 0;
        winner = -1;
        for (k = 0; k < 8; k++) rcvVeh[k] = -1;
        for (k = 0; k < 8; k++) {
            char* v = g + k * VSIZE;
            if (F(v, 0x590)) scePrintf("TMBR teams: car %d kind %d slot %d team %s\n", k, F(v, 0x590), F(v, 0x20C0), TEAMNAME[tmbr_TeamOf(v) & 3]);
        }
    }
    if (tmbr_botTeamMode)                                  /* vs players: every human on A */
        for (s = 0; s < 8; s++) if (HUMAN(s) && !botSlot[s]) tmbr_team[s] = 0;
    for (s = 0; s < 8; s++) F(CLIENT(s), 0x14) = tmbr_team[s];
    if (netIsHost(D_003156C0) && (dirty || ++sendTick >= 120)) { dirty = 0; sendTick = 0; sendTable(); }
    if (gameType() > 1) lastType = gameType();
    if (netIsHost(D_003156C0) && winner < 0) teamLimits();
}

/* team 0 = RED, 1 = BLUE (text colours, 0x80 = full) */
void tmbr_TeamColor(int t)
{
    static const unsigned char c[4][3] = { { 0x80, 0x28, 0x20 }, { 0x30, 0x58, 0x80 }, { 0x80, 0x70, 0x10 }, { 0x60, 0x28, 0x80 } };
    fontSetColor(0, c[t & 3][0], c[t & 3][1], c[t & 3][2]);
}
int tmbr_MyTeam(void)
{
    int me = netGetMyClientIndex(D_003156C0);
    if (tmbr_botTeamMode) return 0;
    return me >= 0 && me < 8 ? tmbr_team[me] % NT() : 0;
}

/* HUD (dmgreport.c tmbr_DamageReportTick, every frame): team score under the damage report */
void tmbr_TeamsHud(void)
{
    char buf[48];
    int wh[2], w;
    TeamStats ts;
    if (!tmbr_Opt(OPT_TEAMS) || !D_004FA030 || gameType() != 1) { overShown = 0; return; }
    /* match over: the winning team in its colour (nothing during the match) */
    if (!overShown) {
        overShown = 1;
        teamStats(&ts);
        score[0] = ts.kills[0]; score[1] = ts.kills[1];
        w = winner >= 0 ? winner : leader(&ts, lastType);
        winShown = w;
        scePrintf("TMBR teams: over, kills red %d blue %d, score red %d blue %d, alive red %d blue %d, winner %s\n",
            ts.kills[0], ts.kills[1], ts.pts[0], ts.pts[1], ts.alive[0], ts.alive[1], w < 0 ? "tie" : TEAMNAME[w & 3]);
    }
    viewGetSize(viewGetCurView(), &wh[0], &wh[1]);
    if (winShown < 0) { sprintf(buf, "TEAMS TIED"); fontSetColor(0, 0x80, 0x80, 0x80); }
    else { sprintf(buf, "%s TEAM WINS", TEAMNAME[winShown & 3]); tmbr_TeamColor(winShown); }
    fontSpritePrintCenteredXY(0, wh[0] / 2, wh[1] / 2 - 40, buf);
    fontSpriteEnd(0);
}

/* waiting room (bots.c tmbr_LobbyFrame, every machine): team pick and the two roster lines (28 chars max).
 * R3 + Left / Right: my team A / B. Host: R3 + Select: bot mode. */
void tmbr_TeamsLobby(char* la, char* lb)
{
    char* line[2];
    int len[2], s, me = netGetMyClientIndex(D_003156C0), host = netIsHost(D_003156C0);
    int pad, pressed, bots, b, n[2] = { 0, 0 };
    line[0] = la; line[1] = lb;
    la[0] = lb[0] = 0;
    if (!tmbr_Opt(OPT_TEAMS)) return;
    pad = inputGetPadButtons(0) & 0xA5;      /* R3 0x4, Select 0x1, Right 0x20, Left 0x80 */
    pressed = pad & ~prevPad;
    prevPad = pad;
    if ((pad & 0x4) && (pressed & 0xA1)) {
        if (pressed & 0x1) {
            if (host) { tmbr_botTeamMode ^= 1; dirty = 1; }
        } else if (!tmbr_botTeamMode) {
            int cur = me >= 0 && me < 8 ? tmbr_team[me] % NT() : 0;
            int t = (cur + ((pressed & 0x20) ? 1 : NT() - 1)) % NT();   /* Right: next team, Left: previous */
            if (host) setTeam(me, t);
            else {
                char m[5];
                m[0] = 1; m[1] = 'T'; m[2] = 'Q'; m[3] = '0' + t; m[4] = 0;
                netChatSend(D_003156C0, m);
                tmbr_team[me & 7] = t;               /* shows at once; the host's table confirms it */
            }
        }
    }
    if (host && (dirty || ++sendTick >= 120)) { dirty = 0; sendTick = 0; sendTable(); }
    if (NT() == 4) {                                   /* four teams: counts (players + the bots to come) */
        int c[4] = { 0, 0, 0, 0 };
        for (s = 0; s < 8; s++) if (HUMAN(s)) c[tmbr_botTeamMode ? 0 : tmbr_team[s] & 3]++;
        bots = tmbr_BotsPlanned();
        for (b = 0; b < bots; b++) {
            int t, m = 0;
            if (tmbr_botTeamMode) t = 1;
            else { for (t = 1; t < 4; t++) if (c[t] < c[m]) m = t; t = m; }
            c[t]++;
        }
        sprintf(la, "RED %d  BLUE %d", c[0], c[1]);
        sprintf(lb, "YELLOW %d  PURPLE %d", c[2], c[3]);
        return;
    }
    for (s = 0; s < 2; s++) len[s] = sprintf(line[s], "%s%s:", TEAMNAME[s], tmbr_botTeamMode ? (s ? " BOTS" : " HUMANS") : "");
    for (s = 0; s < 8; s++) {
        int t;
        if (!HUMAN(s)) continue;
        t = tmbr_botTeamMode ? 0 : tmbr_team[s] & 1;
        n[t]++;
        if (len[t] < 18) len[t] += sprintf(line[t] + len[t], " %.8s", CLIENT(s) + 0x18);
        else if (len[t] < 26) len[t] += sprintf(line[t] + len[t], " +");
    }
    bots = tmbr_BotsPlanned();
    for (b = 0; b < bots; b++) {                   /* the bots that will spawn, as they will be placed */
        int t = tmbr_botTeamMode ? 1 : n[1] < n[0];
        n[t]++;
        if (len[t] < 24) len[t] += sprintf(line[t] + len[t], " BOT");
    }
}

/* Names over the cars (hud func_00149D08 0x14B098: func_0014C4D8(hud, car +0x20F4, &r, &g, &b) picks the text
 * colour from the car's own colour code): with teams on, a player's / bot's name takes its team colour too.
 * The stub passes the car ($s3) on as the 6th argument. Other codes (the fox in Man Hunt) stay as they are. */
extern void hudColorOf(char* hud, int code, unsigned char* r, unsigned char* g, unsigned char* b) __asm__("func_0014C4D8");
/* colour lookup for every HUD caller that can get a team code: the game's func_0014C4D8, plus ours */
void tmbr_HudColor(char* hud, int code, unsigned char* r, unsigned char* g, unsigned char* b)
{
    if (code == 0xF02) { *r = 0xF5; *g = 0xD0; *b = 0x20; return; }      /* yellow */
    if (code == 0xF03) { *r = 0xA8; *g = 0x40; *b = 0xF0; return; }      /* purple */
    hudColorOf(hud, code, r, g, b);
}
void tmbr_NameColor(char* hud, int code, unsigned char* r, unsigned char* g, unsigned char* b, char* v)
{
    int t = v && code == F(v, 0x20F4) ? tmbr_MarkerTeam(v) : -1;
    tmbr_HudColor(hud, t >= 0 ? t : code, r, g, b);
}
__asm__(".section .text\n.set push\n.set noreorder\n.globl tmbr_NameColorS\ntmbr_NameColorS:\n"
        "    j       tmbr_NameColor\n    move    $9, $19\n.set pop\n.previous\n");
