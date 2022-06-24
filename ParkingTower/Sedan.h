#pragma once
#include "Car.h"


class Sedan : public Car
{
private:

public:
	Sedan(int myNum, char* myNameOwner);
	void CarOut();
	void CarIn();
};

