#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


class Animal {
private:
	char* name;

public:

	Animal(char* myname);
	virtual ~Animal();
	const char* getName() const;
	void setName(char* myname);
	virtual void VoiceCheckIn();
	virtual void VoiceCheckOut();
};

