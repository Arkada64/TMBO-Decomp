/* TMB-Reloaded mod: the five Twisted Metal: Lost / Harbor City maps in their own level-select entries
 * (reference/wip/LOST_SLOTS.md, reference/wip/LOST_MAPS.md for the conversion).
 *
 * Design: every Lost map RUNS AS DOGPOUND (level index 10, file base DEATH4 = the conversion's donor: its weapons,
 * pickup models, effects are in the converted NGP). The shell level index (shell +0x18000 +0x23AC, game +0x9FCA0)
 * stays 10, so every per-level table and branch of the game and of the mods (music, weather, fog, sounds, AI count,
 * nav slot, packs, traffic, story) behaves exactly as on Dogpound; only the files differ. No existing level changes:
 * Dogpound itself is still entry 10, and the extra entries only show when their NGP is on the disc.
 *
 * 1. Level select (func_001CA6D8, the host's GAME SETUP level pick; D_004FA448 = highlighted level 0..20, 19
 *    skipped): "virtual positions" after WARHAWK (like skins.c's extra cars behind spot 15). Right from 20 ->
 *    Lost 1 .. Lost n -> wrap to 0; left from 0 -> Lost n .. Lost 1 -> 20. While a Lost entry is highlighted the
 *    game's own position is 10 (Dogpound's picture / LS clip) and its name is printed. Hooks: the step sound
 *    (0x1CA9E0, runs once per step before the game moves the position) and the pad read at the top of the screen's
 *    frame (0x1CA7CC). Confirm (0x1CAB20: the game has just stored the level in +0x23AC and sends the game info)
 *    records the pick.
 * 2. Sync: the host sends "\x01LM<n>" (n = 0 none, 1..5) as a chat message (like skins.c) on confirm and every
 *    5 s in the waiting room; tmbr_ChatHandler (skins.c) passes it here. Clients forget a value they have not had
 *    refreshed for ~10 s of waiting room (another host / an unmodded host).
 * 3. Files: every level file is looked up by name through func_00201910. Its calls inside the generic readers
 *    func_002006D0 (raw: RTX, PTS / PKP / PUP / HPT / PED, our \PCAR\ZNxx nav maps) and func_00200788 (zip: NGP,
 *    TEX), and the loading screen's two size lookups (0x1883C4 / 0x1883FC) go through tmbr_FileSearch: while a
 *    Lost map is active and the level is 10, these names are swapped:
 *      \LVL\DEATH4.{NGP,TEX,RTX,PTR}  -> \LVL\HC<xx>.<ext>
 *      \PTS\DEATH4.{PTS,PKP,PUP}      -> \PTS\HC<xx>.<ext>     (HPT / PED stay Dogpound's)
 *      \PCAR\ZN10.BIN                 -> \PCAR\ZNHC<xx>.BIN   (route map for the bots, navbake.c)
 *    The disc gets them from tools/lost/mklostslots.sh (NGP / TEX / ... wrapped in the game's zip container like
 *    DEATH4's own when that one is zipped).
 * 4. Waiting room "LEVEL : <name>" (0x1C5FD0, func_00189FC8) shows the Lost map's name.
 * Test builds: -DTMBR_LOSTMAP=n (build_shiftable.sh passes $TMBR_LOSTMAP) makes the host's waiting room force
 * Dogpound + Lost map n, so any quick-boot script that reaches the room as host and starts plays it. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern int sprintf(char* d, const char* f, ...);
extern int scePrintf(const char* fmt, ...);
extern int fileSearch(void* f, const char* name) __asm__("func_00201910");
extern void stepSound(void* s) __asm__("func_0019CBC0");
extern void uiPadRead(void) __asm__("func_001CE258");
extern void netSendGameInfo(void* net, int to) __asm__("func_00174988");
extern char* levelShowName(char* shell) __asm__("func_00189FC8");
extern int netIsHost(void* net) __asm__("func_001734B8");
extern void netChatSend(void* net, const char* text) __asm__("func_00171C08");
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern int tmbr_Opt(int bit);
extern char D_003156C0[];
extern char* shellPtr __asm__("D_004FA03C");
extern int levelSel __asm__("D_004FA448");   /* level select: highlighted level */
extern int D_004FA8B0;                       /* UI right flag (step direction) */

#ifndef TMBR_LOSTMAP
#define TMBR_LOSTMAP 0
#endif
#define DONOR 10                             /* DOGPOUND, files DEATH4 */
#define LASTLEVEL 20
#define OPT_STORY 0x20
#define NLOST 5
#define LEVEL() F(shellPtr + 0x18000, 0x23AC)

/* Lost's menu order */
static const char LCODE[NLOST + 1][3] = { "", "SC", "SU", "GD", "ND", "ST" };
static const char* const LNAME[NLOST + 1] = { "", "CARNIVAL OF DARKNESS", "SUBURBAN TERROR", "CITY OF THE DEAD",
    "DEATH PORT", "STADIUM SLAUGHTER" };

