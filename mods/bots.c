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
#define LIST(g) ((char**)((g) + 0x9E690))
#define SORT(g) ((int*)((g) + 0x9E6A8))
#define NAI(g) F(g, 0x9FEE4)

extern char* D_004FA030;   /* game */
extern char D_003156C0[];  /* net: 8 player slots x 0x220 from +0 */
extern int D_002C07F8[];   /* radar name per character */
extern int scePrintf(const char* fmt, ...);
extern int inputGetInput(int mask, int pad) __asm__("inputGetInput__Fii");
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
    if (inputGetInput(0x4, 0)) pad |= 0x4;
    if (inputGetInput(0x800, 0)) pad |= 0x800;
    if (inputGetInput(0x400, 0)) pad |= 0x400;
    pressed = pad & ~prevPad;
    prevPad = pad;
    if ((pad & 0x4) && (pressed & 0xC00)) {
        if (pressed & 0x800) tmbr_botCount++;
        if (pressed & 0x400) tmbr_botCount--;
        if (tmbr_botCount < -1) tmbr_botCount = -1;
        if (tmbr_botCount > MAXBOTS) tmbr_botCount = MAXBOTS;
        scePrintf("TMBR bots: lobby setting %d\n", tmbr_botCount);
    }
    if (tmbr_botCount < 0) sprintf(buf, "BOTS : AUTO  (R3 + L1/R1)");
    else sprintf(buf, "BOTS : %d  (R3 + L1/R1)", tmbr_botCount);
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 10 * 0x100);
    fontPrint(0, buf);
}
