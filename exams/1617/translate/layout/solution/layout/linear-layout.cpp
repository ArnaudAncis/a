#include "linear-layout.h"


LinearLayout::LinearLayout(const std::vector<std::shared_ptr<Layout>>& children, double separation)
	: m_children(children), m_separation(separation) { }