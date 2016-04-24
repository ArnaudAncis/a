#include "invert_filter.h"

std::shared_ptr<Bitmap> InvertFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];
			color modified(1 - original.r, 1 - original.g, 1 - original.b);

			(*result)[p] = modified;
		}
	}

	return result;
}