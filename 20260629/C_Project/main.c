#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include <windows.h>
#include "input.h"
#include "output.h"
#include "practice.h"

typedef struct {
	const char* label;
	void (*run)();
} MenuItem;

static void runTourRecommand(void) {
	TourRecommand(false);
}

static const MenuItem MENU[] = {
	{ "Boolean Practice", boolPractice },
	{ "Type Conversion Practice", typeConversionPractice },
	{ "Calculation Practice", calculation },
	{ "Check Score", checkScore },
	{ "Check Balance", checkBalance },
	{ "Simple Calculator", simpleCalculator },
	{ "Check Pass", checkPass },
	{ "Cinema Ticket", cinemaTicket },
	{ "Shopping Discount", shoppingDiscount },
	{ "Combat Game", CombatGame },
	{ "Tour Recommendation", runTourRecommand },
	{ "Print Gugudan", printGugudan },
	{ "Print All Gugudan", printAllGugudan },
	{ "Print All Gugudan 2", printAllGugudan2 },
	{ "Password Check", passwordCheck },
	{ "Init Until Equal", initUntilEqual },
	{ "Print Even Numbers", printEvenNumbers },
	{ "Process Villa", processVilla },
	{ "Process Score", processScore },
	{ "Array String Init", ArrayStringInit },
	{ "String Copy", StringCopy },
	{ "String Swap", StringSwap },
	{ "Char Function", CharFunction },
	{ "Char Function 2", CharFunc2 },
	{ "Process Char", processChar },
	{ "String Practice", stringPractice },
	{ "Password Register", passwordRegister },
	{ "Pointer Init", pointerInit },
	{ "Get Pointer Value", getPointerValue },
	{ "Pointer Array Type", pointerArrayType },
	{ "Pointer Array Type 1", pointerArrayType1 },
	{ "Pointer Offset", pointerOffset },
	{ "Pointer Array Sum", pointerArraySum },
	{ "Pointer Array Max Find", pointerArrayMaxFind },
	{ "Pointer Array", pointerArray },
	{ "Main Swap Num", mainSwapNum },
	{ "Main Print Array", mainPrintArray },
	{ "Main Print Array 2", mainPrintArray2 },
	{ "Main Score Calc", mainScoreCalc },
	{ "Double Pointer", doublePointer },
	{ "Swap Pointer", SwapPointer },
	{ "Swap Double Pointer", SwapDPointer },
	{ "Swap Char", SwapChar },
	{ "Double Pointer Example", DoublePointer },
	{ "2D Array Name And Array Pointer", Arr2DNameAndArrPtr },
	{ "Array Pointer And Pointer Array", ArrPtrAndPtrArr },
	{ "Student Info", StudentInfo },
	{ "Book Info", BookInfo },
	{ "Analyze Mart", AnalyzeMart },
	{ "Student Struct Practice", studentStructPractice },
	{ "Test Struct Pointer", TestStructPointer },
	{ "Struct Member Pointer", StructMemberPointer },
	{ "Struct Pointer Member Example", StructPointerMemberExample },
	{ "Test Bank System", testBankSystem },
	{ "Test Union", testUnion },
	{ "Test Enum", testEnum },
	{ "Test Todo System", testTodoSystem },
	{ "Dynamic Memory Ex 1", DynamicMemoryEx1 },
	{ "Dynamic Memory Ex 2", DynamicMemoryEx2 },
	{ "Analyze Monthly Sales", analyzeMonthlySales },
	{ "Write Data to File", writeDatatoFile },
	{ "Read Data from File", readDatatoFile },
	{ "Write Binary Data to File", writeBinFile },
	{ "Read Binary Data from File", readBinFile },
	{ "Student Score CSV Practice", mainStudentScore }
};

static const int MENU_COUNT = sizeof(MENU) / sizeof(MENU[0]);

int main(void) {
	// 콘솔 입력/출력 인코딩을 UTF-8(65001)로 설정 (한글 깨짐 해결)
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	for (int i = 0; i < MENU_COUNT; i++) {
		printf("%d. %s\n", i + 1, MENU[i].label);
	}
	printf("실행할 번호: ");

	int sel;
	if (scanf("%d", &sel) == 1 && sel >= 1 && sel <= MENU_COUNT) {
		MENU[sel - 1].run();
	}
	else {
		printf("잘못된 선택입니다.\n");
	}

	return 0;
}
