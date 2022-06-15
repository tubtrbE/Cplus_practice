#define _CRT_SECURE_NO_WARNINGS
#include "VendingMachine.h"
#include <iostream>
#include <cstdio>
#include "Windows.h"

using namespace std;

// name 과 같은 배열 입력을 받기 위해서는 const char* 의 형식자로 입력을 받아야 한다.
VendingMachine::VendingMachine(const char* name1, int price1, const char* name2, int price2,
	const char* name3, int price3, const char* name4, int price4) {

	int len;

	//strcpy 를 사용하기 위해서는 아래와 같이 동적할당 해주어야 한다.
	len = strlen(name1) + 1;
	name[0] = new char[len];
	strcpy(name[0], name1);

	len = strlen(name2) + 1;
	name[1] = new char[len];
	strcpy(name[1], name2);

	len = strlen(name3) + 1;
	name[2] = new char[len];
	strcpy(name[2], name3);

	len = strlen(name4) + 1;
	name[3] = new char[len];
	strcpy(name[3], name4);

	price[0] = price1;
	price[1] = price2;
	price[2] = price3;
	price[3] = price4;

	stock[0] = 1;
	stock[1] = 2;
	stock[2] = 3;
	stock[3] = 4;

	coin = 0;
}

void VendingMachine::ShowMenu() {

	cout << "         <<음료를 선택해 주세요>>           " << endl;
	cout << "============================================" << endl;
	printf("|| 1번 음료  : %10s     가격 : %4d ||\n", name[0], price[0]);
	cout << "||========================================||" << endl;
	printf("|| 2번 음료  : %10s     가격 : %4d ||\n", name[1], price[1]);
	cout << "||========================================||" << endl;
	printf("|| 3번 음료  : %10s     가격 : %4d ||\n", name[2], price[2]);
	cout << "||========================================||" << endl;
	printf("|| 4번 음료  : %10s     가격 : %4d ||\n", name[3], price[3]);
	cout << "||========================================||" << endl;
	printf("|| 코인      :    %5d[coin]             ||\n", coin);
	cout << "||========================================||" << endl;
	cout << "|| [1] 돈 추가                            ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| [2] 음료구매                           ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| [3] 거스름돈                           ||" << endl;
	cout << "============================================" << endl;
}

void VendingMachine::Buy() {
	char beverage[10] = {};
	int min = 100000;
	for (int i = 0; i < 4; i++) {
		if (price[i] < min) {
			min = price[i];
		}
	}

	cout << "먹고싶은 음료를 골라주세요";
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << price[i] << endl;
	}
	cin >> beverage;
	cout << beverage;
	Sleep(1000);

	int i;
	for (i = 0; i < 4; i++) {

		if (beverage[0] == (49 + i) && coin >= price[i]) {
			printf("%s 를 선택하셨습니다.", name[i]);
			coin -= price[i];
			stock[i]--;
			break;
		}


	}
	/*
			if (beverage[0] == '1' && coin >= price[0]) {
				printf("%s 를 선택하셨습니다.", name[0]);
				coin -= price[0];
				stock[0]--;

			}
			else if (beverage[0] == '2' && coin >= price[1]) {
				printf("%s 를 선택하셨습니다.", name[1]);
				coin -= price[1];
				stock[1]--;

			}
			else {
				cout << "금액이 부족합니다.";
			}
	*/
}

void VendingMachine::InputMoney() {
	int input;
	cout << "넣고자 하는 금액을 입력 하시요 : ";
	cin >> input;

	if (input >= 0) {
		coin += input;
	}
	else {
		cout << "잘못된 금액을 입력하셨습니다.";
	}
}
void VendingMachine::OutputMoney() {
	coin = 0;
}

