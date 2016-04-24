#include "color_filters.h"

std::shared_ptr<Bitmap> RedFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];
			color c(original.r, 0, 0);
			
			(*result)[p] = c;
		}
	}

	return result;
}

std::shared_ptr<Bitmap> GreenFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];
			color c(0, original.b, 0);

			(*result)[p] = c;
		}
	}

	return result;
}

std::shared_ptr<Bitmap> BlueFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			color original = bitmap[p];
			color c(0, 0, original.b);

			(*result)[p] = c;
		}
	}

	return result;
}