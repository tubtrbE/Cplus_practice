#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "main.h"
#include "AnimalHotel.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

using namespace std;

int main(void) {

	AnimalHotel hotel(8);
	int roomNum = 0;
	char species[10] = {};
	char name[10] = {};
	int menu = 0;

	while (true) {

		ShowMenu();
		cout << "메뉴를 입력 하시오 : ";
		cin >> menu;

		//Check In
		if (menu == 1) {
			system("cls");

			//CheckIn();
			cout << "CHECK IN 방 번호를 입력 해 주세요 :";
			cin >> roomNum;
			if (hotel.CustomerCheck(roomNum) == false) {
				cout << "동물의 종류는 무엇입니까? : ";
				cin >> species;

				cout << "동물의 이름은 무엇입니까? : ";
				cin >> name;

				if (strcmp(species, "dog") == 0) {
					Animal* temp = new Dog(name);
					hotel.CheckIn(roomNum, temp);
					hotel.CustomerInfo(roomNum)->VoiceCheckIn();
				}
				else if (strcmp(species, "cat") == 0) {
					Animal* temp = new Cat(name);
					hotel.CheckIn(roomNum, temp);
					hotel.CustomerInfo(roomNum)->VoiceCheckIn();
				}
				else {
					cout << "잘못된 입력입니다." << endl;
				}
			}
			else {
				cout << "투숙객이 이미 존재 합니다." << endl;
			}
			roomNum = 0;
			strcpy(species, "");
			strcpy(name, "");
		}

		//Check Out
		if (menu == 2) {
			system("cls");
			cout << "체크아웃 하려는 방의 호실을 입력하여 주십시요 : ";
			int temp = 0;
			cin >> temp;

			if (hotel.CustomerCheck(temp) == true) {
				hotel.CustomerInfo(temp)->VoiceCheckOut();
				hotel.CheckOut(temp);
			}
			else {
				cout << "이미 비어있는 방입니다." << endl;
			}
		}

		//Show List
		if (menu == 3) {
			system("cls");
			hotel.ShowList();
		}

		// Check Customer Info
		if (menu == 4) {
			system("cls");
			cout << "확인하고 싶은 방의 호실을 입력하여 주십시요. :";
			
			int temp = 0;
			cin >> temp;

			if (hotel.CustomerCheck(temp) == true) {
				hotel.CustomerInfo(temp)->getName();
			}
			else {
				cout << "투숙객이 존재하지 않습니다." << endl;
			}
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