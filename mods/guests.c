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
 * Joining (host, waiting room = UI state 0x21): START on controller 2..4 opens the real car select (UI state 0x27)
 * for that controller - its pad drives the UI (tmbr_UiPadButtons, the UI input's inputGetPadButtons call), a title
 * says "PLAYER n" (tmbr_GuestPickTitle from skins.c's car select hook). The confirm / back net calls in car select
 * (func_00173570 at 0x1CB944 / 0x1CB9C4) go through tmbr_CarSelNet: for a guest pick the chosen car goes to the
 * guest (and to the net slot reserved for it, so the level load loads that car's model), the host's own car and
 * highlight are put back and the net step goes out with the host's unchanged car; car select returns to the
 * waiting room as usual. SELECT on a guest's
 * controller in the waiting room drops the guest.
 * Test config: tmbr_guests = { tag "GSTS", count, car 2, car 3, car 4 } (car = character << 5, 0 = random) joins
 * guests without the pick (set in the ELF by tools/qb/split/splitpatch.py). */
#define F(p, off) (*(int*)((char*)(p) + (off)))
extern int sprintf(char* d, const char* f, ...);
extern void fontSetCursorAtSubPixel(int font, int x, int y) __asm__("fontSetCursorAtSubPixel__Fiii");
extern void fontPrint(int font, const char* s) __asm__("func_00203150");
extern void fontSetColor(int font, int r, int g, int b) __asm__("fontSetColor__Fiiii");
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
static int joinCar[4], joinSlot[4] = { -1, -1, -1, -1 };   /* per controller 2..4 (index 1..3): car, net slot */
static int picking, pickSavedCar, pickSavedPos, prevBtn[4], idleT[4];
static int naming;                                  /* controller (1..3) typing its name, 0 = none */
static char guestName[4][16];

int tmbr_GuestCount(void) { return guestN; }
char* tmbr_GuestCar(int i) { return i > 0 && i < 4 && guestCar[i] != (char*)-1 ? guestCar[i] : 0; }   /* view i's guest car, 0 = none / not made yet */
int tmbr_GuestPicking(void) { return picking; }
int tmbr_GuestCarValue(int i) { return i > 0 && i < 4 ? joinCar[i] : 0; }   /* view i's picked car (car id << 5) */
static int joined(void) { int k, n = 0; for (k = 1; k <= 3; k++) if (joinCar[k]) n++; return n; }
int tmbr_GuestsWanted(void)
{
    int n = joined();
    if (!n) n = tmbr_guests[1];
    return n < 0 ? 0 : n > 3 ? 3 : n;
}
int tmbr_GuestSlot(int s) { int k; for (k = 1; k <= 3; k++) if (joinCar[k] && joinSlot[k] == s) return 1; return 0; }
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

/* The level loads one car per player slot (what is loaded is in D_00313F00[slot]); a guest's slot is empty to
 * the network, so it carries the bot car the host rolled for it (test 2026-10-26: Junkyard Dog picked, Yellow
 * Jacket / Outlaw loaded). At level start, load the guest's car into that slot the way TMBO reloads a player
 * who changed cars mid-session (func_001742B0: func_001FE0B8 + func_001890F0, needs slot +0x10 != -1 and
 * +0xB8 set, both put back after). func_0018A480(vehicle) is 1 once nothing is queued for it. */
extern int D_00313F00[];
extern char* D_004FA03C;
extern void shellLoadSlotCar(char* shell, int s) __asm__("func_001890F0");
extern void carUnloadVeh(int v) __asm__("func_001FE0B8");
extern int carLoadDone(int v) __asm__("func_0018A480");
static void preload(int inGame);
void tmbr_GuestsPreload(void) { preload(1); }

static void preload(int inGame)
{
    int k;
    for (k = 1; k <= 3; k++) {
        int s = joinSlot[k], was10, wasB8, vn;
        char* sl;
        if (!joinCar[k] || s < 0) continue;
        sl = D_003156C0 + s * 0x220;
        if (F(sl, 0xB4) != joinCar[k]) F(sl, 0xB4) = joinCar[k];
        if (D_00313F00[s] == joinCar[k]) { scePrintf("TMBR guests: slot %d already has car %d\n", s, joinCar[k] >> 5); continue; }
        scePrintf("TMBR guests: slot %d loaded car %d, loading %d\n", s, D_00313F00[s] >> 5, joinCar[k] >> 5);
        was10 = F(sl, 0x10); wasB8 = F(sl, 0xB8);
        F(sl, 0x10) = s; F(sl, 0xB8) = 1;
        vn = netSlotVehicle(D_003156C0, s);
        if (inGame) carUnloadVeh(vn);
        shellLoadSlotCar(D_004FA03C, s);
        F(sl, 0x10) = was10; F(sl, 0xB8) = wasB8;
        scePrintf("TMBR guests: slot %d now %d, done %d\n", s, D_00313F00[s] >> 5, carLoadDone(vn));
    }
}
/* The level load (func_00188248, from func_00186730 0x186AF8) loads each player slot's car from D_00313F00[slot]
 * (copied to D_003F6E08 at its start); for empty slots that holds the bot car the session rolled. Put the guests'
 * cars there first, so their cars load with the level (Ark 2026-10-26: both halves showed P1 for a second while a
 * guest's car loaded in the match). */
extern void levelLoadCars(char* shell, int a) __asm__("func_00188248");
void tmbr_LevelLoadCars(char* shell, int a)
{
    int k;
    for (k = 1; k <= 3; k++)
        if (joinCar[k] && joinSlot[k] >= 0) {
            scePrintf("TMBR guests: level load, slot %d car %d -> %d\n", joinSlot[k], D_00313F00[joinSlot[k]] >> 5, joinCar[k] >> 5);
            D_00313F00[joinSlot[k]] = joinCar[k];
        }
    levelLoadCars(shell, a);
}
/* make the guests (freecam.c splitFrame, right after the views are set up, cam = their view) */
/* returns how many guests are still waiting for their car to load (call again next frame) */
int tmbr_GuestsMake(int views)
{
    char* g = D_004FA030;
    int i, n = tmbr_GuestsWanted(), pending = 0;
    static const int pads[4] = { 0, 2, 4, 6 };
    int order[4];
    if (!g) return 0;
    {   /* guests from the waiting room joins (controller k, its reserved slot and car) or the test config */
        int k, m = 0;
        for (k = 1; k <= 3; k++) if (joinCar[k]) { m++; order[m] = k; }
        if (!m) for (k = 1; k <= n; k++) order[k] = -k;
    }
    for (i = 1; i <= n && i < views; i++) {
        int k = order[i], v = -1, car;
        char* veh;
        if (guestCar[i]) continue;                      /* made already */
        if (k > 0 && joinSlot[k] >= 0 && !carLoadDone(netSlotVehicle(D_003156C0, joinSlot[k]))) { pending++; continue; }
        if (k > 0) {
            car = joinCar[k];
            if (joinSlot[k] >= 0) v = netSlotVehicle(D_003156C0, joinSlot[k]) - 1;
            if (v >= 0 && v < 8 && F(g + v * 0x31B0, 0x590) != 0) v = -1;    /* (taken after all) */
            if (v < 0) v = freeSlot(g);
            if (joinSlot[k] >= 0) scePrintf("TMBR guests: controller %d slot %d car %d (slot says %d)\n", k + 1, joinSlot[k], car >> 5, F(D_003156C0 + joinSlot[k] * 0x220, 0xB4) >> 5);
        } else { k = -k; car = tmbr_guests[1 + k]; v = freeSlot(g); }
        if (v < 0) { scePrintf("TMBR guests: no free car slot for player %d\n", i + 1); guestCar[i] = (char*)-1; continue; }
        if (car <= 0) car = mathfRandI(1, 14) << 5;
        if ((car >> 5) == 15 && !tmbr_Opt(8)) car = mathfRandI(1, 14) << 5;   /* Minion off */
        padOf[v] = pads[k];
        veh = gameMakeAI(g, v, car, v, i, 0);
        if (!veh) {             /* (the human branch does not return the car: find the one it set up) */
            int k;
            for (k = 0; k < 8; k++)
                if (F(g + k * 0x31B0, 0x20F0) == v && F(g + k * 0x31B0, 0x590) == 1) veh = g + k * 0x31B0;
        }
        if (!veh) { padOf[v] = -1; scePrintf("TMBR guests: player %d not made\n", i + 1); guestCar[i] = (char*)-1; continue; }
        F(veh, 0x210C) = i;
        /* owner type +0x20B4: hits only take health off 1 (this console's player) or 4 (the host's bots), a remote
         * car's damage comes from its own console (func_001E1C40 0x1E22A4). A guest is this console's player
         * (Ark 2026-10-26: guests took no damage) */
        scePrintf("TMBR guests: player %d owner type %d -> 1\n", i + 1, F(veh, 0x20B4));
        F(veh, 0x20B4) = 1;
        /* a net object like the host's bots (bots.c addBot: func_001756A0): the leaderboard (func_00175AA0) only
         * lists cars with one (+0x20D8) and names a human from its net slot (+0x20C0, the name set at join), and
         * clients see the car (Ark 2026-10-26: guests missing from the scoreboard / bay panel) */
        {
            extern int netBotObjects(void* net, char* veh) __asm__("func_001756A0");
            if (!F(veh, 0x20D8)) netBotObjects(D_003156C0, veh);
            if (k > 0 && joinSlot[k] >= 0) F(veh, 0x20C0) = joinSlot[k];   /* its net slot (name: +0x18) */
            F(veh, 0x20B4) = 1;                                 /* (netBotObjects makes it a bot, 4) */
            scePrintf("TMBR guests: player %d net object %x, net slot %d\n", i + 1, F(veh, 0x20D8), F(veh, 0x20C0));
        }
        guestCar[i] = veh;
        {   /* the human branch of gameMakeAI never switches on this car's animation manager (ai branch: 0x13A850),
             * so a guest's shield shimmer / special / death animations stood still (reference/wip/GUEST_SHIELD.md) */
            extern void animMgrEnable(int en, int idx) __asm__("func_001FDE10");
            animMgrEnable(1, (veh - g) / 0x31B0 + 1);
        }
        if (i > guestN) guestN = i;
        scePrintf("TMBR guests: player %d (controller %d) = car slot %d, char %d, pad %d, view %d, kind %d\n", i + 1, k + 1, v, car >> 5, pads[k], i, F(veh, 0x590));
    }
    return pending;
}
/* the HUD's "cars left" counter (func_00144460, from func_00145860 0x146D70): net players (settings +0x24) plus
 * the game's AI count (game +0x98000 +0x7EE4); guests are neither (Ark 2026-10-26: the number was short by the
 * guests). They are added to the AI count for that call only. */
extern void hudCarsLeft(char* hud) __asm__("func_00144460");
void tmbr_HudCarsLeft(char* hud)
{
    char* g = D_004FA030;
    int n = 0, i;
    for (i = 1; i < 4; i++) if (guestCar[i] && guestCar[i] != (char*)-1) n++;
    if (!g || !n) { hudCarsLeft(hud); return; }
    F(g, 0x98000 + 0x7EE4) += n;
    hudCarsLeft(hud);
    F(g, 0x98000 + 0x7EE4) -= n;
}
/* level change / match end */
void tmbr_GuestsReset(void)
{
    int i;
    guestN = 0;
    for (i = 0; i < 8; i++) padOf[i] = -1;
    for (i = 0; i < 4; i++) guestCar[i] = 0;
}

/* ---- waiting room: join / pick / leave ---- */
extern int inputGetPadButtons(int pad) __asm__("inputGetPadButtons__Fi");
extern int netIsHost(void* net) __asm__("func_001734B8");
extern void netSetState(void* net, int st) __asm__("func_00173570");
extern int carSelPos __asm__("D_004FA7D8");
extern char* shellPtr __asm__("D_004FA03C");
extern int D_004FA684, D_004FA688, D_004FA6E4, D_004FA910, D_004FA914, D_004FA718, D_004FA94C;   /* UI state, next state, go, hold, back */
extern char* D_0041BF00[];          /* waiting-room car names by car code >> 5 */
#define UI_ROOM 0x21
#define UI_CARSEL 0x27
#define B_SELECT 0x1
#define B_START 0x8
static char* myClient(void) { return *(char**)(D_003156C0 + 4); }   /* this console's client struct (car at +0xA4) */
static int reserveSlot(void)
{
    int s, k;
    for (s = 7; s >= 0; s--) {
        if (F(D_003156C0 + s * 0x220, 0x214) != 0) continue;
        for (k = 1; k <= 3; k++) if (joinCar[k] && joinSlot[k] == s) break;
        if (k <= 3) continue;
        return s;
    }
    return -1;
}
extern int inputIsCtlAvailable(int pad, int b) __asm__("inputIsCtlAvailable__Fib");
/* a controller's buttons (active high), -1 when it is not there / not ready / reads as all pressed */
static int padBtn(int pad)
{
    int b = inputGetPadButtons(pad) & 0xFFFF;
    static int logT;
    if (pad == 2 && ++logT % 1200 == 0)            /* (debug: what controllers 2-4 read in the waiting room) */
        scePrintf("TMBR guests: pads %04x %04x %04x ui %x>%x go %d hold %d back %d scn %x busy %d\n", inputGetPadButtons(2) & 0xFFFF,
            inputGetPadButtons(4) & 0xFFFF, inputGetPadButtons(6) & 0xFFFF, D_004FA684, D_004FA688, D_004FA6E4, D_004FA910,
            D_004FA914, D_004FA718, D_004FA94C);
    return b == 0xFFFF ? -1 : b;
}
void tmbr_GuestsLobby(void)
{
    int k;
    if (D_004FA684 != UI_ROOM || picking || naming) return;
    for (k = 1; k <= 3; k++) {
        int b = padBtn(2 * k), pr;
        /* a press counts only after the controller has been seen answering with nothing pressed for a while
         * (a missing / not-ready multitap slot reads as garbage: everything pressed, test 2026-10-26) */
        if (b < 0) { idleT[k] = 0; prevBtn[k] = 0; continue; }
        if (!(b & (B_START | B_SELECT))) { if (idleT[k] < 100) idleT[k]++; }
        pr = idleT[k] >= 30 ? b & ~prevBtn[k] : 0;
        prevBtn[k] = b;
        /* START: join (car select), or for a guest already in, change car (Ark 2026-10-26); SELECT: leave */
        if (pr & B_START) {
            if (!netIsHost(D_003156C0)) { scePrintf("TMBR guests: joining on a client console is not done yet\n"); continue; }
            if (!myClient()) continue;
            picking = k;
            pickSavedCar = F(myClient(), 0xA4); pickSavedPos = carSelPos;
            /* to car select, with the shell camera flown to the car display like the room's SELECT CAR does
             * (0x1C7134: D_004FA7D8 = position, D_004FA718 = camera spot = position + 5); without it the room stays
             * behind the car select (Ark 2026-10-26) */
            if (joinCar[k] && shellPtr) {               /* a car change starts on the guest's own car */
                int q;
                for (q = 0; q < 16; q++) if (F(shellPtr + 0x1A2F0, q * 4) == joinCar[k]) { carSelPos = q; break; }
            }
            D_004FA718 = carSelPos + 5;
            D_004FA688 = UI_CARSEL; D_004FA910 = 0; D_004FA6E4 = 1;
            scePrintf("TMBR guests: controller %d picks a car\n", k + 1);
            return;
        }
        if ((pr & B_SELECT) && joinCar[k]) {
            joinCar[k] = 0; joinSlot[k] = -1; guestName[k][0] = 0;
            scePrintf("TMBR guests: controller %d left\n", k + 1);
        }
    }
}
/* func_00174598 (host: each empty player slot, +0x10 == -1, gets a random car at +0xB4 - the bots' cars) runs when
 * the room is made and again in func_0016FA30; a guest's reserved slot is an empty slot, so its car must be put back
 * after it (test 2026-10-26: P2 picked Junkyard Dog and came in as Yellow Jacket) */
extern void netRandomBotCars(void* net) __asm__("func_00174598");
extern void tmbr_BotPakSet(int mask);   /* skins.c */
void tmbr_BotCars(void* net)
{
    int k, s, pak = 0;
    netRandomBotCars(net);
    { extern int tmbr_StoryCars(void); if (tmbr_StoryCars()) s = 8; else s = 0; }   /* story.c: its own rule */
    for (; s < 8; s++) {          /* bots' cars: 12 Pak as often as any other car (1 in 16; TODO 6, 2026-10-26) */
        if (F(D_003156C0 + s * 0x220, 0x10) != -1 || tmbr_GuestSlot(s)) continue;
        if (mathfRandI(0, 15) == 0) { F(D_003156C0 + s * 0x220, 0xB4) = 0x20; pak |= 1 << s; }
    }
    tmbr_BotPakSet(pak);
    for (k = 1; k <= 3; k++) {
        if (!joinCar[k] || joinSlot[k] < 0) continue;
        scePrintf("TMBR guests: slot %d car %d -> %d (+0x10 %d)\n", joinSlot[k], F(D_003156C0 + joinSlot[k] * 0x220, 0xB4) >> 5,
            joinCar[k] >> 5, F(D_003156C0 + joinSlot[k] * 0x220, 0x10));
        F(D_003156C0 + joinSlot[k] * 0x220, 0xB4) = joinCar[k];
    }
}
/* car select's confirm / back (net state 1 + the car in this console's client struct): a guest pick stays local */
void tmbr_CarSelNet(void* net, int st)
{
    int k = picking;
    if (!k) { netSetState(net, st); return; }
    picking = 0;
    if (!D_004FA914 && shellPtr) {                       /* confirm (0) - back (1) cancels the join */
        int car = F(shellPtr + 0x1A2F0, carSelPos * 4), s = reserveSlot();
        if (car <= 0) car = 0x20;
        if (s >= 0) {
            int isNew = !joinCar[k];
            joinCar[k] = car; joinSlot[k] = s;
            F(D_003156C0 + s * 0x220, 0xB4) = car;           /* so the level load loads this car for that slot */
            scePrintf("TMBR guests: controller %d joins with %s (net slot %d)\n", k + 1, D_0041BF00[car >> 5], s);
            if (isNew) nameStart(k);
        } else scePrintf("TMBR guests: no free slot for controller %d\n", k + 1);
    }
    if (myClient()) F(myClient(), 0xA4) = pickSavedCar;   /* the host's own car back */
    carSelPos = pickSavedPos;
    /* then the normal net step with the host's own (unchanged) car: the way back to the waiting room waits for its
     * reply (D_004FA910); skipping it left car select on screen for good (test 2026-10-26) */
    netSetState(net, st);
}
/* the UI's pad (func_001CE258): the picking guest's controller while it picks. The guest's accept / back are
 * handled here and never reach car select: its own confirm re-enters the room (func_001C5430 resends the session
 * join) and left the car select picture up with the waiting room logic running underneath (test 2026-10-26).
 * Instead go back the way we came in (the same transition as tmbr_GuestsLobby's). */
#define B_TRI 0x1000
#define B_CIRCLE 0x2000
#define B_CROSS 0x4000
static void preload(int inGame);
static void nameStart(int k);
void tmbr_GuestPickEnd(int accept)
{
    int k = picking;
    picking = 0;
    if (accept && shellPtr) {
        int car = F(shellPtr + 0x1A2F0, carSelPos * 4);
        int s = joinCar[k] && joinSlot[k] >= 0 ? joinSlot[k] : reserveSlot();   /* (a car change keeps the slot) */
        if (car <= 0) car = 0x20;
        if (s >= 0) {
            int isNew = !joinCar[k];
            joinCar[k] = car; joinSlot[k] = s;
            F(D_003156C0 + s * 0x220, 0xB4) = car;           /* so the level load loads this car for that slot */
            scePrintf("TMBR guests: controller %d joins with %s (net slot %d)\n", k + 1, D_0041BF00[car >> 5], s);
            if (isNew) nameStart(k);
        } else scePrintf("TMBR guests: no free slot for controller %d\n", k + 1);
    } else scePrintf("TMBR guests: controller %d backed out\n", k + 1);   /* (a car change: the old car stays) */

    if (myClient()) F(myClient(), 0xA4) = pickSavedCar;
    carSelPos = pickSavedPos;
    D_004FA718 = 0x75;                                  /* camera back to the room (as car select's own confirm) */
    D_004FA688 = UI_ROOM; D_004FA910 = 0; D_004FA914 = 0; D_004FA6E4 = 1;
}
/* ---- the retail loading screen's crash (TODO 4e, Ark 2026-10-26: in TMB the two halves of the loading screen come
 * crashing together; TMBO shows them already shut). The halves are shell screens (node ids 9901 = bottom half with the
 * LOADING plate, 9902 = top half; struct shell +0xB950 + i * 0x30, its cs at +0x20, the vertical offset at cs +0x18,
 * 0 = shut; found 2026-10-26). The loading UI state (0x29) runs func_001CBD18 (the LOADING... state, called from the
 * UI loop at 0x1B3CA4), which starts the load at once; tmbr_LoadScreen holds it back: the halves start apart (top
 * above the screen, bottom below), fall together with gravity, slam (the shell's crash sound, retail's 0xD), bounce
 * a little and settle; then the original runs and the load starts. */
extern void uiLoadLevel(void) __asm__("func_001CBD18");
extern void shellSfx(void* snd, int id) __asm__("playShellSFXSound__10ShellSoundi");
static int lsT, lsHold;
static float lsY, lsV;
/* (an array, not literals: mod code has no .lit4) start gap, gravity / frame, bounce, settle speed, crash speed */
static float LS_F[5] = { 520.0f, 1.6f, 0.35f, 12.0f, 20.0f };
void tmbr_LoadScreenReset(void) { lsT = 0; }
void tmbr_LoadScreen(void)
{
    char *top, *bot;
    if (!shellPtr || lsT < 0) { uiLoadLevel(); return; }
    bot = *(char**)(shellPtr + 0xB950 + 0x20);
    top = *(char**)(shellPtr + 0xB950 + 0x30 + 0x20);
    if (!top || !bot) { uiLoadLevel(); return; }
    if (lsT == 0) { lsY = LS_F[0]; lsV = 0; lsHold = 0; }
    lsT++;
    if (!lsHold) {
        lsV += LS_F[1]; lsY -= lsV;
        if (lsY <= 0) {
            if (lsV > LS_F[3]) {                         /* impact: crash, bounce back a little */
                if (lsV > LS_F[4]) shellSfx(shellPtr + 0x1A16C, 0xD);
                lsY = 0; lsV = -lsV * LS_F[2];
            } else { lsY = 0; lsV = 0; lsHold = 1; }
        }
        if (lsT > 150) { lsY = 0; lsV = 0; lsHold = 1; }
    } else lsHold++;
    *(float*)(top + 0x18) = lsY; *(float*)(bot + 0x18) = -lsY;
    if (lsHold > 12) {                                   /* shut a moment: now the load */
        scePrintf("TMBR loading: halves shut after %d frames\n", lsT);
        lsT = -1;
        uiLoadLevel();
    }
}
int tmbr_UiPadButtons(int pad)
{
    static int prev, held;
    int b, pr;
    if (D_004FA684 != 0x29) tmbr_LoadScreenReset();   /* (loading screen crash: armed again outside the load) */
    { extern void tmbr_SingleFrame(void); tmbr_SingleFrame(); }   /* menu.c: single player flow */
    { static int lastUi = -1;                           /* UI state changes in the log (menu work) */
      if (D_004FA684 != lastUi) { lastUi = D_004FA684; scePrintf("TMBR ui: state %x\n", lastUi); } }
    if (naming) return 0;                              /* (the keyboard reads the guest's pad itself) */
    if (!picking) { extern int tmbr_MenuPad(int b); extern int tmbr_uiEat; held = 0; return tmbr_MenuPad(inputGetPadButtons(pad)) & ~(D_004FA684 == 0x25 ? tmbr_uiEat : 0); }   /* menu.c, modspage.c */
    if (D_004FA684 != UI_CARSEL) return 0;            /* still flying in */
    b = padBtn(2 * picking);
    if (b < 0) b = 0;
    if (held < 20) { held++; prev = b; return 0; }      /* the START that opened it */
    pr = b & ~prev; prev = b;
    if (pr & B_CROSS) { tmbr_GuestPickEnd(1); return 0; }
    if (pr & (B_TRI | B_CIRCLE)) { tmbr_GuestPickEnd(0); return 0; }
    return b & ~(B_CROSS | B_TRI | B_CIRCLE | B_START);
}
/* ---- guest names (Ark 2026-10-26): on joining, the game's own on-screen keyboard (the screen-name screen's,
 * func_001C1B78: keyboard D_004B3C00, text box objects like D_0045BDB8 - 0x70 bytes with a vtable at +0x68, the
 * text at +0) on the guest's controller, the name filled in as PLAYER n. Keyboard: func_0021A8F0(kb, box) opens,
 * func_0021AC78(kb) runs it (0xD2 / 0xC8 = closed: confirm / back), func_0021B1F8(kb) shuts it, func_002198B8(box,
 * x, y) draws the box. It reads controller 1 (inputGetPadButtons(0) at 0x21B8C4, the analog stick through
 * inputFixAnalogValue): those calls come here while a guest is typing (apply_mods.py). The name goes to the
 * guest's reserved net slot (+0x18, read by the scoreboard / kill feed) and its player list row. ---- */
extern char D_0045BDB8[];
extern char D_004B3C00[];
extern void kbOpen(char* kb, char* box) __asm__("func_0021A8F0");
extern int kbRun(char* kb) __asm__("func_0021AC78");
extern void kbClose(char* kb) __asm__("func_0021B1F8");
extern void boxSet(char* box, const char* t) __asm__("func_00219810");
extern void boxTrim(char* box) __asm__("func_0021A018");
extern void boxDraw(char* box, int x, int y) __asm__("func_002198B8");
extern int inputFixAnalog(int a, int b) __asm__("inputFixAnalogValue__Fii");
static char nameBox[0x80];
static int nameT;
static void nameStart(int k)
{
    int q;
    if (naming || D_004B3C00[0] | D_004B3C00[1] | D_004B3C00[2] | D_004B3C00[3]) {      /* (keyboard busy) */
        sprintf(guestName[k], "PLAYER %d", k + 1);
        return;
    }
    for (q = 0; q < 0x70; q++) nameBox[q] = D_0045BDB8[q];   /* a constructed text box (vtable, size) */
    sprintf(guestName[k], "PLAYER %d", k + 1);
    boxSet(nameBox, guestName[k]);
    kbOpen(D_004B3C00, nameBox);
    naming = k; nameT = 0;
    scePrintf("TMBR guests: controller %d types a name\n", k + 1);
}
int tmbr_GuestNaming(void) { return naming && D_004FA684 == UI_ROOM; }
/* the keyboard's own pad reads */
int tmbr_KbPad(int pad)
{
    int b;
    if (!naming) return inputGetPadButtons(pad);
    b = padBtn(2 * naming);
    return b < 0 ? 0 : b;
}
int tmbr_KbAnalog(int a, int b) { return naming ? 0 : inputFixAnalog(a, b); }
/* waiting room frame (bots.c tmbr_LobbyFrame, after the room's own frame) */
void tmbr_GuestsName(void)
{
    int r, k = naming, s, q;
    if (!k) return;
    if (D_004FA684 != UI_ROOM) return;
    {   /* the text being typed, above the keyboard */
        static const char* const t[4] = { "", "PLAYER 2 NAME", "PLAYER 3 NAME", "PLAYER 4 NAME" };
        fontSetColor(0, 0x50, 0x44, 0x2C);
        fontSetCursorAtSubPixel(0, 0x600, 0x8C0);
        fontPrint(0, t[k]);
        boxDraw(nameBox, 0x145, 0x96);
    }
    r = kbRun(D_004B3C00);
    {   /* START on the guest's controller = done (the keyboard's own way is its ENTER key) */
        static int prevS;
        int b = padBtn(2 * k), st = b > 0 && (b & B_START);
        if (nameT > 20 && st && !prevS) r = 0xD2;
        prevS = st;
    }
    if (++nameT < 20 || (r != 0xD2 && r != 0xC8)) return;
    kbClose(D_004B3C00);
    boxTrim(nameBox);
    if (r == 0xD2 && nameBox[0]) {
        for (q = 0; q < 15 && nameBox[q]; q++) guestName[k][q] = nameBox[q];
        guestName[k][q] = 0;
    }
    if ((s = joinSlot[k]) >= 0) {
        char* n = D_003156C0 + s * 0x220 + 0x18;
        for (q = 0; q < 15 && guestName[k][q]; q++) n[q] = guestName[k][q];
        n[q] = 0;
    }
    scePrintf("TMBR guests: controller %d is %s (%x)\n", k + 1, guestName[k], r);
    naming = 0;
}
/* car select frame (skins.c): title for a guest's pick */
void tmbr_GuestPickTitle(void)
{
    static const char* const t[4] = { "", "PLAYER 2", "PLAYER 3", "PLAYER 4" };
    if (!picking) return;
    fontSetCursorAtSubPixel(0, 0x1400, 0x500);
    fontPrint(0, t[picking]);
}
/* waiting room settings box line (bots.c extraLines): retired - the guests are rows in the player list now
 * (Ark 2026-10-26: a line per guest there would run P3 / P4 off the box) */
void tmbr_GuestsLine(char* b) { b[0] = 0; }
/* the waiting room's player list (func_001C5768 0x1C5C48..): a row per player slot in use (+0x10 != -1) from
 * y 0x500, 0x100 apart; name x 0x1E0, ping 0x1090, car 0x14A0, status 0x1F40. The guests are local only (their
 * slots stay empty for the network), so their rows are drawn after the list, in the same font. */
void tmbr_GuestsRows(void)
{
    int s, k, row = 0;
    char b[40];
    const char* me = myClient() ? myClient() + 8 : "";
    for (s = 0; s < 8; s++) if (F(D_003156C0 + s * 0x220, 0x10) != -1) row++;
    for (k = 1; k <= 3; k++) {
        int y;
        if (!joinCar[k] || row >= 8) continue;
        y = 0x500 + row++ * 0x100;
        fontSetColor(0, 0x44, 0x32, 0x20);
        if (guestName[k][0]) sprintf(b, "%.15s", guestName[k]); else sprintf(b, "%.12s P%d", me, k + 1);
        fontSetCursorAtSubPixel(0, 0x1E0, y); fontPrint(0, b);
        fontSetCursorAtSubPixel(0, 0x14A0, y); fontPrint(0, D_0041BF00[joinCar[k] >> 5]);
        fontSetCursorAtSubPixel(0, 0x1F40, y); fontPrint(0, "SPLIT");
    }
}
