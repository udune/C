# C_Project 2차 패치 문서

> 대상 저장소: `udune/C` — `C_Project` (기준 스냅샷: `20260629/C_Project`, 1차 패치 반영본)
> 작성일: 2026-06-29
> 목적: 1차 패치 반영 후 **빌드 검증 + 재분석** 과정에서 발견된 잔여 이슈의 수정 가이드.
> 1차 6개 항목은 모두 반영 완료(검증 끝). 본 문서는 그 외 항목만 다룬다.

---

## 이슈 요약

| # | 이슈 | 심각도 | 위치 | 유형 |
|---|------|--------|------|------|
| A | `freeSwapCharMemory` — `static` 정의 vs 비-static 선언 충돌 | **높음** | `practice.h:63` / `practice.c:1214` | 빌드/이식성 |
| B | `sizeof` 결과를 `%d`로 출력 | 중간 | `practice.c::ArrayStringInit` (4곳) | 이식성/정확성 |
| C | 미사용 변수 `off` | 낮음 | `practice.c::boolPractice` | 정리 |
| D | `safe_scanf` 설계 검토 (`#define scanf` 표준명 가림 + `input.c` 중복) | 중간 | `practice.c:4~37` | 설계/표준 준수 |

권장 처리 순서: **A → D → B → C**

> 비고: A는 MSVC에서는 경고로 통과하지만 gcc/clang에서는 **컴파일 에러로 빌드 실패**한다(실측 확인). 이식성을 고려하면 가장 먼저 처리할 항목이다.

---

## A. `freeSwapCharMemory` — `static` 정의 vs 비-static 선언 충돌

**위치**: 선언 `practice.h:63`, 정의 `practice.c:1214`, 호출 `practice.c:1210` (호출은 `practice.c` 내부 한 곳뿐)

**문제**: 헤더에는 외부 연결(external linkage)로 선언돼 있는데, 정의는 내부 연결(`static`)로 돼 있다. 표준상 모순된 선언이며, MSVC는 경고로 넘기지만 gcc는 다음과 같이 거부한다.

```
practice.c:1214:13: error: static declaration of 'freeSwapCharMemory' follows non-static declaration
```

**판단 근거**: `freeSwapCharMemory`는 `practice.c` 내부(`SwapChar` 등)에서만 호출되고 외부 파일에서 쓰이지 않는다. 따라서 **내부 전용 헬퍼**로 보고 양쪽을 `static`으로 통일하는 것이 가장 깔끔하다(헤더에서 선언 제거).

```c
// before  (practice.h:63)
void freeSwapCharMemory(char** str, int n);
```

```c
// after  (practice.h)  — 외부에서 안 쓰므로 헤더 선언 삭제
// (해당 줄 제거)
```

```c
// practice.c — 정의는 static 유지 (단, 호출보다 위에 와야 함, 아래 주의 참고)
static void freeSwapCharMemory(char** str, int n) {
    if (str == NULL) {
        return;
    }
    /* ... */
}
```

> **주의**: 현재 정의(1214행)가 호출(1210행)보다 **아래**에 있다. `static` 함수를 호출보다 뒤에 정의하면 선언이 헤더에서 사라지는 순간 "암시적 선언" 경고/에러가 난다. 두 가지 중 하나로 해결한다.
> 1. (권장) `practice.c` 상단(`safe_scanf` 부근)에 **static 프로토타입**을 한 줄 추가:
>    ```c
>    static void freeSwapCharMemory(char** str, int n);
>    ```
> 2. 또는 함수 정의 자체를 첫 호출보다 위로 이동.
>
> **대안**: 외부 공개가 필요하다면 반대로 정의의 `static`을 제거해 양쪽을 비-static으로 맞춰도 된다. 핵심은 **선언과 정의의 연결 지정을 일치**시키는 것.

---

## D. `safe_scanf` 설계 검토

**위치**: `practice.c:4~37`

**현황**: 1차 패치에서 권장한 "각 `scanf` 개별 검사" 대신, 가변 인자 래퍼를 직접 구현하고 매크로로 일괄 치환했다. 발상 자체는 DRY하고 좋다.

```c
int safe_scanf(const char* format, ...) {
    // 포맷에서 변환 지정자 개수를 세고(%% 처리 포함),
    // vscanf 결과가 기대치와 같을 때까지 버퍼를 비우며 재입력
}
#define scanf safe_scanf   // practice.c:37
```

평가할 점: 포맷 파싱에서 `%%`를 올바르게 건너뛰고, 루프마다 `va_start`/`va_end`를 다시 호출하는 처리(가변 인자 재사용 규칙)도 정확하다. 동작 자체는 견고하다.

다만 **구조상 세 가지**를 짚는다.

### D-1. 표준 라이브러리 이름을 매크로로 가림 (이식성/표준 준수)

