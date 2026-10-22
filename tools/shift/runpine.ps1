param([string]$V, [int]$Secs = 12, [int]$TLB = 1)
$P = "C:\Users\Ark\Desktop\TMBO Ready2Play Edition\PCSX2"
$ini = "$P\inis\PCSX2.ini"
Copy-Item $ini "$ini.runss.bak" -Force
$t = (Get-Content $ini) -replace '^EnablePINE = false', 'EnablePINE = true' -replace '^ConfirmShutdown = true', 'ConfirmShutdown = false'
if ($TLB) { $t = $t -replace '^PauseOnTLBMiss = false', 'PauseOnTLBMiss = true' }
$t | Set-Content $ini
$proc = Start-Process -FilePath "$P\pcsx2-qt.exe" -ArgumentList @("-batch", "-elf", "`"C:\Users\Ark\Desktop\TMB Decomp\test\$V.ELF`"", "--", "`"$P\_games\Twisted Metal - Black Online (USA).chd`"") -PassThru
Start-Sleep -Seconds $Secs
try { & "C:\Users\Ark\Desktop\TMB Decomp\pinedump.ps1" -Out "C:\Users\Ark\Desktop\TMB Decomp\test\mem_$V.bin" } catch { "dump failed: $_" }
Stop-Process -Id $proc.Id -ErrorAction SilentlyContinue
Copy-Item "$ini.runss.bak" $ini -Force
Start-Sleep -Seconds 1
Copy-Item "$P\logs\emulog.txt" "C:\Users\Ark\Desktop\TMB Decomp\test\log_$V.txt"
"done"
