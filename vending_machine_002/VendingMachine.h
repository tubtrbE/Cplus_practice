#pragma once

class VendingMachine
{
private:

	char* name[4];
	int price[4];
	int stock[4];
	int coin;

public:

	VendingMachine(const char* name1, int price1, const char* name2, int price2,
		const char* name3, int price3, const char* name4, int price4);

	void ShowMenu();
	void Buy();
	void InputMoney();
	void OutputMoney();
};

