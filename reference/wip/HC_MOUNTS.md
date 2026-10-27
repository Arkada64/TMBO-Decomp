# Extra cars: weapon mounts on the new bodies (HC_MOUNTS) + Old Pickup's flamethrower (HC_FLAME)

2026-10-26. Code: `tools/lost/hcmounts.py` (new), used by `tools/lost/hcbuild.py` (6 Harbor City cars) and
`tools/lost/pakbuild.py` (12 Pak). Build scripts: `tools/lost/hc_buildall.sh` (unchanged), `tools/lost/pak_buildall.sh`
(new: both 12 Pak copies, `PAK_OWNWHEELS=1`, A = `PAK_ACAR=1`; with `HC_MOUNTS=0` it reproduces the earlier
`/tmp/claude-0/pak_own/out/ZY?.*` byte for byte).

## Where the donor's guns / weapons are (TMB car NGP)
- **Machine guns**: `op1 id 4100` = the gun model (one group, drawn twice) under two `op4` (left / right), each under
  an `op6` with id R+13 (attach type 13, `attachAdd` stores it at vehicle +0x2A54), in the high LOD, outside the
  body damage states. Roadkill: op4 0x5cdb0 t(-2.77 3.49 -1.48) / 0x5ce30 t(2.82 3.49 -1.48), switch id 45, gun
  0x680a0.
- **Weapon models** `op1 id 4001..4006` (+ specials 4011 Brimstone, 4028 Spectre) each under an `op3`/`op4` mount
  transform under an `op6` id R+7 (attach type 7: vehicle +0x2A20 + sub*4) whose **sub = weapon slot** (1 special,
  2 fire = 4001, 3 homing = 4002, 4 napalm = 4004, 5 pickup slot = 4005, 7 = 4003 (power / rico), 10 = 4006). They
  sit inside the weapon characters (op25 -> op17 bones; the launcher animations move them). op17 bones hold
  bind / inverse-bind matrices with identity rotation, their children are in model space at rest; the car tree
  instances the characters, sometimes under an op3 (Junkyard Dog's 4006: char under T(-1.67 4.43 -4.17)). So a
  mount's car-space rest position = op3/op4 transforms accumulated from entry point 0 (`hcmounts.donor_mounts`).
- Load path checked in the asm: car nodes go through dbProcInteractive (`func_00127650`): ids < 1025 ->
  `attachAdd` (type = id - R); ids 4000..4069 -> `func_001F1DB8` (a table at TheGame +0x6C310, first one wins);
  4100 is not registered at load. No gun offsets in the exe data (Roadkill's 2.77 / 3.49 / -1.48 floats are not
  there), so the shots come from the model's nodes; **which node exactly (the mount transform / the 4100 / 400x
  group's drawn matrix) is not proven** - moving the mount transform moves both, so either way the shots follow.

## Head-On mount list (BDD ngp)
An op5 near the root (Thumper 0x340, Outlaw 2 0x310, Twister 0x370, 12 Pak 0x320, Gold Tooth / HC Sweet 0x350):
kid 0 = op8, kid i = **slot i // 2** (slot 0 and 7: one entry, 1..6: two); op3 entries carry their slot in the sub
field and the point at +0x10 (same car space as the meshes); op1 / op31 entries have no point. Slot meanings seen:
- slot 0 = special (Thumper (−0.24 7.96 1.82) at the nose = fire breath; Outlaw 2 (0 0.12 5.0) = roof turret)
- **slot 6 = machine guns** (Thumper ±2.33 7.05 1.74: inside its two gun-barrel meshes 0x30150 / mirror)
- slot 4 = a pair ~3.5 ahead of / beside the guns (Thumper ±2.35 10.63, past the bumper): fire point or 2nd gun
- slots 1 / 2 / 5 = rear / side launchers, 3 = rear (or front) centre low, 7 = roof centre
- Old Pickup and Pit Viper (fan-build, near-static) have **no list**.

## What the builds do (HC_MOUNTS, default 1)
- Machine guns: Head-On slot 6 if it is a real left / right pair, else slot 4 (mirrored when both entries are one
  side), else a per-car table (Pit Viper: the outer front bumper bars, ±1.31 7.30 0.0), else the box map.
- Other mounts (4001..4006, specials): **box map** = the donor position relative to the donor's body box (state 0,
  1st..99th percentile, x symmetric) goes to the same relative spot of the new body box (kept state-0 meshes, --add
  parts excluded). This keeps the donor's launcher layout, which its rise / unfold animations expect.
  `HC_MOUNTS=ho` puts them on guessed Head-On slots instead (special 0, fire 1, homing 2, napalm 3, pickup 5,
  4003 / 4006 -> 7); this lands some below the body (Thumper fire at z −3.5), so it is not the default.
