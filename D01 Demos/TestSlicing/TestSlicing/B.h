#pragma once
#include "a.h"

class B : public A {
public:
	B(int x, int y);
	~B(void);
	int bar;
};
