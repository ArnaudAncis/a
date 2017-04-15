#ifndef WAVE_SAMPLING_STREAM_H
#define WAVE_SAMPLING_STREAM_H

#include "wave.h"
#include "stream.h"
#include <memory>


std::shared_ptr<Stream<double>> sample_wave(Wave, unsigned);

#endif
