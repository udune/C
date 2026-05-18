#include <stdio.h>

int main(void) {

	int a = 10;
	int b = 20;

	printf("산술 연산자\n");
	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);
	printf("a %% b = %d\n", a % b);

	printf("\n대입 연산자\n");
	int x = 10;
	x += 5;
	printf("x += 5 -> x = %d\n", x);
	x *= 2;
	printf("x *= 2 -> x = %d\n", x);

	printf("\n증감 연산자\n");
	int i = 1;
	printf("i++ = %d\n", i++);
	printf("현재 i = %d\n", i);
	printf("++i = %d\n", ++i);

	printf("\n관계 연산자\n");
	printf("a > b = %d\n", a > b);
	printf("a < b = %d\n", a < b);
	printf("a == b = %d\n", a == b);
	printf("a != b = %d\n", a != b);

	printf("\n논리 연산자\n");
	printf("(a > b && b > 0) = %d\n", (a > b) && (b > 0));
	printf("(a < b || b > 0) = %d\n", (a < b) || (b > 0));
	printf("!(a > b) = %d\n", !(a > b));

	printf("\n비트 연산자\n");
	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);
	printf("~a = %d\n", ~a);
	printf("b << 1 = %d\n", b << 1);
	printf("b >> 1 = %d\n", b >> 1);
}