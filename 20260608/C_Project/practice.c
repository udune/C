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

	// 입력된 비밀번호가 등록된 비밀번호와 일치할 때까지 반복
	while (password != input) {
		printf("비밀번호가 틀렸습니다.\n");
		printf("다시 입력하세요 : ");
		scanf("%d", &input);
	}

	// 비밀번호가 일치할 때 메시지를 출력
	printf("비밀번호가 일치합니다. 로그인 성공!\n");
}

void initUntilEqual() {
	int num1;
	int num2;

	do { // 사용자로부터 두 개의 숫자를 입력받음
		printf("두 개의 숫자를 입력하세요: ");
		scanf("%d %d", &num1, &num2);

		// 입력된 숫자가 일치하지 않는 경우 메시지를 출력하고 다시 입력받음
		if (num1 != num2) {
			printf("숫자가 일치하지 않습니다. 다시 입력하세요.\n");
		}
	} while (num1 != num2); // num1과 num2가 일치할 때까지 반복

	// num1과 num2가 일치할 때 메시지를 출력
	printf("숫자가 일치합니다. 프로그램을 종료합니다.\n");
}

void printEvenNumbers() {
	int num = 0;
	int total = 0;

	do { // 사용자로부터 숫자를 입력받음
		printf("숫자를 입력하세요 (0 입력 시 종료) : ");
		scanf("%d", &num);

		// 입력된 숫자가 짝수이고 0이 아닌 경우에만 총합에 더함
		if (num % 2 == 0 && num != 0) {
			total += num;
		}

	} while (num != 0); // num이 0이 아닌 동안 반복

	if (num == 0) { // num이 0일 경우
		printf("프로그램을 종료합니다.");
		return;
	}

	// 입력된 숫자가 0이 아닌 경우에만 총합을 출력
	printf("입력한 짝수의 총합은 %d입니다.", total);
}

void processVilla() {
	int villa[4][3]; // villa[0~3][0~2]
	int i;
	int j; 
	int sum;

	for (i = 0; i < 4; i++) { // 0, 1, 2, 3
		for (j = 0; j < 3; j++) { // 0, 1, 2
			// 1층 1호, 1층 2호, 1층 3호, 
			// 2층 1호, 2층 2호, 2층 3호, 
			// 3층 1호, 3층 2호, 3층 3호, 
			// 4층 1호, 4층 2호, 4층 3호
			printf("%d층 %d호 인구수: ", i + 1, j + 1);
			// villa[0][0], villa[0][1], villa[0][2], 
			// villa[1][0], villa[1][1], villa[1][2], 
			// villa[2][0], villa[2][1], villa[2][2], 
			// villa[3][0], villa[3][1], villa[3][2]
			scanf("%d", &villa[i][j]); 
		}
	}

	printf("\n");

	for (i = 0; i < 4; i++) { // 0, 1, 2, 3
		sum = 0; // sum = 0으로 초기화하여 각 층의 인구수를 계산할 때 이전 층의 인구수가 누적되지 않도록 함

		for (j = 0; j < 3; j++) { // 0, 1, 2
			// sum = sum + (villa[0][0] + villa[0][1] + villa[0][2])
			// sum = sum + (villa[1][0] + villa[1][1] + villa[1][2])
			// sum = sum + (villa[2][0] + villa[2][1] + villa[2][2])
			// sum = sum + (villa[3][0] + villa[3][1] + villa[3][2])
			sum += villa[i][j];
		}

		// 1층 인구수: (villa[0][0] + villa[0][1] + villa[0][2])
		// 2층 인구수: (villa[1][0] + villa[1][1] + villa[1][2])
		// 3층 인구수: (villa[2][0] + villa[2][1] + villa[2][2])
		// 4층 인구수: (villa[3][0] + villa[3][1] + villa[3][2])
		printf("%d층 인구수: %d\n", i + 1, sum);
	}
}

