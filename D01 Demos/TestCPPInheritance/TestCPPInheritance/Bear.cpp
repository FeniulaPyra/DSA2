#include "Bear.h"
#include <string>

std::string Bear::makeSound() 
{ 
		return Animal::makeSound() + "roar!";
}

Bear* Bear::mate() { return new Bear(); } // covariant return type
