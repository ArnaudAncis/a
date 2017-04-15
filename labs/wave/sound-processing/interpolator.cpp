#include "interpolator.h"
#include <assert.h>


namespace
{
    class Interpolator : public Wave
    {
        std::shared_ptr<Stream<double>> m_stream;
        unsigned m_sample_rate;

    public:
        Interpolator(std::shared_ptr<Stream<double>> stream, unsigned sample_rate)
            : m_stream(stream), m_sample_rate(sample_rate) { }

        double length() const override
        {
            return double(m_stream->size()) / m_sample_rate;
        }

        double operator [](double t) const override
        {
            assert(0 <= t);
            assert(t < length());

            unsigned i = (unsigned)(t * m_sample_rate);
            unsigned j = i + 1;

            assert(i < m_stream->size());
            assert(j < m_stream->size());

            double dt = (t - double(i) / m_sample_rate) * m_sample_rate;

            assert(-0.00001 <= dt);
            assert(dt < 1.00001);

            double sample_at_i = (*m_stream)[i];
            double sample_at_j = (*m_stream)[j];

            return sample_at_i + (sample_at_j - sample_at_i) * dt;
        }
    };
}

std::shared_ptr<Wave> interpolate(std::shared_ptr<Stream<double>> samples, unsigned sample_rate)
{
    return std::make_shared<Interpolator>(samples, sample_rate);
}