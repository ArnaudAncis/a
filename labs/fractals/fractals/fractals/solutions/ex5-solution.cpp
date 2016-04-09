#include "formats.h"
#include "interval_mapper.h"

int main()
{
    Bitmap bitmap(500, 500);

    for (unsigned y = 0; y < bitmap.height(); ++y)
    {
        for (unsigned x = 0; x < bitmap.width(); ++x)
        {
            interval_mapper map(interval(0, bitmap.width() - 1), interval(0, 1));
            double t = map[x];
            color c = colors::white() * t + colors::black() * (1 - t);

            position p(x, y);

            bitmap[p] = c;
        }
    }

    save_bitmap("output.bmp", bitmap);
}