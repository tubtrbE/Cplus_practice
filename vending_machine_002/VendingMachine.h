#pragma once

class VendingMachine
{
private:

	// 음료가 4개로 고정 되어서 기계안에 4개로 선언해주었다. 
	// 다만 4개를 초과하는 경우를 고려 하지 않았으므로 다른 코드를 생각하여야 할 것이다.
	char* name[4];
	int price[4];
	int stock[4];
	int coin;

public:

	VendingMachine(const char* name1, int price1, const char* name2, int price2,
		const char* name3, int price3, const char* name4, int price4);

	int& GetStock();
	void ShowMenu();
	bool Buy();
	void InputMoney();
	void OutputMoney();
};

