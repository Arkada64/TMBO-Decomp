#!/bin/bash
# Make a pnach of the TMB-Reloaded gameplay mods for the UNMODIFIED online game (SCUS-97196, CRC C54E5CF2):
# release/SCUS-97196_C54E5CF2.pnach = the community pnach (unchanged) + our sections under it.
# Code cave: 0x1B0978..0x1B10AC, traffic code that is dead online once two calls are NOPed - the same two
# the community Respawn Shield NOPs: 0x138D10 (-> func_001B0978, isTollClear, HighwayDirector::update) and
# 0x1881A8 (InitializeFodderCars -> func_001B0688 -> the HighwayDirector::init functions at 0x1B0D30.. and setNumSegments, only called by them).
# Needs the matching ELF built in the private copy (build/SCUS_971.96.elf, with symbols).
set -e
W="/mnt/c/Users/Ark/Desktop/TMB Decomp"; T=/home/ark/modshome/tmbo_decomp; B=$T/build/SCUS_971.96.elf
CAVE=0x1B0978; CAVE_END=0x1B10E0
# second cave for the C parts: getVehicleSection .. func_001B1B68 (0x1B10E8..0x1B1CC8), all only reachable
# from the two NOPed calls (setTrafficDensity at 0x1B10E0 between them is live)
CAVE2=0x1B10E8; CAVE2_END=0x1B1CC8
O=$(mktemp -d)
{ echo '.set noat'; echo '.set noreorder'; echo '.section .text, "ax"'
  sed -n '/^.globl tmbr_InitPOV/,/^tmbr_SpecMark_end:/p' "$W/mods/camera_pnach.s"
  # per-section switches (freecam.c tmbr_en): outside every bulk-written range, so sections never clear each other's
  echo '.align 2'; echo '.globl tmbr_en'; echo 'tmbr_en: .word 0, 0, 0'
  grep -vE '^\.set|^\.section' "$W/mods/dmgreport_pnach.s"
  grep -vE '^\.set|^\.section' "$W/mods/quickmoves.s"
  echo 'tmbr_qm_end:'
} > $O/cave.s
mips-linux-gnu-as -EL -march=5900 -G0 -no-pad-sections -mabi=eabi $O/cave.s -o $O/cave.o
cd $T
tools/sn_cc.sh -c -Iinclude -isystem include/gcc -isystem include/gcc/gcc-lib -isystem include/sdk \
  -isystem include/sdk/common -isystem include/sdk/ee -O2 -G0 -fno-common -DTMBR_PNACH -DTMBR_TRAFFIC_ON=0 "$W/mods/freecam.c" -o $O/freecam.o
tools/sn_cc.sh -c -Iinclude -isystem include/gcc -isystem include/gcc/gcc-lib -isystem include/sdk \
  -isystem include/sdk/common -isystem include/sdk/ee -O2 -G0 -fno-common -DTMBR_PNACH "$W/mods/dmgreport.c" -o $O/dmg.o
cat > $O/cave.ld <<EOF
SECTIONS {
  . = $CAVE;
  .cave : {
    $O/cave.o(.text)
  }
  . = $CAVE2;
  .cave2 : {
    tmbr_fc_code = .;  $O/freecam.o(.text) $O/freecam.o(.rodata) $O/freecam.o(.lit4) $O/freecam.o(.lit8)
                       $O/dmg.o(.text) $O/dmg.o(.rodata) $O/dmg.o(.lit4) $O/dmg.o(.lit8)
    tmbr_fc_vars = .;  $O/freecam.o(.data) $O/freecam.o(.sdata) $O/freecam.o(.bss) $O/freecam.o(.sbss)
                       $O/dmg.o(.data) $O/dmg.o(.sdata) $O/dmg.o(.bss) $O/dmg.o(.sbss)
    tmbr_fc_end = .;
  }
  /DISCARD/ : { *(.reginfo) *(.mdebug*) *(.comment) *(.pdr) *(.gnu.attributes) *(.MIPS.abiflags) }
}
EOF
mips-linux-gnu-ld -EL -T $O/cave.ld --just-symbols=$B --defsym tmbr_ret_17BF80=0x17BF80 \
    --defsym tmbr_ret_17C060=0x17C060 --defsym tmbr_ret_139220=0x139220 --defsym tmbr_ret_1E24D0=0x1E24D0 --defsym tmbr_ret_1E24A4=0x1E24A4 -o $O/cave.elf $O/cave.o $O/freecam.o $O/dmg.o
