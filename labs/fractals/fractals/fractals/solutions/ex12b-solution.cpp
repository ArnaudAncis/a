#include "formats.h"
#include "projection.h"
#include "function.h"

const unsigned MAX_ITERATIONS = 500;
const double ABS_THRESHOLD = 2;
const unsigned ANTIALIAS = 4;
const unsigned SIZE = 800;

unsigned div(const complex& c, unsigned max_iterations)
{
    unsigned result = 0;
    complex z(0);

    while (z.abs() < ABS_THRESHOLD && result < max_iterations)
    {
        z = z * z + c;
        ++result;
    }

    return result;
}

int main()
{
    Bitmap bitmap(SIZE, SIZE);

    projection proj(bitmap.width() * ANTIALIAS, bitmap.height() * ANTIALIAS, complex(-0.745, 0.1), 0.01);

    auto r = gauss(0.7, 4);
    auto g = gauss(0.5, 3);
    auto b = gauss(0.2, 3);

    auto cfunc = color_function(r, g, b);

    for (unsigned y = 0; y != bitmap.height(); ++y)
    {
        for (unsigned x = 0; x != bitmap.width(); ++x)
        {
            color result = colors::black();

            for (unsigned dx = 0; dx != ANTIALIAS; ++dx)
            {
                for (unsigned dy = 0; dy != ANTIALIAS; ++dy)
                {
                    position pos(ANTIALIAS * x + dx, ANTIALIAS * y + dy);
                    complex z = proj.project(pos);
                    unsigned n = div(z, MAX_ITERATIONS);
                    auto c = cfunc(double(n) / MAX_ITERATIONS);

                    result += c;
                }
            }

            bitmap[position(x, y)] = result / (ANTIALIAS * ANTIALIAS);
        }
    }

    save_bitmap("output.bmp", bitmap);
}