#!/usr/bin/env python3
"""
Extract the DME network schema from m2c output of the net init function (func_0016D830).
Patterns (from reading the decompiled code):
  objects : func_00274758()  begin object layout
            func_00274780(init, field, size, kind)   add field
            func_00274958(&TYPEID, &NAME, objsize)   register object type
            func_00274CE0(TYPEID, onCreate, onUpdate, onDestroy)
  messages: func_002746B8()  begin message layout
            func_002746E0(base, field, size, kind)   add field
            func_00274CC0(&MSGID, handler)            register message, id stored in a global
"""
import re, sys, json
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from strrefs import Img

ROOT = Path.home() / "tmbo_decomp"
src = (ROOT / "reference/m2c/func_0016D830.c").read_text().splitlines()
img = Img(ROOT / "disks/SCUS_971.96")

def off(expr):
    expr = expr.strip()
    m = re.fullmatch(r"&sp([0-9A-F]+)\s*-\s*&sp([0-9A-F]+)", expr)
    if m: return int(m.group(1), 16) - int(m.group(2), 16)
    m = re.fullmatch(r"(0x[0-9A-Fa-f]+|\d+)", expr)
    if m: return int(m.group(1), 0)
    return None   # field given by address; position resolved from base below

def num(x):
    try: return int(x, 0)
    except ValueError: return None

def args(line, fn):
    m = re.search(fn + r"\((.*)\);", line)
    return [a.strip() for a in m.group(1).split(",")] if m else None

objects, messages, fields, last_msg_id = [], [], [], None
mode = None
for line in src:
    if "/* extern */" in line: continue
    if "func_00274758(" in line: mode, fields = "obj", []
    elif "func_002746B8(" in line: mode, fields = "msg", []
    elif (a := args(line, "func_00274780")) and len(a) == 4:
        fields.append({"arg": a[1], "off": off(a[1]), "size": num(a[2]), "kind": num(a[3])})
    elif (a := args(line, "func_002746E0")) and len(a) == 4:
        base = re.search(r"&sp([0-9A-F]+)", a[0]); fld = re.search(r"&sp([0-9A-F]+)", a[1])
        o = int(fld.group(1), 16) - int(base.group(1), 16) if base and fld else None
        fields.append({"arg": a[1], "off": o, "size": num(a[2]), "kind": num(a[3])})
    elif (a := args(line, "func_00274958")) and len(a) == 3:
        name = img.cstr(int(a[1].lstrip("&D_"), 16)) or a[1]
        objects.append({"name": name, "id_var": a[0].lstrip("&"), "size": num(a[2]), "fields": fields, "callbacks": None})
    elif (a := args(line, "func_00274CE0")) and len(a) == 4:
        objects[-1]["callbacks"] = {"create": a[1].lstrip("&"), "update": a[2].lstrip("&"), "destroy": a[3].lstrip("&")}
    elif (a := args(line, "func_00274CC0")) and len(a) == 2:
        messages.append({"handler": a[1].lstrip("&"), "fields": fields, "id_var": None})
    elif messages and messages[-1]["id_var"] is None and (m := re.match(r"\s*(D_[0-9A-F]+) = spA44;", line)):
        messages[-1]["id_var"] = m.group(1)

# object field offsets: m2c writes them as (&spEND - &spX) == END - X, already positive;
# first field "0"/"4" literal is absolute.
for o in objects:
    print(f"\nOBJECT {o['name']}  size={o['size']}  id={o['id_var']}  callbacks={o['callbacks']}")
    for f in o["fields"]:
        print(f"    +0x{f['off']:02X}  size {str(f['size']):>2}  kind {f['kind']}" if f["off"] is not None else f"    +?    size {str(f['size']):>2}  kind {f['kind']}  ({f['arg']})")
for i, m in enumerate(messages):
    total = sum((f["size"] or 0) for f in m["fields"])
    print(f"\nMESSAGE #{i}  id={m['id_var']}  handler={m['handler']}  payload={total} bytes in {len(m['fields'])} fields")
    for f in m["fields"]:
        print(f"    +0x{f['off']:02X}  size {str(f['size']):>3}  kind {f['kind']}" if f["off"] is not None else f"    +?  size {f['size']}  ({f['arg']})")
json.dump({"objects": objects, "messages": messages}, open(ROOT / "reference/net_schema.json", "w"), indent=1)