mips-linux-gnu-nm -n $O/cave.elf | grep -vE ' [aAU] ' > $O/syms.txt
mips-linux-gnu-objcopy -O binary -j .cave $O/cave.elf $O/cave.bin
mips-linux-gnu-objcopy -O binary -j .cave2 $O/cave.elf $O/cave2.bin
BASE=0x$(mips-linux-gnu-objdump -h $O/cave.elf | awk '$2==".cave"{print $4}')   # .cave start (aligned)
python3 - "$O" "$W" $BASE $CAVE_END $CAVE2 $CAVE2_END <<'EOF'
import sys, struct, re
O, W, cave, end = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
cave2, end2 = int(sys.argv[5], 16), int(sys.argv[6], 16)
assert 0x1B0978 <= cave < 0x1B0990, hex(cave)
b = open(f"{O}/cave.bin", "rb").read(); b += b"\0" * (-len(b) % 4)
assert cave + len(b) <= end, f"cave too small: {len(b):#x} bytes"
S = {}
for l in open(f"{O}/syms.txt"):
    f = l.split()
    if len(f) == 3: S[f[2]] = int(f[0], 16)
b2 = open(f"{O}/cave2.bin", "rb").read()
assert S["tmbr_fc_code"] == cave2, hex(S["tmbr_fc_code"])
b2 += b"\0" * max(0, S["tmbr_fc_end"] - cave2 - len(b2))   # .bss isn't in the binary dump: zeros
b2 += b"\0" * (-len(b2) % 4)
assert cave2 + len(b2) <= end2, f"cave 2 too small: {len(b2):#x} bytes"
def words(lo, hi):
    if cave2 <= lo < end2: return [(a, struct.unpack_from("<I", b2, a - cave2)[0]) for a in range(lo, hi, 4)]
    return [(a, struct.unpack_from("<I", b, a - cave)[0]) for a in range(lo, hi, 4)]
J = lambda op, t: (op << 26) | ((t >> 2) & 0x3FFFFFF)
def lines(ws, place=1): return "\n".join(f"patch={place},EE,2{a:07X},extended,{v:08X}" for a, v in ws)
NOPS = """//traffic code used as code cave: NOP its two calls (the same ones TMA Ruleset/ Respawn Shield NOPs)
patch=1,EE,20138D10,extended,00000000
patch=1,EE,201881A8,extended,00000000"""
community = open(f"{W}/mods/community.pnach", encoding="utf-8", errors="replace").read()
# our old peds experiment was appended to this copy without a [section] header (it would join Respawn Shield):
# keep the community file as published, and give the peds patch its own section below
peds = ""
i = community.find("\nauthor=TMB-Reloaded")
if i >= 0:
    peds = community[i:].strip(); community = community[:i]
    peds = peds.replace("author=TMB-Reloaded\n", "", 1)
hooks = {0x17BF00, 0x17BF78, 0x139D38, 0x1395E0, 0x1E2498, 0x1E249C, 0x121744}   # 0x139218: the Spectator/ Alternate View codes (turn them off)
for m in re.finditer(r"patch=\d,EE,([0-9A-Fa-f]{8}),", community):
    a = int(m.group(1)[1:], 16)
    assert not (cave <= a < end) and not (cave2 <= a < end2) and a not in hooks, f"community patch at {a:08X} overlaps"
