/* TMB-Reloaded mod: quick boot (scripted pad input) for unattended test runs.
 * scePadRead in the game's pad update (func_00216840, 0x216CAC) goes through tmbr_PadRead. When the script
 * block below is enabled, port 0 gets scripted buttons pressed on top of the real pad, so the menus can be
 * driven without anyone at the controller: boot -> menus -> arena -> match, then optional driving.
 * The block is in .data with a magic word; tools/qb/qbrun.py patches a copy of the ELF (QUICK.ELF) with a
 * script, so changing the map or path needs no rebuild. Disabled (all zero) it does nothing.
 * Script: up to QB_STEPS steps {u16 buttons, u16 frames}: hold `buttons` for `frames` pad reads (one per
 * frame), buttons 0 = wait. A press step is normally followed by a short release step so menus see an edge.
 * Buttons as the game's raw mask (active high here): Select 0x1, L3 0x2, R3 0x4, Start 0x8, Up 0x10,
 * Right 0x20, Down 0x40, Left 0x80, L2 0x100, R2 0x200, L1 0x400, R1 0x800, Triangle 0x1000,
 * Circle 0x2000, Cross 0x4000, Square 0x8000. Each step start is logged: "TMBR qb: step N ..." */
#define QB_STEPS 120
extern int scePrintf(const char* fmt, ...);
extern int scePadRead(int port, int slot, unsigned char* data);

typedef struct {
    unsigned int magic;        /* 'TMQB' */
    unsigned int enabled;
    unsigned int nsteps;
    unsigned int loop_from;    /* after the last step, continue from this step (driving loop); >= nsteps: stop */
    unsigned short step[QB_STEPS][2];
} QbScript;

QbScript tmbr_qb = { 0x42514D54, 0, 0, 0xFFFF, { { 0, 0 } } };

static int qbStep = -1, qbLeft;
static unsigned int qbFrame;

int tmbr_PadRead(int port, int slot, unsigned char* data)
{
    int r = scePadRead(port, slot, data);
    unsigned int b, target;
    if (!tmbr_qb.enabled || port != 0) return r;
    if (slot == 0) {                       /* controller 1's read: once a frame, advances the script */
        qbFrame++;
        while (qbLeft <= 0) {
            qbStep++;
            if (qbStep >= (int)tmbr_qb.nsteps) {
                if (tmbr_qb.loop_from < tmbr_qb.nsteps) qbStep = tmbr_qb.loop_from;
                else { qbStep = tmbr_qb.nsteps; qbLeft = 0x7FFFFFFF; break; }
            }
            qbLeft = tmbr_qb.step[qbStep][1] & 0x3FFF;
            if (tmbr_qb.step[qbStep][0])
                scePrintf("TMBR qb: step %d buttons %04x for %d (frame %d)\n", qbStep, tmbr_qb.step[qbStep][0], tmbr_qb.step[qbStep][1], qbFrame);
        }
        qbLeft--;
    }
    if (qbStep < 0 || qbStep >= (int)tmbr_qb.nsteps) return r;
    /* frames bits 14-15: which controller gets the buttons (0 = 1, 1..3 = multitap 1B..1D = controllers 2..4,
     * for the split-screen guest tests) */
    target = tmbr_qb.step[qbStep][1] >> 14;
    if ((int)target != slot) return r;
    b = tmbr_qb.step[qbStep][0];
    if (r && data[0] == 0 && b) {          /* status ok: buttons are active low in bytes 2-3 */
        data[2] &= ~(b & 0xFF);
        data[3] &= ~(b >> 8);
    }
    return r;
}
