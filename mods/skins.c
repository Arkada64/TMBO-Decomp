/* 12 Pak (Twisted Metal: Lost), synced to every player. (Gold Tooth, skin 0, was removed 2026-10-23.)
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
/* 12 Pak bots (TODO 6, 2026-10-26): the host gives some bot slots 12 Pak (tmbr_BotPakSet from tmbr_BotCars: car =
 * Roadkill, bit set); the mask goes to everyone with the skins ("\x01SB<2 hex>"). A slot counts as a 12 Pak bot
 * only while no human holds it (client +0x10 == -1). */
static unsigned char botPak;
extern int tmbr_GuestSlot(int s);   /* guests.c */
static int prevPad, resendTick;

static int skinOfType(int type)
{
    int k;
    for (k = 0; k < NSKIN; k++) if (skinType[k] == type) return k;
    return -1;
}

static void sendBotPak(void)
{
    static const char hx[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    char m[8];
    extern int netIsHost(void* net) __asm__("func_001734B8");
    if (!netIsHost(netState)) return;
    m[0] = 1; m[1] = 'S'; m[2] = 'B'; m[3] = hx[botPak >> 4]; m[4] = hx[botPak & 15]; m[5] = 0;
    netChatSend(netState, m);
}
void tmbr_BotPakSet(int mask)
{
    if (botPak != (unsigned char)mask) scePrintf("TMBR skins: 12 Pak bots %02x\n", mask & 0xFF);
    botPak = (unsigned char)mask;
    sendBotPak();
}
static void sendSkins(void)
{
    char m[8];
    int k;
    sendBotPak();
    for (k = 0; k < NSKIN; k++) {
        m[0] = 1; m[1] = 'S'; m[2] = 'K'; m[3] = '0' + skinType[k]; m[4] = '0' + (tmbr_skin[k] != 0); m[5] = 0;
        netChatSend(netState, m);
    }
}

/* chat: our skin messages are recorded, not shown */
extern void tmbr_TrafficSyncRecv(int client, const char* data);   /* traffic.c */
extern void tmbr_TeamsRecv(int client, const char* msg);           /* teams.c */
extern void tmbr_TeamsKill(int victim, int killer);
int tmbr_ChatHandler(int a0, int a1, int client, char* msg)
{
    if (msg && msg[0] == 1 && msg[1] == 'T' && msg[2] == 'R') {
        tmbr_TrafficSyncRecv(client, msg + 3);
        return 0x44;
    }
    if (msg && msg[0] == 1 && msg[1] == 'T' && (msg[2] == 'T' || msg[2] == 'Q')) {
        tmbr_TeamsRecv(client, msg + 1);
        return 0x44;
    }
    if (msg && msg[0] == 1 && msg[1] == 'S' && msg[2] == 'B') {
        int h = msg[3] >= 'A' ? msg[3] - 'A' + 10 : msg[3] - '0', l = msg[4] >= 'A' ? msg[4] - 'A' + 10 : msg[4] - '0';
        if (botPak != (unsigned char)(h << 4 | l)) scePrintf("TMBR skins: 12 Pak bots %02x (from %d)\n", h << 4 | l, client);
        botPak = (unsigned char)(h << 4 | l);
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
    if (k == 0) return 0;                            /* Gold Tooth removed */
    if (k == 1 && client >= 0 && client < 8 && (botPak >> client & 1) && *(int*)(netState + client * 0x220 + 0x10) == -1 && !tmbr_GuestSlot(client)) return 1;
    if (client == netGetMyClientIndex(netState)) return tmbr_skin[k];
    return client >= 0 && client < 8 && remote[client][k];
}

/* waiting room player list (func_001C5768 0x1C5E94 / 0x1C5ED4: sprintf(buf, "%s", carName[car >> 5])): the row's
 * client struct is in $s2 there; the stub passes it on, and a player with 12 Pak on shows "12 PAK". */
extern char* D_0041BF00[];          /* waiting-room car names by car code >> 5 (1 = "ROADKILL") */
extern int sprintf(char* d, const char* f, ...);
__asm__(".section .text\n.set push\n.set noreorder\n.globl tmbr_LobbyCarNameS\ntmbr_LobbyCarNameS:\n"
        "    j       tmbr_LobbyCarName\n    move    $7, $18\n.set pop\n.previous\n");
int tmbr_LobbyCarName(char* buf, const char* fmt, const char* name, char* row)
{
    int i = (int)(row - netState) / 0x220;
    if (name == D_0041BF00[1] && i >= 0 && i < 8 && skinOn(i, 1)) name = "12 PAK";
    return sprintf(buf, fmt, name);
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
extern int D_004EFBF0[];                         /* static car select value list (rodata) */
void tmbr_CarSelectSound(void* snd, int car)
{
    int pad, pressed, pak;
    if (shellPtr) *(int*)(shellPtr + 0x1A2F0 + PAK_POS * 4) = 0x20;      /* 16th spot = a Roadkill */
    D_004EFBF0[PAK_POS] = 0x20;                       /* the static list the shell copies its list from (was 0) */
    if (carSelPos == PAK_POS || car <= 0) car = 0x20;  /* first frame back from a match: the 16th slot still read 0
                                                         * (no car) -> engine-sound stream index -1, read past the disc */
    {   /* Minion off (lobby option, bots.c OPT_MINION clear): the highlight hops over his spot, in the direction it came */
        extern int tmbr_Opt(int bit);
        static int lastSel = -1;
        int k, mpos = -1;
        for (k = 0; k < PAK_POS; k++) if (D_004EFBF0[k] == (15 << 5)) { mpos = k; break; }
        if (!tmbr_Opt(8) && mpos >= 0 && carSelPos == mpos) {
            carSelPos = lastSel == (mpos + 1) % (PAK_POS + 1) ? (mpos + PAK_POS) % (PAK_POS + 1) : (mpos + 1) % (PAK_POS + 1);
            car = D_004EFBF0[carSelPos] > 0 ? D_004EFBF0[carSelPos] : 0x20;
        }
        lastSel = carSelPos;
    }
    playCarSound(snd, car);
    { extern void tmbr_GuestPickTitle(void); tmbr_GuestPickTitle(); }   /* guests.c: "PLAYER n" while a guest picks */
    pak = carSelPos == PAK_POS;
    { extern int tmbr_GuestPicking(void); if (tmbr_GuestPicking()) return; }   /* a guest's pick: not the host's skin */
    if (pak != tmbr_skin[1]) {
        tmbr_skin[1] = pak;
        scePrintf("TMBR skins: 12 PAK %s\n", pak ? "on" : "off");
        sendSkins();
    }
    (void)pad; (void)pressed;
    /* Gold Tooth (skin 0) removed 2026-10-23: the toggle is gone and skin 0 is never on, here or from others */
}

/* car select name plate (shell+0xC3C switch, one child per position; SHELL1 ids 9033). Child 15 was the cut
 * 'Black Razer' plate; the test disc's SHELL1.TEX repaints it '12 Pak' (tools/lost/plate12pak.py), so the 16th
 * spot uses it as is. */
void tmbr_PreviewSwitch(void* sw, int i)
{
    hierSetSwitch(sw, i);
}

/* while 12 Pak's launcher updates, his vehicle id is swapped from Roadkill's (0x20) to this unused id, so
 * Roadkill's hold-to-charge special logic (keyed on id 0x20: charge sound, saw blades) never runs for him */
#define PAK_ID 0x7E0

/* is this vehicle a player's 12 Pak? (Roadkill driven by a client with the 12 Pak choice) */
static int isPak(char* v)
{
    int c, s;
    int id = *(int*)(v + 0x20F4);
    if ((id != 0x20 && id != PAK_ID) || !D_004FA030) return 0;
    for (c = 0; c < 8; c++) {
        if (!skinOn(c, 1)) continue;
        s = netSlotVehicle(netState, c);
        if (s > 0 && s <= 8 && *(char**)(D_004FA030 + 0x9E670 + 4 * (s - 1)) == v) return 1;
    }
    return 0;
}

int tmbr_IsPak(char* v) { return v && isPak(v); }

/* 12 Pak's special IS the game's reticle (slot-5 pickup type 0xB at launcher+0x110), run from his special slot:
 * FireCurrentWeapon is re-entered with the slot temporarily reading 5 / type 0xB, so the game's own reticle code
 * arms it (launcher+0x218), releases it on the next special press, or times it out / cancels it on a weapon
 * switch. Its ammo calls for slot 5 (release, timeout, cancel: tmbr_ReticleUsed) take a special instead while
 * his reticle is up. Pickup reticles he collects still use slot 5 as usual. */
extern void fireSpecial(void* l, char* v) __asm__("FireSpecial__8LauncherP7Vehicle");
extern void fireCurrentWeapon(void* l, char* v) __asm__("func_00156E08");
extern void weaponUsed(void* w, char* v, int slot) __asm__("func_001F1AE0");
#define L_SLOT(l)    (*(int*)((char*)(l) + 0x0))
#define L_S5TYPE(l)  (*(int*)((char*)(l) + 0x110))
#define L_ARMED(l)   (*(int*)((char*)(l) + 0x218))
extern void tmbr_DamageReportTick(void);
static int pakRet[8], pakMountLog[8], pakCool[8], pakFrames;
#define PAK_COOLDOWN (10 * 60)                   /* Lost: 10 s between 12 Pak specials */
/* TMB's reticle missile: damage 7, life 7 s, turn 0.1 (D_004FAB98/9C/A4). Lost's reticle weapons: type 4 (taken as
 * 12 Pak's special) vs type 51 (the pickup): damage 13.5 / 21 (x0.64), life 7 / 12 s (x0.58), homing 0.08 / 0.15
 * (x0.53), charge 2.5 / 1.5 (x1.67 slower). 12 Pak gets TMB's values times those ratios. */
#define PAK_DAMAGE 5
#define PAK_LIFE   4
static float PAK_TURN_V[1] = { 0.053f };    /* static, not a literal: mod code has no .lit4 */
#define PAK_TURN   PAK_TURN_V[0]
extern int D_004FAB98, D_004FAB9C;
extern float D_004FABA4;
static char* pakGame;

static int vidx(char* v)
{
    int i = (int)(v - D_004FA030) / 0x31B0;
    return (i >= 0 && i < 8 && D_004FA030 + i * 0x31B0 == v) ? i : -1;
}

#define L_AMMO(l, s) (*(int*)((char*)(l) + 0x188 + 4 * (s)))
static int pakHold[8], pakOldCnt[8], pakOldType[8], pakOldSlot[8], pakSaved[3], pakSwapped;

/* while any 12 Pak reticle is up, the reticle missile globals hold his values (the release can come from the
 * fire button too, through the game's own slot-5 path) */
static void pakMissileValues(int on)
{
    if (on && !pakSwapped) {
        pakSaved[0] = D_004FAB98; pakSaved[1] = D_004FAB9C; *(float*)&pakSaved[2] = D_004FABA4;
        D_004FAB98 = PAK_DAMAGE; D_004FAB9C = PAK_LIFE; D_004FABA4 = PAK_TURN; pakSwapped = 1;
    } else if (!on && pakSwapped) {
        D_004FAB98 = pakSaved[0]; D_004FAB9C = pakSaved[1]; D_004FABA4 = *(float*)&pakSaved[2]; pakSwapped = 0;
    }
}

/* special press: lend the game's reticle (slot 5, type 0xB, one round) and select it, so the HUD shows the
 * reticle overlay and countdown (hud.s 0x14E19C: slot 5, type 0xB, ammo > 0) and the game arms / releases /
 * times it out itself. The round it uses is charged to his special instead (tmbr_ReticleUsed); afterwards his
 * own slot-5 pickup and his previous weapon come back (tmbr_SkinsFrame). */
void tmbr_FireSpecial(void* l, char* v)
{
    int i = vidx(v);
    if (i < 0 || !isPak(v)) { fireSpecial(l, v); return; }
    if (L_ARMED(l) && !pakRet[i]) return;               /* a pickup reticle is up: leave it alone */
    if (!pakRet[i]) {
        if (pakFrames < pakCool[i]) return;              /* cooling down */
        pakOldCnt[i] = L_AMMO(l, 5); pakOldType[i] = L_S5TYPE(l); pakOldSlot[i] = L_SLOT(l);
        L_AMMO(l, 5) = 1; L_S5TYPE(l) = 0xB;
        pakRet[i] = 1; pakHold[i] = 1;
    }
    L_SLOT(l) = 5;
    pakMissileValues(1);
    fireCurrentWeapon(l, v);                             /* arm, or release when armed */
}

/* the reticle code's ammo calls (slot 5): his special pays while his own reticle is up */
void tmbr_ReticleUsed(void* w, char* v, int slot)
{
    int i = vidx(v);
    if (slot == 5 && i >= 0 && pakRet[i]) { pakRet[i] = 0; slot = 1; pakCool[i] = pakFrames + PAK_COOLDOWN; }
    weaponUsed(w, v, slot);
}

/* every game frame (freecam.c's camera hook) */
/* 12 Pak's hatches (tools/lost/pakbuild.py PAK_HATCH=2): three 3-frame switches in his body, registered by the game
 * at vehicle +0x2A20 + sub * 4 (attach type 7, subs no weapon uses). Each opens over a few frames while its weapons
 * are selected (current weapon = launcher +0 = vehicle +0x21B0) and closes again (Ark 2026-10-26: back left = fire,
 * back right = homing / power, trunk = gas can / rico). */
extern void hierSetSwitch(void* sw, int k) __asm__("hierSetSwitch__FP11_hierswitchi");
static const unsigned char HATCH_SUB[3] = { 9, 11, 12 };
static signed char hatchPos[8][3];
static void pakHatches(char* v, int car)
{
    int w = *(int*)(v + 0x21B0), h, want, *sw;
    for (h = 0; h < 3; h++) {
        sw = *(int**)(v + 0x2A20 + HATCH_SUB[h] * 4);
        if (!sw) continue;
        want = h == 0 ? w == 2 : h == 1 ? (w == 3 || w == 6) : (w == 4 || w == 7);
        want = want ? 2 * 4 : 0;                       /* position in frames: 0 closed .. 8 open (4 per step) */
        if (hatchPos[car][h] < want) hatchPos[car][h]++;
        else if (hatchPos[car][h] > want) hatchPos[car][h]--;
        hierSetSwitch(sw, hatchPos[car][h] / 4 > 2 ? 2 : hatchPos[car][h] / 4);
    }
}
void tmbr_SkinsFrame(void)
{
    int i, any = 0;
    if (!D_004FA030) return;
    pakFrames++;
    tmbr_DamageReportTick();
    for (i = 0; i < 8; i++) {
        char* v = D_004FA030 + i * 0x31B0;
        if (*(int*)(v + 0x590) && isPak(v)) pakHatches(v, i);
    }
    if (pakGame != D_004FA030) {
        pakGame = D_004FA030;
        for (i = 0; i < 8; i++) pakRet[i] = pakHold[i] = pakMountLog[i] = pakCool[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        void* l;
        if (!pakHold[i]) continue;
        l = D_004FA030 + i * 0x31B0 + 0x21B0;
        if (pakRet[i] && (L_ARMED(l) || L_SLOT(l) == 5)) { any = 1; continue; }
        if (pakRet[i]) { pakRet[i] = 0; pakCool[i] = pakFrames + PAK_COOLDOWN; weaponUsed(D_004FA030 + 0x6C310, D_004FA030 + i * 0x31B0, 1); }
        L_AMMO(l, 5) = pakOldCnt[i]; L_S5TYPE(l) = pakOldType[i];
        if (L_SLOT(l) == 5) L_SLOT(l) = pakOldSlot[i] == 5 ? 1 : pakOldSlot[i];
        pakHold[i] = 0;
    }
    pakMissileValues(any);
}

/* vehicle update's launcher update call (0x1DCD90): 12 Pak runs it under PAK_ID (see above) */
extern void launcherUpdate(void* l, char* v) __asm__("func_001549A0");
/* weapon mounts: the launcher's per-weapon launch offsets (launcher+0x630, 16 bytes each, x/y/z in the car's
 * frame, +y forward, +z up; filled per car type by func_001518A0, Roadkill's for 12 Pak). Forward-firing ones
 * are moved to 12 Pak's hood gun (centre of the hood, measured from his model); rear drops stay. */
static float PAKGUN[5] = { 0.0f, 5.2f, 1.1f, 0.5f, 0.25f };   /* gun x/y/z, min forward y, x squeeze */
/* machine guns: the two alternating muzzles are separate vectors at launcher+0x610 / +0x620 (Roadkill's:
 * x 0.92 / 1.57, y 6.94, z 1.73). 12 Pak's machine gun is the barrel along his right side (Head-On mesh 0x40710:
 * x 2.87..3.32, y 1.5..6.32, z 0.48..0.87): both muzzles at its front end */
static float PAKMG[3] = { 3.1f, 6.4f, 0.68f };
static void pakMounts(char* l, int i)
{
    int k;
    for (k = 0; k < 20; k++) {
        float* e = (float*)(l + 0x630 + 16 * k);
        if (e[1] <= PAKGUN[3]) continue;                        /* empty, or a rear / under-car launch point */
        if (!pakMountLog[i]) scePrintf("TMBR 12pak mount %d: %d %d %d (x100)\n", k, (int)(e[0] * 100), (int)(e[1] * 100), (int)(e[2] * 100));
        e[0] = PAKGUN[0] + e[0] * PAKGUN[4]; e[1] = PAKGUN[1]; e[2] = PAKGUN[2];
    }
    for (k = 0; k < 2; k++) {
        float* e = (float*)(l + 0x610 + 16 * k);
        if (!pakMountLog[i]) scePrintf("TMBR 12pak mg %d: %d %d %d (x100)\n", k, (int)(e[0] * 100), (int)(e[1] * 100), (int)(e[2] * 100));
        e[0] = PAKMG[0]; e[1] = PAKMG[1]; e[2] = PAKMG[2];
    }
    pakMountLog[i] = 1;
}

void tmbr_LauncherUpdate(void* l, char* v)
{
    if (isPak(v)) {
        int i = vidx(v);
        if (i >= 0) pakMounts((char*)l, i);
        *(int*)(v + 0x20F4) = PAK_ID;
        launcherUpdate(l, v);
        *(int*)(v + 0x20F4) = 0x20;
        return;
    }
    launcherUpdate(l, v);
}

/* kill feed (0x1E278C): only for kills of the 8 real cars (traffic kills showed "UNKNOWN KILLED BY ...") */
extern void hudKillMessage(void* hud, int victim, int killer) __asm__("func_0014E708");
extern int tmbr_KillFeedShown(int p);

void tmbr_KillMessage(void* hud, int victim, int killer)
{
    int i;
    for (i = 0; i < 8; i++) {
        char* v = D_004FA030 + i * 0x31B0;
        int o = *(int*)(v + 0x20B4);
        if (o >= 1 && o <= 5 && *(int*)(v + 0x20FC) == victim) {
            if (tmbr_KillFeedShown((int)((char*)hud - (D_004FA030 + 0x97B50)) / 0xA20))
                *(int*)((char*)hud + 0x9F4) = 0;                  /* clear the report so the kill message shows */
            hudKillMessage(hud, victim, killer);
            if ((char*)hud == D_004FA030 + 0x97B50) tmbr_TeamsKill(victim, killer);   /* team score, once */
            return;
        }
    }
}

/* waiting room (from tmbr_LobbyFrame): repeat the choice every 5 s for players who joined later */
void tmbr_SkinsLobby(void)
{
    if (++resendTick >= 300) { resendTick = 0; sendSkins(); }
}
