#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
private:
	int id;
public:
	virtual int getID() const { return id; }
};

#endif