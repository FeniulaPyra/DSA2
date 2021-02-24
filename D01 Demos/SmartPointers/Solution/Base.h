/*--------------------------------------------------------------------------------------------------
This project was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef _BASE_H
#define _BASE_H

#include <iostream>
#include <memory>

class Base
{
	int data;
public:
	Base();
	~Base();
	void SetData(int _data);
	void Print();
	std::shared_ptr<Base> other;
};

#endif //_BASE_H
