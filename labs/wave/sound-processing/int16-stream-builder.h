#ifndef INT16_STREAM_BUILDER_H
#define INT16_STREAM_BUILDER_H

#include "stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>>);

#endif
