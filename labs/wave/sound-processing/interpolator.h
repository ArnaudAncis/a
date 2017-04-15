#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include "stream.h"
#include "wave.h"
#include <memory>


Wave interpolate(std::shared_ptr<Stream<double>>, unsigned);

#endif
