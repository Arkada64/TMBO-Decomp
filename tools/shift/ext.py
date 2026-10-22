# ruff: noqa
import sys
import struct
import zstandard
import zlib
import zipfile
import os

z = zipfile.ZipFile(sys.argv[1])
os.makedirs(sys.argv[2], exist_ok=True)
for i in z.infolist():
    if i.filename not in (
        "eeMemory.bin",
        "iopMemory.bin",
        "Scratchpad.bin",
        "Screenshot.png",
    ):
        continue
    raw = z.fp
    raw.seek(i.header_offset)
    h = raw.read(30)
    n, e = struct.unpack_from("<HH", h, 26)
    raw.seek(i.header_offset + 30 + n + e)
    data = raw.read(i.compress_size)
    if i.compress_type == 93:
        data = zstandard.ZstdDecompressor().decompress(
            data, max_output_size=i.file_size
        )
    elif i.compress_type == 8:
        data = zlib.decompress(data, -15)
    open(sys.argv[2] + "/" + i.filename, "wb").write(data)
    print(i.filename, len(data))
