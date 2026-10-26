# TODO (later)

- **Work queue (Ark 2026-10-26, top to bottom):**
  1. Split-screen guests: car select (the real screen repeats "PLAYER n CHOOSE A VEHICLE" on that controller).
  2. Guests joining (START on controller 2-4 in the waiting room; on a client the host makes the car over chat).
  3. Guest camera pulled back (retail split distance) + HUD per view.
  4. Letterbox off (the picture is 640x360 inside 448: give split screen the full height).
  5. Bots charge the reticle weapon (satellite-style, hold up to 5 s; Launcher func_001549A0 charger code,
     GetSatelliteReticle; find the held-fire input first).
  6. 12 Pak as a bot.
  7. Outlaw turret secondary / Manslaughter drop-behind (Launcher::UpdateSpecial 0x15CD80).
  8. Minion toggle on the native game mods page.
  9. HEALTH lobby option: ON = health pickups spawn and can be picked up (overrides the TMA ruleset's no-health);
     OFF = no health on the map at all (replaces the TMA health rule; the respawn shield stays).
  10. Environment pickups removed for good (no option), with the clouds on maps whose cloud is an environment pickup
      (Suburbs, Snowy Roads, Mini Suburbs).
  11. Story mode (single player) with retail's cutscenes: ~2.9 GB of retail movies onto the disc (fine for PCSX2), the
      story flow rebuilt in online's menus, each level's story events / bosses checked (retail decomp to compare).
      Health pads back on the maps that had them in retail (single player had them).
      Retail's story versions of the maps go on the disc as separate files (e.g. \LVL\SP_SUBURB.*) and the level
      loader picks them only in story mode (a story flag on the file names, like the content packs): online matches
      keep loading the online maps untouched.
  12. Local co-op story (split-screen guests = retail's 2P co-op path).
      + Bot ally option: you pick its car, it plays alongside you (a teammate bot: team code already keeps it off you),
        taking 20 % of normal damage (story enemy bots take 10 %), 3 lives like the player; enemy AI prefers human targets but can
        still go for it; it sometimes stays near the player; in the Warhawk boss fight it leaves the tankers alone so
        players can position them.
  13. Online co-op story: story enemies / bosses are AI cars (synced like bots), cutscenes and scripted events
      host-driven (hidden chat messages).
  14. (Last, very experimental) Roguelike story option: each round a choice of two maps from any map, a visited map
      leaves the pool; character dialogue won't fit every stage. AI back to the human-hunting routine and doing far
      less damage to each other, so progressing stays a challenge like normal TMB.

- **Target: PCSX2 only** (Ark 2026-10-25): TMB Reloaded is unrestricted TMBO for the emulator; real PS2 hardware is
  not a goal. No view-distance / bot cuts for real-hardware limits: tune the EE cycle rate default instead (130 % now).

- **Ram damage in damage reports, online** (mods/dmgreport.c). Rams on another player's car still show nothing.
  The hook on the type-60 ram game event (`tmbr_RamSent`, `netSendGameEvent` call at 0x121744 in
  func_001214C0) is in both builds, but a test on 2026-10-24 showed no reports for rams. Next step: the debug
  pnach (`DMGDBG=1 bash tools/mods/make_pnach.sh`) logs "TMBR ram" lines. No lines = this console never sends
  the event (the victim's console works rams out itself), so watch the other car's health after any collision
  instead. Lines = the event's fields are being misread. Easier once more of the collision code is decompiled.
- **Game-mode AI, the rest** (mods/bots.c). Done 2026-10-24: Deathmatch (go after a runaway kill leader), LMS (careful
  on the last life, no breakaways / cruising with 3 or fewer left), Man Hunt (up to `PREY_CHASERS` 2 bots chase the
  prey; prey = car whose player slot +0x20C0 equals game info byte +0x1A). Left:
  - Man Hunt escorts: the prey's teammates (team play) stay near it and target its attackers.
  - Bots as the prey: bots' cars have player slot -1, so the game's prey hand-off can't pick them; find the code
    that picks / transfers the prey. Prey routine: driver flee mode 3 + the nav map, fight back when cornered.
  - Collector (type 5) and power relics: find the artifact / relic list (code near "Artifacts Enabled: Setting up
    %d Artifacts"); route to the nearest, chase carriers. TEAM FOX HUNT exists in the strings; maybe a cut mode.
- **Ship (level 15)**: stuck spot near (-460, 518); game code func_0018F8E0 reads through a null table there
  (51 TLB misses, log 2026-10-24) - check whether vanilla does it too.
- **Traffic routes**: fixed 2026-10-25 (cheap-mode cs overwritten from the stale vehicle every frame: far cars drove
  straight off their lanes). Route maps: TRAFFIC_TRACE build + tools/traffic (trafmap.py over the nav heightfields);
  all 6 traffic maps follow their street lanes now. Left: in-play check of the switch between cheap and full physics.
- **Stress test: big maps, full bots, split screen** (Ark 2026-10-25; maybe after the decomp is complete). Find the load
  ceiling and set a load-based bot cap. The slot cap already exists (bots.c `wanted`: bots <= 8 - connected humans,
  rebalanced on join / leave); what is missing is a cap by local screens / traffic.
  - Maps: Suburbs, Freeway, Prison Passage (big, traffic on). Runs: 1, 2, 3, 4 local views, every free slot a bot.
  - The local players' cars driven by the bot AI too (patrol + fight like bots), so every view moves and renders
    action: the test is unattended (qbrun, minimized) and the load is realistic.
  - Measure with the TMBR perf counters (logic vs render per frame) at EE cycle rate 100 / 130 / 180 / 300 %; note
    VU1 too (not covered by the EE cycle rate). Estimate before measuring: 2 views ~1.8x the EE (about 180 %),
    4 views ~2.5-3x (300 % may still drop frames).
  - Then: the cap table (views x traffic -> max bots) in the host settings, and a per-view pass for our HUD mods
    (damage reports / team reminder only draw on screen 0 today).
  - Retail baseline done (2026-10-25, tools/qb/retail: harness patched into SCUS_971.01, scripted 4 controllers on a
    PCSX2 multitap, frame time + EE busy = frame - sceGsSyncV wait). Everyone driving + firing, EE 100 %:
    2P Suburbs 30 % busy (peak 36), 0 slow; 3P Snowy Roads (4 views) 25 % (peak 35), ~1 slow / 300;
    4P Snowy Roads 34 % (peak 47), ~1 slow / 300; 2P Suburbs at 130 %: 25 %. Views cost the EE little (GS/VU work
    runs in parallel): TMBR's lag is the bots / traffic / AI.
    Retail only offers 3/4P on the small arenas (Elevators, Snowy Roads, Power Plant, Dogpound, Sewers, Minion's
    Stadium, Prison Ship, Asylum, Warhawk; unlocked without a save: Snowy Roads, Dogpound, Asylum). Forcing a big map
    there is open: patching initMapMenu2LevelNum's table did not change the level loaded (locks go by menu entry;
    the level comes from elsewhere - start from selectNext34PlayLevel / getCurrentLevelMenuSelection 0x167CB0).
    Next real step: the same harness on TMBR (bots + traffic) in 2/3/4P.
- **Bots and energy moves** (Ark 2026-10-25: bots use none). Every energy move is a player combo: `Combo::Check*Combo`
  (0x1245F8.. shield, cloak, freeze, minion, rear fire, drop mine, gas can, spec up/down/left/right) set the combo's
  `state` to the move (include/tmb/combo.hpp COMBO_TYPE_*: 1 freeze, 3 rear fire, 4 mine, 6 gas can, 7 shield,
  8 cloak); Combo::Update only runs in the human input update (func_0017BE80, our tmbr_ComboUpdate hook at 0x17BF00 -
  mods/quickmoves.s sets `state` the same way). Bots have no combo / pad, so nothing ever sets it. Next: find the
  reader of `state` in the vehicle update (what fires the move, with its energy cost), then let bots call it:
  freeze on a car about to escape or before a Darkside special ram, shield when a big hit is incoming (the dodge
  code already sees missiles), mines when chased (the evade code), cloak to break off a chase.
  Shield, used smart (Ark): energy covers about two shields back to back, then nothing, so never on cooldown or as
  a reflex. Only against a big hit that will land: a heavy weapon (power missile, napalm, ricochet, special, gas can,
  a special ram) closing in with a dodge that can't work (homing too close, boxed in, frozen), or when health is
  low enough that the hit would kill. Keep one shield in reserve when possible; skip it for light hits (fire /
  homing missiles, machine gun). Energy level: vehicle +0x420 (0..100, the HUD's energy bar).
  Freeze as a setup (Ark): freeze a target, then the big hit while it is stuck - skill weapon, gas can, special,
  power missile, a special ram; on teams, call a teammate's heavy weapon onto the frozen car.
  Freeze as a threat: the dodge code (bots.c `dodge`) treats every shot alike (rolls dodgeChance per difficulty); a
  freeze shot should always get the full dodge (and the shield if it can't be dodged), since being frozen sets up
  everything above. Needs the weapon kind of a shot (weapon table +0x14, not mapped yet: find the freeze's value,
  e.g. by logging the kind of shots a freeze creates).
  Darkside's personality (mods/bots.c `rammer`) then freezes before its special ram.
- **Per-car AI, the rest** (Ark 2026-10-25; done: the per-car table, alternate specials for Shadow / Axel via the
  special-up combo (energy handler case 9), turbo off flames (+0x20E0), weapon-aware shield, Spectre's wall-pass
  removed (postlink 0x1EC85C), Minion off option). Weapon kinds (TMBR wk log): MG 0, fire 2, homing 3, napalm 4,
  power 6, rico 7, pickups 11-13, freeze 14 (tagged in the log 2026-10-25), 15 ?, specials 17 Roadkill, 21 Spectre, 26 Grimm, 27 Axel, 28
  Manslaughter; freeze / mines / the other specials not seen yet (bots never used them in the logged match).
  Still to do:
  - Outlaw's turret secondary, Manslaughter dropping his special behind: not in the energy handler's switch -
    find how the player triggers them (launcher update, func_0015CD80 UpdateSpecial) and drive it for bots.
  - Darkside's T-slide: a first try is in (handbrake flick at ~90 on a special ram, 40 %) - check it lands side-on.
  - Roadkill's charge by confidence: the original AI has per-car special firing (aiCheckSpecialWeaponFiring
    0x1095F0: Crazy 8, Roadkill, Sweet Tooth, Darkside) - tune that rather than replace it.
  - 12 Pak as a bot (he only exists as a player's Roadkill skin).
  - Minion toggle on the game mods page itself (it's a host hotkey R3 + Triangle in the waiting room for now).
- **Learning from Ark's play**: a logger in the mod build records his matches vs bots (positions, speed, target,
  distances, weapon / move used, health, energy, a few times a second); fit the bot numbers (engage / break-off
  ranges, weapon choice by range, turbo / shield timing) to it.
- **Damage numbers for the AI** (tmbosvr.com/infocharts.html, online values): armour Minion 160, Manslaughter 155,
  Darkside 150, Warthog / Sweet Tooth 145, Junkyard Dog 135, Axel 116, Outlaw / Yellow Jacket / Shadow 110,
  Brimstone 105, Roadkill / Crazy 8 100, Spectre / Grimm 95. Weapons: machine gun 1 (upgraded 2), freeze 1, ram 10,
  homing 5, fire 8, rico 9, blue mine 11, gas can 11 (21), red mine 22, power 20, zoomy 20, satellite 69, reticle 70.
  Specials: Warthog 120 (42/s), Manslaughter up to 120 (dropped 90), Minion 75-100, Darkside ram 38 / T-slide 50 /
  airborne 65, Sweet Tooth 50, Outlaw 44 (64 with the secondary), Grimm 42, Crazy 8 40 (65 max), Brimstone 37,
  Roadkill 36 max, Shadow 33 (secondary 48), YJ turbo rams 30-110, Spectre 28, Junkyard Dog 25, Axel 22 (45 roller).
  In bots.c: special damage per car (finishing blows) and the retreat point by armour. Still to use: the shield should
  answer hits >= ~20 (power, red mine, specials, satellite, reticle) and ignore light ones (needs the shot's weapon
  kind: weapon table +0x14); threat weighting (keep away from an Outlaw / Warthog / Manslaughter lined up on us).
