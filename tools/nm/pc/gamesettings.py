# gamesettings.py ELF : PCSX2 per-game settings for this build of TMB Reloaded (gamesettings/SCUS-97196_<CRC>.ini,
# keyed by the ELF's CRC, which changes every build): EE cycle rate 130 % (EECycleRate = 1). Ark, 2026-10-25:
# with 7 bots and traffic the mod build is playable at 130 %. Only this build's file is written; other games keep
# their own settings. Widescreen (2026-10-26): AspectRatio 16:9 - the build widens every view (mods/freecam.c).
import os, sys
sys.path.insert(0, os.path.dirname(__file__))
from elfcrc import crc
G = "/mnt/c/Users/Ark/Desktop/TMBO Ready2Play Edition/gamesettings"
c = crc(sys.argv[1])
p = "%s/SCUS-97196_%08X.ini" % (G, c)
if os.path.exists(p) and "EECycleRate" in open(p).read(): print("gamesettings: already there", p); sys.exit(0)
with open(p, "a") as f: f.write("; TMB Reloaded build (written by the ISO build)\n[EmuCore/Speedhacks]\nEECycleRate = 1\n"
                               "[EmuCore/GS]\nAspectRatio = 16:9\n")   # widescreen: the build renders a 16:9 picture (freecam.c)
print("gamesettings: wrote", p)
