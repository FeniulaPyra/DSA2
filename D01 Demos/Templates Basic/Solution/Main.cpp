#include <iostream>
#include "Main.h"

int main ()
{
	IntExample intObject(0,1,2);
	CharExample charObject('a','b','c');
	DoubleExample doubleObject(0.1, 0.2, 0.3);
	
	Print(intObject);
	Print(charObject);
	Print(doubleObject);
	
	std::cout << std::endl;

	TemplateExample<int> intTemplate(0,1,2);
	TemplateExample<char> charTemplate('a','b','c');
	TemplateExample<double> doubleTemplate(0.1, 0.2, 0.3);
	
	Print(intTemplate);
	Print(charTemplate);
	Print(doubleTemplate);

	getchar();
	return 0;
}
