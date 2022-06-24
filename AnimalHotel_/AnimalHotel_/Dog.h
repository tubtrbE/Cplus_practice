#pragma once
#include "Animal.h"
#define _CRT_SECURE_NO_WARNINGS

class Dog:public Animal {

private:
public:

	Dog(char* myname);
	virtual void VoiceCheckIn();
	virtual void VoiceCheckOut();
};
