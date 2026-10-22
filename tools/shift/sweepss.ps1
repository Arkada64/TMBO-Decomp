param([string]$Vs, [int]$Secs = 75)
$P = "C:\Users\Ark\Desktop\TMBO Ready2Play Edition\PCSX2"
$ini = "$P\inis\PCSX2.ini"
Copy-Item $ini "$ini.sweep.bak" -Force
(Get-Content $ini) -replace '^SaveStateOnShutdown = false', 'SaveStateOnShutdown = true' -replace '^ConfirmShutdown = true', 'ConfirmShutdown = false' | Set-Content $ini
$out = "C:\Users\Ark\Desktop\TMB Decomp\sweep.txt"
foreach ($V in ($Vs -split ',')) {
  $before = Get-Date
  $proc = Start-Process -FilePath "$P\pcsx2-qt.exe" -ArgumentList @("-batch", "-elf", "`"C:\Users\Ark\Desktop\TMB Decomp\test\$V.ELF`"", "--", "`"$P\_games\Twisted Metal - Black Online (USA).chd`"") -PassThru
  Start-Sleep -Seconds $Secs
  $proc.CloseMainWindow() | Out-Null
  for ($i = 0; $i -lt 20 -and !$proc.HasExited; $i++) { Start-Sleep -Seconds 1 }
  if (!$proc.HasExited) { Stop-Process -Id $proc.Id }
  Start-Sleep -Seconds 1
  $log = Get-Content "$P\logs\emulog.txt"
  $press = ($log | Select-String -SimpleMatch "D+A+P").Count
  $tlb = ($log | Select-String -SimpleMatch "TLB Miss").Count
  $ss = Get-ChildItem "$P\sstates" -Filter *.p2s | Where-Object { $_.LastWriteTime -gt $before } | Sort-Object LastWriteTime | Select-Object -Last 1
  if ($ss) { Copy-Item $ss.FullName "C:\Users\Ark\Desktop\TMB Decomp\test\ss_$V.p2s" -Force }
  "$V pressmode=$press tlb=$tlb ss=$([bool]$ss)" | Add-Content $out
}
Copy-Item "$ini.sweep.bak" $ini -Force
wsl -e bash "/mnt/c/Users/Ark/Desktop/TMB Decomp/ext.sh" @($Vs -split ',') | Out-Null
"SWEEPDONE" | Add-Content $out
