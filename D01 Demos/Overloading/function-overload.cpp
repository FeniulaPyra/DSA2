#include <iostream>
#using namespace std;

class Person {
          public:
	     Person(int i) : id(i) {}
	     operator int() { return id; } 
          private:
	     int id;
          };
int main() {
   Person p(123);
    cout << int(p) << endl;
}
