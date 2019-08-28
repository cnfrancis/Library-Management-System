#pragma once
#include "pch.h"
#include <string>
using namespace std;

class Person
{

private:
	int borrowerID;
	string borrowerName;
protected:
	int rentalLimit;
	int maxWeeksLimit;

public:
	int type = 0;
	int counter = 0;
	bool isCurrentlyRenting = false;
	Person();
	Person(int, string);
	Person(const Person&);

	int getBorrowerID() const;
	string getBorrowerName() const;
	int getRentalLimit() const;
	int getTimeLimit() const;

	~Person();

};