`#define scanf safe_scanf`는 표준 라이브러리 식별자 `scanf`를 매크로로 재정의한다. 표준(C11 §7.1.3)상 라이브러리 예약 식별자를 매크로로 덮는 것은 **정의되지 않은 동작(UB)** 영역이다. MSVC/gcc에서는 실제로 동작하지만, 권장되는 방식은 아니다.

```c
// after (권장)  — 매크로 치환 대신 함수를 명시적으로 호출
// #define scanf safe_scanf   ← 제거
// 호출부:  scanf("%d", &x);   →   safe_scanf("%d", &x);
```

명시 호출이 번거롭다면, 최소한 매크로 이름을 표준명이 아닌 고유명으로 두는 편이 안전하다(예: 처음부터 `SCANF(...)`로 호출).

### D-2. `input.c`와 검증 로직 중복

`input.c`의 `getInt/getFloat/getChar`는 1차 패치에서 **수동 재입력 루프**로 검증하고, `practice.c`는 `safe_scanf`로 검증한다. 같은 목적의 코드가 두 군데에 서로 다른 방식으로 존재한다. 또한 `safe_scanf`는 `practice.c`에만 있어 `input.c`에는 적용되지 않는다.

**권장**: `safe_scanf`를 공용으로 승격해 한 곳에서만 관리한다.

```c
// common.h  (또는 util.h 신설)
int safe_scanf(const char* format, ...);
```
```c
// safe_scanf.c (신설) — 정의 이동
#include "common.h"
#include <stdarg.h>
int safe_scanf(const char* format, ...) { /* 기존 구현 그대로 */ }
```
```c
// input.c — 수동 루프 대신 공용 래퍼 사용으로 통일
int getInt() {
    int a;
    printf("Enter an integer: ");
    safe_scanf("%d", &a);   // 검증/재입력은 래퍼가 담당
    return a;
}
```
이렇게 하면 검증 정책이 한 곳에 모이고, `input.c`/`practice.c`가 동일하게 동작한다.

### D-3. 부분 매칭 시 전체 재입력 (동작 메모)

`safe_scanf("%19s %d", ...)`에서 문자열만 성공하고 정수가 실패하면(`ret=1`, 기대 `2`), 줄 전체를 비우고 **포맷 전체를 다시** 읽는다. 즉 이미 입력한 문자열도 다시 입력해야 한다. 학습용으로는 무방하나, 다중 입력 폼에서는 사용자 경험이 나빠질 수 있다는 점만 인지한다. (개선하려면 항목 단위로 쪼개 입력받는다.)

---

## B. `sizeof` 결과를 `%d`로 출력

**위치**: `practice.c::ArrayStringInit()` — 549, 554, 560, 565행

**문제**: `sizeof`의 결과 타입은 `size_t`(부호 없는 정수, 보통 64비트)다. 이를 `%d`(`int`)로 출력하면 64비트/타 플랫폼에서 값이 깨질 수 있다. MSVC 32비트에서 우연히 맞는 것뿐이다.

```c
// before
printf("\narr1 크기: %d \n", sizeof(arr1));
```

```c
// after  — size_t 전용 지정자 %zu (C99 이상)
printf("\narr1 크기: %zu \n", sizeof(arr1));
```

549/554/560/565행 4곳 모두 `%d` → `%zu`. (MSVC 구버전에서 `%zu` 미지원 시 `%Iu` 또는 `(unsigned long long)` 캐스트 + `%llu`로 대체.)

---

## C. 미사용 변수 `off`

**위치**: `practice.c::boolPractice()`

**문제**: 선언 후 한 번도 사용되지 않는다. `-Wall`에서 경고로 잡힌다.

```c
// before
bool flag = true;
bool off = false;   // 미사용
```

```c
// after  — 제거 (또는 실제로 사용하는 예제로 확장)
bool flag = true;
```

---

## 적용 체크리스트

- [ ] (A) `practice.h`의 `freeSwapCharMemory` 선언 제거 + `practice.c` 상단에 `static` 프로토타입 추가(또는 양쪽 비-static 통일)
- [ ] (D-1) `#define scanf safe_scanf` 제거, `safe_scanf(...)` 명시 호출로 전환
- [ ] (D-2) `safe_scanf`를 공용 파일로 분리하고 `input.c`도 동일 래퍼 사용
- [ ] (D-3) 부분 매칭 재입력 동작 인지(필요 시 항목 단위 입력으로 개선)
- [ ] (B) `ArrayStringInit` 4곳 `%d` → `%zu`
- [ ] (C) `boolPractice`의 `off` 제거
- [ ] (공통) 컴파일 경고 레벨 상향: MSVC `/W4`, gcc/clang `-Wall -Wextra` → 경고 0 목표

---

## 검증 메모

- 빌드 검증: Windows 의존 헤더(`windows.h`, `conio.h`)를 스텁으로 대체 후 전체 `.c`를 gcc로 링크. **A 항목 1건만 에러**였고, 수정 시 정상 빌드·링크 확인.
- 1차 패치(6항목)는 전부 정상 반영 확인. B/C는 경고 수준, D는 설계 개선 권고.