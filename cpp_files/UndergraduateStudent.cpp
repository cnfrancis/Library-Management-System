#include "pch.h"
#include "UndergraduateStudent.h"
#include <iostream>
using namespace std;


UndergraduateStudent::UndergraduateStudent() : Person()
{
	rentalLimit = 10;
	maxWeeksLimit = 4;
	type = 1;
}

UndergraduateStudent::UndergraduateStudent(int id, string name) : Person(id,name)
{
	rentalLimit = 10;
	maxWeeksLimit = 4;
	type = 1;
}


UndergraduateStudent::~UndergraduateStudent()
{
}
