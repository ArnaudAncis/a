#include "formats.h"
#include "projection.h"
#include "function.h"

const unsigned MAX_ITERATIONS = 500;
const double ABS_THRESHOLD = 2;

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
    Bitmap bitmap(800, 800);

    // projection proj(bitmap.width(), bitmap.height(), complex(-.5, 0), 2);
    // projection proj(bitmap.width(), bitmap.height(), complex(-0.1011, 0.9563), 0.001);
    projection proj(bitmap.width(), bitmap.height(), complex(-0.088, 0.654), 0.01);
    

    auto r = gauss(0.25, 5);
    auto g = gauss(0.5, 5);
    auto b = gauss(.75, 5);

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

    save_bitmap("output.bmp", bitmap);
}