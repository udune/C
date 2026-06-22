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

void scoreCalc(int* score, int* sum, double* average) {
	for (int i = 0; i < 5; i++) {
		*sum += *(score + i);
	}
	
	*average = (double) *sum / 5.0;
}

void doublePointer() {
	// 이중 포인터는 포인터를 가리키는 포인터입니다.
	int num = 10;

	// ptr은 int형 포인터 변수입니다. ptr은 num 변수의 주소를 저장합니다.
	int* ptr = &num;

	// dptr은 int형 이중 포인터 변수입니다. dptr은 ptr 변수의 주소를 저장합니다.
	int** dptr = &ptr;

	printf("&num = %p\n", &num); // num 변수의 주소값을 출력합니다.
	printf("ptr = %p\n", ptr); // ptr이 가리키는 주소값을 출력합니다.
	printf("&ptr = %p\n", &ptr); // ptr 변수의 주소값을 출력합니다. &ptr == &dptr이므로, ptr과 dptr이 가리키는 주소값은 같습니다.
	printf("dptr = %p\n", dptr); // dptr이 가리키는 주소값을 출력합니다. dptr == &ptr이므로, dptr이 가리키는 주소는 ptr의 주소(&ptr)와 같습니다.
	printf("&dptr = %p\n", &dptr); // dptr 변수의 주소값을 출력합니다. &ptr == &dptr이므로, ptr과 dptr이 가리키는 주소값은 같습니다.

	// num, *ptr, **dptr의 값을 출력합니다.
	printf("1. num = %d\n, *ptr = %d, **dptr = %d\n", num, *ptr, **dptr);

	// ptr을 통해 num의 값을 변경합니다.
	*ptr = 20;
	printf("2. num = %d\n, *ptr = %d, **dptr = %d\n", num, *ptr, **dptr);

	// dptr을 통해 num의 값을 변경합니다.
	**dptr = 30;
	printf("3. num = %d\n, *ptr = %d, **dptr = %d\n", num, *ptr, **dptr);
}

void SwapPointer() {
	int num1 = 10;
	int num2 = 20;

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

	// ptr1, ptr2가 가진 복사된 주소값을 복사해서 p1, p2에 넣는다.
	// 함수 안에서 p1과 p2를 바꿔도 복사본끼리의 교환일 뿐 원본 ptr1, ptr2는 그대로다.
	SwapPtr(ptr1, ptr2);

	printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
}

void SwapDPointer() {
	int num1 = 10;
	int num2 = 20;

	// ptr1과 ptr2는 num1과 num2의 주소를 저장하는 포인터입니다.
	int* ptr1 = &num1;
	int* ptr2 = &num2;

	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

	// ptr1, ptr2가 사는 주소를 넘긴다. 
	// p1과 p2는 포인터를 직접 가리키게 되고 
	// *p1, *p2로 원본 포인터의 내용을 진짜로 바꿀수 있다.
	SwapDPtr(&ptr1, &ptr2);

	printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
}

// SwapPtr 함수는 포인터를 사용하여 
// 포인터의 값을 전달받아 포인터 자체를 교환하는 함수입니다.
void SwapPtr(int* p1, int* p2) {
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}

