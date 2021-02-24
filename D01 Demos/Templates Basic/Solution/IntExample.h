/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef __INTEXAMPLE_H_
#define __INTEXAMPLE_H_
#include <iostream>
class IntExample
{
public:
	IntExample(int a_nData0, int a_nData1, int a_nData2);
	IntExample(const IntExample& other);
	IntExample& operator=(const IntExample& other);
	~IntExample(void);
	friend void Print(IntExample other);
private:
	int m_nData[3];
	void Swap(IntExample& other);
	void Release(void);
	void Print(void) const;
};
inline void Print(IntExample other)
{
	other.Print();
}
#endif