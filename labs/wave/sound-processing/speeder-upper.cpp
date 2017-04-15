#include "speeder-upper.h"


namespace
{
    class SpeederUpper : public Wave
    {
    private:
        std::shared_ptr<Wave> m_wave;
        double m_factor;

    public:
        SpeederUpper(std::shared_ptr<Wave> wave, double factor)
            : m_wave(wave), m_factor(factor) { }

        double length() const override { return m_wave->length() / m_factor; }

        double operator [](double t) const override
        {
            return (*m_wave)[t * m_factor];
        }
    };
}

std::shared_ptr<Wave> speed_up(std::shared_ptr<Wave> wave, double factor)
{
    return std::make_shared<SpeederUpper>(wave, factor);
}
