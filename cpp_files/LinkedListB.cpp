// REMEMBER TO USE POINTER FOR THE ELEMENT IN STRUCT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "pch.h"
#include "LinkedListB.h"
#include <iostream>

using namespace std;


LinkedListB::LinkedListB()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedListB::addNewNode(Book &x) {
	Node *temp = new Node;
	temp->element = &x;
	temp->link = nullptr;

	if (head == nullptr) {
		head = temp; // assign address of temp to head
		tail = temp; // assign address of temp to tail
		
	}

	else { // If list is not empty i.e if head not equal to NULL
		tail->link = temp; // Assign the address of current temp to pointer link of previous object
		tail = (*tail).link; // Assign the address of what the link is pointing to to tail
	}
}

void LinkedListB::removeNode(int id)
{
	Node *navigator{ nullptr };
	Node *previous{ nullptr };

	navigator = this->getHead();
	previous = navigator;

	while (navigator)
	{
		if (navigator->element->getBookId() == id)
		{
			previous->link = navigator->link;
			navigator = nullptr;
			break;
		}
		else {
			previous = navigator;
			navigator = navigator->link;
		}
	} // END WHILE

}

void LinkedListB::printBooksInfo() const
{
	Node *navigator{ nullptr };
	navigator = head;
	cout << endl;
	while (navigator)
	{
		cout << "\tBook ID: " << navigator->element->getBookId() << endl;
		cout << "\tBook Name: " << navigator->element->getBookTitle() << endl;
		if ( (navigator->element->isBookAvailable()) == false)
		{
			cout << "\tBook is not on shelf." << endl;
			cout << "\tExpected return date: ";
			navigator->element->getReturnDate().printDate();
			cout << "\tLoaned to: " << navigator->element->getLoanee()->getBorrowerName();
			cout << endl;
			cout << endl;
		}

		if ((navigator->element->isBookAvailable()) == true)
		{
			cout << "\tBook is on shelf." << endl;
			cout << endl;
			cout << endl;
		}

		navigator = navigator->link;
	}


}

Node* LinkedListB::getHead() const {
	return head;
}

Node* LinkedListB::getTail() const {
	return tail;
}

LinkedListB LinkedListB::getCurrentList() const
{
	return *this;
	
}

LinkedListB::~LinkedListB()
{
	delete head, tail;
}