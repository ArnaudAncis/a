#include "formats.h"
#include "projection.h"
#include "function.h"


unsigned div(const complex& c, unsigned max_iterations)
{
    unsigned result = 0;
    complex z(0);

    while (z.abs() < 1000 && result < max_iterations)
    {
        z = z * z + c;
        ++result;
    }

    return result;
}

int main()
{
    const unsigned MAX_ITERATIONS = 100;
    Bitmap bitmap(1000, 1000);
    // projection proj(bitmap.width(), bitmap.height(), complex(-0.1011, 0.9563), 0.001);
    projection proj(bitmap.width(), bitmap.height(), complex(-.5, 0), 2);

    auto r = easeInOut(0, 1);
    auto g = easeInOut(0, 1);
    auto b = easeInOut(0, 1);
    auto cfunc = color_function(r, g, b);

    for (unsigned y = 0; y != bitmap.height(); ++y)
    {
        for (unsigned x = 0; x != bitmap.width(); ++x)
        {
            position pos(x, y);
            complex z = proj.project(pos);
            unsigned n = div(z, MAX_ITERATIONS);
            auto c = cfunc(double(n) / MAX_ITERATIONS);

            bitmap[pos] = c;
        }
    }

    save_bitmap("g:/fractal.bmp", bitmap);
}