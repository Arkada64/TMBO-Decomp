# ruff: noqa
"""
Every online function that walks the vehicle array (stride 0x31B0): loop bound and calls inside the loop.
Output: fx/vehloops.txt (one line per function) for the traffic design.
"""
import re, glob, collections, csv
R = "/home/ark/tmbo_decomp/"
names = {}
for row in csv.DictReader(open(R + "reference/match/mapping.csv")):
    if row["retail_name"]: names[row["online_addr"][2:].upper().zfill(8)] = row["retail_name"]
def nice(t):
    m = re.match(r"func_([0-9A-F]{8})", t)
    return names.get(m.group(1), t) if m else t
files = [f for f in glob.glob(R + "asm/**/*.s", recursive=True) if "0x31B0" in open(f, errors="replace").read()]
out = []
for f in files:
    cur, body = None, collections.defaultdict(list)
    for l in open(f, errors="replace"):
        m = re.match(r"glabel (\S+)", l)
        if m: cur = m.group(1); continue
        if cur: body[cur].append(l.rstrip())
    for fn, ls in body.items():
        txt = "\n".join(ls)
        if "0x31B0" not in txt: continue
        bounds = sorted(set(re.findall(r"slti\s+\$\w+, \$\w+, (0x[0-9A-F]+|\d+)", txt)))
        cnt = sorted(set(re.findall(r"(0x7CA[0-9A-F]|0x7CB[0-9A-F]|unk9FC[0-9A-F]+)", txt)))
        calls = [nice(c) for c in re.findall(r"jal\s+(\S+)", txt)]
        n31 = txt.count("0x31B0")
        out.append((nice(fn), f.replace(R, ""), n31, bounds, cnt, calls))
out.sort(key=lambda x: -x[2])
with open("/mnt/c/Users/Ark/Desktop/TMB Decomp/fx/vehloops.txt", "w") as o:
    for fn, f, n31, b, c, calls in out:
        uniq = list(dict.fromkeys(calls))
        o.write(f"{fn} [{f}] x{n31} slti{b} cnt{c} calls: {', '.join(uniq[:14])}{' ...' if len(uniq) > 14 else ''}\n")
print(len(out), "functions")