void processScore() {
	int score[4][2]; // score[0~3][0~1]
	int i;
	int j;
	int sum;
	int fail;
	float average;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d번 학생 %d과목 점수: ", i + 1, j + 1);
			scanf("%d", &score[i][j]);
		}
	}

	printf("\n");

	for (i = 0; i < 4; i++) { // 0, 1, 2, 3
		sum = 0;
		fail = 0;

		for (j = 0; j < 2; j++) { // 0, 1
			// sum = sum + (score[0][0] + score[0][1])
			// sum = sum + (score[1][0] + score[1][1])
			// sum = sum + (score[2][0] + score[2][1])
			// sum = sum + (score[3][0] + score[3][1])
			sum += score[i][j]; 
			// score[0][0] < 50, score[0][1] < 50, 
			// score[1][0] < 50, score[1][1] < 50, 
			// score[2][0] < 50, score[2][1] < 50, 
			// score[3][0] < 50, score[3][1] < 50
			if (score[i][j] < 50) {
				fail = 1;
			}
		}

		// 1 평균 : (score[0][0] + score[0][1]) / 2.0
		// 2 평균 : (score[1][0] + score[1][1]) / 2.0
		// 3 평균 : (score[2][0] + score[2][1]) / 2.0
		// 4 평균 : (score[3][0] + score[3][1]) / 2.0
		average = sum / 2.0f; // 평균 계산

		printf("%d번 학생 총점: %d 평균 : %.1f ", i + 1, sum, average);

		// 평균이 60 이상이고 fail이 0이면 합격, 그렇지 않으면 불합격
		if (average >= 60 && fail == 0) {
			printf("합격\n");
		}
		else {
			printf("불합격\n");
		}
	}
}

