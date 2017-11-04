#ifndef INTERVAL_H
#define INTERVAL_H

class interval final
{
private:
    double m_lower, m_upper;

public:
    interval(double lower, double upper);
    interval(const interval&) = default;

    double& lower();
    double lower() const;

    double& upper();
    double upper() const;

    double size() const;

    double to_relative(double x) const;
    double from_relative(double t) const;
};

#endif