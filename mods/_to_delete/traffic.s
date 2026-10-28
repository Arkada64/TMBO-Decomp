# TMB-Reloaded mod: traffic ("fodder") cars in online maps.
# Online dropped retail's TheGame::FodderParse (level-db nodes 0x401..0xBB7 are ignored). This is a port of
# retail FodderParse__7TheGameP9_hierhead (0x130FC8), using the online equivalents:
#   AddFodder__7TheGameP3_csii = func_0013A640 (still in online, just unreferenced)
#   dbGetCSForModel: online's version takes cs from the per-vehicle pool (func_00127B58 -> func_00213FF8),
#   so fodder cs come from our own pool (tmbr_FodderCs) built the same way (0xA0-byte cs).
# Called from the online level loader (func_00127650), patched by tools/mods/apply_mods.py.
.set noat
.set noreorder
.section .text, "ax"

.align 3
.globl tmbr_FodderParse
.ent tmbr_FodderParse
tmbr_FodderParse:                       # (TheGame *game, _hierhead *h)
    addiu   $29, $29, -0x70
    sq      $31, 0x60($29)
    sq      $16, 0x00($29)
    sq      $17, 0x10($29)
    sq      $18, 0x20($29)
    sq      $19, 0x30($29)
    sq      $20, 0x40($29)
    sq      $21, 0x50($29)
    daddu   $20, $5, $0                 # h
    lw      $2, 0x0($20)
    srl     $19, $2, 18                 # id
    lui     $4, %hi(tmbr_fodder_msg)    # debug: shows in PCSX2's EE console / emulog.txt
    addiu   $4, $4, %lo(tmbr_fodder_msg)
    jal     scePrintf
    daddu   $5, $19, $0
    addiu   $4, $19, -0x7D0             # rel = id - 2000
    addiu   $2, $19, -0x7B1             # rel + 31
    addiu   $3, $0, -0x1
    slt     $3, $3, $4
    movn    $2, $4, $3
    sra     $17, $2, 5
    sll     $3, $17, 5
    subu    $17, $4, $3                 # sub = rel % 32
    subu    $18, $19, $17               # base = id - sub
    addiu   $21, $0, -0x1               # last = -1
    daddu   $16, $0, $0                 # i = 0
.Lfp_loop:
    slti    $2, $16, 0xA
    beqz    $2, .Lfp_counted
    nop
    lw      $4, %gp_rel(D_004FA030)($28)    # game
    daddu   $5, $18, $0
    jal     GetVehicleFromName__7TheGameii
    daddu   $6, $16, $0
    beqz    $2, .Lfp_counted
    nop
    daddu   $21, $16, $0
    b       .Lfp_loop
    addiu   $16, $21, 0x1
.Lfp_counted:
    bnez    $17, .Lfp_attach
    nop
    # Online's AddFodder puts the car into vehicle slot game[0x98000+0x7CA4] of the 8-slot vehicle
    # array (0x31B0 each) without any bounds check. With no free slot it writes past the array.
    lw      $4, %gp_rel(D_004FA030)($28)
    lui     $3, 0x9
    ori     $3, $3, 0x8000
    addu    $3, $4, $3
    lw      $6, 0x7CA4($3)              # next vehicle slot
    lui     $4, %hi(tmbr_add_msg)
    addiu   $4, $4, %lo(tmbr_add_msg)
    daddu   $5, $19, $0
    jal     scePrintf
    daddu   $16, $6, $0                 # keep slot in $16 (loop counter no longer needed)
    slti    $2, $16, 0x8
    beqz    $2, .Lfp_ret                # no free vehicle slot: skip instead of corrupting memory
    nop
    jal     tmbr_FodderCs               # cs for this fodder car's model
    daddu   $4, $20, $0
    beqz    $2, .Lfp_ret
    nop
    lw      $4, %gp_rel(D_004FA030)($28)
    daddu   $5, $2, $0
    daddu   $6, $18, $0
    jal     func_0013A640               # TheGame::AddFodder(cs, name, index)
    addiu   $7, $21, 0x1
    b       .Lfp_ret
    nop
