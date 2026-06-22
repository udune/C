#include "input.h"

int getInt() {
	int a;
	printf("Enter an integer: ");
	scanf("%d", &a);
	return a;
}

float getFloat() {
	float b;
	printf("Enter a float: ");
	scanf("%f", &b);
	return b;
}

char getChar() {
	char c;
	printf("Enter a character: ");
	scanf(" %c", &c);
	return c;
}