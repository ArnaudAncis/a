#include "bit_sequence.h"

std::ostream& operator <<(std::ostream& out, const bit_sequence& bits)
{
	for (unsigned i = 0; i != bits.length(); ++i)
	{
		out << (i ? '1' : '0');
	}

	return out;
}

bit_sequence bit_sequence::operator +(const bit_sequence& ys) const
{
	std::vector<bool> concat = bits;
	concat.insert(concat.end(), ys.bits.begin(), ys.bits.end());

	return bit_sequence(concat);
}

bit_sequence& bit_sequence::operator +=(const bit_sequence& ys)
{
	return *this = *this + ys;
}

bool bit_sequence::operator ==(const bit_sequence& xs) const
{
	return this->bits == xs.bits;
}

bool bit_sequence::operator !=(const bit_sequence& xs) const
{
	return !(*this == xs);
}