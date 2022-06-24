#include <iostream>
//#include "Car.h"
void ShowTower();
using namespace std;

int main(void) {

	ShowTower();

	return 0;
}

void ShowTower() {

	char floor[50] = "===========================";
	char O[5][50] = { 
		"||     =============     || ",
		"||    ||           ||    || ",
		"||    ||           ||    || ",
		"||    ||           ||    || ",
		"||     =============     || "
	};

	char X[5][50] = {
		"||                       || ",
		"||                       || ",
		"||                       || ",
		"||                       || ",
		"||                       || ",
	};


	cout << floor << endl;
	for (int i = 0; i < 5; i++) {
		cout << O[i] << endl;
	}
	cout << floor << endl;
	for (int i = 0; i < 5; i++) {
		cout << O[i] << endl;
	}
	cout << floor << endl;
	for (int i = 0; i < 5; i++) {
		cout << O[i] << endl;
	}
	cout << floor << endl;
	for (int i = 0; i < 5; i++) {
		cout << O[i] << endl;
	}
	cout << floor << "   ======================="<< endl;


}