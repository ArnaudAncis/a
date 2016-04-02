#ifndef INTERVAL_MAPPER_H
#define INTERVAL_MAPPER_H

#include "interval.h"

class interval_mapper final
{
private:
    interval m_from, m_to;

public:
    interval_mapper(const interval& from, const interval& to);
    interval_mapper(const interval_mapper&) = default;

    double operator[](double x) const;
    interval_mapper inverse() const;
};

#endif