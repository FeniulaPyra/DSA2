#include <iostream>
using namespace std;

class Stack {
public:
	Stack(int size) {
		this->size = size;
		data = new int[size];
		count = 0;
		sp = 0;
	}
	~Stack() { 
		delete[] data;
	}
	int operator++(int) {
		return data[sp++];
	}
	int operator--() {
		return data[--sp];
	}
	bool add(int item) {
		if (count < size) { // still has space
			data[sp++] = item;
			return true;
		}
		return false;
	}
	int operator[](int i) {
		return data[i];
	}
	/*
	int& operator[](int i) {
		return data[i];
	}
	*/

	int getSP() const { return sp; }

private:
	int size;
	int count;
	int* data;
	int sp;
};
int main() {
	Stack* s = new Stack(4);
	s->add(10);
	s->add(21);
	s->add(32);
	s->add(43);
	--(*s); 
	--(*s);
	cout << s->getSP() << endl;
	cout << (*s)++ << endl;
	cout << (*s)[0] << endl;
	// (*s)[0] = 100; // works if you make the [] return ref type

	delete s;
}