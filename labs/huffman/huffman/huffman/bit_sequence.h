#ifndef BIT_SEQUENCE_H
#define BIT_SEQUENCE_H

#include <vector>
#include <algorithm>

class bit_sequence
{
	std::vector<bool> bits;

	bit_sequence(std::vector<bool>& bits) : bits(bits) { }

public:
	bit_sequence(bool b) { bits.push_back(b); }
	bit_sequence() = delete;
	bit_sequence(const bit_sequence&) = default;
	bit_sequence(bit_sequence&&) = default;

	bit_sequence& operator =(const bit_sequence&) = default;

	static bit_sequence empty() { return bit_sequence(std::vector<bool> { } ); }
	static bit_sequence zero() { return false; }
	static bit_sequence one() { return true; }

	int length() const { return bits.size(); }

	bool operator [](unsigned index) const { return bits[index]; }

	bit_sequence operator +(const bit_sequence& ys) const
	{
		std::vector<bool> concat = bits;
		concat.insert(concat.end(), ys.bits.begin(), ys.bits.end());

		return bit_sequence(concat);
	}

	bit_sequence& operator +=(const bit_sequence& ys)
	{
		return *this = *this + ys;
	}

	bool operator ==(const bit_sequence& xs) const
	{
		return this->bits == xs.bits;
	}

	bool operator !=(const bit_sequence& xs) const
	{
		return !(*this == xs);
	}
};

#endif