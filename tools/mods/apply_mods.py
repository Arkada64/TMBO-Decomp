#!/usr/bin/env python3
# ruff: noqa
"""
tools/mods/apply_mods.py apply|revert : patch the split asm for TMB-Reloaded mods (shiftable build only).
build_shiftable.sh runs `apply` before linking and `revert` after, so the normal build stays byte-identical.
Mods:
  traffic: removed 2026-10-28 (traffic.c / traffic.s / traffic_nodes.c in mods/_to_delete)
  peds:    loader sends nodes 0xBB8..0xF9F to func_00178248 (addPedEpNode), and func_00138358 no longer
           clears the pedestrian 'enabled' flag (was the "Pedestrians online v2" pnach)
  shield:  Respawn Shield hooks into mods/shield.s (was the community "TMA Ruleset/ Respawn Shield" pnach)
Rules: patches replace an instruction 1:1 (j/jal to a mod routine) or add labels. Inserted code inside
the game's .text must be a multiple of 0x80 bytes (see HOOKS).
(TMBR_DEBUG_LOADER=1 needed tmbr_LoaderDbg from traffic.s, removed 2026-10-28: don't set it.)
"""

import sys, shutil, os, re
from pathlib import Path

R = Path.home() / "tmbo_decomp"
A = lambda p: R / "asm" / p
LOADER = A("nonmatchings/online/after_prison_10/func_00127650.s")
HOOKS = (
    """\
.Ltmbr_peds:
    jal        func_00178248
    daddu      $4, $17, $0
    b          .L00127AE8
    lq         $31, 0x20($29)
"""
    + "    nop\n" * 28
)
# ^ code growth inside the game's .text must be a multiple of 0x80: some code is followed by data that is
#   read with 128-bit lq (e.g. libmpeg's clamp mask D_002524C0), which ignores the low 4 address bits.
#   4 hook instructions + 28 nops = 0x80 (traffic's 5 removed 2026-10-28). A 0x28-byte growth gave full-screen green bars.
assert (
    sum(1 for l in HOOKS.splitlines() if l.strip() and not l.strip().endswith(":"))
    * 4
    % 0x80
    == 0
)
# (file, address, expected opcode, replacement instruction)
PATCHES = [
    (LOADER, "00127788", "bnel", "bnel       $2, $0, .Ltmbr_peds"),
    (LOADER, "0012778C", "lq", "nop"),
    (A("nonmatchings/tmb/game/func_00138358.s"), "00138828", "sw", "nop"),
    # Respawn Shield
    (
        A("nonmatchings/tmb/vehicle/func_001D72D8.s"),
        "001DC07C",
        "addiu",
        "j          tmbr_shield_spawn",
    ),
    (
        A("nonmatchings/tmb/vehicle/func_001E1C40.s"),
        "001E1CBC",
        "bne",
        "beqz       $5, .L001E1CDC",
    ),
    (
        A("nonmatchings/tmb/vehicle/func_001E4690.s"),
        "001E472C",
        "addiu",
        "j          tmbr_shield_c",
    ),
    (
        A("nonmatchings/tmb/game/func_00138C90.s"),
        "001395E0",
        "jal",
        "jal        tmbr_CameraUpdate",
    ),  # free cam
    (
        A("nonmatchings/tmb/game/func_00138C90.s"),
        "00139218",
        "addiu",
        "j          tmbr_SpecMark",
    ),  # spectating -> free cam
    (
        A("nonmatchings/tmb/game/func_001399A8.s"),
        "00139D38",
        "jal",
        "jal        tmbr_InitPOV",
    ),  # default camera = 2nd view
    (
        A("sdk/libgraph/graphdev.s"),
        "00249F2C",
        "jal",
        "jal        tmbr_pnachTick",
    ),  # per-frame pnach writes
    (
        A("nonmatchings/tmb/player/func_0017BE80.s"),
        "0017BF78",
        "beqz",
        "j          tmbr_ShoulderTap",
    ),  # L1/R1 weapon switch on tap only
    # split-screen guests (mods/guests.c): inputGetPlayerPad -> tmbr_InputGetPlayerPad (a guest's car slot reads its
    # controller; the delay slot "addiu $2, $0, 1" is harmless)
    (A("nonmatchings/tmb/input/inputGetPlayerPad__Fi.s"), "00217B30", "daddu", "j          tmbr_InputGetPlayerPad"),
    # ... guests pick their car on the real car select: its confirm / back net calls (guests.c tmbr_CarSelNet) and the
    # UI's pad read (the picking guest's controller drives the UI)
    (A("tmb/ui.s"), "001CB944", "jal", "jal        tmbr_CarSelNet"),
    (A("tmb/ui.s"), "001CB9C4", "jal", "jal        tmbr_CarSelNet"),
    (A("tmb/ui.s"), "001CE2E8", "jal", "jal        tmbr_UiPadButtons"),
    (A("tmb/ui.s"), "001CD4BC", "jal", "jal        tmbr_BotCars"),
    (A("tmb/hud.s"), "00146D70", "jal", "jal        tmbr_HudCarsLeft"),
    (A("online/after_input_70.s"), "0021B8C4", "jal", "jal        tmbr_KbPad"),
    (A("online/after_input_70.s"), "0021B9B0", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BA00", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BA9C", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BAEC", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BB84", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BBD4", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BC70", "jal", "jal        tmbr_KbAnalog"),
    (A("online/after_input_70.s"), "0021BCC0", "jal", "jal        tmbr_KbAnalog"),
    (A("nonmatchings/online/after_shadow_43/func_00186730.s"), "00186AF8", "jal", "jal        tmbr_LevelLoadCars"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "00183AD4", "jal", "jal        tmbr_HudView"),
    (A("tmb/hud.s"), "00147D14", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147D74", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147E58", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147F20", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147F5C", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147FC4", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00147FF4", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00148044", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "00148098", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "001480EC", "jal", "jal        tmbr_HudPrintTR"),
    (A("tmb/hud.s"), "001485BC", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "001485E0", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148678", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "001486EC", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148728", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148790", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "001487CC", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148834", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148894", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "001488D4", "jal", "jal        tmbr_HudPrintBay"),
    (A("tmb/hud.s"), "00148914", "jal", "jal        tmbr_HudPrintBay"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "001838B4", "jal", "jal        tmbr_HudPlace"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "00183770", "jal", "jal        tmbr_FrameClear"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "001838BC", "jal", "jal        tmbr_ViewScene"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "0018397C", "jal", "jal        tmbr_ViewFx1"),
    (A("nonmatchings/tmb/rt/func_00183580.s"), "00183984", "jal", "jal        tmbr_ViewFx2"),
    (A("nonmatchings/tmb/game/func_00138C90.s"), "00139344", "jal", "jal        tmbr_SbCall"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018C9F4", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CA34", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CA90", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CAA8", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CAC0", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CB18", "jal", "jal        tmbr_SbSize"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CB24", "jal", "jal        tmbr_SbDefSize"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CB58", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CB70", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CBC0", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CBD8", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC04", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC1C", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC34", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC4C", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC78", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CC90", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CCA8", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CCC0", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CCE0", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CCF8", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CD10", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CD28", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CE6C", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CE90", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CF08", "jal", "jal        tmbr_NmD"),   # (tmbr_SbPrint after the bonus car name, skins.c)
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CF38", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CFB0", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018CFE0", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D040", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D078", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D0DC", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D10C", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D140", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D184", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D1B4", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D1E8", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D244", "jal", "jal        tmbr_SbPrint"),
    (A("nonmatchings/online/after_shelloverlays_45/func_0018C7D0.s"), "0018D368", "jal", "jal        tmbr_SbPrintC"),
    (A("nonmatchings/online/net/func_0016FA30.s"), "0016FB58", "jal", "jal        tmbr_BotCars"),
    # ... and the controllers 2-4 are read at all: online's pad update (func_002165A0) only reads the pad whose map
    # entry is 0 (controller 1) and just marks the others ready, so their button buffers stayed empty (read as all
    # pressed, test 2026-10-26). Every port / multitap slot goes through the read now.
    (A("nonmatchings/tmb/input/func_002165A0.s"), "002165EC", "beqz", "b          .L0021660C"),
    (
        A("nonmatchings/tmb/player/func_0017BE80.s"),
        "0017BF00",
        "jal",
        "jal        tmbr_ComboUpdate",
    ),  # quick moves
    (
        A("nonmatchings/tmb/vehicle/func_001E4690.s"),
        "001E4E14",
        "jal",
        "jal        tmbr_shield_hearse",
    ),
    (
        A("nonmatchings/tmb/launch/func_001549A0.s"),
        "00155AB8",
        "jal",
        "j          tmbr_shield_d",
    ),
    (
        A("nonmatchings/tmb/launch/func_001549A0.s"),
        "00155340",
        "lw",
        "j          tmbr_shield_f",
    ),
    (
        A("nonmatchings/tmb/launch/func_00156E08.s"),
        "00156E08",
        "addiu",
        "j          tmbr_shield_e",
    ),
    (A("tmb/collis.s"), "00122D88", "lw", "j          tmbr_shield_h"),
    # retail content packs (mods/packs.c): after LoadLevelDB's level db init, load this level's pack
    (A("tmb/shell.s"), "0018890C", "jal", "jal        tmbr_LevelDbLoaded"),
    # ... and before the level's texture bins are built (level TEX init in func_00188930)
    (A("tmb/shell.s"), "001889E4", "jal", "jal        tmbr_LevelTexInitStub"),
    # ... and the level RTX init (func_00188688), where the pack's CLUTs join the level's
    (A("tmb/shell.s"), "0018873C", "jal", "jal        tmbr_LevelRtxStub"),
    # bots (mods/bots.c): AI list game+0x9E690 2 -> 7 entries, AI sort list 0x9FC98 -> 0x9E6AC
    (A("nonmatchings/online/after_freewaytrain_18/func_00137E08.s"), "00137E70", "addiu", "addiu      $3, $0, 0x7"),
    (A("nonmatchings/tmb/game/InitTypeOfVehicles__7TheGame.s"), "00138340", "slti", "slti       $2, $3, 0x7"),
    (A("nonmatchings/online/net/func_001756A0.s"), "0017576C", "slti", "slti       $2, $18, 0x7"),
    (A("nonmatchings/tmb/game/func_001399A8.s"), "00139B0C", "sw", "sw         $16, 0x1C($3)"),
    (A("nonmatchings/tmb/game/func_0013BEA0.s"), "0013C178", "addiu", "addiu      $12, $13, 0x66AC"),
    # ... game start: any mode (also Last Man Standing), our count instead of "3 - humans"
    (A("nonmatchings/tmb/game/func_001399A8.s"), "00139A50", "beqz", "nop"),
    (A("nonmatchings/tmb/game/func_001399A8.s"), "00139A98", "beqz", "nop"),
    (A("nonmatchings/tmb/game/func_001399A8.s"), "00139AA4", "jal", "jal        tmbr_BotsSpawn"),
    (A("nonmatchings/tmb/game/func_001399A8.s"), "00139AB0", "beqz", "b          .L00139AC0"),
    # ... joins/leaves and bot removal for any number of bots
    # ... bot weapons pass (bots.c): heavy-weapon cooldowns, weighted pick
    (A("nonmatchings/tmb/ai/aiUpdateAttack__7Vehicle.s"), "00105BA0", "jal", "jal        tmbr_AiKeepWeapon"),
    (A("nonmatchings/tmb/ai/aiUpdateAttack__7Vehicle.s"), "00105BB0", "jal", "jal        tmbr_AiPickWeapon"),
    (A("nonmatchings/online/after_trafficdirector_56/func_001B2B68.s"), "001B3CA4", "jal", "jal        tmbr_LoadScreen"),   # loading screen crash (guests.c)
    (A("nonmatchings/tmb/input/inputSetActuator__FiUcUci.s"), "002175E8", "addiu", "j          tmbr_Actuator"),   # no rumble with vibration off (rumble.s)
    # (removed 2026-10-27, online-focused build: 001B331C)
    # (removed 2026-10-27, online-focused build: 001B40D4)
    (A("nonmatchings/online/after_trafficdirector_56/func_001B2B68.s"), "001B3BA8", "jal", "jal        tmbr_ModsPage"),   # MINION / HEALTH rows on GAME MODS (modspage.c)
    (A("tmb/ui.s"), "001C6BCC", "jal", "jal        tmbr_RoomInput"),                      # waiting room input: hidden while R3 is held (menu.c)
    (A("tmb/ui.s"), "001CB004", "jal", "jal        tmbr_ModsInput"),                     # GAME MODS input read: our rows hide it (modspage.c)
    (A("nonmatchings/tmb/vehicle/func_001D6F78.s"), "001D7020", "jal", "jal        tmbr_VehInitDynamics"),            # Twister: Mr. Grimm's stats (skins.c)
    (A("tmb/ui.s"), "001CB768", "jal", "jal        tmbr_CarSelStep"),                    # car select step: extras behind spot 16 (skins.c)
    (A("nonmatchings/tmb/game/func_00138358.s"), "001386C8", "jal", "jal        tmbr_PrisonInitAfter"),        # Prison Passage story sequence (story.c)
    (A("nonmatchings/tmb/game/func_00138358.s"), "001387FC", "jal", "jal        tmbr_LevelInitAfter"),         # Warhawk's roof boss init (story.c)
    (A("nonmatchings/tmb/boss/func_00114B78.s"), "00114D5C", "jal", "jal        tmbr_BossWon"),                # the roof boss down: stage won (story.c)
    (A("nonmatchings/tmb/helicop/Update__10Helicopter.s"), "00141178", "jal", "jal        tmbr_RoofHeliSound"),   # roof's rotor sound: never on level 20 (story.c)
    (A("nonmatchings/tmb/envheli/UpdateEnvHeli__7EnvHeli.s"), "001328F8", "jal", "jal        tmbr_RoofHeliSound"),  # the level's ambient helicopter: same rule
    (A("nonmatchings/tmb/boss/func_001123C0.s"), "001141A0", "jal", "jal        tmbr_RoofHeliSound"),       # the boss helicopter's rotor: same rule
    # (the dispatch 0x14F184 -> tmbr_VehTakeHit: one entry, with the hit-function hooks below)
    (A("nonmatchings/tmb/ai/aiInit__7Vehicle.s"), "0010011C", "jal", "jal        tmbr_MinionVehInit"),          # Minion's stadium: AI Minion health + force field (story.c)
    (A("nonmatchings/tmb/game/func_0013D0C0.s"), "0013D574", "jal", "jal        tmbr_DoFogVolume"),           # Lost map look debug: fog volumes off (lostslots.c)
    (A("nonmatchings/tmb/game/func_0013D0C0.s"), "0013D594", "jal", "jal        tmbr_DoAmbientVolume"),       # ... ambient volumes off
    (A("nonmatchings/online/after_blimp_06/func_00111ED8.s"), "00111F0C", "jal", "jal        tmbr_BossVehName"),      # boss cars by name (story.c)
    (A("nonmatchings/tmb/forceField/func_00136100.s"), "001361B4", "jal", "jal        tmbr_BossVehName"),      # boss cars by name (story.c)
    (A("nonmatchings/tmb/boss/func_00114B78.s"), "00114CEC", "jal", "jal        tmbr_BossVehName"),      # boss cars by name (story.c)
    (A("nonmatchings/tmb/boss/func_001123C0.s"), "00113030", "jal", "jal        tmbr_BossVehName"),      # boss cars by name (story.c)
    (A("nonmatchings/tmb/boss/func_001123C0.s"), "001141D8", "jal", "jal        tmbr_BossVehName"),      # boss cars by name (story.c)
    (A("nonmatchings/tmb/prison_part2/func_0017DA58.s"), "0017DAFC", "jal", "jal        tmbr_PrisonState0"),
    (A("nonmatchings/tmb/prison_part2/func_0017DA58.s"), "0017DB24", "jal", "jal        tmbr_PrisonState2"),
    (A("tmb/collis.s"), "0011F0DC", "jal", "jal        tmbr_PickupHit"),                       # HEALTH : OFF (bots.c)
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167378", "jal", "jal        tmbr_PickupHit"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167454", "jal", "jal        tmbr_PickupHit"),
    # ... UpdatePickups (func_001798A8): no respawn of health / full health (OFF) or environment pickups,
    #     no full-health placing with OFF (bots.c)
    (A("nonmatchings/online/after_highwayptool_32/func_001798A8.s"), "00179A10", "jal", "jal        tmbr_PickupPlaceFullHealth"),
    (A("nonmatchings/online/after_highwayptool_32/func_001798A8.s"), "00179A64", "jal", "jal        tmbr_PickupRegen"),
    (A("nonmatchings/online/after_highwayptool_32/func_001798A8.s"), "00179AF8", "jal", "jal        tmbr_PickupRegen"),
    # ... no storm cloud on Suburbs / Mini Suburbs / Snowy Roads (thunderstormCreate skipped, bots.c)
    (A("nonmatchings/tmb/suburb/func_001AA000.s"), "001AA01C", "jal", "jal        tmbr_NoStormCloud"),
    (A("nonmatchings/tmb/death2/func_00127BE8.s"), "00127C1C", "jal", "jal        tmbr_NoStormCloud"),
    (A("nonmatchings/tmb/sound/func_0019E7C0.s"), "0019E86C", "jal", "jal        tmbr_NoCloudSound"),        # no storm cloud sound (bots.c)
    (A("nonmatchings/tmb/sound/func_0019E7C0.s"), "0019EA1C", "jal", "jal        tmbr_NoCloudSound"),
    # ... team play (teams.c): team colours for every car incl. bots on markers / radar, lock-on skips teammates
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE2C", "addiu", "jal        tmbr_TeamColorS"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE30", "bne", "daddu      $4, $17, $0"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE38", "addiu", "daddu      $18, $2, $0"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE3C", "lw", "addiu      $4, $0, -0x1"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE40", "lw", "beq        $18, $4, .L001DCE70"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE44", "srl", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE48", "andi", "b          .L001DCE78"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE4C", "beqz", "addiu      $7, $6, %lo(D_003156C0)"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE50", "addiu", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE54", "lw", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE58", "addiu", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE5C", "mult", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE60", "addu", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE64", "lw", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCE68", "bne", "nop"),
    (A("tmb/hud.s"), "0014B098", "jal", "jal        tmbr_NameColorS"),
    (A("tmb/hud.s"), "0014A9A0", "jal", "jal        tmbr_HudColor"),
    (A("tmb/hud.s"), "0014A9B8", "jal", "jal        tmbr_HudColor"),
    (A("tmb/hud.s"), "0014B764", "jal", "jal        tmbr_HudColor"),
    (A("tmb/hud.s"), "0014C4C0", "jal", "jal        tmbr_HudColor"),
    (A("tmb/hud.s"), "0014A914", "bne", "nop"),
    (A("tmb/hud.s"), "0014A91C", "lui", "jal        tmbr_TeamColorS"),
    (A("tmb/hud.s"), "0014A920", "addiu", "daddu      $a0, $s3, $zero"),
    (A("tmb/hud.s"), "0014A924", "lw", "daddu      $s0, $v0, $zero"),
    (A("tmb/hud.s"), "0014A928", "lw", "addiu      $a0, $zero, -0x1"),
    (A("tmb/hud.s"), "0014A92C", "srl", "beq        $s0, $a0, .L0014A958"),
    (A("tmb/hud.s"), "0014A930", "andi", "nop"),
    (A("tmb/hud.s"), "0014A934", "beqz", "b          .L0014A960"),
    (A("tmb/hud.s"), "0014A938", "addiu", "lui        $a4, %hi(D_003156C0)"),
    (A("tmb/hud.s"), "0014A93C", "lw", "nop"),
    (A("tmb/hud.s"), "0014A940", "addiu", "nop"),
    (A("tmb/hud.s"), "0014A944", "mult", "nop"),
    (A("tmb/hud.s"), "0014A948", "addu", "nop"),
    (A("tmb/hud.s"), "0014A94C", "lw", "nop"),
    (A("tmb/hud.s"), "0014A950", "bne", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A730", "beqz", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A738", "lw", "daddu      $4, $16, $0"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A73C", "lw", "jal        tmbr_SameTeam"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A740", "mult", "daddu      $5, $17, $0"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A744", "addu", "bnel       $2, $0, .L0015AAC4"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A748", "addiu", "addiu      $18, $18, 0x1"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A74C", "mult", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A750", "addu", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A754", "lw", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A758", "lw", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A75C", "beql", "nop"),
    (A("nonmatchings/tmb/launch_part2/func_0015A650.s"), "0015A760", "addiu", "nop"),
    # ... synchronous entry: the host's "everyone loaded -> go" (net state 0xA -> 0xB) waits for the bots
    (A("nonmatchings/tmb/game/func_00138C90.s"), "00138FD8", "jal", "jal        tmbr_SyncGo"),
    (A("nonmatchings/online/net/func_00176EA0.s"), "00176EA0", "addiu", "j          tmbr_BotsRebalance"),
    (A("nonmatchings/online/net/func_00176EA0.s"), "00176EA4", "lui", "nop"),
    (A("nonmatchings/online/after_game_19/func_0013EED0.s"), "0013EED0", "addiu", "j          tmbr_BotRemove"),
    (A("nonmatchings/online/after_game_19/func_0013EED0.s"), "0013EED4", "sq", "nop"),
    # ... deathmatch settings: "USE BOTS" row removed (bots.c settingsRows), bots no longer exclude sync entry
    (A("tmb/ui.s"), "001C7C3C", "addiu", "addiu      $s7, $zero, 0x6"),   # 6 rows: the sync entry row (row 6 since the USE BOTS row went) is gone too - sync is the standard (bots.c tmbr_LobbyFrame)
    # skip the use-bots / sync exclusion but keep $s0 = &net (.L001C8364): branching to .L001C8368 left $s0 = row
    # index and the next lw 0x3148($s0) faulted (TLB miss at 0x1C8368, addr 0x314E): sync entry could not be set
    (A("tmb/ui.s"), "001C8334", "bne", "b          .L001C8364"),
    # draw 7 rows, not 8: row 7 (sync entry) is shown in row 6's place by settingsRows, it was listed twice
    (A("tmb/ui.s"), "001C80BC", "slti", "slti       $v0, $s1, 0x6"),   # 6: the sync entry row is not drawn either (sync is the standard)
    # bonus cars' own names where the game names an AI car by its type (skins.c tmbr_VehName, Ark 2026-10-27)
    (A("tmb/hud.s"), "0014B008", "jal", "jal        tmbr_NmA"),
    (A("tmb/hud.s"), "0014E818", "jal", "jal        tmbr_NmB"),
    (A("tmb/hud.s"), "0014E8E8", "jal", "jal        tmbr_NmC"),
    (A("nonmatchings/online/net/func_00175AA0.s"), "00175BE8", "jal", "jal        tmbr_NmE"),
    (A("nonmatchings/tmb/game/func_0013A7B8.s"), "0013A934", "jal", "jal        tmbr_NmF"),
    # ... bot count picked in the waiting room
    (A("nonmatchings/online/after_trafficdirector_56/func_001B2B68.s"), "001B39B4", "jal", "jal        tmbr_LobbyFrame"),
    # waiting room: traffic / teams lines inside the game settings box, after ENTRY (mods/lobby.s, bots.c)
    (A("tmb/ui.s"), "001C6570", "jal", "jal        tmbr_PrintEntry"),
    (A("tmb/ui.s"), "001C6748", "jal", "jal        tmbr_PrintEntry"),
    (A("tmb/ui.s"), "001C675C", "jal", "jal        tmbr_PrintEntry"),
    # ... Last Man Standing: no ENTRY line, the box ends with NUMBER OF LIVES
    (A("tmb/ui.s"), "001C6304", "jal", "jal        tmbr_PrintLives"),
    # quick boot (mods/quickboot.c): scripted pad input for unattended test runs
    (A("nonmatchings/tmb/input/func_00216840.s"), "00216CAC", "jal", "jal        tmbr_PadRead"),
    # ... bot targets' attractor group during the hunter's whole AI frame (bot vs bot)
    (A("nonmatchings/tmb/vehicle/func_001DC760.s"), "001DCB64", "jal", "jal        tmbr_AiUpdate"),
    # ... specials offered less often to bots (free-for-all)
    (A("nonmatchings/tmb/ai/func_00106440.s"), "001064E8", "jal", "jal        tmbr_AiGoodWeapon"),
    # ... bots 0..5 in net messages as -2..-7 (was -2 / -3 for everything else): mods/botnet.s
    (A("nonmatchings/online/net/func_00171818.s"), "0017187C", "lui", "jal        tmbr_BotCode"),
    (A("nonmatchings/online/net/func_00171818.s"), "00171880", "ori", "daddu      $4, $5, $0"),
    (A("nonmatchings/online/net/func_00171818.s"), "00171884", "addu", "b          .L00171898"),
    (A("nonmatchings/online/net/func_00171818.s"), "00171888", "lw", "nop"),
    (A("nonmatchings/online/net/func_00171818.s"), "001719B0", "lui", "jal        tmbr_BotCode"),
    (A("nonmatchings/online/net/func_00171818.s"), "001719B4", "lw", "daddu      $4, $5, $0"),
    (A("nonmatchings/online/net/func_00171818.s"), "001719B8", "lui", "b          .L001719D4"),
    (A("nonmatchings/online/net/func_00171818.s"), "001719BC", "ori", "nop"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2540", "lui", "jal        tmbr_BotCode"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2544", "lw", "daddu      $4, $17, $0"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2548", "lui", "subu       $2, $0, $2"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E254C", "ori", "addiu      $2, $2, -0x2"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2550", "addu", "b          .L001E2570"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2554", "lw", "sw         $2, 0x24($29)"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E25A0", "lui", "jal        tmbr_BotCode"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E25A4", "ori", "daddu      $4, $19, $0"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E25A8", "addu", "b          .L001E25C4"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E25AC", "lw", "nop"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AF14", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AF18", "bne", "daddu      $2, $3, $0"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AF1C", "sll", "b          .L0016AF74"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AF20", "lui", "daddu      $19, $2, $0"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AFA0", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AFA4", "bne", "daddu      $2, $3, $0"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AFA8", "addiu", "b          .L0016AFE8"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016AFAC", "lui", "daddu      $20, $2, $0"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5E0", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5E4", "bne", "daddu      $2, $3, $0"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5E8", "sll", "daddu      $6, $2, $0"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5EC", "lui", "bnez       $6, .L0016B640"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5F0", "lw", "nop"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5F4", "lui", "b          .L0016B6B0"),
    (A("nonmatchings/online/net/netWeaponDestroyCB.s"), "0016B5F8", "ori", "lq         $31, 0x40($29)"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B494", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B498", "bne", "daddu      $2, $3, $0"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B49C", "sll", "daddu      $6, $2, $0"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B4A0", "lui", "bnez       $6, .L0016B4F0"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B4A4", "lw", "nop"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B4A8", "lui", "b          .L0016B550"),
    (A("nonmatchings/online/net/netWeaponUpdateCB.s"), "0016B4AC", "ori", "lq         $31, 0x30($29)"),
    (A("nonmatchings/online/net/func_001735E8.s"), "00173650", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/func_001735E8.s"), "00173654", "bne", "daddu      $2, $3, $0"),
    (A("nonmatchings/online/net/func_001735E8.s"), "00173658", "addiu", "b          .L00173698"),
    (A("nonmatchings/online/net/func_001735E8.s"), "0017365C", "lui", "daddu      $17, $2, $0"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "001678BC", "addiu", "jal        tmbr_BotByCode"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "001678C0", "bne", "daddu      $2, $6, $0"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "001678C4", "addiu", "b          .L00167904"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "001678C8", "lui", "daddu      $16, $2, $0"),
    # ... bots hurt each other: func_001E1C40 zeroed damage from a bot to a bot (brain+0x598 unset)
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E1DB8", "bne", "b          .L001E1E10"),
    # ... bots may shoot bots without the "is the player looking at me" fairness gate
    (A("nonmatchings/tmb/ai/func_00107048.s"), "001071A4", "jal", "jal        tmbr_AiMayShoot"),
    (A("nonmatchings/tmb/ai/aiLineUpShot__7Vehicle.s"), "00106C40", "jal", "jal        tmbr_AiMayShoot"),
    (A("nonmatchings/tmb/ai/func_00106D50.s"), "00106F0C", "jal", "jal        tmbr_AiMayShoot"),
    # skins (mods/skins.c): Gold Tooth / 12 Pak picked on the car select screen, synced over chat, loaded per client
    (A("tmb/ui.s"), "001CB50C", "jal", "jal        tmbr_CarSelectSound"),
    (A("nonmatchings/online/net/netInitDme.s"), "0016E680", "lui", "lui        $5, %hi(tmbr_ChatHandler)"),
    (A("nonmatchings/online/net/netInitDme.s"), "0016E68C", "addiu", "addiu      $5, $5, %lo(tmbr_ChatHandler)"),
    (A("tmb/shell.s"), "001884BC", "jal", "jal        tmbr_LoadOwnCar"),
    (A("tmb/shell.s"), "00189048", "jal", "jal        tmbr_LoadCar268"),
    (A("tmb/shell.s"), "00189070", "jal", "jal        tmbr_LoadCar478"),
    (A("tmb/shell.s"), "00189098", "jal", "jal        tmbr_LoadCar680"),
    (A("tmb/shell.s"), "0018AB18", "jal", "jal        tmbr_LoadCar268"),
    (A("tmb/shell.s"), "0018AB2C", "jal", "jal        tmbr_LoadCar478"),
    (A("tmb/shell.s"), "0018AB40", "jal", "jal        tmbr_LoadCar680"),
    (A("nonmatchings/online/net/func_001742B0.s"), "001744F8", "jal", "jal        tmbr_LoadCar0F0"),
    # 12 Pak: 16th car select spot (wrap 14 -> 15), preview shows Roadkill there, his special is the reticle weapon
    (A("tmb/ui.s"), "001CB784", "addiu", "addiu      $v0, $zero, 0xF"),
    (A("tmb/ui.s"), "001CB7B0", "addiu", "addiu      $v0, $zero, 0xF"),
    # ... waiting room player list: "12 PAK" instead of "ROADKILL" for players with 12 Pak on
    (A("tmb/ui.s"), "001C5E94", "jal", "jal        tmbr_LobbyCarNameS"),
    (A("tmb/ui.s"), "001C5ED4", "jal", "jal        tmbr_LobbyCarNameS"),
    (A("tmb/ui.s"), "001CB59C", "jal", "jal        tmbr_PreviewSwitch"),
    (A("tmb/ui.s"), "001CB65C", "jal", "jal        tmbr_PreviewSwitch"),
    (A("tmb/ui.s"), "001CB694", "jal", "jal        tmbr_PreviewSwitch"),
    (A("tmb/ui.s"), "001CB8AC", "jal", "jal        tmbr_PreviewSwitch"),
    (A("nonmatchings/tmb/launch/func_00156E08.s"), "00157D10", "jal", "jal        tmbr_FireSpecial"),
    # extras' borrowed specials (skins.c, Ark 2026-10-26): Thumper = Warthog's, Old Pickup = Minion's (front arc), Twister
    # without Outlaw's special-selected turret aim / laser
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155B84", "jal", "jal        tmbr_OutlawAim"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155D20", "jal", "jal        tmbr_UpdateTowTruck"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155D84", "jal", "jal        tmbr_UpdateSpecial"),
    (A("nonmatchings/online/net/netWeaponCreateCB.s"), "0016B0CC", "jal", "jal        tmbr_NetFireSpecial"),
    (A("nonmatchings/tmb/launch/FireSpecial__8LauncherP7Vehicle.s"), "001594A8", "jal", "jal        tmbr_MinionLockOn"),
    (A("nonmatchings/tmb/launch_part2/UpdateSpecial__8LauncherP7Vehicle.s"), "0015EE50", "jal", "jal        tmbr_MinionLockOn"),
    (A("nonmatchings/tmb/launch_part2/UpdateSpecial__8LauncherP7Vehicle.s"), "0015EEE0", "jal", "jal        tmbr_PkDist"),   # Old Pickup: Minion's torch, not his shells (skins.c)
    (A("nonmatchings/tmb/launch_part2/func_00160D80.s"), "00160E28", "jal", "jal        tmbr_MinionLockOn"),
    # damage reports (mods/dmgreport.c): every hit by the local player, before the car-owner check
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E2498", "lw", "j          tmbr_DmgGate"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E249C", "beql", "nop"),
    # ... and rams on remote cars (sent to the victim's console as a game event instead of applied here)
    (A("tmb/collis.s"), "00121744", "jal", "jal        tmbr_RamSent"),
    # every call of the hit function: team play without friendly fire, real damage for the reports (dmgreport.c)
    # The weapon dispatch and the three network hit events go through story.c's tmbr_VehTakeHit first (Minion's
    # shield, the roof tanker), which then calls tmbr_TakeHit. (One patch per site: a second patch at the same
    # address silently replaces the first.)
    (A("nonmatchings/tmb/fodder/fodderTakeHit__7VehicleP8_fvectorii.s"), "00134AA8", "jal", "jal        tmbr_TakeHit"),
    (A("nonmatchings/tmb/interact/func_0014F108.s"), "0014F184", "jal", "jal        tmbr_VehTakeHit"),
    (A("nonmatchings/tmb/vehicle/func_001DC760.s"), "001DC7C4", "jal", "jal        tmbr_TakeHit"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167938", "jal", "jal        tmbr_TakeHit"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167D38", "jal", "jal        tmbr_VehTakeHit"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167DA0", "jal", "jal        tmbr_VehTakeHit"),
    (A("nonmatchings/online/net/netMsgGameEventHandler.s"), "00167EC4", "jal", "jal        tmbr_VehTakeHit"),
    # 12 Pak's reticle special: the reticle's slot-5 ammo calls
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155240", "jal", "jal        tmbr_ReticleUsed"),
    (A("nonmatchings/tmb/launch/func_00156118.s"), "00156268", "jal", "jal        tmbr_ReticleUsed"),
    (A("nonmatchings/tmb/launch/func_00156118.s"), "00156698", "jal", "jal        tmbr_ReticleUsed"),
    (A("nonmatchings/tmb/launch/func_00156118.s"), "00156A88", "jal", "jal        tmbr_ReticleUsed"),
    (A("nonmatchings/tmb/launch/func_00156E08.s"), "00157BDC", "jal", "jal        tmbr_ReticleUsed"),
    # kill feed: only the 8 real cars; remote players' cars skipped (their console decides) - skins.c
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E278C", "jal", "jal        tmbr_KillMessage"),
    # 12 Pak: launcher update without Roadkill's charge special
    (A("nonmatchings/tmb/vehicle/func_001DCD48.s"), "001DCD90", "jal", "jal        tmbr_LauncherUpdate"),
    # Lost / Harbor City maps in their own level-select entries, run as Dogpound (mods/lostslots.c)
    (A("tmb/ui.s"), "001CA9E0", "jal", "jal        tmbr_LevelSelStep"),       # level select step: entries after 20
    (A("tmb/ui.s"), "001CA7CC", "jal", "jal        tmbr_LevelSelFrame"),      # ... frame: the entry's name
    (A("tmb/ui.s"), "001CAB20", "jal", "jal        tmbr_LevelSelConfirm"),    # ... confirm: record + sync the pick
    (A("tmb/ui.s"), "001C5FD0", "jal", "jal        tmbr_LevelShowName"),      # waiting room "LEVEL : <name>"
    (A("online/after_drawc_66.s"), "002006F8", "jal", "jal        tmbr_FileSearch"),   # raw reader: RTX, PTS/PKP/PUP, ZN
    (A("online/after_drawc_66.s"), "002007C0", "jal", "jal        tmbr_FileSearch"),   # zip reader: NGP, TEX
    (A("tmb/shell.s"), "001883C4", "jal", "jal        tmbr_FileSearch"),             # loading bar: NGP size
    (A("tmb/shell.s"), "001883FC", "jal", "jal        tmbr_FileSearch"),             # loading bar: TEX size
]
# (file, address, label) - global label placed right before that instruction (return points)
LABELS = [
    (A("nonmatchings/tmb/vehicle/func_001D72D8.s"), "001DC084", "tmbr_ret_1DC084"),
    (A("nonmatchings/tmb/vehicle/func_001E4690.s"), "001E4734", "tmbr_ret_1E4734"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155AC0", "tmbr_ret_155AC0"),
    (A("nonmatchings/tmb/launch/func_001549A0.s"), "00155348", "tmbr_ret_155348"),
    (A("nonmatchings/tmb/launch/func_00156E08.s"), "00156E10", "tmbr_ret_156E10"),
    (A("nonmatchings/tmb/player/func_0017BE80.s"), "0017BF80", "tmbr_ret_17BF80"),
    (A("nonmatchings/tmb/player/func_0017BE80.s"), "0017C060", "tmbr_ret_17C060"),
    (A("nonmatchings/tmb/game/func_00138C90.s"), "00139220", "tmbr_ret_139220"),
    (A("tmb/collis.s"), "00122D8C", "tmbr_ret_122D8C"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E24A4", "tmbr_ret_1E24A4"),
    (A("nonmatchings/tmb/vehicle/func_001E1C40.s"), "001E24D0", "tmbr_ret_1E24D0"),
]
# Patches to functions that are already decompiled (matched C): (file, exact old text, new text)
# NOTE: any change in code SIZE moves everything after it, and the shiftable build still has stale data
# references somewhere (the map selector crashes when data moves, even with no mods). Patches must keep every
# function's size; code that needs room goes into the mods area after .bss (see build_shiftable.sh).
# The shield length in matched-C func_001DD0C8 is therefore a post-link word patch (mods/postlink.txt).
C_PATCHES = []
# Plain text substitutions in asm files: (file, exact old text, new text, expected count)
CRT0 = A("gcc/_crt0.s")
ASM_TEXT = [
    # Main-thread stack size (SetupThread arg). The heap runs from the end of .bss to the stack's bottom, so
    # everything the mods add to the ELF comes out of the heap; the map selector ran out (operator new ->
    # abort -> exit to the PS2 menu). TMBR_STACK_SIZE (mods/memory.s) is smaller than the original 0x40000.
    (CRT0, "%hi(D_40000)", "%hi(TMBR_STACK_SIZE)", 1),
    (CRT0, "%lo(D_40000)", "%lo(TMBR_STACK_SIZE)", 1),
    # crt0 zeroes .bss from D_004FB400 up to D_725694 (= main_VRAM_END, the end of everything) - that would
    # wipe the mods, which now sit after .bss. Clear only up to the game's own .bss end; the heap still
    # starts at main_VRAM_END (the second D_725694 pair, $a0).
    (CRT0, "$v1, %hi(D_725694)", "$v1, %hi(main_BSS_END)", 1),
    (CRT0, "$v1, $v1, %lo(D_725694)", "$v1, $v1, %lo(main_BSS_END)", 1),
]
DBG = os.environ.get("TMBR_DEBUG_LOADER") == "1"
# Traffic/peds level-loader hooks: OFF by default. They add 0x80 bytes inside the loader (moves all code and
# data after it -> map selector crash, see above). (TMBR_TRAFFIC is gone with traffic.)
# Peds in normal builds come from the baked "Pedestrians Online" pnach section (same size, stub in a dead func).
NO_TRAFFIC = True   # traffic removed 2026-10-28; the peds loader hooks stay off too (pnach peds)
if NO_TRAFFIC:
    PATCHES = [p for p in PATCHES if p[0] != LOADER and p[1] != "00138828"]
# TMBR_SKIP=group,group: leave hooks out (for bisecting). Groups by hook address:
GROUPS = {
    "camera": {"00139D38"},
    "freecam": {"001395E0", "00139218"},
    "tick": {"00249F2C"},
    "qm": {"0017BF78", "0017BF00"},
    "lost": {"001CA9E0", "001CA7CC", "001CAB20", "001C5FD0", "002006F8", "002007C0", "001883C4", "001883FC"},
    "packs": {"0018890C", "001889E4"},
    "shield": {
        "001DC07C",
        "001E1CBC",
        "001E472C",
        "001E4E14",
        "00155AB8",
        "00155340",
        "00156E08",
        "00122D88",
    },
}
SKIP = [g for g in os.environ.get("TMBR_SKIP", "").split(",") if g]
for g in SKIP:
    PATCHES = [p for p in PATCHES if p[1] not in GROUPS[g]]
if "shield" in SKIP:
    C_PATCHES = [c for c in C_PATCHES if "0x497" not in c[2]]
if SKIP:
    print("hooks left out:", ",".join(SKIP))
CALLERS = [
    A(f"nonmatchings/online/after_prison_10/{n}.s")
    for n in ("func_001274D0", "func_00127188", "func_00127330")
]
INS = re.compile(r"^(\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+)(\S+)(.*)$")


def files():
    fs = (
        {p[0] for p in PATCHES}
        | {l[0] for l in LABELS}
        | {LOADER}
        | {t[0] for t in ASM_TEXT}
    )
    return fs | (set(CALLERS) if DBG else set())


def touch_c(paths):
    # INCLUDE_ASM'd .s files aren't ninja dependencies of their .c: touch the .c files that include them
    dirs = {str(p.parent) for p in paths}
    for c in (R / "src").rglob("*.c"):
        t = c.read_text(errors="ignore")
        if any(f'"{d}"' in t for d in dirs):
            os.utime(c)


def apply():
    fs = files()
    text = {}
    for f in fs:
        bak = f.with_suffix(".s.orig")
        if not bak.exists():
            shutil.copy(f, bak)
        text[f] = bak.read_text()  # always patch from the original
    for f, addr, op, new in PATCHES:
        L = text[f].split("\n")
        hit = 0
        for i, l in enumerate(L):
            m = INS.match(l)
            if m and m.group(2) == addr:
                assert m.group(3) == op, (
                    f"{f.name} {addr}: expected {op}, found {m.group(3)}"
                )
                L[i] = m.group(1) + new
                hit += 1
        assert hit == 1, f"{f.name} {addr}: patch site found {hit}x"
        text[f] = "\n".join(L)
    for f, addr, lab in LABELS:
        L = text[f].split("\n")
        hit = 0
        for i, l in enumerate(L):
            m = INS.match(l)
            if m and m.group(2) == addr:
                L.insert(i, f".globl {lab}\n{lab}:")
                hit += 1
                break
        assert hit == 1, f"{f.name} {addr}: label site not found"
        text[f] = "\n".join(L)
    for f, old, new, n in ASM_TEXT:
        assert text[f].count(old) == n, (
            f"{f.name}: '{old}' found {text[f].count(old)}x, expected {n}"
        )
        text[f] = text[f].replace(old, new)
    assert text[LOADER].count("endlabel func_00127650") == 1
    if not NO_TRAFFIC:
        text[LOADER] = text[LOADER].replace(
            "endlabel func_00127650", HOOKS + "endlabel func_00127650"
        )
    else:
        print("traffic/peds loader hooks left out (TMBR_NO_TRAFFIC=1)")
    if DBG:
        for f in CALLERS:
            assert (
                text[f].count("%hi(func_00127650)") == 1
                and text[f].count("%lo(func_00127650)") == 1
            ), f
            text[f] = text[f].replace("(func_00127650)", "(tmbr_LoaderDbg)")
        print("debug: loader callback wrapped")
    for f, t in text.items():
        f.write_text(t)
    for f, old, new in C_PATCHES:
        bak = f.with_name(f.name + ".orig")
        if not bak.exists():
            shutil.copy(f, bak)
        t = bak.read_text()
        assert t.count(old) == 1, (
            f"{f.name}: C patch site found {t.count(old)}x (function changed?)"
        )
        f.write_text(t.replace(old, new))
    touch_c(fs)
    print("mods applied: traffic, peds, respawn shield, quick moves, camera, free cam")


def revert():
    fs = files() | set(CALLERS)
    for f in fs:
        bak = f.with_suffix(".s.orig")
        if bak.exists():
            shutil.copy(bak, f)
            bak.unlink()
    for f, _, _ in C_PATCHES:
        for bak in (f.with_name(f.name + ".orig"), f.with_suffix(".c.orig")):
            if bak.exists():
                shutil.copy(bak, f)
                bak.unlink()
    touch_c(fs)
    print("mods reverted")


{"apply": apply, "revert": revert}[sys.argv[1]]()