int tmbr_lostMap = TMBR_LOSTMAP;                 /* the game's Lost map (host: its pick; clients: the host's), 0 = none */
static int avail[NLOST + 1], availDone, al[NLOST], an;
static int pos;                   /* level select: 0 = a normal level, 1..an = al[pos - 1] highlighted */
static int resendTick, quietTick;

static void checkAvail(void)
{
    int k, f[32];
    char n[32];
    if (availDone) return;
    availDone = 1;
    an = 0;
    for (k = 1; k <= NLOST; k++) {
        sprintf(n, "%cLVL%cHC%s.NGP;1", 92, 92, LCODE[k]);     /* (backslash as a number) */
        avail[k] = fileSearch(f, n) != 0;
        if (avail[k]) { al[an++] = k; scePrintf("TMBR lost: %s available\n", LNAME[k]); }
    }
}

static int active(void)
{
    return tmbr_lostMap > 0 && tmbr_lostMap <= NLOST && shellPtr && LEVEL() == DONOR &&
           (TMBR_LOSTMAP > 0 || !tmbr_Opt(OPT_STORY));   /* (test builds: also as story level 10) */
}

static void sendLost(void)
{
    char m[8];
    if (!netIsHost(D_003156C0)) return;
    m[0] = 1; m[1] = 'L'; m[2] = 'M'; m[3] = '0' + tmbr_lostMap; m[4] = 0;
    netChatSend(D_003156C0, m);
}

/* skins.c tmbr_ChatHandler: "\x01LM<n>" from the host */
void tmbr_LostRecv(int client, const char* d)
{
    int v = d[0] - '0';
    if (netIsHost(D_003156C0) || v < 0 || v > NLOST) return;
    quietTick = 0;
    if (v != tmbr_lostMap) scePrintf("TMBR lost: host's map %d %s (from %d)\n", v, LNAME[v], client);
    tmbr_lostMap = v;
}

/* bots.c tmbr_LobbyFrame, every waiting-room frame */
void tmbr_LostLobby(void)
{
    if (!netIsHost(D_003156C0)) {
        if (tmbr_lostMap && ++quietTick > 600) { tmbr_lostMap = 0; scePrintf("TMBR lost: no word from the host, map off\n"); }
        return;
    }
#if TMBR_LOSTMAP > 0
    checkAvail();
    if (shellPtr && avail[TMBR_LOSTMAP] && (LEVEL() != DONOR || tmbr_lostMap != TMBR_LOSTMAP)) {   /* test build only */
        int k;
        LEVEL() = DONOR; levelSel = DONOR; tmbr_lostMap = TMBR_LOSTMAP;
        for (k = 0; k < an; k++) if (al[k] == TMBR_LOSTMAP) pos = k + 1;
        netSendGameInfo(D_003156C0, -1);
        sendLost();
        scePrintf("TMBR lost: test build, level forced to %s\n", LNAME[TMBR_LOSTMAP]);
    }
#endif
    if (++resendTick >= 300) { resendTick = 0; sendLost(); }
}

/* level select, once per step (0x1CA9E0: jal func_0019CBC0, $a0 = the shell sound object); the game then moves
 * D_004FA448 by +-1 (wrapping 20 <-> 0, skipping 19) */
void tmbr_LevelSelStep(void* snd)
{
    int dir = D_004FA8B0 ? 1 : -1;
    stepSound(snd);
    checkAvail();
    if (!an) return;
    if (levelSel != DONOR) pos = 0;
    if (dir > 0) {
        if (pos == 0) { if (levelSel == LASTLEVEL) { pos = 1; levelSel = DONOR - 1; } }
        else if (pos < an) { pos++; levelSel = DONOR - 1; }
        else { pos = 0; levelSel = LASTLEVEL; }                 /* -> the game wraps to 0 */
    } else {
        if (pos == 0) { if (levelSel == 0) { pos = an; levelSel = DONOR + 1; } }
        else if (pos > 1) { pos--; levelSel = DONOR + 1; }
        else { pos = 0; levelSel = LASTLEVEL + 1; }             /* -> the game steps to 20 */
    }
}

/* level select frame (0x1CA7CC: its pad read, func_001CE258) + the Lost map's name */
void tmbr_LevelSelFrame(void)
{
    uiPadRead();
    if (levelSel != DONOR) pos = 0;
    if (pos > 0 && pos <= an) {
        fontSetCursorAtSubPixel(0, 0x1400, 0x700);
        fontPrint(0, LNAME[al[pos - 1]]);
    }
}

