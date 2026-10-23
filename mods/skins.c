/* Alternate skins for two cars, picked on the car select screen and synced to every player.
 *   Sweet Tooth -> Gold Tooth (Twisted Metal: Lost), files \PCAR\ZZP.* / \ACAR\ZZA.*
 *   Roadkill    -> 12 Pak     (Twisted Metal: Lost), files \PCAR\ZYP.* / \ACAR\ZYA.*   (Roadkill's stats)
 * Car select (func_001CB4C8, every frame; hooked at its playShellCarsEngineSound call, which gets the highlighted
 * car's value = type << 5): while Sweet Tooth or Roadkill is highlighted a line shows the skin, L1 + SQUARE toggles.
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

int tmbr_skin[NSKIN];                  /* this console's choices */
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
    int pad, pressed, k = skinOfType(car >> 5);
    char line[64];
    playCarSound(snd, car);
    pad = inputGetPadButtons(0) & (PAD_L1 | PAD_SQUARE);
    pressed = pad & ~prevPad;
    prevPad = pad;
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

/* waiting room (from tmbr_LobbyFrame): repeat the choice every 5 s for players who joined later */
void tmbr_SkinsLobby(void)
{
    if (++resendTick >= 300) { resendTick = 0; sendSkins(); }
}
