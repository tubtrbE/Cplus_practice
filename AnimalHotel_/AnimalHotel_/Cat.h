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
		cout << myname << " : �ɳ� �߳�ٿ�~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : �ɳ� �������� ���� ~ " << endl;
	}
};
