#ifndef WAVE_SAMPLING_STREAM_SOLUTION_H
#define WAVE_SAMPLING_STREAM_SOLUTION_H

#include "waves/wave.h"
#include "streams/stream.h"
#include <memory>


namespace solution
{
    std::shared_ptr<Stream<double>> sample_wave(Wave, unsigned);
}

#endif
