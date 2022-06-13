#include <iostream>
#include "stdio.h"
#include "string.h"
#include "Windows.h"

void cli(int coin);
void add_coin(int& coin);
void buy(char beverage[4][10], int beverage_coin[], char beverage_buy[], int& coin);

using std::cin;
using std::cout;
using std::endl;

int main(void) {

	char beverage[4][10] = { "coffee", "coke", "cider", "juice" };
	int beverage_coin[4] = { 200, 300, 700, 1000 };
	char beverage_buy[10] = {};
	int coin = 0;
	int menu = 0;

	while (true) {
		system("cls");
		cli(coin);
		cin >> menu;

		// 돈추가
		if (menu == 1) {
			system("cls");
			cli(coin);
			add_coin(coin);
			menu = 0;
		}

		// 음료 구매
		else if (menu == 2) {
			system("cls");
			cli(coin);
			buy(beverage, beverage_coin, beverage_buy, coin);
			menu = 0;
		}
	}
}

void cli(int coin) {

	cout << "         <<음료를 선택해 주세요>>           " << endl;
	cout << "============================================" << endl;
	cout << "|| 1) coffee : 200[coin]                  ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| 2) coke   : 300[coin]                  ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| 3) cider  : 700[coin]                  ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| 4) juice  : 1000[coin]                 ||" << endl;
	cout << "||========================================||" << endl;
	printf("|| 현재 코인  : %04d[coin]                ||\n", coin);
	cout << "||========================================||" << endl;
	cout << "|| [1] 돈 추가                            ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| [2] 음료구매                           ||" << endl;
	cout << "============================================" << endl;
}

void add_coin(int& coin) {

	int add = 0;
	cout << "추가할 코인을 입력 하십시요 : ";
	cin >> add;
	coin += add;
}

void buy(char beverage[4][10], int beverage_coin[], char beverage_buy[], int& coin) {

	cout << "구입 할 음료를 선택 하십시요 : ";
	cin >> beverage_buy;

	if ((strcmp(beverage[0], beverage_buy) == 0 || beverage_buy[0] == '1') && coin >= beverage_coin[0]) {
		coin -= beverage_coin[0];
	}
	else if ((strcmp(beverage[1], beverage_buy) == 0 || beverage_buy[0] == '2') && coin >= beverage_coin[1]) {
		coin -= beverage_coin[1];
	}
	else if ((strcmp(beverage[2], beverage_buy) == 0 || beverage_buy[0] == '3') && coin >= beverage_coin[2]) {
		coin -= beverage_coin[2];
	}
	else if ((strcmp(beverage[3], beverage_buy) == 0 || beverage_buy[0] == '4') && coin >= beverage_coin[3]) {
		coin -= beverage_coin[3];
	}
	else {
		cout << "돈이 모자랍니다 코인을 추가하여 주십시요";
		Sleep(1000);
	}
}

