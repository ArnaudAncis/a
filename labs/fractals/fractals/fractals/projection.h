#ifndef PROJECTION_H
#define PROJECTION_H

#include "interval_mapper.h"
#include "complex.h"
#include "position.h"


class projection
{
private:
    interval_mapper m_horizontal, m_vertical;

public:
    projection(int width, int height, const interval& target_x, const interval& target_y);
    projection(int width, int height, const complex& center, double size);

    complex project(position p) const;
};

#endif