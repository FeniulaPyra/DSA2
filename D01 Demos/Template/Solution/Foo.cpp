#include "Foo.h"

Foo:: Foo()
{
	data = 0;
}

Foo::~ Foo()
{
}

void Foo::Print()
{
	std::cout << "Data: " << data << std::endl;
}

void Foo::Set(const int input)
{
	data = input;
}

int Foo::Get()
{
	return data;
}

//bool Foo::operator>(const Foo& input)
//{
//	return (this->data > input.data? true : false);
//}

//std::ostream& operator<< (std::ostream& os, const Foo& foo)
//{
//    os << foo.data;
//    return os;
//}