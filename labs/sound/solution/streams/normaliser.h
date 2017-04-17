#ifndef NORMALISER_H
#define NORMALISER_H

#include "streams/stream.h"
#include <memory>


std::shared_ptr<Stream<double>> normalise(std::shared_ptr<Stream<double>>, double = 1);

#endif
