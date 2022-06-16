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

	stock[0] = 0;
	stock[1] = 0;
	stock[2] = 0;
	stock[3] = 0;

	coin = 0;
}


int &VendingMachine::GetStock() {
	return stock[0];
}


void VendingMachine::ShowMenu() {

	// %04d �� 0000 ���� ������ %4d �� '   0' ���� ���´�.
	cout << "         <<���Ḧ ������ �ּ���>>           " << endl;
	cout << "======================================================" << endl;
	printf("|| 1�� ����  : %10s    ���� : %4d  ��� : %3d||\n", name[0], price[0], stock[0]);
	cout << "||==================================================||" << endl;
	printf("|| 2�� ����  : %10s    ���� : %4d  ��� : %3d||\n", name[1], price[1], stock[1]);
	cout << "||==================================================||" << endl;
	printf("|| 3�� ����  : %10s    ���� : %4d  ��� : %3d||\n", name[2], price[2], stock[2]);
	cout << "||==================================================||" << endl;
	printf("|| 4�� ����  : %10s    ���� : %4d  ��� : %3d||\n", name[3], price[3], stock[3]);
	cout << "||==================================================||" << endl;
	printf("|| ����      :    %5d[coin]                       ||\n", coin);
	cout << "||==================================================||" << endl;
	cout << "|| [1] �� �߰�                                      ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] ���ᱸ��                                     ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] �Ž�����                                     ||" << endl;
	cout << "======================================================" << endl;
}

bool VendingMachine::Buy() {
	char beverage[10] = {};
	int min = 100000;
	int buyStatus = 0;
	int index = 0;
	for (int i = 0; i < 4; i++) {
		if (price[i] < min) {
			min = price[i];
		}
	}

	// �ּұݾ� �����Ҷ� �ŷ� ��ü �Ұ�
	if (coin < min) {
		cout << "�ּ� �ݾ��� �����մϴ�.";
		return 0;
	}


	cout << "�԰���� ���Ḧ ����ּ���";
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << price[i] << stock[i] <<endl;
	}
	cin >> beverage;
	cout << beverage << endl;
	cout << min;
	Sleep(1000);

	for (int i = 0; i < 4; i++) {
		if ((beverage[0] == (49 + i) || strcmp(name[i], beverage) == 0) && coin >= price[i]) {
			printf("%s �� �����ϼ̽��ϴ�.", name[i]);

			if (stock[i] == 0) {
				cout << "�Ǹ� ��� �����Ͽ� ���Ű� �Ұ��� �մϴ�." << endl;
				break;
			}
			coin -= price[i];
			stock[i]--;
			index = i;
			buyStatus = 1;

			// �ι�° �Ž����� ����
			if (coin < min) {
				cout << "�ּұݾ׿� ��ġ�� ���ϹǷ� �Ž������� ���� �մϴ�." << endl;
				coin = 0;
			}

			break;
		}
	}

	// �ŷ� ���� �Ǿ����Ƿ� 0�� return
	if (coin < price[index] && buyStatus == 0) {
		cout << "�ݾ��� �����մϴ�.";
		return 0;
	}

	// ���� �ŷ��� �������Ƿ� 1�� return ���ݴϴ�.
	return 1;
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

// ù��° ���� �Ž����� 
void VendingMachine::OutputMoney() {
	coin = 0;
}

