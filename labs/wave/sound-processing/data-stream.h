#ifndef DATA_STREAM_H
#define DATA_STREAM_H

#include "bytes-buffer.h"
#include "stream.h"
#include <cstdint>


class DataStream : public Stream<uint8_t>
{
    BytesBuffer m_data;

public:
    DataStream(BytesBuffer);

    unsigned size() const override;
    uint8_t operator [](unsigned index) const override;
};

#endif
