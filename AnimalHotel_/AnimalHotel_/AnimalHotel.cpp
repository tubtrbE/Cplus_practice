#include "AnimalHotel.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

AnimalHotel::AnimalHotel(int myroomNum) : roomNum(myroomNum) {
	roomList = new int[myroomNum];

	//방의 갯수myroomNum
	room = new Animal * [myroomNum];

	for (int i = 0; i < myroomNum; i++) {
		roomList[i] = 0;
	}
}

AnimalHotel::~AnimalHotel() {
	delete[] roomList;
	delete[] room;
}

void AnimalHotel::ShowList() const {

	for (int i = 0; i < roomNum; i++) {
		const char* myname = " ";

		if (roomList[i] == 1) {
			myname = room[i]->getName();
		}
		cout << i + 1 << "번째 방 : " << roomList[i] << " " << myname << endl;

	}
}

bool AnimalHotel::CustomerCheck(int num) {
	if (roomList[num - 1] == 1) {
		return true;
	}
	else {
		return false;
	}
}

void AnimalHotel::CheckIn() {

	int roomNum = 0;
	char species[10] = {};
	char name[10] = {};

	cout << "CHECK IN 방 번호를 입력 해 주세요 : ";
	cin >> roomNum;
	if (CustomerCheck(roomNum) == false) {
		cout << "동물의 종류는 무엇입니까? : ";
		cin >> species;

		cout << "동물의 이름은 무엇입니까? : ";
		cin >> name;
		if (strcmp(species, "dog") == 0) {
			room[roomNum - 1] = new Dog(name);
			roomList[roomNum - 1] = 1;
		}
		else if (strcmp(species, "cat") == 0) {
			room[roomNum - 1] = new Cat(name);
			roomList[roomNum - 1] = 1;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
		cout << roomNum << "번째 방에 checkin 하였습니다." << endl;
		room[roomNum - 1]->VoiceCheckIn();
	}
	else {
		cout << "투숙객이 이미 존재 합니다." << endl;
	}
}

void AnimalHotel::CheckOut() {
	int temp = 0;

	cout << "체크아웃 하려는 방의 호실을 입력하여 주십시요 : ";
	cin >> temp;

	if (CustomerCheck(temp) == true) {
		room[temp - 1]->VoiceCheckOut();
		roomList[temp - 1] = 0;
		delete room[temp - 1];
		room[temp - 1] = 0;
		cout << temp << "번째 방에 checkout 하였습니다." << endl;
	}
	else {
		cout << "이미 비어있는 방입니다." << endl;
	}
}

void AnimalHotel::CustomerInfo() {
	int temp = 0;

	cout << "확인하고 싶은 방의 호실을 입력하여 주십시요. :";
	cin >> temp;

	if (CustomerCheck(temp) == true) {
		const char* myname = room[temp - 1]->getName();
		cout << "현재 투숙중인 고객님 : " << myname << endl;
	}
	else {
		cout << "투숙객이 존재하지 않습니다." << endl;
	}

}
