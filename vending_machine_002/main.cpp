#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "VendingMachine.h"
#include "Windows.h"

using namespace std;
void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine);

int main(void) {

	// 현재는 4가지의 음료를 인수로 받았지만 구조체를 이용하여 생성자를 만들어 보는것을 목표로 하겠다.
	VendingMachine Acid("coke", 1000, "cider", 1500, "sprite", 2000, "welchs", 2500);
	VendingMachine NonAcid("juice", 1000, "ricedrink", 1500, "water", 2000, "tea", 2500);

	// machine 을 레퍼런스로 사용하고자 할때 가장 처음에 초기화 해야 하므로 임의로 Acid 로 초기화 해주었다.
	VendingMachine& machine = Acid;

	choice(Acid, NonAcid, machine);
	int menu = 0;
	int* p = &machine.GetStock();

	while (true) {

		system("cls");
		machine.ShowMenu();
		// 거스름돈 강제 반환 마지막 재고 부족
		if (*(p + 0) == 0 &&
			*(p + 1) == 0 &&
			*(p + 2) == 0 &&
			*(p + 3) == 0) {
			cout << "<<<<<<<재고가 모두 소진 되었습니다.>>>>>>>" << endl;
			machine.OutputMoney();
			Sleep(1000);
		}
		cout << "원하시는 메뉴를 입력해 주세요" << endl;
		cin >> menu;

		// 돈 추가
		if (menu == 1) {
			system("cls");
			machine.ShowMenu();
			machine.InputMoney();
			if (*(p + 0) == 0 &&
				*(p + 1) == 0 &&
				*(p + 2) == 0 &&
				*(p + 3) == 0) {
				machine.OutputMoney();
			}
			menu = 0;
		}

		// 음료 구매
		if (menu == 2) {
			int temp;
			system("cls");
			machine.ShowMenu();
			// 거스름돈 
			// 1. 최소금액에 미치지 못할경우
			// 2. 재고가 모두 소진되어 판매가 불가능 한경우 
			temp = machine.Buy();
			Sleep(1000);
			menu = 0;
		}

		// 거스름돈 (수동 집행)
		if (menu == 3) {
			system("cls");
			machine.ShowMenu();
			machine.OutputMoney();
			menu = 0;
		}
	}

	return 0;
}

// vending 을 선택하는것은 사용자가 선택하는것이므로 객체가 아닌 main 함수 또는 namespace 로 user 를 따로 만들어서 
// 선언하는 것이 옳은 방법이라 생각한다.
void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine) {

	char choice[10];

	cout << "드시고 싶은 음료의 종류를 골라주세요[탄산: 1, 비탄산: 0]" << endl;
	cin >> choice;
	if (strcmp(choice, "탄산") == 0 || choice[0] == '1') {
		machine = Acid;
	}
	else if (strcmp(choice, "비탄산") == 0 || choice[0] == '0') {
		machine = NonAcid;
	}

}