#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal 
{
public:
	virtual std::string makeSound();		// Print Class name and "goes"
	virtual Animal* mate();					// Creates new Animal

};

#endif

