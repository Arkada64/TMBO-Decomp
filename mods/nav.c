/* TMB-Reloaded mod: bot navigation fallback (navmesh v1, host only, with a chosen bot count).
 *
 * Bots route with the level's attractor graph (driver.c: AttractorPoints groups). On many online maps that
 * graph is thin or wrong, and a bot without line of sight to its target circles or parks. This module plans
 * its own route on the level's real collision instead of the graph:
 *  - a G x G grid laid over the bot and its target (cell 14..40 units), explored lazily with A*;
 *  - a cell is probed only when A* reaches it: one ray down for the ground (hdLosTest, the game's own LOS /
 *    collision ray, terrain + hierarchy), one ray at bumper height from the neighbour (blocked unless the
 *    surface hit is a drivable slope, tireIsDrivableSlope, same test the driver code uses). Ground is followed
 *    from the neighbour's height, so bridges / ramps / under-passes are not flattened into one layer;
 *  - the planner runs for one bot at a time, NAV_RAYS rays per frame, and gives the best partial path when
 *    the target is out of the grid or out of budget (the bot replans when it gets there);
 *  - while a bot follows a path, its driving pads (gas, brake, steer, handbrake) are replaced after its AI
 *    frame; weapons stay with the AI. It hands back as soon as the bot sees its target.
 * When it kicks in: the bot hunts a target, has not seen it for a second, and either the target's group is
 * unreachable in the attractor graph (driver+0x270) or the bot has not closed in for 4 s. Elsewhere the
 * original driving is untouched. NAV_ALWAYS 1 uses it whenever the target is out of sight.
 * Floats: constants live in K[] (no compiler literal pool: the assembler would put it in gp-relative .lit4). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) fvec;
#define F(p, off) (*(int*)((char*)(p) + (off)))
#define FL(p, off) (*(float*)((char*)(p) + (off)))
#define CS(v) ((char*)F(v, 0x2028))
#define POSV(v) ((fvec*)(CS(v) + 0x10))
#define PAD(v) ((unsigned char*)(v) + 0x594)
#define NAV_RAYS 12      /* collision rays per frame for planning (all bots together) */
#define NAV_EXP 700      /* A* expansions per plan */
#define NAV_ALWAYS 0
#define NAVDBG 0         /* one log line per plan (emulog) */
#define G 40
#define NC (G * G)
#define MAXWP 40

extern char* D_004FA030;
extern int scePrintf(const char* fmt, ...);
extern int tmbr_botCount;
extern signed char hdLos(fvec* a, fvec* b, void* res, int flags) __asm__("hdLosTest__FP8_fvectorT0P9_hdResulti");
extern int drivableSlope(char* v, fvec* n) __asm__("tireIsDrivableSlope__7VehicleP8_fvector");
extern void rotFromVec(fvec* out, fvec* v) __asm__("mathfRotationFromVector__FP8_fvectorT0");
extern void boundAngle(float* a) __asm__("boundFAngle__FPf");

/* 0 zero, 1 ray height, 2 min cell, 3 max cell, 4 arrive (cells), 5 steer dead zone, 6 handbrake angle,
 * 7 waypoint height, 8 half, 9 steep (cells), 10 probe down (cells) */
static float K[12] = { 0.0f, 3.0f, 14.0f, 40.0f, 0.8f, 0.12f, 1.6f, 2.0f, 0.5f, 0.7f, 2.0f, 0.0f };

typedef struct {
    int st;          /* 0 idle, 1 waiting for the planner, 2 following */
    int n, i;        /* waypoints, current */
    int timer, cool, tick, lastD, noProg;
    char* tgt;
    fvec wp[MAXWP];
} NavBot;
static NavBot nb[8];  /* by vehicle index */

