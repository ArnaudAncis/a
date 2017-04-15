#ifndef NORMALISER_H
#define NORMALISER_H

#include "stream.h"
#include <memory>


std::shared_ptr<Stream<double>> normalise(std::shared_ptr<Stream<double>>, double = 1);

#endif
