#include <iostream>
using namespace std;

int main() {
	            // http://msdn.microsoft.com/en-us/library/f90831hc(v=vs.110).aspx
	int i = 10; // i gets the value 10, store 10 in i
	            // i is an L-value
	            // 10 is an R-value

	// where's the objects?
	// need to know what happens when we do new...
	// need to know what happens with memory addresses...
	// need to know POINTERS

	int* p;     // p is a POINTER to an integer
	// cout << p << endl; // need to give p a value

	p = &i;     // p stores the ADDRESS of i

	printf("%s%i\n", "&i: ", &i);
	printf("%s%i\n", "p:  ", p);

	// get the value from i...
	printf("%s%i\n", "*p: ",*p);
	// *p on the RIGHT side means
	// go to the object pointed by p
	//    and return the value stored there
	// dereference p

	int tmp = *p; // right side
	cout << tmp << endl;

	int val = 20;
	int* q = &val;
	cout << *q << endl;

	*p = *q;
	// *q gives 20
	// go to the var pointed by p
	//    and store *q (20)

	cout << i << endl;
	cout << val << endl;







	//getchar();
	//system("pause");
}