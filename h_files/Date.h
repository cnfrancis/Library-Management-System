/* Date.h*/
#pragma once
#include <string>
#ifndef DATE_H_
#define DATE_H_
using namespace std;

class Date
{
public:
	Date();
	void printDate() const; // print date to the screen
	void setDate(int, int, int); // set the date and check if invalid date
	string getMonth(); // return month in letters
	int getDifference(int[], int[], int[]); // return the differenc between two given dates
	~Date();

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_H_*/ 

