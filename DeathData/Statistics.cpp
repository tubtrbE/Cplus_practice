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
		
		cout << "도시명 : " << citys[i]->GetCity();
		cout << "  지역명 : " << citys[i]->GetDistrict() << "  사망숫자 : ";
		
		for (int j = 0; j < 11; j++) {
			cout << citys[i]->GetDeath()[j] << " ";
		}
		cout << endl;
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

		for (int i = 0; i < 230; i++) {
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city) {
					cout << "도시명 : " << citys[i]->GetCity();
					cout << "  지역명 : " << citys[i]->GetDistrict() << "  사망숫자 : ";
					for (int j = 0; j < 11; j++) {
						cout << citys[i]->GetDeath()[j] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	// 도시명 지역명 으로 검색하기
	else if (num == 2) {
		cout << "<<<<도시명 지역명 으로 검색하기>>>>" << endl;
		cout << "도시명을 입력하세요 : " ; cin >> city;
		cout << "지역명을 입력하세요 : "; cin >> district;

		for (int i = 0; i < 230; i++) {
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city &&
					citys[i]->GetDistrict() == district) {
					cout << "도시명 : " << citys[i]->GetCity();
					cout << "  지역명 : " << citys[i]->GetDistrict() << "  사망숫자 : ";
					for (int j = 0; j < 11; j++) {
						cout << citys[i]->GetDeath()[j] << " ";
					}
					cout << endl;
				}
			}
		}

	}
	// 도시명 지역명 사망위치으로 검색하기
	else if (num == 3) {
		cout << "<<<<도시명 지역명 사망지역으로 검색하기>>>>" << endl;
		cout << "도시명을 입력하세요 : "; cin >> city;
		cout << "지역명을 입력하세요 : "; cin >> district;
		cout << "사망지역을 입력하세요 : "; cin >> place;

		int placeNum = Place(place);

		if (placeNum < 11) {
			for (int i = 0; i < 230; i++) {
				if (citys[i] != 0) {
					if (citys[i]->GetCity() == city &&
						citys[i]->GetDistrict() == district) {
						cout << "도시명 : " << citys[i]->GetCity();
						cout << "  지역명 : " << citys[i]->GetDistrict() << "  사망지역 : ";
						cout << place << "  사망명수 : " << citys[i]->GetDeath()[placeNum] << " ";
						cout << endl;
					}
				}
			}
		}
		else if (placeNum == 11) {
			cout << "잘못된 입력입니다." << endl;
		}
	}
	else {
		cout << "잘못된 입력입니다." << endl;
	}
}

void Statistics::Sum() {
	int num = 0;
	cout << "           <<<통계방식을 선택해 주세요>>>"              << endl;
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
	int sum = 0;

	// 도시명 사망장소
	if (num == 1) {
		cout << "도시명을 입력하세요 : "; cin >> city;
		cout << "사망장소를 입력하세요 : "; cin >> place;
		
		for (int i = 0; i < 230; i++) {
			int placeNum = Place(place);
			
			if (citys[i] != 0) {
				if (citys[i]->GetCity() == city) {
					sum += citys[i]->GetDeath()[placeNum];
				}
			}
		}
		cout << "총합" << sum << endl;
	}
	// 전체 사망장소
	else if (num == 2) {
		cout << "사망장소를 입력하세요 : "; cin >> place;

		for (int i = 0; i < 230; i++) {
			int placeNum = Place(place);

			if (citys[i] != 0) {
				sum += citys[i]->GetDeath()[placeNum];
			}
		}
		cout << "총합 : " << sum << endl;
	}
	// 전체 각 사망장소
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
			cout << "총합 : " << sums[j] << endl;
		}

	}
	else {
		cout << "잘못된 입력입니다."<< endl;
	}
}


int Statistics::Place(string place) {

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