void ArrayStringInit() {
	// 문자열 초기화
	char arr1[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char arr2[6] = { 'H', 'e' };
	char arr3[6] = "Hello";
	char arr4[] = "Hello Everyone!";

	int arr1Length;
	int arr2Length;
	int arr3Length;
	int arr4Length;

	arr1Length = sizeof(arr1) / sizeof(char); // sizeof(arr1) = 6, sizeof(char) = 1, arr1Length = 6
	arr2Length = sizeof(arr2) / sizeof(char); // sizeof(arr2) = 6, sizeof(char) = 1, arr2Length = 6 (arr2는 'H', 'e', '\0', '\0', '\0', '\0'로 초기화됨)
	arr3Length = sizeof(arr3) / sizeof(char); // sizeof(arr3) = 6, sizeof(char) = 1, arr3Length = 6 (arr3는 'H', 'e', 'l', 'l', 'o', '\0'로 초기화됨)
	arr4Length = sizeof(arr4) / sizeof(char); // sizeof(arr4) = 14, sizeof(char) = 1, arr4Length = 14 (arr4는 'H', 'e', 'l', 'l', 'o', ' ', 'E', 'v', 'e', 'r', 'y', 'o', 'n', '\0'로 초기화됨)

	printf("\narr1 크기: %d \n", sizeof(arr1));
	for (int i = 0; i < arr1Length; i++) {
		printf("arr1[%d] %p : %c : %d \n", i, &arr1[i], arr1[i], arr1[i]);
	}

	printf("\narr2 크기: %d \n", sizeof(arr2));
	for (int i = 0; i < arr2Length; i++) {
		printf("arr2[%d] %p : %c : %d \n", i, &arr2[i], arr2[i], arr2[i]);
	}
	printf("arr2 string %s \n", arr2); // arr2는 "He"로 출력됨 (arr2[0] = 'H', arr2[1] = 'e', arr2[2] = '\0'로 초기화됨))

	printf("\narr3 크기: %d \n", sizeof(arr3));
	for (int i = 0; i < arr3Length; i++) {
		printf("arr3[%d] %p : %c : %d \n", i, &arr3[i], arr3[i], arr3[i]);
	}

	printf("\narr4 크기: %d \n", sizeof(arr4));
	for (int i = 0; i < arr4Length; i++) {
		printf("arr4[%d] %p : %c : %d \n", i, &arr4[i], arr4[i], arr4[i]);
	}

	arr4[14] = '~'; // arr4[14]는 arr4의 마지막 요소인 '\0'이므로, arr4[14]에 '~'를 할당하면 문자열이 제대로 종료되지 않음
	printf("arr4 %s \n", arr4); // arr4는 "Hello Everyone~"이 되어 출력됨


}

void StringCopy() {
	char src[20] = "Hello";
	char dest[20];

	printf("src %s\n", src);
	strcpy(src, "Hello everyone");
	strcpy(dest, src);
	printf("src %s\n", src);
	printf("dest %s\n", dest);
}

void StringSwap() {
	char str[100]; // 입력받은 문자열을 저장할 배열
	char rev[100]; // 문자열을 뒤집어서 저장할 배열
	int len;
	int i;

	printf("문자열 입력 : ");

	// korea로 입력하면 str 배열에는 
	// 'k', 'o', 'r', 'e', 'a', '\0'이 저장됨
	scanf("%s", str);

	// korea로 입력하면 len은 5가 됨 (문자열의 길이)
	len = strlen(str);

	// korea로 입력하면 i = 0, 1, 2, 3, 4가 됨 (문자열의 인덱스)
	for (i = 0; i < len; i++) {
		// korea로 입력하면 rev 배열에는
		// rev[0] = str[5 - 1 - 0] = str[4] = 'a'
		// rev[1] = str[5 - 1 - 1] = str[3] = 'e'
		// rev[2] = str[5 - 1 - 2] = str[2] = 'r'
		// rev[3] = str[5 - 1 - 3] = str[1] = 'o'
		// rev[4] = str[5 - 1 - 4] = str[0] = 'k'
		rev[i] = str[len - 1 - i];
	}

	// korea로 입력하면 rev 배열에는 'a', 'e', 'r', 'o', 'k'이 저장됨
	// rev[5]는 rev 배열의 마지막 요소이므로, rev[5]에 null 문자('\0')를 추가하여 문자열이 제대로 종료되도록 함
	rev[len] = '\0';

	printf("입력한 문자열 : %s\n", str);
	printf("뒤집은 문자열 : %s\n", rev);
}

void CharFunction() {
	int ch;

	while (true) {
		ch = getChar();
		if (ch == 'q') {
			break;
		}

		printChar(ch);
	}
}

void CharFunc2() {
	int ch;

	while (true) {
		ch = _getch();
		putchar(ch);
		printf("\n");
		if (ch == 'q') {
			break;
		}
	}
}

void StringFunc() {
	char str[100];

	printf("문자열 입력 : \n");
	gets(str);

	printf("입력한 문장 : \n");
	puts(str);
}

void processChar() {
	char c;

	printf("문자 하나 입력: ");

	c = getchar();

	if (isalpha(c)) {
		printf("영문자입니다.\n");
	}

	if (isupper(c)) {
		printf("대문자입니다.\n");
	}

	if (islower(c)) {
		printf("소문자입니다.\n");
	}

	if (isdigit(c)) {
		printf("숫자입니다.\n");
	}

	if (isalnum(c)) {
		printf("영문자 또는 숫자입니다.\n");
	}

	if (isxdigit(c)) {
		printf("16진수 문자입니다.\n");
	}

	if (isspace(c)) {
		printf("공백 문자입니다.\n");
	}

	if (ispunct(c)) {
		printf("구두점 문자입니다.\n");
	}

	if (isprint(c)) {
		printf("출력 가능한 문자입니다.\n");
	}

	if (iscntrl(c)) {
		printf("제어 문자입니다.\n");
	}

	if (isascii(c)) {
		printf("ASCII 범위 문자입니다.\n");
	}

	printf("대문자 변환: %c\n", toupper(c));
	printf("소문자 변환: %c\n", tolower(c));
}

void stringPractice() {
	char s1[50] = "Hello";
	char s2[50] = "World";
	char temp[50];

	// strlen 함수는 s1 문자열의 길이 계산. Hello의 길이 5를 반환
	printf("strlen(s1) : %zu\n", strlen(s1));

	// strcpy 함수는 s1문자열을 temp 배열에 복사. Hello를 반환.
	strcpy(temp, s1);
	printf("strcpy(temp, s1) : %s\n", temp);

	// strcat 함수는 s1 문자열과 s2 문자열을 연결. HelloWorld를 반환.
	strcat(s1, s2);
	printf("strcat(s1, s2) : %s\n", s1);

	// strcmp 함수는 s1 문자열과 s2 문자열을 비교. 같으면 0. 다르면 양수 또는 음수 반환. HelloWorld와 World는 다르므로 양수 또는 음수 반환.
	printf("strcmp(s1, s2) : %d\n", strcmp(s1, s2));

	// strncpy 함수는 s1 문자열의 처음 3글자를 temp 배열에 복사. ABC를 반환. 
	// 복사할 글자 수를 지정할 수 있지만, 지정한 글자 수만큼 복사한 후에 문자열이 제대로 종료되지 않을 수 있으므로, 복사한 후에 널 문자를 추가하여 문자열이 제대로 종료되도록 해야 함.
	strncpy(temp, "ABCDE", 3);
	temp[3] = '\0'; // 널 문자 추가
	printf("strncpy: %s\n", temp);

	// strncat 함수는 s1 문자열과 "XYZ" 문자열을 연결하되, "XYZ" 문자열의 처음 2글자만 연결. 
	// ABCXY를 반환.
	strncat(temp, "XYZ", 2);
	printf("strncat: %s\n", temp);

	// strncmp 함수는 "ABC" 문자열과 "ABD" 문자열을 처음 3글자까지 비교. 같으면 0. 다르면 양수 또는 음수 반환. ABC와 ABD는 다르므로 양수 또는 음수 반환.
	printf("strncmp(\"ABC\", \"ABD\", 3) : %d\n", strncmp("ABC", "ABD", 3));

	// strchr 함수는 s1 문자열에서 'W' 문자를 찾음. 
	// 'W'가 포함된 문자열 "World"를 반환.
	char* p = strchr(s1, 'W');
	if (p != NULL) {
		printf("strchr: %s\n", p);
	}
	
	// strstr 함수는 s1 문자열에서 "World" 문자열을 찾음.
	// "World"가 포함된 문자열 "World"를 반환.
	char* q = strstr(s1, "World");
	if (q != NULL) {
		printf("strstr: %s\n", q);
	}
}

void passwordRegister() {
	char pw1[100];
	char pw2[100];

	int i;
	int upper;
	int lower;
	int digit;
	int special;

	bool upperFlag;
	bool lowerFlag;
	bool digitFlag;
	bool specialFlag;

	while (true) {
		printf("등록할 비밀번호 입력 : ");
		scanf("%s", pw1);

		if (strlen(pw1) < 10) {
			printf("비밀번호는 10자 이상이어야 합니다.\n");
			continue;
		}

		upper = 0;
		lower = 0;
		digit = 0;
		special = 0;

		upperFlag = false;
		lowerFlag = false;
		digitFlag = false;
		specialFlag = false;

		for (i = 0; pw1[i] != '\0'; i++) {
			if (isupper(pw1[i])) {
				upper = 1;
			}
			else if (islower(pw1[i])) {
				lower = 1;
			}
			else if (isdigit(pw1[i])) {
				digit = 1;
			}
			else {
				special = 1;
			}

			if (isupper(pw1[i])) {
				upperFlag = true;
			}
			else if (islower(pw1[i])) {
				lowerFlag = true;
			}
			else if (isdigit(pw1[i])) {
				digitFlag = true;
			}
			else {
				specialFlag = true;
			}
		}

		if (!(upper && lower && digit && special)) {
			printf("비밀번호는 대문자, 소문자, 숫자, 특수문자를 모두 포함해야 합니다.\n");
			continue;
		}

		if (!(upperFlag && lowerFlag && digitFlag && specialFlag)) {
			printf("비밀번호는 대문자, 소문자, 숫자, 특수문자를 모두 포함해야 합니다.\n");
			continue;
		}

		printf("비밀번호 확인 입력 : ");
		scanf("%s", pw2);

		while (true) {
			if (strcmp(pw1, pw2) == 0) {
				printf("비밀번호가 등록되었습니다.\n");
				return;
			}
			else {
				printf("비밀번호가 일치하지 않습니다. 다시 시도하세요.\n");
				printf("비밀번호 확인 입력 : ");
				scanf("%s", pw2);
			}
		}
	}
}

void pointerInit() {
	// 포인터는 변수의 주소를 저장하는 변수입니다. 
	// 포인터를 사용하면 변수의 주소를 통해 변수에 접근할 수 있습니다.
	int num = 10;

	// ptr은 int형 포인터 변수입니다. 
	// ptr은 num 변수의 주소를 저장합니다.
	int* ptr = &num;

	// num이 가리키는 주소값을 출력합니다.
	printf("num: %d\n", &num);

	// ptr이 가리키는 주소값을 출력합니다.
	printf("*ptr: %d\n\n", &ptr);

	// &num == &ptr이므로, num과 ptr이 가리키는 주소값은 같습니다.

	// ptr 변수에 저장된 주소값을 출력합니다.
	printf("ptr: %p\n", ptr);

	// num 변수의 값을 변경합니다.
	printf("num: %d\n", num);

	// ptr이 가리키는 주소에 저장된 값을 출력합니다.
	printf("*ptr: %d\n\n", *ptr);

	num = 3;
	// num 변수의 값을 변경하면, ptr이 가리키는 주소에 저장된 값도 변경됩니다.
	printf("num: %d\n", num);
	//	ptr이 가리키는 주소에 저장된 값을 출력합니다.
	printf("*ptr: %d\n\n", *ptr);

	*ptr = 11;
	// ptr이 가리키는 주소에 저장된 값을 변경하면, num 변수의 값도 변경됩니다.
	printf("num: %d\n", num);
	// ptr이 가리키는 주소에 저장된 값을 출력합니다.
	printf("*ptr: %d\n\n", *ptr);
}

void getPointerValue() {
	int num1 = 10;
	int num2 = 20;
	int* ptr = &num1;

	*ptr += 40;

	ptr = &num2;
	*ptr += 40;

	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);
}

