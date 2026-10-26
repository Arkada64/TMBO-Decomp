#!/bin/bash
# TMBR player package (TODO 4d): a trimmed portable PCSX2 + preset + TMBR.exe launcher, in TMB Decomp/release/TMBR_Player.
# PCSX2 binaries come unmodified from the Ready2Play folder (GPL: README points at the source). Nothing in the
# Ready2Play folder is changed. BIOS: copied for Ark's own copy only (never shared: the zip step leaves it out).
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; R="/mnt/c/Users/Ark/Desktop/TMBO Ready2Play Edition"; P="$W/release/TMBR_Player"
mkdir -p "$P"/{inis,bios,memcards,game,textures,cache,logs,snaps,sstates}
cp -u "$R"/pcsx2-qt.exe "$R"/*.dll "$R"/qt.conf "$P"/
cp -ru "$R"/QtPlugins "$R"/D3D12 "$R"/resources "$P"/
: > "$P/portable.ini"
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
    -e '/^RecursivePaths = /d' -e '/^Paths = /d' "$R/inis/PCSX2.ini" > "$P/inis/PCSX2.ini"
grep -q "^StandardVolume = 0" "$P/inis/PCSX2.ini" && sed -i 's/^StandardVolume = 0/StandardVolume = 100/; s/^FastForwardVolume = 0/FastForwardVolume = 100/' "$P/inis/PCSX2.ini"
sed -i 's/^SDL = false/SDL = true/' "$P/inis/PCSX2.ini"
# HD pack (hard links into the renamed copy: no extra disk)
[ -d "$P/textures/SCUS-97196" ] || cp -al "$W/Textures/SCUS-97196" "$P/textures/"
# launcher
cp "$W/cloud/in/pkg/TMBR.cs" "$P/TMBR.cs"
( cd "$P" && /mnt/c/Windows/Microsoft.NET/Framework64/v4.0.30319/csc.exe /nologo /target:winexe /out:TMBR.exe TMBR.cs ) && rm "$P/TMBR.cs"
cp "$W/cloud/in/pkg/README.txt" "$P/"
du -sh --apparent-size "$P"; du -sh "$P"/* | sort -h | tail -8
grep -n "^EECycleRate\|^MultitapPort1\|^AspectRatio\|^upscale\|^Renderer\|^LoadTextureReplacements\|^StartFullscreen\|^EnableWideScreenPatches\|^StandardVolume\|^SDL =" "$P/inis/PCSX2.ini"
