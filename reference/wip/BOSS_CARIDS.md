# Boss car ids 0x200 / 0x220 for AI slots (research, 2026-10-26)

Read-only asm reading. Source: the local TMBO asm copy at /home/claude/tmbo/asm, which is the same tree as WSL `tmbo_decomp/asm`.
Slots are D_003156C0 + s*0x220. Slot +0xB4 holds the car value (index << 5).

## 1. Where AI slot cars come from at level load

### The level load does not read slot +0xB4 for other slots
- `func_00186730` 0x186AF8 calls `func_00188248(shell, a1)`, the level/car load. This jal is already hooked to `tmbr_LevelLoadCars`
  (guests.c).
- At 0x1882A0..0x1882B8 it copies **D_00313F00[0..7] -> D_003F6E08[0..7]**.
- At 0x188510 it calls `func_00188FE8(shell, myClient, a2=1)`. For every slot except mine (0x189028 loop, 8 slots) that calls:
  - `func_00189268(shell, s, 1)`, which loads the car model (rtx).
  - `func_00189478(shell, s, 1)`, which loads tex.
  - `func_00189680(shell, s, 1)`, which loads ngp.
- With a2 != 0 each loader takes the car from **D_003F6E08[s]**, not slot +0xB4:
  - 0x189298..0x1892B4 in `func_00189268`, with the same pattern in the other two.
  - The slot +0xB4 read (0x1892C4) is used only when a2 == 0, which is the reload path `func_0018A930`.
- The only range check is `slti car>>5, 0x12` at 0x189308 (and at 0x1894E8 / 0x1896F0 / 0x1893F4 / 0x1895FC):
  - 0x200 >> 5 = 0x10 and 0x220 >> 5 = 0x11 both pass.
  - Above that check, nothing is clamped or randomised.
- All three loaders use file type 2 = `\ACAR\%sA.%s;1` (formatFilename table D_004EA598 + type*0x20). The one special case is
  `b1` with type 2, which gives `\ACAR\%sB.%s;1`. So **AI slots load B2A.\* / B3A.\***. The PCAR B2P/B3P copies are not used by
  this path.

### What fills D_00313F00
These are the only writers:
- `netMsgSessionHandler`, in the game-info unpack (0x166CC0 loop):
  - `D_00313F00[s] = (signed byte msg[0xDC+s]) << 5`.
  - It also sets slot +0xB4 to the same value when +0xB4 == -1 or +0x214 == 0.
- `netMsgSessionHandler`, in the per-player info at 0x166DA0: `D_00313F00[s] = msg+0x10`.
- The same-car-for-everyone option: `func_00187CA8` 0x187F90, `func_001B2B68`, ui.s 0x1C8460.
- mods/guests.c `tmbr_LevelLoadCars`, which writes only the guests' slots.

The bytes come from `netSendGameInfo` = **func_00174988**:
- Loop at 0x174A90.
- While net+0x1BB0 < 8 it stores `byte = slot+0xB4 >> 5`.
- Otherwise it stores `byte = vehicle[slot]+0x20F4 >> 5`.
- 0x10 and 0x11 fit in a signed byte, so the round trip keeps 0x200 / 0x220.

### Where the random car comes from
**`func_00174598` (0x174598)** gives every slot with +0x10 == -1 (empty, i.e. a bot slot):
`+0xB4 = mathfRand(1, 14) << 5` (jal 0x1745CC, sw 0x1745D8).
- The result is always one of 0x20..0x1C0, which matches the logged 0x20, 0x80 and 0x160.
- Callers:
  - ui.s **0x1CD4BC**, already hooked to `tmbr_BotCars`. That runs the roll and then `tmbr_StoryCars`.
  - **0x16FB58** in `func_0016FA30` (net). This one is **not hooked**, so it is a second roll site.
- The roll goes into slot +0xB4 and reaches D_00313F00 only through a game-info message (`func_00174988` -> session handler).

### Conclusion for the test
- Writing slot +0xB4 = 0x200 / 0x220 "before the level loads" does not change what loads unless a game-info message is sent and
  unpacked afterwards. Without that, D_00313F00 still holds the earlier `func_00174598` roll, and `func_00188248` loads that
  roll (ordinary cars, as logged).
- A slot +0xB4 that differs from D_00313F00 is never range-checked or replaced.
- There is no Minion/boss/`slti 0xF/0x10` replacement on this path. The only `& 0x1E0` clamp is the same-car option. The other
  `mathfRand` use in shell.s is the retail-style AI pick `func_00187CA8` -> shell+0x19DEC. TMBO uses that list only for sounds,
  not for vehicles.
