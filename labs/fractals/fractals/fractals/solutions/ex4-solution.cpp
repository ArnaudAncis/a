#include "formats.h"
#include "interval_mapper.h"

int main()
{
    Bitmap bitmap(500, 500);

    for (unsigned y = 0; y < bitmap.height(); ++y)
    {
        interval_mapper map(interval(0, bitmap.height() - 1), interval(0, 1));
        double t = map[y];

        color c = colors::blue() * t + colors::red() * (1 - t);

        for (unsigned x = 0; x < bitmap.width(); ++x)
        {
            position p(x, y);

            bitmap[p] = c;
        }
    }

    save_bitmap("output.bmp", bitmap);
}