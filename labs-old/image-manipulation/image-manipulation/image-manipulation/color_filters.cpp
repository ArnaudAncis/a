#include "color_filters.h"

std::shared_ptr<Bitmap> RedFilter::apply(const Bitmap& bitmap) const
{
	// Create result bitmap with same dimensions as original bitmap
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	// Iterate over all pixels
	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);

			// Process pixel
			color original = bitmap[p];
			color processed(original.r, 0, 0);

			// Write pixel to result bitmap
			(*result)[p] = processed;
		}
	}

	// Return result
	return result;
}

// TODO