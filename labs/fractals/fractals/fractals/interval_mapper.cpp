#include "interval_mapper.h"

interval_mapper::interval_mapper(const interval& from, const interval& to)
    : m_from(from), m_to(to)
{
    // NOP
}

double interval_mapper::operator[](double x) const
{
    return m_to.from_relative(m_from.to_relative(x));
}

interval_mapper interval_mapper::inverse() const
{
    return interval_mapper(m_to, m_from);
}
