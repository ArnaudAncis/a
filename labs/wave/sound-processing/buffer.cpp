#include "buffer.h"


class BufferInternals
{
public:
    virtual unsigned size() = 0;
    virtual uint8_t operator [](unsigned index) const = 0;
};


Buffer::Buffer(unsigned size)
{

}