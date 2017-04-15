#include "wave-addition.h"
#include <memory>
#include <algorithm>


namespace
{
    class WaveAdditionFunction : public WaveFunction
    {
    private:
        Wave m_first;
        Wave m_second;

    public:
        WaveAdditionFunction(Wave first, Wave second)
            : m_first(first), m_second(second) { }

        double length() const override
        {
            return std::min(m_first.length(), m_second.length());
        }

        double operator [](double t) const override
        {
            return (m_first[t] + m_second[t]) / 2; // TODO Remove /2
        }
    };
}

Wave operator +(Wave a, Wave b)
{
    return Wave(std::make_shared<WaveAdditionFunction>(a, b));
}
