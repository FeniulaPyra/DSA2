#include <iostream>
using namespace std;

#define EXAMPLE1

int main()
{
    // an introduction to const correctness
    // see http://www.parashift.com/c++-faq/overview-const.html

    double pointeeA = 1.0;
    double pointeeB = 2.0;

#ifdef EXAMPLE1
	// constant pointeeA only:
	double const* ptrA = &pointeeA;          // http://www.parashift.com/c++-faq/ptr-to-const.html
	//*ptrA = 2.0;  // allowed?
	//ptrA = &pointeeB;  // allowed?
	printf("%s%3.1f\n","*ptrA: ",*ptrA);
#endif

#ifdef EXAMPLE2
	// constant pointer only:
	double* const ptrA = &pointeeA;          // http://www.parashift.com/c++-faq/ptr-to-const.html
	double* ptrB = &pointeeB;
	//*ptrA = 2.0;		// allowed?
	//ptrA = ptrB;		// allowed?
	//ptrA = nullptr;	// allowed?
	printf("%s%3.1f\n","*ptrA: ",*ptrA);
#endif

#ifdef EXAMPLE3
	// constant pointeeA AND constant pointer
	double const* const ptrA = &pointeeA;     // http://www.parashift.com/c++-faq/ptr-to-const.html
	double* ptrB = &pointeeB;
	//*ptrA = 2.0;	// allowed?
	//ptrA = &pointeeB;	// allowed?
	printf("%s%3.1f\n","*ptrA: ",*ptrA);
#endif
}

