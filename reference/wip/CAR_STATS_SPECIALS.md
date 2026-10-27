# Car stats, specials and 2-/4-wheel physics (research, 2026-10-26)

Read-only research for the skins / extra-characters mod (mods/skins.c). All addresses are **online (TMBO)**
unless marked *retail*. Retail names come from /home/claude/retail/asm and reference/match/mapping.csv.
Car value = vehicle +0x20F4 = type << 5 (retail +0x20A8).

Offset shifts retail -> online in the regions used here: vehicle dynamics block +0x10 (retail 0x300..0x428 ->
online 0x310..0x438; retail 0x1F30.. -> online 0x1F40..), vehicle kind 0x580 -> 0x590, player slot index
0x20A4 -> 0x20F0, launcher 0x2140 -> 0x21B0, inside the launcher the Axel fields are +0x10 (0x338 -> 0x348,
0x330 -> 0x340) and the Axel animation handle 0x91C -> 0xCE8.

## 1. Driving stats: hard-coded per type in vehicleInitDynamics

There is **no stats table in data**. `vehicleInitDynamics__7Vehicle` (*retail* 0x1A4238, size 0x3DDC; **online
func_001D72D8**, not in mapping.csv) is one big `switch (v->carValue)` (online +0x20F4) whose cases store
float immediates (lui/ori) straight into the vehicle. Cases: 0x20..0x1E0 (the 15 cars) plus 0x200, 0x220,
0x8F0/0x910/0x930 (shared case), 0x950 and a default (traffic / boss / other).

Order of operations in **vehicleInit = func_001D6F78** (runs on every spawn and respawn: called from
netObjUpdateVehicleCB, func_0016C488, func_0017BDD8, aiInit, the fodder inits):

| call site | callee | what it does |
|---|---|---|
| 0x1D7020 | func_001D72D8 vehicleInitDynamics | writes every per-type stat below |
| 0x1D7088 | vehicleRecomputeDeltas(v, 1) | derives the working values (0x314, 0x324, 0x344, 0x34C, 0x360, ...) from base fields 0x310/0x320/0x340/0x350/0x364/0x380/0x3CC/0x3F8, scaled by the frame rate |
| 0x1D7160 | collisInitPoints | builds the collision / tire contact points (v+0x5D0..0x720, tireDat at v+0x1AA0 stride 0xF0) from the geometry fields 0x3A4..0x3E4; **has its own Grimm (0x140) branch** |
| 0x1D7178 | func_001518A0 InitLauncher (l = v+0x21B0) | launcher, per-type launch offsets, animations (group = car value + 6) |
| after | 0x180 tankCarInit / 0x140 grimInit / 0x160 axleInit | per-type extras |

The tail of func_001D72D8 also derives: 0x404 = 0x400 (current health = max), 0x418 = 0x41C, destructible HP
shorts at (*(v+0x2084))+0x10 -> +0xA and (*(v+0x2088))+0x10 -> +0xA = (int)0x400, centre point 0x3DC..0x3E4
(Grimm: = 0x3B4..0x3BC; others: blend of 0x3B4.. and 0x3C8..), 0x3CC = 0x3E0 - 0x3E4, 0x3D8 = 1/0x3D4,
0x33C = 0x338 * 0x574, 0x3F8 = 1.0, then smoothInit(v+0x2B0, v+0xE8, v+0x200, ...).

### Per-type values (online offsets, extracted from func_001D72D8)

Field names are inferred from who reads them (retail readers, offset -0x10); "?" = not pinned down.

