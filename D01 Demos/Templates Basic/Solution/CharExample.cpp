#include "CharExample.h"

CharExample::CharExample(char a_cData0, char a_cData1, char a_cData2)
{
	m_cData[0] = a_cData0;
	m_cData[1] = a_cData1;
	m_cData[2] = a_cData2;
}

CharExample::CharExample(const CharExample& other)
{
	CharExample temp( other.m_cData[0], other.m_cData[1], other.m_cData[2]);
	Swap(temp);
}

CharExample& CharExample::operator=(const CharExample& other)
{
	if(this != &other)
	{
		CharExample temp(other);
		Swap(temp);
	}
	return *this;
}

CharExample::~CharExample(void)
{
	Release();
}

void CharExample::Swap(CharExample& other)
{
	std::swap(this->m_cData, other.m_cData);
}
void CharExample::Release(void)
{

}
void CharExample::Print(void) const
{
	std::cout << "The values are: " << m_cData[0] << ", " << m_cData[1] << ", " << m_cData[2] << std::endl;
}