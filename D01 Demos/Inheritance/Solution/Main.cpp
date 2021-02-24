#include <iostream>
#include "Main.h"

int main ()
{
	//. non pointer or regular structures
	//-> pointer

	std::cout << "Felix:\n";
	Cat* felix = new Cat("Felix");
	felix->Move();
	delete felix;
	felix = nullptr;

	std::cout << "Garfield:\n";
	NyanCat* garfield  = new NyanCat("Garfield");
	garfield->Move();
	delete garfield;
	garfield = nullptr;

	std::cout << "Tom:\n";
	Cat* tom = new NyanCat("Tom");
	tom->Move();
	//tom->lives;
	delete tom;
	tom = nullptr;

	//std::cout << "\n";
	//std::cout << "Tom:\n";
	//NyanCat tom(garfield);
	//tom.Move();
	//tom = NyanCat("Tom");
	//tom.Move();

	getchar();
	return 0;
}
