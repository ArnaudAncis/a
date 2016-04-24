#include "mosaic_filter.h"
#include <algorithm>

std::shared_ptr<Bitmap> MosaicFilter::apply(const Bitmap& bitmap) const
{
	auto result = std::make_shared<Bitmap>(bitmap.width(), bitmap.height());

	for (unsigned y = 0; y < bitmap.height(); y += m_size)
	{
		for (unsigned x = 0; x < bitmap.width(); x += m_size)
		{
			color c = colors::black();

			unsigned dx_max = std::min(m_size, bitmap.width() - x);
			unsigned dy_max = std::min(m_size, bitmap.height() - y);

			for (unsigned dx = 0; dx != dx_max; ++dx)
			{
				for (unsigned dy = 0; dy != dy_max; ++dy)
				{
					position p(x + dx, y + dy);

					c += bitmap[p];
				}
			}

			c /= (m_size * m_size);
			
			for (unsigned dx = 0; dx != dx_max; ++dx)
			{
				for (unsigned dy = 0; dy != dy_max; ++dy)
				{
					position p(x + dx, y + dy);

					(*result)[p] = c;
				}
			}
		}
	}

	return result;
}