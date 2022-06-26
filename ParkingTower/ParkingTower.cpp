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

// 출차 입차 명령
void ParkingTower::order() {
	
	int order = 0;
	cout << "<1.출차>" << endl; cout << "<2.입차>" << endl;
	cout << "출차와 입차 중 선택하십시요.(숫자) : ";
	cin >> order;

	//cout << ">>>출차 프로토콜 실행<<<" << endl;
	if (order == 1) {
		OutputCar();
	}
	//cout << ">>>입차 프로토콜 실행<<<" << endl;
	else if (order == 2) {
		InputCar();
	}
	else {
		cout << "잘못된 입력입니다" << endl;
	}
}

void ParkingTower::ParkingStatus() {
	cout << "현재 주차된 차량들의 정보 입니다." << endl;
	for (int i = 0; i < floorNum; i++) {

		if (parkingLot[i] != 0) {
			cout << i + 1 << "[층] => 차주명 : " << parkingLot[i]->getName()
				<< "  차량번호명 : " << parkingLot[i]->getNum() << endl;
		}
		else {
			cout << i + 1 << "[층] : " << endl;
		}
	}
}

bool ParkingTower::ParkingSearch() {
	int temp = 0;
	int tempCarNum = 0;
	char tempName[10] = {};
	cout << "<1.차주명>" << endl; cout << "<2.차량번호>" << endl;
	cout << "입력값(정수) : ";  cin >> temp;

	if (temp == 1) {
		int countFlag = 0;
		cout << "<<<차주명 검색>>>" << endl;
		cout << "차주명을 입력하세요 : ";
		cin >> tempName;
		cout << "### 검색한 결과 입니다. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null 메모리에 접근하는것을 막는다.
			if (parkingLot[i] != 0) {
				if (strcmp(parkingLot[i]->getName(), tempName) == 0) {
					cout << i + 1 << "[층] => 차주명 : " << parkingLot[i]->getName()
						<< "  차량번호명 : " << parkingLot[i]->getNum() << endl;
					countFlag++;
					
				}
			}
		}
		if (countFlag == 0) {
			cout << "찾으시는 차량이 존재하지 않습니다." << endl;
		}
		else {
			return true;
		}
	}
	else if (temp == 2) {
		int countFlag = 0;
		cout << "<<<차량번호 검색>>>" << endl;
		cout << "차량번호를 입력하세요 : ";
		cin >> tempCarNum;
		cout << "### 검색한 결과 입니다. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null 메모리에 접근하는것을 막는다.
			if (parkingLot[i] != 0) {
				if (parkingLot[i]->getNum() == tempCarNum) {
					cout << i + 1 << "[층] => 차주명 : " << parkingLot[i]->getName()
						<< "  차량번호명 : " << parkingLot[i]->getNum() << endl;
					countFlag++;
				}
			}
		}
		if (countFlag == 0) {
			cout << "찾으시는 차량이 존재하지 않습니다." << endl;
			return false;
		}
		else {
			return true;
		}
	}
	else {
		cout << "잘못된 입력을 하셨습니다." << endl;
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

	// 천장
	cout << floor << endl;

	// 1 ~ floorNum 층까지
	for (int i = floorNum-1; i >= 0; i--) {

		if (parkingLot[i] != 0) {
			cout << "###########" << i+1 << "층##########" << endl;
			for (int j = 0; j < 5; j++) {
				cout << parking[j] << endl;
			}
		}
		else if (parkingLot[i] == 0) {
			cout << "###########" << i+1 << "층##########" << endl;
			for (int j = 0; j < 5; j++) {
				cout << parking[j+5] << endl;
			}
		}

		// 스케이트 보드 이동하는 알고리즘
//		cout << floor << "  " << board << endl;
		cout << floor << endl;
	}

	/*
	// 1 층은 door 가 있으므로 따로 제어한다.
	for (int i = 0; i < 5; i++) {
		int j = i;
		cout << parking[i] << "  " << Car[j] << door << Car[j] << endl;
	}
	cout << floor << "  " << board << endl;
	*/
}

// 추후에 hotel 이란 클래스 또는 인터페이스로서 만들어야 한다고 생각한다.
// 

void ParkingTower::InputCar() {
	char carType[10] = {};
	cout << ">>>입차 프로토콜 실행<<<" << endl;
	cout << "<1.SUV>" << endl; cout << "<2.SEDAN>" << endl;
	cout << "차량종류를 입력하세요(숫자, 영어) : "; cin >> carType;

	if (carType[0] == '1' || strcmp(carType, "suv") == 0 || strcmp(carType, "SUV") == 0) {

		int carNumTemp = 0;
		char ownerNameTemp[10] = {};

		cout << ">> 차주명을 입력하세요 : "; cin >> ownerNameTemp;
		cout << ">> 차량번호를 입력하세요 : "; cin >> carNumTemp;

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

		cout << ">> 차주명을 입력하세요 : "; cin >> ownerNameTemp;
		cout << ">> 차량번호를 입력하세요 : "; cin >> carNumTemp;

		for (int i = 0; i < floorNum; i++) {
			if (parkingLot[i] == 0) {
				parkingLot[i] = new Sedan(carNumTemp, ownerNameTemp);
				parkingLot[i]->CarIn();
				break;
			}
		}

	}
	else {
		cout << "잘못 입력하셨습니다." << endl;
	}

	char yesNo[10] = {};
	cout << "입차 후 출차시킬 차량이 있습니까? [yes / no] : "; cin >> yesNo;
	
	if (strcmp(yesNo, "yes") == 0 || strcmp(yesNo, "YES") == 0) {
		OutputCar();
	}
}

void ParkingTower::OutputCar() {
	cout << ">>>출차 프로토콜 실행<<<" << endl;

	int temp = 0;
	int tempCarNum = 0;
	char tempName[10] = {};
	cout << "<1.차주명>" << endl; cout << "<2.차량번호>" << endl;
	cout << "입력값(정수) : ";  cin >> temp;

	if (temp == 1) {
		int countFlag = 0;
		cout << "<<<차주명 검색>>>" << endl;
		cout << "차주명을 입력하세요 : ";
		cin >> tempName;
		cout << "### 검색한 결과 입니다. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null 메모리에 접근하는것을 막는다.
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
			cout << "찾으시는 차량이 존재하지 않습니다." << endl;
		}
	}
	else if (temp == 2) {
		int countFlag = 0;
		cout << "<<<차량번호 검색>>>" << endl;
		cout << "차량번호를 입력하세요 : ";
		cin >> tempCarNum;
		cout << "### 검색한 결과 입니다. ###" << endl;

		for (int i = 0; i < floorNum; i++) {
			//null 메모리에 접근하는것을 막는다.
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
			cout << "찾으시는 차량이 존재하지 않습니다." << endl;
		}
	}
	else {
		cout << "잘못된 입력을 하셨습니다." << endl;
	}
}

// 타워의 문을 열고 닫음
void ParkingTower::Door() {

	// 보드가 1층 이어야 한다.
	BoardMove();
	
	CarCheck();
}

// 스케이트 보드 위 자동차의 존재
void ParkingTower::CarCheck() {

}

// 보드의 움직임
void ParkingTower::BoardMove() {

}



