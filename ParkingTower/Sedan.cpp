#include "Sedan.h"
#include <iostream>

using namespace std;

Sedan::Sedan(int myNum, char* myNameOwner) : Car(myNum, myNameOwner) {

}
void Sedan::CarOut() {
	cout << "¶Ù¶Ù»§»§ Sedan ³ª°©´Ï´Ù ~" << endl;
}
void Sedan::CarIn() {
	cout << "¶Ù¶Ù»§»§ Sedan µé¾î¿É´Ï´Ù ~" << endl;

}