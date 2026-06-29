## 3. `calculation.c`에 자체 `main()` 존재 — 중복 심볼
 
**위치**: `calculation.c`
 
**문제**: `calculation.c`가 `int main(void)`를 정의한다. `main.c`에도 `main()`이 있으므로 두 파일이 같은 빌드에 포함되면 **링커 중복 정의 에러**가 난다. 현재는 빌드에서 빠진 스크래치 파일로 보이지만, 구조상 위험하다.
 
**핵심**: `practice.h`에 이미 `void calculation();` 선언이 존재한다. 즉, 정의만 그 시그니처에 맞추면 곧바로 정상 모듈이 된다.
 
```c
// before  (calculation.c)
#include <stdio.h>
int main(void) {
    int a = 10;
    int b = 20;
    /* ... 연산자 실습 ... */
}
```
 
```c
// after  (calculation.c)  — practice.h의 선언과 일치시킴
#include "practice.h"     // 또는 "common.h"
void calculation(void) {
    int a = 10;
    int b = 20;
    /* ... 연산자 실습 ... */
}
```