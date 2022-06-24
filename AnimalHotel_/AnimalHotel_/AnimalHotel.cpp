#include "AnimalHotel.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

AnimalHotel::AnimalHotel(int myroomNum) : roomNum(myroomNum) {
	roomList = new int[myroomNum];

	//���� ����myroomNum
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
		cout << i + 1 << "��° �� : " << roomList[i] << " " << myname << endl;

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

	cout << "CHECK IN �� ��ȣ�� �Է� �� �ּ��� : ";
	cin >> roomNum;
	if (CustomerCheck(roomNum) == false) {
		cout << "������ ������ �����Դϱ�? : ";
		cin >> species;

		cout << "������ �̸��� �����Դϱ�? : ";
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
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		cout << roomNum << "��° �濡 checkin �Ͽ����ϴ�." << endl;
		room[roomNum - 1]->VoiceCheckIn();
	}
	else {
		cout << "�������� �̹� ���� �մϴ�." << endl;
	}
}

void AnimalHotel::CheckOut() {
	int temp = 0;

	cout << "üũ�ƿ� �Ϸ��� ���� ȣ���� �Է��Ͽ� �ֽʽÿ� : ";
	cin >> temp;

	if (CustomerCheck(temp) == true) {
		room[temp - 1]->VoiceCheckOut();
		roomList[temp - 1] = 0;
		delete room[temp - 1];
		room[temp - 1] = 0;
		cout << temp << "��° �濡 checkout �Ͽ����ϴ�." << endl;
	}
	else {
		cout << "�̹� ����ִ� ���Դϴ�." << endl;
	}
}

void AnimalHotel::CustomerInfo() {
	int temp = 0;

	cout << "Ȯ���ϰ� ���� ���� ȣ���� �Է��Ͽ� �ֽʽÿ�. :";
	cin >> temp;

	if (CustomerCheck(temp) == true) {
		const char* myname = room[temp - 1]->getName();
		cout << "���� �������� ���� : " << myname << endl;
	}
	else {
		cout << "�������� �������� �ʽ��ϴ�." << endl;
	}

}
