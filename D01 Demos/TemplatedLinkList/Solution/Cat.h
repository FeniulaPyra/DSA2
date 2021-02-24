/*--------------------------------------------------------------------------------------------------
Commented by: [YOUR NAME HERE]
--------------------------------------------------------------------------------------------------*/
#ifndef _CAT_H
#define _CAT_H

#include "animal.h"

class Cat :
	public Animal
{
public:
	Cat(void);
	~Cat(void);

	int fish;
};

#endif //_CAT_H