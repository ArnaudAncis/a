#include "color.h"


using namespace imaging;

double clamp(double x)
{
    if (x < 0) return 0;
    else if (x > 1) return 1;
    else return x;
}

void color::clamp()
{
    r = ::clamp(r);
    g = ::clamp(g);
    b = ::clamp(b);
}

color color::clamped() const
{
    color copy = *this;
    copy.clamp();
    return copy;
}