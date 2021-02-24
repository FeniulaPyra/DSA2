/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
--------------------------------------------------------------------------------------------------*/
#ifndef _NYANCAT_H
#define _NYANCAT_H

#include "Cat.h"
class NyanCat : public Cat
{
public:
	NyanCat(char* a_sName);
#pragma region ExplicitDefinition
	NyanCat(const NyanCat& other);
	NyanCat& operator=(const NyanCat& other);
	~NyanCat();
#pragma endregion	
	virtual void Print();
	virtual void Move();
};

#endif //_NyanCat_H