// SwapDPtr 함수는 이중 포인터를 사용하여 
// 포인터의 주소를 전달받아 포인터 자체를 교환하는 함수입니다.
void SwapDPtr(int** p1, int** p2) {
	int* temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void SwapChar()
{
	int n = 3;

	char** str;

	str = (char**)malloc(n * sizeof(char*));

	// str[i]와 *(str+i)는 같은 주소값을 가리킴

	// &str은 str 변수 자신이 사는 주소값을 가리킴
	// str은 포인터 배열의 시작 주소값을 가리킴(첫번째 malloc 결과)
	// str + 1, str + 2는 배열에서 한 칸씩 건너뛴 주소. str은 char*를 가리키므로 한 칸이 sizeof(char*)이다.
	// str[i]는 각 문자열 버퍼의 주소
	// *str은 str[0]이 가리키는 문자열 버퍼의 주소
	// *(str + 1)은 str[1]이 가리키는 문자열 버퍼의 주소
	// *(str + 2)는 str[2]이 가리키는 문자열 버퍼의 주소
	printf("&str : %p\n", &str);
	printf("str : %p\n", str);
	printf("str + 1 : %p\n", str + 1);
	printf("str + 2 : %p\n", str + 2);

	for (int i = 0; i < n; i++) {
		str[i] = (char*)malloc(100 * sizeof(char));
		printf("str[%d] : %p\n", i, str[i]);
	}

	printf("*str : %p\n", *str);
	printf("*(str + 1) : %p\n", *(str + 1));
	printf("*(str + 2) : %p\n", *(str + 2));

	strcpy(str[0], "apple");
	strcpy(str[1], "banana");
	strcpy(str[2], "cherry");

	for (int i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}

	freeSwapCharMemory(str, n);
	str = NULL;
}

static void freeSwapCharMemory(char** str, int n) {
	if (str == NULL) {
		return;
	}

	for (int i = 0; i < n; i++) {
		free(str[i]);
	}
}

void DoublePointer()
{
	char base_str[100];
	char* str_ptr = base_str;

	printf("문자열 입력 : ");
	if (fgets(str_ptr, sizeof(base_str), stdin) == NULL) {
		return;
	}
	str_ptr[strcspn(str_ptr, "\n")] = '\0';

	printf("변경 전 str_ptr이 가리키는 문자열 : ");
	puts(str_ptr);

	updateString(&str_ptr);

	printf("변경 후 str_ptr이 가리키는 문자열 : ");
	puts(str_ptr);
}

void updateString(char** dest_ptr)
{
	char input_buffer[100];

	printf("변경할 문자열 입력 : ");
	if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
		return;
	}
	input_buffer[strcspn(input_buffer, "\n")] = '\0';

	strcpy(*dest_ptr, input_buffer);
}