- `HC_MOUNTS=mg` guns only, `0` off; `HC_MG_SLOT=4|6` forces the gun slot; `HC_MOUNT_POS='4100:x,y,z;4001:x,y,z'`
  sets Head-On-space points by id (4100 = right gun, left mirrored).
- Head-On -> donor space: hcbuild `p * s + (0, dy, dz)` (own wheels: s 1, dy 0, dz = ground match);
  pakbuild `p * scale + (0, 0, LIFT)` (LIFT 0.517). The move adds (target − rest) to the mount's own translation
  (op3 +0x10 / op4 +0x40) in its parent's frame; read back from the built NGPs = the targets.

### Per car (P copy, donor model space; the A copy is within 0.1)
| car (file) | mount | donor rest | new | from |
|---|---|---|---|---|
| Thumper on Brimstone (ZUP) | 4100 L / R | (∓3.06/3.10, 3.49, −1.61) | (∓2.33, 7.05, −1.23) | HO slot 6 |
| | 4001 / 4003 (front L/R) | (−2.68 5.60 0.62) / (2.79 5.65 0.56) | (−1.86 5.26 −0.63) / (1.93 5.30 −0.68) | box |
| | 4002 / 4004 / 4005 / 4006 | (−2.76 −4.54 −0.31) / (0.11 −6.51 3.73) / (5.59 −9.03 −0.71) / (−1.03 −1.49 −0.10) | (−1.91 −3.87 −1.38) / (0.08 −5.64 1.87) / (3.88 −7.91 −1.70) / (−0.72 −1.13 −1.21) | box |
| | 4011 special | (0 10.57 0.72) | (0 9.73 −0.55) | box |
| Outlaw 2 on Crazy 8 (ZVP) | 4100 L / R | (−3.05/3.15, 3.28, −2.34) | (∓3.29, 9.15, 0.46) | HO slot 4 mirrored (slot 6 has no point) |
| | 4001..4006 | rear (0 −5.63 −0.83) ... | within 0.5 of the donor's (same-size body) | box |
| Old Pickup on Junkyard Dog (ZXP) | 4100 L / R | (∓4.92/4.97, 4.45, −3.31) | (∓3.47/3.50, 3.81, −3.25) | box (no HO list) |
| | 4001 / 4002 / 4003 | (−4.28 −5.01 0.81) / (−3.48 −5.01 0.84) / (−3.88 −4.84 0.06) | (−3.02 −3.89 0.73) / (−2.45 −3.89 0.76) / (−2.73 −3.76 0.00) | box |
| | 4004 / 4005 / 4006 | (3.83 −7.53 0.74) / (12.97 −6.67 −0.72) / (−3.95 0.65 −1.37) | (2.70 −5.95 0.66) / (9.14 −5.25 −0.75) / (−2.78 0.72 −1.38) | box |
| Pit Viper on Spectre (ZWP) | 4100 L / R | (∓3.41, −1.63, −0.79) | (∓1.31, 7.30, −0.48) | table (front bars) |
| | 4001..4006, 4028 | e.g. 4028 (2.62 1.70 0.72), 4005 (0.03 −5.68 1.29) | (2.01 1.63 1.01), (0.02 −4.76 1.61) | box |
| Twister on Outlaw (ZTP) | 4100 L / R | (∓3.41/3.35, 3.03, −2.02) | (∓1.79/1.74, 2.80, −1.67) | HO slot 6 |
| | 4001..4006 | e.g. 4005 (−0.73 −9.62 0.82), 4006 (−2.30 −3.78 2.80) | (−0.47 −6.44 −2.24), (−1.47 −2.00 −1.17) | box (Twister sits ~3 lower than Outlaw) |
| Gold Tooth on Sweet Tooth (ZZP) | 4100 L / R | (∓4.19/4.16, 3.55, −2.90) | (−4.05 / 4.20, 5.04, −0.60) | HO slot 6 |
| | 4001 / 4003 / 4006 | (1.83 −9.84 0.34) / (−3.04 0 2.55) / (1.35 −0.20 2.59) | (1.57 −8.14 −0.41) / (−2.61 −0.11 1.21) / (1.16 −0.27 1.24) | box |
| 12 Pak on Roadkill (ZYP) | 4100 L / R | (−2.77/2.82, 3.49, −1.48) | (∓3.09, 7.02, 2.28) | HO slot 4 mirrored (slot 6 = one side gun) |
| | 4001 / 4002 | (−2.58 −6.07 0.49) / (2.64 −6.25 0.51) | (−2.80 −5.95 0.04) / (2.86 −6.12 0.06) | box |
| | 4003 / 4004 / 4005 / 4006 | (1.09 −2.25 0.13) / (0 −6.00 −0.17) / (0.07 −5.12 0) / (2.82 5.90 0.80) | (1.18 −2.44 −0.35) / (0 −5.89 −0.67) / (0.07 −5.08 −0.49) / (3.06 5.03 0.38) | box |
Full lists: `grep '^mount' /tmp/claude-0/hc_*/build_Z*.log /tmp/claude-0/pak_own/build_ZY*.log`.
pakbuild's PAK_MOUNTS translate of the antenna / rack characters is unchanged (separate from these mounts).

