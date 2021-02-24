/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef __TEMPLATEEXAMPLE_H_
#define __TEMPLATEEXAMPLE_H_
#include <iostream>
template <class T>
class TemplateExample
{
public:
	TemplateExample(T a_Data0, T a_Data1, T a_Data2)
	{
		m_Data[0] = a_Data0;
		m_Data[1] = a_Data1;
		m_Data[2] = a_Data2;
	}
	TemplateExample(const TemplateExample<T>& other)
	{
		TemplateExample<T> temp(other.m_Data[0], other.m_Data[1], other.m_Data[2]);
		Swap(temp);
	}
	TemplateExample& operator=(const TemplateExample<T>& other)
	{
		if(this != &other)
		{
			TemplateExample temp(other);
			Swap(temp);
		}
		return *this; 
	}
	~TemplateExample(void)
	{
		Release();
	}
	friend void Print(TemplateExample<T> other)
	{
		other.Print();
	}
private:
	T m_Data[3];
	void Swap(TemplateExample<T>& other)
	{
		std::swap(m_Data, other.m_Data);
	}
	void Release(void)
	{
	};
	void Print(void) const
	{
		std::cout << "The values are: " << m_Data[0] << ", " << m_Data[1] << ", " << m_Data[2] << std::endl;
	}
};

#endif