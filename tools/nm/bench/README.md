# Function test bench

Runs each C draft against the original asm on real game state, in a small EE interpreter, instead of a 25-minute
PCSX2 boot per question.

1. On the PC: `bench2_go.sh` (tools/nm/pc) builds the plain game (no C, layout untouched) with
   `NM_BENCH_OUT` set, so `nm_apply.py` compiles every working draft on its own as `<name>__c`; boots a match with
   `QB_KEEP_STATE=1` and keeps the mid-match savestate; `bench_img.py` links the drafts into `DRAFTS.ELF` at
   0x02000000 (above the PS2's 32 MB: only the interpreter sees it). Output in `cloud/bench/`.
2. Here: `python3 run_frames.py 30` runs the game's frame function (`func_00183580`, after a world update
   `func_00138C90(game)`) for 30 frames from the snapshot. Every call the original code makes to a function with a
   draft runs both versions from the same state and compares memory written, saved registers and the return value.

Verdicts: FAIL = the draft crashes where the asm does not, or writes different memory (reliable); `ret?` = only
v0/f0 differ (void functions leave junk there - low confidence); skip = the asm itself touches hardware / VU0
microprograms the interpreter does not model. First run (2026-10-25): 111 drafts reached, 9 FAIL - including
func_00242930, which the boot tests had already caught.

`ee.py` (interpreter), `bench.py` (pairing + compare), `bench_img.py` (draft image), `callgraph.py` (callers of a
function, for picking roots), `test_ee.py` (interpreter self-checks).
