param([string]$V, [int]$Secs = 45)
$P = "C:\Users\Ark\Desktop\TMBO Ready2Play Edition\PCSX2"
$ini = "$P\inis\PCSX2.ini"
Copy-Item $ini "$ini.runss.bak" -Force
(Get-Content $ini) -replace '^SaveStateOnShutdown = false', 'SaveStateOnShutdown = true' -replace '^ConfirmShutdown = true', 'ConfirmShutdown = false' -replace '^PauseOnTLBMiss = false', 'PauseOnTLBMiss = true' | Set-Content $ini
$before = Get-Date
$proc = Start-Process -FilePath "$P\pcsx2-qt.exe" -ArgumentList @("-batch", "-elf", "`"C:\Users\Ark\Desktop\TMB Decomp\test\$V.ELF`"", "--", "`"$P\_games\Twisted Metal - Black Online (USA).chd`"") -PassThru
Start-Sleep -Seconds $Secs
$proc.CloseMainWindow() | Out-Null
for ($i = 0; $i -lt 20 -and !$proc.HasExited; $i++) { Start-Sleep -Seconds 1 }
if (!$proc.HasExited) { Stop-Process -Id $proc.Id }
Copy-Item "$ini.runss.bak" $ini -Force
Copy-Item "$P\logs\emulog.txt" "C:\Users\Ark\Desktop\TMB Decomp\test\log_$V.txt"
$ss = Get-ChildItem "$P\sstates" -Filter *.p2s | Where-Object { $_.LastWriteTime -gt $before } | Sort-Object LastWriteTime | Select-Object -Last 1
if ($ss) { Copy-Item $ss.FullName "C:\Users\Ark\Desktop\TMB Decomp\test\ss_$V.p2s"; "saved $($ss.Name)" } else { "no savestate" }
