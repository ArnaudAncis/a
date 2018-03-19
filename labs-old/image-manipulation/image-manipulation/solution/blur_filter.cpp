#include "blur_filter.h"

std::shared_ptr<Bitmap> BlurFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y != bitmap.height(); ++y)
	{
		for (unsigned x = 0; x != bitmap.width(); ++x)
		{
			position p(x, y);

			unsigned count = 1;
			color c = bitmap[p];
			for (auto neighbor : p.around8(m_distance))
			{
				if (bitmap.is_inside(neighbor))
				{
					c += bitmap[neighbor];
					++count;
				}
			}

			(*result)[p] = c / count;
		}
	}

	return result;
}