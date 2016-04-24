#include "hflip_filter.h"

std::shared_ptr<Bitmap> HorizontalFlipFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);
			position q(bitmap.width() - x - 1, y);

			(*result)[q] = bitmap[p];
		}
	}

	return result;
}