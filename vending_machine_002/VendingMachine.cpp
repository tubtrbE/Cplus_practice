#define _CRT_SECURE_NO_WARNINGS
#include "VendingMachine.h"
#include <iostream>
#include <cstdio>
#include "Windows.h"

using namespace std;

// name �� ���� �迭 �Է��� �ޱ� ���ؼ��� const char* �� �����ڷ� �Է��� �޾ƾ� �Ѵ�.
VendingMachine::VendingMachine(const char* name1, int price1, const char* name2, int price2,
	const char* name3, int price3, const char* name4, int price4) {

	int len;

	//strcpy �� ����ϱ� ���ؼ��� �Ʒ��� ���� �����Ҵ� ���־�� �Ѵ�.
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

	cout << "         <<���Ḧ ������ �ּ���>>           " << endl;
	cout << "============================================" << endl;
	printf("|| 1�� ����  : %10s     ���� : %4d ||\n", name[0], price[0]);
	cout << "||========================================||" << endl;
	printf("|| 2�� ����  : %10s     ���� : %4d ||\n", name[1], price[1]);
	cout << "||========================================||" << endl;
	printf("|| 3�� ����  : %10s     ���� : %4d ||\n", name[2], price[2]);
	cout << "||========================================||" << endl;
	printf("|| 4�� ����  : %10s     ���� : %4d ||\n", name[3], price[3]);
	cout << "||========================================||" << endl;
	printf("|| ����      :    %5d[coin]             ||\n", coin);
	cout << "||========================================||" << endl;
	cout << "|| [1] �� �߰�                            ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| [2] ���ᱸ��                           ||" << endl;
	cout << "||========================================||" << endl;
	cout << "|| [3] �Ž�����                           ||" << endl;
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

	cout << "�԰���� ���Ḧ ����ּ���";
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
			printf("%s �� �����ϼ̽��ϴ�.", name[i]);
			coin -= price[i];
			stock[i]--;
			break;
		}


	}
	/*
			if (beverage[0] == '1' && coin >= price[0]) {
				printf("%s �� �����ϼ̽��ϴ�.", name[0]);
				coin -= price[0];
				stock[0]--;

			}
			else if (beverage[0] == '2' && coin >= price[1]) {
				printf("%s �� �����ϼ̽��ϴ�.", name[1]);
				coin -= price[1];
				stock[1]--;

			}
			else {
				cout << "�ݾ��� �����մϴ�.";
			}
	*/
}

void VendingMachine::InputMoney() {
	int input;
	cout << "�ְ��� �ϴ� �ݾ��� �Է� �Ͻÿ� : ";
	cin >> input;

	if (input >= 0) {
		coin += input;
	}
	else {
		cout << "�߸��� �ݾ��� �Է��ϼ̽��ϴ�.";
	}
}
void VendingMachine::OutputMoney() {
	coin = 0;
}

