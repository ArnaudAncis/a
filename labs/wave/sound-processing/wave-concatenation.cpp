#include "wave-concatenation.h"


namespace
{
    class WaveConcatenationFunction : public WaveFunction
    {
        std::vector<Wave> m_waves;

    public:
        WaveConcatenationFunction(const std::vector<Wave>& waves) : m_waves(waves) { }

        double length() const override
        {
            double total = 0;

            for (auto& wave : m_waves)
            {
                total += wave.length();
            }

            return total;
        }

        double operator [](double t) const
        {
            unsigned index = 0;

            while (t >= m_waves[index].length())
            {
                t -= m_waves[index].length();
                ++index;
            }

            return m_waves[index][t];
        }
    };
}

Wave concatenate(const std::vector<Wave>& waves)
{
    return Wave(std::make_shared<WaveConcatenationFunction>(waves));
}
