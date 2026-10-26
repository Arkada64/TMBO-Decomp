// TMBR launcher (Ark 2026-10-26, TODO 4d): one window - Play, a few toggles, PCSX2 settings.
// Build (Windows, .NET Framework 4 csc): csc /target:winexe /win32icon:TMBR.ico /resource:logo.png,TMBR.logo.png /out:TMBR.exe TMBR.cs
// (TMBR.ico / logo.png: the game's own logo, SHELL1.TEX textures 60-62 - tools/package/logo.py)
// (HD textures dropped 2026-10-26, Ark.) Lives next to pcsx2-qt.exe in the TMBR player folder; the game image is game\TMBR.iso.
using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

class TMBR : Form
{
    string dir = AppDomain.CurrentDomain.BaseDirectory;
    string Ini { get { return Path.Combine(dir, "inis", "PCSX2.ini"); } }
    string Iso { get { return Path.Combine(dir, "game", "TMBR.iso"); } }
    CheckBox full, wide, potato;
    Label note;

    TMBR()
    {
        Text = "Twisted Metal: Black Reloaded";
        FormBorderStyle = FormBorderStyle.FixedSingle; MaximizeBox = false;
        ClientSize = new Size(360, 300); BackColor = Color.FromArgb(24, 24, 24); ForeColor = Color.Gainsboro;
        Font = new Font("Segoe UI", 10);
        Control title;
        var res = System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream("TMBR.logo.png");
        if (res != null) {
            var img = Image.FromStream(res);
            int w = 328, h = img.Height * w / img.Width;
            title = new PictureBox { Image = img, SizeMode = PictureBoxSizeMode.Zoom, Size = new Size(w, h), Location = new Point(16, 6) };
            Icon = System.Drawing.Icon.ExtractAssociatedIcon(Application.ExecutablePath);
        } else title = new Label { Text = "TMB RELOADED", Font = new Font("Segoe UI", 18, FontStyle.Bold), ForeColor = Color.FromArgb(230, 60, 40), AutoSize = true, Location = new Point(16, 10) };
        int y0 = title.Bottom + 8;
        wide = Box("16:9 picture", y0);
        full = Box("Fullscreen", y0 + 26);
        potato = Box("Potato mode (native resolution, for weak PCs)", y0 + 52);
        var play = Btn("PLAY", 16, y0 + 92, 160); play.BackColor = Color.FromArgb(150, 30, 20);
        var set = Btn("PCSX2 settings", 184, y0 + 92, 160);
        note = new Label { AutoSize = false, Size = new Size(330, 22), Location = new Point(16, y0 + 134), ForeColor = Color.Gray };
        Controls.AddRange(new Control[] { title, wide, full, potato, play, set, note });
        play.Click += (s, e) => Launch(true);
        set.Click += (s, e) => Launch(false);
        Load += (s, e) => Read();
    }
    CheckBox Box(string t, int y) { var c = new CheckBox { Text = t, AutoSize = true, Location = new Point(18, y) }; return c; }
    Button Btn(string t, int x, int y, int w) { return new Button { Text = t, Location = new Point(x, y), Size = new Size(w, 34), FlatStyle = FlatStyle.Flat, ForeColor = Color.White }; }

    string Get(string[] l, string key) { foreach (var s in l) if (s.StartsWith(key + " = ")) return s.Substring(key.Length + 3); return null; }
    void Set(string[] l, string key, string v) { for (int i = 0; i < l.Length; i++) if (l[i].StartsWith(key + " = ")) l[i] = key + " = " + v; }

    void Read()
    {
        if (!File.Exists(Ini)) { note.Text = "inis\\PCSX2.ini is missing"; return; }
        var l = File.ReadAllLines(Ini);
        wide.Checked = Get(l, "AspectRatio") == "16:9";
        full.Checked = Get(l, "StartFullscreen") == "true";
        potato.Checked = Get(l, "upscale_multiplier") == "1";
        if (!Directory.Exists(Path.Combine(dir, "bios")) || Directory.GetFiles(Path.Combine(dir, "bios")).Length == 0)
            note.Text = "Put your PS2 BIOS in the bios folder first.";
        else if (!File.Exists(Iso)) note.Text = "game\\TMBR.iso is missing.";
    }
    void Write()
    {
        var l = File.ReadAllLines(Ini);
        Set(l, "AspectRatio", wide.Checked ? "16:9" : "Auto 4:3/3:2");
        Set(l, "StartFullscreen", full.Checked ? "true" : "false");
        Set(l, "upscale_multiplier", potato.Checked ? "1" : "3");
        File.WriteAllLines(Ini, l);
    }
    void Launch(bool play)
    {
        try { Write(); } catch (Exception ex) { note.Text = ex.Message; return; }
        var exe = Path.Combine(dir, "pcsx2-qt.exe");
        string args = play ? "-batch " + (full.Checked ? "-fullscreen " : "") + "-- \"" + Iso + "\"" : "";
        if (play && !File.Exists(Iso)) { note.Text = "game\\TMBR.iso is missing."; return; }
        Process.Start(new ProcessStartInfo(exe, args) { WorkingDirectory = dir, UseShellExecute = false });
        if (play) Close();
    }
    [STAThread] static void Main() { Application.EnableVisualStyles(); Application.Run(new TMBR()); }
}
