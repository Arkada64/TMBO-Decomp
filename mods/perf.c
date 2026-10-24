/* TMB-Reloaded mod: per-frame cost of the mods, logged every 5 s (TMBR_PERF).
 * Timing uses the EE cycle counter (COP0 Count, 294.912 MHz: 295 cycles = 1 us). A 60 fps frame is
 * 16667 us. Each mod adds its cycles to a slot (tmbr_PerfAdd), tmbr_PerfFrame (once per frame, from the
 * camera update hook) closes the frame. Log line (emulog):
 *   TMBR perf: frame avg A us max M | slow S/300 (frames that took 2+ fields) | <slot> avg/max us ...
 * Slots: think = bots.c target choice + nav planner, ai = the game's own AI frame for all bots,
 * drive = our per-bot driving (combat steering + nav follow), traffic = traffic.c update (all of it),
 * route = baked-map route planning (navbake.c, part of think), tphys = traffic physics only (part of traffic). */
#define TMBR_PERF 1
#define NSLOT 6
#define WINDOW 300
extern int scePrintf(const char* fmt, ...);
extern int fieldsLastFrame(void) __asm__("timerGetFieldsLastFrame__Fv");

static unsigned int acc[NSLOT], sum[NSLOT], peak[NSLOT];
static unsigned int last, fsum, fpeak;
static int frames, slow;
static const char* names[NSLOT] = { "think", "ai", "drive", "traffic", "route", "tphys" };

unsigned int tmbr_Cycles(void)
{
    unsigned int c;
    __asm__ __volatile__("mfc0 %0, $9" : "=r"(c));
    return c;
}

void tmbr_PerfAdd(int slot, unsigned int start)
{
    if (TMBR_PERF && slot >= 0 && slot < NSLOT) acc[slot] += tmbr_Cycles() - start;
}

void tmbr_PerfFrame(void)
{
    unsigned int now, dt;
    int i;
    if (!TMBR_PERF) return;
    now = tmbr_Cycles();
    dt = now - last;
    last = now;
    if (dt > 295 * 200000) dt = 0;      /* first frame / after a pause */
    fsum += dt;
    if (dt > fpeak) fpeak = dt;
    if (fieldsLastFrame() > 1) slow++;
    for (i = 0; i < NSLOT; i++) {
        sum[i] += acc[i];
        if (acc[i] > peak[i]) peak[i] = acc[i];
        acc[i] = 0;
    }
    if (++frames < WINDOW) return;
    scePrintf("TMBR perf: frame avg %d us max %d | slow %d/%d | %s %d/%d %s %d/%d %s %d/%d %s %d/%d %s %d/%d %s %d/%d us\n",
        fsum / WINDOW / 295, fpeak / 295, slow, WINDOW,
        names[0], sum[0] / WINDOW / 295, peak[0] / 295, names[1], sum[1] / WINDOW / 295, peak[1] / 295,
        names[2], sum[2] / WINDOW / 295, peak[2] / 295, names[3], sum[3] / WINDOW / 295, peak[3] / 295,
        names[4], sum[4] / WINDOW / 295, peak[4] / 295, names[5], sum[5] / WINDOW / 295, peak[5] / 295);
    for (i = 0; i < NSLOT; i++) { sum[i] = 0; peak[i] = 0; }
    fsum = fpeak = 0;
    frames = slow = 0;
}
