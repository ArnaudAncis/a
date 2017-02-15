#include "wave-addition.h"
#include <memory>
#include <algorithm>


WaveAddition::WaveAddition(std::shared_ptr<Wave> first, std::shared_ptr<Wave> second)
    : m_first(first), m_second(second)
{
    // NOP
}

double WaveAddition::length() const
{
    return std::min(m_first->length(), m_second->length());
}

double WaveAddition::operator [](double t) const
{
    return ((*m_first)[t] + (*m_second)[t]) / 2; // TODO Remove /2
}
