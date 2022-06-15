#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "VendingMachine.h"
#include "Windows.h"

using namespace std;
void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine);


int main(void) {

	VendingMachine Acid("coke", 1000, "cider", 1500, "sprite", 2000, "welchs", 2500);
	VendingMachine NonAcid("juice", 1000, "ricedrink", 1500, "water", 2000, "tea", 2500);
	VendingMachine& machine = Acid;

	choice(Acid, NonAcid, machine);
	int menu = 0;

	while (true) {

		system("cls");
		machine.ShowMenu();
		cin >> menu;

		// µ∑ √ﬂ∞°
		if (menu == 1) {
			system("cls");
			machine.ShowMenu();
			machine.InputMoney();
			menu = 0;
		}

		// ¿Ω∑· ±∏∏≈
		if (menu == 2) {
			system("cls");
			machine.ShowMenu();
			machine.Buy();
			Sleep(1000);
			menu = 0;
		}

		// ∞≈Ω∫∏ßµ∑
		if (menu == 3) {
			system("cls");
			machine.ShowMenu();
			machine.OutputMoney();
			menu = 0;
		}
	}

	return 0;
}

void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine) {

	char choice[10];

	cout << "µÂΩ√∞Ì ΩÕ¿∫ ¿Ω∑·¿« ¡æ∑˘∏¶ ∞Ò∂Û¡÷ººø‰[≈∫ªÍ: 1, ∫Ò≈∫ªÍ: 0]" << endl;
	cin >> choice;
	if (strcmp(choice, "≈∫ªÍ") == 0 || choice[0] == '1') {
		machine = Acid;
	}
	else if (strcmp(choice, "∫Ò≈∫ªÍ") == 0 || choice[0] == '0') {
		machine = NonAcid;
	}

}