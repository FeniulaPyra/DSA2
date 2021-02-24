#include "MyFriend.h"
MyFriend::MyFriend()
{
	//std::cout << __FUNCTION__ << std::endl;
}
 
MyFriend::MyFriend (const MyFriend& other)
{
	//std::cout << __FUNCTION__ << std::endl;
}

MyFriend& MyFriend::operator= (const MyFriend& other)
{
	//std::cout << __FUNCTION__ << std::endl;
    return *this;
}
 
MyFriend::~MyFriend()
{
	//std::cout << __FUNCTION__ << std::endl;
}

void MyFriend::Method(void)
{
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "Value of Data: " << var.data << std::endl << std::endl;
}