## Old Pickup's flamethrower (HC_FLAME, default 1 for PICKUP.BDD)
- It is not a separate mesh: the roof gun (barrel x 1.1, y −1.9..4.85, z 5.6..6.2; fuel cylinder x 1.5..2.1,
  y −4.2..−1.9; hose back to a bed tank at y −7.7, z 3.8; vertical post at y −1.9) is part of the one body mesh
  0x8c30 (2393 verts, strips run across the whole truck). hcbuild kept it, static, before this change.
- Now: the 160 triangles inside box x 0.6..2.2, y −4.3..5.0, z 5.3..6.5 (barrel + cylinder; post and hose stay on
  the body) are cut out of 0x8c30 (`hcmounts.split_mesh`, winding kept, rest = 2602 triangles) and go into an
  **op6 switch, id R+7 = 263, sub 9** (JD uses subs 0,2,3,4,5,7,10), shared by the 3 damage states, 5 frames:
  frame 0 = straight ahead (= the model as before), 1 = +20°, 2 = +40° (to the left), 3 = −20°, 4 = −40° (right),
  turned about the vertical axis through the post (Head-On x 1.1, y −1.9 = donor space, own-wheels s 1, dy 0).
  The game registers it at **vehicle +0x2A20 + 9*4 = +0x2A44**; nothing drives it, so it shows frame 0.
  The far LOD gets the split body + frame 0. Cost: NGP +21 KB (ZXP 408,448 B, donor 517,472).
- Rejected: hanging it on a Junkyard Dog animated character (pakbuild-style). JD's weapon characters animate
  launchers rising / unfolding for their own weapons, not a turret aiming, and the piece would only move while one
  JD weapon animates.
- **Recommended code hook** (mods/skins.c style, like `pakHatches`): every frame for a car whose model is ZXP/ZXA,
  `sw = *(int**)(v + 0x2A44)`; if set, take the bearing to its target (AI target, or the nearest enemy in a front
  cone for humans) in car space (x right, y forward): `a = atan2(-dx, dy)` (+ = left); pick 0 for |a| < 10°,
  1 / 3 for 10..30° left / right, 2 / 4 beyond; step at most one frame per ~4 game frames (like the hatches) and
  `hierSetSwitch(sw, frame)`. More frames / pitch would need a rebuild (FLAME_YAW in hcmounts.py; each frame
  ~5 KB). A true per-frame rotate would need an op4 node + matrix writes at draw time; the switch avoids that.
  Flames themselves still come from Junkyard Dog's own weapons; pointing a fire effect from the barrel tip
  (Head-On x 1.1, y 4.85, z 5.9 -> donor z 5.9 + dz −1.17) is a separate hook.

## Needs an in-game check
1. Machine-gun tracers start at the new gun spots for all 7 (and the donor's gun models, kept by hcbuild, now sit
   there; they may poke through Head-On's own gun meshes). If shots still come from the old spots, the fire origin
   is not the mount transform: then the 4100 group / switch is the next suspect.
2. Slot 6 vs 4 for the guns: Thumper / Twister / Gold Tooth use 6, Outlaw 2 / 12 Pak fall back to 4 (12 Pak:
   z 2.28 = ~0.2 above the hood; its own gun meshes 0x459c0 / 0x46060 at x ±2.5, y 5, z −1.5 are outside the built
   model). `HC_MG_SLOT=4` / `HC_MOUNT_POS` if one looks wrong.
3. Launchers (box map): missiles leave from the new body and the rise / unfold animations still look sane;
   Junkyard Dog's 4005 (rest x 12.97, outside the body at rest) -> 9.14 on the Pickup is the odd one.
4. Old Pickup: body with the flamethrower cut out has no holes / flipped faces (frame 0 = old look); the switch at
   +0x2A44 is non-null in game.
