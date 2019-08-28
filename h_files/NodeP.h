#pragma once
#include "FacultyMember.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"

class NodeP
{

private:

public:
	NodeP();
	NodeP(int);
	~NodeP();

	Person* element;
	NodeP *link;
};

