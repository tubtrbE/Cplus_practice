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
		cout << myname << " : �۸� �߳�ٿ�~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : �۸� �������� ���� ~ " << endl;
	}
};
