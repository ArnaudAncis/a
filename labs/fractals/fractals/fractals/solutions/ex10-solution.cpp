#include "formats.h"
#include "projection.h"
#include "function.h"

const unsigned MAX_ITERATIONS = 50;
const double ABS_THRESHOLD = 2;

bool converges(const complex& c, unsigned max_iterations)
{
    unsigned iterations = max_iterations;
    complex z(0);

    while (z.abs() < ABS_THRESHOLD && iterations > 0 )
    {
        z = z * z + c;
        --iterations;
    }

    return iterations == 0;
}

int main()
{
    Bitmap bitmap(800, 800);
    
    projection proj(bitmap.width(), bitmap.height(), complex(-.5, 0), 2);

    for (unsigned y = 0; y != bitmap.height(); ++y)
    {
        for (unsigned x = 0; x != bitmap.width(); ++x)
        {
            position pos(x, y);
            complex z = proj.project(pos);
            
            bitmap[pos] = converges(z, 100) ? colors::black() : colors::white();
        }
    }

    save_bitmap("output.bmp", bitmap);
}