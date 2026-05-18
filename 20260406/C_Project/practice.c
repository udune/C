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

	} while (num % 2 == 0);

	if (num == 0) {
		printf("프로그램을 종료합니다.");
		return;
	}

	printf("입력한 짝수의 총합은 %d입니다.", total);
}

void forGugudan() {
	int dan = 1;
	int num = 1;

	printf("몇 단을 프린트할까요? : ");
	scanf("%d", &dan);

	for (int num = 1; num <= 9; num++) {
		printf("%d x %d = %d\n", dan, num, dan * num);
	}
}

void forMultiGugudan() {
	for (int dan = 2; dan <= 9; dan++) {
		for (int num = 1; num <= 9; num++) {
			printf("%d x %d = %d\n", dan, num, dan * num);
		}
		printf("\n");
	}
}

void sumNumber() {
	int num = 0;
	int sum = 0;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		sum += i;
		if (i == 1) {
			printf("%d", i);
		}
		else if (i > 1 && i < num) {
			printf(" + %d", i);
		}
		else {
			printf(" + %d = %d\n", i, sum);
		}

		if (i % 20 == 0 && i != num) {
			printf("\n");
		}
	}
}

void sumOddEven() {
	int start;
	int end;

	while (true) {
		printf("시작 정수를 입력하세요 : ");
		scanf("%d", &start);
		printf("끝 정수를 입력하세요 : ");
		scanf("%d", &end);

		if (start <= end) {
			int oddSum = 0;
			int evenSum = 0;

			for (int i = start; i <= end; i++) {
				if (i % 2 == 0) {
					evenSum += i;
				}
				else {
					oddSum += i;
				}
			}

			printf("%d부터 %d까지 홀수 합: %d\n", start, end, oddSum);
			printf("%d부터 %d까지 짝수 합: %d\n", start, end, evenSum);

			break;
		}
		else {
			printf("잘못된 입력입니다. 시작 정수는 끝 정수보다 작거나 같아야 합니다. 다시 입력해주세요.\n");
		}
	}
}

void HowToUseProg() {
	printf("=== 덧셈 결과 출력 프로그램 ===\n");
	printf("두개의 정수를 입력하세요\n");
}

int getNumber() {
	int num;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	return num;
}

int Add(int num1, int num2) {
	return num1 + num2;
}

void AddResult(int result) {
	printf("두수의 합 : %d\n", result);
}

void printTitle() {
	printf("=== 은행 계좌 관리 프로그램 ===\n");
}

int getInitialBalance() {
	int balance;
	printf("초기 잔액을 입력하세요 : ");
	scanf("%d", &balance);
	return balance;
}

int manageAccount(int balance) {
	int menu;
	int currentBalance = balance;

	int depositAmount;
	int withdrawAmount;

	do {
		printf("\n 1. 입금 2. 출금 3. 종료 : ");
		scanf("%d", &menu);

		switch (menu) {
		case DEPOSIT:
			depositAmount = getDepositAmount();
			currentBalance = updateBalance(menu, currentBalance, depositAmount);
			break;
		case WITHDRAW:
			withdrawAmount = getWithdrawAmount();
			if (withdrawAmount > currentBalance) {
				printf("잔액이 부족합니다. 출금할 수 없습니다.\n");
			}
			else {
				currentBalance = updateBalance(menu, currentBalance, withdrawAmount);
			}
			break;
		case EXIT:
			return currentBalance;
		default:
			printf("잘못된 입력입니다.\n");
		}

		printCurrentBalance(currentBalance);
	
	} while (menu != EXIT);

	return currentBalance;
}

int getDepositAmount() {
	int amount;
	printf("입금할 금액을 입력하세요 : ");
	scanf("%d", &amount);
	return amount;
}

int getWithdrawAmount() {
	int amount;
	printf("출금할 금액을 입력하세요 : ");
	scanf("%d", &amount);
	return amount;
}

int updateBalance(int menu, int balance, int amount) {
	if (menu == DEPOSIT) {
		return balance + amount;
	}
	else if (menu == WITHDRAW) {
		return balance - amount;
	}
	else {
		return balance;
	}
}

