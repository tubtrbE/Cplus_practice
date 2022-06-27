#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Citys
{
private:

	string city;
	string district;
	int death[12];

public:

	Citys(string myCity, string myDistrict, int myData[]);
	~Citys();

	string GetCity() const;
	string GetDistrict() const;
	const int * GetDeath() const;

};

