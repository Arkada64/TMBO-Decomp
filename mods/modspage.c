/* TMB-Reloaded mod: MINION and HEALTH on the game's own GAME MODS page (Ark 2026-10-26, TODO 6f; both off by default).
 * The page is UI state 0x25 (func_001CAC18): five rows SINGLE WEAPON / SINGLE VEHICLE / HUD DISPLAY / POWER RELICS /
 * UNLIMITED WEAPONS, font text at x 0x370, y 0x640 + row * 0x200, cursor shell +0x19BE4 + 0x25 * 4 = row + 1
 * (highlight colour 0x74 0x5A 0x2C, others 0x44 0x32 0x20). Its input comes from the UI's direction / select flags
 * (test 2026-10-26: D_004FA8B4 up, 8B8 down, 8AC left, 8B0 right, 8C8 cross). Hook (apply_mods.py): the UI
 * loop's call of func_001CAC18 -> tmbr_ModsPage. Two more rows follow the native five; while one of ours is
 * selected the native cursor is 0 (no native row lit) and the flags are taken before the page sees them. The values
 * are the lobby options in the game info (bots.c tmbr_OptSet: MINION = bit 8 on, HEALTH = bit 16 on). */
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
#define NROW 2
static const char* const LABEL[NROW] = { "           MINION: %s", "           HEALTH: %s" };
static const int BIT[NROW] = { 8, 16 };

void tmbr_ModsPage(void)
{
    static int v, lastField, logged;
    int t = timerGetFieldCount(), up = D_004FA8B4, dn = D_004FA8B8, lt = D_004FA8AC, rt = D_004FA8B0, ok = D_004FA8C8, i;
    if (t - lastField > 4) v = 0;                              /* page (re)opened */
    lastField = t;
    if ((up | dn | lt | rt | ok) && logged < 12) {
        logged++;
        scePrintf("TMBR modspage: up %d down %d left %d right %d ok %d cursor %d ours %d\n", up, dn, lt, rt, ok, CUR, v);
    }
    if (v) {
        if (up) { if (v == 2) v = 1; else { v = 0; CUR = 5; } }
        else if (dn) { if (v == 1) v = 2; else { v = 0; CUR = 1; } }        /* (the native list wraps too) */
        else if ((lt || rt || ok) && netIsHost(D_003156C0)) {
            tmbr_OptSet(BIT[v - 1], !tmbr_Opt(BIT[v - 1]));
            scePrintf("TMBR modspage: %s %s\n", v == 1 ? "minion" : "health", tmbr_Opt(BIT[v - 1]) ? "on" : "off");
        }
        if (up || dn || lt || rt || ok) shellSfx(shellPtr + 0x1A16C, 2);
        D_004FA8AC = D_004FA8B0 = D_004FA8B4 = D_004FA8B8 = D_004FA8C8 = 0;
        if (v) CUR = 0;
    } else if (CUR == 5 && dn) {
        v = 1; CUR = 0; D_004FA8B8 = 0;
        shellSfx(shellPtr + 0x1A16C, 2);
    } else if (CUR == 1 && up) {
        v = NROW; CUR = 0; D_004FA8B4 = 0;
        shellSfx(shellPtr + 0x1A16C, 2);
    }
    modsMain();
    for (i = 0; i < NROW; i++) {
        char b[48];
        if (v == i + 1) fontSetColor(0, 0x74, 0x5A, 0x2C); else fontSetColor(0, 0x44, 0x32, 0x20);
        fontSetCursorAtSubPixel(0, 0x370, 0x640 + (5 + i) * 0x200);
        sprintf(b, LABEL[i], tmbr_Opt(BIT[i]) ? "YES" : "NO");
        fontPrint(0, b);
    }
}
