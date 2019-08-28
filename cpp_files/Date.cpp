#include "pch.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}


void Date::setDate(int d, int m, int y) {
	day = ((d > 0 && d < 32) ? d : -1);
	month = ((m > 0 && m < 13) ? m : -1);
	year = ((y >= 0) ? y : -1);

	if (day == -1 || month == -1 || year == -1)
	{
		cout << "INVALIDE DATE" << endl;
		cout << "ERROR: -1" << endl;
		cout << "DAY: " << day << "\nMONTH: " << month
			<< "\nYEAR: " << year << endl;
	}

}

string Date::getMonth()
{
	switch (month)
	{
		case 1:
			return "January";
			break;
		case 2:
			return "Febuary";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;

		default:
			cout << "INVALID DATE";
			break;
	}
}

int Date::getDifference(int d[], int m[], int y[])
{
	int d1Diff{ 0 }, d2Diff{ 0 }, d3Diff{ 0 };

	d1Diff = 365 * abs(y[0] - y[1]); 
	d2Diff = 31 * abs(m[0] - m[1]);
	d3Diff = abs(d[0] - d[1]);

	return d1Diff + d2Diff + d3Diff;
}
void Date::printDate() const
{
	cout << month << "/" << day << "/" << year << "\n";
}
Date::~Date()
{
}
