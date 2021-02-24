#include "A.h"
#include <iostream>

A::A(int i) : foo(i) {}


A::~A(void)
{
	std::cout << __FUNCTION__ << std::endl;
}
