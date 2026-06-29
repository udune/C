## 2. `scanf` 반환값 미검사
 
**위치**: `input.c` — `getInt()`, `getFloat()`, `getChar()` (및 `practice.c`의 모든 `scanf`)
 
**문제**: `scanf`는 **정상 변환된 항목 수**를 반환한다. 사용자가 숫자 자리에 문자를 넣으면 변환이 실패하고, 변수는 미초기화 상태로 남으며 입력 버퍼에 잘못된 문자가 그대로 남아 이후 `scanf`가 줄줄이 실패한다(무한 루프의 흔한 원인). `common.h`의 `_CRT_SECURE_NO_WARNINGS`가 MSVC 경고까지 꺼 두어 이 결함이 눈에 띄지 않는다.
 
```c
// before
int getInt() {
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    return a;
}
```
 
```c
// after  — 입력 실패 시 버퍼를 비우고 재입력 요구
int getInt() {
    int a;
    while (1) {
        printf("Enter an integer: ");
        if (scanf("%d", &a) == 1) {
            break;                    // 정상 변환
        }
        printf("정수를 입력하세요.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { } // 입력 버퍼 비우기
    }
    return a;
}
```
 
`getFloat()`도 동일 패턴(`"%f"`, `== 1`)으로 적용한다. `getChar()`는 변환 실패가 드물지만, 일관성을 위해 반환값 확인을 권장한다.
 
---