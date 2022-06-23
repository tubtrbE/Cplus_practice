#pragma once

class VendingMachine
{
private:

	// ���ᰡ 4���� ���� �Ǿ ���ȿ� 4���� �������־���. 
	// �ٸ� 4���� �ʰ��ϴ� ��츦 ��� ���� �ʾ����Ƿ� �ٸ� �ڵ带 �����Ͽ��� �� ���̴�.
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