/* level select confirm (0x1CAB20: jal func_00174988 = send the game info, after the level went into +0x23AC) */
void tmbr_LevelSelConfirm(void* net, int to)
{
    int m = shellPtr && LEVEL() == DONOR && pos > 0 && pos <= an ? al[pos - 1] : 0;
    if (m != tmbr_lostMap) scePrintf("TMBR lost: level %d, Lost map %d %s\n", shellPtr ? LEVEL() : -1, m, LNAME[m]);
    tmbr_lostMap = m;
    sendLost();
    netSendGameInfo(net, to);
}

/* waiting room "LEVEL : %s" (0x1C5FD0) */
char* tmbr_LevelShowName(char* shell)
{
    if (active()) return (char*)LNAME[tmbr_lostMap];
    return levelShowName(shell);
}

/* name swap for the level's files (see 3. above) */
static int prefix(const char* s, const char* p)
{
    while (*p) if (*s++ != *p++) return 0;
    return 1;
}
static int isExt(const char* e, const char* list)   /* list: "NGPTEXRTXPTR" (3 letters each) */
{
    for (; *list; list += 3)
        if (e[0] == list[0] && e[1] == list[1] && e[2] == list[2] && e[3] == ';') return 1;
    return 0;
}
int tmbr_FileSearch(void* f, const char* name)
{
    static char lvl[16], pts[16], zn[24], out[48];
    const char* c;
    if (!lvl[0]) {
        sprintf(lvl, "%cLVL%cDEATH4.", 92, 92);
        sprintf(pts, "%cPTS%cDEATH4.", 92, 92);
        sprintf(zn, "%cPCAR%cZN%02d.BIN;1", 92, 92, DONOR);
    }
    if (name && active()) {
        c = LCODE[tmbr_lostMap];
        out[0] = 0;
        if (prefix(name, lvl) && isExt(name + 12, "NGPTEXRTXPTR"))
            sprintf(out, "%cLVL%cHC%s.%s", 92, 92, c, name + 12);
        else if (prefix(name, pts) && isExt(name + 12, "PTSPKPPUP"))
            sprintf(out, "%cPTS%cHC%s.%s", 92, 92, c, name + 12);
        else if (prefix(name, zn))
            sprintf(out, "%cPCAR%cZNHC%s.BIN;1", 92, 92, c);
        if (out[0]) {
            int r = fileSearch(f, out);
            scePrintf("TMBR lost: %s -> %s%s\n", name + 1, out + 1, r ? "" : " (NOT ON DISC)");
            if (r || prefix(name, zn)) return r;     /* a missing route map: none (not Dogpound's); other files:
                                                      * Dogpound's own, rather than a failed load */
        }
    }
    return fileSearch(f, name);
}

/* ---- Lost map look debug (Ark 2026-10-26: the maps run with Dogpound's dark fog / lighting; is the map itself
 * broken?). On a Lost map, L3 + SELECT steps: 0 off -> 1 fog off + brighter ambient -> 2 the same + free camera
 * (freecam.c: left stick move, right stick look, R1 fast) -> 0. The level's fog / ambient volumes (func_0013D0C0
 * 0x13D574 / 0x13D594) are skipped while it is on. */
extern void fogSet(float nearz, float farz, float maxd, float f15, int r, int g, int b) __asm__("func_002023B0");
extern void viewGetAmbient(float* r, float* g, float* b) __asm__("func_00243C50");
extern void viewSetAmbient(float r, float g, float b) __asm__("viewSetAmbient__Ffff");
extern void doFogVolume(int a, void* v, void* p) __asm__("doFogVolume__FiP14_hierfogvolumeP8_fvector");
extern void doAmbientVolume(int a, void* v, void* p) __asm__("doAmbientVolume__FiP18_hierambientvolumeP8_fvector");
/* Exact collision trees (tools/lost/levels/colfix.py): too big for the level NGP's fixed slot (0x980000, 0xC7EA80
 * reserved), so the op18 roots point into \PCAR\ZCHC<xx>.BIN, read here to LOSTCOL (needs the 128 MB EE setting:
 * the address is past 32 MB). Called at level db load (packs.c tmbr_LevelDbLoaded, slot 0), before any collision
 * test. Header: 'COL1', u32 base, u32 size, u32 pad; the tree nodes follow (absolute pointers for that base). */
#define LOSTCOL 0x3000000
extern int lostFileRead(const char* name, void* dst) __asm__("func_002006D0");
void tmbr_LostColLoad(void)
{
    char n[32];
    unsigned* h = (unsigned*)LOSTCOL;
    if (!active()) return;
    sprintf(n, "%cPCAR%cZCHC%s.BIN;1", 92, 92, LCODE[tmbr_lostMap]);
    h[0] = 0;
    lostFileRead(n, (void*)LOSTCOL);
    if (h[0] != 0x314C4F43 || h[1] != LOSTCOL)          /* "COL1" */
        scePrintf("TMBR lost: %s missing or bad - this map's collision is not there (128 MB EE needed)\n", n);
    else
        scePrintf("TMBR lost: collision %s, %d KB at %08x\n", n, (int)(h[2] >> 10), LOSTCOL);
}