void pointerArrayType() {
	int array[3] = { 10, 20, 30 };
	int* ptr = array;

	printf("&array[0] : %p\n", &array[0]);
	printf("ptr : %p\n", ptr);

	printf("&array[1] : %p\n", &array[1]);
	printf("ptr + 1 : %p\n", ptr + 1);

	printf("&array[2] : %p\n", &array[2]);
	printf("ptr + 2 : %p\n", ptr + 2);

	printf("array[0] : %d\n", array[0]);
	printf("array[1] : %d\n", array[1]);
	printf("array[2] : %d\n", array[2]);

	printf("*ptr : %d\n", *ptr);
	printf("*(ptr + 1) : %d\n", *(ptr + 1));
	printf("*(ptr + 2) : %d\n", *(ptr + 2));
}

void pointerArrayType1() {
	int array[3] = { 10, 20, 30 };
	int* ptr = array;

	printf("%d %d \n", ptr[0], array[0]);
	printf("%d %d \n", ptr[1], array[1]);
	printf("%d %d \n", ptr[2], array[2]);

	printf("%d %d \n", *ptr, array[0]);
	printf("%d %d \n", *(ptr + 1), array[1]);
	printf("%d %d \n", *(ptr + 2), array[2]);
}

void pointerOffset() {
	int arr[5] = { 11, 22, 33, 44, 55 };
	int* ptr = arr;

	printf("포인터 ptr 가리키는 값 : %d\n", *ptr);
	ptr = ptr + 2; // ptr이 arr[2]를 가리키도록 이동

	printf("포인터 ptr 가리키는 값 : %d\n", *ptr);
	ptr = ptr - 1; // ptr이 arr[1]을 가리키도록 이동

	printf("포인터 ptr 가리키는 값 : %d\n", *ptr);
}