.Lfp_attach:                            # sub-node: attachment for the last car with this name
    slti    $2, $19, 0xBB7
    beqz    $2, .Lfp_ret
    nop
    lw      $4, %gp_rel(D_004FA030)($28)
    daddu   $5, $18, $0
    jal     GetVehicleFromName__7TheGameii
    daddu   $6, $21, $0
    beqz    $2, .Lfp_ret
    daddu   $4, $2, $0
    daddu   $5, $17, $0
    jal     attachAdd__7VehicleiP9_hierhead
    daddu   $6, $20, $0
.Lfp_ret:
    lq      $31, 0x60($29)
    lq      $16, 0x00($29)
    lq      $17, 0x10($29)
    lq      $18, 0x20($29)
    lq      $19, 0x30($29)
    lq      $20, 0x40($29)
    lq      $21, 0x50($29)
    jr      $31
    addiu   $29, $29, 0x70
.end tmbr_FodderParse

.align 3
.globl tmbr_FodderCs
.ent tmbr_FodderCs
tmbr_FodderCs:                          # (_hierhead *h) -> _cs*   (online dbGetCSForModel, own pool)
    addiu   $29, $29, -0x30
    sq      $31, 0x20($29)
    sq      $16, 0x00($29)
    sq      $17, 0x10($29)
    daddu   $17, $4, $0
    lui     $2, %hi(tmbr_fodder_next)
    lw      $3, %lo(tmbr_fodder_next)($2)
    addiu   $5, $3, 0x1
    andi    $5, $5, 0x1F                # 32-entry ring, reused every level load
    sw      $5, %lo(tmbr_fodder_next)($2)
    sll     $16, $3, 7
    sll     $3, $3, 5
    addu    $16, $16, $3                # idx * 0xA0
    lui     $2, %hi(tmbr_fodder_cs)
    addiu   $2, $2, %lo(tmbr_fodder_cs)
    addu    $16, $16, $2
    jal     func_00214088               # same init sequence as the pool allocator func_00213FF8
    daddu   $4, $16, $0
    jal     hierInitCs__FP3_cs
    daddu   $4, $16, $0
    addiu   $2, $0, 0x1
    sb      $2, 0xC($16)
    daddu   $4, $16, $0
    jal     hierSetCsEpNode__FP3_csP9_hierhead
    daddu   $5, $17, $0
    jal     hierCsAddToCsList__FP3_cs
    daddu   $4, $16, $0
    daddu   $2, $16, $0
    lq      $31, 0x20($29)
    lq      $16, 0x00($29)
    lq      $17, 0x10($29)
    jr      $31
    addiu   $29, $29, 0x30
.end tmbr_FodderCs

tmbr_fodder_msg:
    .asciz "TMBR fodder node %d\n"
.align 3

# DEBUG: level-loader callback wrapper. Prints every db node with id 0x401..0xF9F (fodder + ped range)
# that the traversal hands to the loader, then continues into the real loader func_00127650.
.globl tmbr_LoaderDbg
.ent tmbr_LoaderDbg
tmbr_LoaderDbg:
    addiu   $29, $29, -0x50
    sq      $31, 0x40($29)
    sq      $4, 0x00($29)
    sq      $5, 0x10($29)
    sq      $6, 0x20($29)
    sq      $7, 0x30($29)
    lw      $2, 0x0($4)
    srl     $5, $2, 18
    andi    $6, $2, 0x3F
    addiu   $3, $5, -0x401
    sltiu   $3, $3, (0xFA0 - 0x401)
    beqz    $3, .Lld_go
    nop
    lui     $4, %hi(tmbr_node_msg)
    jal     scePrintf
    addiu   $4, $4, %lo(tmbr_node_msg)
.Lld_go:
    lq      $4, 0x00($29)
    lq      $5, 0x10($29)
    lq      $6, 0x20($29)
    lq      $7, 0x30($29)
    lq      $31, 0x40($29)
    j       func_00127650
    addiu   $29, $29, 0x50
.end tmbr_LoaderDbg
tmbr_add_msg:
    .asciz "TMBR AddFodder name %d -> vehicle slot %d\n"
.align 3
tmbr_node_msg:
    .asciz "TMBR node %d op %d\n"
.align 3

.section .bss
.align 4
.globl tmbr_fodder_cs
tmbr_fodder_cs:
    .space 0xA0 * 32
.globl tmbr_fodder_next
tmbr_fodder_next:
    .space 0x10
