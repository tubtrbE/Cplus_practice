#include "Suv.h"
#include <iostream>

using namespace std;

Suv::Suv(int myNum, char* myNameOwner) : Car(myNum, myNameOwner){

}
void Suv::CarOut() {
	cout << "�θ��θ� Suv �����ϴ� ~" << endl;
}
void Suv::CarIn() {
	cout << "�θ��θ� Suv ���ɴϴ� ~" << endl;

}