- Retail's story pick survives as `func_00187B98`:
  - It is called from `func_00186730` 0x186AB8.
  - For story (shell+0x18000+0x23B4 == 0) on level 0x14 it sets shell+0x19DEC = {0x220, 0x200} and +0x23C0 = 1.
  - On level 0xE it sets 0x1E0.
  - This list only feeds `func_001A3860` (sounds) and the load progress count (0x188434).
- `func_0016FE70` (net, called at 0x186C20 after the load) reloads a slot through `func_0018A930`, which reads slot +0xB4, when
  vehicle +0x20F4 != slot +0xB4. This did not fix the test cars. Either it does not run in this mode, or its earlier branches
  (0x16FF28) skip the loop. This is unverified.

## 2. Minimal patch

No instruction patch is needed in the loaders. Make D_00313F00 match at load time:

```c
/* in tmbr_LevelLoadCars (hook on jal 0x186AF8 -> func_00188248), before calling levelLoadCars(): */
if (tmbr_Opt(OPT_STORY) && LEVEL() == 20)
    for (s = 0; s < 8; s++)
        if (F(D_003156C0 + s*0x220, 0x10) == -1 && !tmbr_GuestSlot(s))
            D_00313F00[s] = F(D_003156C0 + s*0x220, 0xB4);   /* 0x200 / 0x220 set by tmbr_StoryCars */
```

- An alternative is to keep `tmbr_StoryCars` and make sure `netSendGameInfo` runs after it and is unpacked before the load. The
  direct write is simpler and host-local.
- Clients get the cars through the game-info bytes, which keep 0x10 / 0x11 intact.
- If the roll at 0x16FB58 runs after `tmbr_StoryCars`, it overwrites +0xB4 again. In that case add a HOOKS entry:
  - `(A("nonmatchings/online/net/func_0016FA30.s"), "0016FB58", "jal", "jal        tmbr_BotCars")`, or a wrapper that calls
    `func_00174598` and then `tmbr_StoryCars`.
  - Check that it is safe to rerun `tmbr_BotCars` there.
- Log check: `SHELL: Loading Vehicle %s into slot %d` (D_004EA510, `func_00189268`) must print `b2` / `b3`.

## 3. What else sees 0x200 / 0x220 once they load

- **VehicleParse** (TMBO `func_0013A0D0`):
  - A hier node id (word>>18) of 0x200 also goes to `FinalBoss::AddEpNode` (game+0x97120).
  - Ids < 0x400 with a zero low part become vehicles: `AddVehicle`, name = node id, +0x20F0 = load index.
  - So 0x200 and 0x220 become vehicles, provided B2A/B3A's node ids really are 0x200/0x220.
- **vehicleInitDynamics** `func_001D72D8`: the car switch at 0x1D73A0 has explicit cases.
  - 0x200 (0x1D744C -> 0x1DAF6C): health +0x400 = 125, then jumps to the common tail 0x1DBFB0. There is no per-car handling or
    engine tuning; the prologue defaults stay. It is the retail boss body, not a real drivable car.
  - 0x220 (0x1D74AC -> 0x1DAF7C): full tanker tuning, health 35 if +0x590 == 1 (human), else 160.
  - Neither id falls into the default case (0x1DBAEC).
- **Sounds** `func_001A3860` -> `func_001A41F0` / `func_001A42A0` -> `func_001A31C0`:
  - `func_001A31C0` (car -> sound bank) has cases up to 0x1E0. 0x200 and 0x220 return -1, so no engine bank loads and no flag is
    set. That is harmless at load, but the cars have no engine sound.
  - Its per-car flag arrays are indexed (car>>5)-1 only after a valid bank, so they are not overrun.
- **Load tables:**
  - D_003F6A00 has 18 entries (index < 0x12): OK.
  - D_003F6E08 / D_00313F00 hold 8 words: OK.
  - The human loaders 0x188AD0 / 0x188BD0 / 0x188CB8 also accept < 0x12.
- **gameMakeAI** (`func_0013A7B8`) matches +0x20F0 == load index. It works for any model, but:
  - The AI on 0x200 gets the boss body with default dynamics.
  - TMBO lost the 0x220-specific hit and death code (see STORY_BOSSES.md section 2).
- **Unchecked:**
  - Per-car arrays indexed by car>>5 in the HUD (hud.s 0x148B48, 0x14AFD0, 0x14E808, 0x14E8D8, 0x0BCF50...) and in ui.s.
    Index 16/17 may read past 15/16-entry tables (portraits, names, radar). Check these if the HUD shows garbage or crashes.
  - mods code that indexes by car type, e.g. bots.c `charOf`, story.c `MOVSLOT[17]` (size 17, so index 17 is out of range).