void Arr2DNameAndArrPtr(void)
{
	int arr1[2][2] = {
		{1, 2}, {3, 4}
	};
	int arr2[3][2] = {
		{1, 2}, {3, 4}, {5, 6}
	};
	int arr3[4][2] = {
		{1, 2}, {3, 4}, {5, 6}, {7, 8}
	};

	// 2차원 배열의 이름은 배열의 첫 번째 요소를 가리키는 포인터입니다.
	int (*ptr)[2];
	int i;

	ptr = arr1;
	printf("** case ptr = arr1 **\n");
	// ptr이 arr1의 첫 번째 요소인 arr1[0]을 가리키므로, ptr[i]는 arr1[i]를 가리킴
	for (i = 0; i < 2; i++) {
		printf("%d %d\n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr2;
	printf("** case ptr = arr2 **\n");
	// ptr이 arr2의 첫 번째 요소인 arr2[0]을 가리키므로, ptr[i]는 arr2[i]를 가리킴
	for (i = 0; i < 3; i++) {
		printf("%d %d\n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr3;
	printf("** case ptr = arr3 **\n");
	// ptr이 arr3의 첫 번째 요소인 arr3[0]을 가리키므로, ptr[i]는 arr3[i]를 가리킴
	for (i = 0; i < 4; i++) {
		printf("%d %d\n", ptr[i][0], ptr[i][1]);
	}
}

void ArrPtrAndPtrArr() {
	int num1 = 10;
	int num2 = 20;
	int num3 = 30; 
	int num4 = 40;
	int arr2d[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	
	// 포인터 배열 : 포인터들이 담긴 배열
	// Parr는 칸이 4개인 배열이고 각 칸이 int*(포인터)이다.
	// 각 칸은 독립적으로 서로 다른 변수를 가리킬 수 있다.
	// Parr[0] ==> num1 = 10
	// Parr[1] ==> num2 = 20
	// Parr[2] ==> num3 = 30
	// Parr[3] ==> num4 = 40
	// ... Parr[i] = &num(i+1)
	//	
	// *Parr[0] => 10
	// *Parr[1] => 20
	// *Parr[2] => 30
	// *Parr[3] => 40
	int* Parr[4] = { &num1, &num2, &num3, &num4 };

	// 배열 포인터 : 배열 하나를 가리키는 포인터
	// arrP+1이 &arr2d[1][0]과 같게 찍힌다.
	// *arrP[0] = *(arrP[0]) = *(arr2d[0]) = arr2d[0][0] = 1 -> **arrP
	// *arrP[1] = *(arrP[1]) = *(arr2d[1]) = arr2d[1][0] = 5 -> *(*(arrP+1))
	int (*arrP)[4] = arr2d;
	int (*ptr)[4];
	int i, j;

	printf("num1: %p \n", (void*)&num1);
	printf("Parr[0]: %p \n", (void*)Parr[0]);
	printf("num2: %p \n", (void*)&num2);
	printf("Parr[1]: %p \n", (void*)Parr[1]);
	printf("num3: %p \n", (void*)&num3);
	printf("Parr[2]: %p \n", (void*)Parr[2]);
	printf("num4: %p \n", (void*)&num4);
	printf("Parr[3]: %p \n", (void*)Parr[3]);
	printf("Parr: %p \n", (void*)Parr);

	printf("arr2d[0][0]: %p \n", (void*)&arr2d[0][0]);
	printf("arrP: %p \n", (void*)arrP);
	printf("arr2d[1][0]: %p \n", (void*)&arr2d[1][0]);
	printf("arrP+1: %p \n", (void*)(arrP + 1));

	printf("**arrP: %d *arrP[0] = %d\n", **arrP, *arrP[0]);
	printf("*(*(arrP+1)) : %d *arrP[1] : %d\n", *(*(arrP + 1)), *arrP[1]);
	printf("*Parr[0]: %d *Parr[1]:%d *Parr[2]:%d *Parr[3]:%d \n",
		*Parr[0], *Parr[1], *Parr[2], *Parr[3]);

	ptr = arr2d;
	printf("** case ptr = arr2d **\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			printf("arrP[%d][%d] : %d ", i, j, ptr[i][j]);
		}
		printf("\n");
	}
}

void StudentInfo(void)
{
	struct Student person1;
	struct Student person2;

	strcpy(person1.name, "김현성");
	person1.studen_id = 20260001;
	strcpy(person1.phone_number, "010-1122-3042");

	printf("이름 입력 : ");
	scanf("%s", person2.name);
	printf("학번 입력 : ");
	scanf("%d", &(person2.studen_id));
	printf("전화번호 입력 : ");
	scanf("%s", person2.phone_number);

	printf("이름 : %s \n", person1.name);
	printf("학번 : %d \n", person1.studen_id);
	printf("전화번호 : %s \n", person1.phone_number);

	printf("이름 : %s \n", person2.name);
	printf("학번 : %d \n", person2.studen_id);
	printf("전화번호 : %s \n", person2.phone_number);
}

void BookInfo(void)
{
	struct Book library[3] = {
		{"C언어 기초", "홍길동", 25000},
		{"파이썬 기초", "이영희", 22000},
		{"자바 알고리즘", "김철수", 30000}
	};

	library[1].price = 24000;
	strcpy(library[1].author, "이영수");

	printf("============== 도서 목록 ==============\n");
	for (int i = 0; i < 3; i++)
	{
		printf("책 제목 : %s\n", library[i].title);
		printf("저  자 : %s\n", library[i].author);
		printf("가  격 : %d원\n", library[i].price);
		printf("--------------------------------------\n");
	}
}

void AnalyzeMart(void)
{
	// 1. 매크로 상수를 사용하여 크기가 3인 구조체 배열 2개 선언
	struct Product martA[MAX_PRODUCTS];
	struct Product martB[MAX_PRODUCTS];

	// 변수 선언 (총합 및 최고가 저장용)
	int sumA = 0;
	int sumB = 0;
	int maxPriceA = 0;
	int maxPriceB = 0;

	printf("--- A마트 상품 %d개 입력 (상품명 가격) ---\n", MAX_PRODUCTS);
	for (int i = 0; i < MAX_PRODUCTS; i++) {
		printf("A마트 상품 %d: ", i + 1);
		scanf("%s %d", martA[i].name, &martA[i].price);

		// 입력과 동시에 총합 및 최고가 누적 구하기
		sumA += martA[i].price;
		if (martA[i].price > maxPriceA) {
			maxPriceA = martA[i].price;
		}
	}

	printf("\n--- B마트 상품 %d개 입력 (상품명 가격) ---\n", MAX_PRODUCTS);
	for (int i = 0; i < MAX_PRODUCTS; i++) {
		printf("B마트 상품 %d: ", i + 1);
		scanf("%s %d", martB[i].name, &martB[i].price);

		// 입력과 동시에 총합 및 최고가 누적 구하기
		sumB += martB[i].price;
		if (martB[i].price > maxPriceB) {
			maxPriceB = martB[i].price;
		}
	}

	double avgA = (double)sumA / MAX_PRODUCTS;
	double avgB = (double)sumB / MAX_PRODUCTS;

	printf("\n=== 마트별 가격 분석 결과 ===\n");
	printf("A마트 상품 평균가: %.1f원\n", avgA);
	printf("B마트 상품 평균가: %.1f원\n", avgB);
	printf("--------------------------------------------\n");

	// 평균 가격이 더 낮은(우세한) 마트 판별 및 해당 마트의 최고가 출력
	if (avgA < avgB) {
		printf("평균가가 더 저렴한 우세 마트: A마트\n");
		printf("A마트의 최고가 상품 가격: %d원\n", maxPriceA);
	}
	else if (avgB < avgA) {
		printf("평균가가 더 저렴한 우세 마트: B마트\n");
		printf("B마트의 최고가 상품 가격: %d원\n", maxPriceB);
	}
	else {
		printf("★ 두 마트의 평균가가 같습니다.\n");
	}
	printf("============================================\n");
}

void showStudentInfo(Person person)
{
	printf("등록한 학생 정보\n");
	printf("name : %s\n", person.name);
	printf("phone : %s\n", person.phone);
	printf("age : %d\n", person.age);
}

Person readStudentInfo(void)
{
	Person student;
	printf("학생 정보를 입력하세요.\n");
	printf("name : ");
	scanf("%s", student.name);
	printf("phone : ");
	scanf("%s", student.phone);
	printf("age : ");
	scanf("%d", &student.age);

	return student;
}

void studentStructPractice(void)
{
	Person student = readStudentInfo();
	showStudentInfo(student);
}

void print_position(const Position* ptr) {
	printf("현재 위치 -> x: %d, y: %d\n", ptr->xpos, ptr->ypos);
}

void move_position(Position* ptr, int x_delta, int y_delta) {
	ptr->xpos += x_delta;
	ptr->ypos += y_delta;
}

void TestStructPointer(void)
{
	Position current_pos = { 10, 20 };
	Position *pcur_pos = &current_pos;
	int x_pos, y_pos;
	printf("--- 초기 상태 ---\n");
	print_position(&current_pos);

	printf("\n--증감(x y) 위치입력: ");
	if (scanf("%d %d", &x_pos, &y_pos) != 2) {
		return;
	}

	move_position(pcur_pos, x_pos, y_pos);

	printf("\n--- 이동 후 상태 ---\n");
	print_position(pcur_pos);
}

void StructMemberPointer(void)
{
	char name[10] = "Kim";

	Student s1, s2;

	s1.name = name;
	s2.name = name; // 같은 데이터를 공유

	printf("s1.name : %s\n", s1.name);
	printf("s2.name : %s\n", s2.name);
}

void StructPointerMemberExample(void)
{
	User s1 = { "Kim", NULL };
	User s2 = { "Lee", NULL };

	s1.next = &s2; // s1이 s2를 가리킴

	printf("현재 User : %s\n", s1.name);
	printf("다음 User : %s\n", s1.next->name);
}

// 고객의 자산을 출력하는 함수
void printCustomerInfo(Customer* c_ptr) {
	printf("--- 고객 정보 조회 ---\n");
	printf("고객 이름: %s\n", c_ptr->name);

	// 포인터 멤버를 통해 계좌 정보에 접근할 때 -> 연산자를 연속으로 사용합니다.
	if (c_ptr->my_account != NULL) {
		printf("연계 계좌: %s\n", c_ptr->my_account->account_num);
		printf("현재 잔액: %d원\n", c_ptr->my_account->balance);
	}
	else {
		printf("개설된 계좌가 없습니다.\n");
	}
	printf("---------------------\n\n");
}

void testBankSystem(void) {
	// 1. 실제 계좌 데이터 생성 (메모리 확보)
	Account acc1 = { "110-123-4567", 50000 }; // 잔액 50,000원
	Account acc2 = { "110-987-6543", 120000 }; // 잔액 120,000원

	// 2. 고객 데이터 생성 (초기에는 계좌 주소를 NULL로 설정)
	Customer c1 = { "홍길동", NULL };
	Customer c2 = { "이영희", NULL };

	char name[20];
	int deposit;

	// 3. 은행 연계 작업: 고객 구조체 내부 포인터 멤버에 계좌 구조체의 주소(&) 대입
	c1.my_account = &acc1; // 홍길동 고객에게 acc1 계좌 연결
	c2.my_account = &acc2; // 이영희 고객에게 acc2 계좌 연결

	// 4. 정보 출력
	printCustomerInfo(&c1);
	printCustomerInfo(&c2);

	printf("고객 정보와 입금 금액 입력 : ");
	if (scanf("%s %d", name, &deposit) != 2) {
		return;
	}

	if (strcmp(name, "홍길동") == 0) {
		c1.my_account->balance += deposit;
		printf("\n[%s] 고객님 계좌에 %d원이 입금되었습니다.\n\n", name, deposit);

		printf("=== [변경 후 상태] ===\n");
		printCustomerInfo(&c1); // 변경된 홍길동 정보만 확인
	}
	else if (strcmp(name, "이영희") == 0) {
		c2.my_account->balance += deposit;
		printf("\n[%s] 고객님 계좌에 %d원이 입금되었습니다.\n\n", name, deposit);
		printCustomerInfo(&c2); // 변경된 이영희 정보만 확인
	}
	else {
		printf("\n일치하는 고객 정보가 없습니다.\n\n");
	}
}

void testUnion(void) {
	ControlRegister ctrl;

	ctrl.reg = 0;           // 전체 초기화
	ctrl.bits.mode = 3;     // 모드 설정
	ctrl.bits.enable = 1;   // 활성화

	printf("레지스터 값: 0x%X\n", ctrl.reg);
	printf("mode = %d, enable = %d\n", ctrl.bits.mode, ctrl.bits.enable);
}

void printTodo(Day day) {
	switch (day) {
	case MON:
		printf("월요일: 주간 업무 계획 세우기\n");
		break;
	case TUE:
		printf("화요일: 프로젝트 개발\n");
		break;
	case WED:
		printf("수요일: 팀 회의 참석\n");
		break;
	case THU:
		printf("목요일: 문서 작성\n");
		break;
	case FRI:
		printf("금요일: 주간 업무 정리\n");
		break;
	case SAT:
		printf("토요일: 운동하기\n");
		break;
	case SUN:
		printf("일요일: 휴식 및 독서\n");
		break;
	}
}

void testEnum(void) {
	Day day;

	printf("===== 주간 To-Do List =====\n");

	for (day = MON; day <= SUN; day++) {
		printTodo(day);
	}
}