/* planner (one plan at a time) */
static float cz[NC];
static unsigned char cst[NC];   /* 0 unknown, 1 ground, 2 no ground */
static unsigned char cfl[NC];   /* 1 open, 2 closed */
static short par[NC];
static int gco[NC], fco[NC];
static short heap[NC];
static int hn;
static struct {
    int on, vi, exp, nb8, expansions, best, bestH, rays, start, gx, gy;
    float ox, oy, cell;
    char* v;
} P;
static fvec ra, rb, dv, rot;
static char res[64] __attribute__((aligned(16)));
static int rr;

static int iabs(int a) { return a < 0 ? -a : a; }
static float fabs_(float a) { return a < K[0] ? -a : a; }
static int hcost(int c)
{
    int dx = iabs(c % G - P.gx), dy = iabs(c / G - P.gy);
    return 10 * (dx + dy) - 6 * (dx < dy ? dx : dy);
}
static void hpush(int c)
{
    int i = hn++, p;
    while (i > 0 && fco[heap[p = (i - 1) / 2]] > fco[c]) { heap[i] = heap[p]; i = p; }
    heap[i] = c;
}
static void hfix(int c)   /* decrease key */
{
    int i, p;
    for (i = 0; i < hn && heap[i] != c; i++) ;
    if (i == hn) { hpush(c); return; }
    while (i > 0 && fco[heap[p = (i - 1) / 2]] > fco[c]) { heap[i] = heap[p]; i = p; }
    heap[i] = c;
}
static int hpop(void)
{
    int top = heap[0], last, i = 0, k;
    last = heap[--hn];
    while ((k = 2 * i + 1) < hn) {
        if (k + 1 < hn && fco[heap[k + 1]] < fco[heap[k]]) k++;
        if (fco[heap[k]] >= fco[last]) break;
        heap[i] = heap[k]; i = k;
    }
    heap[i] = last;
    return top;
}
static float cx(int c) { return P.ox + ((float)(c % G) + K[8]) * P.cell; }
static float cy(int c) { return P.oy + ((float)(c / G) + K[8]) * P.cell; }

static int vidx(char* g, char* v) { int i = (int)(v - g) / 0x31B0; return (i >= 0 && i < 8) ? i : -1; }
static int live(char* v) { return v && (F(v, 0x590) == 1 || F(v, 0x590) == 2) && F(v, 0x2028); }

static void planStart(char* g, char* v, char* t)
{
    fvec *a = POSV(v), *b = POSV(t);
    float dx = b->x - a->x, dy = b->y - a->y, ad = fabs_(dx) > fabs_(dy) ? fabs_(dx) : fabs_(dy);
    float cell = ad / (float)(G - 8), half, mx, my, lim;
    int i, sx, sy, tx, ty;
    if (cell < K[2]) cell = K[2];
    if (cell > K[3]) cell = K[3];
    half = (float)(G / 2) * cell;
    lim = (float)(G / 2 - 3) * cell;  /* grid centre: midway, but keep the bot well inside */
    mx = dx * K[8]; my = dy * K[8];
    if (mx > lim) mx = lim; if (mx < -lim) mx = -lim;
    if (my > lim) my = lim; if (my < -lim) my = -lim;
    P.ox = a->x + mx - half; P.oy = a->y + my - half; P.cell = cell;
    for (i = 0; i < NC; i++) { cst[i] = 0; cfl[i] = 0; par[i] = -1; }
    hn = 0;
    sx = (int)((a->x - P.ox) / cell); sy = (int)((a->y - P.oy) / cell);
    tx = (int)((b->x - P.ox) / cell); ty = (int)((b->y - P.oy) / cell);   /* may be outside the grid */
    if (b->x < P.ox) tx--; if (b->y < P.oy) ty--;
    P.gx = tx; P.gy = ty;
    P.start = sy * G + sx;
    cst[P.start] = 1; cz[P.start] = a->z;
    gco[P.start] = 0; fco[P.start] = hcost(P.start); cfl[P.start] = 1;
    hpush(P.start);
    P.best = P.start; P.bestH = fco[P.start];
    P.exp = -1; P.expansions = 0; P.rays = 0; P.v = v; P.vi = vidx(g, v); P.on = 1;
}

