#ifndef WAVE_SAMPLING_STREAM_H
#define WAVE_SAMPLING_STREAM_H

#include "waves/wave.h"
#include "streams/stream.h"
#include <memory>


std::shared_ptr<Stream<double>> sample_wave(Wave, unsigned);

#endif
