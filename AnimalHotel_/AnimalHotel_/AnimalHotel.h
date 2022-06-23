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

		//방의 갯수myroomNum
		room = new Animal*[myroomNum];

		for (int i = 0; i < myroomNum; i++) {
			roomList[i] = 0;
			room[i]->setName((char*)"빈방");
		}
	}

	~AnimalHotel() {
		delete[] roomList;
		delete[] room;
	}

	void ShowList() const {

		for (int i = 0; i < roomNum; i++) {
			const char* myname = room[i]->getName();
			cout << i + 1 << "번째 방 : " << roomList[i];
			cout << "동물이름 : " << myname << endl;
		}
	}

	void CheckIn(int num, Animal* animal) {
		roomList[num - 1] = 1;
		room[num - 1] = animal;
		cout << num << "번째 방에 checkin 하였습니다." << endl;
	}

	void CheckOut(int num, Animal* animal) {
		roomList[num - 1] = 0;
		cout << num << "번째 방에 checkout 하였습니다." << endl;
	}

	void CustomerInformation(int num, Animal* animal) {
		const char* myname = animal->getName();
		animal = 0;
		cout << myname << endl;
	}
};

