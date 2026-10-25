#!/usr/bin/env python3
"""
Function test bench: run each C draft against the original asm, side by side, on real game state.

Input: the plain build (no C) and a PCSX2 savestate taken mid-match with it (qbrun.py with QB_KEEP_STATE=1), plus
the draft image (bench_img.py: every draft compiled on its own as F__c, linked at 0x02000000 against the plain
build). The image sits above the PS2's 32 MB, in the interpreter only, so the game's layout never changes.

The bench runs a few of the game's own per-frame functions (roots) out of the snapshot in the EE interpreter
(ee.py). Every time the original code calls a function F that has an F__c, it stops, runs F and then F__c from
the identical state, compares what each did, puts everything back and carries on with the original. So the
drafts get the arguments and data the game really passes them.

Compared: memory written outside the callee's own stack frame, the callee-saved registers, and v0 / f0 (the
return value; for a void function these are leftovers, so a v0-only difference is reported as "ret?").
Floats that differ only in the last bits (PS2 FPU vs IEEE rounding, reordered math) count as equal.

Usage: bench.py BASE.ELF DRAFTS.ELF state.p2s [--roots name,name] [--per 8] [--limit 3000000] [--json out.json]
"""
import argparse, bisect, json, struct, sys, time, zipfile
from collections import defaultdict
sys.path.insert(0, __import__('os').path.dirname(__file__))
from ee import EE, Unsupported, Hardware, Fault, StepLimit, RET_MAGIC, M64, M32, u2f

# ---------------------------------------------------------------- ELF symbols
def elf_symbols(path):
    d = open(path, 'rb').read()
    shoff, = struct.unpack_from('<I', d, 0x20); shent, shnum = struct.unpack_from('<HH', d, 0x2E)
    secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shent) for i in range(shnum)]
    out = {}
    for s in secs:
        if s[1] != 2: continue                                  # SHT_SYMTAB
        strs = secs[s[6]]
        for o in range(s[4], s[4] + s[5], 16):
            nm, val, size, info, other, shndx = struct.unpack_from('<IIIBBH', d, o)
            if not nm or shndx == 0: continue
            e = d.index(b'\0', strs[4] + nm)
            out[d[strs[4] + nm:e].decode(errors='replace')] = (val, size, info & 15)
    return out

def load_segments(path, ram):
    d = open(path, 'rb').read()
    phoff, = struct.unpack_from('<I', d, 0x1C); phnum, = struct.unpack_from('<H', d, 0x2C)
    for i in range(phnum):
        t, off, va, pa, fs, ms = struct.unpack_from('<IIIIII', d, phoff + 32 * i)
        if t != 1 or not ms: continue
        p = va & 0x1FFFFFFF
        ram[p:p + ms] = d[off:off + fs] + bytes(ms - fs)

def load_state(path):
    z = zipfile.ZipFile(path)
    return z.read('eeMemory.bin'), z.read('Scratchpad.bin')

