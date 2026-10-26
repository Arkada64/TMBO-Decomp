# TODO (later)

- **Split screen - status and open items (2026-10-26 night, Ark asleep; work top to bottom):**
  Done: join on controllers 2-4 (START), real car select (camera flies to the cars), car change (START again),
  leave (SELECT), name entry on the game's keyboard (START = done), rows in the player list, the guest's own car
  loaded with the level, split from the first frame, 2 views (halves) / 3 (quarters + blank) / 4 (quarters), 16:9
  view widths, HUD per view (radar + weapon bay at the edges, sized per layout), top-right game type / score hidden,
  bay panel (Ldr/Rnk/Pts/...) placed per layout, death scoreboard shrunk per view with short titles, damage reports
  per screen, guests take damage, respawn shield (same 10 s timer as P1), guests on the leaderboard by name
  (net object like the bots), "cars left" counter counts guests.
  Done 2026-10-26 morning: bay panel per player (own car colour, own rank; nudged right off the car in 2P and 4P),
  compact quarter panel (size 8), death scoreboard short titles, 3P empty quarter black (view 3's clear colour is
  rewritten by the time of day during views 0-2; set again in view 2's HUD step), tests use no real controllers.
  Open:
  1. Guests' spawn shield is not animated (pixels identical 4 s apart; the timer / state match P1's). The shimmer is
     a UV scroll from the car cs's animation channels (pktAddVu1Obj -> pktClipUVScroll, values via scratchpad
     0x70000020 = the current _animCharInstance during hierTraverse, hierc func_00212430); Ark: P1's scrolls.
     Not the shield switches (0x2068 / 0x206C, both 1 or 2 by car +0x24B4, same for guests) nor forceField (boss
     only). Next: which animCharInstance a car draws with and who advances it (per view? owner 1 only?); check
     bots' shields and P1's shield seen from a guest view.
  2. Sound in split: the mixer (calcDualMonoMixVolPan, func_0019B5F8 ...) loops over every view's camera (count
     game +0x2BB60 = the render loop's view count), so guests should be heard around their cars - Ark to listen.
  3. Guests joining on a client console (host makes the car over chat) - feature, lower priority.
  4. Remove debug prints (guest hp / shield every 30 frames) before an ISO.
  Then the rest of the queue: 4b real widescreen HUD layout, 4c HD texture pack, 4d TMBR player package,
  4e retail loading screen, 5-14 (bots reticle, 12 Pak bot + his weapon panels / own mount points, Outlaw /
  Manslaughter, minion toggle page, HEALTH option, environment pickups gone, story mode, co-op + ally, online
  co-op, roguelike).

