#pragma once
#include "Animal.h"
#define _CRT_SECURE_NO_WARNINGS

class Cat:public Animal {
private:
public:
	Cat(char* myname);
	virtual void VoiceCheckIn();
	virtual void VoiceCheckOut();
};
