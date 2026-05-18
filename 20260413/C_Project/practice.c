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

void shoppingDiscount() {
	int price;
	char memberGrade;
	int finalPrice;

	printf("구매 금액을 입력하세요 : ");
	scanf("%d", &price);

	if (price < 50000) {
		printf("결제 금액이 5만원 미만입니다. 할인 적용이 없습니다.\n");
		finalPrice = price;
	}
	else
	{
		printf("회원 등급을 입력하세요(G: 일반, V: VIP) : ");
		scanf(" %c", &memberGrade);

		if (memberGrade == 'G' || memberGrade == 'g')
		{
			printf("일반 회원입니다.\n");
			finalPrice = price * 0.95f;
		}
		else if (memberGrade == 'V' || memberGrade == 'v')
		{
			printf("VIP 회원입니다.\n");
			finalPrice = price * 0.9f;
		}
		else
		{
			printf("잘못된 회원 등급입니다. 일반 회원으로 처리됩니다.\n");
			finalPrice = price * 0.95f;
		}
	}

	printf("결제 금액 : %d원\n", finalPrice);
}

typedef struct {
	int myHp;
	int myMp;
	int enemyHp;
} StatusData;

StatusData statusData = { 100, 50, 50 };
void CombatGame() {
    if (statusData.myHp <= 0) {
        printf("You Died..\n");
        return;
    }

    if (statusData.enemyHp <= 0) {
        printf("You Win!\n");
        return;
    }

    int choice;

    printf("행동을 선택하세요 (1. 공격, 2. 마법, 3. 회복, 4. 도망) : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("공격을 선택했습니다.\n");
        statusData.enemyHp -= 10;
        printf("적의 남은 HP: %d\n", statusData.enemyHp);

		CombatGame();
        break;
    case 2:
        printf("마법을 선택했습니다.\n");
        statusData.myMp -= 10;
        statusData.enemyHp -= 20;
        printf("적의 남은 HP: %d\n", statusData.enemyHp);

		CombatGame();
        break;
    case 3:
        printf("회복을 선택했습니다.\n");
        statusData.myHp += 15;
        if (statusData.myHp > 100) {
            statusData.myHp = 100;
        }
        printf("내 HP: %d\n", statusData.myHp);

		CombatGame();
        break;
    case 4:
        printf("도망을 선택했습니다.\n");
        break;
    default:
        printf("잘못된 선택입니다.\n");

		CombatGame();
        break;
    }
}

void TourRecommand(bool reQuestion) {

	int choice;

	if (!reQuestion) {
		printf("여행지를 추천해드립니다!\n");
	}

	printf("지역을 선택하세요. (1. 서울 2. 부산 3. 제주) : ");
	scanf("%d", &choice);

	switch (choice) {
	case SEOUL:
		printf("서울을 선택하셨습니다.\n");
		printf("서울숲, 한강공원, 경복궁, 북촌한옥마을 등 다양한 명소가 있습니다.\n");
		printf("즐거운 여행 되세요!\n");
		break;
	case BUSAN:
		printf("부산을 선택하셨습니다.\n");
		printf("해운대, 광안리, 자갈치시장, 감천문화마을 등 다양한 명소가 있습니다.\n");
		printf("즐거운 여행 되세요!\n");
		break;
	case JEJU:
		printf("제주를 선택하셨습니다.\n");
		printf("한라산, 성산일출봉, 제주민속촌, 올레길 등 다양한 명소가 있습니다.\n");
		printf("즐거운 여행 되세요!\n");
		break;
	default:
		printf("잘못된 선택입니다. 1, 2, 3 중에서 선택해주세요.\n");
		TourRecommand(true);
		break;
	}
}

void printGugudan() {
	int dan = 1;
	int num = 1;

	printf("몇 단을 프린트할까요? : ");
	scanf("%d", &dan);

	while (num <= 9) {
		printf("%d x %d = %d\n", dan, num, dan * num);
		num++;
	}
}

void printAllGugudan() {
	int dan = 2;
	int num = 1;

	while (dan <= 9) {
		num = 1;
		while (num <= 9) {
			printf("%d x %d = %d\n", dan, num, dan * num);
			num++;
		}

		printf("\n");
		dan++;
	}
}

void printAllGugudan2() {
	int dan = 2;
	int num = 1;

	while (num <= 9) {
		dan = 2;
		while (dan <= 9) {
			printf("%d x %d = %d\t", dan, num, dan * num);
			dan++;
		}

		printf("\n");
		num++;
	}
}

void passwordCheck() {
	int password;
	int input;

	printf("비밀번호를 등록하세요 : ");
	scanf("%d", &password);

	printf("비밀번호를 입력하세요 : ");
	scanf("%d", &input);

	while (password != input) {
		printf("비밀번호가 틀렸습니다.\n");
		printf("다시 입력하세요 : ");
		scanf("%d", &input);
	}

	printf("비밀번호가 일치합니다. 로그인 성공!\n");
}

void initUntilEqual() {
	int num1;
	int num2;

	do {
		printf("두 개의 숫자를 입력하세요: ");
		scanf("%d %d", &num1, &num2);

		if (num1 != num2) {
			printf("숫자가 일치하지 않습니다. 다시 입력하세요.\n");
		}
	} while (num1 != num2);

	printf("숫자가 일치합니다. 프로그램을 종료합니다.\n");
}

void printEvenNumbers() {
	int num = 0;
	int total = 0;

	do {
		printf("숫자를 입력하세요 (0 입력 시 종료) : ");
		scanf("%d", &num);

		if (num % 2 == 0 && num != 0) {
			total += num;
		}

	} while (num != 0);

	if (num == 0) {
		printf("프로그램을 종료합니다.");
		return;
	}

	printf("입력한 짝수의 총합은 %d입니다.", total);
}