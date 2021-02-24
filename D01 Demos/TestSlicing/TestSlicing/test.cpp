/* Slicing:
 *
 * http://www.devx.com/tips/Tip/14570
 * http://stackoverflow.com/questions/274626/what-is-the-slicing-problem-in-c
 *
 */
#include <iostream>
#include "A.h"
#include "B.h"
using namespace std;

void main() {

	cout << "\nMake B object called test1: " << endl;
	B test1(100,200);
	cout << "Foo:  " << test1.foo << endl;
	cout << "Bar:  " << test1.bar << endl;

	cout << "\nA test2 = test1: " << endl;
	A test2 = test1;
	cout << "Foo:  " << test2.foo << endl;
	//cout << "Bar:  " << test2.bar << endl; // why does this expression fail?
	
	cout << "\nA& test3 = test1: " << endl;
	A& test3 = test1;
	cout << "Foo:  " << test3.foo << endl;
	// cout << "Bar:  " << test3.bar << endl; // why does this expression fail?

	cout << "\nA* test4 = &test1: " << endl;
	A* test4 = &test1;
	cout << "Foo:  " << test4->foo << endl;
	// cout << "Bar:  " << test4->bar << endl; // why does this expression fail?

	cout << "\nA* test5 = new B(100,200): " << endl;
	A* test5 = new B(100,200);
	cout << "Foo:  " << test5->foo << endl;
	cout << "Bar:  " << static_cast<B*>(test5)->bar << endl;
	cout << "Bar:  " << dynamic_cast<B*>(test5)->bar << endl; // better to use dynamic?

	cout << "\nDelete test5: " << endl;
	delete test5;

	cout << "\nDelete everything else: " << endl;
}