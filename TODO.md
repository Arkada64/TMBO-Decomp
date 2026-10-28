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
  6. 12 Pak as a bot: DONE 2026-10-26 (host gives a bot slot 12 Pak 1 in 16, guests.c tmbr_BotCars; mask synced
     "\x01SB" in skins.c; marker says 12 PAK; tested with every bot 12 Pak: models, mounts, special).
     Still open (panel notes 2026-10-26: 29 of HC_STOCK's 112 meshes are outside hocollect's walk of the body roots
     0x469d0 / 0x3a0 - weapon-ish ones: 0x459c0 / 0x46060 front corners (x +-2.5, y 5), 0x4e300 front bumper,
     0x4ec60 right side out to x 5.1 (side gun), 0x4f300 roof (z 0.9-1.8), 0x4fa10 / 0x4fc20 rear deck, 0x1cc40 /
     0x1d680 / 0x294d0 / 0x29ba0 / 0x29f40 / 0x41a50 in local coords (moving parts); 0x46a50-0x47800 rear flames,
     0x47d30-0x4a580 tail light variants. Their placement / animation lives in the ops TMB lacks (20 / 26 / 27)): Also his weapon panels (Ark 2026-10-26: the hatches that open as the weapons come out):
     the Lost body pieces dropped in tools/lost/pakbuild.py (the 'side door left hanging open', 0x2bd70) are
     likely panels in their open pose; hook them to the weapon-mount animation. His mount points differ from
     Roadkill's: read them from the Lost file and move the mounts on his model copy (Roadkill untouched).
     2026-10-26: HC_STOCK has no animation data (Head-On drives its 8 jointed groups from code); its op19 nodes are
     per-panel damage states and 0x50690 lists the pieces that fly off. Done: pakbuild.py puts 12 Pak's rear-left
     hatch (homing / fire), rear-right hatch (power) and trunk lid (napalm) on Roadkill's animated rear panels /
     trunk (animation characters, damage states kept), so they open with Roadkill's weapon animations. Needs a
     look in game (hinges are Roadkill's, ~0.7 off 12 Pak's).
     Ark's check 2026-10-26: homing / fire come out right; the reticle floats above the roof, the power missile
     floats by the machine gun, gas can / rico don't open the trunk. Roadkill's weapon models (RKP): 4001 left rear
     launcher (rot -2.58 -6.07), 4002 right rear (2.64 -6.25), 4003 roof launcher under char 0x3d630 (power),
     4004 / 4005 rear-centre risers (chars 0x36230 / 0x3d940, napalm / rico), 4006 front right (char 0x3e780),
     4100 front guns (switch 45, +-2.77 3.49). Launcher anim handle k = car animation k (InitLauncher:
     animationGetHandle(h, v+0x20A8+6, v+0x20A4, k)); Roadkill also starts handle 30 (0xD54) for weapons 4 / 7.
     Next: move 4003 / reticle / 4004 / 4005 to 12 Pak's mount points (HC_STOCK op5 id 62 list) and put the trunk
     lid on the riser that napalm / rico use.
  6b. Gold Tooth back as his own car (Ark 2026-10-26), after 12 Pak's own-car work: the 2026-10-23 version was a skin
      inside Sweet Tooth's file (Sweet Tooth's wheels / mounts / collision / robot special, model and palettes
      squeezed under Sweet Tooth's size), removed as janky. As a separate car slot like 12 Pak: Head-On model
      (tools/lost/gtbuild.py), his own wheels, Lost's mount points, Sweet Tooth only as the stats / special donor.
      Needs a second free car-select slot and stays under the per-car texture / palette budget.
  6g. 128 MB EE (PCSX2 "Enable 128MB RAM (Dev Console)", ini [EmuCore] ExtraMemory = true; tested 2026-10-26,
      PCSX2 2.7): kernel memory size 0x8000000, memory at 48 / 120 MB reads back, a full bot match runs the same
      (60 fps, no exceptions) with it on or off. The game itself only uses its heap (grows up from .bss), so a
      fixed area high up (e.g. 64-128 MB) is free for us: extra cars, story data, bigger textures. Needs: the
      TMBR launcher turns the setting on; online, everyone must have it if content depends on it (check in the
      lobby); mods check GetMemorySize() and fall back when it is 32 MB.
      Ark 2026-10-26: with an older BIOS the 128 MB setting hard-locks PCSX2 right after the ELF loads (before the
      game runs); a newer BIOS handles it. The TMBR launcher / Ready2Play setup must ship or require a BIOS that does.
  6d. Car select for them DONE 2026-10-26 (skins.c, tested g100 with a placeholder model): the extras sit behind
      12 Pak's spot (right / left from there steps through them, name printed, donor's stand clip), each shows only
      when its \PCAR\Z?P.NGP is on the disc; picked one loads its own files, synced like 12 Pak; story uses the
      donor's movies. Codes: Gold Tooth zz, Old Pickup zx, Pit Viper zw, Outlaw 2 zv, Thumper zu, Twister zt.
      Models: tools/lost/hcbuild.py (generalised pakbuild). Ark 2026-10-26: all HC cars have odd lighting (never
      finished) - fix in the conversion (6e).
      Harbor City cars (Ark 2026-10-26), each its own car slot built from its own Lost model (like 12 Pak's rebuild):
      - Old Pickup: Junkyard Dog's stats; special = a weaker Minion-style special that only tracks ahead and slightly to
        the side. Needs animating; weapon racks unknown.
      - Pit Viper: Spectre's stats and special. Needs animating; weapon racks unknown.
      - Outlaw 2: Crazy 8's stats and special; move the special's effect so it fits (in Harbor City it sits above
        the siren).
      - Thumper: Brimstone's stats; special = Warthog's.
      - Twister: Mr. Grimm's stats; special = Axel's primary. Ark 2026-10-26 (Grimm is a bike): keep Grimm's stats, build
        the model on a 4-wheel donor, Axel's primary as the special (stats copied onto the 4-wheel donor type in code).
      - Gold Tooth: Sweet Tooth's stats; the size problem (model / texture budget) still needs a plan.
  6e. Some cars have oddly lit parts (Ark 2026-10-26): find and fix the lighting / normals on those parts.
  6f. DONE 2026-10-26 (modspage.c, tested g95: MINION / HEALTH / ALLY BOT rows under the native five, no TLB).
      MINION and HEALTH toggles move into the native game mods menu (Ark 2026-10-26), both default OFF.
  6c. Five Harbor City cars as new characters (Ark 2026-10-26): Old Pickup, Outlaw 2, Thumper, Pit Viper, Twister -
      files set aside in TMB Decomp/hc_cars (reference/wip/HEADON_ETE.md). Old Pickup / Pit Viper are near-static
      models (tiny pointer lists): animate them from Black's files (wheels / suspension / weapon parts of a donor).
      Each needs a car slot, so this follows the 12 Pak / Gold Tooth own-slot work.
  7. DONE 2026-10-26 (bots set launcher +4 = v +0x21B4 and fire the special at once: Manslaughter on a target close
     behind, Outlaw at 100-350 now and then; the special consumes the flag - tested; the special-up energy combo did
     not set it for them). Outlaw turret secondary / Manslaughter drop-behind (Launcher::UpdateSpecial 0x15CD80).
  8. DONE (see 6f). Minion toggle on the native game mods page.
  9. CODED 2026-10-26 (b), needs an in-game check. HEALTH lobby option: ON = health pickups spawn and can be picked
     up (overrides the TMA ruleset's no-health); OFF = no health on the map at all (replaces the TMA health rule; the
     respawn shield stays). Lobby toggle (host R3 + Circle, OFF by default) and the add-health patch (func_001E32D8:
     OFF = the baked TMA rule's jr ra, ON = its first two instructions back) work. The first pickup hiding did NOT
     work (Ark: health still on Suburbs): its loop read "+4*i" as an in-use flag (that is the per-type model table,
     then pickup fields), so most pickups were skipped, and the types were off by one (7 is energy, 8 is health,
     9 environment, 17 full health), so with ON health was hidden and untakeable too. Now (mods/bots.c, pickup
     section): every frame the health / full-health pickups (entry type at Pickups +0x5C + i*0x18 or the cs
     model, i < count +0x284C) are not drawn (cs +0xC = 0), the online full-health spawn slots are switched off
     (+0xA38 + k*0x2C = 0) and their glow cs (+0xA44) hidden; the host never respawns them (RegenPickup calls in
     UpdatePickups 0x179A64 / 0x179AF8 -> tmbr_PickupRegen) or places the full health (0x179A10 ->
     tmbr_PickupPlaceFullHealth); TakeHit ignores them (0x11F0DC, 0x167378, 0x167454). Pickup indexes are kept
     (no skipped creation), so host / client tables stay in step. Check in game: Suburbs with OFF - no health
     boxes, no full-health glow / hum, log "TMBR health: off, N of M pickups are health" (N should be all the
     health spots); with ON - health shows, heals, respawns, full health roams. Known edge: a pickup the game
     flips between energy and health (helicopter pickup, func_001406B8) stays hidden after it flips back to
     energy until energy respawns.
  10. CODED 2026-10-26 (b), needs an in-game check. Environment pickups removed for good (no option) and the storm
      cloud never shown. The first try hid type 8 (that was health) and claimed the cloud is an environment
      pickup - wrong: the environment pickup is type 9 (launcher slot 8; the TMA "No ENV" rule zeroes its amount
      0x3303E4) and the cloud is a particle effect (fx 0x24) made by thunderstormCreate in SuburbInitAfter
      (func_001AA000, levels 0 Suburbs and 18 Mini Suburbs) and Death2InitAfter (func_00127BE8, level 8 Snowy
      Roads). Now: both thunderstormCreate calls (0x1AA01C, 0x127C1C) go to an empty tmbr_NoStormCloud, so the
      handle stays -1 and thunderstormUpdate does nothing (no cloud, lightning or cloud sound; the Snowy Roads
      snow is separate and stays); type 9 pickups are hidden every frame, never respawned, and TakeHit ignores
      them. Check in game: no cloud on Suburbs / Mini Suburbs / Snowy Roads, no environment pickup, log
      "TMBR pickups: N environment pickups hidden".
  11. (Plan: reference/wip/STORY_PLAN.md, 2026-10-26 - phases: offline story run, movies, story level files, bosses,
      co-op.) Story mode (single player) with retail's cutscenes: ~2.9 GB of retail movies onto the disc (fine for PCSX2), the
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
  4e. DONE 2026-10-26, Ark to judge (guests.c tmbr_LoadScreen, hook 0x1B3CA4 = UI state 0x29's func_001CBD18:
      halves 9902 top / 9901 bottom = shell +0xB950 screens, slam together with gravity + bounce + shell sfx 0xD,
      then the load). Retail loading screen (Ark 2026-10-26): TMB's load screen where the top and bottom halves come crashing
      down; TMBO skips it. Bring it back for TMBR's level loads.
      Findings 2026-10-26 (retail decomp ~/tmb_decomp on the PC, symbols): retail uiLoadLevel__Fv (0x194C60, a UI
      state: setPov, smoothEasyIn, levelLoadCharBlurb) + LoadingBarBackground__Fv (0x1944B0: 63 hierSetSwitch,
      a jump table on oldScreen; slides two shell "screen" objects - shell +0x17170 / +0x17230, cs +0x20, y at
      cs +0x18 by 200 / 400 per frame until they meet - then exitUi). The 6 screens (0x30 apart from shell
      +0x17140) are set up in uiInitScreens__FP3_cs (0x18F890). TMBO's uiInitScreens = func_001B44E0 (same float
      constants) and has no screen / halves code; TMBO's shell struct offsets differ (0x19BE4 / 0x1A16C ...).
      TMBO's loading screen (qb pic 2026-10-26) still shows a tiled top half and a metal bottom half with the LOADING
      bar - the halves look present, only static. Retail screens: 6 x 0x30 structs at shell +0x17140, cs at +0x20,
      y at cs +0x18 (uiInitScreens zeroes / places them); the cs pointers are not written in retail shell.s (set by
      a table-driven loader?). TMBO's main UI loop is func_001B2B68 (calls func_001B44E0 = uiInitScreens).
      Checked in the lobby (2026-10-26): TMBO's shell +0x17140 screens are all empty (cs 0) - the shell offsets
      below 0x19BE4 match retail (above: +0x28) and shell +0x2110's cs exists, so TMBO never makes the screens.
      Next: find the halves' hier nodes in SHELL1.NGP (retail's screen cs come from a table-driven loader), make
      their cs, then a
      mod step that starts them off screen and slides them in (200 / 400 per frame as retail) before the load.
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
  - DONE 2026-10-26: Outlaw's turret secondary, Manslaughter's drop-behind (launcher +4) and Shadow / Axel's second
    specials (the combo's own writes) set directly by bots before the special; +0x22B0 is always 0 for bots, so
    the old Shadow / Axel request never fired (test: Shadow's second special now shows, kind 19).
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

## Queued 2026-10-27 (Ark: "queue it for tomorrow")
- Bot routing: merge the maps' attractor graph into the baked route maps (tools/nav): read each map's attractor
  points / links, add "jump links" where linked attractors sit in unconnected route-map parts (Freeway stadium ring,
  Skyscrapers roofs, Junkyard building), follow them at speed in mods/nav.c. Step 1: attractor overlay pictures for
  Freeway, Skyscrapers, Junkyard for Ark to check.
- g177 (2026-10-28, Ark: jump-link every map with bot work): the route maps keep every part the attractor graph
  joins to the main one both ways, with the attractor links between parts as jump links (navbake.c A*, nav.c
  drives them straight at full gas + turbo, run-up turbo before the take-off). Jumps: Suburb 24, Junkyard 42,
  Freeway 18 (stadium + south block), Skyscrapers 12, Stadium 20, Loop 5, Death1 4; none on the others. Roof maps
  still use the game's own driving (its attractor graph already has these jumps). Also fixed: the files' header
  was 28 bytes but the game read 36 (every node one off). Overlays: tools/nav/attr_overlay.py.
- DONE g176 (2026-10-28): traffic removed (traffic.c / .s / _nodes.c in mods/_to_delete; collision, hit, net damage,
  loader and frame hooks out; lobby TRAFFIC line / host key gone; ZSF* off the disc; the kill-feed hook stays for the
  remote-car skip). Peds off Prison Ship / Asylum (ZSP* / ZAP* packs, ZZSHIP / ZZASYLUM.PED, inmate retyping); the
  maps' own retail .PED files are used again there. Freeway / Prison Passage peds kept. Watch: false "killed" messages.
