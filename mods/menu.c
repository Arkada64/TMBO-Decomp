/* TMB-Reloaded mod: main menu SINGLE PLAYER / ONLINE / OPTIONS (Ark 2026-10-26, reference/wip/STORY_PLAN.md).
 * The boot menu (UI state 6, func_001B8C10) shows three label quads from SHELL1.TEX texture 3: INTERNET, LAN,
 * OPTIONS. tools/lost/menulabels.py paints SINGLE PLAYER into that texture (over the dead ACCOUNT line); ONLINE is
 * already there (SONY ONLINE). On the main page the INTERNET / LAN quads (and their highlighted copies) get the
 * SINGLE PLAYER / ONLINE texture rectangles and widths (MENU_TAB, patched in the loaded shell NGP); ONLINE opens the
 * online page = the original INTERNET / LAN / OPTIONS; back there returns to the main page. SINGLE PLAYER goes the
 * LAN way for now (its own flow - solo / split-screen co-op straight into a story run - comes next).
 * Hook: see tmbr_MainMenu. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern int scePrintf(const char* fmt, ...);
extern void FlushCache(int);
extern char* shellPtr __asm__("D_004FA03C");
extern int D_004FA684, D_004FA688, D_004FA6E4, D_004FA910, D_004FA914, D_004FA718;   /* UI state, next, go, hold, back */
#define NGP 0x980000
#define CURSOR F(shellPtr + 0x18000, 0x1BE4 + 6 * 4)
static const unsigned MENU_CHK[][2] = {{0x45ae4, 0x009c5b80}, {0x45cb4, 0x009c5d50}, {0x46044, 0x009c60e0}, {0x46214, 0x009c62b0}};
static const unsigned MENU_TAB[][3] = {
    {0x45c10, 0xfd43f053, 0xf230f010},
    {0x45c14, 0xfbcef053, 0xf0c0f010},
    {0x45c18, 0xfd43f7e9, 0xf230fbb0},
    {0x45c1c, 0xfbcef7e9, 0xf0c0fbb0},
    {0x45ba0, 0x423d5727, 0x4084c53b},
    {0x45ba8, 0xc3838304, 0xc3821794},
    {0x45bb8, 0x43518de1, 0x437cbd81},
    {0x45bc0, 0xc388d832, 0xc38a43a2},
    {0x45b94, 0x4245bf60, 0x40c806f4},
    {0x45b9c, 0xc36763b8, 0xc3648cd7},
    {0x45bac, 0x4353a7f1, 0x437ed791},
    {0x45bb4, 0xc3720e15, 0xc374e4f6},
    {0x45de0, 0xfd43f053, 0xf230f010},
    {0x45de4, 0xfbcef053, 0xf0c0f010},
    {0x45de8, 0xfd43f7e9, 0xf230fbb0},
    {0x45dec, 0xfbcef7e9, 0xf0c0fbb0},
    {0x45d70, 0x423d5727, 0x4084c53b},
    {0x45d78, 0xc3838304, 0xc3821794},
    {0x45d88, 0x43518de1, 0x437cbd81},
    {0x45d90, 0xc388d832, 0xc38a43a2},
    {0x45d64, 0x4245bf60, 0x40c806f4},
    {0x45d6c, 0xc36763b8, 0xc3648cd7},
    {0x45d7c, 0x4353a7f1, 0x437ed791},
    {0x45d84, 0xc3720e15, 0xc374e4f6},
    {0x46170, 0xfa0ff280, 0xfee0f5d0},
    {0x46174, 0xf8c7f280, 0xfd70f5d0},
    {0x46178, 0xfa0ff5c2, 0xfee0fba0},
    {0x4617c, 0xf8c7f5c2, 0xfd70fba0},
    {0x46100, 0x42b1c3f6, 0x426fbaa1},
    {0x46108, 0xc396f121, 0xc3962e5f},
    {0x46118, 0x4322b841, 0x433fab94},
    {0x46120, 0xc398e1da, 0xc399a49c},
    {0x460f4, 0x42b38658, 0x42733f65},
    {0x460fc, 0xc389ad4f, 0xc388ea8d},
    {0x4610c, 0x43239972, 0x43408cc5},
    {0x46114, 0xc38b9e08, 0xc38c60ca},
    {0x46340, 0xfa0ff280, 0xfee0f5d0},
    {0x46344, 0xf8c7f280, 0xfd70f5d0},
    {0x46348, 0xfa0ff5c2, 0xfee0fba0},
    {0x4634c, 0xf8c7f5c2, 0xfd70fba0},
    {0x462d0, 0x42b1c3f6, 0x426fbaa1},
    {0x462d8, 0xc396f121, 0xc3962e5f},
    {0x462e8, 0x4322b841, 0x433fab94},
    {0x462f0, 0xc398e1da, 0xc399a49c},
    {0x462c4, 0x42b38658, 0x42733f65},
    {0x462cc, 0xc389ad4f, 0xc388ea8d},
    {0x462dc, 0x43239972, 0x43408cc5},
    {0x462e4, 0xc38b9e08, 0xc38c60ca},
};

