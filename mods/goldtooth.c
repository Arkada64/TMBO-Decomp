/* Gold Tooth (Twisted Metal: Lost) as an alternate Sweet Tooth.
 *
 * In the waiting room, L1 + SQUARE toggles it (local to this console; other players see their own choice).
 * On: the vehicle file code table's Sweet Tooth entry (D_003F6A00[6] = "st" -> \PCAR\STP.NGP/PTR/TEX/RTX,
 * formatFilename uppercases it) becomes "zz" -> \PCAR\ZZP.* (Gold Tooth: Sweet Tooth's model with the
 * retextured gold sheets, tools/lost/gtretex.py; on the test disc), and Sweet Tooth's name strings read
 * Gold Tooth. Off restores both. The table is read when the match loads its cars, so the choice made in the
 * waiting room applies to the next match. */

extern char vehCodes[] __asm__("D_003F6A00");          /* 8 bytes per vehicle type: "rk", "tx", .. "st" (6) */
extern char nmSelect[] __asm__("D_004EA890");          /* "SWEETTOOTH" */
extern char nmShort[] __asm__("D_004E2870");           /* "Sweet To" */
extern char nmDestroyed[] __asm__("D_004E3480");       /* "SWEETTOOTH DESTROYED" */
extern char nmKilled[] __asm__("D_004E4260");          /* "YOU KILLED SWEET TOOTH!" + spaces */
extern char nmKilledBy[] __asm__("D_004E4590");        /* "KILLED BY  SWEET TOOTH!" + spaces */

extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern void scePrintf(const char* f, ...);

#define GT_TYPE 6
#define PAD_L1 0x400
#define PAD_SQUARE 0x8000

int tmbr_goldTooth;

typedef struct {
    char* p;
    const char* gold;
    char orig[48];
    int len;
} GtName;

static GtName names[5];
static int gtInit, gtPrev;

static void addName(int i, char* p, const char* gold)
{
    int n = 0;
    while (p[n] && n < 47) { names[i].orig[n] = p[n]; n++; }
    names[i].orig[n] = 0;
    names[i].p = p; names[i].gold = gold; names[i].len = n;
}

static void apply(int on)
{
    int i, k;
    vehCodes[GT_TYPE * 8 + 0] = on ? 'z' : 's';
    vehCodes[GT_TYPE * 8 + 1] = on ? 'z' : 't';
    for (i = 0; i < 5; i++) {
        GtName* g = &names[i];
        const char* s = on ? g->gold : g->orig;
        char fill = (g->len && g->orig[g->len - 1] == ' ') ? ' ' : 0;   /* padded messages stay padded */
        for (k = 0; k < g->len && s[k]; k++) g->p[k] = s[k];
        for (; k < g->len; k++) g->p[k] = fill;
    }
}

/* called every waiting-room frame from tmbr_LobbyFrame (bots.c), for every player */
void tmbr_GoldToothLobby(void)
{
    int pad, pressed;
    if (!gtInit) {
        gtInit = 1;
        addName(0, nmSelect, "GOLDTOOTH");
        addName(1, nmShort, "Gold Too");
        addName(2, nmDestroyed, "GOLDTOOTH DESTROYED");
        addName(3, nmKilled, "YOU KILLED GOLD TOOTH!");
        addName(4, nmKilledBy, "KILLED BY  GOLD TOOTH!");
    }
    pad = inputGetPadButtons(0) & (PAD_L1 | PAD_SQUARE);
    pressed = pad & ~gtPrev;
    gtPrev = pad;
    if ((pad & PAD_L1) && (pressed & PAD_SQUARE)) {
        tmbr_goldTooth = !tmbr_goldTooth;
        apply(tmbr_goldTooth);
        scePrintf("TMBR goldtooth: %s\n", tmbr_goldTooth ? "on (\\PCAR\\ZZP.*)" : "off");
    }
    fontSetCursorAtSubPixel(0, 0x1810, 0xFA0 + 11 * 0x100);
    fontPrint(0, tmbr_goldTooth ? "SWEET TOOTH -> GOLD TOOTH  (L1 + SQUARE)" : "SWEET TOOTH  (L1 + SQUARE: GOLD TOOTH)");
}