# ---------------------------------------------------------------- the bench
class Bench:
    def __init__(self, elf, img, state, per=8, limit=3_000_000, fn_limit=400_000):
        self.syms = elf_symbols(elf)
        isyms = elf_symbols(img)
        ram, spr = load_state(state)
        ram = bytearray(ram) + bytearray(0x800000)          # + 8 MB above the PS2's RAM for the draft image
        load_segments(img, ram)
        for n, v in isyms.items():
            if n.endswith('__c'): self.syms[n] = v
        self.ee = EE(ram, spr)
        self.base = self.ee.ram[:]; self.base_spr = self.ee.spr[:]
        funcs = sorted((v, n) for n, (v, sz, t) in self.syms.items() if t == 2 and not n.endswith('.NON_MATCHING'))
        self.fa = [a for a, _ in funcs]; self.fn = [n for _, n in funcs]
        self.pairs = {}                                          # asm address -> (name, C address)
        for n, (v, sz, t) in self.syms.items():
            if n.endswith('__c') and n[:-3] in self.syms:
                self.pairs[self.syms[n[:-3]][0]] = (n[:-3], v)
        self.gp = self.syms.get('_gp', (0,))[0]
        self.per, self.limit, self.fn_limit = per, limit, fn_limit
        self.res = defaultdict(lambda: dict(calls=0, ok=0, near=0, fail=0, ret=0, skip=0, first=None, why=defaultdict(int)))
        self.ee.on_call = self.on_call
        self.busy = False

    def sym(self, a):
        k = bisect.bisect_right(self.fa, a & M32) - 1
        return '%s+0x%x' % (self.fn[k], a - self.fa[k]) if k >= 0 else '%08x' % a

    def reset(self):
        self.ee.ram[:] = self.base; self.ee.spr[:] = self.base_spr

    # run one version of the callee from the current state; returns (outcome, regs, writes)
    def run_one(self, entry, ra, sp0):
        ee = self.ee
        ee.begin(); ee.hw_ok = False
        ee.pc = entry
        err = None
        try:
            end = ee.steps + self.fn_limit
            while not (ee.pc == ra and (ee.r(29) & M32) == sp0):
                if ee.steps >= end: raise StepLimit('callee ran %d steps' % self.fn_limit)
                ee.step()
        except (Unsupported, Hardware, Fault, StepLimit) as e:
            err = e
        regs = ee.state()
        writes = {}
        for k, o, old in ee.journal:
            buf = ee.spr if k == 'S' else ee.ram
            for i in range(len(old)):
                writes[(k, o + i)] = buf[o + i]
        ee.undo(); ee.hw_ok = True
        return err, regs, writes

    def on_call(self, ee, target):
        if self.busy or target not in self.pairs: return
        name, caddr = self.pairs[target]
        r = self.res[name]
        if r['calls'] >= self.per: return
        r['calls'] += 1
        self.busy = True
        try:
            start = ee.state()
            ra = ee.r(31) & M32; sp0 = ee.r(29) & M32
            ea, ra_regs, wa = self.run_one(target, ra, sp0)
            ee.restore(start)
            eb, rb_regs, wb = self.run_one(caddr, ra, sp0)
            ee.restore(start)
            self.judge(name, r, sp0, ea, eb, ra_regs, rb_regs, wa, wb)
        finally:
            self.busy = False

    def judge(self, name, r, sp0, ea, eb, A, B, wa, wb):
        def note(kind, text):
            r[kind] += 1; r['why'][text.split(':')[0]] += 1
            if r['first'] is None or (kind == 'fail' and not r['first'].startswith('FAIL')):
                r['first'] = ('FAIL ' if kind == 'fail' else kind + ' ') + text
        if ea is not None:                                   # the original itself left what we can model
            return note('skip', 'asm %s: %s' % (type(ea).__name__, ea))
        if eb is not None:
            return note('fail', 'C %s (asm ran fine): %s' % (type(eb).__name__, eb))
        # memory outside the callee's frame (the frame is below the entry sp)
        lo = sp0 - 0x8000
        diffs = []
        keys = set(wa) | set(wb)
        words = sorted({(k, o & ~3) for k, o in keys if not (k == 'R' and lo <= o < sp0 & 0x1FFFFFF)})
        near = 0
        for k, o in words:
            buf = self.ee.spr if k == 'S' else self.ee.ram
            va = int.from_bytes(bytes(wa.get((k, o + i), buf[o + i]) for i in range(4)), 'little')
            vb = int.from_bytes(bytes(wb.get((k, o + i), buf[o + i]) for i in range(4)), 'little')
            if va == vb: continue
            fa, fb = u2f(va), u2f(vb)
            isf = lambda x: (x & 0x7FFFFFFF) == 0 or (x >> 23) & 0xFF        # 0.0 or a normal float (not a small int)
            if isf(va) and isf(vb) and (abs(fa - fb) <= 1e-4 * max(abs(fa), abs(fb)) or abs(fa - fb) < 1e-7):
                near += 1; continue
            diffs.append((k, o, va, vb))
        saved = [16, 17, 18, 19, 20, 21, 22, 23, 28, 29, 30]
        rdiff = [i for i in saved if A['gpr'][i] & M64 != B['gpr'][i] & M64]
        if diffs:
            k, o, va, vb = diffs[0]
            where = ('scratchpad+%x' % o) if k == 'S' else self.data_name(o)
            return note('fail', 'memory: %d word(s) differ, first %s: asm %08x C %08x' % (len(diffs), where, va, vb))
        if rdiff:
            return note('fail', 'saved register: $%d asm %x C %x' % (rdiff[0], A['gpr'][rdiff[0]] & M64, B['gpr'][rdiff[0]] & M64))
        if A['gpr'][2] & M64 != B['gpr'][2] & M64 or A['fpr'][0] != B['fpr'][0]:
            if A['gpr'][2] & M64 != B['gpr'][2] & M64:
                return note('ret', 'ret?: v0 asm %x C %x (or a void function)' % (A['gpr'][2] & M64, B['gpr'][2] & M64))
            fa, fb = u2f(A['fpr'][0]), u2f(B['fpr'][0])
            if abs(fa - fb) > 1e-4 * max(abs(fa), abs(fb), 1e-6):
                return note('ret', 'ret?: f0 asm %g C %g (or not a float function)' % (fa, fb))
        if near: return note('near', 'near: %d float word(s) differ in the last bits' % near)
        r['ok'] += 1

    def data_name(self, o):
        # the data symbol at or below a RAM offset
        if not hasattr(self, 'da'):
            ds = sorted((v & 0x1FFFFFF, n) for n, (v, sz, t) in self.syms.items() if t == 1 or t == 0)
            self.da = [a for a, _ in ds]; self.dn = [n for _, n in ds]
        k = bisect.bisect_right(self.da, o) - 1
        return '%s+0x%x' % (self.dn[k], o - self.da[k]) if k >= 0 else '%07x' % o

    # ------------------------------------------------------------ roots
    def run_root(self, name, args=(), sp=0x01FF0000):
        ee = self.ee
        if name not in self.syms: print('  (no symbol %s)' % name); return
        ee.w(28, self.gp)
        t0, s0 = time.time(), ee.steps
        try:
            ee.call(self.syms[name][0], args, sp=sp, limit=self.limit)
            how = 'returned'
        except (Unsupported, Hardware, Fault, StepLimit) as e:
            how = '%s: %s (at %s)' % (type(e).__name__, e, self.sym(ee.pc))
        print('  root %s%s: %d steps, %.1fs, %s' % (name, tuple(hex(a) for a in args), ee.steps - s0, time.time() - t0, how), flush=True)

    def report(self):
        rows = sorted(self.res.items(), key=lambda kv: (-kv[1]['fail'], kv[0]))
        tot = defaultdict(int)
        for n, r in rows:
            for k in ('ok', 'near', 'fail', 'ret', 'skip'): tot[k] += r[k]
            verdict = 'FAIL' if r['fail'] else 'ret?' if r['ret'] and not r['ok'] else 'skip' if r['skip'] == r['calls'] else 'pass'
            r['verdict'] = verdict
        tested = len(rows)
        print('\n%d drafted functions reached (of %d in the build); calls: %s' % (tested, len(self.pairs), dict(tot)))
        for n, r in rows:
            if r['verdict'] != 'pass':
                print('  %-4s %-36s %d/%d  %s' % (r['verdict'], n, r['fail'] or r['ret'] or r['skip'], r['calls'], r['first']))
        print('  pass: %d functions' % sum(1 for _, r in rows if r['verdict'] == 'pass'))
        return {n: dict(r, why=dict(r['why'])) for n, r in rows}

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('elf'); ap.add_argument('img'); ap.add_argument('state')
    ap.add_argument('--roots', default='')
    ap.add_argument('--per', type=int, default=8)
    ap.add_argument('--limit', type=int, default=3_000_000)
    ap.add_argument('--json')
    a = ap.parse_args()
    b = Bench(a.elf, a.img, a.state, a.per, a.limit)
    print('bench: %d drafts in the build, gp %08x' % (len(b.pairs), b.gp))
    for spec in filter(None, a.roots.split(',')):
        name, *args = spec.split(':')
        b.reset(); b.run_root(name, tuple(int(x, 16) for x in args))
    res = b.report()
    if a.json: json.dump(res, open(a.json, 'w'), indent=1)

if __name__ == '__main__':
    main()
