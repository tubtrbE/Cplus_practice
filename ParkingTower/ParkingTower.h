#pragma once
#include "Car.h"
#include "Suv.h"
#include "Sedan.h"

class ParkingTower
{
private:

	//	the floor num of tower
	int floorNum;
	//�� ���������� �ִ� �ڵ���
	Car** parkingLot;
	// ���� ���ȴ��� �������� Ȯ�� (����(����) 0, ����(�ִ�) 1) 
	bool isDoor;
	// ���� ���� ���� �� �ִ��� Ȯ�� ((����) 0, (�ִ�) 1)
	bool isCar;
	// ���� ��ġ
	int board;

public:

	ParkingTower(int myfloor);
	~ParkingTower();
	//////////////////////////////////////////////////////////////////////////

	// ���� ���� ���
	void order();

	//  ������ �ڵ������� ���¸� �� �� �ִ� â
	void ParkingStatus();

	//  ������ �ڵ������� ���¸� �� �� �ִ� â
	bool ParkingSearch();

	// Ÿ�� ��ü�� �ַܼ� �� �� �ֵ��� ǥ���غ��Ҵ�.
	void ShowTower();

	// ����
	void InputCar();

	// ����
	void OutputCar();
	///////////////////////////////////////////////////////////////////////////

	// Ÿ���� ���� ���� ����
	void Door();

	// ������Ʈ ���� �� �ڵ����� ����
	void CarCheck();

	// ������ ������
	void BoardMove();

	///////////////////////////////////////////////////////////////////////////
};