void printCurrentBalance(int balance) {
	printf("현재 잔액 : %d원\n", balance);
}

void resultBalance(int balance) {
	printf("프로그램 종료. 최종 잔액 : %d원\n", balance);
}

void ArrayAccess() {
	int arr[5];
	int sum = 0;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}

	printf("배열 요소의 합: %d\n", sum);
}

void ArrayInit() {
	int arr1[5] = { 10, 20, 30, 40, 50 };
	int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr3[5] = { 11, 22 };
	int arr1Length, arr2Length, arr3Length, i;

	printf("arr1 크기: %d \n", sizeof(arr1));
	printf("arr2 크기: %d \n", sizeof(arr2));
	printf("arr3 크기: %d \n", sizeof(arr3));

	printf("\n");

	arr1Length = sizeof(arr1) / sizeof(int);
	arr2Length = sizeof(arr2) / sizeof(int);
	arr3Length = sizeof(arr3) / sizeof(int);

	printf("arr1 길이: %d \n", arr1Length);
	printf("arr2 길이: %d \n", arr2Length);
	printf("arr3 길이: %d \n", arr3Length);

	printf("\n");

	for (i = 0; i < arr1Length; i++) {
		printf("arr1[%d] = %d\n", i, arr1[i]);
	}

	printf("\n");

	for (i = 0; i < arr2Length; i++) {
		printf("arr2[%d] = %d\n", i, arr2[i]);
	}

	printf("\n");

	for (i = 0; i < arr3Length; i++) {
		printf("arr3[%d] = %d\n", i, arr3[i]);
	}

	printf("\n");
}

void ArrayString() {
	char str[] = "Good job!";

	printf("배열 str의 크기: %d \n", sizeof(str));
	printf("널 문자 문자형 출력: %c \n", str[9]);
	printf("널 문자 정수형 출력: %d \n", str[9]);

	str[8] = '~';
	printf("문자열 출력: %s \n", str);

	return 0;
}

void ReadArrayString() {
	char str[50];
	int idx = 0;

	printf("문자열 입력: ");
	scanf("%s", str);
	printf("입력 받은 문자열: %s \n", str);

	printf("문자 단위 출력 \n");

	while (str[idx] != '\0') {
		printf("%d %c\n", idx, str[idx]);
		idx++;
	}

	printf("\n");
}

void gradeScore() 
{
	int score[5];
	int studentCount;
	int i;

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &studentCount);

	for (i = 0; i < studentCount; i++) {
		printf("%d번째 점수 입력: ", i + 1);
		scanf("%d", &score[i]);
	}

	printf("\n--- 등급 결과 ---\n");

	for (i = 0; i < studentCount; i++) {
		printf("%d번째 학생 점수: %d -> ", i + 1, score[i]);

		if (score[i] >= 90) {
			printf("A\n");
		} 
		else if (score[i] >= 80) {
			printf("B\n");
		}
		else if (score[i] >= 70) {
			printf("C\n");
		}
		else if (score[i] >= 60) {
			printf("D\n");
		}
		else {
			printf("F\n");
		}
	}
}

void TwoDimArraySize() {
	char arr1[3][4];
	char arr2[7][9];
	int arr3[3][4];
	int arr4[7][9];

	printf("char 세로3, 가로4: %d \n", sizeof(arr1));
	printf("char 세로7, 가로9: %d \n", sizeof(arr2));
	printf("int 세로3, 가로4: %d \n", sizeof(arr3));
	printf("int 세로7, 가로9: %d \n", sizeof(arr4));
}

void print2DArray() {
	int arr[2][3];

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;

	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	printf("출력 \n");

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
}

void print2DArrayAddr()
{
	int arr[2][3];

	printf("2차원 배열의 주소 \n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%p ", &arr[i][j]);
		}

		printf("\n");
	}
}

void TwoDimArrayInit()
{
	int arr1[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	int arr2[2][3] = {
		{1},
		{4, 5}
	};

	int arr3[2][3] = { 1, 2, 3, 4 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr1[i][j]);
		};
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr2[i][j]);
		};
		printf("\n");
	}

	printf("\n");

	for(int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", arr3[i][j]);
		};
		printf("\n");
	}
}