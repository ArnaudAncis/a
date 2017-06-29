#include "box.h"
#include "box.h"
#include "Catch.h"
#include <sstream>


TEST_CASE("Box creation using default constructor")
{
	Box b;

	CHECK(b.width == 0);
	CHECK(b.height == 0);
}

TEST_CASE("Box creation using binary constructor")
{
	Box b(2, 5);

	CHECK(b.width == Approx(2));
	CHECK(b.height == Approx(5));
}

TEST_CASE("Single box to output stream")
{
	const Box b(4, 9);
	std::stringstream ss;

	ss << b;

	CHECK(ss.str() == "Box(4x9)");
}

TEST_CASE("Two boxes to output stream")
{
	const Box b1(3, 2);
	const Box b2(7, 4);
	std::stringstream ss;

	ss << b1 << " " << b2;

	CHECK(ss.str() == "Box(3x2) Box(7x4)");
}
