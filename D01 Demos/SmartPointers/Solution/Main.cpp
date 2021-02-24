/*--------------------------------------------------------------------------------------------------
This project was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/

#include "Main.h"

int main()
{
	std::shared_ptr<Base> b1(new Base());
	b1->Print();
	b1->SetData(1);
	b1->Print();

	typedef std::shared_ptr<Base> SharedBasePtr;
	SharedBasePtr b2;
	b2 = b1;
	b2->Print();

	//b1->other = b2;
	//b1->Print();

	//Ending the program
	std::cout << std::endl;
	std::cout << "Press enter to finish...";
	getchar();
	return 0;
}