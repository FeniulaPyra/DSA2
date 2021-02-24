#include "Base.h"
Base::Base() : data (1)
{
	//std::cout << __FUNCTION__ << std::endl;
}
 
Base::Base (const Base& other)
{
	//std::cout << __FUNCTION__ << std::endl;
	data = other.data;
}

Base& Base::operator= (const Base& other)
{
	//std::cout << __FUNCTION__ << std::endl;
    Base temporary (other);
    std::swap (data, temporary.data);
    return *this;
}
 
Base::~Base()
{
	//std::cout << __FUNCTION__ << std::endl;
}

void Base::Method()
{
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Value of Data: " <<  data << std::endl << std::endl;
}

void PrivateAccessor(Base &other)
{
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Value of Data: " << other.data << std::endl << std::endl;
}