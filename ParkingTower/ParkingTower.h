#pragma once
#include "Car.h"
#include "Suv.h"
#include "Sedan.h"

class ParkingTower
{
private:

	int parkingLotNum;
	Car** parkingLot;

public:
	ParkingTower();

	void Door();
	void CarCheck();
	void CarNum();
	void ParkingCarCheck();


};

