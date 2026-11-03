#!/bin/bash
# TMBR player package (TODO 4d): a trimmed portable PCSX2 + preset + TMBR.exe launcher, in TMB Decomp/release/TMBR_Player.
# PCSX2 binaries come unmodified from the Ready2Play folder (GPL: README points at the source). Nothing in the
# Ready2Play folder is changed. BIOS: copied for Ark's own copy only (never shared: the zip step leaves it out).
set -e
# Layout (Ark 2026-10-26): top level = TMBR.exe, README.txt, bios\, game\, emulator\ (all of PCSX2; it makes its own
# cache / logs / snaps ... folders there when it needs them).
W="/mnt/d/TMB Decomp"; R="/mnt/d/TMBR/emulator"; P="$W/release/TMBR_Player"; E="$P/emulator"
mkdir -p "$P"/{bios,game} "$E"/{inis,memcards}
cp -u "$R"/pcsx2-qt.exe "$R"/*.dll "$R"/qt.conf "$E"/   # (not updater.exe: no auto updates, Ark 2026-10-26)
cp -ru "$R"/QtPlugins "$R"/D3D12 "$R"/resources "$E"/
: > "$E/portable.ini"
cp -u "$R"/bios/* "$P"/bios/
# settings: Ready2Play's, minus its game list / cheats / built-in widescreen patch (TMBR has its own), plus multitap
pgrep -f "[t]ools/qb/qbrun.py" > /dev/null && { echo "a test is running (its ini is muted): try later"; exit 1; }
sed -e 's/^EnableCheats = .*/EnableCheats = false/' \
    -e 's/^EnableWideScreenPatches = .*/EnableWideScreenPatches = false/' \
    -e 's/^MultitapPort1 = .*/MultitapPort1 = true/' \
    -e 's/^DumpReplaceableTextures = .*/DumpReplaceableTextures = false/' \
    -e 's/^LoadTextureReplacements = .*/LoadTextureReplacements = false/' \
    -e 's/^PrecacheTextureReplacements = .*/PrecacheTextureReplacements = false/' \
    -e 's/^EnablePINE = .*/EnablePINE = false/' \
    -e 's/^CheckAtStartup = .*/CheckAtStartup = false/' \
    -e '/^RecursivePaths = /d' -e '/^Paths = /d' "$R/inis/PCSX2.ini" > "$E/inis/PCSX2.ini"
grep -q "^StandardVolume = 0" "$E/inis/PCSX2.ini" && sed -i 's/^StandardVolume = 0/StandardVolume = 100/; s/^FastForwardVolume = 0/FastForwardVolume = 100/' "$E/inis/PCSX2.ini"
sed -i 's/^SDL = false/SDL = true/' "$E/inis/PCSX2.ini"
sed -i "s#^Bios = .*#Bios = ../bios#" "$E/inis/PCSX2.ini"   # (the launcher writes the full path on every launch)
# (HD texture pack dropped 2026-10-26, Ark)
# launcher
cp "$W/cloud/in/pkg/TMBR.cs" "$W/cloud/in/pkg/TMBR.ico" "$W/cloud/in/pkg/logo.png" "$P/"
( cd "$P" && /mnt/c/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe /nologo /target:winexe /win32icon:TMBR.ico /resource:logo.png,TMBR.logo.png /out:TMBR.exe TMBR.cs ) && rm "$P/TMBR.cs" "$P/TMBR.ico" "$P/logo.png"
cp "$W/cloud/in/pkg/README.txt" "$P/"
du -sh --apparent-size "$P"; ls "$P"
grep -n "^EECycleRate\|^MultitapPort1\|^AspectRatio\|^upscale\|^Renderer\|^LoadTextureReplacements\|^StartFullscreen\|^EnableWideScreenPatches\|^StandardVolume\|^SDL =" "$E/inis/PCSX2.ini"
