#pragma once
#include "Car.h"
class Suv : public Car
{
private:

public:
	Suv(int myNum, char* myNameOwner);
	void CarOut();
	void CarIn();
};

