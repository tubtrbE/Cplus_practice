#pragma once
#include "Car.h"
#include "Suv.h"
#include "Sedan.h"

class ParkingTower
{
private:

	//	the floor num of tower
	int floorNum;
	//각 주차공간에 있는 자동차
	Car** parkingLot;
	// 문이 열렸는지 닫혔는지 확인 (열림(없다) 0, 닫힘(있다) 1) 
	bool isDoor;
	// 보드 위에 차가 잘 있는지 확인 ((없다) 0, (있다) 1)
	bool isCar;
	// 보드 위치
	int board;

public:

	ParkingTower(int myfloor);
	~ParkingTower();
	//////////////////////////////////////////////////////////////////////////

	// 출차 입차 명령
	void order();

	//  주차된 자동차들의 상태를 볼 수 있는 창
	void ParkingStatus();

	//  주차된 자동차들의 상태를 볼 수 있는 창
	bool ParkingSearch();

	// 타워 자체를 콘솔로 볼 수 있도록 표현해보았다.
	void ShowTower();

	// 입차
	void InputCar();

	// 출차
	void OutputCar();
	///////////////////////////////////////////////////////////////////////////

	// 타워의 문을 열고 닫음
	void Door();

	// 스케이트 보드 위 자동차의 존재
	void CarCheck();

	// 보드의 움직임
	void BoardMove();

	///////////////////////////////////////////////////////////////////////////
};

