#include "DoubleExample.h"

DoubleExample::DoubleExample(double a_dData0, double a_dData1, double a_dData2)
{
	m_dData[0] = a_dData0;
	m_dData[1] = a_dData1;
	m_dData[2] = a_dData2;
}

DoubleExample::DoubleExample(const DoubleExample& other)
{
	DoubleExample temp( other.m_dData[0], other.m_dData[1], other.m_dData[2]);
	Swap(temp);
}

DoubleExample& DoubleExample::operator=(const DoubleExample& other)
{
	if(this != &other)
	{
		DoubleExample temp(other);
		Swap(temp);
	}
	return *this;
}

DoubleExample::~DoubleExample(void)
{
	Release();
}

void DoubleExample::Swap(DoubleExample& other)
{
	std::swap(this->m_dData, other.m_dData);
}
void DoubleExample::Release(void)
{

}
void DoubleExample::Print(void) const
{
	std::cout << "The values are: " << m_dData[0] << ", " << m_dData[1] << ", " << m_dData[2] << std::endl;
}