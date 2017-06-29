#include "vertical-layout.h"
#include <algorithm>


namespace
{
	class VerticalLayout : public LinearLayout
	{
	public:
		VerticalLayout(const std::vector<std::shared_ptr<Layout>>& children, double separation)
			: LinearLayout(children, separation) { }

		Box box() const
		{
			Box result;

			result.height = std::max((int)m_children.size() - 1, 0) * m_separation;

			for (auto& child : m_children)
			{
				auto box = child->box();

				result.width = std::max(box.width, result.width);
				result.height += box.height;
			}

			return result;
		}
	};
}

std::shared_ptr<Layout> create_vertical_layout(const std::vector<std::shared_ptr<Layout>>& children, double separation)
{
	return std::make_shared<VerticalLayout>(children, separation);
}
