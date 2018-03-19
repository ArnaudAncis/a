#include "data-stream.h"


DataStream::DataStream(BytesBuffer buffer)
    : m_data(buffer) { }


unsigned DataStream::size() const
{
    return m_data.size();
}

uint8_t DataStream::operator [](unsigned index) const
{
    return m_data[index];
}
