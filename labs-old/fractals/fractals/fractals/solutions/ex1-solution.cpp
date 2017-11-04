#include "formats.h"

int main()
{
    Bitmap bitmap(500, 500);

    save_bitmap("output.bmp", bitmap);
}