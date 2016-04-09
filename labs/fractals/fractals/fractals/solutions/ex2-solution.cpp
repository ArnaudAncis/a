#include "formats.h"

int main()
{
    Bitmap bitmap(500, 500);

    bitmap.clear(colors::red());

    save_bitmap("output.bmp", bitmap);
}