int tmbr_menuPage;          /* 0 main (SINGLE PLAYER / ONLINE / OPTIONS), 1 online (INTERNET / LAN / OPTIONS) */
int tmbr_singlePlayer;      /* SINGLE PLAYER chosen (the LAN path then knows it is a solo / co-op story run) */
static int shown = -1, bad;

static void labels(int main)
{
    int i, k = main ? 2 : 1;
    if (bad) return;
    if (shown >= 0 && *(unsigned*)(NGP + MENU_TAB[0][0]) != MENU_TAB[0][shown ? 2 : 1]) shown = -1;   /* shell reloaded */
    if (shown == main) return;
    for (i = 0; i < (int)(sizeof(MENU_CHK) / sizeof(MENU_CHK[0])); i++)
        if (*(unsigned*)(NGP + MENU_CHK[i][0]) != MENU_CHK[i][1]) {   /* not the shell file we know: leave it */
            bad = 1;
            scePrintf("TMBR menu: shell mesh %x is %08x, not %08x - labels left alone\n", MENU_CHK[i][0],
                *(unsigned*)(NGP + MENU_CHK[i][0]), MENU_CHK[i][1]);
            return;
        }
    for (i = 0; i < (int)(sizeof(MENU_TAB) / sizeof(MENU_TAB[0])); i++)
        *(unsigned*)(NGP + MENU_TAB[i][0]) = MENU_TAB[i][k];
    FlushCache(0);
    shown = main;
}

/* Main menu (UI state 6, func_001B8C10: cursor shell +0x19BE4 + 6 * 4 = 3 INTERNET, 4 LAN, 5 OPTIONS; CROSS picks).
 * Hook (tools/mods/apply_mods.py): the UI loop's call of it -> tmbr_MainMenu. A CROSS on ONLINE / a TRIANGLE on the
 * online page only changes the page: that frame the menu does not run, so it never sees the press (a pad-read
 * filter was too late: test 2026-10-26 went on to the network screen). */
#define B_TRI 0x1000
#define B_CROSS 0x4000
extern void menuMain(void) __asm__("func_001B8C10");
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern void shellSfx(void* snd, int id) __asm__("playShellSFXSound__10ShellSoundi");
int tmbr_MenuPad(int b) { return b; }
/* 128 MB EE (PCSX2 "Enable 128MB RAM (Dev Console)", ini ExtraMemory): is memory past 32 MB there? (test 2026-10-26).
 * Writes a pattern at 48 MB and 120 MB (uncached kseg1) and reads it back; 32 MB machines mirror / fault there, so
 * it only runs when the kernel's memory size says more than 32 MB. */
extern int GetMemorySize(void) __asm__("GetMemorySize");
int tmbr_bigRam;
static void ramProbe(void)
{
    static int done;
    volatile unsigned* a = (volatile unsigned*)0xA3000000;   /* 48 MB */
    volatile unsigned* b = (volatile unsigned*)0xA7800000;   /* 120 MB */
    volatile unsigned* z = (volatile unsigned*)0xA1000000;   /* 16 MB (mirror check) */
    unsigned keep;
    int sz;
    if (done) return;
    done = 1;
    sz = GetMemorySize();
    scePrintf("TMBR ram: kernel memory size %x\n", sz);
    if (sz <= 0x2000000) return;
    {
        unsigned oa = *a, ob = *b, ra, rb;
        keep = *z;
        *a = 0x12345678; *b = 0x9ABCDEF0;
        ra = *a; rb = *b;
        tmbr_bigRam = ra == 0x12345678 && rb == 0x9ABCDEF0 && *z == keep;
        *a = oa; *b = ob;                                    /* (the heap may reach up there now) */
        scePrintf("TMBR ram: 48 MB %08x 120 MB %08x 16 MB %s -> extra memory %s\n", ra, rb, *z == keep ? "kept" : "CHANGED", tmbr_bigRam ? "OK" : "no");
    }
}
void tmbr_MainMenu(void)
{
    static int prev = -1, hold;
    int b = inputGetPadButtons(0) & 0xFFFF, pr = prev < 0 ? 0 : b & ~prev;
    ramProbe();
    prev = b;
    labels(tmbr_menuPage == 0);
    if (hold & b) return;                                            /* the page press: the menu waits until it is let go */
    hold = 0;
    if (tmbr_menuPage == 0 && (pr & B_CROSS) && CURSOR == 4) {      /* ONLINE: the online page */
        tmbr_menuPage = 1; CURSOR = 3; labels(0); hold = B_CROSS;
        shellSfx(shellPtr + 0x1A16C, 2);
        scePrintf("TMBR menu: online page\n");
        return;
    }
    if (tmbr_menuPage == 1 && (pr & B_TRI)) {                       /* back: the main page */
        tmbr_menuPage = 0; CURSOR = 4; labels(1); hold = B_TRI;
        scePrintf("TMBR menu: main page\n");
        return;
    }
    if (pr & B_CROSS) {
        if (tmbr_menuPage == 0 && CURSOR == 3) { tmbr_singlePlayer = 1; CURSOR = 4; }   /* SINGLE PLAYER: the LAN way for now */
        else tmbr_singlePlayer = 0;
        scePrintf("TMBR menu: page %d pick %d, single player %d\n", tmbr_menuPage, CURSOR, tmbr_singlePlayer);
    }
    menuMain();
}

