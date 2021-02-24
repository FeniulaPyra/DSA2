#include <iostream>
using namespace std;

int main() {

    int *p1;
    int* p2;
    int i = 10;
    p1 = &i;
    p2 = &i;

    // http://www.cplusplus.com/reference/cstdio/printf/

    printf("%s%i\n","i:    ",i);
    printf("%s%i\n","*p1:  ",*p1);
    printf("%s%i\n","*p2:  ",*p2);

    cout << endl;

    printf("%s%i\n","&i:   ",&i);
    printf("%s%p\n","p1:   ",p1); // prints in hexadecimal
    printf("%s%i\n","p2:   ",p2);

    // for printing pointer addresses via cout
    // see http://stackoverflow.com/questions/5657123/how-to-simulate-printfs-p-format-when-using-stdcout

    cout << endl;
    cout << "Testing cout: " << static_cast<void*>(p1) << endl;

    // in case you don't have Ctrl-F5 set:
    // getchar();
}
