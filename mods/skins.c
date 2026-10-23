/* Gold Tooth and 12 Pak (Twisted Metal: Lost), synced to every player.
 *   Gold Tooth: Sweet Tooth skin, files \PCAR\ZZP.* / \ACAR\ZZA.*; on car select, while Sweet Tooth is highlighted
 *               a line shows it and L1 + SQUARE toggles.
 *   12 Pak:     his own (16th) spot on car select, after Minion. In game he is a Roadkill (type 1: Roadkill's stats,
 *               sounds, HUD; files \PCAR\ZYP.* / \ACAR\ZYA.*) with his own special: the reticle weapon (see
 *               tmbr_FireSpecial).
 * Car select (func_001CB4C8, every frame; hooked at its playShellCarsEngineSound call, which gets the highlighted
 * car's value = type << 5; position D_004FA7D8, list of values shell+0x1A2F0, 15 entries 0..14): the wrap
 * constants are 15 instead of 14, entry 15 is Roadkill's value, the preview model switch shows Roadkill there.
 * Sync: the choice goes out as a chat message "\x01SK<type><on>" (func_00171C08 sends chat to every client) on every
 * change and every 5 s in the waiting room; the chat handler (netMsgChatHandler, re-registered as tmbr_ChatHandler)
 * swallows those and records skin[sender]. Unmodded clients would see the message as a chat line.
 * Loading: every car file load goes through formatFilename with the code from the vehicle code table D_003F6A00
 * (8 bytes per type: "rk" = 1, "st" = 6, \PCAR\<code>P / \ACAR\<code>A). The per-client load calls (own car
 * func_00188A00, others func_00189268 / 478 / 680, late join func_001890F0) are wrapped: for the duration of the
 * call the client's skinned type gets the skin's code, then the table is restored. Bots keep the normal skin. */

extern char vehCodes[] __asm__("D_003F6A00");
extern char netState[] __asm__("D_003156C0");
extern int netGetMyClientIndex(void* net) __asm__("netGetMyClientIndex");
extern void netChatSend(void* net, const char* text) __asm__("func_00171C08");
extern int netMsgChatHandler(int a0, int a1, int client, char* msg) __asm__("netMsgChatHandler");
extern void playCarSound(void* s, int car) __asm__("playShellCarsEngineSound__10ShellSoundi");
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern void scePrintf(const char* f, ...);

extern void loadOwnCar(void* shell, int client) __asm__("func_00188A00");
extern void loadCar268(void* shell, int client, int ai) __asm__("func_00189268");
extern void loadCar478(void* shell, int client, int ai) __asm__("func_00189478");
extern void loadCar680(void* shell, int client, int ai) __asm__("func_00189680");
extern void loadCar0F0(void* shell, int client) __asm__("func_001890F0");

#define PAD_L1 0x400
#define PAD_SQUARE 0x8000
#define NSKIN 2

static const int skinType[NSKIN] = { 6, 1 };                       /* Sweet Tooth, Roadkill */
static const char skinCode[NSKIN][2] = { { 'z', 'z' }, { 'z', 'y' } };
static const char* const skinName[NSKIN] = { "GOLD TOOTH", "12 PAK" };
static const char* const baseName[NSKIN] = { "SWEET TOOTH", "ROADKILL" };

int tmbr_skin[NSKIN];                  /* this console's choices (12 Pak = car select position 15) */
#define PAK_POS 15
extern int carSelPos __asm__("D_004FA7D8");
extern char* shellPtr __asm__("D_004FA03C");
extern void hierSetSwitch(void* sw, int i) __asm__("hierSetSwitch__FP11_hierswitchi");
extern char* D_004FA030;
extern int netSlotVehicle(void* net, int client) __asm__("func_00174268");
extern void createWeapon(void* w, int type, char* v, void* t, void* tp) __asm__("func_001ED8D0");
static unsigned char remote[8][NSKIN]; /* per client, from their chat messages */
static int prevPad, resendTick;

static int skinOfType(int type)
{
    int k;
    for (k = 0; k < NSKIN; k++) if (skinType[k] == type) return k;
    return -1;
}

