#include "Sedan.h"
#include <iostream>

using namespace std;

Sedan::Sedan(int myNum, char* myNameOwner) : Car(myNum, myNameOwner) {

}
void Sedan::CarOut() {
	cout << "�ٶٻ��� Sedan �����ϴ� ~" << endl;
}
void Sedan::CarIn() {
	cout << "�ٶٻ��� Sedan ���ɴϴ� ~" << endl;

}