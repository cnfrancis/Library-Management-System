#include "pch.h"
#include "GraduateStudent.h"
#include <iostream>
using namespace std;


GraduateStudent::GraduateStudent()
{
	maxWeeksLimit = 6;
	rentalLimit = 20;
	type = 2;
}

GraduateStudent::GraduateStudent(int id, string name) : Person(id, name)
{
	maxWeeksLimit = 6;
	rentalLimit = 20;
	type = 2;
}





GraduateStudent::~GraduateStudent()
{
}
