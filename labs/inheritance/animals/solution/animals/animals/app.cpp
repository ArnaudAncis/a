#include "dog.h"
#include <iostream>

void print(const Animal& animal)
{
	std::cout << animal.getVerb() << std::endl;
}

int main()
{
	print(Dog());
}