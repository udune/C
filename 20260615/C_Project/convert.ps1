$h = Get-Content -Path "practice.h" -Raw -Encoding UTF8
[System.IO.File]::WriteAllText("practice.h", $h, [System.Text.Encoding]::UTF8)

$c = Get-Content -Path "practice.c" -Raw -Encoding UTF8
[System.IO.File]::WriteAllText("practice.c", $c, [System.Text.Encoding]::UTF8)
