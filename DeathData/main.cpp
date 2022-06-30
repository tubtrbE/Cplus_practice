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

	//input file stream 파일을 읽는다.
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

		// 한줄을 , 로 나누고 구분된 데이터를 cell 에 저장한다.
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
		cout << "메뉴를 입력해 주세요" << endl;
		cout << "1.검색" << endl;
		cout << "2.모든정보 보기" << endl;
		cout << "3.합" << endl;
		cout << "4.파일출력" << endl;

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
		// 기존에는 따로 check 함수를 만들어서 메뉴를 제어 했는데
		// cin.clear()과 
		// cin.ignore()을 활용하여 다른 키가 발생할 때에도 제어할 수 있게되었다.
		else {
			cout << "잘못된 입력입니다." << endl;
			menu = 0;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	return 0;
}
