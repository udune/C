## 5. `main.c` 주석 토글 디스패처 — 확장성 개선
 
**위치**: `main.c`
 
**문제**: 실습 함수가 늘 때마다 주석 처리된 호출 목록이 비대해진다(현재 60+ 줄). 학습용으로는 무방하나, 이미 **함수 포인터·콜백**을 학습했으므로 그 복습을 겸해 메뉴 디스패처로 전환할 만하다.
 
```c
// after  — 함수 포인터 테이블 기반 메뉴 디스패처 (개념 예시)
typedef struct {
    const char* label;
    void (*run)(void);
} MenuItem;
 
static const MenuItem MENU[] = {
    { "동적 메모리 1",      DynamicMemoryEx1 },
    { "동적 메모리 2",      DynamicMemoryEx2 },
    { "월별 매출 분석",     analyzeMonthlySales },
    // ... 필요한 항목 추가
};
static const int MENU_COUNT = sizeof(MENU) / sizeof(MENU[0]);
 
int main(void) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
 
    for (int i = 0; i < MENU_COUNT; i++) {
        printf("%d. %s\n", i + 1, MENU[i].label);
    }
    printf("실행할 번호: ");
 
    int sel;
    if (scanf("%d", &sel) == 1 && sel >= 1 && sel <= MENU_COUNT) {
        MENU[sel - 1].run();
    } else {
        printf("잘못된 선택입니다.\n");
    }
    return 0;
}
```