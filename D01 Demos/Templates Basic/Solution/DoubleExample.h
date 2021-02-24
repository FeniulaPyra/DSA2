/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef __DOUBLEEXAMPLE_H_
#define __DOUBLEEXAMPLE_H_

#include <iostream>
class DoubleExample
{
public:
	DoubleExample(double a_dData0, double a_dData1, double a_dData2);
	DoubleExample(const DoubleExample& other);
	DoubleExample& operator=(const DoubleExample& other);
	~DoubleExample(void);
	friend void Print(DoubleExample other);
private:
	double m_dData[3];
	void Swap(DoubleExample& other);
	void Release(void);
	void Print(void) const;
};
inline void Print(DoubleExample other)
{
	other.Print();
}
#endif