#include "horizontal-layout.h"
#include <algorithm>


namespace
{
	class HorizontalLayout : public LinearLayout
	{
	public:
		HorizontalLayout(const std::vector<std::shared_ptr<Layout>>& children, double separation)
			: LinearLayout(children, separation) { }

		Box box() const override
		{
			Box result;

			result.width = std::max((int) m_children.size() - 1, 0) * m_separation;

			for (auto& child : m_children)
			{
				auto box = child->box();

				result.width += box.width;
				result.height = std::max(box.height, result.height);
			}

			return result;
		}
	};
}

std::shared_ptr<Layout> create_horizontal_layout(const std::vector<std::shared_ptr<Layout>>& children, double separation)
{
	return std::make_shared<HorizontalLayout>(children, separation);
}
