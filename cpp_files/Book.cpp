#include "pch.h"
#include "Book.h"
#include <iostream>
#include <exception>
using namespace std;


Book::Book()
{
	bookID = 0;
	bookTitle = "";
	isOnShelf = true;
	ptrReturnDate = new Date();
	ptrLoanee = nullptr;
}

Book::Book(int id, string n)
{
	bookID = id;
	bookTitle = n;
	isOnShelf = true;
	ptrReturnDate = new Date();
	ptrLoanee = nullptr;



}


Book::Book(const Book& b)
{
	bookID = b.getBookId();
	bookTitle = b.getBookTitle();
	isOnShelf = b.isBookAvailable();
	*ptrReturnDate = b.getReturnDate();
}

int Book::getBookId() const
{
	return bookID;
}

string Book::getBookTitle() const
{
	return bookTitle;
}

bool Book::isBookAvailable() const
{
	return isOnShelf;
}

Date Book::getReturnDate() const
{
	return *ptrReturnDate;
}

Person* Book::getLoanee() const
{
	try {

		return ptrLoanee;
	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void Book::setPtrLoanee(Person& p)
{
	//cout << "LOADING ADDRESS OF BORROWER INTO POINTER IN BOOK OBJECT.(Book.cpp/setPtrLoanee)" << endl;
	ptrLoanee = &p;
	cout << ptrLoanee->getBorrowerName() << " has borrowed the book " << bookTitle << endl;
}

void Book::setPtrLoaneeToGround()
{
	//cout << "POINTER TO GROUND. (Book.cpp/setPtrLoaneeToGround)" << endl;
	cout << ptrLoanee->getBorrowerName() << " has returned the book " << bookTitle << endl;
	ptrLoanee = nullptr;
}


void Book::setReturnDate(int d, int m, int y)
{
	ptrReturnDate->setDate(d, m, y);
}

void Book::setBookAvailability(bool flagVal)
{
	isOnShelf = flagVal;
}

Book::~Book() {
}
