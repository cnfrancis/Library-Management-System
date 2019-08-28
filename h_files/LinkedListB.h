#pragma once
#include "Book.h"
using namespace std;

#ifndef LINKEDLISTB_H_
#define LINKEDLISTB_H_

struct Node {
	Book *element;
	Node *link;
};

class LinkedListB
{
private:
	Node *head;
	Node *tail;

public:
	LinkedListB();
	~LinkedListB();
	void addNewNode(Book&);
	void removeNode(int);
	void printBooksInfo() const;
	Node *getHead() const;
	Node *getTail() const;
	LinkedListB getCurrentList() const;
};
#endif
