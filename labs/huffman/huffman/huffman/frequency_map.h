#ifndef FREQUENCY_MAP
#define FREQUENCY_MAP

#include <map>

class frequency_map
{
	std::map<uint8_t, unsigned> map;

public:
	unsigned& operator [](uint8_t);
	unsigned operator [](uint8_t) const;
};

frequency_map frequencies(const std::string&);

#endif