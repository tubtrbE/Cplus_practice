#include "Statistics.h"

Statistics::Statistics() {

	citys = new Citys* [230];
	for (int i = 0; i < 230; i++) {
		citys[i] = 0;
	}

}

Statistics::~Statistics() {

}

void Statistics::InputCity(Citys* city) {

	for (int i = 0; i < 230; i++) {
		if (citys[i] == 0) {
			citys[i] = city;
			break;
		}
	}

}

void Statistics::ShowCity() {
	for (int i = 0; i < 230; i++) {
		
		cout << "���ø� : " << citys[i]->GetCity();
		cout << "  ������ : " << citys[i]->GetDistrict() << "  ������� : ";
		
		for (int j = 0; j < 11; j++) {
			cout << citys[i]->GetDeath()[j] << " ";
		}
		cout << endl;
	}
}

void Statistics::Search() {
	int num = 0;

	cout << "           <<<�˻������ ������ �ּ���>>>" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [1] ���ø� ������ �˻��ϱ�                       ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] ���ø� ������ ���� �˻��ϱ�                  ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] ���ø� ������ �����ҷ� �˻��ϱ�            ||" << endl;
	cout << "||==================================================||" << endl;
	cin >> num;


	string city = "";
	string district = "";
	string place = "";

	// ���ø� ������ �˻��ϱ�
	if (num == 1) {
		cout << "<<<<���ø� ������ �˻��ϱ�>>>>" << endl;
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;

		for (int i = 0; i < 230; i++) {
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city) {
					cout << "���ø� : " << citys[i]->GetCity();
					cout << "  ������ : " << citys[i]->GetDistrict() << "  ������� : ";
					for (int j = 0; j < 11; j++) {
						cout << citys[i]->GetDeath()[j] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	// ���ø� ������ ���� �˻��ϱ�
	else if (num == 2) {
		cout << "<<<<���ø� ������ ���� �˻��ϱ�>>>>" << endl;
		cout << "���ø��� �Է��ϼ��� : " ; cin >> city;
		cout << "�������� �Է��ϼ��� : "; cin >> district;

		for (int i = 0; i < 230; i++) {
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city &&
					citys[i]->GetDistrict() == district) {
					cout << "���ø� : " << citys[i]->GetCity();
					cout << "  ������ : " << citys[i]->GetDistrict() << "  ������� : ";
					for (int j = 0; j < 11; j++) {
						cout << citys[i]->GetDeath()[j] << " ";
					}
					cout << endl;
				}
			}
		}

	}
	// ���ø� ������ �����ġ���� �˻��ϱ�
	else if (num == 3) {
		cout << "<<<<���ø� ������ ����������� �˻��ϱ�>>>>" << endl;
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;
		cout << "�������� �Է��ϼ��� : "; cin >> district;
		cout << "��������� �Է��ϼ��� : "; cin >> place;

		int placeNum = Place(place);

		if (placeNum < 11) {
			for (int i = 0; i < 230; i++) {
				if (citys[i] != 0) {
					if (citys[i]->GetCity() == city &&
						citys[i]->GetDistrict() == district) {
						cout << "���ø� : " << citys[i]->GetCity();
						cout << "  ������ : " << citys[i]->GetDistrict() << "  ������� : ";
						cout << place << "  ������ : " << citys[i]->GetDeath()[placeNum] << " ";
						cout << endl;
					}
				}
			}
		}
		else if (placeNum == 11) {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	else {
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
}

void Statistics::Sum() {
	int num = 0;
	cout << "           <<<������� ������ �ּ���>>>"              << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [1] ���ø� ������ ���                         ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] �� �����Һ� ���                           ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] ��ü ��� ��� �� ���                       ||" << endl;
	cout << "||==================================================||" << endl;
	cin >> num;

	string city = "";
	string district = "";
	string place = "";
	int sum = 0;

	// ���ø� ������
	if (num == 1) {
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;
		cout << "�����Ҹ� �Է��ϼ��� : "; cin >> place;
		
		for (int i = 0; i < 230; i++) {
			int placeNum = Place(place);
			
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city) {
					sum += citys[i]->GetDeath()[placeNum];
				}
			}
		}
		cout << "����" << sum << endl;
	}
	// ��ü ������
	else if (num == 2) {
		cout << "�����Ҹ� �Է��ϼ��� : "; cin >> place;

		for (int i = 0; i < 230; i++) {
			int placeNum = Place(place);

			if (citys[i] != 0) {
				sum += citys[i]->GetDeath()[placeNum];
			}
		}
		cout << "���� : " << sum << endl;
	}
	// ��ü �� ������
	else if (num == 3) {
		int sums[12] = {};

		for (int i = 0; i < 230; i++) {
			for (int j = 0; j < 11; j++) {
				if (citys[i] != 0) {
					sums[j] += citys[i]->GetDeath()[j];
				}
			}
		}
		for (int j = 0; j < 11; j++) {
			cout << "���� : " << sums[j] << endl;
		}

	}
	else {
		cout << "�߸��� �Է��Դϴ�."<< endl;
	}
}


int Statistics::Place(string place) {

	if (place == "�ͳξ�") {
		return 0;
	}
	else if (place == "������") {
		return 1;
	}
	else if (place == "��������") {
		return 2;
	}
	else if (place == "������" || place == "������(����)") {
		return 3;
	}
	else if (place == "��Ÿ���Ϸ�") {
		return 4;
	}
	else if (place == "�����γ�") {
		return 5;
	}
	else if (place == "����Ⱦ�ܺ���") {
		return 6;
	}
	else if (place == "�����κα�") {
		return 7;
	}
	else if (place == "ö��ǳθ�") {
		return 8;
	}
	else if (place == "��Ÿ") {
		return 9;
	}
	else if (place == "�Ҹ�") {
		return 10;
	}
	else {
		return 11;
	}
}

