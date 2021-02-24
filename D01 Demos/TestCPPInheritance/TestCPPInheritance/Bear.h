#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"
#include <string>

class Bear : public Animal 
{
public:
	std::string makeSound();	// Animal makeNoise and "roar"
	virtual Bear* mate();		// covariant return type

};

#endif