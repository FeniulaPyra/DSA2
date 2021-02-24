/*--------------------------------------------------------------------------------------------------
This project was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#include "Main.h"

int main()
{
	std::cout << "Templates\n" << std::endl;

#pragma region INTEGER
	//Integer
	int a, b;
	a = 1;
	b = 2;
	std::cout << "Integer: " << std::endl;
	std::cout << "The max value is " << GetMax(a,b) << std::endl << std::endl;
#pragma endregion

#pragma region FLOAT
	////Float
	//float c, d;	
	//c = 1.5f;
	//d = 2.8f;
	//std::cout << "Float: " << std::endl;
	//std::cout << "The max value is " << GetMax(c,d) << std::endl << std::endl;
#pragma endregion

#pragma region CLASS
	////Class
	//Foo foo, foo2;
	//foo.Set(1);
	//foo2.Set(4);
	//std::cout << "Foo: " << std::endl;
	//std::cout << "The max value is " << GetMax(foo,foo2) << std::endl << std::endl;
#pragma endregion

#pragma region MIX
	////Mix
	//std::cout << "Integer and Float: " << std::endl;
	//std::cout << "The max value is " << GetMax<int,float>(a,c) << std::endl << std::endl;
#pragma endregion

#pragma region MIX WITH CLASS
	////Mix with class
	//Bar bar;
	//bar.Set(5);
	//std::cout << "Bar: " << std::endl;
	//std::cout << "The max value is " << GetMax(foo,bar) << std::endl << std::endl;
#pragma endregion

#pragma region TEMPLATECLASS
	////Template Class
	//myClass<int, double, long> myObject;
	//myObject.Set( 115, 36.0, 25);

	//myClass<int, int, int> vertex;
	//vertex.Set(0,0,0);
	//myClass<float, float, float> coordinate;
	//coordinate.Set(5.0, 5.0, 5.0);

	//myClass<int,int,int>* vert;
	//vert = new myClass<int,int,int>[10];
#pragma endregion

	//Ending the program
	std::cout << std::endl;
	std::cout << "Press enter to finish...";
	getchar();
	return 0;
}