void pointerArraySum() {
	int arr[5];
	int* ptr = arr;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		printf("%d번째 값: ", i + 1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		sum += *(ptr + i);
	}

	printf("배열의 총합: %d\n", sum);
}

void pointerArrayMaxFind() {
	int arr[5];
	int* ptr = arr;
	int max;

	for (int i = 0; i < 5; i++) {
		printf("%d번째 값: ", i + 1);
		scanf("%d", (ptr + i));
	}

	max = *ptr; // max를 arr[0]의 값으로 초기화

	for (int i = 1; i < 5; i++) {
		if (*(ptr + i) > max) {
			max = *(ptr + i); // max보다 큰 값이 있으면 max를 업데이트
		}
	}

	printf("배열의 최대값: %d\n", max);
}

void pointerArray() {
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;

	int* arr[3] = { &num1, &num2, &num3 };

	printf("&num1 = %p arr[0] = %p\n", &num1, arr[0]);
	printf("&num2 = %p arr[1] = %p\n", &num2, arr[1]);
	printf("&num3 = %p arr[2] = %p\n", &num3, arr[2]);

	printf("*arr[0] = %d\n", *arr[0]);
	printf("*arr[1] = %d\n", *arr[1]);
	printf("*arr[2] = %d\n", *arr[2]);
}