/* walkable edge c -> n (probes n's ground first). Costs 1-2 rays. */
static int edge(int c, int n, int* rays)
{
    float pz = cz[c];
    if (!cst[n]) {
        ra.x = rb.x = cx(n); ra.y = rb.y = cy(n);
        ra.z = pz + P.cell; rb.z = pz - P.cell * K[10];
        (*rays)++;
        if (hdLos(&ra, &rb, res, 0)) cst[n] = 2;
        else if (!drivableSlope(P.v, (fvec*)(res + 0x10))) cst[n] = 2;   /* ground too steep to drive (hills) */
        else { cst[n] = 1; cz[n] = ((fvec*)res)->z; }
    }
    if (cst[n] != 1) return 0;
    if (fabs_(cz[n] - pz) > P.cell * K[9]) return 0;   /* too steep / another floor */
    ra.x = cx(c); ra.y = cy(c); ra.z = pz + K[1];
    rb.x = cx(n); rb.y = cy(n); rb.z = cz[n] + K[1];
    (*rays)++;
    if (hdLos(&ra, &rb, res, 0)) return 1;
    return drivableSlope(P.v, (fvec*)(res + 0x10)) != 0;
}

static void planFinish(int c)
{
    static short tmp[NC];
    NavBot* b = &nb[P.vi];
    int n = 0, k, dir = 99, d;
    P.on = 0;
    while (c >= 0 && n < NC) { tmp[n++] = c; c = par[c]; }
    /* tmp[n-1] is the start: walk from the start, keep the cells where the direction changes */
    b->n = 0;
    for (k = n - 2; k >= 0 && b->n < MAXWP; k--) {
        d = tmp[k] - tmp[k + 1];
        if (k > 0 && tmp[k - 1] - tmp[k] == d && d == dir) continue;
        dir = d;
        b->wp[b->n].x = cx(tmp[k]); b->wp[b->n].y = cy(tmp[k]); b->wp[b->n].z = cz[tmp[k]] + K[7];
        b->n++;
    }
    b->i = 0; b->timer = 0;
    b->st = b->n > 0 ? 2 : 0;
    if (!b->n) b->cool = 300;
    if (NAVDBG)
        scePrintf("TMBR nav: car %d exp %d rays %d path %d cells -> %d pts, cell %d, %s\n", P.vi, P.expansions,
                  P.rays, n - 1, b->n, (int)P.cell, P.best == P.start ? "no route" : (hcost(P.best) ? "partial" : "to target"));
}

static void planStep(void)
{
    static const signed char ddx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, ddy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
    int budget = 0, c, x, y, n, ng, h;
    if (!live(P.v)) { P.on = 0; nb[P.vi].st = 0; return; }
    while (budget < NAV_RAYS) {
        if (P.exp < 0) {
            if (!hn || P.expansions >= NAV_EXP) { planFinish(P.best); return; }
            c = hpop();
            if (cfl[c] == 2) continue;
            cfl[c] = 2;
            h = hcost(c);
            if (h < P.bestH || P.best == P.start) { P.bestH = h; P.best = c; }
            if (!h) { planFinish(c); return; }
            P.exp = c; P.nb8 = 0; P.expansions++;
        }
        c = P.exp;
        while (P.nb8 < 8 && budget < NAV_RAYS) {
            x = c % G + ddx[P.nb8]; y = c / G + ddy[P.nb8];
            ng = gco[c] + (P.nb8 < 4 ? 10 : 14);
            P.nb8++;
            if (x < 0 || y < 0 || x >= G || y >= G) continue;
            n = y * G + x;
            if (cfl[n] == 2 || (cfl[n] == 1 && ng >= gco[n]) || cst[n] == 2) continue;
            if (P.nb8 > 4 && (cst[(c / G) * G + x] == 2 || cst[y * G + c % G] == 2)) continue; /* no corner cuts */
            if (!edge(c, n, &budget)) continue;
            gco[n] = ng; fco[n] = ng + hcost(n); par[n] = c;
            if (cfl[n] == 1) hfix(n); else { cfl[n] = 1; hpush(n); }
        }
        if (P.nb8 >= 8) P.exp = -1;
    }
    P.rays += budget;
}

