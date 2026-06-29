#include "input.h"

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

float getFloat() {
	float b;
	while (1) {
		printf("Enter a float: ");
		if (scanf("%f", &b) == 1) {
			break;                    // 정상 변환
		}
		printf("실수를 입력하세요.\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { } // 입력 버퍼 비우기
	}
	return b;
}

char getChar() {
	char c;
	while (1) {
		printf("Enter a character: ");
		if (scanf(" %c", &c) == 1) {
			break;                    // 정상 변환
		}
		printf("문자를 입력하세요.\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF) { } // 입력 버퍼 비우기
	}
	return c;
}