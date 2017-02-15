#include "sample-stream.h"
#include <vector>


SampleStream::SampleStream(const std::vector<double>& samples)
    : samples(samples)
{
    // NOP
}

SampleStream::SampleStream(const std::vector<double>&& samples)
    : samples(std::move(samples))
{
    // NOP
}

unsigned SampleStream::size() const
{
    return samples.size();
}

double SampleStream::operator [](unsigned index) const
{
    return samples[index];
}
