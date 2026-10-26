/* TMB-Reloaded: damage reports as in Twisted Metal: Head-On (mod build and the vanilla pnach, tools/mods/make_pnach.sh).
 * "N Pts Damage" each time the local player hurts another car; hits on the same victim within 1 s add up.
 * Confirmed damage only: a hit only arms a watch on that car; what is reported is the car's actual health drop
 * in the next 3/4 s. Online that health comes from the car owner's console (netObjUpdateVehicleCB writes +0x404
 * from the update packet), so a hit that landed on your screen but not on theirs reports nothing.
 * (Someone else hitting the same car inside that window is counted too.)
 * Mod build: hooks in tools/mods/apply_mods.py; the tick runs from skins.c every frame and also draws the team score.
 * Hook (pnach): tmbr_DmgGate (dmgreport_pnach.s) in func_001E1C40, on every hit with damage > 0 (all owners);
 * the per-frame draw runs from tmbr_CameraUpdate (freecam.c) while tmbr_en[1] is set. */
#define VSIZE 0x31B0
extern char* D_004FA030;              /* game: the 8 vehicle slots */
extern void fontSpritePrintCenteredXY(int font, int x, int y, const char* s) __asm__("fontSpritePrintCenteredXY__FiiiPc");
extern void fontSpriteEnd(int font) __asm__("func_00202C58");
extern void fontSetColor(int font, int r, int g, int b) __asm__("fontSetColor__Fiiii");
extern void* viewGetCurView(void) __asm__("viewGetCurView__Fv");
extern void viewGetSize(void* view, int* w, int* h) __asm__("func_00243AA8");
extern int sprintf(char* s, const char* f, ...);

/* per screen (split screen, Ark 2026-10-26: each player's own reports in their own view): the screen is the
 * attacker's +0x210C (0 = this console's first player; guests 1..3, freecam.c / guests.c) */
static char* dmgVictim[4];
static float dmgSum[4];
static int dmgTime[4], dmgClock, dmgLen[4];
static char dmgText[4][32];
static float DMG_K[2] = { 0.5f, 0.0f };   /* (no literal pool: .lit4 would be gp-relative) */
static char DMG_FMT[] = "%d Pts Damage";
#define NW 4
#define WATCH 45                          /* frames a hit keeps watching the car's health */
static char* wCar[NW];
static float wHp[NW];
static int wEnd[NW], wScr[NW];

static void report(int sc, char* victim, float dmg)
{
    int n;
    if (sc < 0 || sc > 3) return;
    if (dmgVictim[sc] == victim && dmgClock - dmgTime[sc] < 60) dmgSum[sc] += dmg;
    else { dmgSum[sc] = dmg; dmgVictim[sc] = victim; }
    dmgTime[sc] = dmgClock;
    n = (int)(dmgSum[sc] + DMG_K[0]);
    if (n < 1) n = 1;
    dmgLen[sc] = sprintf(dmgText[sc], DMG_FMT, n);
#ifndef TMBR_PNACH
    /* a report of hundreds in one go (log 2026-10-24): log the big ones to find the source */
    if ((int)dmg >= 100 || n >= 200) {          /* (int compare: no float literal) */
        extern int scePrintf(const char* fmt, ...);
        extern int tmbr_TeamOf(char* v);
        char* g = D_004FA030;
        int k, mine = -1;
        for (k = 0; k < 8; k++)
            if (*(int*)(g + k * VSIZE + 0x590) && *(int*)(g + k * VSIZE + 0x20B4) == 1) { mine = tmbr_TeamOf(g + k * VSIZE); break; }
        scePrintf("TMBR dmg: +%d (shown %d) car %d own %d hp %d / max %d, team %d (mine %d)\n", (int)dmg, n,
                  (int)(victim - g) / VSIZE, *(int*)(victim + 0x20B4), (int)*(float*)(victim + 0x404),
                  (int)*(float*)(victim + 0x3F0), tmbr_TeamOf(victim), mine);
    }
#endif
}

#ifndef DMG_DBG
#define DMG_DBG 0
#endif
extern int scePrintf(const char* fmt, ...);
#if DMG_DBG
static char DBG_HP[] = "TMBR dmg: watched car %x health %d -> %d\n";
#endif
void tmbr_DamageDraw(int sc);
void tmbr_DamageReportTick(void)
{
    int i;
    dmgClock++;
#ifndef TMBR_PNACH
    { extern void tmbr_TeamsHud(void); tmbr_TeamsHud(); }   /* teams.c: team score under the report */
#endif
    for (i = 0; i < NW; i++) {
        float hp;
        if (!wCar[i]) continue;
        hp = *(float*)(wCar[i] + 0x404);
        if (hp < wHp[i]) {
            report(wScr[i], wCar[i], wHp[i] - hp);
#if DMG_DBG
            scePrintf(DBG_HP, (int)wCar[i], (int)wHp[i], (int)hp);
#endif
        }
        wHp[i] = hp;                       /* also follows repairs / respawns upward */
        if (dmgClock - wEnd[i] > 0) wCar[i] = 0;
    }
#ifndef TMBR_PNACH
    { extern int tmbr_SplitViews(void); if (tmbr_SplitViews() >= 2) return; }   /* (split: drawn per view) */
#endif
    tmbr_DamageDraw(0);
}
/* one screen's report, in the view being drawn (split screen: freecam.c tmbr_HudView for each view) */
void tmbr_DamageDraw(int sc)
{
    int wh[2];
    if (sc < 0 || sc > 3 || !dmgLen[sc] || dmgClock - dmgTime[sc] > 90) return;
    viewGetSize(viewGetCurView(), &wh[0], &wh[1]);
    fontSetColor(0, 0x7C, 0x78, 0x02);
    fontSpritePrintCenteredXY(0, wh[0] / 2, 27, dmgText[sc]);
    fontSpriteEnd(0);
}

