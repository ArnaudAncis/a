#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include "streams/stream.h"
#include "waves/wave.h"
#include <memory>


Wave interpolate(std::shared_ptr<Stream<double>>, unsigned);

#endif
