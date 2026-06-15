#ifndef PRACTICE_H
#define PRACTICE_H

#include "common.h"

#define SEOUL 1
#define BUSAN 2
#define JEJU 3

void boolPractice();
void typeConversionPractice();
void calculation();
void checkScore();
void checkBalance();
void simpleCalculator();
void checkPass();
void cinemaTicket();
void shoppingDiscount();
void CombatGame();
void TourRecommand(bool reQuestion);
void printGugudan();
void printAllGugudan();
void printAllGugudan2();
void passwordCheck();
void initUntilEqual();
void printEvenNumbers();
void processVilla();
void processScore();
void ArrayStringInit();
void StringCopy();
void StringSwap();
void CharFunction();
void CharFunc2();
void StringFunc();
void processChar();
void stringPractice();
void passwordRegister();
void pointerInit();
void getPointerValue();
void pointerArrayType();
void pointerArrayType1();
void pointerOffset();
void pointerArraySum();
void pointerArrayMaxFind();
void Arr2DNameAndArrPtr();
void ArrPtrAndPtrArr(void);

void pointerArray();
void mainSwapNum();
void swapNum(int* pnum1, int* pnum2);
void printArray(int* arr, int size);
void mainPrintArray();
void printArray2(int arr[], int size);
void mainPrintArray2();
void mainScoreCalc();
void scoreCalc(int* score, int* sum, double* average);
void doublePointer();
void SwapPointer();
void SwapPtr(int* p1, int* p2);
void SwapDPointer();
void SwapDPtr(int** pp1, int** pp2);
void SwapChar();
void freeSwapCharMemory(char** str, int n);
void DoublePointer();
void updateString(char** dest_ptr);

// 구조체 정의
struct Student {
	char name[20];
	int studen_id;
	char phone_number[20];
};

void StudentInfo(void);

struct Book {
	char title[40];
	char author[20];
	int price;
};

void BookInfo(void);

#define MAX_PRODUCTS 3

struct Product {
	char name[20];
	int price;
};

void AnalyzeMart(void);

typedef struct person
{
	char name[20];
	char phone[20];
	int age;
} Person;

void showStudentInfo(Person person);
Person readStudentInfo(void);
void studentStructPractice(void);

typedef struct {
	int xpos;
	int ypos;
} Position;

void TestStructPointer(void);

#endif



