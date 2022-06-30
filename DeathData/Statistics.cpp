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
		// int 배열을 string 으로 다시 변환 해주기
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

	cout << "           <<<검색방식을 선택해 주세요>>>" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [1] 도시명 만으로 검색하기                       ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] 도시명 지역명 으로 검색하기                  ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] 도시명 지역명 사망장소로 검색하기            ||" << endl;
	cout << "||==================================================||" << endl;

	cin >> num;
	string city = "";
	string district = "";
	string place = "";

	// 도시명 만으로 검색하기
	if (num == 1) {
		cout << "<<<<도시명 만으로 검색하기>>>>" << endl;
		cout << "도시명을 입력하세요 : "; cin >> city;
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
	// 도시명 지역명 으로 검색하기
	else if (num == 2) {
		cout << "<<<<도시명 지역명 으로 검색하기>>>>" << endl;
		cout << "도시명을 입력하세요 : "; cin >> city;
		cout << "지역명을 입력하세요 : "; cin >> district;

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
	// 도시명 지역명 사망위치으로 검색하기
	else if (num == 3) {
		cout << "<<<<도시명 지역명 사망지역으로 검색하기>>>>" << endl;
		cout << "도시명을 입력하세요 : "; cin >> city;
		cout << "지역명을 입력하세요 : "; cin >> district;
		cout << "사망지역을 입력하세요 : "; cin >> place;

		int placeNum = PlaceInt(place);

		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				if (vCity.at(i)->GetCity() == city &&
					vCity.at(i)->GetDistrict() == district) {
					cout << "도시명 : " << vCity.at(i)->GetCity();
					cout << "  지역명 : " << vCity.at(i)->GetDistrict() << "  사망지역 =>";
					cout << place << "  사망명수 : " << vCity.at(i)->GetDeath()[placeNum] << " ";
					cout << endl;
				}
			}
		}
		else if (placeNum == 11) {
			cout << "잘못된 입력입니다." << endl;
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
	cout << "           <<<통계방식을 선택해 주세요>>>" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [1] 도시명 사망장소 통계                         ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [2] 각 사망장소별 통계                           ||" << endl;
	cout << "||==================================================||" << endl;
	cout << "|| [3] 전체 사망 장소 별 통계                       ||" << endl;
	cout << "||==================================================||" << endl;
	cin >> num;

	string city = "";
	string district = "";
	string place = "";
	int sum[11] = {};


	// 도시명 사망장소
	if (num == 1) {
		cout << "도시명을 입력하세요 : "; cin >> city;
		cout << "사망장소를 입력하세요 : "; cin >> place;
		int placeNum = PlaceInt(place);

		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				if (vCity.at(i)->GetCity() == city) {
					sum[0] += vCity.at(i)->GetDeath()[placeNum];
				}
			}
			cout << "도시명 : " << city << endl;
			cout << "장소명 : " << place << endl;
			cout << "사망자 수 : " << sum[0] << " [명]" << endl;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}
	// 전체 사망장소
	else if (num == 2) {
		cout << "사망장소를 입력하세요 : "; cin >> place;
		int placeNum = PlaceInt(place);
		if (placeNum < 11) {
			for (int i = 0; i < vCity.size(); i++) {
				sum[0] += vCity.at(i)->GetDeath()[placeNum];
			}
			cout << "장소명 : " << place << endl;
			cout << "사망자 수 : " << sum[0] << " [명]" << endl;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
	}
	// 전체 각 사망장소
	else if (num == 3) {
		for (int i = 0; i < vCity.size(); i++) {
			for (int j = 0; j < 11; j++) {
				sum[j] += vCity.at(i)->GetDeath()[j];
			}
		}
		cout << "터널안 : " << sum[0] << endl;
		cout << "교량위 : " << sum[1] << endl;
		cout << "고가도로위 : " << sum[2] << endl;
		cout << "하차도(도로) : " << sum[3] << endl;
		cout << "기타단일로 : " << sum[4] << endl;
		cout << "교차로내 : " << sum[5] << endl;
		cout << "차로횡단보도 : " << sum[6] << endl;
		cout << "교차로부근 : " << sum[7] << endl;
		cout << "철길건널목 : " << sum[8] << endl;
		cout << "기타 : " << sum[9] << endl;
		cout << "불명 : " << sum[10] << endl;
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

void Statistics::MakeFile() {
	fileFlag = true;
	int menu;

	string fileName;
	cout << "파일명을 입력해 주세요" << endl;
	cin >> fileName;

	//out file stream 파일을 바깥으로 내보낸다. 
	ofstream myfile;
	myfile.open(fileName + ".csv");
	ShowCity();
	for (int i = 0; i < vFile.size(); i++) {
		myfile << vFile.at(i) + "\n";
	}

	myfile.close();
	// 파일로써 출력하고 난다음에는 쓸모 없으므로 할당을 제거해준다.
	vFile.clear();
	fileFlag = false;
}

string Statistics::PlaceString(int place) {
	if (place == 0) {
		return "터널안";
	}
	else if (place == 1) {
		return "교량위";
	}
	else if (place == 2) {
		return "고가도로위";
	}
	else if (place == 3) {
		return "하차도(도로)";
	}
	else if (place == 4) {
		return "기타단일로";
	}
	else if (place == 5) {
		return "차로횡단보도";
	}
	else if (place == 6) {
		return "교차로부근";
	}
	else if (place == 7) {
		return "철길건널목";
	}
	else if (place == 8) {
		return "기타";
	}
	else if (place == 9) {
		return "불명";
	}
	else {
		return "잘못입력 하셨습니다.";
	}

}

int Statistics::PlaceInt(string place) {

	if (place == "터널안") {
		return 0;
	}
	else if (place == "교량위") {
		return 1;
	}
	else if (place == "고가도로위") {
		return 2;
	}
	else if (place == "하차도" || place == "하차도(도로)") {
		return 3;
	}
	else if (place == "기타단일로") {
		return 4;
	}
	else if (place == "교차로내") {
		return 5;
	}
	else if (place == "차로횡단보도") {
		return 6;
	}
	else if (place == "교차로부근") {
		return 7;
	}
	else if (place == "철길건널목") {
		return 8;
	}
	else if (place == "기타") {
		return 9;
	}
	else if (place == "불명") {
		return 10;
	}
	else {
		return 11;
	}
}

