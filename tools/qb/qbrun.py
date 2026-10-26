#!/usr/bin/env python3
"""Unattended test run: patch a quick-boot script into a copy of the test ELF (mods/quickboot.c block), run
PCSX2 muted on a disc, take screenshots of its window (winshot.ps1, PrintWindow), stop it, and collect the log + screenshots.
Runs in WSL on the test PC.
  python3 tools/qb/qbrun.py SCRIPT.json [--iso test/TMBR_LOST.iso] [--elf test/TMBR_TEST.ELF]
SCRIPT.json: {"steps": [["CROSS", 10], ["", 120], ...], "loop_from": 12,
              "shots": [70, 80, 90], "stop": 100}
  a step is [buttons, frames]; buttons = names joined with + (START, CROSS, CIRCLE, TRIANGLE, SQUARE, UP, DOWN,
  LEFT, RIGHT, L1, R1, L2, R2, SELECT, L3, R3) or "" to wait.
  shots = seconds after launch to capture; stop = seconds after launch to kill PCSX2; state_at = seconds after launch to save a savestate (PINE). Output: qb_out/<timestamp>/ (emulog.txt + PNGs)."""
import sys, os, json, struct, time, subprocess, shutil, glob, argparse

W = "/mnt/c/Users/Ark/Desktop/TMB Decomp"
P = "/mnt/c/Users/Ark/Desktop/TMBO Ready2Play Edition"
WP = r"C:\Users\Ark\Desktop\TMBO Ready2Play Edition"
WW = r"C:\Users\Ark\Desktop\TMB Decomp"
BTN = dict(SELECT=0x1, L3=0x2, R3=0x4, START=0x8, UP=0x10, RIGHT=0x20, DOWN=0x40, LEFT=0x80, L2=0x100, R2=0x200,
           L1=0x400, R1=0x800, TRIANGLE=0x1000, CIRCLE=0x2000, CROSS=0x4000, SQUARE=0x8000)
MAGIC = struct.pack('<I', 0x42514D54)
QB_STEPS = 120

def patch(elf, script):
    d = bytearray(open(elf, 'rb').read())
    o = d.find(MAGIC)
    assert o >= 0 and d.find(MAGIC, o + 1) < 0, 'quick-boot block not found (or twice) in ' + elf
    steps = script['steps']
    assert len(steps) <= QB_STEPS
    struct.pack_into('<III', d, o + 4, 1, len(steps), script.get('loop_from', 0xFFFF))
    for i, st in enumerate(steps):
        b, n = st[0], st[1]
        ctl = st[2] if len(st) > 2 else 1          # optional 3rd field: controller 1..4 (multitap) gets the buttons
        assert n < 0x4000 and 1 <= ctl <= 4
        m = 0
        for k in filter(None, b.upper().split('+')): m |= BTN[k]
        struct.pack_into('<HH', d, o + 16 + 4 * i, m, n | (ctl - 1) << 14)
    return bytes(d)

def ps(cmd):
    return subprocess.run(['powershell.exe', '-NoProfile', '-ExecutionPolicy', 'Bypass', '-Command', cmd], capture_output=True, text=True).stdout

KEEP_RUNS, KEEP_STATES, MIN_FREE_GB = 150, 3, 20
def prune():
    """disk safeguards for the automated runs (they are ours to manage): keep the newest KEEP_RUNS run folders
    in cloud/qb_out (logs are small), and savestates only in the newest KEEP_STATES of them."""
    runs = sorted(glob.glob(f'{W}/cloud/qb_out/2026*') + glob.glob(f'{W}/cloud/qb_out/boot_*'), key=os.path.getmtime)
    for d in runs[:-KEEP_RUNS]: shutil.rmtree(d, ignore_errors=True)
    states = sorted(glob.glob(f'{W}/cloud/qb_out/*/state.p2s'), key=os.path.getmtime)
    for f in states[:-KEEP_STATES]: os.remove(f)

