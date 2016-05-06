#pragma once

#include "bit_sequence.h"

bit_sequence parse_bit_sequence(std::string string)
{
	auto result = bit_sequence::empty();

	for (char c : string)
	{
		if (c == '0')
		{
			result += false;
		}
		else if (c == '1')
		{
			result += true;
		}
		else
		{
			abort();
		}
	}

	return result;
}