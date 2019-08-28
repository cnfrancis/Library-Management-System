//
//  Borrower.cpp
//  ASSIGNMENT 4 SUMMER
//
//  Created by Kelly Acoca on 2019-08-01.
//  Copyright © 2019 Kelly Acoca. All rights reserved.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


Person::Person()
{
	borrowerID = 0;
	borrowerName = "";

}
Person::Person(int id, string name)
{
	borrowerID = id;
	borrowerName = name;
}

//copy constructor
Person::Person(const Person& p)
{
	borrowerID = p.getBorrowerID();
	borrowerName = p.getBorrowerName();
}

int Person::getBorrowerID() const
{
	return borrowerID;
}

string Person::getBorrowerName() const
{
	return borrowerName;
}

int Person::getRentalLimit() const
{
	return rentalLimit;
}

int Person::getTimeLimit() const
{
	return maxWeeksLimit;
}


//virtual destrcutor
Person::~Person()
{

}