def low_disk():
    st = os.statvfs(W)
    return st.f_bavail * st.f_frsize < MIN_FREE_GB * 2**30

def main():
    ap = argparse.ArgumentParser(); ap.add_argument('script'); ap.add_argument('--iso', default='test/TMBR_LOST.iso')
    ap.add_argument('--elf', default='test/TMBR_TEST.ELF'); a = ap.parse_args()
    os.chdir(W)
    if low_disk():
        sys.exit(f'less than {MIN_FREE_GB} GB free on the drive: not starting a test run')
    if 'pcsx2-qt.exe' in subprocess.run(['tasklist.exe'], capture_output=True, text=True).stdout:
        sys.exit('PCSX2 is already running (someone is playing): not starting a test run')
    script = json.load(open(a.script))
    # "prepatched": the ELF already carries its script (retail harness, tools/qb/retail): copy as is
    open('test/QUICK.ELF', 'wb').write(open(a.elf, 'rb').read() if script.get('prepatched') else patch(a.elf, script))
    ini = f'{P}/inis/PCSX2.ini'; shutil.copy(ini, ini + '.qbbak')
    s = open(ini).read().replace('StandardVolume = 100', 'StandardVolume = 0').replace('FastForwardVolume = 100', 'FastForwardVolume = 0')
    # PINE on (savestates on request, for the EE registers of a hang) and uncompressed savestates
    s = s.replace('EnablePINE = false', 'EnablePINE = true').replace('SavestateCompressionType = 2', 'SavestateCompressionType = 0')
    if os.environ.get('QB_PADS'):                     # retail split screen: multitap on port 1 + controllers 2-5 present
        import re
        s = s.replace('MultitapPort1 = false', 'MultitapPort1 = true')
        for k in range(2, 2 + int(os.environ['QB_PADS'])):
            s = re.sub(r'(\[Pad%d\]\s*\nType = )None' % k, r'\1DualShock2', s)
    if os.environ.get('QB_EECYCLE') is not None:      # stress tests: EE cycle rate for this run (-3..3; 1 = 130 %, 2 = 180 %, 3 = 300 %)
        import re
        s = re.sub(r'(?m)^EECycleRate = -?\d+', 'EECycleRate = ' + os.environ['QB_EECYCLE'], s)
    open(ini, 'w').write(s)
    snaps = f'{P}/snaps'; before = set(glob.glob(f'{snaps}/**/*.png', recursive=True))
    iso = WW + '\\' + a.iso.replace('/', '\\')
    t0 = time.time(); shots = []
    # normal window even when this runs from a minimized console (a minimized PCSX2 captures black)
    if os.environ.get('QB_MIN', '1') == '1':          # (screenshots of a minimized window come out black: QB_MIN=0 for those)
        # minimized and without taking focus (the user can keep using the PC; the test only reads the log)
        ps(f"Start-Process -WindowStyle Minimized -FilePath '{WP}\\pcsx2-qt.exe' -ArgumentList '-elf','\"{WW}\\test\\QUICK.ELF\"','--','\"{iso}\"'")
        time.sleep(4)
        ps("Add-Type -Name W -Namespace U -MemberDefinition '[DllImport(\"user32.dll\")] public static extern bool ShowWindow(System.IntPtr h, int c);'; "
           "Get-Process pcsx2-qt -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | "
           "ForEach-Object { if ((Get-CimInstance Win32_Process -Filter \"ProcessId=$($_.Id)\").CommandLine -match 'QUICK.ELF') { [U.W]::ShowWindow($_.MainWindowHandle, 7) | Out-Null } }")
    else:
        ps(f"Start-Process -WindowStyle Normal -FilePath '{WP}\\pcsx2-qt.exe' -ArgumentList '-elf','\"{WW}\\test\\QUICK.ELF\"','--','\"{iso}\"'")

    minimized = os.environ.get('QB_MIN', '1') == '1'
    pics = []
    def pine_save(slot):
        # PINE MsgSaveState (opcode 9): u32 size, u8 op, u8 slot
        return ps("$c=New-Object Net.Sockets.TcpClient('127.0.0.1',28011); $s=$c.GetStream(); "
                  f"$m=[byte[]](6,0,0,0,9,{slot}); $s.Write($m,0,6); Start-Sleep 3; $c.Close(); 'sent'").strip()
    try:
        # "pics": screenshots that work minimized - a savestate (slot 8) carries a Screenshot.png; keep only that
        events = [(t, 'shot') for t in ([] if minimized else script.get('shots', []))] + [(t, 'pic') for t in script.get('pics', [])]
        for t, kind in sorted(events):
            time.sleep(max(0, t - (time.time() - t0)))
            if kind == 'shot':                                       # (a minimized window captures black)
                k = len(shots); shots.append(f'{WW}\\qb_tmp_{k}.png')
                print('shot at', round(time.time() - t0, 1), ps(f"& '{WW}\\tools\\qb\\winshot.ps1' '{shots[-1]}'").strip(), flush=True)
            else:
                pine_save(8); time.sleep(2)
                st = sorted(glob.glob(f'{P}/sstates/*.08.p2s'), key=os.path.getmtime)
                if st and os.path.getmtime(st[-1]) > t0:
                    try:
                        import zipfile
                        pics.append(zipfile.ZipFile(st[-1]).read('Screenshot.png'))
                    except Exception as e: print('pic failed', e)
                    os.remove(st[-1])                                  # (45 MB: never kept)
                print('pic at', round(time.time() - t0, 1), flush=True)
        if 'state_at' in script:
            time.sleep(max(0, script['state_at'] - (time.time() - t0)))
            print('savestate', pine_save(9), flush=True)
            time.sleep(5)
        time.sleep(max(0, script.get('stop', 60) - (time.time() - t0)))
    finally:
        # only the PCSX2 this run started (never the user's own session)
        ps("Get-CimInstance Win32_Process -Filter \"Name='pcsx2-qt.exe'\" | Where-Object { $_.CommandLine -match 'QUICK.ELF' } | "
           "ForEach-Object { Stop-Process -Id $_.ProcessId -Force }")
        time.sleep(2)
        shutil.copy(ini + '.qbbak', ini)
    out = time.strftime('cloud/qb_out/%Y%m%d_%H%M%S'); os.makedirs(out, exist_ok=True)
    shutil.copy(f'{P}/logs/emulog.txt', f'{out}/emulog.txt')
    for i, png in enumerate(pics): open(f'{out}/pic{i}.png', 'wb').write(png)
    n = 0
    for i in range(len(shots)):
        f = f'{W}/qb_tmp_{i}.png'
        if os.path.exists(f): shutil.move(f, f'{out}/shot{i}.png'); n += 1
    # keep the savestate (~45 MB) only for a run that went wrong: it is for looking at a hang / fault, and the
    # night runs filled 2.4 GB with clean ones. (Slot 9 in sstates is simply overwritten by the next run.)
    lg = open(f'{out}/emulog.txt', errors='replace').read()
    bad = lg.count('TLB Miss') > 0 or lg.count('TMBR perf') <= 3
    bad = bad or os.environ.get('QB_KEEP_STATE') == '1'   # the function test bench's snapshot (tools/nm/bench)
    st = sorted(glob.glob(f'{P}/sstates/*.09.p2s'), key=os.path.getmtime)
    if bad and st and os.path.getmtime(st[-1]) > t0: shutil.move(st[-1], f'{out}/state.p2s'); print('state saved')
    prune()
    print('OUT', out, 'shots', n)
    log = open(f'{out}/emulog.txt', errors='replace').read().splitlines()
    for l in log:
        if 'TMBR' in l or 'GIF' in l or 'TLB' in l or 'xception' in l: print(l[:160])

if __name__ == '__main__':
    main()
