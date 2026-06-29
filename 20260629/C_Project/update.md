# C_Project 3차 패치 문서

> 대상 저장소: `udune/C` — `C_Project` (기준 스냅샷: `20260629/C_Project`, 1·2차 패치 반영본)
> 작성일: 2026-06-29
> 목적: 1·2차 패치로 빌드 에러가 0이 된 뒤, **컴파일 경고 레벨을 `-Wall -Wextra`로 올려** 드러난 잔여 이슈의 수정 가이드.
> 배경: 1·2차 때는 `freeSwapCharMemory` 빌드 에러가 전체 컴파일을 막아 경고 분석까지 도달하지 못했다. 2차에서 그 에러가 해소되면서 아래 항목들이 비로소 노출됐다.

---

## 이슈 요약

| # | 이슈 | 심각도 | 위치 | 유형 |
|---|------|--------|------|------|
| E | `gets()` 사용 — 무제한 입력 (C11 삭제 함수) | **높음** | `practice.c:617` `StringFunc()` | 보안/안정성 |
| F | `getChar`/`printChar` 암시적 선언 | 중간 | `practice.c:591,596` `CharFunction()` | 빌드/정확성 |
| G | 포인터 예제의 포맷·라벨·주석 오류 | 중간(교육적) | `practice.c:825,828` `pointerInit()` / `1026` `printArray2()` | 정확성/학습 |
| H | `Todo` 공용체 초기화 누락 경고 | 낮음 | `practice.c::testTodoSystem` | 정리 |

권장 처리 순서: **E → F → G → H**

> 참고: 본 저장소는 두 차례에 걸쳐 `scanf`를 `%99s`/`safe_scanf`로 강화해 버퍼 오버플로를 제거했다. E의 `gets()`는 그 노력과 정면으로 모순되는 단일 취약점이므로 **최우선**으로 처리한다.

---

## E. `gets()` 사용 — 무제한 입력

**위치**: `practice.c:617`, `StringFunc()`

**문제**: `gets()`는 입력 길이를 전혀 제한하지 않아, 버퍼 크기를 넘는 입력이 들어오면 그대로 스택을 침범한다. 위험성 때문에 **C11에서 표준 라이브러리에서 삭제**됐고, gcc는 링크 시 다음 경고를 낸다.

```
warning: the `gets' function is dangerous and should not be used.
warning: implicit declaration of function 'gets'; did you mean 'fgets'?
```

```c
// before
void StringFunc() {
    char str[100];
    printf("문자열 입력 : \n");
    gets(str);                 // ← 길이 제한 없음
    printf("입력한 문장 : \n");
    puts(str);
}
```

```c
// after  — fgets로 교체 (버퍼 크기 전달 + 개행 제거)
void StringFunc() {
    char str[100];
    printf("문자열 입력 : \n");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';   // 입력 끝 개행 제거
    }
    printf("입력한 문장 : \n");
    puts(str);
}
```

> `fgets`는 `\n`까지 포함해 읽으므로 `strcspn`으로 개행을 잘라낸다. `<string.h>`는 `common.h`에 이미 포함돼 있다.

---

## F. `getChar`/`printChar` 암시적 선언

**위치**: `practice.c:591, 596`, `CharFunction()`

**문제**: `CharFunction()`이 `getChar()`와 `printChar()`를 호출하는데, 두 함수는 각각 `input.h`/`output.h`에 선언돼 있다. 그런데 `practice.c`는 `practice.h`만 포함하므로 컴파일러가 이 둘을 **암시적으로 선언**(반환형 `int`로 가정)한다.

```
warning: implicit declaration of function 'getChar'; did you mean 'getchar'?
warning: implicit declaration of function 'printChar'; did you mean 'putchar'?
```

지금은 우연히 동작하지만, 실제 시그니처와 가정된 시그니처가 어긋나면 잘못된 호출 규약으로 깨진다. 헤더를 명시적으로 포함해 해결한다.

```c
// before  (practice.c 상단)
#include "practice.h"
#include <stdarg.h>
```

```c
// after
#include "practice.h"
#include "input.h"     // getChar 선언
#include "output.h"    // printChar 선언
#include <stdarg.h>
```

> 대안: 입출력 헬퍼를 프로젝트 전반에서 쓴다면 `input.h`/`output.h`를 `common.h`에 묶어도 된다. 다만 헤더 결합도가 올라가므로, 필요한 곳에서만 포함하는 현재 방식이 더 깔끔하다.

---

## G. 포인터 예제의 포맷·라벨·주석 오류

포인터를 **가르치는** 함수에서 "주소(address)"와 "값(value)"이 뒤섞여 있다. 입문자가 가장 헷갈리는 지점이므로 동작 여부와 별개로 정확히 잡아야 한다.

### G-1. `pointerInit()` — `practice.c:822~836`

**문제 1**: 주소(`&num`, `&ptr`)를 `%d`로 출력한다. 주소는 포인터이므로 `%p` + `(void*)` 캐스트가 맞다. `%d`는 64비트에서 값이 잘린다.

**문제 2**: 라벨이 실제 출력과 어긋난다. `"*ptr: %d", &ptr`는 라벨이 `*ptr`(역참조 값)인데 실제로는 `&ptr`(ptr 변수의 주소)을 넘긴다 — 개념이 정반대다.

**문제 3**: 주석 `// &num == &ptr 이므로...`는 **거짓**이다. `ptr == &num`은 참이지만(ptr이 num의 주소를 담음), `&num`(num의 주소)과 `&ptr`(ptr의 주소)은 서로 다른 변수의 주소이므로 같지 않다.

