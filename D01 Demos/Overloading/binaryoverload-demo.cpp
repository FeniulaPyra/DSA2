#include <iostream>
using namespace std;
class Interval {
public:
	Interval(int a, int b):low(a), high(b) { }
	Interval* operator+(const Interval& other) {
		return new Interval(low+other.low,high+other.high);
	}
	void print() const { 
		cout << "[" << low << "," << high << "]" << endl;
	}

private:
	int low, high;
};

int main() {
	Interval* i1 = new Interval(1,2);
	Interval* i2 = new Interval(3,4);
	Interval* i3 = *i1 + *i2;
	i3->print();
	delete i1;
	delete i2;
	delete i3;
}