head = community.rstrip() + "\n\n\n//// TMB-Reloaded Patches (https://github.com/Arkada64/TMB-Reloaded)\n"
STATE = f"""//button state, cleared once at boot
{lines(words(S["tmbr_prevDpad"], S["tmbr_qm_end"]), 0)}"""
# Quick moves: NOT in the TMA play file (a TMA admin ruled it cheating); kept in our full pnach and the mod build
qm_sec = f"""
[Arkada Tweaks/ Quick Energy Moves]
author=TMB-Reloaded
description=Hold L1 + D-Pad: Up Freeze, Right Shield, Left Mine, Down Rear Fire. Hold R1 + D-Pad: Right Charged Mine, Left Invisibility. The classic combos still work. Best with Tap Weapon Switch (holding L1/R1 for a move then doesn't switch weapons). Not allowed in TMA lobbies.
{NOPS}
//Combo::Update call -> tmbr_ComboUpdate
patch=1,EE,2017BF00,extended,{J(3, S["tmbr_ComboUpdate"]):08X}
{lines(words(S["tmbr_ComboUpdate"], S["tmbr_ShoulderTap"]))}
{STATE}
"""
tap_sec = f"""
[Arkada Tweaks/ Tap Weapon Switch]
author=TMB-Reloaded
description=L1/R1 switch weapons only on a quick tap (under 1/4 s); holding them never switches. L1 + R1 together still jumps.
{NOPS}
//after the shoulder buttons are read -> tmbr_ShoulderTap (replaces beqz $3, 0x17C060)
patch=1,EE,2017BF78,extended,{J(2, S["tmbr_ShoulderTap"]):08X}
{lines(words(S["tmbr_ShoulderTap"], S["tmbr_prevDpad"]))}
{STATE}
"""
EN = lambda i: f"//switch this part on\npatch=0,EE,2{S['tmbr_en'] + 4 * i:07X},extended,00000001"
FRAME = f"""//per-frame camera update -> tmbr_CameraUpdate (shared by Free Cam, Damage Reports, Default Camera & HUD)
patch=1,EE,201395E0,extended,{J(3, S["tmbr_CameraUpdate"]):08X}
{lines(words(S["tmbr_fc_code"], S["tmbr_fc_vars"]))}
//constants and state, written once at boot
{lines(words(S["tmbr_fc_vars"], S["tmbr_fc_end"]), 0)}"""
out = f"""
[Arkada Tweaks/ Default Camera - 2nd View + Weapon List HUD]
author=TMB-Reloaded
description=Matches start on the camera view you get after pressing Select + Down once, with the weapon bay in its list view (Select + Right still cycles it).
{NOPS}
//match-start SetCameraPOV -> tmbr_InitPOV (same call, then one Select+Down step)
patch=1,EE,20139D38,extended,{J(3, S["tmbr_InitPOV"]):08X}
{lines(words(S["tmbr_InitPOV"], S["tmbr_InitPOV_end"]))}
{FRAME}
{EN(2)}

[Arkada Tweaks/ Spectator Free Cam]
author=TMB-Reloaded
description=Free camera while spectating: left stick move, right stick look, L2/R2 down/up, hold R1 faster. R3 turns it on and off while spectating (Select keeps its normal spectator use). Turn OFF the Spectator/ Alternate View codes when using this (they patch the same instruction).
{NOPS}
//spectator start (SetCameraPOV(.., 5)) -> tmbr_SpecMark (marks spectating)
patch=1,EE,20139218,extended,{J(2, S["tmbr_SpecMark"]):08X}
{lines(words(S["tmbr_SpecMark"], S["tmbr_SpecMark_end"]))}
{FRAME}
{EN(0)}

[Arkada Tweaks/ Damage Reports]
author=TMB-Reloaded
description=Twisted Metal: Head-On style "N Pts Damage" under the kill feed. Confirmed damage only: online it shows the health your target actually lost (from its owner's update), so hits that only landed on your screen show nothing. Rams count too. Hits on the same car within 1 s add up.
{NOPS}
//every hit (func_001E1C40, before the owner check) -> tmbr_DmgGate (counts it, then the original check)
patch=1,EE,201E2498,extended,{J(2, S["tmbr_DmgGate"]):08X}
patch=1,EE,201E249C,extended,00000000
//rams on remote cars (sent as a game event) -> tmbr_RamSent (sends it, then watches the victim)
patch=1,EE,20121744,extended,{J(3, S["tmbr_RamSent"]):08X}
{lines(words(S["tmbr_DmgGate"], S["tmbr_DmgGate_end"]))}
{FRAME}
{EN(1)}
"""
if peds:
    out += f"""
[Arkada Tweaks/ Pedestrians Online (experimental, not synced)]
author=TMB-Reloaded
{peds}
"""
open(f"{W}/release/SCUS-97196_C54E5CF2.pnach", "w", newline="\r\n").write(head + qm_sec + tap_sec + out)
# TMA play file: no Quick Energy Moves and no Tap Weapon Switch (it exists for the quick moves) - user's call
import os; os.makedirs(f"{W}/release/TMA", exist_ok=True)
open(f"{W}/release/TMA/SCUS-97196_C54E5CF2.pnach", "w", newline="\r\n").write(head + out)
print(f"cave used {len(b):#x} of {end - cave:#x} bytes, cave 2 {len(b2):#x} of {end2 - cave2:#x}; wrote release/SCUS-97196_C54E5CF2.pnach (all)"
      " and release/TMA/SCUS-97196_C54E5CF2.pnach (no Quick Energy Moves, no Tap Weapon Switch)")
EOF
cp -r $O /tmp/cave_dbg; rm -rf $O
