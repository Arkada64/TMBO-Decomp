# TMB-Reloaded mod: waiting room game settings box. The ENTRY line's print (fontPrint = func_00203150) in
# func_001C5768 is sent here (tools/mods/apply_mods.py: 0x1C6570, 0x1C6748, 0x1C675C); $s1 holds the box row
# that line is on, which tmbr_PrintEntryC (mods/bots.c) needs to put traffic / teams under it.
.set noat
.set noreorder
.section .text, "ax"
.align 3

.globl tmbr_PrintEntry
tmbr_PrintEntry:                        # $a0 font, $a1 string -> tmbr_PrintEntryC(font, string, row)
    j       tmbr_PrintEntryC
    daddu   $6, $17, $0
