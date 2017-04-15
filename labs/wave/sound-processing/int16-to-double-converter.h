#ifndef INT16_TO_DOUBLE_CONVERTER_H
#define INT16_TO_DOUBLE_CONVERTER_H

#include "stream.h"
#include <memory>


std::shared_ptr<Stream<double>> convert_int16_to_double_stream(std::shared_ptr<Stream<int16_t>>);

#endif
