"""
Parameter types from GCC 2.x mangled names (retail TMB is C++ "C with classes").
  uiMain__Fv -> []      fogSetFogParms__Fffffiii -> [float, float, float, float, int, int, int]
  axleInit__7Vehicle -> ['void*'] (this)        mathfAddVector__FP8_fvectorT0T0 -> 3 x void*
Pointers/references/arrays all become void* (drafts only need the register class and width).
Returns None for anything not understood (class by value, templates, member pointers...).
"""
import re
BASE = {"v": None, "c": "char", "s": "short", "i": "int", "l": "int", "x": "long long", "f": "float",
        "d": "double", "r": "double", "b": "unsigned char", "w": "int", "e": "..."}
UNS = {"c": "unsigned char", "s": "unsigned short", "i": "unsigned int", "l": "unsigned int", "x": "unsigned long long"}

def _name(s, i):
    m = re.match(r"\d+", s[i:])
    if not m: raise ValueError
    n = int(m.group(0)); i += len(m.group(0)); return s[i:i + n], i + n

def _qual(s, i):
    """Q<n>[_]<len><name>... -> index after it"""
    i += 1
    if s[i] == "_":
        j = s.index("_", i + 1); n = int(s[i + 1:j]); i = j + 1
    else:
        n = int(s[i]); i += 1
    for _ in range(n): _, i = _name(s, i)
    return i

def _type(s, i):
    """one type at s[i]: returns (C type or None for void, next index)"""
    ptr, uns = False, False
    while i < len(s) and s[i] in "CVSUPRA":
        c = s[i]
        if c in "PR": ptr = True
        elif c == "A":
            j = s.index("_", i); ptr = True; i = j
        elif c == "U": uns = True
        i += 1
    c = s[i]
    if c.isdigit():
        _, i = _name(s, i); t = "STRUCT"
    elif c == "Q": i = _qual(s, i); t = "STRUCT"
    elif c == "F":                      # function type: params, '_', return
        i += 1
        while s[i] != "_": _, i = _type(s, i)
        _, i = _type(s, i + 1); t = "FUNC"
    elif c in BASE: t = (UNS.get(c) if uns else BASE[c]); i += 1
    else: raise ValueError(c)
    if ptr: return "void*", i
    if t in ("STRUCT", "FUNC"): raise ValueError("by value")
    return t, i

def params(mangled):
    m = re.match(r"^(.*?)__(.+)$", mangled)
    if not m: return None
    s = m.group(2)
    try:
        out, i = [], 0
        if s[0] == "F": i = 1                                # free function
        elif s[0] in "C" and (s[1].isdigit() or s[1] == "Q"): # const method
            i = _qual(s, 1) if s[1] == "Q" else _name(s, 1)[1]; out.append("void*")
        elif s[0].isdigit() or s[0] == "Q":                  # method (or ctor when name is empty)
            i = _qual(s, 0) if s[0] == "Q" else _name(s, 0)[1]
            if i < len(s) and s[i] == "S": i += 1           # static method: no this
            else: out.append("void*")
        else: return None
        while i < len(s):
            c = s[i]
            if c == "T":                                     # repeat of earlier param n
                m2 = re.match(r"T_(\d+)_|T(\d)", s[i:])
                n = int(m2.group(1) or m2.group(2)); out.append(out[n]); i += len(m2.group(0))
            elif c == "N":                                   # N<count><idx> (or N<count>_<idx>_ when >9)
                m2 = re.match(r"N(\d)(\d)|N(\d+)_(\d+)_", s[i:])
                cnt, n = (int(m2.group(1)), int(m2.group(2))) if m2.group(1) else (int(m2.group(3)), int(m2.group(4)))
                out += [out[n]] * cnt; i += len(m2.group(0))
            else:
                t, i = _type(s, i)
                if t is None:                                # 'v' = no parameters
                    continue
                out.append(t)
        return out
    except (ValueError, IndexError, AttributeError):
        return None

if __name__ == "__main__":
    for n in ["uiMain__Fv", "fogSetFogParms__Fffffiii", "axleInit__7Vehicle", "mathfAddVector__FP8_fvectorT0T0",
              "animationPause__FR11_animHandle", "viewSetBgColor__FUlUlUlUl", "uiInitScreens__FP3_cs",
              "attachAddTire__7VehicleiP9_hierhead", "mathfMulTransVec4x4__FPA3_A3_fP8_fvectorT1", "Init__5Comboi"]:
        print(n, params(n))
