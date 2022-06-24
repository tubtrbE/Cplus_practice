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

	AnimalHotel(int myroomNum);
	~AnimalHotel();
	bool CustomerCheck(int num);
	void ShowList() const;
	void CheckIn();
	void CheckOut();
	void CustomerInfo();
};



