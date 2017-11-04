#include "interval.h"

interval::interval(double lower, double upper)
    : m_lower(lower), m_upper(upper)  { }

double& interval::lower() { return m_lower; }
double interval::lower() const { return m_lower; }

double& interval::upper() { return m_upper; }
double interval::upper() const { return m_upper; }

double interval::size() const { return m_upper - m_lower; }

double interval::to_relative(double x) const { return (x - m_lower) / size(); }
double interval::from_relative(double t) const { return m_lower + size() * t; }
