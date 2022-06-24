#include "Cat.h"

Cat::Cat(char* myname) : Animal(myname) {

}
void Cat::VoiceCheckIn() {
	const char* myname = getName();
	cout << myname << " : 냥냥 잘놀다와~" << endl;
}
void Cat::VoiceCheckOut() {
	const char* myname = getName();
	cout << myname << " : 냥냥 잘지내다 가요 ~ " << endl;
}