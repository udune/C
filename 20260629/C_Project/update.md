## 6. 파일 인코딩 혼재
 
**위치**: 저장소 전반 (`main.c`/`practice.c` = UTF-8, `calculation.c` 등 = CP949)
 
**문제**: 파일별 인코딩이 섞여 있어 외부 도구(git diff, 비-MSVC 에디터, CI)에서 한글이 깨질 수 있다.
 
**권장**: 전 파일을 **UTF-8 (with BOM)** 으로 통일한다. MSVC는 BOM 있는 UTF-8을 안정적으로 인식한다.
 
```bash
# 예: CP949 → UTF-8(BOM) 일괄 변환 (Git Bash / WSL)
for f in $(grep -rIl --include='*.c' --include='*.h' . ); do
  enc=$(file -b --mime-encoding "$f")
  if [ "$enc" = "iso-8859-1" ] || [ "$enc" = "euc-kr" ]; then
    iconv -f CP949 -t UTF-8 "$f" | sed '1s/^/\xEF\xBB\xBF/' > "$f.tmp" && mv "$f.tmp" "$f"
  fi
done
```
> 변환 전 커밋/백업 필수. `.gitattributes`에 `*.c text` / `*.h text`를 두면 줄바꿈 일관성도 확보된다.
 
---