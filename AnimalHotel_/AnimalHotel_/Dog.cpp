#include "Dog.h"

Dog::Dog(char* myname) : Animal(myname) {

}
void Dog::VoiceCheckIn() {
	const char* myname = getName();
	cout << myname << " : �۸� �߳�ٿ�~" << endl;
}
void Dog::VoiceCheckOut() {
	const char* myname = getName();
	cout << myname << " : �۸� �������� ���� ~ " << endl;
}
