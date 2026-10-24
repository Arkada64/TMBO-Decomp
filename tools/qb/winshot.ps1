param([string]$out)
Add-Type -ReferencedAssemblies System.Drawing -TypeDefinition @"
using System; using System.Drawing; using System.Runtime.InteropServices;
public class WS {
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr dc, uint f);
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int L, T, R, B; }
  public static string Shot(IntPtr h, string path) {
    RECT r; GetWindowRect(h, out r); int w = r.R - r.L, ht = r.B - r.T;
    if (w <= 0 || ht <= 0) return "bad rect";
    using (var b = new Bitmap(w, ht)) { using (var g = Graphics.FromImage(b)) { var dc = g.GetHdc(); PrintWindow(h, dc, 2); g.ReleaseHdc(dc); }
      b.Save(path, System.Drawing.Imaging.ImageFormat.Png); }
    return w + "x" + ht;
  }
}
"@
$p = Get-Process pcsx2-qt -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 } | Select-Object -First 1
if (-not $p) { "no window"; exit }
[WS]::Shot($p.MainWindowHandle, $out)
