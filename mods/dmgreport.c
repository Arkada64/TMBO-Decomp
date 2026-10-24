/* TMB-Reloaded, vanilla pnach build only (tools/mods/make_pnach.sh): damage reports as in Twisted Metal: Head-On.
 * "N Pts Damage" each time the local player hurts another car; hits on the same victim within 1 s add up.
 * Same code as the mod build's (traffic.c tmbr_NetVehicleDamage / tmbr_DamageReportTick) without traffic and teams.
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

void tmbr_DamageReportTick(void)
{
    int wh[2];
    dmgClock++;
    if (!dmgLen || dmgClock - dmgTime > 90) return;
    viewGetSize(viewGetCurView(), &wh[0], &wh[1]);
    fontSetColor(0, 0x7C, 0x78, 0x02);
    fontSpritePrintCenteredXY(0, wh[0] / 2, 27, dmgText);
    fontSpriteEnd(0);
}

void tmbr_DmgSeen(char* victim, char* attacker, float dmg)
{
    char* g = D_004FA030;
    int n;
    if (!g || !attacker || attacker == victim || !(dmg > DMG_K[1])) return;
    if (attacker < g || attacker >= g + 8 * VSIZE || *(int*)(attacker + 0x20B4) != 1) return;
    if (*(int*)(attacker + 0x210C) != 0) return;              /* first screen only */
    if (dmgVictim == victim && dmgClock - dmgTime < 60) dmgSum += dmg;
    else { dmgSum = dmg; dmgVictim = victim; }
    dmgTime = dmgClock;
    n = (int)(dmgSum + DMG_K[0]);
    if (n < 1) n = 1;
    dmgLen = sprintf(dmgText, DMG_FMT, n);
}
