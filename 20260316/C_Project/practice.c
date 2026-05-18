#include "practice.h"

void boolPractice() {
	bool flag = true;
	bool off = false;

	if (flag) 
	{
		printf("이것은 참입니다.\n");
	}

	bool test = 100;
	printf("%d\n", test); // 1
}

void typeConversionPractice() {
	int a = 5, b = 2;

	// 자동형변환 없이 int 나누기
	double result1 = a / b;
	printf("자동형변환 없이 int 나누기: %f\n", result1);

	// 명시적 형변환
	double result2 = (double)a / b;
	printf("명시적 형변환 후 나누기: %f\n", result2);
}