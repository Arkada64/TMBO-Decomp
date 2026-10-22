param([string]$Out, [int]$Start = 0x100000, [int]$End = 0x1000000, [int]$Port = 28011)
$c = New-Object System.Net.Sockets.TcpClient("127.0.0.1", $Port)
$s = $c.GetStream()
$fs = [System.IO.File]::Create($Out)
$N = 40000
for ($a = $Start; $a -lt $End; $a += 8 * $N) {
    $n = [Math]::Min($N, ($End - $a) / 8)
    $msg = New-Object byte[] (4 + 5 * $n)
    [BitConverter]::GetBytes([int](4 + 5 * $n)).CopyTo($msg, 0)
    for ($i = 0; $i -lt $n; $i++) { $msg[4 + 5 * $i] = 3; [BitConverter]::GetBytes([int]($a + 8 * $i)).CopyTo($msg, 5 + 5 * $i) }
    $s.Write($msg, 0, $msg.Length)
    $want = 5 + 8 * $n; $buf = New-Object byte[] $want; $got = 0
    while ($got -lt $want) { $r = $s.Read($buf, $got, $want - $got); if ($r -le 0) { throw "eof" }; $got += $r }
    if ($buf[4] -ne 0) { throw "pine error at $a" }
    $fs.Write($buf, 5, 8 * $n)
}
$fs.Close(); $c.Close(); "dumped $Out"
