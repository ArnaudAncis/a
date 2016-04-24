#include "per_pixel_filter.h"

std::shared_ptr<Bitmap> PerPixelFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];			
			color processed = process(original);

			(*result)[p] = processed;
		}
	}

	return result;
}