/* a hit by the local player (tmbr_DmgGate). Remote cars (0x20B4 2) never take damage here - their owner's
 * console decides and its update packet brings the new health: watch that car */
void tmbr_DmgSeen(char* victim, char* attacker, float dmg)
{
    char* g = D_004FA030;
    int i, k = -1;
    if (!g || !attacker || !victim || attacker == victim || !(dmg > DMG_K[1])) return;
    if (attacker < g || attacker >= g + 8 * VSIZE || *(int*)(attacker + 0x20B4) != 1) return;
    if ((unsigned)*(int*)(attacker + 0x210C) > 3) return;       /* this console's screens 0..3 */
    /* cars this console owns (you, bots, traffic): tmbr_TakeHit reports their real health loss. (At this point
     * of func_001E1C40 $f22 is no longer the damage for them: it held the car's health, log 2026-10-24) */
    if (*(int*)(victim + 0x20B4) != 2) return;
    for (i = 0; i < NW; i++) if (wCar[i] == victim) { wEnd[i] = dmgClock + WATCH; wScr[i] = *(int*)(attacker + 0x210C); return; }
    for (i = 0; i < NW; i++) if (!wCar[i]) { k = i; break; }
    if (k < 0) {                                              /* all busy: the one ending first */
        k = 0;
        for (i = 1; i < NW; i++) if (wEnd[i] - wEnd[k] < 0) k = i;
    }
    wCar[k] = victim;
    wHp[k] = *(float*)(victim + 0x404);                       /* health before the owner's verdict */
    wEnd[k] = dmgClock + WATCH;
    wScr[k] = *(int*)(attacker + 0x210C);
}

/* Rams on a car another console owns never reach func_001E1C40 here: func_001214C0 (car-to-car collision) sends
 * the victim's console a game event instead (netSendGameEvent, type 60: ev[0] rammer's player index, ev[4]
 * victim's, ev[5] damage) and that console applies the hit. Hook on that call (0x121744): send it, then watch
 * the victim like a weapon hit. (Rams on cars this console owns go through func_001E1C40 and the gate.) */
extern void netSendGameEvent(void* net, int to, int* ev) __asm__("netSendGameEvent");
static char* byPlayer(int idx)
{
    char* g = D_004FA030;
    int i;
    for (i = 0; g && i < 8; i++)
        if (*(int*)(g + i * VSIZE + 0x20C0) == idx && *(int*)(g + i * VSIZE + 0x590)) return g + i * VSIZE;
    return 0;
}
#ifndef DMG_DBG
#define DMG_DBG 0
#endif
extern int scePrintf(const char* fmt, ...);
#if DMG_DBG
static char DBG_RAM[] = "TMBR ram: to %d ev %d %d %d %d %d %d -> rammer %x (own %d) victim %x (own %d hp %d)\n";
#endif
void tmbr_RamSent(void* net, int to, int* ev)
{
    char *r, *v;
    netSendGameEvent(net, to, ev);
    r = byPlayer(ev[0]); v = byPlayer(ev[4]);
#if DMG_DBG
        scePrintf(DBG_RAM, to, ev[0], ev[1], ev[4], ev[5], ev[6], ev[2], (int)r, r ? *(int*)(r + 0x20B4) : -1,
                  (int)v, v ? *(int*)(v + 0x20B4) : -1, v ? (int)*(float*)(v + 0x404) : -1);
#endif
    if (ev[1] != 60) return;
    if (r && v && ev[5] > 0) tmbr_DmgSeen(v, r, (float)ev[5]);
}

/* Every call of the game's hit function (func_001E1C40(car, pos, damage, attacker id, x), 7 call sites, all
 * hooked) comes here:
 *  - team play (mod build): a hit from a teammate is dropped before it is applied - no damage, no effect;
 *  - damage reports for cars this console owns: health before minus health after = the damage really done.
 * The attacker is the car whose +0x20FC is the id (+0x20D0 set), as func_001E1C40 looks it up. */
extern int gameTakeHit(char* v, void* pos, int dmg, int att, int x) __asm__("func_001E1C40");
int tmbr_TakeHit(char* v, void* pos, int dmg, int att, int x)
{
    char *g = D_004FA030, *a = 0;
    int k, r;
    float hp0;
    for (k = 0; g && k < 8; k++)
        if (*(int*)(g + k * VSIZE + 0x20FC) == att && *(int*)(g + k * VSIZE + 0x20D0)) { a = g + k * VSIZE; break; }
#ifndef TMBR_PNACH
    {
        extern int tmbr_SameTeam(char* a, char* b);       /* teams.c: 0 unless team play is on */
        if (a && a != v && tmbr_SameTeam(a, v)) return 0;
    }
#endif
    hp0 = *(float*)(v + 0x404);
    r = gameTakeHit(v, pos, dmg, att, x);
    if (a && a != v && *(int*)(a + 0x20B4) == 1 && (unsigned)*(int*)(a + 0x210C) <= 3 && *(int*)(v + 0x20B4) != 2 &&
        *(float*)(v + 0x404) < hp0)
        report(*(int*)(a + 0x210C), v, hp0 - *(float*)(v + 0x404));
    return r;
}
