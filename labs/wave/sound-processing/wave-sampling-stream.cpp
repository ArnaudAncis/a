#include "wave-sampling-stream.h"


WaveSamplingStream::WaveSamplingStream(std::shared_ptr<Wave> wave, unsigned sampling_rate)
        : m_wave(wave), m_sampling_rate(sampling_rate) { }

unsigned WaveSamplingStream::size() const
{
    return (unsigned)(m_wave->length() * m_sampling_rate);
}

double WaveSamplingStream::operator [](unsigned index) const
{
    return (*m_wave)[((double)index) / m_sampling_rate];
}
