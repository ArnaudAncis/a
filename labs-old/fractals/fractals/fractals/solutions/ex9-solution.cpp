#include "formats.h"
#include "projection.h"

inline double sqr(double x)
{
    return x * x;
}

int main()
{
    Bitmap bitmap(500, 500);

    projection proj(bitmap.width(), bitmap.height(), interval(-0.5,0.5), interval(-0.5,0.5));

    for (int y = 0; y < bitmap.height(); ++y)
    {
        for (int x = 0; x < bitmap.width(); ++x)
        {            
            position p(x, y);
            complex c = proj.project(p);

            bitmap[p] = color(c.abs(), c.abs(), c.abs());
        }
    }

    save_bitmap("output.bmp", bitmap);
}