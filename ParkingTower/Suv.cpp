#include "Suv.h"
#include <iostream>

using namespace std;

Suv::Suv(int myNum, char* myNameOwner) : Car(myNum, myNameOwner){

}
void Suv::CarOut() {
	cout << "ºÎ¸ªºÎ¸ª Suv ³ª°©´Ï´Ù ~" << endl;
}
void Suv::CarIn() {
	cout << "ºÎ¸ªºÎ¸ª Suv µé¾î¿É´Ï´Ù ~" << endl;

}