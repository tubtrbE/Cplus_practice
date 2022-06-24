#include "Animal.h"

Animal::Animal(char* myname) {
	int len = strlen(myname) + 1;
	name = new char[len];
	strcpy(name, myname);
}
Animal::~Animal() {
	delete[] name;
}
const char* Animal::getName() const {
	return this->name;
}
void Animal::setName(char* myname) {}
void Animal::VoiceCheckIn() {}
void Animal::VoiceCheckOut() {}