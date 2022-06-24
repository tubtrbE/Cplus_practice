#pragma once


class Car
{
private:
	int num;
	char* nameOwner;

public:
	Car(int myNum, char* myNameOwner);
	const char* getName() const;
	void SetName(char* mynameOwner);
	virtual ~Car();
	virtual void CarIn();
	virtual void CarOut();
};

