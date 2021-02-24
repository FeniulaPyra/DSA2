#include "B2.h"
#include <iostream>

using namespace std;


void B2::test1() { cout << "B2 test1: " << typeid(*this).name() << endl; }
void B2::test2() { cout << "B2 test2: " << typeid(*this).name() << endl; }
void B2::test3() { cout << "B2 test3: " << typeid(*this).name() << endl; }

/*virtual*/ void B2::test4() { cout << "B2 test4: " << typeid(*this).name() << endl; } // virtual? see v-table...