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
	cout << "�ڽ��� �ǹ��� �´� ������ �����Ͻʽÿ�" << endl;
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
			cout << "���Է� �Ͻʽÿ�. �߸��� �Է��Դϴ�. " << endl;
			menu = 0;
			break;
		};
	}
	return 0;
}

int ShowMenu(int _menu) {
	
		system("cls");
		cout << "  <<<<�޴��� �����Ͻʽÿ�>>>>" << endl;
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
	cout << "###�޴��� ���Ʒ��� ����(����) �� ���� �Է��ϼ���###" << endl;
	cin >> temp;
}