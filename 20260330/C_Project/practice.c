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

void calculation() {

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

void checkScore() {
	int score;

	printf("점수를 입력하세요: ");
	scanf("%d", &score);

	if (score < 0 || score > 100) {
		printf("잘못된 점수입니다. 0에서 100 사이의 값을 입력하세요.\n");
		return;
	}

	if (score >= 60) {
		printf("합격입니다.\n");
		return;
	}

	printf("불합격입니다.\n");
}

void checkBalance() {
	int balance;

	printf("계좌 잔액을 입력하세요 : ");
	scanf("%d", &balance);

	if (balance > 1000) {
		printf("출금이 가능합니다.\n");
	}
	else {
		printf("잔액이 부족합니다.\n");
	}

}	

void simpleCalculator() {
	int num1;
	int num2;
	int choice;
	double result;

	printf("첫 번째 숫자를 입력하세요: ");
	scanf("%d", &num1);

	printf("두 번째 숫자를 입력하세요: ");
	scanf("%d", &num2);

	printf("1.덧셈 2.뺄셈 3.곱셈 4.나눗셈\n");
	printf("연산을 선택하세요 : ");
	scanf("%d", &choice);

	if (choice == 1) {
		result = num1 + num2;
	}
	else if (choice == 2) {
		result = num1 - num2;
	}
	else if (choice == 3) {
		result = num1 * num2;
	}
	else if (choice == 4) {
		result = (double)num1 / num2;
	}
	else {
		printf("잘못된 선택입니다.\n");
		return;
	}

	printf("결과: %f\n", result);
}

void checkPass() {
	
	int score;
	int attendance;

	printf("점수를 입력하세요 (0-100): ");
	scanf("%d", &score);

	printf("출석 횟수를 입력하세요 (0-20): ");
	scanf("%d", &attendance);

	if (score >= 60) {
		if (attendance >= 15) {
			printf("합격입니다.\n");
		}
		else {
			printf("불합격: 출석 부족\n");
		}
	}
	else {
		if (attendance >= 15) {
			printf("불합격: 점수 부족\n");
		}
		else {
			printf("불합격: 점수 및 출석 부족\n");
		}
	}
}

void cinemaTicket() {
	int age;
	char isMember;
	int price;
	int finalPrice;

	printf("나이를 입력하세요: ");
	scanf("%d", &age);

	printf("회원입니까? (Y/N): ");
	scanf(" %c", &isMember);

	if (age < 13) {
		price = 5000; // 어린이 요금
	}
	else if (age < 65 && age >= 13) {
		price = 10000; // 성인 요금
	}
	else if (age >= 65) {
		price = 7000; // 경로 우대 요금
	}

	if (isMember == 'Y' || isMember == 'y') {
		finalPrice = price * 0.9f; // 회원 할인 10%
	}
	else {
		finalPrice = price;
	}

	printf("영화 티켓 가격: %d원\n", price);
	printf("결제 금액: %d원\n", finalPrice);
}