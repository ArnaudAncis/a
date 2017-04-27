#include "bits.h"
#include <algorithm>


Bits::Bits() : Bits(0, 0) { }


Bits::Bits(uint64_t bits, unsigned size)
    : m_bits(bits), m_size(size) { }


Bits Bits::operator <<(unsigned n) const
{
    return Bits(m_bits << n, m_size + n);
}

Bits Bits::operator |(const Bits& b) const
{
    return Bits(m_bits | b.m_bits, std::max(m_size, b.m_size));
}


