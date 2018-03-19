#include "horizontal-layout.h"
#include "horizontal-layout.h"
#include "fixed-layout.h"
#include "fixed-layout.h"
#include "Catch.h"


TEST_CASE("Empty horizontal layout")
{
	std::vector<std::shared_ptr<Layout>> children;
	std::shared_ptr<Layout> layout = create_horizontal_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == 0);
	CHECK(box.height == 0);
}

TEST_CASE("Horizontal layout with one child")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 8)) };
	std::shared_ptr<Layout> layout = create_horizontal_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == 1);
	CHECK(box.height == 8);
}

TEST_CASE("Horizontal layout with two children")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 8)), create_fixed_layout(Box(4, 2)) };
	std::shared_ptr<Layout> layout = create_horizontal_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == Approx(1 + 5 + 4));
	CHECK(box.height == Approx(8));
}

TEST_CASE("Horizontal layout with three children")
{
	std::vector<std::shared_ptr<Layout>> children{ create_fixed_layout(Box(1, 8)), create_fixed_layout(Box(4, 2)), create_fixed_layout(Box(3, 9)) };
	std::shared_ptr<Layout> layout = create_horizontal_layout(children, 5);
	auto box = layout->box();

	CHECK(box.width == Approx(1 + 5 + 4 + 5 + 3));
	CHECK(box.height == Approx(9));
}
