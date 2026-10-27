# Guest respawn shield not animating - cause and fix

(TODO.md "Split screen ... Open: 1." - read-only research, 2026-10-26, TMBO addresses)

## Cause

Car animation (including the shield's UV-scroll channels) is not updated per vehicle, per view or per owner type.
It runs through **14 global animation managers**, one per loaded char set:

- `D_00465E68[14]` = animmgr pointers, registered at car/level load by `animationSetGlobal` (func_001FDF68,
  from the car loaders func_00127188 / func_00127330 / func_001274D0). Index 0 = level, index **k+1 = game vehicle
  slot k** (game + k*0x31B0).
- `D_00465EA0[]` = an **enable flag** per manager. Setter: `func_001FDE10(int enable, int idx)` (online_only,
  0x18 bytes: `D_00465EA0[idx] = enable`).
- `animationRunGlobal` (0x1FDDA0, called each frame from func_00174D78 0x174E90 / rtMain 0x1838E4) runs
  `animationManager` -> `animationUpdateActiveTree` -> channel values (instance +4) **only for managers whose flag
  is set**. pktAddVu1Obj then reads those values via scratchpad 0x70000020 (the instance) for pktClipUVScroll.
  If the manager is not run, the channel values never change, so the shield is drawn with a fixed UV offset.

Who sets the flags:

| Where | What |
|---|---|
| ui.s func_001C5768 0x1C7164.. (match start) | enable 0 (level) and 1 (P1 = slot 0), **disable 2..8** |
| gameMakeAI func_0013A7B8 0x13A850, **AI branch only** (`ai != 0`) | enable slot+1 |
| netObjCreateCB 0x169378 / 0x1693C0, func_001690F0 0x169200 | enable for remote net cars |
| func_0013EED0 0x13F068 (AI removal), func_0016F1C8 0x16F314 (net obj destroy) | disable |

The human branch of gameMakeAI (`ai == 0`, 0x13A94C..) never calls func_001FDE10. Guests are made with
`gameMakeAI(g, v, car, v, i, 0)` (guests.c:175), so their manager stays disabled from the match-start reset. P1
works because the UI enables index 1. **Bots** (bots.c:134, `ai = 1`) go through the AI branch, so their shields
(and other car anims) should animate. A check that Ark can do: bots' shields shimmer.

The shield switches (+0x2068/+0x206C via vehicleUpdateShields func_001DD0C8), owner type +0x20B4 and the
vehicle's animHandles are not involved. func_001DD708 (death/landing anims) and the Grim/Axle/launcher anim
handles found with animationGetHandle (func_001FBCF8, bank = car code (+0x20F4) + 0xE, id = +0x20F0) live in the same
manager, so those are probably frozen for guests too. The fix below covers them as well.

## Fix (guests.c, tmbr_GuestsMake, after `veh` is found, e.g. next to `guestCar[i] = veh;` at line 198)

```c
extern void animMgrEnable(int enable, int idx) __asm__("func_001FDE10");
...
animMgrEnable(1, (veh - g) / 0x31B0 + 1);   /* game vehicle slot k -> animmgr k+1 (as gameMakeAI's AI branch) */
```

Notes:
- Use the game slot of `veh` (`(veh - g) / 0x31B0`), the same `k` gameMakeAI uses (the slot whose +0x20F0 == v).
  It is not necessarily `v`.
- The match-start UI code (0x1C7164) runs before the guests are made, so the guests' flag is not cleared again.
  On a later rebuild after a level change, tmbr_GuestsMake makes the cars again, so this runs again too.
- If a guest is removed, `func_001FDE10(0, k+1)` can be called for symmetry (func_0013EED0 does this for AI).
  It is optional.
- Retail: func_001FDE10 has no retail match in mapping.csv (online_only). Related names: animationSetGlobal
  (retail 0x1BFE50), animationSetInstance (0x1BFC50), animationGetHandle (0x1BDC20).
