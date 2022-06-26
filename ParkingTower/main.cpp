#include <iostream>
#include "Windows.h"
#include "ParkingTower.h"
#include "Car.h"
#include "Suv.h"
#include "Sedan.h"

int ShowMenu(int _menu);
void CheckMenu();

using namespace std;

int main(void) {

	int floor = 0;
	int timeFlag = 1;
	int menu = 0;
	cout << "자신의 건물에 맞는 층수를 선택하십시요" << endl;
	cin >> floor;
	ParkingTower tower(floor);
	system("cls");


	while (true) {

		/*
		if (timeFlag == 1) {
			Sleep(200);
		}
		*/

		switch (ShowMenu(menu)) {
		case 0:
			ShowMenu(menu);
			break;

		case 1:
			tower.order();
			CheckMenu();
			break;

		case 2:
			tower.ParkingStatus();
			CheckMenu();
			break;

		case 3:
			tower.ParkingSearch();
			CheckMenu();
			break;

		case 4:
			tower.ShowTower();
			CheckMenu();
			break;

		default:
			cout << "재입력 하십시요. 잘못된 입력입니다. " << endl;
			menu = 0;
			break;
		};
	}
	return 0;
}

int ShowMenu(int _menu) {
	
		system("cls");
		cout << "  <<<<메뉴를 선택하십시오>>>>" << endl;
		cout << "||===========================||" << endl;
		cout << "|| [1] order                 ||" << endl;
		cout << "||===========================||" << endl;
		cout << "|| [2] ParkingStatus         ||" << endl;
		cout << "||===========================||" << endl;
		cout << "|| [3] ParkingCheck          ||" << endl;
		cout << "||===========================||" << endl;
		cout << "|| [4] ShowTower             ||" << endl;
		cout << "||===========================||" << endl;
		cin >> _menu;
		return _menu;
}

void CheckMenu() {
	char temp[5] = {};
	cout << "###메뉴로 돌아려면 문자(영어) 나 숫자 입력하세요###" << endl;
	cin >> temp;
}