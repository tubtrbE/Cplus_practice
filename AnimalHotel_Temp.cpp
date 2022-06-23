#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void ShowMenu();

class Animal {
private:
	char* name;

public:

	Animal(char* myname) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
	}
	~Animal() {
		delete[] name;
	}
	const char* getName() const {
		return this->name;
	}
	void setName() {}

	virtual void VoiceCheckIn() {}
	virtual void VoiceCheckOut() {}
};

class Dog :public Animal {
private:
public:
	Dog(char* myname) : Animal(myname) {

	}
	virtual void VoiceCheckIn() {
		const char* myname = getName();
		cout << myname << " : 멍멍 잘놀다와~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : 멍멍 잘지내다 가요 ~ " << endl;
	}
};

class Cat :public Animal {
private:
public:
	Cat(char* myname) : Animal(myname) {

	}
	virtual void VoiceCheckIn() {
		const char* myname = getName();
		cout << myname << " : 냥냥 잘놀다와~" << endl;
	}
	virtual void VoiceCheckOut() {
		const char* myname = getName();
		cout << myname << " : 냥냥 잘지내다 가요 ~ " << endl;
	}
};

class AnimalHotel {
private:
	int roomNum;
	int* roomList;

public:

	AnimalHotel(int myroomNum) : roomNum(myroomNum) {
		roomList = new int[myroomNum];
		for (int i = 0; i < myroomNum; i++) {
			roomList[i] = 0;
		}
	}
	~AnimalHotel() {
		delete[] roomList;
	}

	void ShowList() const {
		for (int i = 0; i < roomNum; i++) {
			cout << i + 1 << "번째 방 : " << roomList[i] << endl;
		}
	}

	Animal* CheckIn(int num, Animal* animal) {
		roomList[num - 1] = 1;
		cout << num << "번째 방에 checkin 하였습니다." << endl;
		return animal;
	}

	void CheckOut(int num, Animal* animal) {
		roomList[num - 1] = 1;
		cout << num << "번째 방에 checkout 하였습니다." << endl;
	}

	void CustomerInformation(int num, Animal* animal) {
		const char* myname = animal->getName();
		animal = 0;
		cout << myname << endl;
	}
};

int main(void) {

	AnimalHotel hotel(8);
	Animal* animal[8];

	int roomNum = 0;
	char species[10] = {};
	char name[10] = {};
	int menu = 0;

	while (1) {

		cout << "메뉴를 입력 하시오" << endl;
		cin >> menu;

		//Check In
		if (menu == 1) {

			cout << "CHECK IN 방 번호를 입력 해 주세요." << endl;
			cin >> roomNum;

			cout << "동물의 종류는 무엇입니까?" << endl;
			cin >> species;

			cout << "동물의 이름은 무엇입니까?" << endl;
			cin >> name;

			if (strcmp(species, "dog") == 0) {
				animal[roomNum] = new Dog(name);
				hotel.CheckIn(roomNum, animal[roomNum]);
			}
			else if (strcmp(species, "cat") == 0) {
				animal[roomNum] = new Dog(name);
				hotel.CheckIn(roomNum, animal[roomNum]);
			}

			roomNum = 0;
			strcpy(species, "");
			strcpy(name, "");
		}

		//Check Out
		if (menu == 2) {
			int temp;
			cin >> temp;
			hotel.CheckOut(temp, animal[temp]);

		}

		//Show List
		if (menu == 3) {
			hotel.ShowList();
		}

		// Check Customer Info
		if (menu == 4) {
			int temp;
			cin >> temp;
			hotel.CustomerInformation(temp, animal[temp]);
		}
		if (menu == '0') break;

	}
	return 0;
}

void ShowMenu() {



}