- **Work queue (Ark 2026-10-26, top to bottom):**
  1. Split-screen guests: car select (the real screen repeats "PLAYER n CHOOSE A VEHICLE" on that controller).
  1b. Guest names (Ark 2026-10-26): on joining, the game's own keyboard + text box asks for a name (default
      PLAYER 2 / 3 / 4); shown in the player list, scoreboard and kill feed. Status: 1-3 work on the host
      (join / car select / car change / leave, player list row, own car, view, HUD, scoreboard per half).
  2. Guests joining (START on controller 2-4 in the waiting room; on a client the host makes the car over chat).
  3. Guest camera pulled back (retail split distance) + HUD per view.
  4. Letterbox off - NOT the game (2026-10-26): TMBO draws the full 640x448 (view layouts D_004CEE40, GS DISPLAY2 dh
     447). The bars are PCSX2 AspectRatio = 16:9 (Ready2Play PCSX2.ini, and a leftover TMBR gamesettings ini) seen in a
     4:3 frame. Fix = 4:3 / Auto in PCSX2, or real widescreen (4b). HUD anchors (hud +0x800 left cluster -2.47 3.36
     1.11, +0x810 right cluster 2.11 3.5 -0.89; x right, y forward, z up). Retail TMB widescreen pnach (PCSX2
     patches.zip SCUS-97101_073696DA) lists every view's FOV + HUD constant (1P, 2P horizontal/vertical, 4P).
  5. DONE (002db01: bots hold the reticle 1.5-4.5 s, longer on a still target). Bots charge the reticle weapon (satellite-style, hold up to 5 s; Launcher func_001549A0 charger code,
     GetSatelliteReticle; find the held-fire input first).
  5b. DONE 2026-10-26, Ark to judge in play (bots.c aimShot: power missile / zoomy = slot type 13, confirmed in a
      run: 16 line-ups in 5 min, most 1-2 shots; stop, brake, fine aim, fire within
      3.4 deg, leave on turbo; chance 30/55/75 % by difficulty). Bots aim the big shots (Ark 2026-10-26): they fire power missiles / zoomys (and other slow, straight shots)
      on the move and mostly miss. For those weapons let a bot slow down / stop, line up the shot, fire its load,
      then get back up to speed - sometimes, not every time.
  6. 12 Pak as a bot. Also his weapon panels (Ark 2026-10-26: the hatches that open as the weapons come out):
     the Lost body pieces dropped in tools/lost/pakbuild.py (the 'side door left hanging open', 0x2bd70) are
     likely panels in their open pose; hook them to the weapon-mount animation. His mount points differ from
     Roadkill's: read them from the Lost file and move the mounts on his model copy (Roadkill untouched).
  6b. Gold Tooth back as his own car (Ark 2026-10-26), after 12 Pak's own-car work: the 2026-10-23 version was a skin
      inside Sweet Tooth's file (Sweet Tooth's wheels / mounts / collision / robot special, model and palettes
      squeezed under Sweet Tooth's size), removed as janky. As a separate car slot like 12 Pak: Head-On model
      (tools/lost/gtbuild.py), his own wheels, Lost's mount points, Sweet Tooth only as the stats / special donor.
      Needs a second free car-select slot and stays under the per-car texture / palette budget.
  6c. Five Harbor City cars as new characters (Ark 2026-10-26): Old Pickup, Outlaw 2, Thumper, Pit Viper, Twister -
      files set aside in TMB Decomp/hc_cars (reference/wip/HEADON_ETE.md). Old Pickup / Pit Viper are near-static
      models (tiny pointer lists): animate them from Black's files (wheels / suspension / weapon parts of a donor).
      Each needs a car slot, so this follows the 12 Pak / Gold Tooth own-slot work.
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
        3 lives like the player. Bot-to-bot damage only (players hit everyone at full damage): enemy bots hitting each
        other do 10 %, enemy bots hitting the ally do 20 % (so it isn't killed at once), the ally hitting enemies does 50 %
        (the player has to fight alongside it); enemy AI prefers human targets but can
        still go for it; it sometimes stays near the player; in the Warhawk boss fight it leaves the tankers alone so
        players can position them.
  13. Online co-op story: story enemies / bosses are AI cars (synced like bots), cutscenes and scripted events
      host-driven (hidden chat messages).
  4b. Widescreen done properly (Ark 2026-10-26): the FOV change works, but the HUD parts placed through the 3D
      projection moved inward and the online score text sat on the weapon list / health. Lay the HUD out for 16:9
      (elements to the edges, sprites x 3/4 so they aren't stretched); widescreen stays off by default until then.
  4c. DROPPED 2026-10-26 (Ark: removed from the launcher and his drive - files moved to TMB Decomp/_to_delete for
      him to delete). HD texture pack (Ark 2026-10-26): Textures/SCUS-97101 (2275 .dds, 431 MB, made for retail TMB). TMBO/TMBR is
      SCUS-97196. Checked 2026-10-26 (QB_TEXDUMP run, 2P match): 467 textures dumped, 369 share texture + CLUT hash
      with the pack but TMBO draws them with TEX0 TCC 0 (name bits 0x4000; 11 also T8H 0x1B vs T8 0x13).
      Textures/SCUS-97196/replacements = hard links renamed (cloud/in/g3/tx_map.py): 369 exact hits, loads
      (QB_TEXLOAD run). Second pass: direct-colour names (2 fields) renamed too, 9 near-palette aliases
      (tools/hdpack/aliases.txt, mean RGB diff < 20): 379 of 523 seen textures covered. The rest (cloud/hd_miss,
      contact sheet): TMBO's own menu / lobby text and logo pieces, effects TMBO recoloured (palette diff 30-250),
      and a handful of world textures (dirt, stone, planks) the pack never had - they need upscaling of their own.
      Unseen maps / menus may hold more misses.
  4d. TMBR player package (Ark 2026-10-26) - first build 2026-10-26: TMB Decomp/release/TMBR_Player
      (tools/package/pk_build.sh + TMBR.cs launcher with the game's logo as icon: PLAY, 16:9 / fullscreen / potato,
      PCSX2 settings; ~62 MB). Left: TMBR.iso into game/, zip without bios, untested by Ark.
      Original note: portable PCSX2 trimmed to what TMBR needs, settings preset (EE 130%,
      multitap, renderer), a TMBR.exe launcher that boots the ISO straight in (-batch -fullscreen), and toggles
      (HD textures, potato preset, upscale, later widescreen). The user supplies the BIOS; a rebuilt PCSX2 means
      publishing its source (GPL).
  4e. Retail loading screen (Ark 2026-10-26): TMB's load screen where the top and bottom halves come crashing
      down; TMBO skips it. Bring it back for TMBR's level loads.
      Findings 2026-10-26 (retail decomp ~/tmb_decomp on the PC, symbols): retail uiLoadLevel__Fv (0x194C60, a UI
      state: setPov, smoothEasyIn, levelLoadCharBlurb) + LoadingBarBackground__Fv (0x1944B0: 63 hierSetSwitch,
      a jump table on oldScreen; slides two shell "screen" objects - shell +0x17170 / +0x17230, cs +0x20, y at
      cs +0x18 by 200 / 400 per frame until they meet - then exitUi). The 6 screens (0x30 apart from shell
      +0x17140) are set up in uiInitScreens__FP3_cs (0x18F890). TMBO's uiInitScreens = func_001B44E0 (same float
      constants) and has no screen / halves code; TMBO's shell struct offsets differ (0x19BE4 / 0x1A16C ...).
      Next: are the halves' meshes still in TMBO's SHELL NGP (retail screen node ids vs TMBO's), then port the
      two functions as a mod UI step before the level load.
  13b. Garage / car colour (Ark 2026-10-26, idea): recolour a car's body textures (palette / CLUT tint at load, or
      a texture swap like the 12 Pak skin), choice synced to other players like the skin byte.
  14. (Last, very experimental) Roguelike story option (no story: online's default loading screen instead of the
      story loading screens / dialogue, no cutscenes; synchronous entry by default so everyone starts together): each round a choice of two maps from any map, a visited map
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