/* once per frame (bots.c tmbr_BotsThink, host) */
void tmbr_NavFrame(void)
{
    char* g = D_004FA030;
    int k, i;
    if (tmbr_botCount < 0 || !g) return;
    if (!P.on) {
        for (k = 0; k < 8; k++) {
            i = (rr + k) % 8;
            if (nb[i].st == 1) {
                char* v = g + i * 0x31B0;
                rr = i + 1;
                if (!live(v) || !live(nb[i].tgt)) { nb[i].st = 0; continue; }
                planStart(g, v, nb[i].tgt);
                break;
            }
        }
    }
    if (P.on) planStep();
}

/* after a bot's AI frame (bots.c tmbr_AiUpdate). Returns 1 when it drove the car this frame. */
int tmbr_NavDrive(char* g, char* v, char* t)
{
    char* br = (char*)F(v, 0x2014);
    char* drv = (char*)F(v, 0x2018);
    int i = vidx(g, v), noLos, dist, want;
    NavBot* b;
    unsigned char* pad;
    fvec* pos;
    float err, d;
    if (i < 0 || !br || !drv) return 0;
    b = &nb[i];
    if (F(drv, 4) != 5 || !live(t)) { if (b->st == 2) b->st = 0; return 0; }
    noLos = F(br, 0x4B0);
    dist = (int)FL(br, 0x20);
    if (b->cool > 0) b->cool--;
    if (++b->tick % 240 == 0) {            /* closing in? (4 s) */
        b->noProg = dist * 100 >= b->lastD * 85;
        b->lastD = dist;
    }
    if (b->st == 2) {
        if ((noLos < 10 && dist < 500) || t != b->tgt || ++b->timer > 900 || b->i >= b->n || F(v, 0x444) >= 60) {
            if (F(v, 0x444) >= 60) b->cool = 120;   /* stuck: the AI's own reverse/turn takes over */
            b->st = 0;
            return 0;
        }
        pos = POSV(v);
        d = fabs_(b->wp[b->i].x - pos->x) + fabs_(b->wp[b->i].y - pos->y);
        if (d < P.cell * K[4] + K[2] * K[8]) b->i++;
        else if ((b->timer & 7) == 0 && b->i + 1 < b->n) {   /* shortcut when the next point is in sight */
            ra = *pos; ra.z += K[1]; rb = b->wp[b->i + 1];
            if (hdLos(&ra, &rb, res, 0)) b->i++;
        }
        if (b->i >= b->n) { b->st = 0; return 0; }
        dv.x = b->wp[b->i].x - pos->x; dv.y = b->wp[b->i].y - pos->y; dv.z = b->wp[b->i].z - pos->z; dv.w = K[0];
        rotFromVec(&rot, &dv);
        err = rot.z - FL(CS(v), 0x68);
        boundAngle(&err);
        pad = PAD(v);
        pad[2] = 0; pad[6] = 0; pad[8] = 0; pad[9] = 0; pad[0xA] = 0;
        pad[4] = 1;
        if (err > K[5]) pad[0xA] = 1;
        else if (err < -K[5]) pad[9] = 1;
        if (fabs_(err) > K[6]) pad[2] = 1;
        return 1;
    }
    want = noLos >= 60 && dist > 60 && !b->cool && (NAV_ALWAYS || b->noProg || !F(drv, 0x270));
    if (want && b->st == 0) { b->st = 1; b->tgt = t; }
    if (b->st == 1 && b->tgt != t) b->st = 0;
    return 0;
}
