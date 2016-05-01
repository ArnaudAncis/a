#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal
{
public:
	std::string getVerb() const;
};

#endif
