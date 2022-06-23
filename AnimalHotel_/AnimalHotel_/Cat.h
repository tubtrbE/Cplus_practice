#pragma once
#include "Animal.h"
#define _CRT_SECURE_NO_WARNINGS

class Cat :public Animal {
private:
public:
	Cat(char* myname) : Animal(myname) {

	}
	virtual void VoiceCheckIn() {
		const char* myname = getName();
		cout << myname << " : 냥냥 잘놀다와~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : 냥냥 잘지내다 가요 ~ " << endl;
	}
};
