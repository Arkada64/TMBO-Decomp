W="/mnt/d/TMB Decomp"
VARIANTS="$*" bash "$W/shift_bisect.sh" > "$W/bis.log" 2>&1
echo BUILT >> "$W/bis.log"
