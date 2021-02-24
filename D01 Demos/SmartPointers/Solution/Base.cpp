#include "Base.h"
Base::Base()
{
	std::cout << __FUNCTION__ << std::endl;
	data = 0;
};
Base::~Base()
{
	std::cout << __FUNCTION__ << std::endl;
};
void Base::SetData(int _data)
{
	data = _data;
}
void Base::Print()
{
	std::cout << data << std::endl;
}