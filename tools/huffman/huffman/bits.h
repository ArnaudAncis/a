#ifndef BITS_H
#define BITS_H

#include <cstdint>


class Bits
{
    uint64_t m_bits;
    unsigned m_size;

public:
    Bits();
    Bits(uint64_t bits, unsigned size);

    Bits operator <<(unsigned) const;
    Bits operator |(const Bits& bits) const;


};

#endif
