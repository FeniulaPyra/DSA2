/*--------------------------------------------------------------------------------------------------
This project was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef _FOO_H
#define _FOO_H

#include <iostream>

class  Foo
{
public:
	 Foo();
	~ Foo();

	void Print();

	void Set(const int);
	int Get();

	//bool operator> (const Foo& input);

	//friend std::ostream& operator<< (std::ostream& os, const Foo& foo);

public:
	int data;
};

//class Bar : public Foo
//{
//};

#endif //_MAIN_H