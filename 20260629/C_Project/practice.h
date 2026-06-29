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

void print_position(const Position* ptr);
void move_position(Position* ptr, int x_delta, int y_delta);
void TestStructPointer(void);

typedef struct {
	char* name;
} Student;

void StructMemberPointer(void);

typedef struct User
{
	char name[20];
	struct User* next;
} User;

void StructPointerMemberExample(void);

// 계좌 구조체 정의
typedef struct {
	char account_num[20]; // 계좌번호
	int balance;          // 잔액
} Account;

// 고객 구조체 정의 (내부에 계좌 구조체 포인터를 멤버로 가짐)
typedef struct {
	char name[20];        // 고객 이름
	Account* my_account;  // 소유한 계좌의 주소를 가리킬 포인터 멤버
} Customer;

void printCustomerInfo(Customer* c_ptr);
void testBankSystem(void);

#include <stdint.h>

typedef union {
	uint8_t reg;
	struct {
		uint8_t mode : 2;   // 2bit
		uint8_t enable : 1; // 1bit
		uint8_t status : 5; // 5bit
	} bits;
} ControlRegister;

void testUnion(void);

typedef enum {
	MON = 0,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
} Day;

void printTodoDay(Day day);
void testEnum(void);

// 공용체와 열거형 조합 실습
typedef enum {
	TODO_PENDING,
	TODO_IN_PROGRESS,
	TODO_DONE
} TodoStatus;

typedef union {
	char createdDate[20];
	char assignee[20];
	char completedDate[20];
} TodoInfo;

typedef struct {
	char title[50];
	TodoStatus status;
	TodoInfo info;
} Todo;

void printTodo(Todo todo);
void testTodoSystem(void);

void DynamicMemoryEx1(void);
void DynamicMemoryEx2(void);
void analyzeMonthlySales(void);

void writeDatatoFile(void);
void readDatatoFile(void);

#endif



