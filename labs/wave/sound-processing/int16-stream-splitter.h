#ifndef INT16_STREAM_SPLITTER_H
#define INT16_STREAM_SPLITTER_H

#include "stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<uint8_t>> convert_int16_to_uint8_stream(std::shared_ptr<Stream<int16_t>>);

#endif
