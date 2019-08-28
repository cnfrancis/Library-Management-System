#pragma once
#include "NodeP.h"

class LinkedListP
{
private:
	NodeP *head;
	NodeP *tail;

public:
	LinkedListP();
	~LinkedListP();
	void addNewNode(Person*);
	void removeNode(int);
	NodeP *getHead() const;
	NodeP *getTail() const;
};

