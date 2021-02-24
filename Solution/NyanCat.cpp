#include "NyanCat.h"

NyanCat::NyanCat(char* a_sName):Cat(a_sName) //Using "base" constructor
{
}

#pragma region ExplicitDefinition
NyanCat::NyanCat(const NyanCat& other): Cat(other.m_sName)
{

}
NyanCat& NyanCat::operator=(const NyanCat& other)
{
	if(this != &other)
	{
		Release();
		NyanCat temp(other.m_sName);
		Swap(temp);
	}
	return *this;
}
NyanCat::~NyanCat()
{
	Release();
}
#pragma endregion

void NyanCat::Print()
{
	std::cout << "This NyanCat's name is " << m_sName << "." << std::endl;
}
void NyanCat::Move()
{
	std::cout << m_sName << " is a NyanCat that moves by flying." << std::endl;
}