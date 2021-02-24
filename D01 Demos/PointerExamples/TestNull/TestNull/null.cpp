#include <iostream>
using namespace std;

int main() {
    int* p;
    int* q;
    int i = 10;
    p = &i;
    q = p;

    cout << "Before setting p to null: " << endl;

    printf("%s%i\n","*p: ",*p);
    printf("%s%i\n","p:  ",p);

	p = nullptr; // 0

    cout << "p is now null: " << endl;

    //printf("%s%i\n","*p: ",*p); // no deref of NULL
    printf("%s%i\n","p:  ",p);
    printf("%s%i\n","q:  ",q);

    cout << "set q via nullptr: " << endl;
	
	// C++11
    q = nullptr; // see http://thenewcpp.wordpress.com/2011/11/03/nullptr/
    // printf("%s%i\n","*q: ",*q);
    printf("%s%i\n","q:  ",q);

    // actually, if you might use managed C++, it's safer to use __nullptr when using VS:
    // http://msdn.microsoft.com/en-us/library/jj651642.aspx
    q = __nullptr;
    printf("%s%i\n","q:  ",q);
}
