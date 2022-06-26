#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>

Car::Car(int myNum, char* myNameOwner) : num(myNum) {

	int len = strlen(myNameOwner + 1);
	nameOwner = new char();
	strcpy(nameOwner, myNameOwner);
}
Car::~Car() {
	delete[] nameOwner;
}

const char* Car::getName() const{
	return nameOwner;
}
void Car::SetName(char* mynameOwner) {
	nameOwner = mynameOwner;
}

int Car::getNum() {
	return num;
}

void Car::setNum(int myNum) {
	num = myNum;
}

void Car::CarIn() {}
void Car::CarOut() {}