#include "projection.h"

projection::projection(int width, int height, const interval& target_x, const interval& target_y)
    : m_horizontal(interval(0, width), target_x)
    , m_vertical(interval(0, height), target_y)
{
    // NOP
}

projection::projection(int width, int height, const complex& center, double size)
    : projection(width, height, interval(center.re() - size / 2, center.re() + size / 2), interval(center.im() - size / 2, center.im() + size / 2))
{
    // NOP
}

complex projection::project(position p) const
{
    return complex(m_horizontal[p.x], m_vertical[p.y]);
}