| off | meaning (inferred) | RK | YJ | Outlaw | Spectre | Crazy8 | SweetT | Brim | JDog | Shadow | Grimm | Axel | Warthog | Darkside | Mansl | Minion |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0x310 | engine / accel constant (?) | .0537 | .0595 | .0693 | .0556 | .0537 | .0537 | .0576 | .04 | .0693 | .0420 | .0693 | .04 | .0529 | .0517 | .0712 |
| 0x320 | top speed | 185 | 185 | 175 | 190 | 185 | 175 | 185 | 170 | 175 | 195 | 185 | 170 | 175 | 172 | 170 |
| 0x350 | turn rate / handling | .0478 | .0392 | .0440 | .0525 | .0402 | .0468 | .0478 | .0364 | .0573 | .0516 | .0478 | .043 | .0335 | .0288 | .024 |
| 0x368 | grip / slide (?) | .75 | .75 | .75 | .95 | .75 | .65 | .75 | .65 | .75 | .75 | .95 | 1 | .55 | .75 | .75 |
| 0x374 | peel-out / tilt angle (rad) | .175 | .175 | .140 | .105 | .209 | .244 | .105 | .140 | .192 | .035 | .052 | 0 | .105 | .070 | .070 |
| 0x380..0x394 | suspension (susp* readers) | | | | | | | | | | | | | | | |
| 0x3A4 | ride height (centre to ground, used by vehicleSetToPosition) | -2.66 | -2.66 | -4.67 | -1.4 | -2.92 | -5.19 | -2.92 | -5.86 | -2.89 | -2.64 | -5.96 | -5.12 | -5.30 | -4.5 | -4.40 |
| 0x3A8/AC/B0 | collision radius (collisInitPoints) | 2.4 | 2.08 | 4.6 | 2.5 | 1.6 | 4 | 2.5 | 5.3 | 2.7 | 3.6 | 6 | 4.2 | 8 | 11.2 | 9.28 |
| 0x3B4 | half track (tire x) | 3.2 | 3.1 | 3.70 | 3.2 | 2.81 | 3.6 | 2.75 | 4.1 | 3.40 | 2.3 | 5.48 | 3.9 | 5.94 | 5.5 | 4.7 |
| 0x3B8 / 0x3BC | front / rear axle y | 5.38/-5.20 | 4.32/-5.0 | 5.79/-5.09 | 5.02/-3.69 | 5.68/-4.95 | 6.48/-5.6 | 6.17/-4.74 | 7.75/-7.35 | 5.22/-5.91 | 3.5/-3 | 5/-5 | 6/-6 | 10.97/-16.17 | 6.4/-13.4 | 6.8/-22 |
| 0x3C0 / 0x3C4 / 0x3C8 | bumper y front / rear, length-ish | | | | | | | | | | | | | | | |
| 0x3D0 / 0x3D4 | height points | | | | | | | | | | | | | | | |
| 0x3E8 / 0x3EC | tire / hit-point params (default 2.3 / 3) | | | | | | | | | | | | | | | |
| 0x400 | max health | 100 | 110 | 110 | 95 | 100 | 145 | 105 | 135 | 110 | 95 | 116 | 145 | 150 | 155 | 160 |
| 0x41C | mass (copied to 0x418, read by collisGetRelativeMass) | .12 | .12 | .3 | .08 | .08 | .25 | .12 | .3 | .13 | .05 | .2 | .7 | .75 | 1 | 1 |
| 0x424 / 0x428 | drift / turn params | .03/.025 (Sweet Tooth, Shadow .02/.023) | | | | | | | | | | | | | | |
| 0x430 | turn (vehicleUpdateTurn) | 2.35 | 2.3 | 2 | 1.5 | 2.5 | 2.4 | 2 | 1.7 | 2 | 2.15 | 2 | 3 | 2.35 | 2 | 2.35 |
| 0x434 | max steer (2.007 for all) | | | | | | | | | | | | | | | |
| 0x438 | drift (vehicleUpdateDrift) | 8 | 6 | 6 | 11 | 8 | 15 | 8 | 15 | 6 | 8 | 10 | 14 | 15 | 10 | 10 |
| 0x478 (int) | skid trail / tire-set count | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 1 | 32 | 2 | 2 | 2 |
| 0x1F40..0x200C | chase-camera presets (dist, height, pitch) x N, walked by the camera (retail camera.s 0x113214..) | model-size dependent | | | | | | | | | | | | | | |

