#include "Statistics.h"

Statistics::Statistics() : fileFlag(false) {

}

Statistics::~Statistics() {
	vCity.clear();
	vFile.clear();
}

void Statistics::InputCity(Citys* city) {
	vCity.push_back(city);
}

void Statistics::ShowCity() {


	string deathNum = "";

	if (fileFlag == 1) {
		// int �迭�� string ���� �ٽ� ��ȯ ���ֱ�
		for (int i = 0; i < vCity.size(); i++) {
			for (int j = 0; j < 11; j++) {
				deathNum += to_string(vCity.at(i)->GetDeath()[j]) + ",";
			}
			vFile.push_back(vCity.at(i)->GetCity() + "," + vCity.at(i)->GetDistrict() + "," + deathNum);
			deathNum = "";
		}
	}
	else {
		for (int i = 0; i < vCity.size(); i++) {
			cout << vCity.at(i)->GetCity() << "  ";
			cout << vCity.at(i)->GetDistrict() << "  ";
			for (int j = 0; j < 11; j++) {
				cout << vCity.at(i)->GetDeath()[j];
			}
			cout << endl;
		}
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
		for (int i = 0; i < vCity.size(); i++) {
			if (vCity.at(i)->GetCity() == city) {
				cout << vCity.at(i)->GetCity() << "  ";
				cout << vCity.at(i)->GetDistrict() << "  ";
				for (int j = 0; j < 11; j++) {
					cout << vCity.at(i)->GetDeath()[j];
				}
				cout << endl;
			}
		}
	}
	// ���ø� ������ ���� �˻��ϱ�
	else if (num == 2) {
		cout << "<<<<���ø� ������ ���� �˻��ϱ�>>>>" << endl;
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;
		cout << "�������� �Է��ϼ��� : "; cin >> district;

		for (int i = 0; i < vCity.size(); i++) {
			if (vCity.at(i)->GetCity() == city &&
				vCity.at(i)->GetDistrict() == district) {

				cout << vCity.at(i)->GetCity() << "  ";
				cout << vCity.at(i)->GetDistrict() << "  ";
				for (int j = 0; j < 11; j++) {
					cout << vCity.at(i)->GetDeath()[j];
				}
				cout << endl;
			}
		}
	}
	// ���ø� ������ �����ġ���� �˻��ϱ�
	else if (num == 3) {
		cout << "<<<<���ø� ������ ����������� �˻��ϱ�>>>>" << endl;
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;
		cout << "�������� �Է��ϼ��� : "; cin >> district;
		cout << "��������� �Է��ϼ��� : "; cin >> place;

		int placeNum = PlaceInt(place);

		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				if (vCity.at(i)->GetCity() == city &&
					vCity.at(i)->GetDistrict() == district) {
					cout << "���ø� : " << vCity.at(i)->GetCity();
					cout << "  ������ : " << vCity.at(i)->GetDistrict() << "  ������� =>";
					cout << place << "  ������ : " << vCity.at(i)->GetDeath()[placeNum] << " ";
					cout << endl;
				}
			}
		}
		else if (placeNum == 11) {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	else {
		num = 0;
		cin.clear();
		cin.ignore(1000, '\n');
	}

}

void Statistics::Sum() {
	int num = 0;
	cout << "           <<<������� ������ �ּ���>>>" << endl;
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
	int sum[11] = {};


	// ���ø� ������
	if (num == 1) {
		cout << "���ø��� �Է��ϼ��� : "; cin >> city;
		cout << "�����Ҹ� �Է��ϼ��� : "; cin >> place;
		int placeNum = PlaceInt(place);

		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				if (vCity.at(i)->GetCity() == city) {
					sum[0] += vCity.at(i)->GetDeath()[placeNum];
				}
			}
			cout << "���ø� : " << city << endl;
			cout << "��Ҹ� : " << place << endl;
			cout << "����� �� : " << sum[0] << " [��]" << endl;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	// ��ü ������
	else if (num == 2) {
		cout << "�����Ҹ� �Է��ϼ��� : "; cin >> place;
		int placeNum = PlaceInt(place);
		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				sum[0] += vCity.at(i)->GetDeath()[placeNum];
			}
			cout << "��Ҹ� : " << place << endl;
			cout << "����� �� : " << sum[0] << " [��]" << endl;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	// ��ü �� ������
	else if (num == 3) {
		for (int i = 0; i < vCity.size(); i++) {
			for (int j = 0; j < 11; j++) {
				sum[j] += vCity.at(i)->GetDeath()[j];
			}
		}
		cout << "�ͳξ� : " << sum[0] << endl;
		cout << "������ : " << sum[1] << endl;
		cout << "�������� : " << sum[2] << endl;
		cout << "������(����) : " << sum[3] << endl;
		cout << "��Ÿ���Ϸ� : " << sum[4] << endl;
		cout << "�����γ� : " << sum[5] << endl;
		cout << "����Ⱦ�ܺ��� : " << sum[6] << endl;
		cout << "�����κα� : " << sum[7] << endl;
		cout << "ö��ǳθ� : " << sum[8] << endl;
		cout << "��Ÿ : " << sum[9] << endl;
		cout << "�Ҹ� : " << sum[10] << endl;
	}
	else {
		cout << "�߸��� �Է��Դϴ�." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

void Statistics::MakeFile() {
	fileFlag = true;
	int menu;

	string fileName;
	cout << "���ϸ��� �Է��� �ּ���" << endl;
	cin >> fileName;

	//out file stream ������ �ٱ����� ��������. 
	ofstream myfile;
	myfile.open(fileName + ".csv");
	ShowCity();
	for (int i = 0; i < vFile.size(); i++) {
		myfile << vFile.at(i) + "\n";
	}

	myfile.close();
	// ���Ϸν� ����ϰ� ���������� ���� �����Ƿ� �Ҵ��� �������ش�.
	vFile.clear();
	fileFlag = false;
}

string Statistics::PlaceString(int place) {
	if (place == 0) {
		return "�ͳξ�";
	}
	else if (place == 1) {
		return "������";
	}
	else if (place == 2) {
		return "��������";
	}
	else if (place == 3) {
		return "������(����)";
	}
	else if (place == 4) {
		return "��Ÿ���Ϸ�";
	}
	else if (place == 5) {
		return "����Ⱦ�ܺ���";
	}
	else if (place == 6) {
		return "�����κα�";
	}
	else if (place == 7) {
		return "ö��ǳθ�";
	}
	else if (place == 8) {
		return "��Ÿ";
	}
	else if (place == 9) {
		return "�Ҹ�";
	}
	else {
		return "�߸��Է� �ϼ̽��ϴ�.";
	}

}

int Statistics::PlaceInt(string place) {

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

