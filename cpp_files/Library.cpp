#include "pch.h"
#include "Library.h"
#include <iostream>
#include <exception>

using namespace std;

void Library::printLoaneeBooks(Person* p) const
{
	Node *navB = nullptr;
	navB = catalog.getHead();
	/*try {
		cout << "CHECKING IF books.getLoanee works: " << navB->element->getLoanee() << endl;
	}
	
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	*/
	while (navB!=nullptr)
	{
		
		if (navB->element->getLoanee() != nullptr && navB->element->getLoanee()->getBorrowerID() == p->getBorrowerID())
		{
			cout << "\tID: " << navB->element->getBookId() << endl;
			cout << "\tTitle: " << navB->element->getBookTitle() << endl;
			cout << "\tReturn Date: ";
			navB->element->getReturnDate().printDate();

		}
		navB = navB->link;
	}
}

Library::Library()
{
}

void Library::addNewMember(Person *p)
{
	borrowers.addNewNode(p);
}

void Library::removeMember(Person *p)
{
	Node *nav1 = nullptr;
	nav1 = catalog.getHead();

	while (nav1)
	{
		if ( (nav1->element->getLoanee()) == p)
		{
			nav1->element->setPtrLoaneeToGround();
		}
		nav1 = nav1->link;
	}

	borrowers.removeNode(p->getBorrowerID());
	
}

void Library::addBookToLibrary(Book& b)
{
	catalog.addNewNode(b);

}

void Library::addBookToMember(Book & book, int personID, int day, int month, int year)
{

	NodeP *nav1 = nullptr;
	nav1 = borrowers.getHead();

		while (nav1!=nullptr)
		{
			if (nav1->element->getBorrowerID() == personID)
			{
				if (nav1->element->counter < nav1->element->getRentalLimit())
				{
					book.setPtrLoanee(*(nav1->element));
					book.setBookAvailability(false);
					book.setReturnDate(day, month, year);
					nav1->element->isCurrentlyRenting = true;
					nav1->element->counter++;
					break;
				}
			}
			nav1 = nav1->link;
		} 
	
}

void Library::removeBookFromMember(Book &book, int personID)
{
	book.setPtrLoaneeToGround();
	book.setBookAvailability(true);
	NodeP *nav1 = nullptr;
	nav1 = borrowers.getHead();

	while (nav1)
	{
		if (nav1->element->getBorrowerID() == personID)
		{
			nav1->element->counter--;
			break;
		}
		if(nav1->element->counter == 0) nav1->element->isCurrentlyRenting = false;

		nav1 = nav1->link;
	}
	

}

void Library::printBorrowersSummary() const
{

	NodeP *navigator = nullptr;
	navigator = borrowers.getHead();

	cout << "\tLibrary's Members" << endl;
	cout << endl;
	while (navigator)
	{
		switch (navigator->element->type)
		{
		case 1:
			cout << "\tUndergraduate Student ID: " << navigator->element->getBorrowerID() << endl;
			cout << "\tName: " << navigator->element->getBorrowerName() << endl;
			
			if (navigator->element->isCurrentlyRenting)
			{
				cout << "\tBooks Borrowed: " << navigator->element->counter << endl;
				printLoaneeBooks(navigator->element);
			}
			cout << endl;
			cout << endl;


			break;

		case 2:
			cout << "\tGraduate Student ID: " << navigator->element->getBorrowerID() << endl;
			cout << "\tName: " << navigator->element->getBorrowerName() << endl;
			if (navigator->element->isCurrentlyRenting)
			{
				cout << "\tBooks Borrowed: " << navigator->element->counter << endl;
				printLoaneeBooks(navigator->element);
			}
			cout << endl;
			cout << endl;
			break;

		case 3:
			cout << "\tFaculty Member ID: " << navigator->element->getBorrowerID() << endl;
			cout << "\tName: " << navigator->element->getBorrowerName() << endl;
			if (navigator->element->isCurrentlyRenting)
			{
				cout << "\tBooks Borrowed: " << navigator->element->counter << endl;
				printLoaneeBooks(navigator->element);
			}
			cout << endl;
			cout << endl;
			break;
		default:
			cout << "NOT WORKING.\n";

		} // END SWITCH
		navigator = navigator->link;
	}
} 

void Library::printCatalogSummary() const
{
	
	cout << "\tLibrary's Catalog" << endl;
	catalog.printBooksInfo();
	cout << endl;
}


LinkedListB Library::getBookList() const
{
	return catalog;
}

Library::~Library()
{
}