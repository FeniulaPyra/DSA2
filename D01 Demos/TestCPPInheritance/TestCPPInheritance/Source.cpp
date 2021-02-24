#include <iostream>

using namespace std;

#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "Bear.h"
#include "CS.h"
#include "Junior.h"


int main()
{

	#pragma region Test Data Members
	cout << "\nTesting Data Members:" << endl;
	B1* t1 = new D1();
	t1->x = 1;
	t1->y = 2;
	t1->print1();
	// t1->print2(); // fails--why?
	D1* t2 = new D1();
	t2->x = 2;
	t2->y = false;
	t2->print2();
	#pragma endregion

	#pragma region test non-virtual functions
	cout << "\nTesting non-virtual" << endl;
	B2* x1 = new D2();
	x1->test1();
	x1->test2(); // no polymorphism w/o virtual (static dispatch)
	// x1->test3();
	// x1->test4();
	D2* x2 = new D2(); // did test3 inherit?
	x2->test2(); // call D2's version
	x2->D2::test2(); // call D2's version
	#pragma endregion

	#pragma region test static
	cout << "\nTesting static" << endl;
	B3* statictest = new D3();
	statictest->test1();
	B3::test1();
	D3::test1();
	statictest->test2();
	#pragma endregion

	#pragma region test virtual functions
	cout << "\nTesting virtual functions:" << endl;
	Animal* a1 = new Bear();
	cout << a1->makeSound() << endl;
	Bear* b1 = (Bear*)a1->mate(); // using c-style cast (fixed below)
	cout << b1->makeSound() << endl;
	#pragma endregion

	#pragma region test "super.super..."
	cout << "\nTesting 'super.super....':" << endl;
	AS* supertest = new CS();
	supertest->test();
	#pragma endregion

	#pragma region test casting and aliases
	cout << "\nTesting casting:" << endl;
	Person p1 = Student();
	p1.setSSN(123456789);
	Person p2 = Student();
	p2 = p1;
	cout << "P2's ssn: " << p2.getSSN() << endl;
	Person* p3 = new Junior();
	Junior* p4 = (Junior*)p3; // c-style cast, frowned upon!
	Junior* p5 = dynamic_cast<Junior*>(p3); // encouraged for downcasting
	p5->setSSN(987654321);
	cout << "P5's ssn: " << p5->getSSN() << endl;
	#pragma endregion

}