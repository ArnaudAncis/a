#ifndef DOUBLE_TO_UINT8_CONVERSION_H
#define DOUBLE_TO_UINT8_CONVERSION_H

#include "streams/stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<uint8_t>> convert_double_to_uint8_stream(std::shared_ptr<Stream<double>>);

#endif
