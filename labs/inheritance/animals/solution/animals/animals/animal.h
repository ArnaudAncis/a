#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
	virtual ~Animal() { }

	virtual std::string getVerb() const = 0;
};

#endif