Constant for every car: 0x338 = 0.14, 0x354 = 0.0005, 0x360 = 0x364 = 0.02. Minion also writes ints
0x408..0x414 (32, 5, 25, 25). The full table (all fields, all 15 cars) can be regenerated from the asm; the
extractor was a throw-away script (lui/ori/mtc1 -> swc1 tracking per case label).

Health / armor: there is no separate armor stat; "armor" is max health 0x400 (plus mass 0x41C for ramming).

### Giving car type X the stats of type Y (e.g. Outlaw model, Grimm stats)

Do not change +0x20F4 permanently: ~30 functions switch on it (see section 3), including the special,
animations, sounds and Grimm's bike code. Instead hook the **jal func_001D72D8 at 0x1D7020** in vehicleInit
(covers respawns too) with a wrapper:

1. call func_001D72D8(v) with the real type X and save the geometry fields;
2. set v+0x20F4 = Y, call func_001D72D8(v) again, set v+0x20F4 back to X;
3. copy X's geometry back: 0x380..0x394 (suspension), 0x3A4..0x3E4 (ride height, collision radii, axle /
   bumper geometry, centre point and the derived 0x3CC/0x3D8), 0x3E8/0x3EC, 0x478, 0x1F40..0x200F (camera).

Kept from Y: 0x310, 0x320, 0x340, 0x350, 0x354, 0x360..0x374, 0x400 (+0x404 and the destructible HP shorts,
already written by the second call), 0x41C (+0x418), 0x424..0x438. No extra call is needed:
vehicleRecomputeDeltas (0x1D7088) and collisInitPoints (0x1D7160) run after the hook and derive from the
final fields. If instead you patch after vehicleInit returns, also call vehicleRecomputeDeltas(v, 1).

Network: every client runs vehicleInit for every car (netObjUpdateVehicleCB), so the wrapper must decide from
the synced skin state (as isPak() does), or health bars / masses differ per console.

## 2. Specials

No per-type special table either. Ammo/energy is the same for all cars: InitLauncher (func_001518A0, 0x15199C..)
sets slot counts at launcher +0x188 + 4*slot (slot 1 = special = 1, slots 2/3 = 2) and recharge timers
+0x21C / +0x228 / +0xD4 from D_004F9B08 / D_004F9B0C / D_004F9B04 (x 60). Using a special calls
DecrementWeaponCount = func_001F1AE0(D_004FA030 + 0x6C310, v, 1).

The weapon is chosen in code: **FireSpecial__8LauncherP7Vehicle (0x157D50)** switches on +0x20F4, and timed / held specials continue in UpdateSpecial__8LauncherP7Vehicle (0x15CD80).
Weapon object types created per car (from *retail* FireSpecial): Roadkill 0x11 (charger), Yellow Jacket 0x12,
Outlaw 0x14, Spectre 0x15, Sweet Tooth 0xD, Brimstone 0x17, Shadow 0x19, **Axel 0x1B**, Minion 0x1F; Crazy 8
(pulse), Junkyard Dog (wrecking ball / tow), Mr. Grimm (animation, 0x1593B0), Warthog, Darkside (ram),
Manslaughter (dump) are animation / UpdateSpecial driven.

### Axel

Online FireSpecial case 0x160 (0x158F88) clears launcher +0x350 and calls **func_001599A0(l, v)** (online-only
helper):

