#include "pch.h"
#include "LinkedListP.h"
#include <iostream>
using namespace std;


LinkedListP::LinkedListP()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedListP::addNewNode(Person *x) {
	NodeP *temp = new NodeP(x->type);
	temp->element = x;
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

void LinkedListP::removeNode(int id)
{
	NodeP *navigator{ nullptr };
	NodeP *previous{ nullptr };

	navigator = head;
	previous = navigator;

	while (navigator)
	{
		if ((navigator->element->getBorrowerID() == id))
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



NodeP* LinkedListP::getHead() const {
	return head;
}

NodeP* LinkedListP::getTail() const {
	return tail;
}

LinkedListP::~LinkedListP()
{
	delete head, tail;
}
