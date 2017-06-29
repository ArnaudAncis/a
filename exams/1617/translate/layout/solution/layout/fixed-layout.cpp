#include "fixed-layout.h"


class FixedLayout : public Layout
{
	Box m_box;

public:
	FixedLayout(const Box& box)
		: m_box(box) { }

	Box box() const override
	{
		return m_box;
	}
};

std::shared_ptr<Layout> create_fixed_layout(const Box& box)
{
	return std::make_shared<FixedLayout>(box);
}