static void sendSkins(void)
{
    char m[8];
    int k;
    for (k = 0; k < NSKIN; k++) {
        m[0] = 1; m[1] = 'S'; m[2] = 'K'; m[3] = '0' + skinType[k]; m[4] = '0' + (tmbr_skin[k] != 0); m[5] = 0;
        netChatSend(netState, m);
    }
}

/* chat: our skin messages are recorded, not shown */
extern void tmbr_TrafficSyncRecv(int client, const char* data);   /* traffic.c */
int tmbr_ChatHandler(int a0, int a1, int client, char* msg)
{
    if (msg && msg[0] == 1 && msg[1] == 'T' && msg[2] == 'R') {
        tmbr_TrafficSyncRecv(client, msg + 3);
        return 0x44;
    }
    if (msg && msg[0] == 1 && msg[1] == 'S' && msg[2] == 'K') {
        int k = skinOfType(msg[3] - '0');
        if (k >= 0 && client >= 0 && client < 8) {
            if (remote[client][k] != (msg[4] == '1'))
                scePrintf("TMBR skins: client %d %s %s\n", client, skinName[k], msg[4] == '1' ? "on" : "off");
            remote[client][k] = msg[4] == '1';
        }
        return 0x44;
    }
    return netMsgChatHandler(a0, a1, client, msg);
}

static int skinOn(int client, int k)
{
    if (client == netGetMyClientIndex(netState)) return tmbr_skin[k];
    return client >= 0 && client < 8 && remote[client][k];
}

static void setCodes(int client)
{
    int k;
    for (k = 0; k < NSKIN; k++) {
        char* c = vehCodes + skinType[k] * 8;
        if (client >= 0 && skinOn(client, k)) { c[0] = skinCode[k][0]; c[1] = skinCode[k][1]; }
        else if (k == 0) { c[0] = 's'; c[1] = 't'; }
        else { c[0] = 'r'; c[1] = 'k'; }
    }
}

void tmbr_LoadOwnCar(void* shell, int client) { setCodes(client); loadOwnCar(shell, client); setCodes(-1); }
void tmbr_LoadCar268(void* s, int c, int ai) { setCodes(ai ? -1 : c); loadCar268(s, c, ai); setCodes(-1); }
void tmbr_LoadCar478(void* s, int c, int ai) { setCodes(ai ? -1 : c); loadCar478(s, c, ai); setCodes(-1); }
void tmbr_LoadCar680(void* s, int c, int ai) { setCodes(ai ? -1 : c); loadCar680(s, c, ai); setCodes(-1); }
void tmbr_LoadCar0F0(void* s, int c) { setCodes(c); loadCar0F0(s, c); setCodes(-1); }

/* car select frame: highlighted car value (type << 5) */
void tmbr_CarSelectSound(void* snd, int car)
{
    int pad, pressed, k = -1, pak;
    char line[64];
    playCarSound(snd, car);
    if (shellPtr) *(int*)(shellPtr + 0x1A2F0 + PAK_POS * 4) = 0x20;      /* 16th spot = a Roadkill */
    pak = carSelPos == PAK_POS;
    if (pak != tmbr_skin[1]) {
        tmbr_skin[1] = pak;
        scePrintf("TMBR skins: 12 PAK %s\n", pak ? "on" : "off");
        sendSkins();
    }
    pad = inputGetPadButtons(0) & (PAD_L1 | PAD_SQUARE);
    pressed = pad & ~prevPad;
    prevPad = pad;
    if (pak) {
        fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 11 * 0x100);
        fontPrint(0, "12 PAK   (TWISTED METAL: LOST)");
        return;
    }
    if ((car >> 5) == skinType[0]) k = 0;
    if (k < 0) return;
    if ((pad & PAD_L1) && (pressed & PAD_SQUARE)) {
        tmbr_skin[k] = !tmbr_skin[k];
        scePrintf("TMBR skins: %s %s\n", skinName[k], tmbr_skin[k] ? "on" : "off");
        sendSkins();
    }
    {
        const char* a = tmbr_skin[k] ? skinName[k] : baseName[k];
        const char* b = tmbr_skin[k] ? baseName[k] : skinName[k];
        int i = 0, j;
        for (j = 0; a[j]; j++) line[i++] = a[j];
        for (j = 0; "   (L1 + SQUARE: "[j]; j++) line[i++] = "   (L1 + SQUARE: "[j];
        for (j = 0; b[j]; j++) line[i++] = b[j];
        line[i++] = ')'; line[i] = 0;
    }
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 11 * 0x100);
    fontPrint(0, line);
}

