#include <iostream>
using namespace std;

int main() {
    int* p; // int* is pointer-to-int type
    int i = 10;
    p = &i; // p gets address of i
    *p = 20; // L-value
    // dereference p and store 20
    // goto the "pointee" of p and store 20
    // L-val: put 20 where p points
    cout << "i:  " << i << endl;
    cout << "p:  " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "&i: " << &i << endl;

    int j = 30;
    int* q = &j; // q is a pointer-to-int type
    // q can store an address
    // q now stores address of j

    *p = *q;
    cout << "i:  " << i << endl; // 30
    // RHS: *q means: get the value stored at the address
    //                contained in q (get j's address and
    //                return the value stored at j)
    // LHS: *p means: take the value from the RHS (30 was
    //				  the result of *q) and store in i

    p = q; // p gets q's value (p points to j)
    // alias
    *q = 40; 
    *p = 50;
    cout << "i:  " << i << endl; // no change
    cout << "j:  " << j << endl; // 50

    int k = 100;
    //int* r = &k; // could also use
    cout << *&k << endl; // inverse operators

    // NOTE: the expressions in the output statements above
    // are R-values!!!

    // null pointer:
    int* a = nullptr;
    int* b = 0;

}