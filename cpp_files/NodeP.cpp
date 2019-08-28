#include "pch.h"
#include "NodeP.h"
#include <iostream>

using namespace std;


NodeP::NodeP()
{
	link = nullptr;
	element = nullptr;
}

NodeP::NodeP(int type)
{
	switch (type)
	{
		case 1:
			element = new UndergraduateStudent;
			break;
		case 2:
			element = new GraduateStudent;
			break;
		case 3:
			element = new FacultyMember;
			break;
		default:
			cout << "NOT WORKING (NodeP.cpp)" << endl;
			break;


	}

}


NodeP::~NodeP()
{
	delete link, element;
}
