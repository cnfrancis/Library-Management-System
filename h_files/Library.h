#pragma once
#include "LinkedListB.h"
#include "LinkedListP.h"
class Library
{

private:
	LinkedListB catalog;
	LinkedListP borrowers;
	void printLoaneeBooks(Person* p) const;

public:
	Library();
	void addNewMember(Person*);
	void removeMember(Person*);
	void addBookToLibrary(Book&);

	void addBookToMember(Book& book, int personID, int day, int month, int year);
	void removeBookFromMember(Book&, int personID);

	void printBorrowersSummary() const;
	void printCatalogSummary() const;
	

	LinkedListB getBookList() const;
	~Library();
};