void mainSwapNum() {
	int num1 = 50;
	int num2 = 30;

	printf("swapNum before : num1 = %d, num2 = %d \n", num1, num2);
	printf("&num1 = %p, &num2 = %p \n", &num1, &num2);

	swapNum(&num1, &num2);
	printf("swapNum after : num1 = %d, num2 = %d \n", num1, num2);
}

void swapNum(int* pnum1, int* pnum2)
{
	int temp;
	printf("%s &pnum1 = %p, &pnum2 = %p \n", __func__, &pnum1, &pnum2);
	printf("pnum1 = %p, pnum2 = %p \n", pnum1, pnum2);
	printf("*pnum1 = %d, *pnum2 = %d \n", *pnum1, *pnum2);

	temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;

	printf("*pnum1 = %d, *pnum2 = %d \n", *pnum1, *pnum2);
}

void mainPrintArray() {
	int numbers[] = { 10, 20, 30, 40, 50 };

	printf("numbers = %p \n", numbers);
	printArray(numbers, 5);
}

void printArray(int* arr, int size) {
	printf("arr = %p \n", arr);

	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
}

void mainPrintArray2() {
	int numbers[] = { 10, 20, 30, 40, 50 };

	printf("numbers = %p \n", numbers);
	printArray2(numbers, 5);

	for (int i = 0; i < 5; i++) {
		printf("numbers[%d] = %d \n", i, numbers[i]);
	}
}

void printArray2(int arr[], int size) {
	printf("arr = %p \n", arr);

	for (int i = 0; i < size; i++) {
		printf("arr[%d] = %d \n", i, arr[i]);
		printf("arr+%d : %p \n\n", i, *(arr + i));
	}

	arr[0] = 11;
	*(arr + 1) = 22;
}

void mainScoreCalc() {
	int score[5];
	int sum = 0;
	double average = 0;

	printf("5명의 점수를 입력하세요: \n");
	for (int i = 0; i < 5; i++) {
		printf("%d번째 학생 점수: ", i + 1);	
		scanf("%d", &score[i]);

	}

	scoreCalc(score, &sum, &average);

	printf("\n합계 : %d\n", sum);
	printf("평균 : %.2f\n", average);
}

void Arr2DAccessType(void)
{
	int arr[3][2] = { {1, 2}, {3, 4}, {5, 6} };

	// 초기 값 확인 (arr[2][1] == 6)
	printf("값: %d\n\n", arr[2][1]);

	// [1] 일반적인 2차원 배열 표기
	arr[2][1] = 7;
	printf("[1] arr[2][1] = 7 수행 후: %d\n", arr[2][1]);

	// [2] 배열 이름을 포인터처럼 해석
	// arr + 2  -> 3번째 행 주소
	// *(arr+2) -> 3번째 행의 시작 주소(int*)
	// (*(arr+2))[1] -> 3번째 행의 2번째 열
	(*(arr + 2))[1] = 70;
	printf("[2] (*(arr + 2))[1] = 70 수행 후: %d\n", arr[2][1]);

	// [3] arr[2]는 3번째 행의 시작 주소(int*)로 decay
	// *(arr[2] + 1) == arr[2][1]
	*(arr[2] + 1) = 700;
	printf("[3] *(arr[2] + 1) = 700 수행 후: %d\n", arr[2][1]);

	// [4] 순수 포인터 형태
	// *(*(arr + 2) + 1) == arr[2][1]
	*(*(arr + 2) + 1) = 777;
	printf("[4] *(*(arr + 2) + 1) = 777 수행 후: %d\n\n", arr[2][1]);

	// 네 가지 표현의 실제 주소가 같은지 비교
	printf("--- 네 가지 표현의 실제 메모리 주소 비교 ---\n");
	printf("&arr[2][1]           의 주소: %p\n", (void*)&arr[2][1]);
	printf("(*(arr + 2)) + 1     의 주소: %p\n", (void*)((*(arr + 2)) + 1));
	printf("arr[2] + 1           의 주소: %p\n", (void*)(arr[2] + 1));
	printf("*(arr + 2) + 1       의 주소: %p\n", (void*)(*(arr + 2) + 1));
}

void scoreCalc(int* score, int* sum, double* average)
{
	for (int i = 0; i < 5; i++) {
		*sum += *(score + i);
	}

	*average = (double)*sum / 5.0;
}