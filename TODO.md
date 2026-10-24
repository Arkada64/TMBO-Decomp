# TODO (later)

- **Ram damage in damage reports, online** (mods/dmgreport.c). Rams on another player's car still show nothing.
  The hook on the type-60 ram game event (`tmbr_RamSent`, `netSendGameEvent` call at 0x121744 in
  func_001214C0) is in both builds, but a test on 2026-10-24 showed no reports for rams. Next step: the debug
  pnach (`DMGDBG=1 bash tools/mods/make_pnach.sh`) logs "TMBR ram" lines. No lines = this console never sends
  the event (the victim's console works rams out itself), so watch the other car's health after any collision
  instead. Lines = the event's fields are being misread. Easier once more of the collision code is decompiled.
