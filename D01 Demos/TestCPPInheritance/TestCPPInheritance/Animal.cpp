#include "Animal.h"

#include <string>

std::string Animal::makeSound() 
{
	return std::string(typeid(*this).name()) + " goes ";
}

Animal* Animal::mate() { return new Animal(); }