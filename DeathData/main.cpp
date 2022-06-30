#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Statistics.h"

using namespace std;

int main()
{

	Statistics status;
	int row = 0;

	//input file stream ������ �д´�.
	ifstream  data("ANSIData.csv");
	string line;

	vector<Citys*> v;

	while (std::getline(data, line))
	{
		string city = {};
		string district = {};
		int num[20] = {};
		int column = 0;

		stringstream  lineStream(line);
		string        cell;

		// ������ , �� ������ ���е� �����͸� cell �� �����Ѵ�.
		while (std::getline(lineStream, cell, ','))
		{

			if (cell == "-") {
				cell = "0";
			}
			if (column == 0) {
				city = cell;
			}
			else if (column == 1) {
				district = cell;
			}
			else {
				num[column - 2] = stoi(cell);
			}

			column++;
			if (column == 12) {
				Citys* temp = new Citys(city, district, num);
				status.InputCity(temp);
				v.push_back(temp);
				row++;
				for (int i = 0; i < 13; i++) {
					num[i] = 0;
				}
			}
		}
	}
	int menu;
	while (1)
	{
		system("cls");
		cout << "�޴��� �Է��� �ּ���" << endl;
		cout << "1.�˻�" << endl;
		cout << "2.������� ����" << endl;
		cout << "3.��" << endl;
		cout << "4.�������" << endl;

		cin >> menu;

		if (menu == 1) {
			status.Search();
			system("pause");
		}
		else if (menu == 2) {
			status.ShowCity();
			system("pause");
		}
		else if (menu == 3) {
			status.Sum();
			system("pause");
		}
		else if (menu == 4) {
			status.MakeFile();
			system("pause");
		}
		// �������� ���� check �Լ��� ���� �޴��� ���� �ߴµ�
		// cin.clear()�� 
		// cin.ignore()�� Ȱ���Ͽ� �ٸ� Ű�� �߻��� ������ ������ �� �ְԵǾ���.
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			menu = 0;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	return 0;
}
