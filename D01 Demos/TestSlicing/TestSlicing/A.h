#pragma once
class A
{
public:
	A(int x);
	virtual ~A(void);
	// ~A(void); // what happens if you don't make A virtual?
	int foo;
};

