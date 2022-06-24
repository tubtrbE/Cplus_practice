#include "Dog.h"

Dog::Dog(char* myname) : Animal(myname) {

}
void Dog::VoiceCheckIn() {
	const char* myname = getName();
	cout << myname << " : ¸Û¸Û Àß³î´Ù¿Í~" << endl;
}
void Dog::VoiceCheckOut() {
	const char* myname = getName();
	cout << myname << " : ¸Û¸Û ÀßÁö³»´Ù °¡¿ä ~ " << endl;
}