* `if (l+0x27C) return;` (a timed special is running)
* **launcher +0x348 != 0** -> the *alternate* special, "axle smash": +0x280 = 300 frames, +0x27C = 1,
  +0x340 = 2, animationStart(l+0xCE8) (Axel's wheel animation), func_0018F5F0(l+0xB38) (playAxleAnimationSound).
  +0x348 is set only by vehicleCheckForCombos from the combo byte (*retail* v+0x593 copied to v+0x2478 = launcher+0x338; the online offsets were not checked), i.e. a
  button combo. Damage comes from collisAxleSmash (car-to-car contact), and UpdateSpecial ends it (reverse
  animation, decrement, clear +0x348). This is tied to Axel's model animation and his collision code.
* **otherwise (the plain special press) = the primary: Shockwave.** Only on the owning console
  (v+0x20B4 == 1 or 4): CreateWeapon func_001ED8D0(D_004FA030+0x6C310, **0x1B**, v, 0, 0), sound
  func_00194D78(v+0x2AD0, v+0x1D0) (triggerAxleShockWaveSound), func_001F1AE0(weapons, v, 1), l+0x94 = 0, l+4 = 0.

So the primary is a normal weapon object (type 0x1B) that any launcher can create, **but** InitWeapon
(func_001EE038, case 0x1B ~line 1737) starts with
`node = D_0045FFD8[v->slot (v+0x20F0)]; if (!node) return;` and only then sets damage (D_004FAD00, halved for
non-players), duration (D_004FAD08), range (D_004FAD04), calls DetonateWeapon (func_001F0EE0), attaches the node
(hierSetCsEpNode) and starts animation D_00460000[slot] (stride 0xC, animation id 0xFB0).
D_0045FFD8 (*retail* axleShockWaveScale) is filled by AddWeaponEpNode (db loader -> Weapons::AddWeaponEpNode,
EP id **0xFB0**, index from the node's flag bits) when a model carrying that EP node is loaded for that slot,
and cleared by InitWeaponsAfter. Most likely that node lives in Axel's car file; not verified (no Axel files on
disk here).

To give car X Axel's shockwave (in tmbr_FireSpecial, like 12 Pak's reticle): when the special is pressed and
l+0x27C == 0 and special ammo > 0, run the shockwave branch above yourself instead of fireSpecial(). Make sure
D_0045FFD8[slot] is non-null **on every client** (the weapon is networked and each client runs InitWeapon):
either put the EP node 0xFB0 (copied from Axel's model) into the skin's car files, or point D_0045FFD8[slot] at
a loaded hierhead before creating the weapon. With a null entry the weapon does nothing (no damage, no visual).
Skip the smash (+0x348) branch: it needs Axel's wheel animation.

## 3. 2-wheel vs 4-wheel

Physics contact does not come from the model: collisInitPoints builds four contact points / tireDat records
from the per-type geometry (0x3A4..0x3D4), so Grimm drives on four virtual points 2.3 apart. The model's tire
nodes only drive visuals: attachAdd (0x10AF20..) attach kinds 1..4 -> attachAddTire func_0010B2A8 ->
tireDat[k-1].node = v+0x1AA0 + 0xF0*(k-1), radius node+0x48 -> +0x80; kinds 3/4 with a sub-index ->
v+0x1ED0 / v+0x1ED4 (extra rear wheels). Tire nodes are null-checked (suspCheckTireRotation 0x1AB260), so
missing wheels are skipped, not crashes.

Code that branches on +0x20F4 == 0x140 (Grimm) and would act on any model while the type is 10:
vehicleInit (grimInit 0x13FD88: animations group 0x146 ids 0x1A/0x1B.., null-checked), vehicleInitDynamics
tail, collisInitPoints, vehicleUpdateAnimations func_001DD708 (grimUpdate 0x13FF38 / axleUpdate 0x110DC8),
tireUpdateTires 0x1ACF98 and tireCalcLastRotChange (tire spin pairs), suspCheckTireRotation 0x1AB260 and
suspCheckPitchAndRoll 0x1AACF0 (bike lean), vehicleUpdatePitch 0x1DEFB0, vehicleUpdateRollingCar 0x1E1398,
skidmarkUpdateVehicleSkidmarks 0x18D5C8, attachAdd (kind 0x1E node -> v+0x1ED8 for Grimm/Manslaughter/Minion),
func_001E3800 / SetCarOnFire, driverInit 0x12E2E0, FireSpecial / UpdateSpecial / Start/ReverseAnimation,
animation sounds, AI (aiUpdateAttack, aiTurnAndShoot 0x102948, aiDelayAfterFireWeapon 0x1076E8), net
func_00172A90 / func_001E55A0.

Consequences:
* Keeping the model's own type (the section 1 approach) avoids all of these: a 4-wheel Outlaw with Grimm's
  numbers stays a car in every branch. Only the borrowed numbers change; do not borrow Grimm's geometry
  (ride height -2.64 vs Outlaw -4.67 would sink the body, track 2.3 vs 3.7 would leave the wheels outside the
  contact points) or Grimm's tiny mass 0.05 unless that is wanted.
* Setting the type itself to 10 on a 4-wheel model: bike lean / pitch, Grimm's tire-spin pairing (some wheels
  would not spin or steer), Grimm's collision points, no handlebar / airborne animations (null handles), and
  Grimm's special code against a model without his animations.
