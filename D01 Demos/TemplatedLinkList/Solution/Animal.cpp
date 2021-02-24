#include <iostream>
#include <typeinfo.h>
#include "Animal.h"

Animal::Animal(void)
{
}

Animal::~Animal(void)
{
}
void Animal::print() {
	std::cout << typeid(*this).name() << std::endl;
}