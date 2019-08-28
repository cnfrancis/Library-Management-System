#pragma once
#include <string>
#include "Date.h"
#include "FacultyMember.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"

using namespace std;
class Book
{

private:
	int bookID;
	string bookTitle;
	bool isOnShelf;
	Date *ptrReturnDate;
	Person *ptrLoanee;


public:

	Book();
	Book(int, string);
	Book(const Book&);
	~Book();

	int getBookId() const;
	string getBookTitle() const;
	bool isBookAvailable() const;
	Date getReturnDate() const;
	
	void setReturnDate(int day, int month, int year);
	void setBookAvailability(bool);

	Person* getLoanee() const;
	void setPtrLoanee(Person&);
	void setPtrLoaneeToGround();


};

