#include "formats.h"
#include "interval_mapper.h"

inline double sqr(double x)
{
    return x * x;
}

int main()
{
    Bitmap bitmap(500, 500);

    for (int y = 0; y < bitmap.height(); ++y)
    {
        for (int x = 0; x < bitmap.width(); ++x)
        {
            interval_mapper map(interval(0, sqrt(sqr(bitmap.width() / 2) + sqr(bitmap.height() / 2))), interval(0, 1));
            double t = map[sqrt(sqr(x - int(bitmap.width()) / 2) + sqr(y - int(bitmap.height()) / 2))];
            color c = colors::red() * t + colors::yellow() * (1 - t);

            position p(x, y);

            bitmap[p] = c;
        }
    }

    save_bitmap("output.bmp", bitmap);
}