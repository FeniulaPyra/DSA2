#include "D2.h"
#include <iostream>

using namespace std;

void D2::test2()
{
	cout << "From D2's test2, call B2's test2 then B2's test3:" << endl; 

	B2::test2();	// Call B2's test2

	test3(); 
}