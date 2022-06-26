#include "ParkingTower.h"
#include <iostream>

using namespace std;

ParkingTower::ParkingTower(int myfloor) : floorNum(myfloor), isCar(false), isDoor(true), board(0) {
	parkingLot = new Car* [myfloor];
	for (int i = 0; i < myfloor; i++) {
		parkingLot[i] = 0;
	}
}

ParkingTower::~ParkingTower() {
	delete[] parkingLot;
}

// ���� ���� ���
void ParkingTower::order() {
	
	int order = 0;
	cout << "<1.����>" << endl; cout << "<2.����>" << endl;
	cout << "������ ���� �� �����Ͻʽÿ�.(����) : ";
	cin >> order;

	//cout << ">>>���� �������� ����<<<" << endl;
	if (order == 1) {
		OutputCar();
	}
	//cout << ">>>���� �������� ����<<<" << endl;
	else if (order == 2) {
		InputCar();
	}
	else {
		cout << "�߸��� �Է��Դϴ�" << endl;
	}
}

void ParkingTower::ParkingStatus() {
	cout << "���� ������ �������� ���� �Դϴ�." << endl;
	for (int i = 0; i < floorNum; i++) {

		if (parkingLot[i] != 0) {
			cout << i + 1 << "[��] => ���ָ� : " << parkingLot[i]->getName()
				<< "  ������ȣ�� : " << parkingLot[i]->getNum() << endl;
		}
		else {
			cout << i + 1 << "[��] : " << endl;
		}
	}
}

bool ParkingTower::ParkingSearch() {
	int temp = 0;
	int tempCarNum = 0;
	char tempName[10] = {};
	cout << "<1.���ָ�>" << endl; cout << "<2.������ȣ>" << endl;
	cout << "�Է°�(����) : ";  cin >> temp;

	if (temp == 1) {
		int countFlag = 0;
		cout << "<<<���ָ� �˻�>>>" << endl;
		cout << "���ָ��� �Է��ϼ��� : ";
		cin >> tempName;
		cout << "### �˻��� ��� �Դϴ�. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null �޸𸮿� �����ϴ°��� ���´�.
			if (parkingLot[i] != 0) {
				if (strcmp(parkingLot[i]->getName(), tempName) == 0) {
					cout << i + 1 << "[��] => ���ָ� : " << parkingLot[i]->getName()
						<< "  ������ȣ�� : " << parkingLot[i]->getNum() << endl;
					countFlag++;
					
				}
			}
		}
		if (countFlag == 0) {
			cout << "ã���ô� ������ �������� �ʽ��ϴ�." << endl;
		}
		else {
			return true;
		}
	}
	else if (temp == 2) {
		int countFlag = 0;
		cout << "<<<������ȣ �˻�>>>" << endl;
		cout << "������ȣ�� �Է��ϼ��� : ";
		cin >> tempCarNum;
		cout << "### �˻��� ��� �Դϴ�. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null �޸𸮿� �����ϴ°��� ���´�.
			if (parkingLot[i] != 0) {
				if (parkingLot[i]->getNum() == tempCarNum) {
					cout << i + 1 << "[��] => ���ָ� : " << parkingLot[i]->getName()
						<< "  ������ȣ�� : " << parkingLot[i]->getNum() << endl;
					countFlag++;
				}
			}
		}
		if (countFlag == 0) {
			cout << "ã���ô� ������ �������� �ʽ��ϴ�." << endl;
			return false;
		}
		else {
			return true;
		}
	}
	else {
		cout << "�߸��� �Է��� �ϼ̽��ϴ�." << endl;
		return false;
	}
}

void ParkingTower::ShowTower() {
	system("cls");
	char floor[50] = "===========================";
	char board[50] = "=========================";

	char parking[12][50] = {
		"||     =============        ",
		"||    ||           ||       ",
		"||    ||           ||       ",
		"||    ||           ||       ",
		"||     =============        ",
		"||                          ",
		"||                          ",
		"||                          ",
		"||                          ",
		"||                          ",
	};

	char Car[12][50] = {
		"      ===========        ",
		"     ||         ||       ",
		"    ===         ===      ",
		"    ||           ||      ",
		"     =============       ",
		"                         ",
		"                         ",
		"                         ",
		"                         ",
		"                         ",
	};

	char door[5] = "##";

	// õ��
	cout << floor << endl;

	// 1 ~ floorNum ������
	for (int i = floorNum-1; i >= 0; i--) {

		if (parkingLot[i] != 0) {
			cout << "###########" << i+1 << "��##########" << endl;
			for (int j = 0; j < 5; j++) {
				cout << parking[j] << endl;
			}
		}
		else if (parkingLot[i] == 0) {
			cout << "###########" << i+1 << "��##########" << endl;
			for (int j = 0; j < 5; j++) {
				cout << parking[j+5] << endl;
			}
		}

		// ������Ʈ ���� �̵��ϴ� �˰���
//		cout << floor << "  " << board << endl;
		cout << floor << endl;
	}

	/*
	// 1 ���� door �� �����Ƿ� ���� �����Ѵ�.
	for (int i = 0; i < 5; i++) {
		int j = i;
		cout << parking[i] << "  " << Car[j] << door << Car[j] << endl;
	}
	cout << floor << "  " << board << endl;
	*/
}

