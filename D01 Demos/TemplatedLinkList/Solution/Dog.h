/*--------------------------------------------------------------------------------------------------
Commented by: [YOUR NAME HERE]
--------------------------------------------------------------------------------------------------*/
#ifndef _DOG_H
#define _DOG_H

#include "animal.h"

class Dog :
	public Animal
{
public:
	Dog(void);
	~Dog(void);

	int bones;
};

#endif //_DOG_H