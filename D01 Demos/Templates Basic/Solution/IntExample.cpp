#include "IntExample.h"

IntExample::IntExample(int a_nData0, int a_nData1, int a_nData2)
{
	m_nData[0] = a_nData0;
	m_nData[1] = a_nData1;
	m_nData[2] = a_nData2;
}

IntExample::IntExample(const IntExample& other)
{
	IntExample temp( other.m_nData[0], other.m_nData[1], other.m_nData[2]);
	Swap(temp);
}

IntExample& IntExample::operator=(const IntExample& other)
{
	if(this != &other)
	{
		IntExample temp(other);
		Swap(temp);
	}
	return *this;
}

IntExample::~IntExample(void)
{
	Release();
}

void IntExample::Swap(IntExample& other)
{
	std::swap(this->m_nData, other.m_nData);
}
void IntExample::Release(void)
{

}
void IntExample::Print(void) const
{
	std::cout << "The values are: " << m_nData[0] << ", " << m_nData[1] << ", " << m_nData[2] << std::endl;
}