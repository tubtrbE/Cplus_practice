#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "main.h"

using namespace std;

int main(void) {

	AnimalHotel hotel(8);
	int roomNum = 0;
	char species[10] = {};
	char name[10] = {};
	int menu = 0;

	while (1) {

		ShowMenu();
		cout << "�޴��� �Է� �Ͻÿ� : ";
		cin >> menu;

		//Check In
		if (menu == 1) {

			//CheckIn();
			cout << "CHECK IN �� ��ȣ�� �Է� �� �ּ��� :";
			cin >> roomNum;

			cout << "������ ������ �����Դϱ�? : ";
			cin >> species;

			cout << "������ �̸��� �����Դϱ�? : ";
			cin >> name;

			if (strcmp(species, "dog") == 0) {
				Animal* temp = new Dog(name);
				hotel.CheckIn(roomNum, temp);
				delete temp;
			}
			else if (strcmp(species, "cat") == 0) {
				Animal* temp = new Cat(name);
				hotel.CheckIn(roomNum, temp);
				delete temp;
			}

			roomNum = 0;
			strcpy(species, "");
			strcpy(name, "");
		}

		//Check Out
		if (menu == 2) {

		}

		//Show List
		if (menu == 3) {
			hotel.ShowList();
		}

		// Check Customer Info
		if (menu == 4) {

		}
	}
	return 0;
}

void ShowMenu() {
	cout << "======================================================" << endl;
	cout << "|| [1] CheckIn                                      ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] CheckOut                                     ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] ShowList                                     ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [4] CusInfo                                      ||" << endl;
	cout << "======================================================" << endl;
}