/* TMB-Reloaded mod: MINION and HEALTH on the game's own GAME MODS page (Ark 2026-10-26, TODO 6f; both off by default).
 * The page is UI state 0x25 (func_001CAC18): five rows SINGLE WEAPON / SINGLE VEHICLE / HUD DISPLAY / POWER RELICS /
 * UNLIMITED WEAPONS, font text at x 0x370, y 0x640 + row * 0x200, cursor shell +0x19BE4 + 0x25 * 4 = row + 1
 * (highlight colour 0x74 0x5A 0x2C, others 0x44 0x32 0x20). Its input comes from the UI's direction / select flags
 * (D_004FA8B4 up, 8B8 down, 8AC left, 8B0 right, 8C8 cross - set by the UI input read, which runs before the page function). Hook (apply_mods.py): the UI
 * loop's call of func_001CAC18 -> tmbr_ModsPage. Two more rows follow the native five; while one of ours is
 * selected the native cursor is 0 (no native row lit) and the presses are hidden from the page's input read. The values
 * are the lobby options in the game info (bots.c tmbr_OptSet: MINION = bit 8 on, HEALTH = bit 16 on, ALLY BOT = 0x40). */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern void modsMain(void) __asm__("func_001CAC18");
extern int scePrintf(const char* fmt, ...);
extern int sprintf(char* d, const char* f, ...);
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern void fontSetColor(int font, int r, int g, int b) __asm__("fontSetColor__Fiiii");
extern void shellSfx(void* snd, int id) __asm__("playShellSFXSound__10ShellSoundi");
extern int timerGetFieldCount(void) __asm__("timerGetFieldCount__Fv");
extern int netIsHost(void* net) __asm__("func_001734B8");
extern int tmbr_Opt(int bit);
extern void tmbr_OptSet(int bits, int on);
extern char* shellPtr __asm__("D_004FA03C");
extern char D_003156C0[];
extern int D_004FA8AC, D_004FA8B0, D_004FA8B4, D_004FA8B8, D_004FA8C8;
#define CUR F(shellPtr + 0x18000, 0x1BE4 + 0x25 * 4)
#define NROW 3
static const char* const LABEL[NROW] = { "           MINION: %s", "           HEALTH: %s", "         ALLY BOT: %s" };
static const int BIT[NROW] = { 8, 16, 0x40 };   /* ALLY BOT (teams.c): a bot on the humans' team when it is humans vs bots */

extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
int tmbr_uiEat;           /* (unused now: guests.c tmbr_UiPadButtons still masks with it) */
#define B_UP 0x10
#define B_RIGHT 0x20
#define B_DOWN 0x40
#define B_LEFT 0x80
#define B_CROSS 0x4000
/* The page reads its input itself (func_001CE258 at 0x1CB004 -> flags from inputGetInput, not from the pad read
 * guests.c hooks), so that call is wrapped (apply_mods.py): while one of our rows is selected, or this frame's
 * press moved onto / off one, the flags are cleared (test g93/g94: a RIGHT with the game cursor at 0 went to the
 * game's row -1, a null pointer). */
extern void uiReadInput(void) __asm__("func_001CE258");
static int eatFlags;
void tmbr_ModsInput(void)
{
    uiReadInput();
    if (eatFlags) D_004FA8AC = D_004FA8B0 = D_004FA8B4 = D_004FA8B8 = D_004FA8C8 = 0;
}

void tmbr_ModsPage(void)
{
    static int v, lastField, prev;
    int t = timerGetFieldCount(), b = inputGetPadButtons(0) & 0xFFFF, pr = b & ~prev, i, ate = 0;
    prev = b;
    if (t - lastField > 4) { v = 0; pr = 0; }                       /* page (re)opened */
    lastField = t;
    if (!v && CUR == 5 && (pr & B_DOWN)) { v = 1; ate = 1; }
    else if (!v && CUR == 1 && (pr & B_UP)) { v = NROW; ate = 1; }
    else if (v) {
        ate = 1;
        if (pr & B_UP) { if (v > 1) v--; else { v = 0; CUR = 5; } }
        else if (pr & B_DOWN) { if (v < NROW) v++; else { v = 0; CUR = 1; } }
        else if ((pr & (B_LEFT | B_RIGHT | B_CROSS)) && netIsHost(D_003156C0)) {
            tmbr_OptSet(BIT[v - 1], !tmbr_Opt(BIT[v - 1]));
            scePrintf("TMBR modspage: row %d bit %x %s\n", v, BIT[v - 1], tmbr_Opt(BIT[v - 1]) ? "on" : "off");
        }
        if (pr & (B_UP | B_DOWN | B_LEFT | B_RIGHT | B_CROSS)) shellSfx(shellPtr + 0x1A16C, 2);
    }
    eatFlags = ate;                                     /* (TRIANGLE still leaves the page) */
    if (v) CUR = 0;
    modsMain();
    eatFlags = 0;
    if (v) CUR = 0;
    for (i = 0; i < NROW; i++) {
        char t2[48];
        if (v == i + 1) fontSetColor(0, 0x74, 0x5A, 0x2C); else fontSetColor(0, 0x44, 0x32, 0x20);
        fontSetCursorAtSubPixel(0, 0x370, 0x640 + (5 + i) * 0x200);
        sprintf(t2, LABEL[i], tmbr_Opt(BIT[i]) ? "YES" : "NO");
        fontPrint(0, t2);
    }
}
