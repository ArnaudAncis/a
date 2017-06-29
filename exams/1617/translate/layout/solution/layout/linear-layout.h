#ifndef LINEAR_LAYOUT_H
#define LINEAR_LAYOUT_H

#include "layout.h"
#include <vector>
#include <memory>


class LinearLayout : public Layout
{
protected:
	std::vector<std::shared_ptr<Layout>> m_children;
	double m_separation;

	LinearLayout(const std::vector<std::shared_ptr<Layout>>&, double separation);
};

#endif
