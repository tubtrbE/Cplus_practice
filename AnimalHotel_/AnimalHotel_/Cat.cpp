#include "Cat.h"

Cat::Cat(char* myname) : Animal(myname) {

}
void Cat::VoiceCheckIn() {
	const char* myname = getName();
	cout << myname << " : �ɳ� �߳�ٿ�~" << endl;
}
void Cat::VoiceCheckOut() {
	const char* myname = getName();
	cout << myname << " : �ɳ� �������� ���� ~ " << endl;
}