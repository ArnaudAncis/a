#include "frequency_map.h"

unsigned& frequency_map::operator [](uint8_t x)
{
	if (this->map.find(x)  == this->map.end())
	{
		this->map[x] = 0;
	}
	
	return this->map[x];
}

unsigned frequency_map::operator [](uint8_t x) const
{
	if (this->map.find(x) == this->map.end())
	{
		return 0;
	}

	return this->map.at(x);
}