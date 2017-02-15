#ifndef SAMPLE_STREAM_H
#define SAMPLE_STREAM_H

#include "stream.h"
#include <vector>


class SampleStream : public Stream
{
private:
    std::vector<double> samples;

public:
    SampleStream(const std::vector<double>& samples);

    SampleStream(const std::vector<double>&& samples);

    unsigned size() const override;

    double operator [](unsigned index) const override;
};

#endif
