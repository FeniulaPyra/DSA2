#include "B.h"
#include <iostream>

B::B(int x, int y) : A(x), bar(y) {} 


B::~B(void)
{
	std::cout << __FUNCTION__ << std::endl;
}
