#include <iostream>
using namespace std;

int main() {
    int i, x;
    x = 50;
    i = *&x;
    //int j = *x;

    printf("%s%i\n","p:  ",i);
    printf("%s%i\n","p:  ",x);
}