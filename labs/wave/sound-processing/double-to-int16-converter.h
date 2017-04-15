#ifndef DOUBLE_TO_INT16_CONVERTER_H
#define DOUBLE_TO_INT16_CONVERTER_H

#include "stream.h"
#include <memory>


std::shared_ptr<Stream<int16_t>> convert_double_to_int16_stream(std::shared_ptr<Stream<double>>);

#endif
