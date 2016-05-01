#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Cat : public Animal
{
public:
	std::string getVerb() const override;
};

#endif
