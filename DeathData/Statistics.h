#pragma once
#include "Citys.h"
class Statistics
{
private:
	Citys** citys;

public:
	Statistics();
	~Statistics();
	void InputCity(Citys* city);
	void ShowCity();
	void Search();
	void Sum();

	int Place(string place);
};

