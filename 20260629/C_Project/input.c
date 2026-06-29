#include "input.h"

int getInt() {
	int a;
	printf("Enter an integer: ");
	safe_scanf("%d", &a);
	return a;
}

float getFloat() {
	float b;
	printf("Enter a float: ");
	safe_scanf("%f", &b);
	return b;
}

char getChar() {
	char c;
	printf("Enter a character: ");
	safe_scanf(" %c", &c);
	return c;
}