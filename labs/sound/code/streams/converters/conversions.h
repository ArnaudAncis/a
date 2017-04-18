#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "streams/converters/double-to-int16-conversion.h"
#include "streams/converters/double-to-uint8-conversion.h"
#include "streams/converters/int16-to-double-conversion.h"
#include "streams/stream.h"
#include <cstdint>
#include <memory>


std::shared_ptr<Stream<uint8_t>> convert_int16_to_uint8_stream(std::shared_ptr<Stream<int16_t>>);
std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>>);
std::shared_ptr<Stream<double>> convert_uint8_to_double_stream(std::shared_ptr<Stream<uint8_t>>);

#endif
