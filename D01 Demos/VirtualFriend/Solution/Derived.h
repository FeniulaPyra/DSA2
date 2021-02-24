/*--------------------------------------------------------------------------------------------------
This Program was generated by Alberto Bobadilla in 2013
--------------------------------------------------------------------------------------------------*/
#ifndef _B_H
#define _B_H

#include "Base.h"

class Derived : public Base
{
public:
	Derived() : Base() , extendedData (2)
    {
		//std::cout << __FUNCTION__ << std::endl;
    }
 
    /** Copy Constructor */
    Derived (const Derived& other)
    {
		//std::cout << __FUNCTION__ << std::endl;
		data = other.data;
		extendedData = other.extendedData;
    }

	/** Copy Assignment Operator */
    Derived& operator= (const Derived& other)
    {
		//std::cout << __FUNCTION__ << std::endl;
        Derived temporary (other);

        std::swap (data, temporary.data);
		std::swap (extendedData, temporary.extendedData);
        return *this;
    }
 
    /** Destructor */
    ~Derived()
    {
		//std::cout << __FUNCTION__ << std::endl;
    } 
	
	void print()
	{
		std::cout << "From Derived: print" << std::endl;
	}
	
	virtual void virtualPrint()
	{
		std::cout << "From Derived : virtualPrint" << std::endl;
	}

	friend void f()
	{
		//std::cout << __FUNCTION__ << std::endl;
		std::cout << "From Derived : f (friend)" << std::endl;
	}
protected:
	virtual void do_function()
	{
		//std::cout << __FUNCTION__ << std::endl;
		std::cout << "From Derived : g (\"virtual friend\")" << std::endl;
	}
	int extendedData;
};

#endif //_B_H
