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
		cout << "�޴��� �Է� �Ͻÿ� : ";
		cin >> menu;

		//Check In
		if (menu == 1) {
			system("cls");

			//CheckIn();
			cout << "CHECK IN �� ��ȣ�� �Է� �� �ּ��� :";
			cin >> roomNum;
			if (hotel.CustomerCheck(roomNum) == false) {
				cout << "������ ������ �����Դϱ�? : ";
				cin >> species;

				cout << "������ �̸��� �����Դϱ�? : ";
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
					cout << "�߸��� �Է��Դϴ�." << endl;
				}
			}
			else {
				cout << "�������� �̹� ���� �մϴ�." << endl;
			}
			roomNum = 0;
			strcpy(species, "");
			strcpy(name, "");
		}

		//Check Out
		if (menu == 2) {
			system("cls");
			cout << "üũ�ƿ� �Ϸ��� ���� ȣ���� �Է��Ͽ� �ֽʽÿ� : ";
			int temp = 0;
			cin >> temp;

			if (hotel.CustomerCheck(temp) == true) {
				hotel.CustomerInfo(temp)->VoiceCheckOut();
				hotel.CheckOut(temp);
			}
			else {
				cout << "�̹� ����ִ� ���Դϴ�." << endl;
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
			cout << "Ȯ���ϰ� ���� ���� ȣ���� �Է��Ͽ� �ֽʽÿ�. :";
			
			int temp = 0;
			cin >> temp;

			if (hotel.CustomerCheck(temp) == true) {
				hotel.CustomerInfo(temp)->getName();
			}
			else {
				cout << "�������� �������� �ʽ��ϴ�." << endl;
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