```c
// before
int num = 10;
int* ptr = &num;

printf("num: %d\n", &num);      // 라벨 num인데 주소를 %d로
printf("*ptr: %d\n\n", &ptr);   // 라벨 *ptr인데 &ptr을 전달
// &num == &ptr이므로, num과 ptr이 가리키는 주소값은 같습니다.  ← 거짓
```

```c
// after  — 주소는 %p+(void*), 값은 %d. 라벨을 실제 출력과 일치
int num = 10;
int* ptr = &num;

printf("num 값:          %d\n", num);          // 변수의 값
printf("num 주소 (&num): %p\n", (void*)&num);  // 변수의 주소
printf("ptr 값:          %p\n", (void*)ptr);   // ptr이 담은 주소 (== &num)
printf("*ptr (역참조):   %d\n", *ptr);          // ptr이 가리키는 값 (== num)
printf("ptr 주소 (&ptr): %p\n", (void*)&ptr);  // ptr 변수 자신의 주소 (≠ &num)

// 관계 정리:
//   ptr == &num   (참: ptr은 num의 주소를 담는다)
//   *ptr == num   (참: 역참조하면 num의 값)
//   &ptr != &num  (참: ptr과 num은 서로 다른 변수다)
```

> 함수 뒷부분(`printf("ptr: %p\n", ptr)`, `*ptr` 출력 등)은 이미 올바르므로 그대로 둔다. 위 첫 블록과 거짓 주석만 교체하면 된다.

### G-2. `printArray2()` — `practice.c:1026`

**문제**: 라벨 `"arr+%d"`는 주소를 출력하려는 의도인데, `%p`에 **값** `*(arr + i)`(int)를 넘긴다. 형식·의도가 모두 어긋난다.

```c
// before
printf("arr+%d : %p \n\n", i, *(arr + i));   // %p에 int 값 전달
```

```c
// after  — 주소를 보이려는 의도라면 (void*)(arr + i)
printf("arr+%d : %p \n\n", i, (void*)(arr + i));
// (값을 보이려는 의도였다면 → printf("arr[%d] : %d\n\n", i, *(arr + i)); )
```

---

## H. `Todo` 공용체 초기화 누락 (경고)

**위치**: `practice.c::testTodoSystem()`

**문제**: `Todo t1 = { "...", TODO_PENDING };`처럼 초기화하면 마지막 멤버인 공용체 `info`가 초기화 목록에서 빠져 `-Wmissing-field-initializers` 경고가 난다(3건). 이후 `strcpy`로 채우므로 실동작 위험은 낮다.

```c
// before
Todo t1 = { "c 언어 공부", TODO_PENDING };
strcpy(t1.info.createdDate, "2026-06-11");
```

```c
// after  — 나머지 멤버를 0으로 명시 초기화 (경고 제거)
Todo t1 = { "c 언어 공부", TODO_PENDING, {0} };
strcpy(t1.info.createdDate, "2026-06-11");
```

> 또는 `Todo t1 = {0};` 후 필드를 개별 대입하는 방식도 가능하다. 핵심은 집합 초기화 시 전체 멤버를 명시해 경고를 없애는 것.

---

## 적용 체크리스트

- [ ] (E) `StringFunc`의 `gets(str)` → `fgets` + `strcspn` 개행 제거
- [ ] (F) `practice.c`에 `#include "input.h"`, `#include "output.h"` 추가
- [ ] (G-1) `pointerInit` 첫 블록 포맷/라벨 수정 + 거짓 주석 교정
- [ ] (G-2) `printArray2`의 `%p`에 `(void*)(arr + i)` 전달
- [ ] (H) `Todo` 집합 초기화에 `{0}` 추가 (3곳)
- [ ] (공통) `-Wall -Wextra`(gcc) / `/W4`(MSVC) 상시 적용 → 경고 0 유지

---

## 검증 메모

- 현재 빌드: 에러 0, 정상 링크. 본 문서 항목은 모두 `-Wall -Wextra` 경고 수준(E는 잠재적 런타임 취약점).
- E~H 반영 후 재빌드하면 의미 있는 경고는 0에 수렴할 것으로 예상(`conio.h` 스텁 관련 경고는 실제 MSVC 환경에선 발생하지 않음).
- 권고: 이번 이후로는 경고 레벨을 항상 올린 상태로 작업하면, 같은 유형(포맷 불일치·암시적 선언·위험 함수)이 작성 시점에 바로 잡힌다.