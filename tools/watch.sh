#!/bin/bash
# Pops a Windows message box when the overnight jobs (permuter run 3 + fixup 2 + apply) are all done.
cd ~/tmbo_decomp
until grep -q "APPLY DONE" logs/apply_fix2.txt 2>/dev/null && ! pgrep -f "tools/(perm_run|fixup).py|apply_fix" > /dev/null; do sleep 120; done
P=$(grep -c SOLVED logs/perm_run3.txt); A=$(grep -oE 'APPLY DONE: [0-9]+' logs/apply_fix2.txt | grep -oE '[0-9]+')
L=$(grep -rhoE '^ *INCLUDE_ASM' src | wc -l)
powershell.exe -NoProfile -Command "Add-Type -AssemblyName PresentationFramework; [System.Windows.MessageBox]::Show('Overnight decomp jobs finished.`n`nPermuter solved: $P`nSignedness fixup kept: $A`nFunctions still in asm: $L`n`nRun morning.sh for details.', 'TMB-Reloaded')" > /dev/null
