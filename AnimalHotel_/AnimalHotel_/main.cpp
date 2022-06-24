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
	int menu = 0;

	while (true) {

		ShowMenu();
		cout << "메뉴를 입력 하시오 : ";
		cin >> menu;

		switch (menu) {

		case 1:
			system("cls");
			hotel.CheckIn();
			break;

		case 2:
			system("cls");
			hotel.CheckOut();
			break;

		case 3:
			system("cls");
			hotel.ShowList();
			break;

		case 4:
			system("cls");
			hotel.CustomerInfo(); 
			break;
		
		default:
			menu = 0;
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