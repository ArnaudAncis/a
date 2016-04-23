#include "grayscale_filter.h"

std::shared_ptr<Bitmap> GrayscaleFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];
			double average = original.r + original.g + original.b;

			(*result)[p] = color(average, average, average);
		}
	}

	return result;
}