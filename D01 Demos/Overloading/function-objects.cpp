#include <iostream>
#include <set>
using namespace std;

#pragma region Thing
class Thing {
public:
	Thing(int i) : x(i) {}
	Thing(const Thing& t) { 
		x=t.x;
		cout << "ctor of Thing" << endl;
	}
	Thing& operator=(const Thing& t) { 
		x=t.x;
		cout << "=op of Thing" << endl;
	}
	~Thing() { 
		cout << "Destroying Thing: " << x << endl;
	}
	int getX() const { return x; }
private:
	int x;
};
#pragma endregion

#pragma region FunctionObjects (comparisons)
struct LessThing { 
   bool operator()(const Thing& lhs, const Thing& rhs) const {
      return lhs.getX() < rhs.getX();
   }
};

struct GreaterThing { 
   bool operator()(const Thing* lhs, const Thing* rhs) const {
      return lhs->getX() > rhs->getX();
   }
};
#pragma endregion

#pragma region Tests
typedef unsigned int uint;
void main() {

	// http://msdn.microsoft.com/en-us/library/e8wh7665.aspx:
	// unique, sorted values
	// see MSDN for more rules

	cout << "\nTest1" << endl;
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(2);
	s1.insert(2);
	set<int>::iterator itr1;
	cout << "set1 (of ints) contents:" << endl;
	for (itr1 = s1.begin() ; itr1 != s1.end(); itr1++) cout << (*itr1) << endl;

	cout << "\n\nTest2" << endl;
	set<Thing*>* s2 = new set<Thing*>();
	s2->insert(new Thing(3));
	s2->insert(new Thing(1));
	s2->insert(new Thing(2));
	set<Thing*>::iterator itr2;
	for (itr2 = s2->begin() ; itr2 != s2->end(); itr2++)
		cout << (*itr2)->getX() << endl;
	s2->insert(new Thing(2)); // Thing objects are NOT their "x" values!
	cout << "set2 (of Things) contents:" << endl;
	for (itr2 = s2->begin() ; itr2 != s2->end(); itr2++)
		cout << (*itr2)->getX() << endl;
	for (itr2 = s2->begin() ; itr2 != s2->end(); itr2++) 
		delete *itr2;
	delete s2;

	cout << "\n\nTest3" << endl;
	set<Thing, LessThing> s3;
	s3.insert(Thing(4));
	s3.insert(Thing(6));
	s3.insert(Thing(5));
	s3.insert(Thing(5));
	set<Thing,LessThing>::iterator itr3;
	cout << "set3 (of Thing values) contents (sort by less):" << endl;
	for (itr3 = s3.begin() ; itr3 != s3.end(); itr3++)
		cout << (*itr3).getX() << endl;

	cout << "\n\nTest4" << endl;
	set<Thing*, GreaterThing>* s4 = new set<Thing*,GreaterThing>(); 
	s4->insert(new Thing(8));
	s4->insert(new Thing(7));
	s4->insert(new Thing(9));
	s4->insert(new Thing(8));
	s4->insert(new Thing(8));
	set<Thing*,GreaterThing>::iterator itr4;
	cout << "set4 (of Thing pointers) contents (sort by greater):" << endl;
	for (itr4 = s4->begin() ; itr4 != s4->end(); itr4++)
		cout << (*itr4)->getX() << endl;
	for (itr4 = s4->begin() ; itr4 != s4->end(); itr4++)
		delete *itr4;
	delete s4;

	cout << "\n\nCall destructors for remaining stuff:" << endl;
	#pragma endregion
}