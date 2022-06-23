#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "VendingMachine.h"
#include "Windows.h"

using namespace std;
void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine);

int main(void) {

	// ����� 4������ ���Ḧ �μ��� �޾����� ����ü�� �̿��Ͽ� �����ڸ� ����� ���°��� ��ǥ�� �ϰڴ�.
	VendingMachine Acid("coke", 1000, "cider", 1500, "sprite", 2000, "welchs", 2500);
	VendingMachine NonAcid("juice", 1000, "ricedrink", 1500, "water", 2000, "tea", 2500);

	// machine �� ���۷����� ����ϰ��� �Ҷ� ���� ó���� �ʱ�ȭ �ؾ� �ϹǷ� ���Ƿ� Acid �� �ʱ�ȭ ���־���.
	VendingMachine& machine = Acid;

	choice(Acid, NonAcid, machine);
	int menu = 0;
	int* p = &machine.GetStock();

	while (true) {

		system("cls");
		machine.ShowMenu();
		// �Ž����� ���� ��ȯ ������ ��� ����
		if (*(p + 0) == 0 &&
			*(p + 1) == 0 &&
			*(p + 2) == 0 &&
			*(p + 3) == 0) {
			cout << "<<<<<<<��� ��� ���� �Ǿ����ϴ�.>>>>>>>" << endl;
			machine.OutputMoney();
			Sleep(1000);
		}
		cout << "���Ͻô� �޴��� �Է��� �ּ���" << endl;
		cin >> menu;

		// �� �߰�
		if (menu == 1) {
			system("cls");
			machine.ShowMenu();
			machine.InputMoney();
			if (*(p + 0) == 0 &&
				*(p + 1) == 0 &&
				*(p + 2) == 0 &&
				*(p + 3) == 0) {
				machine.OutputMoney();
			}
			menu = 0;
		}

		// ���� ����
		if (menu == 2) {
			int temp;
			system("cls");
			machine.ShowMenu();
			// �Ž����� 
			// 1. �ּұݾ׿� ��ġ�� ���Ұ��
			// 2. ��� ��� �����Ǿ� �ǸŰ� �Ұ��� �Ѱ�� 
			temp = machine.Buy();
			Sleep(1000);
			menu = 0;
		}

		// �Ž����� (���� ����)
		if (menu == 3) {
			system("cls");
			machine.ShowMenu();
			machine.OutputMoney();
			menu = 0;
		}
	}

	return 0;
}

// vending �� �����ϴ°��� ����ڰ� �����ϴ°��̹Ƿ� ��ü�� �ƴ� main �Լ� �Ǵ� namespace �� user �� ���� ���� 
// �����ϴ� ���� ���� ����̶� �����Ѵ�.
void choice(VendingMachine& Acid, VendingMachine& NonAcid, VendingMachine& machine) {

	char choice[10];

	cout << "��ð� ���� ������ ������ ����ּ���[ź��: 1, ��ź��: 0]" << endl;
	cin >> choice;
	if (strcmp(choice, "ź��") == 0 || choice[0] == '1') {
		machine = Acid;
	}
	else if (strcmp(choice, "��ź��") == 0 || choice[0] == '0') {
		machine = NonAcid;
	}

}