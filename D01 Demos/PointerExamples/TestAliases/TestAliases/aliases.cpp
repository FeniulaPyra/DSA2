#include <iostream>
using namespace std;

int main() {
    int i;
    int* p;
    int* q;

    p = &i; 
    *p = 30;  // store 30 in => do a PUT for L-values
    q = p;    // q gets p => q gets the value stored in p
	          //             q points to i
    *q = 40;  // go to i and PUT the 40

    printf("%s%i\n","*p: ",*p);
    printf("%s%i\n","*q: ",*q);
    printf("%s%i\n","i:  ", i);

}

