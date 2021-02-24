#include <iostream>
using namespace std;

int main() {

    int i = 10;
    int* q = &i;
    int** p = &q;

    /*
    *     ┌───┐         ┌───┐     ┌───┐ 
    *     │ p │────────>│ q │────>│ i │
    *     └─┬─┘         └─┬─┘     └─┬─┘
    *       │             │         │
    * ┌─────┴─────┐  ┌────┴────┐  ┌─┴──┐ 
    * │  address  │  │ address │  │ 10 │
    * │   of p    │  │  of q   │  │    │
    * └───────────┘  └─────────┘  └────┘
    */

    printf("%s%i\n","&i:  ",&i);
    printf("%s%i\n","q:   ",q);
    printf("%s%i\n","*p:  ",*p);

    cout << endl;

    printf("%s%i\n","i:   ",i);
    printf("%s%i\n","*q:  ",*q);
    printf("%s%i\n","**p: ",**p);



}
