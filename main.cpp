#include "pch.h"
#include <iostream>
#include <string>
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "FacultyMember.h"
#include "Library.h"
#include "Book.h"
using namespace std;


int main()
{
	// CREATING TEN BOOK OBJECTS
	Book *ptrBooks = new Book[10];

	ptrBooks[0] = Book(700, "Brave New World"); 
	ptrBooks[1] = Book(701, "Antifragile");
	ptrBooks[2] = Book(702, "Foundation");
	ptrBooks[3] = Book(703, "The Abyss Beyond Dreams");
	ptrBooks[4] = Book(704, "Night Without Stars");
	ptrBooks[5] = Book(705, "Wealth of Nations");
	ptrBooks[6] = Book(706, "Surely You're Joking Mr.Feynman");
	ptrBooks[7] = Book(707, "The Diamond Age");
	ptrBooks[8] = Book(708, "The Everything Store");
	ptrBooks[9] = Book(709, "Blindsight");

	// ADDING THESE BOOKS TO LIBRARY OBJECTS
	Library *ptrLibrary = new Library;
	int counter = 0;
	while (true)
	{	
		if (counter == 10) break;
		ptrLibrary->addBookToLibrary(ptrBooks[counter]);
		counter++;
	}

	// CREATING FIVE OBJECTS OF TYPE PERSON
	Person* ptrBorrowers = new Person[5];

	ptrBorrowers[0] = UndergraduateStudent(001, "Amelia Dalucci");
	ptrBorrowers[1] = GraduateStudent(002, "Sana Laketz");
	ptrBorrowers[2] = FacultyMember(003, "Moane Ibn Ahloukhl");
	ptrBorrowers[3] = GraduateStudent(004, "Anderson Wellington");
	ptrBorrowers[4] = GraduateStudent(005, "Adrien Racine");

	// ADDING THESE MEMBERS TO LIBRARY
	counter = 0;
	while (true)
	{
		if (counter == 5) break;
		ptrLibrary->addNewMember(&ptrBorrowers[counter]);
		counter++;
	}
	
	// LOANING BOOKS TO MEMBER
	ptrLibrary->addBookToMember(ptrBooks[0], ptrBorrowers[4].getBorrowerID(), 1, 10, 2019);
	ptrLibrary->addBookToMember(ptrBooks[1], ptrBorrowers[4].getBorrowerID(), 15, 10, 2019);
	ptrLibrary->addBookToMember(ptrBooks[2], ptrBorrowers[2].getBorrowerID(), 27, 10, 2019);
	ptrLibrary->addBookToMember(ptrBooks[3], ptrBorrowers[2].getBorrowerID(), 27, 10, 2019);
	ptrLibrary->addBookToMember(ptrBooks[4], ptrBorrowers[2].getBorrowerID(), 27, 10, 2019);


	ptrLibrary->addBookToMember(ptrBooks[5], ptrBorrowers[1].getBorrowerID(), 1, 9, 2019);
	ptrLibrary->addBookToMember(ptrBooks[6], ptrBorrowers[1].getBorrowerID(), 1, 9, 2019);
	ptrLibrary->addBookToMember(ptrBooks[7], ptrBorrowers[1].getBorrowerID(), 1, 9, 2019);
	ptrLibrary->addBookToMember(ptrBooks[8], ptrBorrowers[3].getBorrowerID(), 15, 9, 2019);
	ptrLibrary->addBookToMember(ptrBooks[9], ptrBorrowers[2].getBorrowerID(), 27, 9, 2019);
	
	cout << endl;
	
	ptrLibrary->removeBookFromMember(ptrBooks[0], ptrBorrowers[4].getBorrowerID());
	cout << endl;

	ptrLibrary->printCatalogSummary();
	cout << endl;
	ptrLibrary->printBorrowersSummary();
}
