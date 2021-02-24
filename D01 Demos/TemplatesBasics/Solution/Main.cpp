#include <iostream>
#include "Main.h"

template<class T>
class SingleVariable
{
public:
	SingleVariable(T a)
	{
		std::cout << __FUNCTION__ << " ";
		std::cout << a << std::endl;
	}
};
template<class T, class U>
class DoubleVariableDifferent
{
public:
	DoubleVariableDifferent(T a, U b)
	{
		std::cout << __FUNCTION__ << " ";
		std::cout << a << " ";
		std::cout << b << std::endl;
	}
};

template<class T>
class DoubleVariableSame
{
public:
	DoubleVariableSame(T a, T b)
	{
		std::cout << __FUNCTION__ << " ";
		std::cout << a << " ";
		std::cout << b << std::endl;
	}
};

int main ()
{
	SingleVariable<int> single(0);
	DoubleVariableDifferent<int, float> doubleDifferentA( 0, 0.0f);
	DoubleVariableDifferent<int, int> doubleDifferentB( 0, 1);
	DoubleVariableSame<int> doubleSame(0,1);

	std::cout << "Press Enter to Finish" << std::endl;
	getchar();
	return 0;
}
