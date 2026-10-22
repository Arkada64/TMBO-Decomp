# Unattended stripe bisect. Known: T240 = stripes, T260 = clean (T<n> = pad after the n-th .text object,
# so objects n+1.. move). Finds the single object whose moving causes the green stripes.
# Result -> bisect_result.txt. Takes ~10-15 min; PCSX2 windows open and close by themselves.
$W = "C:\Users\Ark\Desktop\TMB Decomp"
$P = "C:\Users\Ark\Desktop\TMBO Ready2Play Edition"
if (!(Test-Path "$P\pcsx2-qt.exe")) { $P = "$P\PCSX2" }
$ini = "$P\inis\PCSX2.ini"
$res = "$W\bisect_result.txt"
$L = "/mnt/c/Users/Ark/Desktop/TMB Decomp"   # same folder, as WSL sees it
Add-Type -AssemblyName System.Drawing
function Log($s) { $line = "$(Get-Date -Format HH:mm:ss) $s"; Write-Host $line; Add-Content $res $line }
function Stripes($png) {
  $bmp = [System.Drawing.Bitmap]::FromFile($png); $n = 0
  for ($y = 100; $y -lt [Math]::Min(380, $bmp.Height); $y += 4) {
    for ($x = 0; $x -lt $bmp.Width; $x++) {
      $c = $bmp.GetPixel($x, $y)
      if ($c.G -gt 90 -and $c.R -lt 70 -and $c.B -lt 70 -and $c.G -gt 2 * $c.R) { $n++ }
    }
  }
  $bmp.Dispose(); return $n
}
function Test($V) {
  Remove-Item "$W\test\$V.ELF" -ErrorAction SilentlyContinue
  wsl -e bash "$L/bis.sh" $V | Out-Null
  if (!(Test-Path "$W\test\$V.ELF")) { Log "BUILD FAILED for $V (see bis.log)"; return -1 }
  $before = Get-Date
  $proc = Start-Process -FilePath "$P\pcsx2-qt.exe" -ArgumentList @("-batch", "-elf", "`"$W\test\$V.ELF`"", "--", "`"$P\_games\Twisted Metal - Black Online (USA).chd`"") -PassThru
  Start-Sleep -Seconds 75
  $proc.CloseMainWindow() | Out-Null
  for ($i = 0; $i -lt 20 -and !$proc.HasExited; $i++) { Start-Sleep -Seconds 1 }
  if (!$proc.HasExited) { Stop-Process -Id $proc.Id -Force }
  Start-Sleep -Seconds 1
  $ss = Get-ChildItem "$P\sstates" -Filter *.p2s | Where-Object { $_.LastWriteTime -gt $before } | Sort-Object LastWriteTime | Select-Object -Last 1
  if (!$ss) { Log "NO SAVESTATE for $V"; return -1 }
  Copy-Item $ss.FullName "$W\test\ss_$V.p2s" -Force
  wsl -e bash "$L/ext.sh" $V | Out-Null
  return (Stripes "$W\test\ss_$V\Screenshot.png")
}
Copy-Item $ini "$ini.autobisect.bak" -Force
try {
  (Get-Content $ini) -replace '^SaveStateOnShutdown = false', 'SaveStateOnShutdown = true' -replace '^ConfirmShutdown = true', 'ConfirmShutdown = false' | Set-Content $ini
  Log "start: T240=stripes, T260=clean"
  $lo = 240; $hi = 260
  while ($hi - $lo -gt 1) {
    $mid = [int][Math]::Floor(($lo + $hi) / 2)
    $s = Test "T$mid"
    if ($s -lt 0) { Log "stopping (error)"; break }
    Log "T$mid stripes=$s"
    if ($s -gt 1000) { $lo = $mid } else { $hi = $mid }
  }
  if ($hi - $lo -eq 1) {
    $name = wsl -e bash "$L/objname.sh" $hi
    Log "RESULT: culprit is text object #$hi : $name"
  }
} finally {
  Stop-Process -Name pcsx2-qt -Force -ErrorAction SilentlyContinue
  Copy-Item "$ini.autobisect.bak" $ini -Force
  Log "done; PCSX2 settings restored"
}
