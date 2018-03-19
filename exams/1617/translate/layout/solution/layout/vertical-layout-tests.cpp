#include "vertical-layout.h"
#include "vertical-layout.h"
#include "fixed-layout.h"
#include "fixed-layout.h"
#include "Catch.h"


TEST_CASE("Empty vertical layout")
{
	std::vector<std::shared_ptr<Layout>> children;
	std::shared_ptr<Layout> layout = create_vertical_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == 0);
	CHECK(box.height == 0);
}

TEST_CASE("Vertical layout with one child")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 8)) };
	std::shared_ptr<Layout> layout = create_vertical_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == 1);
	CHECK(box.height == 8);
}

TEST_CASE("Vertical layout with two children")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 3)), create_fixed_layout(Box(4, 6)) };
	std::shared_ptr<Layout> layout = create_vertical_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == Approx(4));
	CHECK(box.height == Approx(3 + 5 + 6));
}

TEST_CASE("Vertical layout with three children")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 8)), create_fixed_layout(Box(4, 2)), create_fixed_layout(Box(3, 9)) };
	std::shared_ptr<Layout> layout = create_vertical_layout(children, 7);
	auto box = layout->box();

	CHECK(box.width == Approx(4));
	CHECK(box.height == Approx(8 + 7 + 2 + 7 + 9));
}
