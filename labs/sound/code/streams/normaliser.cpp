#include "normaliser.h"
#include <algorithm>
#include <limits>
#include <cmath>


namespace
{
    class StreamMultiplier : public Stream<double>
    {
    private:
        std::shared_ptr<Stream> m_stream;
        double m_factor;

    public:
        StreamMultiplier(std::shared_ptr<Stream> stream, double factor)
            : m_stream(stream), m_factor(factor) { }

        unsigned size() const
        {
            return m_stream->size();
        }

        double operator [](unsigned i) const
        {
            return (*m_stream)[i] * m_factor;
        }
    };
}

std::shared_ptr<Stream<double>> normalise(std::shared_ptr<Stream<double>> stream, double maximum)
{
    double lowest = std::numeric_limits<double>::infinity();
    double highest = -std::numeric_limits<double>::infinity();

    unsigned imax = stream->size();
    for (unsigned i = 0; i != imax; ++i)
    {
        lowest = std::min(lowest, (*stream)[i]);
        highest = std::max(highest, (*stream)[i]);
    }

    double factor = std::max(fabs(lowest), fabs(highest));

    return std::make_shared<StreamMultiplier>(stream, 1.0 / factor);
}