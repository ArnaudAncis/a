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

frequency_map frequencies(const std::string& string)
{
	frequency_map result;

	for (char c : string)
	{
		result[uint8_t(c)]++;
	}

	return result;
}