/* TMB-Reloaded mod: local split-screen guests (experimental) - players 2..4 on controllers 2..4 (multitap).
 *
 * Online kept retail's local-player machinery; it just never uses more than one:
 *  - gameMakeAI (func_0013A7B8) with ai = 0 makes a HUMAN car: player struct game+0x1F0E0 + 0x7E4 * slot as its
 *    combo (+0x2010), player index +0x2100 = slot, player init func_0017BDD8 (kind +0x590 = 1, Combo::Init),
 *    and with cam >= 0 gameInitCamera (camera `cam` follows it, HUD of viewport `cam` shows it);
 *  - every frame the human input update (func_0017BE80, from the vehicle update) reads its pad through
 *    inputGetPlayerPad(+0x2100): gas, brake, steer, fire, turbo, combos - the whole player.
 * Online's inputGetPlayerPad returns the player index itself (except 1: the multitap), so a guest in car slot 5
 * would read pad 5. The hook (apply_mods.py: first instruction of inputGetPlayerPad -> tmbr_InputGetPlayerPad)
 * maps a guest's slot to its controller's pad (pad index = port + 2 x multitap slot: controller 2 = 1B = 2,
 * 3 = 1C = 4, 4 = 1D = 6); everything else as before.
 * Views: 1 guest = top / bottom (layouts 1, 2), 2-3 guests = 4-way (0xA..0xD; with 2 guests view 3 follows a bot).
 * Made by the host 5 s into the match (with the extra views, freecam.c splitFrame); bots leave room for them
 * (bots.c wanted: guests count as humans). Guests on a console that joined someone else's match: not yet.
 *
 * Test config (this stage): tmbr_guests = { tag "GSTS", count, car 2, car 3, car 4 } (car = character << 5, 0 =
 * random), set in the ELF by tools/qb/split/splitpatch.py. Car choice on the car select screen comes next. */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern char* D_004FA030;              /* game */
extern char D_003156C0[];             /* net: 8 player slots x 0x220 */
extern int scePrintf(const char* fmt, ...);
extern int mathfRandI(int lo, int hi) __asm__("mathfRand__Fii");
extern char* gameMakeAI(char* game, int v, int name, int v2, int cam, int ai) __asm__("func_0013A7B8");
extern int netSlotVehicle(void* net, int slot) __asm__("func_00174268");
extern int tmbr_Opt(int bit);

int tmbr_guests[5] = { 0x53545347, 0, 0, 0, 0 };   /* "GSTS", count, cars */
static signed char padOf[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };   /* car slot -> controller pad index */
static char* guestCar[4];
static int guestN;

int tmbr_GuestCount(void) { return guestN; }
int tmbr_GuestsWanted(void) { int n = tmbr_guests[1]; return n < 0 ? 0 : n > 3 ? 3 : n; }
int tmbr_IsGuest(char* v)
{
    int i;
    for (i = 1; i <= guestN; i++) if (guestCar[i] == v) return 1;
    return 0;
}

/* inputGetPlayerPad replacement (online's logic + the guests' controllers) */
extern int D_00612B40[];   /* portAndSlotMap[port * 4 + slot] = pad index */
extern int D_00612BC0[];   /* padPhase[pad] (non-zero: a pad answers there) */
extern int D_004FB690;     /* mtapConnected */
int tmbr_InputGetPlayerPad(int p)
{
    int k;
    if (p >= 0 && p < 8 && padOf[p] >= 0) return padOf[p];
    if (p != 1) return p;
    k = D_00612B40[1];
    if (D_00612BC0[k]) { D_004FB690 = 1; return k; }
    D_004FB690 = 0;
    return D_00612B40[4];
}

/* a free car slot: a net slot nobody uses (+0x214 == 0) whose vehicle is not set up (like bots.c addBot) */
static int freeSlot(char* g)
{
    int s, v;
    for (s = 7; s >= 0; s--) {               /* from the top: bots fill from the bottom */
        if (F(D_003156C0 + s * 0x220, 0x214) != 0) continue;
        v = netSlotVehicle(D_003156C0, s) - 1;
        if (v < 0 || v >= 8 || F(g + v * 0x31B0, 0x590) != 0) continue;
        if (F(g, 0x9E670 + v * 4) && F(F(g, 0x9E670 + v * 4), 0x20D0) != 0) continue;
        return v;
    }
    return -1;
}

/* make the guests (freecam.c splitFrame, right after the views are set up, cam = their view) */
void tmbr_GuestsMake(int views)
{
    char* g = D_004FA030;
    int i, n = tmbr_GuestsWanted();
    static const int pads[4] = { 0, 2, 4, 6 };
    guestN = 0;
    for (i = 0; i < 8; i++) padOf[i] = -1;
    if (!g) return;
    for (i = 1; i <= n && i < views; i++) {
        int v = freeSlot(g), car = tmbr_guests[1 + i];
        char* veh;
        if (v < 0) { scePrintf("TMBR guests: no free car slot for player %d\n", i + 1); break; }
        if (car <= 0) car = mathfRandI(1, 14) << 5;
        if ((car >> 5) == 15 && tmbr_Opt(8)) car = mathfRandI(1, 14) << 5;   /* Minion off */
        padOf[v] = pads[i];
        veh = gameMakeAI(g, v, car, v, i, 0);
        if (!veh) {             /* (the human branch does not return the car: find the one it set up) */
            int k;
            for (k = 0; k < 8; k++)
                if (F(g + k * 0x31B0, 0x20F0) == v && F(g + k * 0x31B0, 0x590) == 1) veh = g + k * 0x31B0;
        }
        if (!veh) { padOf[v] = -1; scePrintf("TMBR guests: player %d not made\n", i + 1); break; }
        F(veh, 0x210C) = i;
        guestCar[i] = veh;
        guestN = i;
        scePrintf("TMBR guests: player %d = car slot %d, char %d, pad %d, view %d, kind %d\n", i + 1, v, car >> 5, pads[i], i, F(veh, 0x590));
    }
}
/* level change / match end */
void tmbr_GuestsReset(void)
{
    int i;
    guestN = 0;
    for (i = 0; i < 8; i++) padOf[i] = -1;
    for (i = 0; i < 4; i++) guestCar[i] = 0;
}
