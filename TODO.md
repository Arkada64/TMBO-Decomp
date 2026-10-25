# TODO (later)

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
- **Suburbs traffic** (mods/traffic.c): online Suburbs had traffic stripped; we use retail's models (ZSF pack) on the
  online map's leftover street points (280). Half the cars spawn at z ~280-313 vs ~70-130, and cars drive off the road.
  Next: dump the points from one run, drop the ones far above their neighbours / not in a lane; else traffic off there.
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
  power 6, rico 7, pickups 11-13, debris 14 / 15, specials 17 Roadkill, 21 Spectre, 26 Grimm, 27 Axel, 28
  Manslaughter; freeze / mines / the other specials not seen yet (bots never used them in the logged match).
  Still to do:
  - Outlaw's turret secondary, Manslaughter dropping his special behind: not in the energy handler's switch -
    find how the player triggers them (launcher update, func_0015CD80 UpdateSpecial) and drive it for bots.
  - Darkside's T-slide (side-on ram) for bonus damage.
  - Roadkill's charge by confidence: the original AI has per-car special firing (aiCheckSpecialWeaponFiring
    0x1095F0: Crazy 8, Roadkill, Sweet Tooth, Darkside) - tune that rather than replace it.
  - The freeze dodge: the freeze's weapon kind (log one), then full dodge + shield fallback for it.
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
