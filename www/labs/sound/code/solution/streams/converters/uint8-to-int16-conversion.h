#ifndef UINT8_TO_INT16_CONVERSION_H
#define UINT8_TO_INT16_CONVERSION_H

#include "streams/stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>>);

#endif
