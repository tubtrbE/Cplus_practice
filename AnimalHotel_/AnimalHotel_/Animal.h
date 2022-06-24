#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


class Animal {
private:
	char* name;

public:

	Animal(char* myname) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}
	~Animal() {
		delete[] name;
	}
	const char* getName() const {
		return this->name;
	}
	void setName(char* myname) {}
	virtual void VoiceCheckIn() {}
	virtual void VoiceCheckOut() {}
};