// ���Ŀ� hotel �̶� Ŭ���� �Ǵ� �������̽��μ� ������ �Ѵٰ� �����Ѵ�.
// 

void ParkingTower::InputCar() {
	char carType[10] = {};
	cout << ">>>���� �������� ����<<<" << endl;
	cout << "<1.SUV>" << endl; cout << "<2.SEDAN>" << endl;
	cout << "���������� �Է��ϼ���(����, ����) : "; cin >> carType;

	if (carType[0] == '1' || strcmp(carType, "suv") == 0 || strcmp(carType, "SUV") == 0) {

		int carNumTemp = 0;
		char ownerNameTemp[10] = {};

		cout << ">> ���ָ��� �Է��ϼ��� : "; cin >> ownerNameTemp;
		cout << ">> ������ȣ�� �Է��ϼ��� : "; cin >> carNumTemp;

		for (int i = 0; i < floorNum; i++) {
			if (parkingLot[i] == 0) {
				parkingLot[i] = new Suv(carNumTemp, ownerNameTemp);
				parkingLot[i]->CarIn();
				break;
			}
		}

	}

	else if (carType[0] == '2' || strcmp(carType, "sedan") == 0 || strcmp(carType, "SEDAN") == 0) {

		int carNumTemp = 0;
		char ownerNameTemp[10] = {};

		cout << ">> ���ָ��� �Է��ϼ��� : "; cin >> ownerNameTemp;
		cout << ">> ������ȣ�� �Է��ϼ��� : "; cin >> carNumTemp;

		for (int i = 0; i < floorNum; i++) {
			if (parkingLot[i] == 0) {
				parkingLot[i] = new Sedan(carNumTemp, ownerNameTemp);
				parkingLot[i]->CarIn();
				break;
			}
		}

	}
	else {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}

	char yesNo[10] = {};
	cout << "���� �� ������ų ������ �ֽ��ϱ�? [yes / no] : "; cin >> yesNo;
	
	if (strcmp(yesNo, "yes") == 0 || strcmp(yesNo, "YES") == 0) {
		OutputCar();
	}
}

void ParkingTower::OutputCar() {
	cout << ">>>���� �������� ����<<<" << endl;

	int temp = 0;
	int tempCarNum = 0;
	char tempName[10] = {};
	cout << "<1.���ָ�>" << endl; cout << "<2.������ȣ>" << endl;
	cout << "�Է°�(����) : ";  cin >> temp;

	if (temp == 1) {
		int countFlag = 0;
		cout << "<<<���ָ� �˻�>>>" << endl;
		cout << "���ָ��� �Է��ϼ��� : ";
		cin >> tempName;
		cout << "### �˻��� ��� �Դϴ�. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null �޸𸮿� �����ϴ°��� ���´�.
			if (parkingLot[i] != 0) {
				if (strcmp(parkingLot[i]->getName(), tempName) == 0) {
					parkingLot[i]->CarOut();
					parkingLot[i] = 0;
					countFlag++;
					delete parkingLot[i];
					break;
				}
			}
		}
		if (countFlag == 0) {
			cout << "ã���ô� ������ �������� �ʽ��ϴ�." << endl;
		}
	}
	else if (temp == 2) {
		int countFlag = 0;
		cout << "<<<������ȣ �˻�>>>" << endl;
		cout << "������ȣ�� �Է��ϼ��� : ";
		cin >> tempCarNum;
		cout << "### �˻��� ��� �Դϴ�. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null �޸𸮿� �����ϴ°��� ���´�.
			if (parkingLot[i] != 0) {
				if (parkingLot[i]->getNum() == tempCarNum) {
					parkingLot[i]->CarOut();
					parkingLot[i] = 0;
					countFlag++;
					delete parkingLot[i];
					break;
				}
			}
		}
		if (countFlag == 0) {
			cout << "ã���ô� ������ �������� �ʽ��ϴ�." << endl;
		}
	}
	else {
		cout << "�߸��� �Է��� �ϼ̽��ϴ�." << endl;
	}
}

// Ÿ���� ���� ���� ����
void ParkingTower::Door() {

	// ���尡 1�� �̾�� �Ѵ�.
	BoardMove();
	
	CarCheck();
}

// ������Ʈ ���� �� �ڵ����� ����
void ParkingTower::CarCheck() {

}

// ������ ������
void ParkingTower::BoardMove() {

}



