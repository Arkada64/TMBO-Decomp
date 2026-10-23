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
#define CLIENT(s) (D_003156C0 + (s) * 0x220)
#define HUMAN(s) (F(CLIENT(s), 0x214) >= 7 && F(CLIENT(s), 0xC8) == 0)

int tmbr_team[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };
int tmbr_botTeamMode;                    /* 0 balanced, 1 vs players */
static char botSlot[8];                  /* host: slot taken by a bot this match */
static int sendTick, prevPad, dirty;
static int score[2], scoreSerial = -1, overShown;

static void sendTable(void)
{
    char m[16];
    int s;
    m[0] = 1; m[1] = 'T'; m[2] = 'T';
    for (s = 0; s < 8; s++) m[3 + s] = '0' + (tmbr_team[s] & 1);
    m[11] = '0' + tmbr_botTeamMode;
    m[12] = 0;
    netChatSend(D_003156C0, m);
}

static void setTeam(int s, int t)
{
    if (s < 0 || s > 7 || tmbr_team[s] == t) return;
    tmbr_team[s] = t;
    dirty = 1;
    scePrintf("TMBR teams: slot %d -> team %s\n", s, t ? "blue" : "red");
}

/* chat (skins.c tmbr_ChatHandler): msg points after the \x01 */
void tmbr_TeamsRecv(int client, const char* msg)
{
    int s;
    if (msg[1] == 'T') {                                   /* TT: the host's table */
        if (netIsHost(D_003156C0)) return;
        for (s = 0; s < 8 && msg[2 + s]; s++) tmbr_team[s] = msg[2 + s] == '1';
        if (msg[10]) tmbr_botTeamMode = msg[10] == '1';
    } else if (msg[1] == 'Q') {                            /* TQ: a player asks for a team */
        if (!netIsHost(D_003156C0) || tmbr_botTeamMode) return;
        setTeam(client, msg[2] == '1');
    }
}

int tmbr_TeamOfSlot(int s) { return s >= 0 && s < 8 ? tmbr_team[s] : -1; }

/* team of a car: a bot's slot (host knows it), else its player slot (+0x20C0), else by car index */
static signed char vehSlot[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
int tmbr_TeamOf(char* v)
{
    int s = F(v, 0x20C0), k = (int)(v - D_004FA030) / VSIZE;
    if (k >= 0 && k < 8 && vehSlot[k] >= 0) return tmbr_team[(int)vehSlot[k]];
    if (s >= 0 && s < 8) return tmbr_team[s];
    return k & 1;
}

/* bots.c addBot: a bot (car index k) took slot s (host) */
void tmbr_TeamsBotJoined(int s, int k)
{
    int t, s2, n[2] = { 0, 0 };
    if (s < 0 || s > 7) return;
    botSlot[s] = 1;
    if (k >= 0 && k < 8) vehSlot[k] = s;
    if (tmbr_botTeamMode) t = 1;
    else {
        for (s2 = 0; s2 < 8; s2++)
            if (s2 != s && (HUMAN(s2) || botSlot[s2])) n[tmbr_team[s2] & 1]++;
        t = n[1] < n[0];
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

/* kill feed (skins.c tmbr_KillMessage, first viewport only): victim / killer are car ids (+0x20FC) */
void tmbr_TeamsKill(int victim, int killer)
{
    char *g = D_004FA030, *vv = 0, *kv = 0;
    int i;
    if (!tmbr_Opt(OPT_TEAMS) || !g) return;
    for (i = 0; i < 8; i++) {
        char* v = g + i * VSIZE;
        if (!F(v, 0x590)) continue;
        if (F(v, 0x20FC) == victim) vv = v;
        if (F(v, 0x20FC) == killer) kv = v;
    }
    if (!vv || !kv || vv == kv) return;
    if (tmbr_TeamOf(kv) != tmbr_TeamOf(vv)) score[tmbr_TeamOf(kv) & 1]++;
    else if (score[tmbr_TeamOf(kv) & 1] > 0) score[tmbr_TeamOf(kv) & 1]--;   /* team kill */
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
        for (k = 0; k < 8; k++) {
            char* v = g + k * VSIZE;
            if (F(v, 0x590)) scePrintf("TMBR teams: car %d kind %d slot %d team %s\n", k, F(v, 0x590), F(v, 0x20C0), tmbr_TeamOf(v) ? "blue" : "red");
        }
    }
    if (tmbr_botTeamMode)                                  /* vs players: every human on A */
        for (s = 0; s < 8; s++) if (HUMAN(s) && !botSlot[s]) tmbr_team[s] = 0;
    for (s = 0; s < 8; s++) F(CLIENT(s), 0x14) = tmbr_team[s];
    if (netIsHost(D_003156C0) && (dirty || ++sendTick >= 120)) { dirty = 0; sendTick = 0; sendTable(); }
}

/* team 0 = RED, 1 = BLUE (text colours, 0x80 = full) */
void tmbr_TeamColor(int t)
{
    if (t) fontSetColor(0, 0x30, 0x58, 0x80);
    else fontSetColor(0, 0x80, 0x28, 0x20);
}
int tmbr_MyTeam(void)
{
    int me = netGetMyClientIndex(D_003156C0);
    if (tmbr_botTeamMode) return 0;
    return me >= 0 && me < 8 ? tmbr_team[me] & 1 : 0;
}

/* HUD (traffic.c tmbr_DamageReportTick, every frame): team score under the damage report */
void tmbr_TeamsHud(void)
{
    char buf[48];
    int wh[2], over;
    char* gi = *(char**)(D_003156C0 + 0x3148);
    if (!tmbr_Opt(OPT_TEAMS) || !D_004FA030 || !gi) return;
    over = ((F(gi, 0) >> 1) & 0xF) == 1;
    viewGetSize(viewGetCurView(), &wh[0], &wh[1]);
    if (over) {
        if (score[0] == score[1]) sprintf(buf, "TEAMS TIED  %d - %d", score[0], score[1]);
        else sprintf(buf, "%s TEAM WINS  %d - %d", score[0] > score[1] ? "RED" : "BLUE", score[0], score[1]);
        if (!overShown) { overShown = 1; scePrintf("TMBR teams: %s\n", buf); }
        if (score[0] == score[1]) fontSetColor(0, 0x80, 0x80, 0x80);
        else tmbr_TeamColor(score[0] > score[1] ? 0 : 1);
        fontSpritePrintCenteredXY(0, wh[0] / 2, wh[1] / 2 - 40, buf);
    } else {
        /* "YOU: RED  3 - 1" in your team's colour: your score first */
        int me = tmbr_MyTeam();
        sprintf(buf, "YOU: %s  %d - %d", me ? "BLUE" : "RED", score[me], score[me ^ 1]);
        tmbr_TeamColor(me);
        fontSpritePrintCenteredXY(0, wh[0] / 2, 47, buf);
    }
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
            int t = (pressed & 0x20) != 0;
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
    for (s = 0; s < 2; s++) len[s] = sprintf(line[s], "%s%s:", s ? "BLUE" : "RED", tmbr_botTeamMode ? (s ? " BOTS" : " HUMANS") : "");
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
