#ifndef B2_H
#define B2_H

class B2 
{
public:
	void test1();		// B2 test1 - Prints Class Name
	void test2();		// B2 test2 - Prints Class Name

protected:
	void test3();		// B2 test3 - Prints Class Name

private:
	// B2 test4 - Prints Class Name
	/*virtual*/ void test4();			 // virtual? see v-table...

};

#endif