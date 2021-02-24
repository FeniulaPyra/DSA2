#include "Cat.h"

Cat::Cat(const char* a_sName) : m_sName(nullptr)
{
	if(a_sName == nullptr)
		return;

	int nCount = 0;
	char sTemp = a_sName[nCount];
	
	while (sTemp != '\0')
	{
		sTemp = a_sName[nCount];
		nCount++;
	}

	m_sName = new char[nCount];

	for(int i = 0; i < nCount; i++)
	{
		m_sName[i] = a_sName[i];
	}
}
Cat::Cat(const Cat& other) : m_sName(nullptr)
{
	Cat temp(other.m_sName);
	Swap(temp);
}
Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		Release();
		Cat temp(other);
		Swap(temp);
	}
	return *this;
}
Cat::~Cat()
{
	Release();
}
void Cat::Release()
{
	if(m_sName != nullptr)
	{
		delete[] m_sName;
		m_sName = nullptr;
	}
}
void Cat::Swap(Cat& other)
{
	std::swap(this->m_sName, other.m_sName);
}
void Cat::Print()
{
	std::cout << "This cat's name is " << m_sName << "." << std::endl;
}
void Cat::Move()
{
	std::cout << m_sName << " is a cat that moves by walking." << std::endl;
}