int tmbr_lostDbg;
static float amb0[3], dbgK[4] = { 20000.0f, 30000.0f, 0.0f, 2.5f };
static int ambSaved;
int tmbr_LostActive(void) { return active(); }
/* freecam.c, every camera update: L3 + SELECT pressed (edge) on a Lost map */
static void lostSky(void);
int tmbr_LostDebug(int toggle)
{
    if (!active()) { tmbr_lostDbg = 0; ambSaved = 0; return 0; }
    if (toggle) {
        tmbr_lostDbg = (tmbr_lostDbg + 1) % 3;
        scePrintf("TMBR lost: look debug %d\n", tmbr_lostDbg);
        if (!tmbr_lostDbg && ambSaved) { viewSetAmbient(amb0[0], amb0[1], amb0[2]); ambSaved = 0; }
    }
    if (tmbr_lostDbg) {
        if (!ambSaved) { viewGetAmbient(&amb0[0], &amb0[1], &amb0[2]); ambSaved = 1;
            scePrintf("TMBR lost: ambient was %d %d %d (x1000)\n", (int)(amb0[0] * 1000), (int)(amb0[1] * 1000), (int)(amb0[2] * 1000)); }
        fogSet(dbgK[0], dbgK[1], dbgK[2], dbgK[1], 60, 60, 60);
        viewSetAmbient(amb0[0] * dbgK[3], amb0[1] * dbgK[3], amb0[2] * dbgK[3]);
    }
    else lostSky();
    return tmbr_lostDbg;
}
/* Lost maps' sky (Ark 2026-10-27: "the black sky is a whole void thing"): they run with Dogpound's view distance,
 * which clips Head-On's sky domes (radius up to ~23500), and its black background showed instead. Far clip 30000
 * (fog pushed out with it, as the look debug's) and the background / fog in the sky's horizon colour. */
extern void viewSetBgColor(unsigned long r, unsigned long g, unsigned long b, unsigned long a) __asm__("viewSetBgColor__FUlUlUlUl");
/* horizon colours of the skies Ark picked (2026-10-27; tools/lost/levels/lvbuild.py SKY_PICK): Carnival = Junkyard's,
 * Suburban Terror = Prison's, City of the Dead = City's, Death Port = Prison's, Stadium Slaughter = Suburb's */
static const unsigned char SKYCOL[NLOST + 1][3] = { { 0, 0, 0 }, { 70, 36, 12 }, { 58, 64, 72 }, { 80, 74, 62 }, { 58, 64, 72 }, { 82, 76, 62 } };
/* LOSTCLIP: view distance. Ark 2026-10-27: far clip 30000 (g146) and 12000 (g147) both stalled the maps (the game
 * keeps running, nothing drawn but the background colour); Dogpound's own is fog 720..4370, far clip 3170. Test g148
 * split the suspects over the five maps (only Suburban Terror at 6000 stalled: the view distance is the limit, the sky
 * dome and the white meshes are fine). All maps run with the level's own now; clip per map (0 = the level's own, only the fog / background colour set),
 * and the builds differ in the sky dome / untextured (white) meshes (tools/lost/levels/lvbuild.py LV_SKY, LV_WHITE). */
static const int clipK[NLOST + 1][2] = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };   /* fog start, far clip (ints: no float literals in mod code) */
extern float D_004FAE58, D_004FAE5C, D_004FAE60, D_004FAE64;
static int skyLogged = -1;
static void lostSky(void)
{
    const unsigned char* c;
    const int* k;
    if (!active() || tmbr_lostDbg) return;
    k = clipK[tmbr_lostMap];
    if (skyLogged != tmbr_lostMap) {
        skyLogged = tmbr_lostMap;
        scePrintf("TMBR lost: level fog %d..%d far clip %d -> clip %d\n", (int)D_004FAE58, (int)D_004FAE5C,
                  (int)D_004FAE64, k[1]);
    }
    c = SKYCOL[tmbr_lostMap];
    if (k[1]) { float n = (float)k[0], f = (float)k[1]; fogSet(n, f, D_004FAE60, f, c[0], c[1], c[2]); }
    else fogSet(D_004FAE58, D_004FAE5C, D_004FAE60, D_004FAE64, c[0], c[1], c[2]);
    viewSetBgColor(c[0], c[1], c[2], 0x80);
}
void tmbr_DoFogVolume(int a, void* v, void* p) { if (!tmbr_lostDbg) doFogVolume(a, v, p); lostSky(); }
void tmbr_DoAmbientVolume(int a, void* v, void* p) { if (!tmbr_lostDbg) doAmbientVolume(a, v, p); }
