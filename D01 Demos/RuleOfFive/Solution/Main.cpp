/*--------------------------------------------------------------------------------------------------
Exemplifies the Rule of Five for C++ 11
--------------------------------------------------------------------------------------------------*/
#include "Foo.h"

int main()
{

	//Constructor
    const Foo foo; 

    std::cout << foo << '\n'; //Friend Function (Overriding <<)

	//Copy Constructor
	Foo bar(foo);
	std::cout << bar << '\n';

	Foo baz;
	//Copy Assignment
	baz = foo;
	std::cout << baz << '\n';

	//for more information on Move Constructor and Copy Move Constructor:
	//http://en.wikipedia.org/wiki/Rvalue_reference#Rvalue_references_and_move_constructors
	//http://en.cppreference.com/w/cpp/language/move_constructor
	//http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html


	//Ending the program
	std::cout << "Press enter to finish";
	getchar();

	//No memory allocation and Destructors are called without memory leaks
	return 0;
}