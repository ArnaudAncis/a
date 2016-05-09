#include "rle.h"
#include <iostream>

std::vector<uint8_t> rle(uint8_t* input, unsigned size)
{
	std::vector<uint8_t> result;

	if (size > 0)
	{
		result.push_back(1);
		result.push_back(input[0]);

		unsigned i = 1, j = 0;

		while (i < size)
		{
			if (input[i] == result[j + 1])
			{
				if (result[j] == std::numeric_limits<uint8_t>::max())
				{
					result.push_back(1);
					result.push_back(result[j + 1]);
					j += 2;
				}
				else
				{
					++result[j];
				}
			}
			else
			{
				result.push_back(1);
				result.push_back(input[i]);
				j += 2;
			}

			++i;
		}
	}

	return result;
}

std::vector<uint8_t> unrle(uint8_t* input, unsigned size)
{
	std::vector<uint8_t> result;

	for (unsigned i = 0; i != size; i += 2)
	{
		for (unsigned j = 0; j != input[i]; ++j)
		{
			result.push_back(input[i + 1]);
		}
	}

	return result;
}