* A 2-wheel model on a 4-wheel type: physics is fine, the missing tire nodes are skipped, but there is no lean
  and the bike is not tilted. Usable for a skin, it just looks like a balanced 4-point vehicle.

## 4. Borrowed specials, implemented (mods/skins.c, 2026-10-26)

Requirements (Ark): Twister = Axel's shockwave, Thumper = Warthog's special, Old Pickup = Minion's special
(nerfed, front arc only), Outlaw 2 = Crazy 8's and Pit Viper = Spectre's (their donors' own, unchanged).

### How specials are reached (TMBO)
* Local press: func_001549A0 (launcher update) -> func_00156E08 (FireCurrentWeapon, slot 1) -> **0x157D10** jal
  FireSpecial (hooked: tmbr_FireSpecial). This is the only local call site.
* Network replay: netWeaponCreateCB **0x16B0CC** calls FireSpecial for message id 0x1E0 / type 1 (Minion) and
  func_00159C98 (Warthog) for id 0x180 / type 1 directly. The message id is the sender's +0x20F4 at send time
  (func_00171818 reads w+0x130 = vehicle).
* Per frame, outside FireSpecial, keyed on +0x20F4 in func_001549A0: 0x60 Outlaw **0x155B84 func_0015FCA8** (special
  selected + ammo: turret auto-aim + targeting laser / laser sound), 0xE0 Brimstone 0x155BC8.. (anim 0xFAB),
  0x100 JD 0x155D20 UpdateTowTruck, 0x1E0 Minion 0x155D3C func_00160D80 (turret aim), and **0x155D84 UpdateSpecial**
  while launcher +0x27C is set (timer +0x280).

### Twister (what was wrong)
The FireSpecial hook sent Twister to twisterSpecial, but Outlaw's own special code still ran for him outside
FireSpecial: func_0015FCA8 every frame while the special is selected (Outlaw's turret targeting / laser sight and
laser sound). A shockwave with a null D_0045FFD8[slot] does nothing, so all that was visible was Outlaw's. Also,
if vehSkin() failed at fire time, tmbr_FireSpecial fell through to Outlaw's FireSpecial (turret bursts, weapon
0x14). Fixes: hook 0x155B84 -> tmbr_OutlawAim (skipped for Twister); vehSkinF() = vehSkin with a per-vehicle
fallback recorded at vehicleInit (tmbr_SkinAtInit) so an extra never falls through to its donor's special;
tmbr_ShockFix (D_0045FFD8[slot] null -> copy node + D_00460000 anim from slot 4, else any filled slot) at
vehicleInit, before each shockwave and every frame (tmbr_SkinsFrame) on every console. Log lines:
"Twister shockwave (slot N node X)", "shockwave node for slot N from slot M".

### Warthog's special (for Thumper)
TMBO / retail: Warthog ("tank car", 0x180) special is a **flame torch**, not missiles: FireSpecial case 0x180 ->
func_00159C98 (owner only): +0x27C = 1, +0x280 = D_004F9B9C (3) * 60, particle fx 0x48 from the special mount
(launcher +0x640), net message (id 0x180); UpdateSpecial case 0x180 (0x15E560): ray hits forward, damage
D_004F9B94 (1, doubled by a 0x20E0 test), SetCarOnFire, sound updateTankCarTorchSound, decrement at the end.
No turret node needed. Thumper: FireSpecial and UpdateSpecial run with +0x20F4 = 0x180 for the call
(borrowIn / borrowOut); remote consoles replay it via the id-0x180 message and run UpdateSpecial borrowed too.

