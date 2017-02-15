#ifndef WAVE_SAMPLING_STREAM_H
#define WAVE_SAMPLING_STREAM_H

#include "wave.h"
#include "stream.h"
#include <memory>


class WaveSamplingStream : public Stream
{
private:
    std::shared_ptr<Wave> m_wave;
    unsigned m_sampling_rate;

public:
    WaveSamplingStream(std::shared_ptr<Wave> wave, unsigned sampling_rate);

    unsigned size() const override;

    double operator [](unsigned index) const override;
};

#endif