/* car select preview model (shell+0xC3C switch, one child per position): the 16th spot shows Roadkill's */
void tmbr_PreviewSwitch(void* sw, int i)
{
    hierSetSwitch(sw, i == PAK_POS ? 0 : i);
}

/* is this vehicle a player's 12 Pak? (Roadkill driven by a client with the 12 Pak choice) */
static int isPak(char* v)
{
    int c, s;
    if (*(int*)(v + 0x20F4) != 0x20 || !D_004FA030) return 0;
    for (c = 0; c < 8; c++) {
        if (!skinOn(c, 1)) continue;
        s = netSlotVehicle(netState, c);
        if (s > 0 && s <= 8 && *(char**)(D_004FA030 + 0x9E670 + 4 * (s - 1)) == v) return 1;
    }
    return 0;
}

/* 12 Pak's special = the game's reticle weapon (weapon 0xB; FireCurrentWeapon's reticle pickup case): first press
 * arms it, the longer it stays armed the more missiles (1..10 over 4 s, like the pickup's 0x224*10/0x228), second
 * press (or 5 s) releases them at the lock-on target. Hooked at FireCurrentWeapon's FireSpecial call; everyone
 * else's special is untouched. Ammo: one special (func_001F1AE0 slot 1, as Roadkill's special uses). */
extern void fireSpecial(void* l, char* v) __asm__("FireSpecial__8LauncherP7Vehicle");
extern int getLockOn(void* l, char* v, void* t, void* tp, float r) __asm__("func_0015A650");
extern void weaponUsed(void* w, char* v, int slot) __asm__("func_001F1AE0");
extern int timerGetFieldCount(void) __asm__("timerGetFieldCount__Fv");
extern void hudAddMessage(void* hud, int id, int a, int b) __asm__("AddMessage__3Hudiii");
static float PK[2] = { 17.5f, 0.0f };     /* lock-on range used by the reticle pickup (D_004F9BC4) */
static int pakArm[8], pakT0[8];
static void* pakL[8];

static int vidx(char* v)
{
    int i = (int)(v - D_004FA030) / 0x31B0;
    return (i >= 0 && i < 8 && D_004FA030 + i * 0x31B0 == v) ? i : -1;
}

static void pakHud(char* v, int id)
{
    if (*(int*)(v + 0x20B4) == 1)
        hudAddMessage(D_004FA030 + 0x97B50 + *(int*)(v + 0x210C) * 0xA20, id, 1, 1);
}

static void pakRelease(int i)
{
    char* v = D_004FA030 + i * 0x31B0;
    void *t = 0, *tp = 0;
    int k, n = (timerGetFieldCount() - pakT0[i]) * 10 / 240;
    if (n < 1) n = 1;
    if (n > 10) n = 10;
    pakArm[i] = 0;
    getLockOn(pakL[i], v, &t, &tp, PK[0]);
    for (k = 0; k < n; k++) createWeapon(D_004FA030 + 0x6C310, 0xB, v, t, tp);
    weaponUsed(D_004FA030 + 0x6C310, v, 1);
    scePrintf("TMBR 12pak: special released, %d missiles\n", n);
}

void tmbr_FireSpecial(void* l, char* v)
{
    int i = vidx(v);
    if (i < 0 || !isPak(v)) { fireSpecial(l, v); return; }
    if (!pakArm[i]) {
        pakArm[i] = 1; pakT0[i] = timerGetFieldCount(); pakL[i] = l;
        pakHud(v, 0x80);
        return;
    }
    pakRelease(i);
}

/* every game frame (freecam.c's camera hook): armed reticles release by themselves after 5 s */
void tmbr_SkinsFrame(void)
{
    int i;
    if (!D_004FA030) return;
    for (i = 0; i < 8; i++)
        if (pakArm[i] && timerGetFieldCount() - pakT0[i] > 300) pakRelease(i);
}

/* waiting room (from tmbr_LobbyFrame): repeat the choice every 5 s for players who joined later */
void tmbr_SkinsLobby(void)
{
    if (++resendTick >= 300) { resendTick = 0; sendSkins(); }
}