### Minion's special (for Old Pickup)
FireSpecial case 0x1E0 (0x159434): needs |roll| < 90 deg; +0x27C = 1, +0x280 = 0xF0 (4 s); lock-on
func_0015AE98 -> +0x2F8 (vehicle) / +0x300 (its hier); target within 250: torch (particle 0x48, +0x284 = 1,
net message id 0x1E0); else cannon shell weapon 0x1F (InitWeapon: damage D_004FAD84 = 5) every rand(20..65)
frames (+0x98). UpdateSpecial case 0x1E0 (0x15EE28): torch hits (D_004F9B94 per hit, 50 %/frame), shells,
decrement + terminateMinionTorchSound at the end. Per-frame turret aim func_00160D80 (UpdateMinion): angles
+0x290..0x298 relative to the car (pitch clamped +-20 deg), matrix written to *(launcher+0x2A0)+0x10. Turret
pivot / muzzle: launcher +0x5E0 / +0x5F0 (Minion-only fields). attachAdd: kind 0x1F -> v+0x2450 (= launcher
+0x2A0) for Minion; for Junkyard Dog +0x2A0 is the tow arm (kind 0x1E) and +0x290.. its angles, used by
UpdateTowTruck (towing branch when +0x27C is set uses +0x2A4).

Old Pickup implementation: borrowIn swaps id 0x1E0, its own turret matrix (pkNode, identity at first) into
+0x2A0, its own angles into +0x290..0x298, writes +0x5E0 = (1.1, -1.9, 4.73) roof-gun post, +0x5F0 = (0, 6.75, 0)
muzzle (HC_MOUNTS.md HC_FLAME numbers), D_004FAD84 = 3 for the call. Calls: FireSpecial (tmbr_FireSpecial, and
tmbr_NetFireSpecial at 0x16B0CC for the remote replay), UpdateSpecial (0x155D84 tmbr_UpdateSpecial), turret aim
func_00160D80 from the JD tow hook (0x155D20 tmbr_UpdateTowTruck, which then runs UpdateTowTruck with +0x27C hidden).
Front arc: Minion's three lock-on calls (0x1594A8, 0x15EE50, 0x160E28 -> tmbr_MinionLockOn) return no target while
an Old Pickup call is running when the target is outside +-45 deg of straight ahead (x right / y forward from the
car matrix rows at hier +0x20). Without a target in the arc Minion's code fires the shell straight ahead.

Nerf (Old Pickup vs Minion): duration 120 frames (2 s) instead of 240 (half the torch damage per special; the torch
hit is D_004F9B94 = 1, cannot be halved); cannon shell damage 3 instead of 5; shell interval doubled (40..130
frames instead of 20..65). Roof flamethrower switch (+0x2A44, op6 263 sub 9): frame from the target's bearing
while +0x27C is set (0 ahead, 1/2 = 20/40 deg left, 3/4 = 20/40 deg right), one 20-deg step per 4 frames, back to
0 afterwards (tmbr_SkinsFrame -> pickupTurret).

### Needs an in-game check
1. Twister: special press shows the shockwave (log line node != 0), no Outlaw laser while the special is selected.
   Outlaw's turret pop-up animation / sound on selecting the special (weapon toggle, func_00156118) still runs.
2. Thumper: flame torch from Brimstone's special mount (+0x640) for 3 s, damage + fire on cars in front; the
   torch sound (Warthog's LauncherSound) may need Warthog's sound bank. Same on the other console.
3. Old Pickup: torch from the roof gun (pivot / muzzle sign of x: if the flame starts on the wrong side, flip
   PK_OFS[0]); no target outside +-45 deg; switch turns the right way (if mirrored, swap frames 1/2 with 3/4 in
   pickupTurret); JD's tow arm is not disturbed; the other console sees the torch (remote replay id 0x1E0).
4. Remote damage of the halved shell: InitWeapon on the other console (network-created) uses the full D_004FAD84.
