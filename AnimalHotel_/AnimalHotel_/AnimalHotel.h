#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Animal.h"

using namespace std;

class AnimalHotel {
private:
	int roomNum;
	int* roomList;
	Animal** room;

public:

	AnimalHotel(int myroomNum) : roomNum(myroomNum) {
		roomList = new int[myroomNum];

		//���� ����myroomNum
		room = new Animal*[myroomNum];

		for (int i = 0; i < myroomNum; i++) {
			roomList[i] = 0;
		}
	}

	~AnimalHotel() {
		delete[] roomList;
		delete[] room;
	}

	void ShowList() const {

		for (int i = 0; i < roomNum; i++) {
			const char* myname = " ";

			if (roomList[i] == 1) {
				myname = room[i]->getName();
			}
			cout << i + 1 << "��° �� : " << roomList[i] << " " << myname << endl;

		}
	}

	bool CustomerCheck(int num) {
		if (roomList[num - 1] == 1) {
			return true;
		}
		else {
			return false;
		}	
	}

	void CheckIn(int num, Animal* animal) {

		roomList[num - 1] = 1;
		room[num - 1] = animal;
		cout << num << "��° �濡 checkin �Ͽ����ϴ�." << endl;
	}

	void CheckOut(int num) {
		roomList[num - 1] = 0;
		delete room[num - 1];
		room[num - 1] = 0;

		cout << num << "��° �濡 checkout �Ͽ����ϴ�." << endl;
	}

	Animal* CustomerInfo(int num) {

		if (roomList[num-1] == 1) {
			return room[num - 1];
		}
		else {
			return 0;
		}
	}


};



