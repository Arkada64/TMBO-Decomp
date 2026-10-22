param([string[]]$Vs, [int]$Secs = 25)
$P = "C:\Users\Ark\Desktop\TMBO Ready2Play Edition\PCSX2"
$Vs = @($Vs | ForEach-Object { $_ -split ',' })
$ini = "$P\inis\PCSX2.ini"
Copy-Item $ini "$ini.sweep.bak" -Force
(Get-Content $ini) -replace '^ConfirmShutdown = true', 'ConfirmShutdown = false' | Set-Content $ini
$out = "C:\Users\Ark\Desktop\TMB Decomp\sweep.txt"
foreach ($V in $Vs) {
  $proc = Start-Process -FilePath "$P\pcsx2-qt.exe" -ArgumentList @("-batch", "-elf", "`"C:\Users\Ark\Desktop\TMB Decomp\test\$V.ELF`"", "--", "`"$P\_games\Twisted Metal - Black Online (USA).chd`"") -PassThru
  Start-Sleep -Seconds $Secs
  $proc.CloseMainWindow() | Out-Null
  for ($i = 0; $i -lt 10 -and !$proc.HasExited; $i++) { Start-Sleep -Seconds 1 }
  if (!$proc.HasExited) { Stop-Process -Id $proc.Id }
  Start-Sleep -Seconds 1
  $log = Get-Content "$P\logs\emulog.txt"
  Copy-Item "$P\logs\emulog.txt" "C:\Users\Ark\Desktop\TMB Decomp\test\log_$V.txt"
  $press = ($log | Select-String -SimpleMatch "D+A+P").Count
  $tlb = ($log | Select-String -SimpleMatch "TLB Miss").Count
  $pad = ($log | Select-String -SimpleMatch "Pad: DS2 Config").Count
  "$V pressmode=$press padcfg=$pad tlb=$tlb" | Add-Content $out
}
Copy-Item "$ini.sweep.bak" $ini -Force
"SWEEPDONE" | Add-Content $out
