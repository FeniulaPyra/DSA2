/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef __CHAREXAMPLE_H_
#define __CHAREXAMPLE_H_

#include <iostream>
class CharExample
{
public:
	CharExample(char a_cData0, char a_cData1, char a_cData2);
	CharExample(const CharExample& other);
	CharExample& operator=(const CharExample& other);
	~CharExample(void);
	friend void Print(CharExample other);
private:
	char m_cData[3];
	void Swap(CharExample& other);
	void Release(void);
	void Print(void) const;
};
inline void Print(CharExample other)
{
	other.Print();
}
#endif