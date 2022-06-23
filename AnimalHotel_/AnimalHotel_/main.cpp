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
		cout << "메뉴를 입력 하시오 : ";
		cin >> menu;

		//Check In
		if (menu == 1) {

			//CheckIn();
			cout << "CHECK IN 방 번호를 입력 해 주세요 :";
			cin >> roomNum;

			cout << "동물의 종류는 무엇입니까? : ";
			cin >> species;

			cout << "동물의 이름은 무엇입니까? : ";
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