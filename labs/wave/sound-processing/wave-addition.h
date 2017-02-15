#ifndef WAVE_ADDITION_H
#define WAVE_ADDITION_H

#include "wave.h"
#include <memory>


class WaveAddition : public Wave
{
private:
    std::shared_ptr<Wave> m_first;
    std::shared_ptr<Wave> m_second;

public:
    WaveAddition(std::shared_ptr<Wave> first, std::shared_ptr<Wave> second);

    double length() const override;

    double operator [](double t) const override;
};

#endif