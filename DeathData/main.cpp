#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Statistics.h"

void CheckMenu();
using namespace std;

int main()
{
	Statistics status;
	int row = 0;

	//input file stream 파일을 읽는다.
	ifstream  data("ANSIData.csv");
	string line;
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
				num[column-2] = stoi(cell);
			}

			column++;
			if (column == 12) {
				Citys* temp = new Citys(city, district, num);
				status.InputCity(temp);
				row++;
				for (int i = 0; i < 13; i++) {
					num[i] = 0;
				}
			}
		}
	}
	int menu = 0;

	while (1)
	{
		system("cls");
		cout << "메뉴를 입력해 주세요" << endl;
		cout << "1.검색" << endl;
		cout << "2.모든정보 보기" << endl;
		cout << "3.합" << endl;

		cin >> menu;

		if (menu == 1) {
			status.Search();
			CheckMenu();
		}
		else if (menu == 2) {
			status.ShowCity();
			CheckMenu();
		}
		else if (menu == 3) {
			status.Sum();
			CheckMenu();
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}
	return 0;
}

void CheckMenu() {
	char temp[5] = {};
	cout << "###메뉴로 돌아려면 문자(영어) 나 숫자 입력하세요###" << endl;
	cin >> temp;
}