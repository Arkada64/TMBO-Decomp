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
  Darkside's personality (mods/bots.c `rammer`) then freezes before its special ram.