/* SINGLE PLAYER (Ark 2026-10-26): the LAN host path without the network screens - in the LAN game list (UI state
 * 0x13) SQUARE (create game), on the create-game screen (0xF) CROSS (the default name), then the waiting room
 * (0x21) opens with STORY on (story.c). Split-screen co-op = controllers 2-4 press START there (guests.c).
 * Called every UI frame (guests.c tmbr_UiPadButtons); the presses go in through quickboot.c's pad read. */
#define B_SQUARE 0x8000
#ifndef TMBR_WEAPTEST
#define TMBR_WEAPTEST 0
#endif
#ifndef TMBR_STORYTEST
#define TMBR_STORYTEST 0
#endif
extern int tmbr_padInject;
void tmbr_SingleFrame(void)
{
    static int st = -1, t;
    tmbr_padInject = 0;
#if TMBR_STORYTEST
    {   /* test build only: every waiting room visit -> PLAY GAME (DOWN, CROSS); visit 2 first swaps the branch (L3) */
        static int ws = -1, wt, visits;
        if (tmbr_singlePlayer == 2) {
            if (D_004FA684 != ws) { ws = D_004FA684; wt = 0; if (ws == 0x21) visits++; scePrintf("TMBR storytest: ui %x visit %d\n", ws, visits); }
            wt++;
            if (ws == 0x21 && visits == 2 && wt >= 120 && wt < 126) tmbr_padInject = 0x2;
            if (ws == 0x21 && wt >= 200 && wt < 206) tmbr_padInject = 0x40;
            if (ws == 0x21 && wt >= 240 && wt < 246) tmbr_padInject = B_CROSS;
            return;
        }
    }
#endif
#if TMBR_WEAPTEST
    {   /* test build only: room -> SELECT CAR -> 12 Pak -> room -> PLAY GAME */
        extern int carSelPos __asm__("D_004FA7D8");
        static int ws = -1, wt, visits;
        if (tmbr_singlePlayer == 2) {
            if (D_004FA684 != ws) { ws = D_004FA684; wt = 0; if (ws == 0x21) visits++; scePrintf("TMBR weaptest: ui %x visit %d\n", ws, visits); }
            wt++;
            if (ws == 0x21 && visits == 1 && wt == 30) {      /* no story, no bots: only our car on the map */
                extern void tmbr_OptSet(int bits, int on); extern int tmbr_botCount;
                tmbr_OptSet(0x20, 0); tmbr_OptSet(2, 0); tmbr_botCount = 0;
            }
            if (ws == 0x21 && visits == 2 && wt == 30) { extern int tmbr_botCount; tmbr_botCount = 0; }
            if (ws == 0x21 && visits == 1 && wt >= 60 && wt < 66) tmbr_padInject = B_CROSS;
            if (ws == 0x27 && wt == 40) carSelPos = 15;
            if (ws == 0x27 && wt >= 70 && wt < 76) tmbr_padInject = B_CROSS;
            if (ws == 0x21 && visits == 2 && wt >= 60 && wt < 66) tmbr_padInject = 0x40;
            if (ws == 0x21 && visits == 2 && wt >= 90 && wt < 96) tmbr_padInject = B_CROSS;
            return;
        }
    }
#endif
    if (tmbr_singlePlayer != 1) { st = -1; return; }
    if (D_004FA684 != st) { st = D_004FA684; t = 0; scePrintf("TMBR single: ui %x\n", st); }
    t++;
    if (st == 0x13 && t >= 40 && t < 46) tmbr_padInject = B_SQUARE;
    if (st == 0xF && t >= 40 && t < 46) tmbr_padInject = B_CROSS;
}
