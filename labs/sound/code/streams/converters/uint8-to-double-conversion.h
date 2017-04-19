#ifndef UINT8_TO_DOUBLE_CONVERSION_H
#define UINT8_TO_DOUBLE_CONVERSION_H

#include "streams/stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<double>> convert_uint8_to_double_stream(std::shared_ptr<Stream<uint8_t>>);

#endif
