#pragma once
#include "Animal.h"
#define _CRT_SECURE_NO_WARNINGS

class Dog:public Animal {
private:
public:
	Dog(char* myname) : Animal(myname) {

	}
	virtual void VoiceCheckIn() {
		const char* myname = getName();
		cout << myname << " : ¸Û¸Û Àß³î´Ù¿Í~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : ¸Û¸Û ÀßÁö³»´Ù °¡¿ä ~ " << endl;
	}
};
