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

static char* dmgVictim;
static float dmgSum;
static int dmgTime, dmgClock, dmgLen;
static char dmgText[32];
static float DMG_K[2] = { 0.5f, 0.0f };   /* (no literal pool: .lit4 would be gp-relative) */
static char DMG_FMT[] = "%d Pts Damage";
#define NW 4
#define WATCH 45                          /* frames a hit keeps watching the car's health */
static char* wCar[NW];
static float wHp[NW];
static int wEnd[NW];

static void report(char* victim, float dmg)
{
    int n;
    if (dmgVictim == victim && dmgClock - dmgTime < 60) dmgSum += dmg;
    else { dmgSum = dmg; dmgVictim = victim; }
    dmgTime = dmgClock;
    n = (int)(dmgSum + DMG_K[0]);
    if (n < 1) n = 1;
    dmgLen = sprintf(dmgText, DMG_FMT, n);
}

#ifndef DMG_DBG
#define DMG_DBG 0
#endif
extern int scePrintf(const char* fmt, ...);
static char DBG_HP[] = "TMBR dmg: watched car %x health %d -> %d\n";
void tmbr_DamageReportTick(void)
{
    int wh[2], i;
    dmgClock++;
#ifndef TMBR_PNACH
    { extern void tmbr_TeamsHud(void); tmbr_TeamsHud(); }   /* teams.c: team score under the report */
#endif
    for (i = 0; i < NW; i++) {
        float hp;
        if (!wCar[i]) continue;
        hp = *(float*)(wCar[i] + 0x404);
        if (hp < wHp[i]) {
            report(wCar[i], wHp[i] - hp);
            if (DMG_DBG) scePrintf(DBG_HP, (int)wCar[i], (int)wHp[i], (int)hp);
        }
        wHp[i] = hp;                       /* also follows repairs / respawns upward */
        if (dmgClock - wEnd[i] > 0) wCar[i] = 0;
    }
    if (!dmgLen || dmgClock - dmgTime > 90) return;
    viewGetSize(viewGetCurView(), &wh[0], &wh[1]);
    fontSetColor(0, 0x7C, 0x78, 0x02);
    fontSpritePrintCenteredXY(0, wh[0] / 2, 27, dmgText);
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
    if (*(int*)(attacker + 0x210C) != 0) return;              /* first screen only */
    /* a car this console owns (bots / AI: 0x20B4 4) already took the damage above the hook - that is final */
    if (*(int*)(victim + 0x20B4) != 2) { report(victim, dmg); return; }
    for (i = 0; i < NW; i++) if (wCar[i] == victim) { wEnd[i] = dmgClock + WATCH; return; }
    for (i = 0; i < NW; i++) if (!wCar[i]) { k = i; break; }
    if (k < 0) {                                              /* all busy: the one ending first */
        k = 0;
        for (i = 1; i < NW; i++) if (wEnd[i] - wEnd[k] < 0) k = i;
    }
    wCar[k] = victim;
    wHp[k] = *(float*)(victim + 0x404);                       /* health before the owner's verdict */
    wEnd[k] = dmgClock + WATCH;
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
static char DBG_RAM[] = "TMBR ram: to %d ev %d %d %d %d %d %d -> rammer %x (own %d) victim %x (own %d hp %d)\n";
void tmbr_RamSent(void* net, int to, int* ev)
{
    char *r, *v;
    netSendGameEvent(net, to, ev);
    r = byPlayer(ev[0]); v = byPlayer(ev[4]);
    if (DMG_DBG)
        scePrintf(DBG_RAM, to, ev[0], ev[1], ev[4], ev[5], ev[6], ev[2], (int)r, r ? *(int*)(r + 0x20B4) : -1,
                  (int)v, v ? *(int*)(v + 0x20B4) : -1, v ? (int)*(float*)(v + 0x404) : -1);
    if (ev[1] != 60) return;
    if (r && v && ev[5] > 0) tmbr_DmgSeen(v, r, (float)ev[5]);
}
