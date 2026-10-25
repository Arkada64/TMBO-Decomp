/* Retail TMB (SCUS_971.01) test harness: scripted buttons on up to 4 controllers + frame load, for unattended
 * split-screen stress tests (tools/qb/retail/README.md). Linked at 0x760000 (after retail's memory) by rbuild.sh and
 * put in as an extra load segment by rpatch.py; hooks: the pad read in inputUpdateState (0x1D7810) and the game
 * loop's frame wait in rtMain (0x15B518).
 * Script (tmbr_rq, written by rpatch.py): steps of {frames, buttons per player}; key[p] = port * 4 + slot of player p
 * (multitap on port 1: slots 0..3 = keys 0..3). Buttons as the game's raw mask (active high: Select 0x1, L3 0x2,
 * R3 0x4, Start 0x8, Up 0x10, Right 0x20, Down 0x40, Left 0x80, L2 0x100, R2 0x200, L1 0x400, R1 0x800,
 * Triangle 0x1000, Circle 0x2000, Cross 0x4000, Square 0x8000).
 * Load: see frameTick (EE cycle counter, 294.912 MHz: 4,915,200 cycles = one 60 Hz frame). */
#define RQ_STEPS 150
typedef struct { unsigned short frames, pad_, btn[4]; } RStep;
typedef struct { unsigned int magic, nsteps, loop_from; unsigned char key[4]; RStep step[RQ_STEPS]; } RScript;
RScript tmbr_rq = { 0x52514D54, 0, 0xFFFF, { 0, 1, 2, 3 }, { { 0 } } };

extern int scePadRead(int port, int slot, unsigned char* data);
extern void scePrintf(const char* f, ...);
extern void timerWait(unsigned int* p) __asm__("timerWaitForMinUpdateRate__FPUi");
extern int viewNumViews;

static int st, left = -1;
static char FMT_STEP[] = "TMBR rqb: step %d for %d\n";
static char FMT_PERF[] = "TMBR rperf: frame avg %d us max %d us | busy avg %d%% max %d%% | slow %d/300 | views %d\n";

static unsigned int count(void)
{
    unsigned int c;
    __asm__ volatile ("mfc0 %0, $9" : "=r" (c));
    return c;
}

int tmbr_rPadRead(int port, int slot, unsigned char* d)
{
    int r = scePadRead(port, slot, d), p, key = port * 4 + slot, b;
    if (key == tmbr_rq.key[0]) {                       /* player 1's read: once a frame - advance the script */
        frameTick();
        if (left < 0) { st = 0; left = tmbr_rq.nsteps ? tmbr_rq.step[0].frames : 0; }
        else if (--left <= 0 && st < (int)tmbr_rq.nsteps) {
            st++;
            if (st >= (int)tmbr_rq.nsteps && tmbr_rq.loop_from < tmbr_rq.nsteps) st = tmbr_rq.loop_from;
            if (st < (int)tmbr_rq.nsteps) {
                left = tmbr_rq.step[st].frames;
                if (tmbr_rq.step[st].btn[0] | tmbr_rq.step[st].btn[1] | tmbr_rq.step[st].btn[2] | tmbr_rq.step[st].btn[3])
                    scePrintf(FMT_STEP, st, left);
            }
        }
    }
    if (!r || d[0] != 0 || st >= (int)tmbr_rq.nsteps) return r;
    for (p = 0; p < 4; p++) {
        if (tmbr_rq.key[p] != key) continue;
        b = tmbr_rq.step[st].btn[p];
        d[2] &= ~(b & 0xFF);                          /* buttons are active low in bytes 2-3 */
        d[3] &= ~(b >> 8);
    }
    return r;
}

/* frame load: frame time = player 1's pad read to the next one (once a frame); wait = time spent in sceGsSyncV
 * (all its call sites go through tmbr_rSyncV); busy = frame - wait. Every 300 frames:
 * "TMBR rperf: frame avg F us max M us | busy avg B% max X% | slow S/300 | views V" (slow: frame > 1.5 x 16.7 ms) */
extern int sceGsSyncV(int mode);
static unsigned int waitAcc, lastRead, fSumK, fMax, bSumK, bMax, fn, fSlow;
int tmbr_rSyncV(int mode)
{
    unsigned int t = count();
    int r = sceGsSyncV(mode);
    waitAcc += count() - t;
    return r;
}
static void frameTick(void)
{
    unsigned int c = count(), f = c - lastRead, b = f > waitAcc ? f - waitAcc : 0;
    waitAcc = 0;
    if (lastRead && f < 60000000) {
        fSumK += f / 1000; bSumK += b / 1000;
        if (f > fMax) fMax = f;
        if (b > bMax) bMax = b;
        if (f > 7372800) fSlow++;
        if (++fn == 300) {
            scePrintf(FMT_PERF, (int)(fSumK / fn * 1000 / 295), (int)(fMax / 295), (int)(bSumK / fn * 100 / 4915),
                      (int)(bMax / 1000 * 100 / 4915), (int)fSlow, viewNumViews);
            fn = 0; fSumK = 0; bSumK = 0; fMax = 0; bMax = 0; fSlow = 0;
        }
    }
    lastRead = c;
}
