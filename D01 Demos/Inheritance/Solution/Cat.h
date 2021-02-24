/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef _CAT_H
#define _CAT_H

#include <iostream>

class Cat
{
protected:
	//member fields
	char* m_sName;

public:
	//Constructor
	Cat(const char* a_sName);
	//Copy Constructor
	Cat(const Cat& other);
	//Copy Assignment Operator
	Cat& operator=(const Cat& other);
	//Destructor
	~Cat();
	//Prints the information of the Cat
	virtual void Print();
	//Makes the Cat Move
	virtual void Move();

protected:
	//Releases fields of the class
	virtual void Release();
	//Swaps the information from the one contained in other object
	virtual void Swap(Cat& other);
};
#endif