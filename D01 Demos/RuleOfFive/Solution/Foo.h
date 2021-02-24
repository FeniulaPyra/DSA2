//http://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
#ifndef _FOO_H
#define _FOO_H

#include <cstring>
#include <iostream>
 
class Foo
{
public:
    /** Constructor */
    Foo() :
        data (new char[14])
    {
		std::cout << __FUNCTION__ << std::endl;
        strcpy_s (data, 14, "Hello, World!");
    }
 
    /** Copy Constructor */
    Foo (const Foo& other) :
        data (new char[std::strlen (other.data) + 1])
    {
		std::cout << __FUNCTION__ << std::endl;
        strcpy_s (data, 14, other.data );
    }

	/** Copy Assignment Operator */
    Foo& operator= (const Foo& other)
    {
		std::cout << __FUNCTION__ << std::endl;
        Foo temporary (other);
        std::swap (data, temporary.data);
        return *this;
    }

	/** Destructor */
    ~Foo()
    {
		std::cout << __FUNCTION__ << std::endl;
        delete[] data;
    }
 
    /** Move Constructor */
    Foo (Foo&& other) :
        data (other.data)
    {
		std::cout << __FUNCTION__ << std::endl;
        other.data = nullptr;
    }
 
    /** Move Assignment Operator */
    Foo& operator= (Foo&& other)
    {
		std::cout << __FUNCTION__ << std::endl;
        std::swap (data, other.data);
        return *this;
    }
 
private:
    friend std::ostream& operator<< (std::ostream& os, const Foo& foo)
    {
		std::cout << __FUNCTION__ << std::endl;
        os << foo.data;
        return os;
    }
 
    char* data;
};
#endif //_MAIN_H