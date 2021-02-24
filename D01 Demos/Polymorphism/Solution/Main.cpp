#include <iostream>
#include "Main.h"

int main ()
{
	std::cout << "Felix:\n";
	Cat felix("Felix");
	std::cout << felix;

	std::cout << "Garfield:\n";
	NyanCat garfield("Garfield");
	std::cout << garfield;

	std::cout << "\n";
	std::cout << "Tom:\n";
	NyanCat tom(garfield);
	std::cout << tom;
	std::cout << "\n";
	tom = NyanCat("Tom");
	std::cout << tom;

	std::cout << "\nInheritance\n";
	std::cout << "Duchess:\n";
	NyanCat *duchess = new NyanCat("Duchess");
	std::cout << *duchess;
	std::cout << "Artemis:\n";
	Cat *artemis = new NyanCat("Artemis");
	std::cout << *artemis;

	delete duchess;
	delete artemis;

	getchar();
	return 0;
}
