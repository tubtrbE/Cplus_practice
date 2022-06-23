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
			room[i]->setName((char*)"���");
		}
	}

	~AnimalHotel() {
		delete[] roomList;
		delete[] room;
	}

	void ShowList() const {

		for (int i = 0; i < roomNum; i++) {
			const char* myname = room[i]->getName();
			cout << i + 1 << "��° �� : " << roomList[i];
			cout << "�����̸� : " << myname << endl;
		}
	}

	void CheckIn(int num, Animal* animal) {
		roomList[num - 1] = 1;
		room[num - 1] = animal;
		cout << num << "��° �濡 checkin �Ͽ����ϴ�." << endl;
	}

	void CheckOut(int num, Animal* animal) {
		roomList[num - 1] = 0;
		cout << num << "��° �濡 checkout �Ͽ����ϴ�." << endl;
	}

	void CustomerInformation(int num, Animal* animal) {
		const char* myname = animal->getName();
		animal = 0;
		cout << myname << endl;
	}
};

